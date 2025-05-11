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

template <class T>
class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<unsigned> zero;
  vector<T> cmp;
  T MI, MA;

  inline unsigned compress(const T &x) {
    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
  }

 public:
  // コンストラクタ
  WaveletMatrix() {}
  WaveletMatrix(const vector<T> &v) {
    MI = numeric_limits<T>::min();
    MA = numeric_limits<T>::max();
    n = v.size();
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    vector<unsigned> compressed(n);
    vector<unsigned> tmpc(n);
    unsigned size_mx = v.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = compress(v[i]);
    }
    bitsize = bit_width(cmp.size());
    b.resize(bitsize);
    zero.assign(bitsize, 0);
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

      for (unsigned j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      swap(tmpc, compressed);
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

  // v[l,r) の中でk番目(1-origin)に小さい値を返す
  T kth_smallest(unsigned l, unsigned r, unsigned k) {
    unsigned res = 0;
    unsigned rank1_l, rank1_r, num0;
    for (unsigned i = 0; i < bitsize; i++) {
      rank1_l = b[i].rank(l);
      rank1_r = b[i].rank(r);
      num0 = r - l - (rank1_r - rank1_l);
      if (num0 < k) {
        res |= (1U << (bitsize - i - 1));
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
        k -= num0;
      } else {
        l -= rank1_l;
        r -= rank1_r;
      }
    }
    return cmp[res];
  }

  // v[l,r) の中でk番目(1-origin)に大きい値を返す
  T kth_largest(unsigned l, unsigned r, unsigned k) {
    return kth_smallest(l, r, r - l - k + 1);
  }

  // v[l,r) の中で[mink,maxk)に入る値の個数を返す
  unsigned range_freq(int vl, int vr, T mink, T maxk) {
    int D = compress(mink);
    int U = compress(maxk);
    unsigned res = 0;
    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
      if (U <= A or B <= D) return;
      if (D <= A and B <= U) {
        res += (R - L);
        return;
      }
      if (d == bitsize) {
        if (D <= A and A < U) {
          res += (R - L);
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

	// v[l,r)の中でval未満の要素のうち最大の値を返す
  T prev_value(unsigned l, unsigned r, T val) {
    int num = range_freq(l, r, MI, val);
    if (num == 0) {
      return MA;
    } else {
      return kth_smallest(l, r, num);
    }
  }

  // v[l,r)の中でvalより大きい要素のうち最小の値を返す
  T next_value(unsigned l, unsigned r, T val) {
    int num = range_freq(l, r, MI, val + 1);
    if (num == r - l) {
      return MI;
    } else {
      return kth_smallest(l, r, num + 1);
    }
  }
};