---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AtCoder/data-structure/wavelet-matrix/PrefixEquality.test.cpp
    title: verify/AtCoder/data-structure/wavelet-matrix/PrefixEquality.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet-matrix/WaveletMatrixHash.hpp\"\n\
    class BitVector {\n private:\n  unsigned n;\n  vector<unsigned> bsum;\n  vector<unsigned\
    \ long long> sum, srsum;\n  vector<unsigned long long> h;\n  vector<__int128_t>\
    \ hs;\n\n public:\n  BitVector() {\n  }\n\n  BitVector(vector<bool> &b, vector<unsigned>\
    \ &v) {\n    n = b.size();\n    bsum.resize(n + 1, 0);\n    sum.resize(n + 1,\
    \ 0);\n    srsum.resize(n + 1, 0);\n    h.resize(n + 1, 0);\n    hs.resize(n +\
    \ 1, 0);\n    for (int i = 0; i < n; i++) {\n      bsum[i + 1] = bsum[i] + int(b[i]);\n\
    \      sum[i + 1] = sum[i] + v[i];\n    }\n  }\n\n  inline void srsum_set(const\
    \ vector<unsigned> &v) {\n    for (int i = 0; i < n; i++) {\n      srsum[i + 1]\
    \ = srsum[i] + v[i];\n    }\n  }\n\n  inline void hash_set(const vector<unsigned\
    \ long long> &v, const vector<unsigned long long> &s) {\n    for (int i = 0; i\
    \ < n; i++) {\n      h[i + 1] = h[i] ^ v[i];\n      hs[i + 1] = (hs[i] + __int128_t(s[i]));\n\
    \    }\n  }\n\n  unsigned long long hash_prod(unsigned l, unsigned r) {\n    return\
    \ h[r] ^ h[l];\n  }\n\n  __int128_t multihash(unsigned l, unsigned r) {\n    return\
    \ ((hs[r] - hs[l]));\n  }\n\n  inline unsigned rank(unsigned k) {\n    return\
    \ bsum[k];\n  }\n\n  inline unsigned long long rank_sum(unsigned k) {\n    return\
    \ sum[k];\n  }\n\n  inline unsigned long long rank_srsum(unsigned k) {\n    return\
    \ srsum[k];\n  }\n\n  inline unsigned select(unsigned k) {\n    return distance(bsum.begin()\
    \ + 1, lower_bound(bsum.begin(), bsum.end(), k));\n  }\n\n  inline bool access(unsigned\
    \ k) {\n    return (rank(k + 1) - rank(k)) == 1;\n  }\n};\n\nstruct custom_hash\
    \ {\n  static uint64_t splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n \
    \   static const uint64_t FIXED_RANDOM =\n        chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n} rng;\n\nunordered_map<unsigned,\
    \ unsigned long long> hashmap;\n\nclass WaveletMatrix {\n private:\n  unsigned\
    \ n;\n  unsigned bitsize;\n  vector<BitVector> b;\n  vector<BitVector> cnt;\n\
    \  vector<unsigned> zero, zero2;\n  vector<int> stInd, prev;\n  vector<unsigned>\
    \ prev_i;\n  vector<unsigned long long> hashA, hashB;\n  vector<unsigned> compressed,\
    \ cmp;\n\n  // prev_i[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n  unsigned rank_less_prev(unsigned l, unsigned r, unsigned\
    \ k) {\n    unsigned less = 0;\n    for (unsigned i = 0; i < bitsize and l < r;\
    \ i++) {\n      const unsigned rank1_l = cnt[i].rank(l);\n      const unsigned\
    \ rank1_r = cnt[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n   \
    \   const unsigned rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i -\
    \ 1))) {\n        less += (rank0_r - rank0_l);\n        l = zero2[i] + rank1_l;\n\
    \        r = zero2[i] + rank1_r;\n      } else {\n        l = rank0_l;\n     \
    \   r = rank0_r;\n      }\n    }\n    return less;\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067\u5024\u304Ck\u672A\u6E80\u3067\u3042\u308B\u8981\u7D20\u306E\u591A\u91CD\
    \u96C6\u5408\u306Ehash\u5024\u3092\u8FD4\u3059\n  __int128_t less_multihash(unsigned\
    \ l, unsigned r, unsigned k) {\n    __int128_t less = 0;\n    for (unsigned i\
    \ = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l = b[i].rank(l);\n\
    \      const unsigned rank1_r = b[i].rank(r);\n      const unsigned rank0_l =\
    \ l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n      if (k & (1U\
    \ << (bitsize - i - 1))) {\n        less += b[i].multihash(rank0_l, rank0_r);\n\
    \        l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n      } else\
    \ {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n    return less;\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n  unsigned rank_less(unsigned l, unsigned r, unsigned k) {\n\
    \    unsigned less = 0;\n    for (unsigned i = 0; i < bitsize and l < r; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less += (rank0_r - rank0_l);\n        l = zero[i] + rank1_l;\n        r = zero[i]\
    \ + rank1_r;\n      } else {\n        l = rank0_l;\n        r = rank0_r;\n   \
    \   }\n    }\n    return less;\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304C\
    k\u672A\u6E80\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned long long rank_less_sum(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned long long less_sum = 0;\n    for\
    \ (unsigned i = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l\
    \ = b[i].rank(l);\n      const unsigned rank1_r = b[i].rank(r);\n      const unsigned\
    \ rank0_l = l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n      if\
    \ (k & (1U << (bitsize - i - 1))) {\n        less_sum += b[i].rank_srsum(rank0_r)\
    \ - b[i].rank_srsum(rank0_l);\n        l = zero[i] + rank1_l;\n        r = zero[i]\
    \ + rank1_r;\n      } else {\n        l = rank0_l;\n        r = rank0_r;\n   \
    \   }\n    }\n    return less_sum;\n  }\n\n  // \u5EA7\u6A19\u5727\u7E2E\n  inline\
    \ unsigned compress(const unsigned &x) {\n    return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n  WaveletMatrix() {}\n  WaveletMatrix(vector<unsigned> v) {\n  \
    \  n = v.size();\n    prev_i.resize(n);\n    hashA.resize(n);\n    hashB.resize(n);\n\
    \    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    compressed.resize(n);\n    prev.resize(cmp.size(),\
    \ -1);\n    vector<unsigned> tmp(n), tmp2(n), tmpc(n);\n    vector<unsigned long\
    \ long> tmph(n), tmph2(n);\n    unsigned size_mx = v.size();\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      if (hashmap.find(v[i]) == hashmap.end()) hashmap[v[i]]\
    \ = rng(v[i]);\n      hashA[i] = hashmap[v[i]];\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n      if (prev[compressed[i]] !=\
    \ -1) {\n        prev_i[i] = prev[compressed[i]];\n      } else {\n        prev_i[i]\
    \ = 0;\n      }\n      prev[compressed[i]] = i + 1;\n    }\n    hashB = hashA;\n\
    \    stInd.resize(cmp.size() + 1, -1);\n    bitsize = numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(n);\n    b.resize(bitsize);\n    cnt.resize(bitsize);\n\
    \    zero.resize(bitsize, 0);\n    zero2.resize(bitsize, 0);\n    vector<bool>\
    \ bit(n, 0), bit2(n, 0);\n    for (unsigned i = 0; i < bitsize; i++) {\n     \
    \ for (unsigned j = 0; j < n; j++) {\n        bit[j] = compressed[j] & (1U <<\
    \ (bitsize - i - 1));\n        zero[i] += unsigned(!bit[j]);\n        bit2[j]\
    \ = prev_i[j] & (1U << (bitsize - i - 1));\n        zero2[i] += unsigned(!bit2[j]);\n\
    \        tmp[j] = v[j];\n        tmp2[j] = prev_i[j];\n        tmpc[j] = compressed[j];\n\
    \        tmph[j] = hashA[j];\n        tmph2[j] = hashB[j];\n      }\n      b[i]\
    \ = BitVector(bit, compressed);\n      cnt[i] = BitVector(bit2, prev_i);\n   \
    \   int cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n        if (!bit[j])\
    \ {\n          v[cur] = tmp[j];\n          compressed[cur] = tmpc[j];\n      \
    \    hashB[cur] = tmph2[j];\n          cur++;\n        }\n      }\n      for (unsigned\
    \ j = 0; j < n; j++) {\n        if (bit[j]) {\n          v[cur] = tmp[j];\n  \
    \        compressed[cur] = tmpc[j];\n          hashB[cur] = tmph2[j];\n      \
    \    cur++;\n        }\n      }\n      cur = 0;\n      for (unsigned j = 0; j\
    \ < n; j++) {\n        if (!bit2[j]) {\n          prev_i[cur] = tmp2[j];\n   \
    \       hashA[cur] = tmph[j];\n          cur++;\n        }\n      }\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (bit2[j]) {\n          prev_i[cur]\
    \ = tmp2[j];\n          hashA[cur] = tmph[j];\n          cur++;\n        }\n \
    \     }\n      b[i].srsum_set(v);\n      b[i].hash_set(hashA, hashB);\n    }\n\
    \n    for (unsigned i = 0; i < n; i++) {\n      if (stInd[compressed[i]] == -1)\
    \ {\n        stInd[compressed[i]] = i;\n      }\n    }\n  }\n\n  // get v[k]\n\
    \  unsigned access(unsigned k) {\n    unsigned res = 0;\n    unsigned cur = k;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      if (b[i].access(cur)) {\n\
    \        res |= (1U << (bitsize - i - 1));\n        cur = zero[i] + b[i].rank(cur);\n\
    \      } else {\n        cur -= b[i].rank(cur);\n      }\n    }\n    return cmp[res];\n\
    \  }\n\n  // v[0,k) \u4E2D\u3067\u306Ec\u306E\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\
    \u3059\n  unsigned rank(unsigned k, unsigned c) {\n    c = compress(c);\n    unsigned\
    \ cur = k;\n    if (stInd[c] == -1) {\n      return 0;\n    }\n    for (unsigned\
    \ i = 0; i < bitsize; i++) {\n      if (c & (1U << (bitsize - i - 1))) {\n   \
    \     cur = zero[i] + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n\
    \      }\n    }\n    return cur - stInd[c];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067\
    \u5024\u304C{k\u672A\u6E80\u306E\u500B\u6570\u3001k\u306E\u500B\u6570\u3001k\u3088\
    \u308A\u5927\u304D\u3044\u500B\u6570}\u3092\u8FD4\u3059\n  vector<unsigned> rank_less_more(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned range = r - l;\n    unsigned less\
    \ = 0;\n    unsigned more = 0;\n    for (unsigned i = 0; i < bitsize and l < r;\
    \ i++) {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less += (rank0_r - rank0_l);\n        l = zero[i] + rank1_l;\n        r = zero[i]\
    \ + rank1_r;\n      } else {\n        more += (rank1_r - rank1_l);\n        l\
    \ = rank0_l;\n        r = rank0_r;\n      }\n    }\n    unsigned rank = range\
    \ - more - less;\n    return {less, rank, more};\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067k-1\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  unsigned\
    \ kth_smallest(unsigned l, unsigned r, unsigned k) {\n    unsigned res = 0;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      unsigned num1 = b[i].rank(r)\
    \ - b[i].rank(l);\n      unsigned num0 = r - l - num1;\n      if (num0 < k) {\n\
    \        res |= (1ULL << (bitsize - i - 1));\n        l = zero[i] + b[i].rank(l);\n\
    \        r = zero[i] + b[i].rank(r);\n        k -= num0;\n      } else {\n   \
    \     l -= b[i].rank(l);\n        r -= b[i].rank(r);\n      }\n    }\n    return\
    \ cmp[res];\n  }\n\n  // v[l,r) \u3092\u6607\u9806\u30BD\u30FC\u30C8\u3057\u305F\
    \u6642\u306E\u5148\u982Dk\u500B\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned\
    \ long long kth_sum(unsigned l, unsigned r, unsigned k) {\n    unsigned long long\
    \ res = 0;\n    unsigned val = 0;\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      const unsigned num1 = rank1_r - rank1_l;\n   \
    \   const unsigned num0 = rank0_r - rank0_l;\n      if (num0 < k) {\n        val\
    \ |= (1ULL << (bitsize - i - 1));\n        res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n\
    \        l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n        k -=\
    \ num0;\n      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n\
    \    }\n    res += uint64_t(cmp[val]) * uint64_t(k);\n    return res;\n  }\n\n\
    \  // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n  unsigned range_freq(unsigned l, unsigned r, unsigned\
    \ mink, unsigned maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n\
    \    return rank_less(l, r, maxk) - rank_less(l, r, mink);\n  }\n\n  // v[l,r)\
    \ \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\u548C\u3092\
    \u8FD4\u3059\n  unsigned long long range_sum(unsigned l, unsigned r, unsigned\
    \ mink, unsigned maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n\
    \    return rank_less_sum(l, r, maxk) - rank_less_sum(l, r, mink);\n  }\n\n  //\
    \ v[l,r) \u306E\u4E2D\u306E\u5024\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u3059\n\
    \  unsigned range_count(unsigned l, unsigned r) {\n    return rank_less_prev(l,\
    \ r, l + 1);\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067val\u672A\u6E80\u306E\u6700\
    \u5927\u306E\u5024\u3092\u8FD4\u3059\n  unsigned prev_value(unsigned l, unsigned\
    \ r, unsigned val) {\n    int num = range_freq(l, r, 0, val);\n    if (num ==\
    \ 0) {\n      return UINT32_MAX;\n    } else {\n      return kth_smallest(l, r,\
    \ num);\n    }\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u5024\u3092\u8FD4\u3059\n  unsigned next_value(unsigned l, unsigned\
    \ r, unsigned val) {\n    int num = range_freq(l, r, 0, val);\n    if (num ==\
    \ r - l) {\n      return UINT32_MAX;\n    } else {\n      return kth_smallest(l,\
    \ r, num + 1);\n    }\n  }\n\n  // v[l,r) \u306E\u91CD\u8907\u3092\u9664\u3044\
    \u305F\u8981\u7D20\u306Ehash\u3092\u8FD4\u3059\n  unsigned long long range_hash(unsigned\
    \ l, unsigned r) {\n    unsigned k = l + 1;\n    unsigned long long h = 0;\n \
    \   for (unsigned i = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l\
    \ = cnt[i].rank(l);\n      const unsigned rank1_r = cnt[i].rank(r);\n      const\
    \ unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n\
    \      if (k & (1U << (bitsize - i - 1))) {\n        h ^= b[i].hash_prod(rank0_l,\
    \ rank0_r);\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return h;\n  }\n\n  // [l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\
    \u5024\u306E\u591A\u91CD\u96C6\u5408\u306Ehash\u3092\u8FD4\u3059\n  __int128_t\
    \ range_hash_multi(unsigned l, unsigned r, unsigned mink, unsigned maxk) {\n \
    \   maxk = compress(maxk);\n    mink = compress(mink);\n    return (less_multihash(l,\
    \ r, maxk) - less_multihash(l, r, mink));\n  }\n\n  // v[l1,r1) \u306E\u8981\u7D20\
    \u306E\u96C6\u5408\u3068v[l2,r2) \u306E\u8981\u7D20\u306E\u96C6\u5408\u304C\u7B49\
    \u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n  bool range_equal(unsigned\
    \ l1, unsigned r1, unsigned l2, unsigned r2) {\n    return range_hash(l1, r1)\
    \ == range_hash(l2, r2);\n  }\n\n  // v[l1,r1)\u306E[mink1,maxk1) \u306B\u5024\
    \u304C\u5165\u308B\u8981\u7D20\u306E\u591A\u91CD\u96C6\u5408\u3068v[l2,r2) \u306E\
    [mink2,maxk2) \u306B\u5024\u304C\u5165\u308B\u8981\u7D20\u306E\u591A\u91CD\u96C6\
    \u5408\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n  bool\
    \ range_equal_multi(unsigned l1, unsigned r1, unsigned mink1, unsigned maxk1,\
    \ unsigned l2, unsigned r2, unsigned mink2, unsigned maxk2) {\n    return range_hash_multi(l1,\
    \ r1, mink1, maxk1) == range_hash_multi(l2, r2, mink2, maxk2);\n  }\n};\n"
  code: "#pragma once\nclass BitVector {\n private:\n  unsigned n;\n  vector<unsigned>\
    \ bsum;\n  vector<unsigned long long> sum, srsum;\n  vector<unsigned long long>\
    \ h;\n  vector<__int128_t> hs;\n\n public:\n  BitVector() {\n  }\n\n  BitVector(vector<bool>\
    \ &b, vector<unsigned> &v) {\n    n = b.size();\n    bsum.resize(n + 1, 0);\n\
    \    sum.resize(n + 1, 0);\n    srsum.resize(n + 1, 0);\n    h.resize(n + 1, 0);\n\
    \    hs.resize(n + 1, 0);\n    for (int i = 0; i < n; i++) {\n      bsum[i + 1]\
    \ = bsum[i] + int(b[i]);\n      sum[i + 1] = sum[i] + v[i];\n    }\n  }\n\n  inline\
    \ void srsum_set(const vector<unsigned> &v) {\n    for (int i = 0; i < n; i++)\
    \ {\n      srsum[i + 1] = srsum[i] + v[i];\n    }\n  }\n\n  inline void hash_set(const\
    \ vector<unsigned long long> &v, const vector<unsigned long long> &s) {\n    for\
    \ (int i = 0; i < n; i++) {\n      h[i + 1] = h[i] ^ v[i];\n      hs[i + 1] =\
    \ (hs[i] + __int128_t(s[i]));\n    }\n  }\n\n  unsigned long long hash_prod(unsigned\
    \ l, unsigned r) {\n    return h[r] ^ h[l];\n  }\n\n  __int128_t multihash(unsigned\
    \ l, unsigned r) {\n    return ((hs[r] - hs[l]));\n  }\n\n  inline unsigned rank(unsigned\
    \ k) {\n    return bsum[k];\n  }\n\n  inline unsigned long long rank_sum(unsigned\
    \ k) {\n    return sum[k];\n  }\n\n  inline unsigned long long rank_srsum(unsigned\
    \ k) {\n    return srsum[k];\n  }\n\n  inline unsigned select(unsigned k) {\n\
    \    return distance(bsum.begin() + 1, lower_bound(bsum.begin(), bsum.end(), k));\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (rank(k + 1) - rank(k))\
    \ == 1;\n  }\n};\n\nstruct custom_hash {\n  static uint64_t splitmix64(uint64_t\
    \ x) {\n    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return x ^ (x >> 31);\n  }\n\
    \n  size_t operator()(uint64_t x) const {\n    static const uint64_t FIXED_RANDOM\
    \ =\n        chrono::steady_clock::now().time_since_epoch().count();\n    return\
    \ splitmix64(x + FIXED_RANDOM);\n  }\n} rng;\n\nunordered_map<unsigned, unsigned\
    \ long long> hashmap;\n\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned\
    \ bitsize;\n  vector<BitVector> b;\n  vector<BitVector> cnt;\n  vector<unsigned>\
    \ zero, zero2;\n  vector<int> stInd, prev;\n  vector<unsigned> prev_i;\n  vector<unsigned\
    \ long long> hashA, hashB;\n  vector<unsigned> compressed, cmp;\n\n  // prev_i[l,r)\
    \ \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\
    \n  unsigned rank_less_prev(unsigned l, unsigned r, unsigned k) {\n    unsigned\
    \ less = 0;\n    for (unsigned i = 0; i < bitsize and l < r; i++) {\n      const\
    \ unsigned rank1_l = cnt[i].rank(l);\n      const unsigned rank1_r = cnt[i].rank(r);\n\
    \      const unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r\
    \ - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n        less += (rank0_r\
    \ - rank0_l);\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return less;\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\
    \u3067\u3042\u308B\u8981\u7D20\u306E\u591A\u91CD\u96C6\u5408\u306Ehash\u5024\u3092\
    \u8FD4\u3059\n  __int128_t less_multihash(unsigned l, unsigned r, unsigned k)\
    \ {\n    __int128_t less = 0;\n    for (unsigned i = 0; i < bitsize and l < r;\
    \ i++) {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less += b[i].multihash(rank0_l, rank0_r);\n        l = zero[i] + rank1_l;\n\
    \        r = zero[i] + rank1_r;\n      } else {\n        l = rank0_l;\n      \
    \  r = rank0_r;\n      }\n    }\n    return less;\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\n  unsigned\
    \ rank_less(unsigned l, unsigned r, unsigned k) {\n    unsigned less = 0;\n  \
    \  for (unsigned i = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l\
    \ = b[i].rank(l);\n      const unsigned rank1_r = b[i].rank(r);\n      const unsigned\
    \ rank0_l = l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n      if\
    \ (k & (1U << (bitsize - i - 1))) {\n        less += (rank0_r - rank0_l);\n  \
    \      l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n      } else {\n\
    \        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n    return less;\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u7DCF\u548C\
    \u3092\u8FD4\u3059\n  unsigned long long rank_less_sum(unsigned l, unsigned r,\
    \ unsigned k) {\n    unsigned long long less_sum = 0;\n    for (unsigned i = 0;\
    \ i < bitsize and l < r; i++) {\n      const unsigned rank1_l = b[i].rank(l);\n\
    \      const unsigned rank1_r = b[i].rank(r);\n      const unsigned rank0_l =\
    \ l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n      if (k & (1U\
    \ << (bitsize - i - 1))) {\n        less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n\
    \        l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n      } else\
    \ {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n    return less_sum;\n\
    \  }\n\n  // \u5EA7\u6A19\u5727\u7E2E\n  inline unsigned compress(const unsigned\
    \ &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n  }\n\
    \n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n  WaveletMatrix(vector<unsigned> v) {\n    n = v.size();\n    prev_i.resize(n);\n\
    \    hashA.resize(n);\n    hashB.resize(n);\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ compressed.resize(n);\n    prev.resize(cmp.size(), -1);\n    vector<unsigned>\
    \ tmp(n), tmp2(n), tmpc(n);\n    vector<unsigned long long> tmph(n), tmph2(n);\n\
    \    unsigned size_mx = v.size();\n    for (unsigned i = 0; i < n; i++) {\n  \
    \    if (hashmap.find(v[i]) == hashmap.end()) hashmap[v[i]] = rng(v[i]);\n   \
    \   hashA[i] = hashmap[v[i]];\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n      if (prev[compressed[i]] != -1) {\n        prev_i[i]\
    \ = prev[compressed[i]];\n      } else {\n        prev_i[i] = 0;\n      }\n  \
    \    prev[compressed[i]] = i + 1;\n    }\n    hashB = hashA;\n    stInd.resize(cmp.size()\
    \ + 1, -1);\n    bitsize = numeric_limits<unsigned int>::digits - __builtin_clz(n);\n\
    \    b.resize(bitsize);\n    cnt.resize(bitsize);\n    zero.resize(bitsize, 0);\n\
    \    zero2.resize(bitsize, 0);\n    vector<bool> bit(n, 0), bit2(n, 0);\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        bit[j] = compressed[j] & (1U << (bitsize - i - 1));\n        zero[i]\
    \ += unsigned(!bit[j]);\n        bit2[j] = prev_i[j] & (1U << (bitsize - i - 1));\n\
    \        zero2[i] += unsigned(!bit2[j]);\n        tmp[j] = v[j];\n        tmp2[j]\
    \ = prev_i[j];\n        tmpc[j] = compressed[j];\n        tmph[j] = hashA[j];\n\
    \        tmph2[j] = hashB[j];\n      }\n      b[i] = BitVector(bit, compressed);\n\
    \      cnt[i] = BitVector(bit2, prev_i);\n      int cur = 0;\n      for (unsigned\
    \ j = 0; j < n; j++) {\n        if (!bit[j]) {\n          v[cur] = tmp[j];\n \
    \         compressed[cur] = tmpc[j];\n          hashB[cur] = tmph2[j];\n     \
    \     cur++;\n        }\n      }\n      for (unsigned j = 0; j < n; j++) {\n \
    \       if (bit[j]) {\n          v[cur] = tmp[j];\n          compressed[cur] =\
    \ tmpc[j];\n          hashB[cur] = tmph2[j];\n          cur++;\n        }\n  \
    \    }\n      cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n        if (!bit2[j])\
    \ {\n          prev_i[cur] = tmp2[j];\n          hashA[cur] = tmph[j];\n     \
    \     cur++;\n        }\n      }\n      for (unsigned j = 0; j < n; j++) {\n \
    \       if (bit2[j]) {\n          prev_i[cur] = tmp2[j];\n          hashA[cur]\
    \ = tmph[j];\n          cur++;\n        }\n      }\n      b[i].srsum_set(v);\n\
    \      b[i].hash_set(hashA, hashB);\n    }\n\n    for (unsigned i = 0; i < n;\
    \ i++) {\n      if (stInd[compressed[i]] == -1) {\n        stInd[compressed[i]]\
    \ = i;\n      }\n    }\n  }\n\n  // get v[k]\n  unsigned access(unsigned k) {\n\
    \    unsigned res = 0;\n    unsigned cur = k;\n    for (unsigned i = 0; i < bitsize;\
    \ i++) {\n      if (b[i].access(cur)) {\n        res |= (1U << (bitsize - i -\
    \ 1));\n        cur = zero[i] + b[i].rank(cur);\n      } else {\n        cur -=\
    \ b[i].rank(cur);\n      }\n    }\n    return cmp[res];\n  }\n\n  // v[0,k) \u4E2D\
    \u3067\u306Ec\u306E\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n  unsigned rank(unsigned\
    \ k, unsigned c) {\n    c = compress(c);\n    unsigned cur = k;\n    if (stInd[c]\
    \ == -1) {\n      return 0;\n    }\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      if (c & (1U << (bitsize - i - 1))) {\n        cur = zero[i] + b[i].rank(cur);\n\
    \      } else {\n        cur -= b[i].rank(cur);\n      }\n    }\n    return cur\
    \ - stInd[c];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304C{k\u672A\u6E80\
    \u306E\u500B\u6570\u3001k\u306E\u500B\u6570\u3001k\u3088\u308A\u5927\u304D\u3044\
    \u500B\u6570}\u3092\u8FD4\u3059\n  vector<unsigned> rank_less_more(unsigned l,\
    \ unsigned r, unsigned k) {\n    unsigned range = r - l;\n    unsigned less =\
    \ 0;\n    unsigned more = 0;\n    for (unsigned i = 0; i < bitsize and l < r;\
    \ i++) {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less += (rank0_r - rank0_l);\n        l = zero[i] + rank1_l;\n        r = zero[i]\
    \ + rank1_r;\n      } else {\n        more += (rank1_r - rank1_l);\n        l\
    \ = rank0_l;\n        r = rank0_r;\n      }\n    }\n    unsigned rank = range\
    \ - more - less;\n    return {less, rank, more};\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067k-1\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  unsigned\
    \ kth_smallest(unsigned l, unsigned r, unsigned k) {\n    unsigned res = 0;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      unsigned num1 = b[i].rank(r)\
    \ - b[i].rank(l);\n      unsigned num0 = r - l - num1;\n      if (num0 < k) {\n\
    \        res |= (1ULL << (bitsize - i - 1));\n        l = zero[i] + b[i].rank(l);\n\
    \        r = zero[i] + b[i].rank(r);\n        k -= num0;\n      } else {\n   \
    \     l -= b[i].rank(l);\n        r -= b[i].rank(r);\n      }\n    }\n    return\
    \ cmp[res];\n  }\n\n  // v[l,r) \u3092\u6607\u9806\u30BD\u30FC\u30C8\u3057\u305F\
    \u6642\u306E\u5148\u982Dk\u500B\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned\
    \ long long kth_sum(unsigned l, unsigned r, unsigned k) {\n    unsigned long long\
    \ res = 0;\n    unsigned val = 0;\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      const unsigned num1 = rank1_r - rank1_l;\n   \
    \   const unsigned num0 = rank0_r - rank0_l;\n      if (num0 < k) {\n        val\
    \ |= (1ULL << (bitsize - i - 1));\n        res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n\
    \        l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n        k -=\
    \ num0;\n      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n\
    \    }\n    res += uint64_t(cmp[val]) * uint64_t(k);\n    return res;\n  }\n\n\
    \  // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n  unsigned range_freq(unsigned l, unsigned r, unsigned\
    \ mink, unsigned maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n\
    \    return rank_less(l, r, maxk) - rank_less(l, r, mink);\n  }\n\n  // v[l,r)\
    \ \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\u548C\u3092\
    \u8FD4\u3059\n  unsigned long long range_sum(unsigned l, unsigned r, unsigned\
    \ mink, unsigned maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n\
    \    return rank_less_sum(l, r, maxk) - rank_less_sum(l, r, mink);\n  }\n\n  //\
    \ v[l,r) \u306E\u4E2D\u306E\u5024\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u3059\n\
    \  unsigned range_count(unsigned l, unsigned r) {\n    return rank_less_prev(l,\
    \ r, l + 1);\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067val\u672A\u6E80\u306E\u6700\
    \u5927\u306E\u5024\u3092\u8FD4\u3059\n  unsigned prev_value(unsigned l, unsigned\
    \ r, unsigned val) {\n    int num = range_freq(l, r, 0, val);\n    if (num ==\
    \ 0) {\n      return UINT32_MAX;\n    } else {\n      return kth_smallest(l, r,\
    \ num);\n    }\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u5024\u3092\u8FD4\u3059\n  unsigned next_value(unsigned l, unsigned\
    \ r, unsigned val) {\n    int num = range_freq(l, r, 0, val);\n    if (num ==\
    \ r - l) {\n      return UINT32_MAX;\n    } else {\n      return kth_smallest(l,\
    \ r, num + 1);\n    }\n  }\n\n  // v[l,r) \u306E\u91CD\u8907\u3092\u9664\u3044\
    \u305F\u8981\u7D20\u306Ehash\u3092\u8FD4\u3059\n  unsigned long long range_hash(unsigned\
    \ l, unsigned r) {\n    unsigned k = l + 1;\n    unsigned long long h = 0;\n \
    \   for (unsigned i = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l\
    \ = cnt[i].rank(l);\n      const unsigned rank1_r = cnt[i].rank(r);\n      const\
    \ unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n\
    \      if (k & (1U << (bitsize - i - 1))) {\n        h ^= b[i].hash_prod(rank0_l,\
    \ rank0_r);\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return h;\n  }\n\n  // [l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\
    \u5024\u306E\u591A\u91CD\u96C6\u5408\u306Ehash\u3092\u8FD4\u3059\n  __int128_t\
    \ range_hash_multi(unsigned l, unsigned r, unsigned mink, unsigned maxk) {\n \
    \   maxk = compress(maxk);\n    mink = compress(mink);\n    return (less_multihash(l,\
    \ r, maxk) - less_multihash(l, r, mink));\n  }\n\n  // v[l1,r1) \u306E\u8981\u7D20\
    \u306E\u96C6\u5408\u3068v[l2,r2) \u306E\u8981\u7D20\u306E\u96C6\u5408\u304C\u7B49\
    \u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n  bool range_equal(unsigned\
    \ l1, unsigned r1, unsigned l2, unsigned r2) {\n    return range_hash(l1, r1)\
    \ == range_hash(l2, r2);\n  }\n\n  // v[l1,r1)\u306E[mink1,maxk1) \u306B\u5024\
    \u304C\u5165\u308B\u8981\u7D20\u306E\u591A\u91CD\u96C6\u5408\u3068v[l2,r2) \u306E\
    [mink2,maxk2) \u306B\u5024\u304C\u5165\u308B\u8981\u7D20\u306E\u591A\u91CD\u96C6\
    \u5408\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n  bool\
    \ range_equal_multi(unsigned l1, unsigned r1, unsigned mink1, unsigned maxk1,\
    \ unsigned l2, unsigned r2, unsigned mink2, unsigned maxk2) {\n    return range_hash_multi(l1,\
    \ r1, mink1, maxk1) == range_hash_multi(l2, r2, mink2, maxk2);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixHash.hpp
  requiredBy: []
  timestamp: '2024-06-26 12:49:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AtCoder/data-structure/wavelet-matrix/PrefixEquality.test.cpp
documentation_of: data-structure/wavelet-matrix/WaveletMatrixHash.hpp
layout: document
title: Wavelet Matrix (Hash)
---

## 概要

todo

## 計算量
todo