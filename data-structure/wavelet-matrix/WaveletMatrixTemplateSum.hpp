
template <class T>
struct BitVector {
  unsigned sz;
  unsigned blocksize;
  vector<unsigned long long> bit;
  vector<unsigned> sum;
  vector<T> srsum;

  BitVector() {}

  BitVector(unsigned siz) {
    sz = siz;
    blocksize = (sz + 63) >> 6;
    bit.assign(blocksize, 0ULL);
    sum.assign(blocksize, 0U);
    srsum.assign(sz, 0);
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

  inline void srsum_set(vector<T> &v) {
    for (int i = 0; i < sz - 1; i++) {
      srsum[i + 1] = srsum[i] + v[i];
    }
  }

  inline T rank_srsum(int l, int r) {
    return srsum[r] - srsum[l];
  }

  inline T rank_srsum(int r) {
    return srsum[r];
  }
};

template <class T, class S>
class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector<S>> b;
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
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector<T>(n + 1);
      b[i].srsum_set(v);
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
    b[bitsize].srsum_set(v);
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
    zero.resize(bitsize, 0);
    int cur = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector<S>(n + 1);
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
    b[bitsize] = BitVector<S>(n + 1);
    b[bitsize].srsum_set(w);
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

  // v[l,r]を昇順ソートした時の先頭k個の総和を返す
  S kth_ascending_sum(unsigned l, unsigned r, unsigned k) {
    S res = 0;
    unsigned val = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      const unsigned num1 = rank1_r - rank1_l;
      const unsigned num0 = rank0_r - rank0_l;
      if (num0 < k) {
        val |= (1ULL << (bitsize - i - 1));
        res += b[i + 1].rank_srsum(rank0_r) - b[i + 1].rank_srsum(rank0_l);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
        k -= num0;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    res += int64_t(cmp[val]) * (k);
    return res;
  }

  // v[l,r]を降順ソートした時の先頭k個の総和を返す
  S kth_descending_sum(unsigned l, unsigned r, unsigned k) {
    return range_sum(l, r, MI, MA) - kth_ascending_sum(l, r, r - l - k);
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

  // v[l,r) の中で[mink,maxk)に入る値の総和を返す
  S range_sum(int vl, int vr, T mink, T maxk) {
    int D = compress(mink);
    int U = compress(maxk);
    S res = 0;
    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
      if (U <= A or B <= D) return;
      if (D <= A and B <= U) {
        res = res + b[d].rank_srsum(L, R);
        return;
      }
      if (d == bitsize) {
        if (D <= A and A < U) {
          res = res + b[d].rank_srsum(L, R);
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

  // v[l,r) の中で ∑|v[i]-d| を計算して返す
  S range_abs(unsigned l, unsigned r, T d) {
    int dnum = range_freq(l, r, d, d + 1);
    S dsum = d * dnum;
    S asum = range_sum(l, r, MI, MA);
    int less = range_freq(l, r, MI, d);
    S less_sum = range_sum(l, r, MI, d);
    int more = r - l - dnum - less;
    S more_sum = asum - dsum - less_sum;
    return d * less + more_sum - less_sum - (d * more);
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
};