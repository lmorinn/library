
using S = tuple<mint, mint, mint, mint>;

S op(const S &a, const S &b) {
  auto &[a1, a2, a3, a4] = a;
  auto &[b1, b2, b3, b4] = b;
  return {a1 + b1, a2 + b2, a3 + b3, a4 + b4};
}

void print(const S &a) {
  auto &[a1, a2, a3, a4] = a;
  out(a1.val(), a2.val(), a3.val(), a4.val());
}

S e() {
  return {0, 0, 0, 0};
}

S operator+(const S &a, const S &b) {
  return op(a, b);
}

S operator-(const S &a, const S &b) {
  auto &[a1, a2, a3, a4] = a;
  auto &[b1, b2, b3, b4] = b;
  return {a1 - b1, a2 - b2, a3 - b3, a4 - b4};
}

struct BitVector {
  unsigned sz;
  unsigned blocksize;
  vector<unsigned long long> bit;
  vector<unsigned> sum;
  vector<S> srsum;

  BitVector() {}

  BitVector(unsigned siz) {
    sz = siz;
    blocksize = (sz + 63) >> 6;
    bit.assign(blocksize, 0ULL);
    sum.assign(blocksize, 0U);
    srsum.resize(sz);
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

  inline void srsum_set(vector<S> &v) {
    for (int i = 0; i < sz - 1; i++) {
      srsum[i + 1] = srsum[i] + v[i];
    }
  }

  inline S rank_srsum(int l, int r) {
    return srsum[r] - srsum[l];
  }

  inline S rank_srsum(int r) {
    return srsum[r];
  }
};

class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize, logn;
  vector<BitVector> b;
  vector<unsigned> zero;
  vector<int> cmp;
  vector<int> px;
  int MI, MA;

  inline unsigned compress(const int &x) {
    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
  }

 public:
  // コンストラクタ
  WaveletMatrix() {}

  WaveletMatrix(vector<int> x, vector<int> y, vector<S> w) {
    n = x.size();
    px.resize(n);
    vector<tuple<int, int, S>> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = {x[i], y[i], w[i]};
    }
    sort(v.begin(), v.end(), [](const tuple<int, int, S> &l, const tuple<int, int, S> &r) {
      return std::get<0>(l) < std::get<0>(r);
    });
    for (int i = 0; i < n; i++) {
      px[i] = std::get<0>(v[i]);
      y[i] = std::get<1>(v[i]);
      w[i] = std::get<2>(v[i]);
    }
    vector<unsigned> compressed(n);
    cmp.resize(y.size());
    cmp = y;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    vector<unsigned> tmpc(n);
    vector<S> tmp(n);
    unsigned size_mx = y.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y[i]));
    }
    bitsize = bit_width(cmp.size());
    b.resize(bitsize + 1);
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector(n + 1);
      b[i].srsum_set(w);
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

    b[bitsize] = BitVector(n + 1);
    b[bitsize].srsum_set(w);
  }

  // v[l,r) の中で[mink,maxk)に入る値の総和を返す
  S range_sum(int vl, int vr, int mink, int maxk) {
    int D = mink;
    int U = compress(maxk);
    S res = e();
    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
      if (U <= A or B <= D) return;
      if (D <= A and B <= U) {
        res = op(res, b[d].rank_srsum(L, R));
        return;
      }
      if (d == bitsize) {
        if (D <= A and A < U) {
          res = op(res, b[bitsize].rank_srsum(L, R));
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

  // x座標が[l,r) かつy座標が[d,u) に入る点の総積を返す
  S rectangle_sum(int l, int r, int d, int u) {
    unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(), r));
    return range_sum(l, cr, d, u);
  }
};

class RectangleAddRectangleSum {
 private:
  vector<int> x, y;
  vector<S> z;
  WaveletMatrix wm;

 public:
  RectangleAddRectangleSum(const vector<int> &x1, const vector<int> &y1, const vector<int> &x2, const vector<int> &y2, const vector<int> &weight) {
    int n = x1.size();
    x.resize(n * 4);
    y.resize(n * 4);
    z.resize(n * 4);

    for (int i = 0; i < n; i++) {
      int xl = x1[i];
      int yl = y1[i];
      int xr = x2[i];
      int yr = y2[i];
      mint w = weight[i];
      x[i * 4] = xl;
      y[i * 4] = yl;
      z[i * 4] = {w, w * -yl, w * -xl, w * +xl * yl};

      x[i * 4 + 1] = xl;
      y[i * 4 + 1] = yr;
      z[i * 4 + 1] = {-w, w * +yr, w * xl, w * -xl * yr};

      x[i * 4 + 2] = xr;
      y[i * 4 + 2] = yl;
      z[i * 4 + 2] = {-w, w * yl, w * xr, w * -xr * yl};

      x[i * 4 + 3] = xr;
      y[i * 4 + 3] = yr;
      z[i * 4 + 3] = {w, w * -yr, w * -xr, w * xr * yr};
    }

    wm = WaveletMatrix(x, y, z);
  }

  mint rectangle_sum(int xl, int yl, int xr, int yr) {
    mint resp = 0;
    mint resn = 0;
    {
      auto [a, b, c, d] = wm.rectangle_sum(0, xl, 0, yl);
      resp += a * xl * yl;
      resp += b * xl;
      resp += c * yl;
      resp += d;
    }
    {
      auto [a, b, c, d] = wm.rectangle_sum(0, xl, 0, yr);
      resn += a * xl * yr;
      resn += b * xl;
      resn += c * yr;
      resn += d;
    }
    {
      auto [a, b, c, d] = wm.rectangle_sum(0, xr, 0, yl);
      resn += a * xr * yl;
      resn += b * xr;
      resn += c * yl;
      resn += d;
    }
    {
      auto [a, b, c, d] = wm.rectangle_sum(0, xr, 0, yr);
      resp += a * xr * yr;
      resp += b * xr;
      resp += c * yr;
      resp += d;
    }
    return resp - resn;
  }
};
