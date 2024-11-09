#include <WaveletMatrixTemplate.hpp>

template <class T>
class WaveletMatrix3d {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<WaveletMatrix<T>> w;
  vector<unsigned> zero;
  vector<int> stInd;
  vector<unsigned> compressed;
  vector<T> cmp, px;
  T MI, MA;

  // v[l,r) の中で値がk未満の個数を返す
  unsigned rank_less(unsigned l, unsigned r, T d, T u, T k) {
    unsigned less = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += w[i].range_freq(rank0_l, rank0_r, d, u);
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

  unsigned range_freq(unsigned l, unsigned r, T d, T u, T s, T t) {
    d = compress(d);
    u = compress(u);
    if (d == 0) {
      return rank_less(l, r, s, t, u);
    }
    return rank_less(l, r, s, t, u) - rank_less(l, r, s, t, d);
  }

  T kth_smallest(unsigned l, unsigned r, T d, T u, unsigned k) {
    unsigned res = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      unsigned num1 = b[i].rank(r) - b[i].rank(l);
      unsigned num0 = w[i].range_freq(l - b[i].rank(l), r - b[i].rank(r), d, u);
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

 public:
  WaveletMatrix3d(vector<T> x, vector<T> y, vector<T> z) {
    n = x.size();
    px.resize(n);
    vector<tuple<T, T, T>> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = {x[i], z[i], y[i]};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      px[i] = get<0>(v[i]);
      z[i] = get<1>(v[i]);
      y[i] = get<2>(v[i]);
    }
    cmp.resize(z.size());
    cmp = z;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    compressed.resize(n);
    vector<unsigned> tmp(n), tmpc(n);
    unsigned size_mx = z.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), z[i]));
    }
    stInd.resize(cmp.size() + 1, -1);
    bitsize = bit_width(cmp.size() + 1);
    b.resize(bitsize);
    w.resize(bitsize);
    zero.resize(bitsize, 0);
    vector<bool> bit(n, 0);
    for (unsigned i = 0; i < bitsize; i++) {
      for (unsigned j = 0; j < n; j++) {
        bit[j] = compressed[j] & (1U << (bitsize - i - 1));
        zero[i] += unsigned(!bit[j]);
        tmp[j] = y[j];
        tmpc[j] = compressed[j];
      }
      b[i] = BitVector<T>(bit);
      int cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit[j]) {
          y[cur] = tmp[j];
          compressed[cur] = tmpc[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit[j]) {
          y[cur] = tmp[j];
          compressed[cur] = tmpc[j];
          cur++;
        }
      }
      w[i] = WaveletMatrix<T>(y);
    }
    for (unsigned i = 0; i < n; i++) {
      if (stInd[compressed[i]] == -1) {
        stInd[compressed[i]] = i;
      }
    }
  }

  unsigned rectangle_kth(int l, int r, int d, int u, unsigned k) {
    l = distance(px.begin(), lower_bound(px.begin(), px.end(), l));
    r = distance(px.begin(), lower_bound(px.begin(), px.end(), r));
    return kth_smallest(l, r, d, u, k);
  }

  unsigned space_freq(T xl, T xr, T yl, T yr, T zl, T zr) {
    xl = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));
    xr = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));
    return range_freq(xl, xr, yl, yr, zl, zr);
  }
};