---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
    title: Wavelet Matrix (Segment Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/query/RangeMex.hpp\"\n\n#line\
    \ 1 \"data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp\"\nstruct BitVector\
    \ {\n    unsigned sz;\n    unsigned blocksize;\n    vector<unsigned> bit, sum;\n\
    \n    BitVector() {}\n\n    BitVector(unsigned siz) {\n        sz = siz;\n   \
    \     blocksize = (sz + 31) >> 5;\n        bit.assign(blocksize, 0U);\n      \
    \  sum.assign(blocksize, 0U);\n    }\n\n    inline void set(int k) { bit[k >>\
    \ 5] |= 1U << (k & 31); }\n\n    inline void build() {\n        sum[0] = 0U;\n\
    \        for (int i = 1; i < blocksize; i++) {\n            sum[i] = sum[i - 1]\
    \ + __builtin_popcount(bit[i - 1]);\n        }\n    }\n\n    inline bool access(unsigned\
    \ k) {\n        return (bool((bit[k >> 5] >> (k & 31)) & 1));\n    }\n\n    inline\
    \ int rank(int k) {\n        return (sum[k >> 5] + __builtin_popcount(bit[k >>\
    \ 5] & ((1U << (k & 31)) - 1)));\n    }\n};\n\ntemplate <class S, auto op, auto\
    \ e, class T>\nclass WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned\
    \ bitsize;\n    vector<BitVector> b;\n    vector<segtree<S, op, e>> seg;\n   \
    \ vector<unsigned> zero;\n    vector<T> cmp;\n    T MI, MA;\n\n    inline unsigned\
    \ compress(const T &x) {\n        return lower_bound(cmp.begin(), cmp.end(), x)\
    \ - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n    WaveletMatrix() {}\n    WaveletMatrix(vector<T> v) {\n        MI =\
    \ numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n        n\
    \ = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n     \
    \   cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<T> tmp(n);\n\
    \        vector<T> tmpc(n);\n        vector<T> compressed(n);\n        for (unsigned\
    \ i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        seg.resize(bitsize + 1);\n        zero.resize(bitsize,\
    \ 0);\n        int cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            b[i] = BitVector(n + 1);\n            seg[i] = segtree<T, op, e>(v);\n\
    \            cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n      \
    \          if (compressed[j] & (1U << (bitsize - i - 1))) {\n                \
    \    b[i].set(j);\n                } else {\n                    zero[i]++;\n\
    \                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = v[j];\n                    cur++;\n                }\n            }\n    \
    \        b[i].build();\n            for (int j = 0; j < n; j++) {\n          \
    \      if (compressed[j] & (1U << (bitsize - i - 1))) {\n                    tmpc[cur]\
    \ = compressed[j];\n                    tmp[cur] = v[j];\n                   \
    \ cur++;\n                }\n            }\n            swap(tmpc, compressed);\n\
    \            swap(tmp, v);\n        }\n        b[bitsize] = BitVector(n + 1);\n\
    \        seg[bitsize] = segtree<T, op, e>(v);\n    }\n\n    WaveletMatrix(vector<T>\
    \ v, vector<S> w) {\n        MI = numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n\
    \        n = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n\
    \        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<S>\
    \ tmp(n);\n        vector<T> tmpc(n);\n        vector<T> compressed(n);\n    \
    \    for (unsigned i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize + 1);\n        seg.resize(bitsize + 1);\n        zero.resize(bitsize,\
    \ 0);\n        int cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            b[i] = BitVector(n + 1);\n            seg[i] = segtree<S, op, e>(w);\n\
    \            cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n      \
    \          if (compressed[j] & (1U << (bitsize - i - 1))) {\n                \
    \    b[i].set(j);\n                } else {\n                    zero[i]++;\n\
    \                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = w[j];\n                    cur++;\n                }\n            }\n    \
    \        b[i].build();\n            for (int j = 0; j < n; j++) {\n          \
    \      if (compressed[j] & (1U << (bitsize - i - 1))) {\n                    tmpc[cur]\
    \ = compressed[j];\n                    tmp[cur] = w[j];\n                   \
    \ cur++;\n                }\n            }\n            swap(tmpc, compressed);\n\
    \            swap(tmp, w);\n        }\n        b[bitsize] = BitVector(n + 1);\n\
    \        seg[bitsize] = segtree<S, op, e>(w);\n    }\n\n    void set(int p, S\
    \ x) {\n        unsigned cur = p;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            seg[i].set(cur, x);\n            if (b[i].access(cur)) {\n  \
    \              cur = zero[i] + b[i].rank(cur);\n            } else {\n       \
    \         cur -= b[i].rank(cur);\n            }\n        }\n        seg[bitsize].set(cur,\
    \ x);\n    }\n\n    S get(int p) {\n        return seg[0].get(p);\n    }\n\n \
    \   // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\
    \u7A4D\u3092\u8FD4\u3059\n    S range_prod(int vl, int vr, T mink, T maxk) {\n\
    \        int D = compress(mink);\n        int U = compress(maxk);\n        S res\
    \ = e();\n        auto dfs = [&](auto &rec, int d, int L, int R, int A, int B)\
    \ -> void {\n            if (U <= A or B <= D) return;\n            if (D <= A\
    \ and B <= U) {\n                res = op(res, seg[d].prod(L, R));\n         \
    \       return;\n            }\n            if (d == bitsize) {\n            \
    \    if (D <= A and A < U) {\n                    res = op(res, seg[bitsize].prod(L,\
    \ R));\n                }\n                return;\n            }\n          \
    \  int C = (A + B) >> 1;\n            int rank0_l = L - b[d].rank(L);\n      \
    \      int rank0_r = R - b[d].rank(R);\n            int rank1_l = b[d].rank(L)\
    \ + zero[d];\n            int rank1_r = b[d].rank(R) + zero[d];\n\n          \
    \  rec(rec, d + 1, rank0_l, rank0_r, A, C);\n            rec(rec, d + 1, rank1_l,\
    \ rank1_r, C, B);\n        };\n        dfs(dfs, 0, vl, vr, 0, 1 << bitsize);\n\
    \        return res;\n    }\n};\n#line 3 \"data-structure/wavelet-matrix/query/RangeMex.hpp\"\
    \nusing S = int;\nS op(S a, S b) {\n  return min(a, b);\n}\n\nS e() {\n  return\
    \ INT_MAX;\n}\nclass RangeMex {\n private:\n  int n;\n  WaveletMatrix<S, op, e>\
    \ wm;\n\n public:\n  RangeMex(const vector<int> &v) {\n    n = v.size();\n   \
    \ vector<int> x, y, z;\n    vector<int> last(n + 1, -1);\n    x.reserve(n * 2);\n\
    \    y.reserve(n * 2);\n    z.reserve(n * 2);\n\n    for (int i = 0; i < n; i++)\
    \ {\n      if (v[i] > n) continue;\n      x.emplace_back(last[v[i]]);\n      y.emplace_back(i);\n\
    \      z.emplace_back(v[i]);\n      last[v[i]] = i;\n    }\n\n    for (int i =\
    \ 0; i < n + 1; i++) {\n      x.emplace_back(last[i]);\n      y.emplace_back(n);\n\
    \      z.emplace_back(i);\n    }\n\n    wm = WaveletMatrix<S, op, e>(x, y, z);\n\
    \  }\n\n  int range_mex(int l, int r) {\n    return wm.rectangle_prod(-1, l, r,\
    \ n + 1);\n  }\n};\n"
  code: "\n#include \"../WaveletMatrixSegtree.hpp\"\nusing S = int;\nS op(S a, S b)\
    \ {\n  return min(a, b);\n}\n\nS e() {\n  return INT_MAX;\n}\nclass RangeMex {\n\
    \ private:\n  int n;\n  WaveletMatrix<S, op, e> wm;\n\n public:\n  RangeMex(const\
    \ vector<int> &v) {\n    n = v.size();\n    vector<int> x, y, z;\n    vector<int>\
    \ last(n + 1, -1);\n    x.reserve(n * 2);\n    y.reserve(n * 2);\n    z.reserve(n\
    \ * 2);\n\n    for (int i = 0; i < n; i++) {\n      if (v[i] > n) continue;\n\
    \      x.emplace_back(last[v[i]]);\n      y.emplace_back(i);\n      z.emplace_back(v[i]);\n\
    \      last[v[i]] = i;\n    }\n\n    for (int i = 0; i < n + 1; i++) {\n     \
    \ x.emplace_back(last[i]);\n      y.emplace_back(n);\n      z.emplace_back(i);\n\
    \    }\n\n    wm = WaveletMatrix<S, op, e>(x, y, z);\n  }\n\n  int range_mex(int\
    \ l, int r) {\n    return wm.rectangle_prod(-1, l, r, n + 1);\n  }\n};"
  dependsOn:
  - data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/query/RangeMex.hpp
  requiredBy: []
  timestamp: '2025-05-12 02:45:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/query/RangeMex.hpp
layout: document
title: Range Mex Query
---

## 概要

todo

## 計算量
todo