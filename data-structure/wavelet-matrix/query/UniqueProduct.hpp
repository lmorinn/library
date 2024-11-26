template <class T, auto op, auto e>
class BitVector {
 private:
  unsigned n, cur, p;
  vector<unsigned> acc, bit;
  segtree<T, op, e> seg;

 public:
  BitVector() {
  }

  BitVector(vector<bool> &b) {
    cur = 0;
    n = b.size();
    acc.resize((n >> 5) + 2, 0);
    bit.resize((n >> 5) + 2, 0);
    for (int i = 0; i < n; i++) {
      if (!(i & 31)) {
        cur++;
        acc[cur] = acc[cur - 1];
      }
      if (b[i]) {
        acc[cur] += int(b[i]);
        bit[cur - 1] |= (1U << (32 - (i & 31) - 1));
      }
    }
  }

  inline void seg_set(const vector<T> &v) {
    seg = segtree<T, op, e>(v);
  }

  inline void val_set(unsigned pos, T x) {
    seg.set(pos, x);
  }
  inline void val_get(unsigned pos, T x) {
    seg.get(pos, x);
  }

  inline unsigned rank(unsigned k) {
    if (!(k & 31)) return acc[k >> 5];
    return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));
  }

  inline unsigned rank0(unsigned k) {
    return k - rank(k);
  }

  inline T rank_prod(unsigned l, unsigned r) {
    return seg.prod(l, r);
  }

  inline bool access(unsigned k) {
    return (rank(k + 1) - rank(k)) == 1;
  }
};

template <class T, auto op, auto e>
class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector<T, op, e>> b;
  vector<BitVector<T, op, e>> cnt;
  vector<unsigned> zero, zero2;
  vector<unsigned> prev_i;

 public:
  // コンストラクタ
  WaveletMatrix() {}

  WaveletMatrix(vector<T> v, vector<T> w) {
    n = v.size();
    vector<int> prev;
    prev_i.resize(n);
    vector<unsigned> compressed(n);
    vector<T> cmp(n);
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    prev.resize(cmp.size(), -1);
    vector<unsigned> tmp2(n), tmpc(n);
    vector<T> tmp(n);
    unsigned size_mx = v.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
      if (prev[compressed[i]] != -1) {
        prev_i[i] = prev[compressed[i]];
      } else {
        prev_i[i] = 0;
      }
      prev[compressed[i]] = i + 1;
    }
    bitsize = bit_width(n);
    b.resize(bitsize);
    cnt.resize(bitsize);
    zero.resize(bitsize, 0);
    zero2.resize(bitsize, 0);
    vector<bool> bit(n, 0), bit2(n, 0);
    for (unsigned i = 0; i < bitsize; i++) {
      for (unsigned j = 0; j < n; j++) {
        bit[j] = compressed[j] & (1U << (bitsize - i - 1));
        zero[i] += unsigned(!bit[j]);
        bit2[j] = prev_i[j] & (1U << (bitsize - i - 1));
        zero2[i] += unsigned(!bit2[j]);
        tmp[j] = w[j];
        tmp2[j] = prev_i[j];
        tmpc[j] = compressed[j];
      }
      b[i] = BitVector<T, op, e>(bit);
      cnt[i] = BitVector<T, op, e>(bit2);
      int cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit[j]) {
          compressed[cur] = tmpc[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit[j]) {
          compressed[cur] = tmpc[j];
          cur++;
        }
      }
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit2[j]) {
          w[cur] = tmp[j];
          prev_i[cur] = tmp2[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit2[j]) {
          w[cur] = tmp[j];
          prev_i[cur] = tmp2[j];
          cur++;
        }
      }
      b[i].seg_set(w);
    }
  }

  // v[l,r) の中で重複を除いた値の総積を返す
  T unique_prod(unsigned l, unsigned r) {
    unsigned k = l + 1;
    T res = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = cnt[i].rank(l);
      const unsigned rank1_r = cnt[i].rank(r);
      const unsigned rank0_l = cnt[i].rank0(l);
      const unsigned rank0_r = cnt[i].rank0(r);
      if (k & (1U << (bitsize - i - 1))) {
        res = op(res, b[i].rank_prod(rank0_l, rank0_r));
        l = zero2[i] + rank1_l;
        r = zero2[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return res;
  }
};