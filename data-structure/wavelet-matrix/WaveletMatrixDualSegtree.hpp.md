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
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp\"\
    \ntemplate <class S, class F, auto mapping, auto composition, auto id>\nstruct\
    \ DualSegmentTree {\n   private:\n    int n;\n    vector<F> node;\n    F ID;\n\
    \    void Apply(int a, int b, F x, int k = 0, int l = 0, int r = -1) {\n     \
    \   if (r < 0) r = n;\n        eval(k, l, r);\n        if (r <= a or b <= l) return;\n\
    \        if (a <= l and r <= b) {\n            node[k] = composition(x, node[k]);\n\
    \            eval(k, l, r);\n            return;\n        }\n        Apply(a,\
    \ b, x, (k << 1) + 1, l, (l + r) >> 1);\n        Apply(a, b, x, (k << 1) + 2,\
    \ (l + r) >> 1, r);\n    }\n\n    void eval(int k, int l, int r) {\n        if\
    \ (r - l > 1) {\n            node[(k << 1) + 1] = composition(node[k], node[(k\
    \ << 1) + 1]);\n            node[(k << 1) + 2] = composition(node[k], node[(k\
    \ << 1) + 2]);\n            node[k] = ID;\n        }\n    }\n\n   public:\n  \
    \  DualSegmentTree() {}\n    DualSegmentTree(vector<S> &v) {\n        int sz =\
    \ v.size();\n        n = 1;\n        while (n < sz) n <<= 1;\n        node.resize((n\
    \ << 1) - 1, id());\n        ID = id();\n    }\n\n    void apply(int l, int r,\
    \ F x) {\n        Apply(l, r, x);\n    }\n\n    F getf(int p) {\n        p +=\
    \ (n - 1);\n        F f = node[p];\n        while (p > 0) {\n            p = (p\
    \ - 1) >> 1;\n            f = composition(node[p], f);\n        }\n        return\
    \ f;\n    }\n};\n\nstruct BitVector {\n    unsigned sz;\n    unsigned blocksize;\n\
    \    vector<unsigned> bit, sum;\n\n    BitVector() {}\n\n    BitVector(unsigned\
    \ siz) {\n        sz = siz;\n        blocksize = (sz + 31) >> 5;\n        bit.assign(blocksize,\
    \ 0U);\n        sum.assign(blocksize, 0U);\n    }\n\n    inline void set(int k)\
    \ { bit[k >> 5] |= 1U << (k & 31); }\n\n    inline void build() {\n        sum[0]\
    \ = 0U;\n        for (int i = 1; i < blocksize; i++) {\n            sum[i] = sum[i\
    \ - 1] + __builtin_popcount(bit[i - 1]);\n        }\n    }\n\n    inline bool\
    \ access(unsigned k) {\n        return (bool((bit[k >> 5] >> (k & 31)) & 1));\n\
    \    }\n\n    inline int rank(int k) {\n        return (sum[k >> 5] + __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1)));\n    }\n};\n\ntemplate <class T, class F,\
    \ auto mapping, auto composition, auto id>\nclass WaveletMatrix {\n   private:\n\
    \    unsigned n;\n    unsigned bitsize;\n    vector<BitVector> b;\n    vector<unsigned>\
    \ zero;\n    vector<T> cmp;\n    vector<T> px;\n    vector<int> index;\n    vector<T>\
    \ arr;\n    vector<DualSegmentTree<T, F, mapping, composition, id>> seg;\n\n \
    \   inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n    WaveletMatrix() {}\n\n    WaveletMatrix(vector<T> x, vector<T>\
    \ y, vector<T> w) {\n        n = x.size();\n        index.resize(n);\n       \
    \ px.resize(n);\n        arr = w;\n        vector<tuple<T, T, T, int>> v(n);\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] = {x[i], y[i], w[i],\
    \ i};\n        }\n        sort(v.begin(), v.end(), [](const tuple<T, T, T, int>\
    \ &l, const tuple<T, T, T, int> &r) {\n            return get<0>(l) < get<0>(r);\n\
    \        });\n        for (int i = 0; i < n; i++) {\n            px[i] = get<0>(v[i]);\n\
    \            y[i] = get<1>(v[i]);\n            w[i] = get<2>(v[i]);\n        \
    \    index[get<3>(v[i])] = i;\n        }\n        vector<unsigned> compressed(n);\n\
    \        cmp.resize(y.size());\n        cmp = y;\n        sort(cmp.begin(), cmp.end());\n\
    \        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<unsigned>\
    \ tmpc(n);\n        vector<T> tmp(n);\n        unsigned size_mx = y.size();\n\
    \        for (unsigned i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize + 1);\n        seg.resize(bitsize + 1);\n        zero.resize(bitsize,\
    \ 0);\n        int cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            b[i] = BitVector(n + 1);\n            seg[i] = DualSegmentTree<T,\
    \ F, mapping, composition, id>(w);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = w[j];\n                    cur++;\n          \
    \      }\n            }\n\n            b[i].build();\n            for (int j =\
    \ 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i -\
    \ 1))) {\n                    tmpc[cur] = compressed[j];\n                   \
    \ tmp[cur] = w[j];\n                    cur++;\n                }\n          \
    \  }\n            swap(tmpc, compressed);\n            swap(tmp, w);\n       \
    \ }\n        seg[bitsize] = DualSegmentTree<T, F, mapping, composition, id>(w);\n\
    \    }\n\n    T get_val(unsigned k) {\n        F f = id();\n        T val = arr[k];\n\
    \        unsigned cur = index[k];\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            f = composition(seg[i].getf(cur), f);\n            if (b[i].access(cur))\
    \ {\n                cur = zero[i] + b[i].rank(cur);\n            } else {\n \
    \               cur -= b[i].rank(cur);\n            }\n        }\n        f =\
    \ composition(seg[bitsize].getf(cur), f);\n        return mapping(f, val);\n \
    \   }\n\n    void rectangle_apply(T x_min, T x_max, T y_min, T y_max, F x) {\n\
    \        x_min = distance(px.begin(), lower_bound(px.begin(), px.end(), x_min));\n\
    \        x_max = distance(px.begin(), lower_bound(px.begin(), px.end(), x_max));\n\
    \        int D = compress(y_min);\n        int U = compress(y_max);\n        auto\
    \ dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {\n        \
    \    if (U <= A or B <= D) return;\n            if (D <= A and B <= U) {\n   \
    \             seg[d].apply(L, R, x);\n                return;\n            }\n\
    \            if (d == bitsize) {\n                if (D <= A and A < U) {\n  \
    \                  seg[bitsize].apply(L, R, x);\n                }\n         \
    \       return;\n            }\n            int C = (A + B) >> 1;\n          \
    \  int rank0_l = L - b[d].rank(L);\n            int rank0_r = R - b[d].rank(R);\n\
    \            int rank1_l = b[d].rank(L) + zero[d];\n            int rank1_r =\
    \ b[d].rank(R) + zero[d];\n            rec(rec, d + 1, rank0_l, rank0_r, A, C);\n\
    \            rec(rec, d + 1, rank1_l, rank1_r, C, B);\n        };\n        dfs(dfs,\
    \ 0, x_min, x_max, 0, 1 << bitsize);\n    }\n};\n"
  code: "template <class S, class F, auto mapping, auto composition, auto id>\nstruct\
    \ DualSegmentTree {\n   private:\n    int n;\n    vector<F> node;\n    F ID;\n\
    \    void Apply(int a, int b, F x, int k = 0, int l = 0, int r = -1) {\n     \
    \   if (r < 0) r = n;\n        eval(k, l, r);\n        if (r <= a or b <= l) return;\n\
    \        if (a <= l and r <= b) {\n            node[k] = composition(x, node[k]);\n\
    \            eval(k, l, r);\n            return;\n        }\n        Apply(a,\
    \ b, x, (k << 1) + 1, l, (l + r) >> 1);\n        Apply(a, b, x, (k << 1) + 2,\
    \ (l + r) >> 1, r);\n    }\n\n    void eval(int k, int l, int r) {\n        if\
    \ (r - l > 1) {\n            node[(k << 1) + 1] = composition(node[k], node[(k\
    \ << 1) + 1]);\n            node[(k << 1) + 2] = composition(node[k], node[(k\
    \ << 1) + 2]);\n            node[k] = ID;\n        }\n    }\n\n   public:\n  \
    \  DualSegmentTree() {}\n    DualSegmentTree(vector<S> &v) {\n        int sz =\
    \ v.size();\n        n = 1;\n        while (n < sz) n <<= 1;\n        node.resize((n\
    \ << 1) - 1, id());\n        ID = id();\n    }\n\n    void apply(int l, int r,\
    \ F x) {\n        Apply(l, r, x);\n    }\n\n    F getf(int p) {\n        p +=\
    \ (n - 1);\n        F f = node[p];\n        while (p > 0) {\n            p = (p\
    \ - 1) >> 1;\n            f = composition(node[p], f);\n        }\n        return\
    \ f;\n    }\n};\n\nstruct BitVector {\n    unsigned sz;\n    unsigned blocksize;\n\
    \    vector<unsigned> bit, sum;\n\n    BitVector() {}\n\n    BitVector(unsigned\
    \ siz) {\n        sz = siz;\n        blocksize = (sz + 31) >> 5;\n        bit.assign(blocksize,\
    \ 0U);\n        sum.assign(blocksize, 0U);\n    }\n\n    inline void set(int k)\
    \ { bit[k >> 5] |= 1U << (k & 31); }\n\n    inline void build() {\n        sum[0]\
    \ = 0U;\n        for (int i = 1; i < blocksize; i++) {\n            sum[i] = sum[i\
    \ - 1] + __builtin_popcount(bit[i - 1]);\n        }\n    }\n\n    inline bool\
    \ access(unsigned k) {\n        return (bool((bit[k >> 5] >> (k & 31)) & 1));\n\
    \    }\n\n    inline int rank(int k) {\n        return (sum[k >> 5] + __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1)));\n    }\n};\n\ntemplate <class T, class F,\
    \ auto mapping, auto composition, auto id>\nclass WaveletMatrix {\n   private:\n\
    \    unsigned n;\n    unsigned bitsize;\n    vector<BitVector> b;\n    vector<unsigned>\
    \ zero;\n    vector<T> cmp;\n    vector<T> px;\n    vector<int> index;\n    vector<T>\
    \ arr;\n    vector<DualSegmentTree<T, F, mapping, composition, id>> seg;\n\n \
    \   inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n    WaveletMatrix() {}\n\n    WaveletMatrix(vector<T> x, vector<T>\
    \ y, vector<T> w) {\n        n = x.size();\n        index.resize(n);\n       \
    \ px.resize(n);\n        arr = w;\n        vector<tuple<T, T, T, int>> v(n);\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] = {x[i], y[i], w[i],\
    \ i};\n        }\n        sort(v.begin(), v.end(), [](const tuple<T, T, T, int>\
    \ &l, const tuple<T, T, T, int> &r) {\n            return get<0>(l) < get<0>(r);\n\
    \        });\n        for (int i = 0; i < n; i++) {\n            px[i] = get<0>(v[i]);\n\
    \            y[i] = get<1>(v[i]);\n            w[i] = get<2>(v[i]);\n        \
    \    index[get<3>(v[i])] = i;\n        }\n        vector<unsigned> compressed(n);\n\
    \        cmp.resize(y.size());\n        cmp = y;\n        sort(cmp.begin(), cmp.end());\n\
    \        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<unsigned>\
    \ tmpc(n);\n        vector<T> tmp(n);\n        unsigned size_mx = y.size();\n\
    \        for (unsigned i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize + 1);\n        seg.resize(bitsize + 1);\n        zero.resize(bitsize,\
    \ 0);\n        int cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            b[i] = BitVector(n + 1);\n            seg[i] = DualSegmentTree<T,\
    \ F, mapping, composition, id>(w);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = w[j];\n                    cur++;\n          \
    \      }\n            }\n\n            b[i].build();\n            for (int j =\
    \ 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i -\
    \ 1))) {\n                    tmpc[cur] = compressed[j];\n                   \
    \ tmp[cur] = w[j];\n                    cur++;\n                }\n          \
    \  }\n            swap(tmpc, compressed);\n            swap(tmp, w);\n       \
    \ }\n        seg[bitsize] = DualSegmentTree<T, F, mapping, composition, id>(w);\n\
    \    }\n\n    T get_val(unsigned k) {\n        F f = id();\n        T val = arr[k];\n\
    \        unsigned cur = index[k];\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            f = composition(seg[i].getf(cur), f);\n            if (b[i].access(cur))\
    \ {\n                cur = zero[i] + b[i].rank(cur);\n            } else {\n \
    \               cur -= b[i].rank(cur);\n            }\n        }\n        f =\
    \ composition(seg[bitsize].getf(cur), f);\n        return mapping(f, val);\n \
    \   }\n\n    void rectangle_apply(T x_min, T x_max, T y_min, T y_max, F x) {\n\
    \        x_min = distance(px.begin(), lower_bound(px.begin(), px.end(), x_min));\n\
    \        x_max = distance(px.begin(), lower_bound(px.begin(), px.end(), x_max));\n\
    \        int D = compress(y_min);\n        int U = compress(y_max);\n        auto\
    \ dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {\n        \
    \    if (U <= A or B <= D) return;\n            if (D <= A and B <= U) {\n   \
    \             seg[d].apply(L, R, x);\n                return;\n            }\n\
    \            if (d == bitsize) {\n                if (D <= A and A < U) {\n  \
    \                  seg[bitsize].apply(L, R, x);\n                }\n         \
    \       return;\n            }\n            int C = (A + B) >> 1;\n          \
    \  int rank0_l = L - b[d].rank(L);\n            int rank0_r = R - b[d].rank(R);\n\
    \            int rank1_l = b[d].rank(L) + zero[d];\n            int rank1_r =\
    \ b[d].rank(R) + zero[d];\n            rec(rec, d + 1, rank0_l, rank0_r, A, C);\n\
    \            rec(rec, d + 1, rank1_l, rank1_r, C, B);\n        };\n        dfs(dfs,\
    \ 0, x_min, x_max, 0, 1 << bitsize);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
  requiredBy: []
  timestamp: '2025-01-25 20:21:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
layout: document
title: Wavelet Matrix (Dual Segment Tree)
---

## 概要

todo

## 計算量
todo