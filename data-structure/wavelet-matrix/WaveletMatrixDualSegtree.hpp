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
  DualSegmentTree(int sz) {
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

template <class S, class F, auto mapping, auto composition, auto id, class T>
class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<unsigned> zero;
  vector<T> cmp;
  vector<S> arr;
  vector<DualSegmentTree<S, F, mapping, composition, id>> seg;

  inline unsigned compress(const T &x) {
    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
  }

 public:
  // コンストラクタ
  WaveletMatrix() {}

  WaveletMatrix(vector<T> v) {
    n = v.size();
    arr = v;
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    vector<T> tmpc(n);
    vector<T> compressed(n);
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
    }
    bitsize = bit_width(cmp.size());
    b.resize(bitsize + 1);
    seg.resize(bitsize + 1, DualSegmentTree<S, F, mapping, composition, id>(n));
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector(n + 1);
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          b[i].set(j);
        } else {
          zero[i]++;
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      b[i].build();
      for (int j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      swap(tmpc, compressed);
    }
    b[bitsize] = BitVector(n + 1);
  }

  WaveletMatrix(vector<T> v, vector<S> w) {
    n = v.size();
    arr = w;
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    vector<T> tmpc(n);
    vector<T> compressed(n);
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
    }
    bitsize = bit_width(cmp.size());
    seg.resize(bitsize + 1, DualSegmentTree<S, F, mapping, composition, id>(n));
    b.resize(bitsize + 1);
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector(n + 1);
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          b[i].set(j);
        } else {
          zero[i]++;
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      b[i].build();
      for (int j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      swap(tmpc, compressed);
    }
    b[bitsize] = BitVector(n + 1);
  }

  S get(unsigned k) {
    F f = id();
    S val = arr[k];
    unsigned cur = k;
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

  void range_apply(int l, int r, T mink, T maxk, F x) {
    int D = compress(mink);
    int U = compress(maxk);
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
    dfs(dfs, 0, l, r, 0, 1 << bitsize);
  }
};