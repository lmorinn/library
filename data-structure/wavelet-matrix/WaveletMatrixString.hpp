template <class T>
class BitVector {
   private:
    unsigned n, cur, p;
    vector<unsigned> acc, bit;

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

    inline unsigned rank(unsigned k) {
        if (!(k & 31)) return acc[k >> 5];
        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));
    }

    inline bool access(unsigned k) {
        return (rank(k + 1) - rank(k)) == 1;
    }
};

class WaveletMatrix {
   private:
    unsigned n;
    unsigned bitsize;
    vector<BitVector<unsigned char>> b;
    vector<unsigned> zero;
    vector<int> stInd;
    unsigned char MI, MA;

    // v[l,r) の中で値がk未満の個数を返す
    unsigned rank_less(unsigned l, unsigned r, unsigned char k) {
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

   public:
    // コンストラクタ
    WaveletMatrix() {}
    WaveletMatrix(string v) {
        MI = numeric_limits<unsigned char>::min();
        MA = numeric_limits<unsigned char>::max();
        n = v.size();

        vector<unsigned> tmp(n);
        stInd.resize(256, -1);
        bitsize = 8;
        b.resize(bitsize);
        zero.resize(bitsize, 0);
        vector<bool> bit(n, 0);
        for (unsigned i = 0; i < bitsize; i++) {
            for (unsigned j = 0; j < n; j++) {
                bit[j] = v[j] & (1U << (bitsize - i - 1));
                zero[i] += unsigned(!bit[j]);
                tmp[j] = v[j];
            }
            b[i] = BitVector<unsigned char>(bit);
            int cur = 0;
            for (unsigned j = 0; j < n; j++) {
                if (!bit[j]) {
                    v[cur] = tmp[j];
                    cur++;
                }
            }
            for (unsigned j = 0; j < n; j++) {
                if (bit[j]) {
                    v[cur] = tmp[j];
                    cur++;
                }
            }
        }

        for (unsigned i = 0; i < n; i++) {
            if (stInd[v[i]] == -1) {
                stInd[v[i]] = i;
            }
        }
    }

    // get v[k]
    unsigned char access(unsigned k) {
        unsigned char res = 0;
        unsigned cur = k;
        for (unsigned i = 0; i < bitsize; i++) {
            if (b[i].access(cur)) {
                res |= (1U << (bitsize - i - 1));
                cur = zero[i] + b[i].rank(cur);
            } else {
                cur -= b[i].rank(cur);
            }
        }
        return res;
    }

    // v[0,k) 中でのcの出現回数を返す
    unsigned rank(unsigned k, unsigned char c) {
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
    unsigned char kth_smallest(unsigned l, unsigned r, unsigned k) {
        unsigned char res = 0;
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
        return res;
    }

    // v[l,r) の中でk番目(1-origin)に大きい値を返す
    unsigned char kth_largest(unsigned l, unsigned r, unsigned k) {
        return kth_smallest(l, r, r - l - k + 1);
    }

    // v[l,r) の中で[mink,maxk)に入る値の個数を返す
    unsigned range_freq(unsigned l, unsigned r, unsigned char mink, unsigned char maxk) {
        if (mink == 0) {
            return rank_less(l, r, maxk);
        }
        return rank_less(l, r, maxk) - rank_less(l, r, mink);
    }

    // v[l,r)の中でvalを超えない最大の値を返す
    unsigned char prev_value(unsigned l, unsigned r, unsigned char val) {
        int num = range_freq(l, r, MI, val);
        if (num == 0) {
            return MA;
        } else {
            return kth_smallest(l, r, num);
        }
    }

    // v[l,r)の中でvalより大きい最小の値を返す
    unsigned char next_value(unsigned l, unsigned r, unsigned char val) {
        int num = range_freq(l, r, MI, val + 1);
        if (num == r - l) {
            return MI;
        } else {
            return kth_smallest(l, r, num + 1);
        }
    }
};