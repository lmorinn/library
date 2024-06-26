#pragma once
template <class T>
class BIT {
 private:
  unsigned n;
  vector<T> a;
  vector<bool> active;

  T sum_sub(unsigned i) {
    i++;
    T s = 0;
    if (i == 0) return s;
    for (unsigned k = i; k > 0; k -= (k & -k)) {
      s += a[k];
    }
    return s;
  }

 public:
  BIT() {}
  BIT(unsigned siz) {
    n = siz;
    a.resize(n + 1, 0);
    active.resize(n, false);
  }

  // a[i] on
  inline void on(unsigned i, unsigned x = 1) {
    if (active[i]) return;
    active[i] = true;
    i++;
    if (i == 0) return;
    for (unsigned k = i; k <= n; k += (k & -k)) {
      a[k] += x;
    }
  }

  // a[i] off
  inline void off(unsigned i, unsigned x = 1) {
    if (!active[i]) return;
    active[i] = false;
    i++;
    if (i == 0) return;
    for (unsigned k = i; k <= n; k += (k & -k)) {
      a[k] -= x;
    }
  }

  // active a[i,j)
  inline T cnt(unsigned i, unsigned j) {
    if (i >= j) return 0;
    return sum_sub(j - 1) - sum_sub(i - 1);
  }
};

class BitVector {
 private:
  unsigned n, cur, p;
  vector<unsigned> acc, bit;
  BIT<unsigned> active0, active1;
  BIT<unsigned long long> active0sum, active1sum;

 public:
  BitVector() {
  }

  BitVector(vector<bool> &b, vector<unsigned> &v) {
    cur = 0;
    n = b.size();
    acc.resize(n / 32 + 2, 0);
    bit.resize(n / 32 + 2, 0);
    active0 = BIT<unsigned>(n);
    active1 = BIT<unsigned>(n);
    active0sum = BIT<unsigned long long>(n);
    active1sum = BIT<unsigned long long>(n);
    for (int i = 0; i < n; i++) {
      p = i % 32;
      if (p == 0) {
        cur++;
        acc[cur] = acc[cur - 1];
      }

      if (b[i]) {
        active1.on(i);
        acc[cur] += int(b[i]);
        bit[cur - 1] |= (1U << (32 - p - 1));
      } else {
        active0.on(i);
      }
    }
  }

  inline void srsum_set(const vector<unsigned> &v, unsigned zero) {
    for (int i = 0; i < zero; i++) {
      active0sum.on(i, v[i]);
    }
    for (int i = zero; i < n; i++) {
      active1sum.on(i, v[i]);
    }
  }

  inline unsigned rank(unsigned k) {
    if (!(k & 31)) return acc[k / 32];
    return acc[k / 32] + __builtin_popcount(bit[k / 32] >> (32 - (k & 31)));
  }

  inline unsigned ac1(unsigned l, unsigned r) {
    return active1.cnt(l, r);
  }

  inline unsigned ac0(unsigned l, unsigned r) {
    return active0.cnt(l, r);
  }

  inline unsigned ac1sum(unsigned l, unsigned r) {
    return active1sum.cnt(l, r);
  }

  inline unsigned ac0sum(unsigned l, unsigned r) {
    return active0sum.cnt(l, r);
  }

  inline void on(unsigned k, bool f) {
    if (f) {
      active1.on(k);
    } else {
      active0.on(k);
    }
  }

  inline void off(unsigned k, bool f) {
    if (f) {
      active1.off(k);
    } else {
      active0.off(k);
    }
  }

  inline void ons(unsigned k, bool f, unsigned x) {
    if (f) {
      active1sum.on(k, x);
    } else {
      active0sum.on(k, x);
    }
  }

  inline void offs(unsigned k, bool f, unsigned x) {
    if (f) {
      active1sum.off(k, x);
    } else {
      active0sum.off(k, x);
    }
  }

  inline unsigned long long rank_srsum(unsigned k) {
    return active0sum.cnt(0, k) + active1sum.cnt(0, k);
  }

  inline bool access(unsigned k) {
    return (rank(k + 1) - rank(k)) == 1;
  }
};

