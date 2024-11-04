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
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrix3D.hpp\"\n#include\
    \ <WaveletMatrixTemplate.hpp>\n\ntemplate <class T>\nclass WaveletMatrix3d {\n\
    \   private:\n    unsigned n;\n    unsigned bitsize;\n    vector<BitVector<T>>\
    \ b;\n    vector<WaveletMatrix<T>> w;\n    vector<unsigned> zero;\n    vector<int>\
    \ stInd;\n    vector<unsigned> compressed;\n    vector<T> cmp, px;\n    T MI,\
    \ MA;\n\n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n    unsigned rank_less(unsigned l, unsigned r, T d,\
    \ T u, T k) {\n        unsigned less = 0;\n        for (unsigned i = 0; i < bitsize\
    \ and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n    \
    \        const unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l\
    \ = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n        \
    \    if (k & (1U << (bitsize - i - 1))) {\n                less += w[i].range_freq(rank0_l,\
    \ rank0_r, d, u);\n                l = zero[i] + rank1_l;\n                r =\
    \ zero[i] + rank1_r;\n            } else {\n                l = rank0_l;\n   \
    \             r = rank0_r;\n            }\n        }\n        return less;\n \
    \   }\n\n    inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n    unsigned range_freq(unsigned l, unsigned\
    \ r, T d, T u, T s, T t) {\n        d = compress(d);\n        u = compress(u);\n\
    \        if (d == 0) {\n            return rank_less(l, r, s, t, u);\n       \
    \ }\n        return rank_less(l, r, s, t, u) - rank_less(l, r, s, t, d);\n   \
    \ }\n\n    T kth_smallest(unsigned l, unsigned r, T d, T u, unsigned k) {\n  \
    \      unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n \
    \           unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = w[i].range_freq(l - b[i].rank(l), r - b[i].rank(r), d, u);\n        \
    \    if (num0 < k) {\n                res |= (1ULL << (bitsize - i - 1));\n  \
    \              l = zero[i] + b[i].rank(l);\n                r = zero[i] + b[i].rank(r);\n\
    \                k -= num0;\n            } else {\n                l -= b[i].rank(l);\n\
    \                r -= b[i].rank(r);\n            }\n        }\n        return\
    \ cmp[res];\n    }\n\n   public:\n       WaveletMatrix3d(vector<T> x, vector<T>\
    \ y, vector<T> z) {\n        n = x.size();\n        px.resize(n);\n        vector<tuple<T,\
    \ T, T>> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i] = {x[i],\
    \ z[i], y[i]};\n        }\n        sort(v.begin(), v.end());\n        for (int\
    \ i = 0; i < n; i++) {\n            px[i] = get<0>(v[i]);\n            z[i] =\
    \ get<1>(v[i]);\n            y[i] = get<2>(v[i]);\n        }\n        cmp.resize(z.size());\n\
    \        cmp = z;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        compressed.resize(n);\n        vector<unsigned>\
    \ tmp(n), tmpc(n);\n        unsigned size_mx = z.size();\n        for (unsigned\
    \ i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), z[i]));\n        }\n        stInd.resize(cmp.size() + 1, -1);\n \
    \       bitsize = bit_width(cmp.size() + 1);\n        b.resize(bitsize);\n   \
    \     w.resize(bitsize);\n        zero.resize(bitsize, 0);\n        vector<bool>\
    \ bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U\
    \ << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n    \
    \            tmp[j] = y[j];\n                tmpc[j] = compressed[j];\n      \
    \      }\n            b[i] = BitVector<T>(bit);\n            int cur = 0;\n  \
    \          for (unsigned j = 0; j < n; j++) {\n                if (!bit[j]) {\n\
    \                    y[cur] = tmp[j];\n                    compressed[cur] = tmpc[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        y[cur] = tmp[j];\n                    compressed[cur] = tmpc[j];\n  \
    \                  cur++;\n                }\n            }\n            w[i]\
    \ = WaveletMatrix<T>(y);\n        }\n        for (unsigned i = 0; i < n; i++)\
    \ {\n            if (stInd[compressed[i]] == -1) {\n                stInd[compressed[i]]\
    \ = i;\n            }\n        }\n    }\n\n    unsigned rectangle_kth(int l, int\
    \ r, int d, int u, unsigned k) {\n        l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), l));\n        r = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n        return kth_smallest(l, r, d, u, k);\n    }\n\n    unsigned space_freq(T\
    \ xl, T xr, T yl, T yr, T zl, T zr) {\n        xl = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xl));\n        xr = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ xr));\n        return range_freq(xl, xr, yl, yr, zl, zr);\n    }\n};\n"
  code: "#include <WaveletMatrixTemplate.hpp>\n\ntemplate <class T>\nclass WaveletMatrix3d\
    \ {\n   private:\n    unsigned n;\n    unsigned bitsize;\n    vector<BitVector<T>>\
    \ b;\n    vector<WaveletMatrix<T>> w;\n    vector<unsigned> zero;\n    vector<int>\
    \ stInd;\n    vector<unsigned> compressed;\n    vector<T> cmp, px;\n    T MI,\
    \ MA;\n\n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n    unsigned rank_less(unsigned l, unsigned r, T d,\
    \ T u, T k) {\n        unsigned less = 0;\n        for (unsigned i = 0; i < bitsize\
    \ and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n    \
    \        const unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l\
    \ = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n        \
    \    if (k & (1U << (bitsize - i - 1))) {\n                less += w[i].range_freq(rank0_l,\
    \ rank0_r, d, u);\n                l = zero[i] + rank1_l;\n                r =\
    \ zero[i] + rank1_r;\n            } else {\n                l = rank0_l;\n   \
    \             r = rank0_r;\n            }\n        }\n        return less;\n \
    \   }\n\n    inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n    unsigned range_freq(unsigned l, unsigned\
    \ r, T d, T u, T s, T t) {\n        d = compress(d);\n        u = compress(u);\n\
    \        if (d == 0) {\n            return rank_less(l, r, s, t, u);\n       \
    \ }\n        return rank_less(l, r, s, t, u) - rank_less(l, r, s, t, d);\n   \
    \ }\n\n    T kth_smallest(unsigned l, unsigned r, T d, T u, unsigned k) {\n  \
    \      unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n \
    \           unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = w[i].range_freq(l - b[i].rank(l), r - b[i].rank(r), d, u);\n        \
    \    if (num0 < k) {\n                res |= (1ULL << (bitsize - i - 1));\n  \
    \              l = zero[i] + b[i].rank(l);\n                r = zero[i] + b[i].rank(r);\n\
    \                k -= num0;\n            } else {\n                l -= b[i].rank(l);\n\
    \                r -= b[i].rank(r);\n            }\n        }\n        return\
    \ cmp[res];\n    }\n\n   public:\n       WaveletMatrix3d(vector<T> x, vector<T>\
    \ y, vector<T> z) {\n        n = x.size();\n        px.resize(n);\n        vector<tuple<T,\
    \ T, T>> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i] = {x[i],\
    \ z[i], y[i]};\n        }\n        sort(v.begin(), v.end());\n        for (int\
    \ i = 0; i < n; i++) {\n            px[i] = get<0>(v[i]);\n            z[i] =\
    \ get<1>(v[i]);\n            y[i] = get<2>(v[i]);\n        }\n        cmp.resize(z.size());\n\
    \        cmp = z;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        compressed.resize(n);\n        vector<unsigned>\
    \ tmp(n), tmpc(n);\n        unsigned size_mx = z.size();\n        for (unsigned\
    \ i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), z[i]));\n        }\n        stInd.resize(cmp.size() + 1, -1);\n \
    \       bitsize = bit_width(cmp.size() + 1);\n        b.resize(bitsize);\n   \
    \     w.resize(bitsize);\n        zero.resize(bitsize, 0);\n        vector<bool>\
    \ bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U\
    \ << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n    \
    \            tmp[j] = y[j];\n                tmpc[j] = compressed[j];\n      \
    \      }\n            b[i] = BitVector<T>(bit);\n            int cur = 0;\n  \
    \          for (unsigned j = 0; j < n; j++) {\n                if (!bit[j]) {\n\
    \                    y[cur] = tmp[j];\n                    compressed[cur] = tmpc[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        y[cur] = tmp[j];\n                    compressed[cur] = tmpc[j];\n  \
    \                  cur++;\n                }\n            }\n            w[i]\
    \ = WaveletMatrix<T>(y);\n        }\n        for (unsigned i = 0; i < n; i++)\
    \ {\n            if (stInd[compressed[i]] == -1) {\n                stInd[compressed[i]]\
    \ = i;\n            }\n        }\n    }\n\n    unsigned rectangle_kth(int l, int\
    \ r, int d, int u, unsigned k) {\n        l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), l));\n        r = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n        return kth_smallest(l, r, d, u, k);\n    }\n\n    unsigned space_freq(T\
    \ xl, T xr, T yl, T yr, T zl, T zr) {\n        xl = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xl));\n        xr = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ xr));\n        return range_freq(xl, xr, yl, yr, zl, zr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrix3D.hpp
  requiredBy: []
  timestamp: '2024-11-04 22:20:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrix3D.hpp
layout: document
title: Wavelet Matrix (3D)
---

## 概要

todo

## 計算量
todo