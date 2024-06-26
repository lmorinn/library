#pragma once
class BitVector {
 private:
  unsigned n;
  vector<unsigned> bsum;
  vector<unsigned long long> sum, srsum;
  vector<unsigned long long> h;
  vector<__int128_t> hs;

 public:
  BitVector() {
  }

  BitVector(vector<bool> &b, vector<unsigned> &v) {
    n = b.size();
    bsum.resize(n + 1, 0);
    sum.resize(n + 1, 0);
    srsum.resize(n + 1, 0);
    h.resize(n + 1, 0);
    hs.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      bsum[i + 1] = bsum[i] + int(b[i]);
      sum[i + 1] = sum[i] + v[i];
    }
  }

  inline void srsum_set(const vector<unsigned> &v) {
    for (int i = 0; i < n; i++) {
      srsum[i + 1] = srsum[i] + v[i];
    }
  }

  inline void hash_set(const vector<unsigned long long> &v, const vector<unsigned long long> &s) {
    for (int i = 0; i < n; i++) {
      h[i + 1] = h[i] ^ v[i];
      hs[i + 1] = (hs[i] + __int128_t(s[i]));
    }
  }

  unsigned long long hash_prod(unsigned l, unsigned r) {
    return h[r] ^ h[l];
  }

  __int128_t multihash(unsigned l, unsigned r) {
    return ((hs[r] - hs[l]));
  }

  inline unsigned rank(unsigned k) {
    return bsum[k];
  }

  inline unsigned long long rank_sum(unsigned k) {
    return sum[k];
  }

  inline unsigned long long rank_srsum(unsigned k) {
    return srsum[k];
  }

  inline unsigned select(unsigned k) {
    return distance(bsum.begin() + 1, lower_bound(bsum.begin(), bsum.end(), k));
  }

  inline bool access(unsigned k) {
    return (rank(k + 1) - rank(k)) == 1;
  }
};

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
} rng;

unordered_map<unsigned, unsigned long long> hashmap;

class WaveletMatrix {
 private:
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<BitVector> cnt;
  vector<unsigned> zero, zero2;
  vector<int> stInd, prev;
  vector<unsigned> prev_i;
  vector<unsigned long long> hashA, hashB;
  vector<unsigned> compressed, cmp;

