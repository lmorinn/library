---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/query/RangeMex.hpp
    title: Range Mex Query
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/rectangle/RectangleProdPointSet.hpp
    title: Rectangle Prod Point Set
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
    \        return res;\n    }\n};\n"
  code: "struct BitVector {\n    unsigned sz;\n    unsigned blocksize;\n    vector<unsigned>\
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
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/query/RangeMex.hpp
  - data-structure/wavelet-matrix/rectangle/RectangleProdPointSet.hpp
  timestamp: '2025-05-12 02:45:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
layout: document
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (+ \u30BB\u30B0\u30E1\
  \u30F3\u30C8\u6728)"
---

## 概要

Wavelet Matrixとセグメント木を同時に持つことで、数列に対して高度な1点更新・区間演算のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<T, S> wm(vector<T> v)
(2) WaveletMatrix<T, S> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルとセグメント木を構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` からセグメント木を構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。モノイドの代数構造の性質を満たす必要がある。
- op: 二項演算 `S op(S a, S b)`
- e: 単位元 `S e()`
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい

ドキュメントの計算量は、オラクルであるop, eが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。

### 計算量
- $O(n\log{n})$



## range_prod

```cpp
S wm.range_prod(int l, int r, T mink, T maxk)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たす $i$ に対して、セグメント木の総積を計算して返す。条件を満たすインデックスがひとつも存在しないときは `e()` を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`であり、Range Max Queryならば、 

```cpp
S wm.range_prod(1, 5, 2, 5) // 返り値は4
S wm.range_prod(0, 4, 1, 4) // 返り値は3
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たす $i$ に対して、セグメント木の総積を計算して返す。条件を満たすインデックスがひとつも存在しないときは `e()` を返す。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` であり、Range Max Query ならば、 

```cpp
S wm.range_prod(1, 5, 2, 6) // 返り値は2
S wm.range_prod(2, 6, 1, 5) // 返り値は8
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- `std::numeric_limits<T>::min()` $\leq mink \leq maxk \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log^2{n})$


## get

```cpp
S wm.get(int p)
```

(1) (2)  セグメント木の `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(1)$


## set

```cpp
S wm.set(int p, S x)
```

(1) (2)  セグメント木の `p` 番目に `x` を代入する。`v[p]` の値は変更しない。


### 制約
- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$




