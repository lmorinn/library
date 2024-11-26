---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix/query/PointSetRangeFreq.hpp
    title: Point Set Range Frequency
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/wavelet-matrix/RangeKthSmallest.test.cpp
    title: verify/LibraryChecker/data-structure/wavelet-matrix/RangeKthSmallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/wavelet-matrix/StaticRangeFrequency.test.cpp
    title: verify/LibraryChecker/data-structure/wavelet-matrix/StaticRangeFrequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/wavelet-matrix/query/PointSetRangeFrequency.test.cpp
    title: verify/LibraryChecker/data-structure/wavelet-matrix/query/PointSetRangeFrequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp\"\
    \nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned>\
    \ bit, sum;\n\n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n\
    \    blocksize = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class T>\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned bitsize;\n\
    \  vector<BitVector> b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n  T MI, MA;\n\
    \n  inline unsigned compress(const T &x) {\n    return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n  WaveletMatrix() {}\n  WaveletMatrix(const vector<T> &v) {\n  \
    \  MI = numeric_limits<T>::min();\n    MA = numeric_limits<T>::max();\n    n =\
    \ v.size();\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    vector<unsigned> compressed(n);\n    vector<unsigned>\
    \ tmpc(n);\n    unsigned size_mx = v.size();\n    for (unsigned i = 0; i < n;\
    \ i++) {\n      compressed[i] = compress(v[i]);\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize);\n    zero.assign(bitsize, 0);\n    int cur = 0;\n\n  \
    \  for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n\
    \      cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n        } else {\n \
    \         zero[i]++;\n          tmpc[cur] = compressed[j];\n          cur++;\n\
    \        }\n      }\n      b[i].build();\n\n      for (unsigned j = 0; j < n;\
    \ j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n         \
    \ tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n      swap(tmpc,\
    \ compressed);\n    }\n  }\n\n  // get v[k]\n  T access(unsigned k) {\n    unsigned\
    \ res = 0;\n    unsigned cur = k;\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      if (b[i].access(cur)) {\n        res |= (1U << (bitsize - i - 1));\n\
    \        cur = zero[i] + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n\
    \      }\n    }\n    return cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\
    \u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  T kth_smallest(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned res = 0;\n    unsigned rank1_l, rank1_r,\
    \ num0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      rank1_l = b[i].rank(l);\n\
    \      rank1_r = b[i].rank(r);\n      num0 = r - l - (rank1_r - rank1_l);\n  \
    \    if (num0 < k) {\n        res |= (1U << (bitsize - i - 1));\n        l = zero[i]\
    \ + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n      } else\
    \ {\n        l -= rank1_l;\n        r -= rank1_r;\n      }\n    }\n    return\
    \ cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\
    \u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n  T kth_largest(unsigned l, unsigned\
    \ r, unsigned k) {\n    return kth_smallest(l, r, r - l - k + 1);\n  }\n\n  //\
    \ v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n  unsigned range_freq(int vl, int vr, T mink, T maxk) {\n\
    \    int D = compress(mink);\n    int U = compress(maxk);\n    unsigned res =\
    \ 0;\n    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void\
    \ {\n      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n   \
    \     res += (R - L);\n        return;\n      }\n      if (d == bitsize) {\n \
    \       if (D <= A and A < U) {\n          res += (R - L);\n        }\n      \
    \  return;\n      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r)\u306E\u4E2D\
    \u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\
    \n  T prev_value(unsigned l, unsigned r, T val) {\n    int num = range_freq(l,\
    \ r, MI, val);\n    if (num == 0) {\n      return MA;\n    } else {\n      return\
    \ kth_smallest(l, r, num);\n    }\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n  T next_value(unsigned\
    \ l, unsigned r, T val) {\n    int num = range_freq(l, r, MI, val);\n    if (num\
    \ == r - l) {\n      return MI;\n    } else {\n      return kth_smallest(l, r,\
    \ num + 1);\n    }\n  }\n};\n"
  code: "struct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned>\
    \ bit, sum;\n\n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n\
    \    blocksize = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class T>\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned bitsize;\n\
    \  vector<BitVector> b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n  T MI, MA;\n\
    \n  inline unsigned compress(const T &x) {\n    return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n  WaveletMatrix() {}\n  WaveletMatrix(const vector<T> &v) {\n  \
    \  MI = numeric_limits<T>::min();\n    MA = numeric_limits<T>::max();\n    n =\
    \ v.size();\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    vector<unsigned> compressed(n);\n    vector<unsigned>\
    \ tmpc(n);\n    unsigned size_mx = v.size();\n    for (unsigned i = 0; i < n;\
    \ i++) {\n      compressed[i] = compress(v[i]);\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize);\n    zero.assign(bitsize, 0);\n    int cur = 0;\n\n  \
    \  for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n\
    \      cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n        } else {\n \
    \         zero[i]++;\n          tmpc[cur] = compressed[j];\n          cur++;\n\
    \        }\n      }\n      b[i].build();\n\n      for (unsigned j = 0; j < n;\
    \ j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n         \
    \ tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n      swap(tmpc,\
    \ compressed);\n    }\n  }\n\n  // get v[k]\n  T access(unsigned k) {\n    unsigned\
    \ res = 0;\n    unsigned cur = k;\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      if (b[i].access(cur)) {\n        res |= (1U << (bitsize - i - 1));\n\
    \        cur = zero[i] + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n\
    \      }\n    }\n    return cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\
    \u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  T kth_smallest(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned res = 0;\n    unsigned rank1_l, rank1_r,\
    \ num0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      rank1_l = b[i].rank(l);\n\
    \      rank1_r = b[i].rank(r);\n      num0 = r - l - (rank1_r - rank1_l);\n  \
    \    if (num0 < k) {\n        res |= (1U << (bitsize - i - 1));\n        l = zero[i]\
    \ + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n      } else\
    \ {\n        l -= rank1_l;\n        r -= rank1_r;\n      }\n    }\n    return\
    \ cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\
    \u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n  T kth_largest(unsigned l, unsigned\
    \ r, unsigned k) {\n    return kth_smallest(l, r, r - l - k + 1);\n  }\n\n  //\
    \ v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n  unsigned range_freq(int vl, int vr, T mink, T maxk) {\n\
    \    int D = compress(mink);\n    int U = compress(maxk);\n    unsigned res =\
    \ 0;\n    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void\
    \ {\n      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n   \
    \     res += (R - L);\n        return;\n      }\n      if (d == bitsize) {\n \
    \       if (D <= A and A < U) {\n          res += (R - L);\n        }\n      \
    \  return;\n      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r)\u306E\u4E2D\
    \u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\
    \n  T prev_value(unsigned l, unsigned r, T val) {\n    int num = range_freq(l,\
    \ r, MI, val);\n    if (num == 0) {\n      return MA;\n    } else {\n      return\
    \ kth_smallest(l, r, num);\n    }\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n  T next_value(unsigned\
    \ l, unsigned r, T val) {\n    int num = range_freq(l, r, MI, val);\n    if (num\
    \ == r - l) {\n      return MI;\n    } else {\n      return kth_smallest(l, r,\
    \ num + 1);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
  requiredBy:
  - data-structure/wavelet-matrix/query/PointSetRangeFreq.hpp
  timestamp: '2024-11-09 12:35:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/wavelet-matrix/query/PointSetRangeFrequency.test.cpp
  - verify/LibraryChecker/data-structure/wavelet-matrix/RangeKthSmallest.test.cpp
  - verify/LibraryChecker/data-structure/wavelet-matrix/StaticRangeFrequency.test.cpp
documentation_of: data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
layout: document
title: Wavelet Matrix (Template)
---

## 概要

todo

## 計算量
todo