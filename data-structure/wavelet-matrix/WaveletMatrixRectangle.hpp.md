---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet-matrix/WaveletMatrixRectangle.hpp\"\
    \nclass BitVector {\n private:\n  unsigned n, cur, p;\n  vector<unsigned> acc,\
    \ bit;\n  vector<unsigned long long> sum, srsum;\n\n public:\n  BitVector() {\n\
    \  }\n\n  BitVector(vector<bool> &b, vector<unsigned> &v) {\n    cur = 0;\n  \
    \  n = b.size();\n    acc.resize(n / 32 + 2, 0);\n    bit.resize(n / 32 + 2, 0);\n\
    \    sum.resize(n + 1, 0);\n    srsum.resize(n + 1, 0);\n    for (int i = 0; i\
    \ < n; i++) {\n      p = i % 32;\n      if (p == 0) {\n        cur++;\n      \
    \  acc[cur] = acc[cur - 1];\n      }\n      sum[i + 1] = sum[i] + v[i];\n\n  \
    \    if (b[i]) {\n        acc[cur] += int(b[i]);\n        bit[cur - 1] |= (1U\
    \ << (32 - p - 1));\n      }\n    }\n  }\n\n  inline void srsum_set(const vector<unsigned>\
    \ &v) {\n    for (int i = 0; i < n; i++) {\n      srsum[i + 1] = srsum[i] + v[i];\n\
    \    }\n  }\n\n  inline unsigned rank(unsigned k) {\n    if (!(k & 31)) return\
    \ acc[k / 32];\n    return acc[k / 32] + __builtin_popcount(bit[k / 32] >> (32\
    \ - (k & 31)));\n  }\n\n  inline unsigned long long rank_sum(unsigned k) {\n \
    \   return sum[k];\n  }\n\n  inline unsigned long long rank_srsum(unsigned k)\
    \ {\n    return srsum[k];\n  }\n\n  inline bool access(unsigned k) {\n    return\
    \ (rank(k + 1) - rank(k)) == 1;\n  }\n};\n\nclass WaveletMatrix {\n private:\n\
    \  unsigned n;\n  unsigned bitsize;\n  vector<BitVector> b;\n  vector<BitVector>\
    \ cnt;\n  vector<unsigned> zero, zero2;\n  vector<int> stInd, prev;\n  vector<unsigned>\
    \ prev_i, px;\n  vector<unsigned> compressed, cmp;\n\n  // prev_i[l,r) \u306E\u4E2D\
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\n  unsigned\
    \ rank_less_prev(unsigned l, unsigned r, unsigned k) {\n    unsigned less = 0;\n\
    \    for (unsigned i = 0; i < bitsize and l < r; i++) {\n      const unsigned\
    \ rank1_l = cnt[i].rank(l);\n      const unsigned rank1_r = cnt[i].rank(r);\n\
    \      const unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r\
    \ - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n        less += (rank0_r\
    \ - rank0_l);\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return less;\n  }\n\n  inline unsigned compress(const unsigned x) {\n   \
    \ return distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), x));\n  }\n\
    \n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n  WaveletMatrix(vector<unsigned> x, vector<unsigned> y, vector<unsigned>\
    \ w) {\n    n = x.size();\n    px.resize(n);\n    vector<tuple<unsigned, unsigned,\
    \ unsigned>> v(n);\n    for (int i = 0; i < n; i++) {\n      v[i] = {x[i], y[i],\
    \ w[i]};\n    }\n    sort(v.begin(), v.end());\n    for (int i = 0; i < n; i++)\
    \ {\n      px[i] = get<0>(v[i]);\n      y[i] = get<1>(v[i]);\n      w[i] = get<2>(v[i]);\n\
    \    }\n    cmp.resize(y.size());\n    cmp = y;\n    sort(cmp.begin(), cmp.end());\n\
    \    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n    compressed.resize(n);\n\
    \    vector<unsigned> tmp(n), tmpc(n);\n    unsigned size_mx = y.size();\n   \
    \ for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), y[i]));\n    }\n    stInd.resize(cmp.size()\
    \ + 1, -1);\n    bitsize = bit_width(size_mx);\n    b.resize(bitsize);\n    zero.resize(bitsize,\
    \ 0);\n    vector<bool> bit(n, 0);\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      for (unsigned j = 0; j < n; j++) {\n        bit[j] = compressed[j]\
    \ & (1U << (bitsize - i - 1));\n        zero[i] += unsigned(!bit[j]);\n      \
    \  tmp[j] = w[j];\n        tmpc[j] = compressed[j];\n      }\n      b[i] = BitVector(bit,\
    \ compressed);\n      int cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n\
    \        if (!bit[j]) {\n          w[cur] = tmp[j];\n          compressed[cur]\
    \ = tmpc[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0;\
    \ j < n; j++) {\n        if (bit[j]) {\n          w[cur] = tmp[j];\n         \
    \ compressed[cur] = tmpc[j];\n          cur++;\n        }\n      }\n      b[i].srsum_set(w);\n\
    \    }\n    for (unsigned i = 0; i < n; i++) {\n      if (stInd[compressed[i]]\
    \ == -1) {\n        stInd[compressed[i]] = i;\n      }\n    }\n  }\n\n  // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix(vector<unsigned> v, vector<unsigned>\
    \ w = {}) {\n    n = v.size();\n    prev_i.resize(n);\n    if (w.empty()) {\n\
    \      w.resize(n);\n      w = v;\n    }\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ compressed.resize(n);\n    prev.resize(cmp.size(), -1);\n    vector<unsigned>\
    \ tmp(n), tmp2(n), tmpc(n);\n    unsigned size_mx = v.size();\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n      if (prev[compressed[i]] != -1) {\n        prev_i[i]\
    \ = prev[compressed[i]];\n      } else {\n        prev_i[i] = 0;\n      }\n  \
    \    prev[compressed[i]] = i + 1;\n    }\n    stInd.resize(cmp.size() + 1, -1);\n\
    \    bitsize = bit_width(size_mx);\n    b.resize(bitsize);\n    cnt.resize(bitsize);\n\
    \    zero.resize(bitsize, 0);\n    zero2.resize(bitsize, 0);\n    vector<bool>\
    \ bit(n, 0), bit2(n, 0);\n    for (unsigned i = 0; i < bitsize; i++) {\n     \
    \ for (unsigned j = 0; j < n; j++) {\n        bit[j] = compressed[j] & (1U <<\
    \ (bitsize - i - 1));\n        zero[i] += unsigned(!bit[j]);\n        bit2[j]\
    \ = prev_i[j] & (1U << (bitsize - i - 1));\n        zero2[i] += unsigned(!bit2[j]);\n\
    \        tmp[j] = w[j];\n        tmp2[j] = prev_i[j];\n        tmpc[j] = compressed[j];\n\
    \      }\n      b[i] = BitVector(bit, compressed);\n      cnt[i] = BitVector(bit2,\
    \ prev_i);\n      int cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n   \
    \     if (!bit[j]) {\n          w[cur] = tmp[j];\n          compressed[cur] =\
    \ tmpc[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0; j\
    \ < n; j++) {\n        if (bit[j]) {\n          w[cur] = tmp[j];\n          compressed[cur]\
    \ = tmpc[j];\n          cur++;\n        }\n      }\n      cur = 0;\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (!bit2[j]) {\n          prev_i[cur]\
    \ = tmp2[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0;\
    \ j < n; j++) {\n        if (bit2[j]) {\n          prev_i[cur] = tmp2[j];\n  \
    \        cur++;\n        }\n      }\n      b[i].srsum_set(w);\n    }\n\n    for\
    \ (unsigned i = 0; i < n; i++) {\n      if (stInd[compressed[i]] == -1) {\n  \
    \      stInd[compressed[i]] = i;\n      }\n    }\n  }\n\n  // get v[k]\n  unsigned\
    \ access(unsigned k) {\n    unsigned res = 0;\n    unsigned cur = k;\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      if (b[i].access(cur)) {\n      \
    \  res |= (1U << (bitsize - i - 1));\n        cur = zero[i] + b[i].rank(cur);\n\
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
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned\
    \ long long rank_less_sum(unsigned l, unsigned r, unsigned k) {\n    unsigned\
    \ long long less_sum = 0;\n    for (unsigned i = 0; i < bitsize and l < r; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n        l\
    \ = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n      } else {\n     \
    \   l = rank0_l;\n        r = rank0_r;\n      }\n    }\n    return less_sum;\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n  unsigned rank_less(unsigned l, unsigned r, unsigned k) {\n\
    \    unsigned less = 0;\n    for (unsigned i = 0; i < bitsize and l < r; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less += (rank0_r - rank0_l);\n        l = zero[i] + rank1_l;\n        r = zero[i]\
    \ + rank1_r;\n      } else {\n        l = rank0_l;\n        r = rank0_r;\n   \
    \   }\n    }\n    return less;\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k-1\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  unsigned kth_smallest(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned res = 0;\n    for (unsigned i = 0;\
    \ i < bitsize; i++) {\n      unsigned num1 = b[i].rank(r) - b[i].rank(l);\n  \
    \    unsigned num0 = r - l - num1;\n      if (num0 < k) {\n        res |= (1ULL\
    \ << (bitsize - i - 1));\n        l = zero[i] + b[i].rank(l);\n        r = zero[i]\
    \ + b[i].rank(r);\n        k -= num0;\n      } else {\n        l -= b[i].rank(l);\n\
    \        r -= b[i].rank(r);\n      }\n    }\n    return cmp[res];\n  }\n\n  //\
    \ v[l,r]\u3092\u6607\u9806\u30BD\u30FC\u30C8\u3057\u305F\u6642\u306E\u5148\u982D\
    k\u500B\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned long long kth_sum(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned long long res = 0;\n    unsigned\
    \ val = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      const unsigned\
    \ rank1_l = b[i].rank(l);\n      const unsigned rank1_r = b[i].rank(r);\n    \
    \  const unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n\
    \      const unsigned num1 = rank1_r - rank1_l;\n      const unsigned num0 = rank0_r\
    \ - rank0_l;\n      if (num0 < k) {\n        val |= (1ULL << (bitsize - i - 1));\n\
    \        res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n       \
    \ l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    res += uint64_t(cmp[val]) * uint64_t(k);\n    return res;\n  }\n\n  // v[l,r)\
    \ \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\n  unsigned range_freq(unsigned l, unsigned r, unsigned mink, unsigned\
    \ maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n    return\
    \ rank_less(l, r, maxk) - rank_less(l, r, mink);\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n\
    \  unsigned long long range_sum(unsigned l, unsigned r, unsigned mink, unsigned\
    \ maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n    return\
    \ rank_less_sum(l, r, maxk) - rank_less_sum(l, r, mink);\n  }\n\n  // x\u5EA7\u6A19\
    \u304C[l,r) \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n  unsigned rectangle_freq(unsigned l, unsigned\
    \ r, unsigned d, unsigned u) {\n    l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), l));\n    r = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n    return range_freq(l, r, d, u);\n  }\n\n  // x\u5EA7\u6A19\u304C[l,r)\
    \ \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\u7DCF\u548C\
    \u3092\u8FD4\u3059\n  unsigned long long rectangle_sum(unsigned l, unsigned r,\
    \ unsigned d, unsigned u) {\n    l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), l));\n    r = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n    return range_sum(l, r, d, u);\n  }\n\n  // v[l,r) \u306E\u4E2D\u306E\
    \u5024\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u3059\n  unsigned range_count(unsigned\
    \ l, unsigned r) {\n    return rank_less_prev(l, r, l + 1);\n  }\n\n  // v[l,r)\u306E\
    \u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\
    \u3059\n  unsigned prev_value(unsigned l, unsigned r, unsigned val) {\n    int\
    \ num = range_freq(l, r, 0, val);\n    if (num == 0) {\n      return UINT32_MAX;\n\
    \    } else {\n      return kth_smallest(l, r, num);\n    }\n  }\n\n  // v[l,r)\u306E\
    \u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n\
    \  unsigned next_value(unsigned l, unsigned r, unsigned val) {\n    int num =\
    \ range_freq(l, r, 0, val);\n    if (num == r - l) {\n      return UINT32_MAX;\n\
    \    } else {\n      return kth_smallest(l, r, num + 1);\n    }\n  }\n};\n"
  code: "#pragma once\nclass BitVector {\n private:\n  unsigned n, cur, p;\n  vector<unsigned>\
    \ acc, bit;\n  vector<unsigned long long> sum, srsum;\n\n public:\n  BitVector()\
    \ {\n  }\n\n  BitVector(vector<bool> &b, vector<unsigned> &v) {\n    cur = 0;\n\
    \    n = b.size();\n    acc.resize(n / 32 + 2, 0);\n    bit.resize(n / 32 + 2,\
    \ 0);\n    sum.resize(n + 1, 0);\n    srsum.resize(n + 1, 0);\n    for (int i\
    \ = 0; i < n; i++) {\n      p = i % 32;\n      if (p == 0) {\n        cur++;\n\
    \        acc[cur] = acc[cur - 1];\n      }\n      sum[i + 1] = sum[i] + v[i];\n\
    \n      if (b[i]) {\n        acc[cur] += int(b[i]);\n        bit[cur - 1] |= (1U\
    \ << (32 - p - 1));\n      }\n    }\n  }\n\n  inline void srsum_set(const vector<unsigned>\
    \ &v) {\n    for (int i = 0; i < n; i++) {\n      srsum[i + 1] = srsum[i] + v[i];\n\
    \    }\n  }\n\n  inline unsigned rank(unsigned k) {\n    if (!(k & 31)) return\
    \ acc[k / 32];\n    return acc[k / 32] + __builtin_popcount(bit[k / 32] >> (32\
    \ - (k & 31)));\n  }\n\n  inline unsigned long long rank_sum(unsigned k) {\n \
    \   return sum[k];\n  }\n\n  inline unsigned long long rank_srsum(unsigned k)\
    \ {\n    return srsum[k];\n  }\n\n  inline bool access(unsigned k) {\n    return\
    \ (rank(k + 1) - rank(k)) == 1;\n  }\n};\n\nclass WaveletMatrix {\n private:\n\
    \  unsigned n;\n  unsigned bitsize;\n  vector<BitVector> b;\n  vector<BitVector>\
    \ cnt;\n  vector<unsigned> zero, zero2;\n  vector<int> stInd, prev;\n  vector<unsigned>\
    \ prev_i, px;\n  vector<unsigned> compressed, cmp;\n\n  // prev_i[l,r) \u306E\u4E2D\
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\n  unsigned\
    \ rank_less_prev(unsigned l, unsigned r, unsigned k) {\n    unsigned less = 0;\n\
    \    for (unsigned i = 0; i < bitsize and l < r; i++) {\n      const unsigned\
    \ rank1_l = cnt[i].rank(l);\n      const unsigned rank1_r = cnt[i].rank(r);\n\
    \      const unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r\
    \ - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n        less += (rank0_r\
    \ - rank0_l);\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return less;\n  }\n\n  inline unsigned compress(const unsigned x) {\n   \
    \ return distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), x));\n  }\n\
    \n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n  WaveletMatrix(vector<unsigned> x, vector<unsigned> y, vector<unsigned>\
    \ w) {\n    n = x.size();\n    px.resize(n);\n    vector<tuple<unsigned, unsigned,\
    \ unsigned>> v(n);\n    for (int i = 0; i < n; i++) {\n      v[i] = {x[i], y[i],\
    \ w[i]};\n    }\n    sort(v.begin(), v.end());\n    for (int i = 0; i < n; i++)\
    \ {\n      px[i] = get<0>(v[i]);\n      y[i] = get<1>(v[i]);\n      w[i] = get<2>(v[i]);\n\
    \    }\n    cmp.resize(y.size());\n    cmp = y;\n    sort(cmp.begin(), cmp.end());\n\
    \    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n    compressed.resize(n);\n\
    \    vector<unsigned> tmp(n), tmpc(n);\n    unsigned size_mx = y.size();\n   \
    \ for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), y[i]));\n    }\n    stInd.resize(cmp.size()\
    \ + 1, -1);\n    bitsize = bit_width(size_mx);\n    b.resize(bitsize);\n    zero.resize(bitsize,\
    \ 0);\n    vector<bool> bit(n, 0);\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      for (unsigned j = 0; j < n; j++) {\n        bit[j] = compressed[j]\
    \ & (1U << (bitsize - i - 1));\n        zero[i] += unsigned(!bit[j]);\n      \
    \  tmp[j] = w[j];\n        tmpc[j] = compressed[j];\n      }\n      b[i] = BitVector(bit,\
    \ compressed);\n      int cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n\
    \        if (!bit[j]) {\n          w[cur] = tmp[j];\n          compressed[cur]\
    \ = tmpc[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0;\
    \ j < n; j++) {\n        if (bit[j]) {\n          w[cur] = tmp[j];\n         \
    \ compressed[cur] = tmpc[j];\n          cur++;\n        }\n      }\n      b[i].srsum_set(w);\n\
    \    }\n    for (unsigned i = 0; i < n; i++) {\n      if (stInd[compressed[i]]\
    \ == -1) {\n        stInd[compressed[i]] = i;\n      }\n    }\n  }\n\n  // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix(vector<unsigned> v, vector<unsigned>\
    \ w = {}) {\n    n = v.size();\n    prev_i.resize(n);\n    if (w.empty()) {\n\
    \      w.resize(n);\n      w = v;\n    }\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ compressed.resize(n);\n    prev.resize(cmp.size(), -1);\n    vector<unsigned>\
    \ tmp(n), tmp2(n), tmpc(n);\n    unsigned size_mx = v.size();\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n      if (prev[compressed[i]] != -1) {\n        prev_i[i]\
    \ = prev[compressed[i]];\n      } else {\n        prev_i[i] = 0;\n      }\n  \
    \    prev[compressed[i]] = i + 1;\n    }\n    stInd.resize(cmp.size() + 1, -1);\n\
    \    bitsize = bit_width(size_mx);\n    b.resize(bitsize);\n    cnt.resize(bitsize);\n\
    \    zero.resize(bitsize, 0);\n    zero2.resize(bitsize, 0);\n    vector<bool>\
    \ bit(n, 0), bit2(n, 0);\n    for (unsigned i = 0; i < bitsize; i++) {\n     \
    \ for (unsigned j = 0; j < n; j++) {\n        bit[j] = compressed[j] & (1U <<\
    \ (bitsize - i - 1));\n        zero[i] += unsigned(!bit[j]);\n        bit2[j]\
    \ = prev_i[j] & (1U << (bitsize - i - 1));\n        zero2[i] += unsigned(!bit2[j]);\n\
    \        tmp[j] = w[j];\n        tmp2[j] = prev_i[j];\n        tmpc[j] = compressed[j];\n\
    \      }\n      b[i] = BitVector(bit, compressed);\n      cnt[i] = BitVector(bit2,\
    \ prev_i);\n      int cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n   \
    \     if (!bit[j]) {\n          w[cur] = tmp[j];\n          compressed[cur] =\
    \ tmpc[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0; j\
    \ < n; j++) {\n        if (bit[j]) {\n          w[cur] = tmp[j];\n          compressed[cur]\
    \ = tmpc[j];\n          cur++;\n        }\n      }\n      cur = 0;\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (!bit2[j]) {\n          prev_i[cur]\
    \ = tmp2[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0;\
    \ j < n; j++) {\n        if (bit2[j]) {\n          prev_i[cur] = tmp2[j];\n  \
    \        cur++;\n        }\n      }\n      b[i].srsum_set(w);\n    }\n\n    for\
    \ (unsigned i = 0; i < n; i++) {\n      if (stInd[compressed[i]] == -1) {\n  \
    \      stInd[compressed[i]] = i;\n      }\n    }\n  }\n\n  // get v[k]\n  unsigned\
    \ access(unsigned k) {\n    unsigned res = 0;\n    unsigned cur = k;\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      if (b[i].access(cur)) {\n      \
    \  res |= (1U << (bitsize - i - 1));\n        cur = zero[i] + b[i].rank(cur);\n\
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
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned\
    \ long long rank_less_sum(unsigned l, unsigned r, unsigned k) {\n    unsigned\
    \ long long less_sum = 0;\n    for (unsigned i = 0; i < bitsize and l < r; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n        l\
    \ = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n      } else {\n     \
    \   l = rank0_l;\n        r = rank0_r;\n      }\n    }\n    return less_sum;\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n  unsigned rank_less(unsigned l, unsigned r, unsigned k) {\n\
    \    unsigned less = 0;\n    for (unsigned i = 0; i < bitsize and l < r; i++)\
    \ {\n      const unsigned rank1_l = b[i].rank(l);\n      const unsigned rank1_r\
    \ = b[i].rank(r);\n      const unsigned rank0_l = l - rank1_l;\n      const unsigned\
    \ rank0_r = r - rank1_r;\n      if (k & (1U << (bitsize - i - 1))) {\n       \
    \ less += (rank0_r - rank0_l);\n        l = zero[i] + rank1_l;\n        r = zero[i]\
    \ + rank1_r;\n      } else {\n        l = rank0_l;\n        r = rank0_r;\n   \
    \   }\n    }\n    return less;\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k-1\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  unsigned kth_smallest(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned res = 0;\n    for (unsigned i = 0;\
    \ i < bitsize; i++) {\n      unsigned num1 = b[i].rank(r) - b[i].rank(l);\n  \
    \    unsigned num0 = r - l - num1;\n      if (num0 < k) {\n        res |= (1ULL\
    \ << (bitsize - i - 1));\n        l = zero[i] + b[i].rank(l);\n        r = zero[i]\
    \ + b[i].rank(r);\n        k -= num0;\n      } else {\n        l -= b[i].rank(l);\n\
    \        r -= b[i].rank(r);\n      }\n    }\n    return cmp[res];\n  }\n\n  //\
    \ v[l,r]\u3092\u6607\u9806\u30BD\u30FC\u30C8\u3057\u305F\u6642\u306E\u5148\u982D\
    k\u500B\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  unsigned long long kth_sum(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned long long res = 0;\n    unsigned\
    \ val = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      const unsigned\
    \ rank1_l = b[i].rank(l);\n      const unsigned rank1_r = b[i].rank(r);\n    \
    \  const unsigned rank0_l = l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n\
    \      const unsigned num1 = rank1_r - rank1_l;\n      const unsigned num0 = rank0_r\
    \ - rank0_l;\n      if (num0 < k) {\n        val |= (1ULL << (bitsize - i - 1));\n\
    \        res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);\n       \
    \ l = zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    res += uint64_t(cmp[val]) * uint64_t(k);\n    return res;\n  }\n\n  // v[l,r)\
    \ \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\n  unsigned range_freq(unsigned l, unsigned r, unsigned mink, unsigned\
    \ maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n    return\
    \ rank_less(l, r, maxk) - rank_less(l, r, mink);\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n\
    \  unsigned long long range_sum(unsigned l, unsigned r, unsigned mink, unsigned\
    \ maxk) {\n    mink = compress(mink);\n    maxk = compress(maxk);\n    return\
    \ rank_less_sum(l, r, maxk) - rank_less_sum(l, r, mink);\n  }\n\n  // x\u5EA7\u6A19\
    \u304C[l,r) \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n  unsigned rectangle_freq(unsigned l, unsigned\
    \ r, unsigned d, unsigned u) {\n    l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), l));\n    r = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n    return range_freq(l, r, d, u);\n  }\n\n  // x\u5EA7\u6A19\u304C[l,r)\
    \ \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\u7DCF\u548C\
    \u3092\u8FD4\u3059\n  unsigned long long rectangle_sum(unsigned l, unsigned r,\
    \ unsigned d, unsigned u) {\n    l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), l));\n    r = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n    return range_sum(l, r, d, u);\n  }\n\n  // v[l,r) \u306E\u4E2D\u306E\
    \u5024\u306E\u7A2E\u985E\u6570\u3092\u8FD4\u3059\n  unsigned range_count(unsigned\
    \ l, unsigned r) {\n    return rank_less_prev(l, r, l + 1);\n  }\n\n  // v[l,r)\u306E\
    \u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\
    \u3059\n  unsigned prev_value(unsigned l, unsigned r, unsigned val) {\n    int\
    \ num = range_freq(l, r, 0, val);\n    if (num == 0) {\n      return UINT32_MAX;\n\
    \    } else {\n      return kth_smallest(l, r, num);\n    }\n  }\n\n  // v[l,r)\u306E\
    \u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n\
    \  unsigned next_value(unsigned l, unsigned r, unsigned val) {\n    int num =\
    \ range_freq(l, r, 0, val);\n    if (num == r - l) {\n      return UINT32_MAX;\n\
    \    } else {\n      return kth_smallest(l, r, num + 1);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixRectangle.hpp
  requiredBy: []
  timestamp: '2024-06-26 12:49:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixRectangle.hpp
layout: document
title: Wavelet Matrix (Rectangle)
---

## 概要

todo

## 計算量
todo