template <class S, class F, auto mapping, auto composition, auto id>
struct DualSegmentTree {
   private:
    int n;
    vector<F> node;
    F ID;
    void Apply(int a, int b, F x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (r <= a or b <= l) return;
        if (a <= l and r <= b) {
            node[k] = composition(x, node[k]);
            eval(k, l, r);
            return;
        }
        Apply(a, b, x, (k << 1) + 1, l, (l + r) >> 1);
        Apply(a, b, x, (k << 1) + 2, (l + r) >> 1, r);
    }

    void eval(int k, int l, int r) {
        if (r - l > 1) {
            node[(k << 1) + 1] = composition(node[k], node[(k << 1) + 1]);
            node[(k << 1) + 2] = composition(node[k], node[(k << 1) + 2]);
            node[k] = ID;
        }
    }

   public:
    DualSegmentTree() {}
    DualSegmentTree(vector<S> &v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n <<= 1;
        node.resize((n << 1) - 1, id());
        ID = id();
    }

    void apply(int l, int r, F x) {
        Apply(l, r, x);
    }

    F getf(int p) {
        p += (n - 1);
        F f = node[p];
        while (p > 0) {
            p = (p - 1) >> 1;
            f = composition(node[p], f);
        }
        return f;
    }
};

struct BitVector {
    unsigned sz;
    unsigned blocksize;
    vector<unsigned> bit, sum;

    BitVector() {}

    BitVector(unsigned siz) {
        sz = siz;
        blocksize = (sz + 31) >> 5;
        bit.assign(blocksize, 0U);
        sum.assign(blocksize, 0U);
    }

    inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }

    inline void build() {
        sum[0] = 0U;
        for (int i = 1; i < blocksize; i++) {
            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
        }
    }

    inline bool access(unsigned k) {
        return (bool((bit[k >> 5] >> (k & 31)) & 1));
    }

    inline int rank(int k) {
        return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
    }
};

template <class T, class F, auto mapping, auto composition, auto id>
class WaveletMatrix {
   private:
    unsigned n;
    unsigned bitsize;
    vector<BitVector> b;
    vector<unsigned> zero;
    vector<T> cmp;
    vector<T> px;
    vector<int> index;
    vector<T> arr;
    vector<DualSegmentTree<T, F, mapping, composition, id>> seg;

    inline unsigned compress(const T &x) {
        return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
    }

   public:
    // コンストラクタ
    WaveletMatrix() {}

    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {
        n = x.size();
        index.resize(n);
        px.resize(n);
        arr = w;
        vector<tuple<T, T, T, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {x[i], y[i], w[i], i};
        }
        sort(v.begin(), v.end(), [](const tuple<T, T, T, int> &l, const tuple<T, T, T, int> &r) {
            return get<0>(l) < get<0>(r);
        });
        for (int i = 0; i < n; i++) {
            px[i] = get<0>(v[i]);
            y[i] = get<1>(v[i]);
            w[i] = get<2>(v[i]);
            index[get<3>(v[i])] = i;
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
        seg.resize(bitsize + 1);
        zero.resize(bitsize, 0);
        int cur = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            b[i] = BitVector(n + 1);
            seg[i] = DualSegmentTree<T, F, mapping, composition, id>(w);
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
        seg[bitsize] = DualSegmentTree<T, F, mapping, composition, id>(w);
    }

    T get_val(unsigned k) {
        F f = id();
        T val = arr[k];
        unsigned cur = index[k];
        for (unsigned i = 0; i < bitsize; i++) {
            f = composition(seg[i].getf(cur), f);
            if (b[i].access(cur)) {
                cur = zero[i] + b[i].rank(cur);
            } else {
                cur -= b[i].rank(cur);
            }
        }
        f = composition(seg[bitsize].getf(cur), f);
        return mapping(f, val);
    }

    void rectangle_apply(T x_min, T x_max, T y_min, T y_max, F x) {
        x_min = distance(px.begin(), lower_bound(px.begin(), px.end(), x_min));
        x_max = distance(px.begin(), lower_bound(px.begin(), px.end(), x_max));
        int D = compress(y_min);
        int U = compress(y_max);
        auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
            if (U <= A or B <= D) return;
            if (D <= A and B <= U) {
                seg[d].apply(L, R, x);
                return;
            }
            if (d == bitsize) {
                if (D <= A and A < U) {
                    seg[bitsize].apply(L, R, x);
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
        dfs(dfs, 0, x_min, x_max, 0, 1 << bitsize);
    }
};
