#include "../binary-indexed-tree/DualBinaryIndexedTree.hpp"
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
  vector<unsigned> zero;
  vector<T> cmp;
  vector<S> arr;
  vector<RangeAddPointGet<S>> fen;

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
    fen.resize(bitsize + 1, RangeAddPointGet<S>(n));
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
    fen.resize(bitsize + 1, RangeAddPointGet<S>(n));
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
    S val = arr[k];
    unsigned cur = k;
    for (unsigned i = 0; i < bitsize; i++) {
      val += fen[i].point_get(cur);
      if (b[i].access(cur)) {
        cur = zero[i] + b[i].rank(cur);
      } else {
        cur -= b[i].rank(cur);
      }
    }
    val += fen[bitsize].point_get(cur);
    return val;
  }

  void range_add(int l, int r, T mink, T maxk, S x) {
    int D = compress(mink);
    int U = compress(maxk);
    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
      if (U <= A or B <= D) return;
      if (D <= A and B <= U) {
        fen[d].range_add(L, R, x);
        return;
      }
      if (d == bitsize) {
        if (D <= A and A < U) {
          fen[bitsize].range_add(L, R, x);
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