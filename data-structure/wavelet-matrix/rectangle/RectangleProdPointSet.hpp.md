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
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp\"\
    \nstruct BitVector {\n    unsigned sz;\n    unsigned blocksize;\n    vector<unsigned>\
    \ bit, sum;\n\n    BitVector() {}\n\n    BitVector(unsigned siz) {\n        sz\
    \ = siz;\n        blocksize = (sz + 31) >> 5;\n        bit.assign(blocksize, 0U);\n\
    \        sum.assign(blocksize, 0U);\n    }\n\n    inline void set(int k) { bit[k\
    \ >> 5] |= 1U << (k & 31); }\n\n    inline void build() {\n        sum[0] = 0U;\n\
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
    \        return res;\n    }\n};\n#line 2 \"data-structure/wavelet-matrix/rectangle/RectangleProdPointSet.hpp\"\
    \n\ntemplate <class S, auto op, auto e, class T>\nclass RectangleProdPointSet\
    \ {\n   private:\n    WaveletMatrix<S, op, e, T> wm;\n    vector<T> px;\n    vector<int>\
    \ ord;\n\n   public:\n    RectangleProdPointSet() {}\n    RectangleProdPointSet(vector<T>\
    \ x, vector<T> y, vector<S> w) {\n        int n = int(x.size());\n        ord.resize(n);\n\
    \        vector<tuple<T, T, S, int>> v(n);\n        for (int i = 0; i < n; i++)\
    \ v[i] = {x[i], y[i], w[i], i};\n        sort(v.begin(), v.end(), [](const auto\
    \ &a, const auto &b) {\n            return std::get<0>(a) < std::get<0>(b);\n\
    \        });\n        px.resize(n);\n        for (int i = 0; i < n; i++) {\n \
    \           px[i] = std::get<0>(v[i]);\n            y[i] = std::get<1>(v[i]);\n\
    \            w[i] = std::get<2>(v[i]);\n            ord[std::get<3>(v[i])] = i;\n\
    \        }\n        wm = WaveletMatrix<S, op, e, T>(y, w);\n    }\n\n    S rectangle_prod(T\
    \ xl, T xr, T yl, T yr) {\n        int l = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xl));\n        int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xr));\n        return wm.range_prod(l, r, yl, yr);\n    }\n\n    void\
    \ set(int p, S x) {\n        wm.set(ord[p], x);\n    }\n\n    S get(int p) {\n\
    \        return wm.get(ord[p]);\n    }\n};\n"
  code: "#include \"../WaveletMatrixSegtree.hpp\"\n\ntemplate <class S, auto op, auto\
    \ e, class T>\nclass RectangleProdPointSet {\n   private:\n    WaveletMatrix<S,\
    \ op, e, T> wm;\n    vector<T> px;\n    vector<int> ord;\n\n   public:\n    RectangleProdPointSet()\
    \ {}\n    RectangleProdPointSet(vector<T> x, vector<T> y, vector<S> w) {\n   \
    \     int n = int(x.size());\n        ord.resize(n);\n        vector<tuple<T,\
    \ T, S, int>> v(n);\n        for (int i = 0; i < n; i++) v[i] = {x[i], y[i], w[i],\
    \ i};\n        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {\n \
    \           return std::get<0>(a) < std::get<0>(b);\n        });\n        px.resize(n);\n\
    \        for (int i = 0; i < n; i++) {\n            px[i] = std::get<0>(v[i]);\n\
    \            y[i] = std::get<1>(v[i]);\n            w[i] = std::get<2>(v[i]);\n\
    \            ord[std::get<3>(v[i])] = i;\n        }\n        wm = WaveletMatrix<S,\
    \ op, e, T>(y, w);\n    }\n\n    S rectangle_prod(T xl, T xr, T yl, T yr) {\n\
    \        int l = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));\n\
    \        int r = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));\n\
    \        return wm.range_prod(l, r, yl, yr);\n    }\n\n    void set(int p, S x)\
    \ {\n        wm.set(ord[p], x);\n    }\n\n    S get(int p) {\n        return wm.get(ord[p]);\n\
    \    }\n};"
  dependsOn:
  - data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/rectangle/RectangleProdPointSet.hpp
  requiredBy: []
  timestamp: '2025-09-23 21:04:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/rectangle/RectangleProdPointSet.hpp
layout: document
title: Rectangle Prod Point Set
---

## 概要

[ウェーブレット行列 (+ セグメント木)](../WaveletMatrixSegtree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形総積取得 / 一点更新が可能。


## コンストラクタ

```cpp
WaveletMatrix<S, op, e, T> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 番目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。モノイドの代数構造の性質を満たす必要がある。
- op: 二項演算 `S op(S a, S b)`
- e: 単位元 `S e()`
- x, y, wの数列のサイズは等しい

ドキュメントの計算量は、オラクルであるop, eが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。


### 計算量
- $O(n\log{n})$

## rectangle_prod

```cpp
S wm.rectangle_prod(T lx, T rx, T ly, T ry)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重みの総積を返す。

### 制約

- `std::numeric_limits<T>::min()` $\leq lx \leq rx \leq$ `std::numeric_limits<T>::max()`
- `std::numeric_limits<T>::min()` $\leq ly \leq ry \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log^2{n})$

## set

```cpp
void wm.set(int p, S x)
```

`p` 番目の点の重みを `x` に変更する。

### 制約

- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$


## get

```cpp
S wm.get(int p)
```

`p` 番目の点の重みを返す。

### 制約

- $0 \leq p \lt n$ 


### 計算量
- $O(1)$