  // prev_i[l,r) の中で値がk未満の個数を返す
  unsigned rank_less_prev(unsigned l, unsigned r, unsigned k) {
    unsigned less = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = cnt[i].rank(l);
      const unsigned rank1_r = cnt[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += (rank0_r - rank0_l);
        l = zero2[i] + rank1_l;
        r = zero2[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return less;
  }

  // v[l,r) の中で値がk未満である要素の多重集合のhash値を返す
  __int128_t less_multihash(unsigned l, unsigned r, unsigned k) {
    __int128_t less = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += b[i].multihash(rank0_l, rank0_r);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return less;
  }

  // v[l,r) の中で値がk未満の個数を返す
  unsigned rank_less(unsigned l, unsigned r, unsigned k) {
    unsigned less = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += (rank0_r - rank0_l);
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
    hashA.resize(n);
    hashB.resize(n);
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    compressed.resize(n);
    prev.resize(cmp.size(), -1);
    vector<unsigned> tmp(n), tmp2(n), tmpc(n);
    vector<unsigned long long> tmph(n), tmph2(n);
    unsigned size_mx = v.size();
    for (unsigned i = 0; i < n; i++) {
      if (hashmap.find(v[i]) == hashmap.end()) hashmap[v[i]] = rng(v[i]);
      hashA[i] = hashmap[v[i]];
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
      if (prev[compressed[i]] != -1) {
        prev_i[i] = prev[compressed[i]];
      } else {
        prev_i[i] = 0;
      }
      prev[compressed[i]] = i + 1;
    }
    hashB = hashA;
    stInd.resize(cmp.size() + 1, -1);
    bitsize = numeric_limits<unsigned int>::digits - __builtin_clz(n);
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
        tmph[j] = hashA[j];
        tmph2[j] = hashB[j];
      }
      b[i] = BitVector(bit, compressed);
      cnt[i] = BitVector(bit2, prev_i);
      int cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit[j]) {
          v[cur] = tmp[j];
          compressed[cur] = tmpc[j];
          hashB[cur] = tmph2[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit[j]) {
          v[cur] = tmp[j];
          compressed[cur] = tmpc[j];
          hashB[cur] = tmph2[j];
          cur++;
        }
      }
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (!bit2[j]) {
          prev_i[cur] = tmp2[j];
          hashA[cur] = tmph[j];
          cur++;
        }
      }
      for (unsigned j = 0; j < n; j++) {
        if (bit2[j]) {
          prev_i[cur] = tmp2[j];
          hashA[cur] = tmph[j];
          cur++;
        }
      }
      b[i].srsum_set(v);
      b[i].hash_set(hashA, hashB);
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
    return cur - stInd[c];
  }

  // v[l,r) の中で値が{k未満の個数、kの個数、kより大きい個数}を返す
  vector<unsigned> rank_less_more(unsigned l, unsigned r, unsigned k) {
    unsigned range = r - l;
    unsigned less = 0;
    unsigned more = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = b[i].rank(l);
      const unsigned rank1_r = b[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        less += (rank0_r - rank0_l);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
      } else {
        more += (rank1_r - rank1_l);
        l = rank0_l;
        r = rank0_r;
      }
    }
    unsigned rank = range - more - less;
    return {less, rank, more};
  }

  // v[l,r) の中でk-1番目に小さい値を返す
  unsigned kth_smallest(unsigned l, unsigned r, unsigned k) {
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

  // v[l,r) を昇順ソートした時の先頭k個の総和を返す
  unsigned long long kth_sum(unsigned l, unsigned r, unsigned k) {
    unsigned long long res = 0;
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
        res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
        k -= num0;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    res += uint64_t(cmp[val]) * uint64_t(k);
    return res;
  }

  // v[l,r) の中で[mink,maxk)に入る値の個数を返す
  unsigned range_freq(unsigned l, unsigned r, unsigned mink, unsigned maxk) {
    mink = compress(mink);
    maxk = compress(maxk);
    return rank_less(l, r, maxk) - rank_less(l, r, mink);
  }

  // v[l,r) の中で[mink,maxk)に入る値の総和を返す
  unsigned long long range_sum(unsigned l, unsigned r, unsigned mink, unsigned maxk) {
    mink = compress(mink);
    maxk = compress(maxk);
    return rank_less_sum(l, r, maxk) - rank_less_sum(l, r, mink);
  }

  // v[l,r) の中の値の種類数を返す
  unsigned range_count(unsigned l, unsigned r) {
    return rank_less_prev(l, r, l + 1);
  }

  // v[l,r) の中でval未満の最大の値を返す
  unsigned prev_value(unsigned l, unsigned r, unsigned val) {
    int num = range_freq(l, r, 0, val);
    if (num == 0) {
      return UINT32_MAX;
    } else {
      return kth_smallest(l, r, num);
    }
  }

  // v[l,r) の中でval以上の最小の値を返す
  unsigned next_value(unsigned l, unsigned r, unsigned val) {
    int num = range_freq(l, r, 0, val);
    if (num == r - l) {
      return UINT32_MAX;
    } else {
      return kth_smallest(l, r, num + 1);
    }
  }

  // v[l,r) の重複を除いた要素のhashを返す
  unsigned long long range_hash(unsigned l, unsigned r) {
    unsigned k = l + 1;
    unsigned long long h = 0;
    for (unsigned i = 0; i < bitsize and l < r; i++) {
      const unsigned rank1_l = cnt[i].rank(l);
      const unsigned rank1_r = cnt[i].rank(r);
      const unsigned rank0_l = l - rank1_l;
      const unsigned rank0_r = r - rank1_r;
      if (k & (1U << (bitsize - i - 1))) {
        h ^= b[i].hash_prod(rank0_l, rank0_r);
        l = zero2[i] + rank1_l;
        r = zero2[i] + rank1_r;
      } else {
        l = rank0_l;
        r = rank0_r;
      }
    }
    return h;
  }

  // [l,r) の中で[mink,maxk)に入る値の多重集合のhashを返す
  __int128_t range_hash_multi(unsigned l, unsigned r, unsigned mink, unsigned maxk) {
    maxk = compress(maxk);
    mink = compress(mink);
    return (less_multihash(l, r, maxk) - less_multihash(l, r, mink));
  }

  // v[l1,r1) の要素の集合とv[l2,r2) の要素の集合が等しいかどうかを返す
  bool range_equal(unsigned l1, unsigned r1, unsigned l2, unsigned r2) {
    return range_hash(l1, r1) == range_hash(l2, r2);
  }

  // v[l1,r1)の[mink1,maxk1) に値が入る要素の多重集合とv[l2,r2) の[mink2,maxk2) に値が入る要素の多重集合が等しいかどうかを返す
  bool range_equal_multi(unsigned l1, unsigned r1, unsigned mink1, unsigned maxk1, unsigned l2, unsigned r2, unsigned mink2, unsigned maxk2) {
    return range_hash_multi(l1, r1, mink1, maxk1) == range_hash_multi(l2, r2, mink2, maxk2);
  }
};