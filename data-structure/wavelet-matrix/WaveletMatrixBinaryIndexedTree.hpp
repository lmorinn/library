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

template <class S, class T>
class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<fenwick_tree<S>> fen;
  vector<unsigned> zero;
  vector<T> cmp;
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
    fen.resize(bitsize + 1);
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector(n + 1);
      fen[i] = fenwick_tree<T>(n);
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        fen[i].add(j, v[j]);
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
    b[bitsize] = BitVector(n + 1);
    fen[bitsize] = fenwick_tree<T>(n);
    for (unsigned i = 0; i < n; i++) {
      fen[bitsize].add(i, v[i]);
    }
  }

  WaveletMatrix(vector<T> v, vector<S> w) {
    MI = numeric_limits<T>::min();
    MA = numeric_limits<T>::max();
    n = v.size();
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    vector<S> tmp(n);
    vector<T> tmpc(n);
    vector<T> compressed(n);
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
    }
    bitsize = bit_width(cmp.size());
    b.resize(bitsize + 1);
    fen.resize(bitsize + 1);
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector(n + 1);
      fen[i] = fenwick_tree<S>(n);
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        fen[i].add(j, w[j]);
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
    fen[bitsize] = fenwick_tree<S>(n);
    for (unsigned i = 0; i < n; i++) {
      fen[bitsize].add(i, w[i]);
    }
  }

  void set(int p, S x) {
    unsigned cur = p;
    S before = fen[0].get(p);
    for (unsigned i = 0; i < bitsize; i++) {
      fen[i].add(cur, x - before);
      if (b[i].access(cur)) {
        cur = zero[i] + b[i].rank(cur);
      } else {
        cur -= b[i].rank(cur);
      }
    }
    fen[bitsize].add(cur, x - before);
  }

  void add(int p, S x) {
    unsigned cur = p;
    for (unsigned i = 0; i < bitsize; i++) {
      fen[i].add(cur, x);
      if (b[i].access(cur)) {
        cur = zero[i] + b[i].rank(cur);
      } else {
        cur -= b[i].rank(cur);
      }
    }
    fen[bitsize].add(cur, x);
  }

  S get(int p) {
    return fen[0].get(p);
  }

  // v[l,r) の中で[mink,maxk)に入る値の総和を返す
  S range_sum(int vl, int vr, T mink, T maxk) {
    int D = compress(mink);
    int U = compress(maxk);
    S res = 0;
    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
      if (U <= A or B <= D) return;
      if (D <= A and B <= U) {
        res += fen[d].sum(L, R);
        return;
      }
      if (d == bitsize) {
        if (D <= A and A < U) {
          res += fen[bitsize].sum(L, R);
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
};