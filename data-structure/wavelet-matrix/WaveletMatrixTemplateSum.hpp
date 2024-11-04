
template <class T>
class BitVector {
   private:
    unsigned n, cur, p;
    vector<unsigned> acc, bit;
    vector<T> srsum;

   public:
    BitVector() {
    }

    BitVector(vector<bool> &b) {
        cur = 0;
        n = b.size();
        acc.resize((n >> 5) + 2, 0);
        bit.resize((n >> 5) + 2, 0);
        srsum.resize(n + 1, 0);
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

    inline void srsum_set(const vector<T> &v) {
        for (int i = 0; i < n; i++) {
            srsum[i + 1] = srsum[i] + v[i];
        }
    }

    inline unsigned rank(unsigned k) {
        if (!(k & 31)) return acc[k >> 5];
        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));
    }

    inline T rank_srsum(unsigned k) {
        return srsum[k];
    }

    inline bool access(unsigned k) {
        return (rank(k + 1) - rank(k)) == 1;
    }
};

template <class T>
class WaveletMatrix {
   private:
    unsigned n;
    unsigned bitsize;
    vector<BitVector<T>> b;
    vector<unsigned> zero;
    vector<int> stInd;
    vector<unsigned> compressed;
    vector<T> cmp;
    vector<long long> sum;
    T MI, MA;

    // v[l,r) の中で値がk未満の総和を返す
    long long rank_sum(unsigned l, unsigned r, unsigned k) {
        long long less_sum = 0;
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            } else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return less_sum;
    }

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

    // v[l,r) の中で値がk未満の個数と総和を返す
    pair<long long, long long> rank_less_sum(unsigned l, unsigned r, T k) {
        long long less = 0;
        long long less_sum = 0;
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                less += (rank0_r - rank0_l);
                less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            } else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return {less, less_sum};
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
            b[i].srsum_set(v);
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

    // v[l,r]を昇順ソートした時の先頭k個の総和を返す
    long long kth_ascending_sum(unsigned l, unsigned r, unsigned k) {
        long long res = 0;
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
                res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
                k -= num0;
            } else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        res += int64_t(cmp[val]) * (k);
        return res;
    }

    // v[l,r]を降順ソートした時の先頭k個の総和を返す
    long long kth_descending_sum(unsigned l, unsigned r, unsigned k) {
        return range_sum(l, r) - kth_ascending_sum(l, r, r - l - k);
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

    // v[l,r) の総和を返す
    long long range_sum(unsigned l, unsigned r) {
        return sum[r] - sum[l];
    }

    // v[l,r) の中で[mink,maxk)に入る値の総和を返す
    long long range_sum(unsigned l, unsigned r, T mink, T maxk) {
        mink = compress(mink);
        maxk = compress(maxk);
        return rank_sum(l, r, maxk) - rank_sum(l, r, mink);
    }

    // v[l,r) の中で ∑|v[i]-d| を計算して返す
    long long range_abs(unsigned l, unsigned r, T d) {
        T dnum = rank(r, d) - rank(l, d);
        T dsum = d * dnum;
        T asum = range_sum(l, r);
        auto p = rank_less_sum(l, r, compress(d));
        T less = p.first;
        T less_sum = p.second;
        T more = r - l - dnum - less;
        T more_sum = asum - dsum - less_sum;
        return d * less + more_sum - less_sum - (d * more);
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
