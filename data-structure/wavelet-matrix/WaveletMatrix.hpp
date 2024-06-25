#pragma once
class BitVector {
 private:
  unsigned n, cur, p;
  vector<unsigned> acc, bit;

 public:
  BitVector() {
  }

  BitVector(vector<bool> &b, vector<unsigned> &v) {
    cur = 0;
    n = b.size();
    acc.resize(n / 32 + 2, 0);
    bit.resize(n / 32 + 2, 0);
    for (int i = 0; i < n; i++) {
      p = i % 32;
      if (p == 0) {
        cur++;
        acc[cur] = acc[cur - 1];
      }
      if (b[i]) {
        acc[cur] += int(b[i]);
        bit[cur - 1] |= (1U << (32 - p - 1));
      }
    }
  }

  inline unsigned rank(unsigned k) {
    if (!(k & 31)) return acc[k / 32];
    return acc[k / 32] + __builtin_popcount(bit[k / 32] >> (32 - (k & 31)));
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
  vector<unsigned> zero;
  vector<int> stInd;
  vector<unsigned> compressed, cmp;

  inline unsigned compress(const unsigned &x) {
    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
  }

 public:
  // コンストラクタ
  WaveletMatrix() {}
  WaveletMatrix(vector<unsigned> v) {
    n = v.size();
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    compressed.resize(n);
    vector<unsigned> tmpc(n);
    unsigned size_mx = v.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));
    }
    stInd.resize(cmp.size() + 1, -1);
    bitsize = bit_width(size_mx);
    b.resize(bitsize);
    cnt.resize(bitsize);
    zero.resize(bitsize, 0);
    vector<bool> bit(n, 0);
    for (unsigned i = 0; i < bitsize; i++) {
      for (unsigned j = 0; j < n; j++) {
        bit[j] = compressed[j] & (1U << (bitsize - i - 1));
        zero[i] += unsigned(!bit[j]);
        tmpc[j] = compressed[j];
      }
      b[i] = BitVector(bit, compressed);
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

  // v[l,r) の中で[mink,maxk)に入る値の個数を返す
  unsigned range_freq(unsigned l, unsigned r, unsigned mink, unsigned maxk) {
    mink = compress(mink);
    maxk = compress(maxk);
    return rank_less(l, r, maxk) - rank_less(l, r, mink);
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
