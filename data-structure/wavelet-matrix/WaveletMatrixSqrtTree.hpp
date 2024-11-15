#include "../others/SqrtTree.hpp"

template <class T, auto op, auto e>
class WaveletMatrix {
   private:
    unsigned n;
    unsigned bitsize;
    vector<BitVector<T, op, e>> b;
    vector<unsigned> zero;
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
            b[i] = BitVector<T, op, e>(n + 1);
            b[i].sqrt_set(v);
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
        b[bitsize] = BitVector<T, op, e>(n + 1);
        b[bitsize].sqrt_set(v);
    }

    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {
        n = x.size();
        px.resize(n);
        vector<tuple<T, T, T>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {x[i], y[i], w[i]};
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            px[i] = std::get<0>(v[i]);
            y[i] = std::get<1>(v[i]);
            w[i] = std::get<2>(v[i]);
        }

        cmp.resize(y.size());
        cmp = y;
        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
        vector<T> tmpc(n);
        vector<T> tmp(n);
        vector<T> compressed(n);
        for (unsigned i = 0; i < n; i++) {
            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y[i]));
        }
        bitsize = bit_width(cmp.size());
        b.resize(bitsize + 1);
        zero.resize(bitsize, 0);
        vector<bool> bit(n, 0);
        int cur = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            b[i] = BitVector<T, op, e>(bit);
            b[i].sqrt_set(w);
            int cur = 0;
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
            for (unsigned j = 0; j < n; j++) {
                if (compressed[j] & (1U << (bitsize - i - 1))) {
                    tmpc[cur] = compressed[j];
                    tmp[cur] = w[j];
                    cur++;
                }
            }

            swap(tmpc, compressed);
            swap(tmp, w);
        }
        b[bitsize] = BitVector<T, op, e>(n + 1);
        b[bitsize].sqrt_set(w);
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
    T range_prod(int vl, int vr, T mink, T maxk) {
        int D = compress(mink);
        int U = compress(maxk);
        T res = e();
        auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
            if (U <= A or B <= D) return;
            if (D <= A and B <= U) {
                res = op(res, b[d].rank_prod(L, R));
                return;
            }
            if (d == bitsize) {
                if (D <= A and A < U) {
                    res = op(res, b[bitsize].rank_prod(L, R));
                }
                return;
            }
            int C = (A + B) / 2;
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
    T rectangle_prod(T l, T r, T d, T u) {
        unsigned cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));
        unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(), r));
        return range_prod(cl, cr, d, u);
    }

    template <typename F>
    T max_y(T xl, T xr, F check) {
        unsigned L = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));
        unsigned R = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));
        int cnt = 0;
        T prod = e();
        unsigned yidx = 0;
        if (check(R - L, b[0].rank_prod(L, R))) {
            return cmp.back();
        }
        for (int i = 0; i < bitsize; i++) {
            int l0 = L - b[i].rank(L);
            int r0 = R - b[i].rank(R);
            int l1 = L + zero[i] - l0;
            int r1 = R + zero[i] - r0;
            int cnt1 = cnt + r0 - l0;
            T tmp = op(prod, b[i + 1].rank_prod(l0, r0));
            if (check(cnt1, tmp)) {
                cnt = cnt1;
                prod = tmp;
                L = l1;
                R = r1;
                yidx |= 1U << (bitsize - i - 1);
            } else {
                L = l0;
                R = r0;
            }
        }
        return cmp[yidx];
    }
};