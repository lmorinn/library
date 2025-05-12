---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
    title: Dual Binary Indexed Tree
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
    title: Rectangle Add Point Get
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp\"\
    \ntemplate <class T>\nstruct RangeAddPointGet {\n   private:\n    fenwick_tree<T>\
    \ ft;\n\n   public:\n    RangeAddPointGet() {}\n    RangeAddPointGet(int siz)\
    \ : ft(siz + 1) {}\n\n    void range_add(int l, int r, T x) {\n        ft.add(l,\
    \ x);\n        ft.add(r, -x);\n    }\n\n    void add(int p, T x) {\n        ft.add(p,\
    \ x);\n        ft.add(p + 1, -x);\n    }\n\n    T point_get(int p) {\n       \
    \ return ft.sum(0, p + 1);\n    }\n};\n#line 2 \"data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp\"\
    \nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned>\
    \ bit, sum;\n\n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n\
    \    blocksize = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class S, class T>\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned\
    \ bitsize;\n  vector<BitVector> b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n\
    \  vector<S> arr;\n  vector<RangeAddPointGet<S>> fen;\n\n  inline unsigned compress(const\
    \ T &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n \
    \ }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<T> v) {\n    n = v.size();\n    arr = v;\n    cmp\
    \ = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()),\
    \ cmp.end());\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n    b.resize(bitsize\
    \ + 1);\n    fen.resize(bitsize + 1, RangeAddPointGet<S>(n));\n    zero.resize(bitsize,\
    \ 0);\n    int cur = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      b[i]\
    \ = BitVector(n + 1);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          cur++;\n        }\n      }\n      b[i].build();\n      for (int j =\
    \ 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      swap(tmpc, compressed);\n    }\n    b[bitsize] = BitVector(n + 1);\n  }\n\
    \n  WaveletMatrix(vector<T> v, vector<S> w) {\n    n = v.size();\n    arr = w;\n\
    \    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n\
    \    for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    fen.resize(bitsize + 1, RangeAddPointGet<S>(n));\n    b.resize(bitsize +\
    \ 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n    for (unsigned i = 0;\
    \ i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n      cur = 0;\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          b[i].set(j);\n        } else {\n          zero[i]++;\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      b[i].build();\n      for (int j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          tmpc[cur] = compressed[j];\n     \
    \     cur++;\n        }\n      }\n      swap(tmpc, compressed);\n    }\n    b[bitsize]\
    \ = BitVector(n + 1);\n  }\n\n  S get(unsigned k) {\n    S val = arr[k];\n   \
    \ unsigned cur = k;\n    for (unsigned i = 0; i < bitsize; i++) {\n      val +=\
    \ fen[i].point_get(cur);\n      if (b[i].access(cur)) {\n        cur = zero[i]\
    \ + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n      }\n\
    \    }\n    val += fen[bitsize].point_get(cur);\n    return val;\n  }\n\n  void\
    \ range_add(int l, int r, T mink, T maxk, S x) {\n    int D = compress(mink);\n\
    \    int U = compress(maxk);\n    auto dfs = [&](auto &rec, int d, int L, int\
    \ R, int A, int B) -> void {\n      if (U <= A or B <= D) return;\n      if (D\
    \ <= A and B <= U) {\n        fen[d].range_add(L, R, x);\n        return;\n  \
    \    }\n      if (d == bitsize) {\n        if (D <= A and A < U) {\n         \
    \ fen[bitsize].range_add(L, R, x);\n        }\n        return;\n      }\n    \
    \  int C = (A + B) >> 1;\n      int rank0_l = L - b[d].rank(L);\n      int rank0_r\
    \ = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n      int\
    \ rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r, A,\
    \ C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs, 0,\
    \ l, r, 0, 1 << bitsize);\n  }\n};\n"
  code: "#include \"../binary-indexed-tree/DualBinaryIndexedTree.hpp\"\nstruct BitVector\
    \ {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned> bit, sum;\n\n \
    \ BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class S, class T>\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned\
    \ bitsize;\n  vector<BitVector> b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n\
    \  vector<S> arr;\n  vector<RangeAddPointGet<S>> fen;\n\n  inline unsigned compress(const\
    \ T &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n \
    \ }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<T> v) {\n    n = v.size();\n    arr = v;\n    cmp\
    \ = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()),\
    \ cmp.end());\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n    b.resize(bitsize\
    \ + 1);\n    fen.resize(bitsize + 1, RangeAddPointGet<S>(n));\n    zero.resize(bitsize,\
    \ 0);\n    int cur = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      b[i]\
    \ = BitVector(n + 1);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          cur++;\n        }\n      }\n      b[i].build();\n      for (int j =\
    \ 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      swap(tmpc, compressed);\n    }\n    b[bitsize] = BitVector(n + 1);\n  }\n\
    \n  WaveletMatrix(vector<T> v, vector<S> w) {\n    n = v.size();\n    arr = w;\n\
    \    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n\
    \    for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    fen.resize(bitsize + 1, RangeAddPointGet<S>(n));\n    b.resize(bitsize +\
    \ 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n    for (unsigned i = 0;\
    \ i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n      cur = 0;\n      for\
    \ (unsigned j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          b[i].set(j);\n        } else {\n          zero[i]++;\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      b[i].build();\n      for (int j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          tmpc[cur] = compressed[j];\n     \
    \     cur++;\n        }\n      }\n      swap(tmpc, compressed);\n    }\n    b[bitsize]\
    \ = BitVector(n + 1);\n  }\n\n  S get(unsigned k) {\n    S val = arr[k];\n   \
    \ unsigned cur = k;\n    for (unsigned i = 0; i < bitsize; i++) {\n      val +=\
    \ fen[i].point_get(cur);\n      if (b[i].access(cur)) {\n        cur = zero[i]\
    \ + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n      }\n\
    \    }\n    val += fen[bitsize].point_get(cur);\n    return val;\n  }\n\n  void\
    \ range_add(int l, int r, T mink, T maxk, S x) {\n    int D = compress(mink);\n\
    \    int U = compress(maxk);\n    auto dfs = [&](auto &rec, int d, int L, int\
    \ R, int A, int B) -> void {\n      if (U <= A or B <= D) return;\n      if (D\
    \ <= A and B <= U) {\n        fen[d].range_add(L, R, x);\n        return;\n  \
    \    }\n      if (d == bitsize) {\n        if (D <= A and A < U) {\n         \
    \ fen[bitsize].range_add(L, R, x);\n        }\n        return;\n      }\n    \
    \  int C = (A + B) >> 1;\n      int rank0_l = L - b[d].rank(L);\n      int rank0_r\
    \ = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n      int\
    \ rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r, A,\
    \ C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs, 0,\
    \ l, r, 0, 1 << bitsize);\n  }\n};"
  dependsOn:
  - data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
  timestamp: '2025-05-12 13:53:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