class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<BitVector> cnt;
  vector<unsigned> zero, zero2;
  vector<int> stInd, prev;
  vector<unsigned> prev_i;
  vector<unsigned> compressed, cmp;
  BIT<unsigned> activeleaf;

  // prev_i[l,r) の中で値がk未満の個数を返す
  unsigned rank_less_prev(unsigned l, unsigned r, unsigned k) {
    unsigned less = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = cnt[i].rank(l);
      const unsigned rank1_r = cnt[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += cnt[i].ac0(l, r);
        l = zero2[i] + rank1_l;
        r = zero2[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return less;
  }

  // v[l,r) の中で値がk未満の個数を返す
  unsigned rank_less(unsigned l, unsigned r, unsigned k) {
    k = compress(k);
    unsigned less = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += b[i].ac0(l, r);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return less;
  }

  // v[l,r) の中で値がk未満の総和を返す
  unsigned long long rank_less_sum(unsigned l, unsigned r, unsigned k) {
    k = compress(k);
    unsigned long long less_sum = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return less_sum;
  }

  // 座標圧縮
  inline unsigned compress(const unsigned &x) {
    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
  }

 public:
  // コンストラクタ
  WaveletMatrix() {}
  WaveletMatrix(vector<unsigned> v) {
    n = v.size();
    prev_i.resize(n);
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    compressed.resize(n);
    activeleaf = BIT<unsigned>(n);
    prev.resize(cmp.size(), -1);
    vector<unsigned> tmp(n), tmp2(n), tmpc(n);
    unsigned size_mx = v.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
      if (prev[compressed[i]] != -1) {
        prev_i[i] = prev[compressed[i]];
      } else {
        prev_i[i] = 0;
      }
      prev[compressed[i]] = i + 1;
      activeleaf.on(i);
    }
    stInd.resize(cmp.size() + 1, -1);
    bitsize = bit_width(size_mx);
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
        tmp[j] = v[j];
        tmp2[j] = prev_i[j];
        tmpc[j] = compressed[j];
      }
      b[i] = BitVector(bit, compressed);
      cnt[i] = BitVector(bit2, prev_i);
      int cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit[j]) {
          v[cur] = tmp[j];
          compressed[cur] = tmpc[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit[j]) {
          v[cur] = tmp[j];
          compressed[cur] = tmpc[j];
          cur++;
        }
      }
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit2[j]) {
          prev_i[cur] = tmp2[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit2[j]) {
          prev_i[cur] = tmp2[j];
          cur++;
        }
      }
      b[i].srsum_set(v, zero[i]);
    }

    for (unsigned i = 0; i < n; i++) {
      if (stInd[compressed[i]] == -1) {
        stInd[compressed[i]] = i;
      }
    }
  }

  // get v[k]
  unsigned access(unsigned k) {
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

  // v[k] のoff状態を解除する
  void on(unsigned k) {
    unsigned cur = k;
    unsigned cur2 = k;
    unsigned element = access(k);
    for (unsigned i = 0; i < bitsize; i++) {
      if (b[i].access(cur)) {
        b[i].on(cur, 1);
        cur = zero[i] + b[i].rank(cur);
        b[i].ons(cur, 1, element);
      } else {
        b[i].on(cur, 0);
        cur -= b[i].rank(cur);
        b[i].ons(cur, 0, element);
      }

      if (cnt[i].access(cur2)) {
        cnt[i].on(cur2, 1);
        cur2 = zero2[i] + cnt[i].rank(cur2);
      } else {
        cnt[i].on(cur2, 0);
        cur2 -= cnt[i].rank(cur2);
      }
    }
    activeleaf.on(cur);
  }

  // v[k] をoff状態にしこれ以降のクエリで無視する
  void off(unsigned k) {
    unsigned cur = k;
    unsigned cur2 = k;
    unsigned element = access(k);
    for (unsigned i = 0; i < bitsize; i++) {
      if (b[i].access(cur)) {
        b[i].off(cur, 1);
        cur = zero[i] + b[i].rank(cur);
        b[i].offs(cur, 1, element);
      } else {
        b[i].off(cur, 0);
        cur -= b[i].rank(cur);
        b[i].offs(cur, 0, element);
      }

      if (cnt[i].access(cur2)) {
        cnt[i].off(cur2, 1);
        cur2 = zero2[i] + cnt[i].rank(cur2);
      } else {
        cnt[i].off(cur2, 0);
        cur2 -= cnt[i].rank(cur2);
      }
    }
    activeleaf.off(cur);
  }

  // v[0,k) 中でのcの出現回数を返す
  unsigned rank(unsigned k, unsigned c) {
    c = compress(c);
    unsigned cur = k;
    if (stInd[c] == -1) {
      return 0;
    }
    for (unsigned i = 0; i < bitsize; i++) {
      if (c & (1U << (bitsize - i - 1))) {
        cur = zero[i] + b[i].rank(cur);
      } else {
        cur -= b[i].rank(cur);
      }
    }
    return activeleaf.cnt(stInd[c], cur);
  }

  // v[l,r) の中で値が{k未満の個数、kの個数、kより大きい個数}を返す
  vector<unsigned> rank_less_more(unsigned l, unsigned r, unsigned k) {
    k = compress(k);
    unsigned range = b[0].ac0(l, r) + b[0].ac1(l, r);
    unsigned less = 0;
    unsigned more = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].ac1(0, l);
      const unsigned rank1_r = b[i].ac1(0, r);
      if (k & (1U << (bitsize - i - 1))) {
        less += b[i].ac0(l, r);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
      } else {
        more += b[i].ac1(l, r);
        l -= rank1_l;
        r -= rank1_r;
      }
    }
    unsigned rank = range - more - less;
    return {less, rank, more};
  }

  // v[l,r) の中でk-1番目に小さい値を返す
  unsigned kth_smallest(unsigned l, unsigned r, unsigned k) {
    unsigned res = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      const unsigned rank1_l = b[i].ac1(0, l);
      const unsigned rank1_r = b[i].ac1(0, r);
      unsigned num0 = b[i].ac0(l, r);
      if (num0 < k) {
        res |= (1ULL << (bitsize - i - 1));
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

  // v[l,r]を昇順ソートした時の先頭k個の総和を返す
  unsigned long long kth_sum(unsigned l, unsigned r, unsigned k) {
    unsigned long long res = 0;
    unsigned val = 0;
    for (unsigned i = 0; i < bitsize; i++) {
      const unsigned rank1_l = b[i].ac1(0, l);
      const unsigned rank1_r = b[i].ac1(0, r);
      const unsigned rank0_l = b[i].ac0(0, l);
      const unsigned rank0_r = b[i].ac0(0, r);
      unsigned num0 = rank0_r - rank0_l;
      if (num0 < k) {
        val |= (1ULL << (bitsize - i - 1));
        res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
        k -= num0;
      } else {
        l -= rank1_l;
        r -= rank1_r;
      }
    }
    res += uint64_t(cmp[val]) * uint64_t(k);
    return res;
  }

  // v[l,r) の中で[mink,maxk)に入る値の個数を返す
  unsigned range_freq(unsigned l, unsigned r, unsigned mink, unsigned maxk) {
    return rank_less(l, r, maxk) - rank_less(l, r, mink);
  }

  // v[l,r) の中で[mink,maxk)に入る値の総和を返す
  unsigned long long range_sum(unsigned l, unsigned r, unsigned mink, unsigned maxk) {
    return rank_less_sum(l, r, maxk) - rank_less_sum(l, r, mink);
  }

  // v[l,r) の中の値の種類数を返す
  unsigned range_count(unsigned l, unsigned r) {
    return rank_less_prev(l, r, l + 1);
  }

  // v[l,r)の中でvalを超えない最大の値を返す
  unsigned prev_value(unsigned l, unsigned r, unsigned val) {
    int num = range_freq(l, r, 0, val);
    if (num == 0) {
      return UINT32_MAX;
    } else {
      return kth_smallest(l, r, num);
    }
  }

  // v[l,r)の中でval以上の最小の値を返す
  unsigned next_value(unsigned l, unsigned r, unsigned val) {
    int num = range_freq(l, r, 0, val);
    if (num == r - l) {
      return UINT32_MAX;
    } else {
      return kth_smallest(l, r, num + 1);
    }
  }
};