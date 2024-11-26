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
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/query/UniqueProduct.hpp\"\n\
    template <class T, auto op, auto e>\nclass BitVector {\n private:\n  unsigned\
    \ n, cur, p;\n  vector<unsigned> acc, bit;\n  segtree<T, op, e> seg;\n\n public:\n\
    \  BitVector() {\n  }\n\n  BitVector(vector<bool> &b) {\n    cur = 0;\n    n =\
    \ b.size();\n    acc.resize((n >> 5) + 2, 0);\n    bit.resize((n >> 5) + 2, 0);\n\
    \    for (int i = 0; i < n; i++) {\n      if (!(i & 31)) {\n        cur++;\n \
    \       acc[cur] = acc[cur - 1];\n      }\n      if (b[i]) {\n        acc[cur]\
    \ += int(b[i]);\n        bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n      }\n\
    \    }\n  }\n\n  inline void seg_set(const vector<T> &v) {\n    seg = segtree<T,\
    \ op, e>(v);\n  }\n\n  inline void val_set(unsigned pos, T x) {\n    seg.set(pos,\
    \ x);\n  }\n  inline void val_get(unsigned pos, T x) {\n    seg.get(pos, x);\n\
    \  }\n\n  inline unsigned rank(unsigned k) {\n    if (!(k & 31)) return acc[k\
    \ >> 5];\n    return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k\
    \ & 31)));\n  }\n\n  inline unsigned rank0(unsigned k) {\n    return k - rank(k);\n\
    \  }\n\n  inline T rank_prod(unsigned l, unsigned r) {\n    return seg.prod(l,\
    \ r);\n  }\n\n  inline bool access(unsigned k) {\n    return (rank(k + 1) - rank(k))\
    \ == 1;\n  }\n};\n\ntemplate <class T, auto op, auto e>\nclass WaveletMatrix {\n\
    \ private:\n  unsigned n;\n  unsigned bitsize;\n  vector<BitVector<T, op, e>>\
    \ b;\n  vector<BitVector<T, op, e>> cnt;\n  vector<unsigned> zero, zero2;\n  vector<unsigned>\
    \ prev_i;\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<T> v, vector<T> w) {\n    n = v.size();\n    vector<int>\
    \ prev;\n    prev_i.resize(n);\n    vector<unsigned> compressed(n);\n    vector<T>\
    \ cmp(n);\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    prev.resize(cmp.size(), -1);\n    vector<unsigned>\
    \ tmp2(n), tmpc(n);\n    vector<T> tmp(n);\n    unsigned size_mx = v.size();\n\
    \    for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n      if (prev[compressed[i]] !=\
    \ -1) {\n        prev_i[i] = prev[compressed[i]];\n      } else {\n        prev_i[i]\
    \ = 0;\n      }\n      prev[compressed[i]] = i + 1;\n    }\n    bitsize = bit_width(n);\n\
    \    b.resize(bitsize);\n    cnt.resize(bitsize);\n    zero.resize(bitsize, 0);\n\
    \    zero2.resize(bitsize, 0);\n    vector<bool> bit(n, 0), bit2(n, 0);\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        bit[j] = compressed[j] & (1U << (bitsize - i - 1));\n        zero[i]\
    \ += unsigned(!bit[j]);\n        bit2[j] = prev_i[j] & (1U << (bitsize - i - 1));\n\
    \        zero2[i] += unsigned(!bit2[j]);\n        tmp[j] = w[j];\n        tmp2[j]\
    \ = prev_i[j];\n        tmpc[j] = compressed[j];\n      }\n      b[i] = BitVector<T,\
    \ op, e>(bit);\n      cnt[i] = BitVector<T, op, e>(bit2);\n      int cur = 0;\n\
    \      for (unsigned j = 0; j < n; j++) {\n        if (!bit[j]) {\n          compressed[cur]\
    \ = tmpc[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0;\
    \ j < n; j++) {\n        if (bit[j]) {\n          compressed[cur] = tmpc[j];\n\
    \          cur++;\n        }\n      }\n      cur = 0;\n      for (unsigned j =\
    \ 0; j < n; j++) {\n        if (!bit2[j]) {\n          w[cur] = tmp[j];\n    \
    \      prev_i[cur] = tmp2[j];\n          cur++;\n        }\n      }\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (bit2[j]) {\n          w[cur] = tmp[j];\n\
    \          prev_i[cur] = tmp2[j];\n          cur++;\n        }\n      }\n    \
    \  b[i].seg_set(w);\n    }\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u91CD\u8907\u3092\
    \u9664\u3044\u305F\u5024\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n  T unique_prod(unsigned\
    \ l, unsigned r) {\n    unsigned k = l + 1;\n    T res = 0;\n    for (unsigned\
    \ i = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l = cnt[i].rank(l);\n\
    \      const unsigned rank1_r = cnt[i].rank(r);\n      const unsigned rank0_l\
    \ = cnt[i].rank0(l);\n      const unsigned rank0_r = cnt[i].rank0(r);\n      if\
    \ (k & (1U << (bitsize - i - 1))) {\n        res = op(res, b[i].rank_prod(rank0_l,\
    \ rank0_r));\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return res;\n  }\n};\n"
  code: "template <class T, auto op, auto e>\nclass BitVector {\n private:\n  unsigned\
    \ n, cur, p;\n  vector<unsigned> acc, bit;\n  segtree<T, op, e> seg;\n\n public:\n\
    \  BitVector() {\n  }\n\n  BitVector(vector<bool> &b) {\n    cur = 0;\n    n =\
    \ b.size();\n    acc.resize((n >> 5) + 2, 0);\n    bit.resize((n >> 5) + 2, 0);\n\
    \    for (int i = 0; i < n; i++) {\n      if (!(i & 31)) {\n        cur++;\n \
    \       acc[cur] = acc[cur - 1];\n      }\n      if (b[i]) {\n        acc[cur]\
    \ += int(b[i]);\n        bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n      }\n\
    \    }\n  }\n\n  inline void seg_set(const vector<T> &v) {\n    seg = segtree<T,\
    \ op, e>(v);\n  }\n\n  inline void val_set(unsigned pos, T x) {\n    seg.set(pos,\
    \ x);\n  }\n  inline void val_get(unsigned pos, T x) {\n    seg.get(pos, x);\n\
    \  }\n\n  inline unsigned rank(unsigned k) {\n    if (!(k & 31)) return acc[k\
    \ >> 5];\n    return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k\
    \ & 31)));\n  }\n\n  inline unsigned rank0(unsigned k) {\n    return k - rank(k);\n\
    \  }\n\n  inline T rank_prod(unsigned l, unsigned r) {\n    return seg.prod(l,\
    \ r);\n  }\n\n  inline bool access(unsigned k) {\n    return (rank(k + 1) - rank(k))\
    \ == 1;\n  }\n};\n\ntemplate <class T, auto op, auto e>\nclass WaveletMatrix {\n\
    \ private:\n  unsigned n;\n  unsigned bitsize;\n  vector<BitVector<T, op, e>>\
    \ b;\n  vector<BitVector<T, op, e>> cnt;\n  vector<unsigned> zero, zero2;\n  vector<unsigned>\
    \ prev_i;\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<T> v, vector<T> w) {\n    n = v.size();\n    vector<int>\
    \ prev;\n    prev_i.resize(n);\n    vector<unsigned> compressed(n);\n    vector<T>\
    \ cmp(n);\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    prev.resize(cmp.size(), -1);\n    vector<unsigned>\
    \ tmp2(n), tmpc(n);\n    vector<T> tmp(n);\n    unsigned size_mx = v.size();\n\
    \    for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n      if (prev[compressed[i]] !=\
    \ -1) {\n        prev_i[i] = prev[compressed[i]];\n      } else {\n        prev_i[i]\
    \ = 0;\n      }\n      prev[compressed[i]] = i + 1;\n    }\n    bitsize = bit_width(n);\n\
    \    b.resize(bitsize);\n    cnt.resize(bitsize);\n    zero.resize(bitsize, 0);\n\
    \    zero2.resize(bitsize, 0);\n    vector<bool> bit(n, 0), bit2(n, 0);\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        bit[j] = compressed[j] & (1U << (bitsize - i - 1));\n        zero[i]\
    \ += unsigned(!bit[j]);\n        bit2[j] = prev_i[j] & (1U << (bitsize - i - 1));\n\
    \        zero2[i] += unsigned(!bit2[j]);\n        tmp[j] = w[j];\n        tmp2[j]\
    \ = prev_i[j];\n        tmpc[j] = compressed[j];\n      }\n      b[i] = BitVector<T,\
    \ op, e>(bit);\n      cnt[i] = BitVector<T, op, e>(bit2);\n      int cur = 0;\n\
    \      for (unsigned j = 0; j < n; j++) {\n        if (!bit[j]) {\n          compressed[cur]\
    \ = tmpc[j];\n          cur++;\n        }\n      }\n      for (unsigned j = 0;\
    \ j < n; j++) {\n        if (bit[j]) {\n          compressed[cur] = tmpc[j];\n\
    \          cur++;\n        }\n      }\n      cur = 0;\n      for (unsigned j =\
    \ 0; j < n; j++) {\n        if (!bit2[j]) {\n          w[cur] = tmp[j];\n    \
    \      prev_i[cur] = tmp2[j];\n          cur++;\n        }\n      }\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (bit2[j]) {\n          w[cur] = tmp[j];\n\
    \          prev_i[cur] = tmp2[j];\n          cur++;\n        }\n      }\n    \
    \  b[i].seg_set(w);\n    }\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067\u91CD\u8907\u3092\
    \u9664\u3044\u305F\u5024\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n  T unique_prod(unsigned\
    \ l, unsigned r) {\n    unsigned k = l + 1;\n    T res = 0;\n    for (unsigned\
    \ i = 0; i < bitsize and l < r; i++) {\n      const unsigned rank1_l = cnt[i].rank(l);\n\
    \      const unsigned rank1_r = cnt[i].rank(r);\n      const unsigned rank0_l\
    \ = cnt[i].rank0(l);\n      const unsigned rank0_r = cnt[i].rank0(r);\n      if\
    \ (k & (1U << (bitsize - i - 1))) {\n        res = op(res, b[i].rank_prod(rank0_l,\
    \ rank0_r));\n        l = zero2[i] + rank1_l;\n        r = zero2[i] + rank1_r;\n\
    \      } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n\
    \    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/query/UniqueProduct.hpp
  requiredBy: []
  timestamp: '2024-11-27 01:22:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/query/UniqueProduct.hpp
layout: document
title: Unique Product Query
---

## 概要

todo

## 計算量
todo