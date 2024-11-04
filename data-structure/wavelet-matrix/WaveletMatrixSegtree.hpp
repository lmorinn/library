
template <class T, auto op, auto e>
class BitVector {
   private:
    unsigned n, cur, p;
    vector<unsigned> acc, bit;
    segtree<T, op, e> seg;

   public:
    BitVector() {
    }

    BitVector(vector<bool> &b) {
        cur = 0;
        n = b.size();
        acc.resize((n >> 5) + 2, 0);
        bit.resize((n >> 5) + 2, 0);
        for (int i = 0; i < n; i++) {
            if (!(i & 31)) {
                cur++;
                acc[cur] = acc[cur - 1];
            }
            if (b[i]) {
                acc[cur] += int(b[i]);
                bit[cur - 1] |= (1U << (32 - (i & 31) - 1));
            }
        }
    }

    inline void seg_set(const vector<T> &v) {
        seg = segtree<T, op, e>(v);
    }

    inline unsigned rank(unsigned k) {
        if (!(k & 31)) return acc[k >> 5];
        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));
    }

    inline T rank_prod(unsigned l, unsigned r) {
        return seg.prod(l, r);
    }

    inline bool access(unsigned k) {
        return (rank(k + 1) - rank(k)) == 1;
    }
};

template <class T, auto op, auto e>
class WaveletMatrix {
   private:
    unsigned n;
    unsigned bitsize;
    vector<BitVector<T>> b;
    vector<unsigned> zero;
    vector<int> stInd;
    vector<unsigned> compressed;
    vector<T> cmp;
    vector<T> prod_pw;
    vector<long long> sum;
    T MI, MA;

    // v[l,r) の中で値がk未満の個数を返す
    unsigned rank_less(unsigned l, unsigned r, T k) {
        unsigned less = 0;
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                less += (rank0_r - rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            } else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return less;
    }

    inline unsigned compress(const T &x) {
        return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
    }

   public:
    // コンストラクタ
    WaveletMatrix() {}
    WaveletMatrix(vector<T> v) {
        MI = numeric_limits<T>::min();
        MA = numeric_limits<T>::max();
        n = v.size();
        cmp = v;
        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
        compressed.resize(n);
        sum.resize(n + 1);
        prod_pw.resize(32);
        vector<T> tmp(n);
        vector<unsigned> tmpc(n);
        unsigned size_mx = v.size();
        for (unsigned i = 0; i < n; i++) {
            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
            sum[i + 1] = sum[i] + v[i];
        }
        stInd.resize(cmp.size() + 1, -1);
        bitsize = bit_width(size_mx);
        b.resize(bitsize);
        zero.resize(bitsize, 0);
        vector<bool> bit(n, 0);
        for (unsigned i = 0; i < bitsize; i++) {
            for (unsigned j = 0; j < n; j++) {
                bit[j] = compressed[j] & (1U << (bitsize - i - 1));
                zero[i] += unsigned(!bit[j]);
                tmp[j] = v[j];
                tmpc[j] = compressed[j];
            }
            b[i] = BitVector<T>(bit);
            int cur = 0;
            for (unsigned j = 0; j < n; j++) {
                if (!bit[j]) {
                    v[cur] = tmp[j];
                    compressed[cur] = tmpc[j];
                    cur++;
                }
            }
            for (unsigned j = 0; j < n; j++) {
                if (bit[j]) {
                    v[cur] = tmp[j];
                    compressed[cur] = tmpc[j];
                    cur++;
                }
            }
            b[i].seg_set(v);
        }

        for (unsigned i = 0; i < n; i++) {
            if (stInd[compressed[i]] == -1) {
                stInd[compressed[i]] = i;
            }
        }
    }

    // get v[k]
    T access(unsigned k) {
        unsigned res = 0;
        unsigned cur = k;
        for (unsigned i = 0; i < bitsize; i++) {
            if (b[i].access(cur)) {
                res |= (1U << (bitsize - i - 1));
                cur = zero[i] + b[i].rank(cur);
            } else {
                cur -= b[i].rank(cur);
            }
        }
        return cmp[res];
    }

    // v[0,k) 中でのcの出現回数を返す
    unsigned rank(unsigned k, T c) {
        c = compress(c);
        unsigned cur = k;
        if (stInd[c] == -1) {
            return 0;
        }
        for (unsigned i = 0; i < bitsize; i++) {
            if (c & (1U << (bitsize - i - 1))) {
                cur = zero[i] + b[i].rank(cur);
            } else {
                cur -= b[i].rank(cur);
            }
        }
        return cur - stInd[c];
    }

    // v[l,r) の中でk番目(1-origin)に小さい値を返す
    T kth_smallest(unsigned l, unsigned r, unsigned k) {
        unsigned res = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            unsigned num1 = b[i].rank(r) - b[i].rank(l);
            unsigned num0 = r - l - num1;
            if (num0 < k) {
                res |= (1ULL << (bitsize - i - 1));
                l = zero[i] + b[i].rank(l);
                r = zero[i] + b[i].rank(r);
                k -= num0;
            } else {
                l -= b[i].rank(l);
                r -= b[i].rank(r);
            }
        }
        return cmp[res];
    }

    // v[l,r) の中でk番目(1-origin)に大きい値を返す
    T kth_largest(unsigned l, unsigned r, unsigned k) {
        return kth_smallest(l, r, r - l - k + 1);
    }

    // v[l,r]を昇順ソートした時の先頭k個の総積を返す
    T kth_ascending_prod(unsigned l, unsigned r, unsigned k) {
        T res = e();
        unsigned val = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            const unsigned num1 = rank1_r - rank1_l;
            const unsigned num0 = rank0_r - rank0_l;
            if (num0 < k) {
                val |= (1ULL << (bitsize - i - 1));
                res = op(res, b[i].rank_prod(rank0_l, rank0_r));
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
                k -= num0;
            } else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        int bw = bit_width(k);
        prod_pw[0] = cmp[val];
        for (int i = 1; i < bw; i++) {
            prod_pw[i] = op(prod_pw[i - 1], prod_pw[i - 1]);
        }
        for (int i = 0; i < bw; i++) {
            if (k & (1 << i)) {
                res = op(res, prod_pw[i]);
            }
        }
        return res;
    }

    // v[l,r) の中で[mink,maxk)に入る値の個数を返す
    unsigned range_freq(unsigned l, unsigned r, T mink, T maxk) {
        mink = compress(mink);
        maxk = compress(maxk);
        if (mink == 0) {
            return rank_less(l, r, maxk);
        }
        return rank_less(l, r, maxk) - rank_less(l, r, mink);
    }

    // v[l,r) の中で値がupper未満の総積を返す
    T rank_less_prod(unsigned l, unsigned r, T upper) {
        T ret = e();
        unsigned k = compress(upper);
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                ret = op(ret, b[i].rank_prod(rank0_l, rank0_r));
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            } else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return ret;
    }

    // v[l,r)の中でvalを超えない最大の値を返す
    T prev_value(unsigned l, unsigned r, T val) {
        int num = range_freq(l, r, MI, val);
        if (num == 0) {
            return MA;
        } else {
            return kth_smallest(l, r, num);
        }
    }

    // v[l,r)の中でval以上の最小の値を返す
    T next_value(unsigned l, unsigned r, T val) {
        int num = range_freq(l, r, MI, val);
        if (num == r - l) {
            return MI;
        } else {
            return kth_smallest(l, r, num + 1);
        }
    }
};
