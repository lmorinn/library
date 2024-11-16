template <class T>
struct BitVector {
    unsigned sz;
    unsigned blocksize;
    vector<unsigned long long> bit;
    vector<unsigned> sum;
    fenwick_tree<T> seg;

    BitVector() {}

    BitVector(unsigned siz) {
        sz = siz;
        blocksize = (sz + 63) >> 6;
        bit.assign(blocksize, 0ULL);
        sum.assign(blocksize, 0U);
    }

    inline void set(int k) { bit[k >> 6] |= 1ULL << (k & 63ULL); }

    inline void build() {
        sum[0] = 0ULL;
        for (int i = 1; i < blocksize; i++) {
            sum[i] = sum[i - 1] + __builtin_popcountll(bit[i - 1]);
        }
    }

    inline bool access(unsigned k) {
        return (bool((bit[k >> 6] >> (k & 63)) & 1));
    }

    inline int rank(int k) {
        return (sum[k >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL << (k & 63)) - 1)));
    }

    inline void ft_set(const vector<T> &v) {
        seg = fenwick_tree<T>(v.size());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) {
                seg.add(i, v[i]);
            }
        }
    }

    inline void val_add(unsigned pos, T x) {
        seg.add(pos, x);
    }

    inline T val_get(unsigned pos) {
        return seg.sum(pos, pos + 1);
    }

    inline T rank_sum(unsigned l, unsigned r) {
        return seg.sum(l, r);
    }
};

template <class T>
class WaveletMatrix {
   private:
    unsigned n;
    unsigned bitsize, logn;
    vector<BitVector<T>> b;
    vector<unsigned> zero;
    vector<unsigned> index;
    vector<T> cmp;
    vector<T> px;
    T MI, MA;

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
        vector<T> tmp(n);
        vector<T> tmpc(n);
        vector<T> compressed(n);
        for (unsigned i = 0; i < n; i++) {
            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
        }
        bitsize = bit_width(cmp.size());
        b.resize(bitsize + 1);
        zero.resize(bitsize, 0);
        int cur = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            b[i] = BitVector<T>(n + 1);
            b[i].ft_set(v);
            cur = 0;
            for (unsigned j = 0; j < n; j++) {
                if (compressed[j] & (1U << (bitsize - i - 1))) {
                    b[i].set(j);
                } else {
                    zero[i]++;
                    tmpc[cur] = compressed[j];
                    tmp[cur] = v[j];
                    cur++;
                }
            }
            b[i].build();
            for (int j = 0; j < n; j++) {
                if (compressed[j] & (1U << (bitsize - i - 1))) {
                    tmpc[cur] = compressed[j];
                    tmp[cur] = v[j];
                    cur++;
                }
            }
            swap(tmpc, compressed);
            swap(tmp, v);
        }
        b[bitsize] = BitVector<T>(n + 1);
        b[bitsize].ft_set(v);
    }

    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {
        n = x.size();
        px.resize(n);
        index.resize(n);
        vector<tuple<T, T, T, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {x[i], y[i], w[i], i};
        }
        sort(v.begin(), v.end(), [](const tuple<T, T, T, int> &l, const tuple<T, T, T, int> &r) {
            return std::get<0>(l) < std::get<0>(r);
        });
        for (int i = 0; i < n; i++) {
            px[i] = std::get<0>(v[i]);
            y[i] = std::get<1>(v[i]);
            w[i] = std::get<2>(v[i]);
            index[std::get<3>(v[i])] = i;
        }
        vector<unsigned> compressed(n);
        cmp.resize(y.size());
        cmp = y;
        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
        vector<unsigned> tmpc(n);
        vector<T> tmp(n);
        unsigned size_mx = y.size();
        for (unsigned i = 0; i < n; i++) {
            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y[i]));
        }
        bitsize = bit_width(cmp.size());
        b.resize(bitsize + 1);
        zero.resize(bitsize, 0);
        int cur = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            b[i] = BitVector<T>(n + 1);
            b[i].ft_set(w);
            cur = 0;
            for (unsigned j = 0; j < n; j++) {
                if (compressed[j] & (1U << (bitsize - i - 1))) {
                    b[i].set(j);
                } else {
                    zero[i]++;
                    tmpc[cur] = compressed[j];
                    tmp[cur] = w[j];
                    cur++;
                }
            }

            b[i].build();
            for (int j = 0; j < n; j++) {
                if (compressed[j] & (1U << (bitsize - i - 1))) {
                    tmpc[cur] = compressed[j];
                    tmp[cur] = w[j];
                    cur++;
                }
            }
            swap(tmpc, compressed);
            swap(tmp, w);
        }

        b[bitsize].ft_set(w);
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

    void set(int p, T x) {
        unsigned cur = index[p];
        T before = b[0].val_get(cur);
        for (unsigned i = 0; i < bitsize; i++) {
            b[i].val_add(cur, x - before);
            if (b[i].access(cur)) {
                cur = zero[i] + b[i].rank(cur);
            } else {
                cur -= b[i].rank(cur);
            }
        }
        b[bitsize].val_add(cur, x - before);
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

    // v[l,r) の中で[mink,maxk)に入る値の総積を返す
    T range_sum(int vl, int vr, T mink, T maxk) {
        int D = compress(mink);
        int U = compress(maxk);
        T res = 0;
        auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
            if (U <= A or B <= D) return;
            if (D <= A and B <= U) {
                res += b[d].rank_sum(L, R);
                return;
            }
            if (d == bitsize) {
                if (D <= A and A < U) {
                    res += b[bitsize].rank_sum(L, R);
                }
                return;
            }
            int C = (A + B) >> 1;
            int rank0_l = L - b[d].rank(L);
            int rank0_r = R - b[d].rank(R);
            int rank1_l = b[d].rank(L) + zero[d];
            int rank1_r = b[d].rank(R) + zero[d];

            rec(rec, d + 1, rank0_l, rank0_r, A, C);
            rec(rec, d + 1, rank1_l, rank1_r, C, B);
        };
        dfs(dfs, 0, vl, vr, 0, 1 << bitsize);
        return res;
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

    // x座標が[l,r) かつy座標が[d,u) に入る点の総積を返す
    T rectangle_sum(T l, T r, T d, T u) {
        unsigned cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));
        unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(), r));
        return range_sum(cl, cr, d, u);
    }
};