layout: document
title: Wavelet Matrix (Dual Binary Indexed Tree)
---

## 概要

Wavelet Matrixと双対BITを同時に持つことで、数列に対して高度な加算・一点取得のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<S, T> wm(vector<T> v)
(2) WaveletMatrix<S, T> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルと双対BITを構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` から双対BITを構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい

### 計算量
- $O(n\log{n})$



## range_add

```cpp
void wm.range_add(int l, int r, T mink, T maxk, S x)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対BITで表される数列の $i$ 番目のインデックスの要素に `x` を加算する。 `v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` ならば、 


```cpp
// 初期状態: {3, 1, 4, 1, 5, 9}

void wm.range_add(1, 5, 2, 5, 10) // {3, 1, 14, 1, 5, 9}
void wm.range_add(0, 4, 1, 4, 10) // {13, 11, 14, 11, 5, 9}
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対BITで表される数列の $i$ 番目のインデックスの要素に `x` を加算する。`v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` ならば、 

```cpp
// 初期状態: {2, 7, 1, 8, 2, 8}
void wm.range_add(1, 5, 2, 6, 10) // {2, 7, 11, 8, 12, 8}
void wm.range_add(2, 6, 1, 5, 10) // {2, 7, 21, 18, 12, 8}
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

(1) (2)  双対BITで表される数列の `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(\log^2{n})$




