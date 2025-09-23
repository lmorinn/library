---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/rectangle/RectangleApplyPointGet.hpp
    title: Rectangle Apply Point Get
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp\"\
    \ntemplate <class S, class F, auto mapping, auto composition, auto id>\nstruct\
    \ DualSegmentTree {\n private:\n  int n;\n  vector<F> node;\n  F ID;\n  void Apply(int\
    \ a, int b, F x, int k = 0, int l = 0, int r = -1) {\n    if (r < 0) r = n;\n\
    \    eval(k, l, r);\n    if (r <= a or b <= l) return;\n    if (a <= l and r <=\
    \ b) {\n      node[k] = composition(x, node[k]);\n      eval(k, l, r);\n     \
    \ return;\n    }\n    Apply(a, b, x, (k << 1) + 1, l, (l + r) >> 1);\n    Apply(a,\
    \ b, x, (k << 1) + 2, (l + r) >> 1, r);\n  }\n\n  void eval(int k, int l, int\
    \ r) {\n    if (r - l > 1) {\n      node[(k << 1) + 1] = composition(node[k],\
    \ node[(k << 1) + 1]);\n      node[(k << 1) + 2] = composition(node[k], node[(k\
    \ << 1) + 2]);\n      node[k] = ID;\n    }\n  }\n\n public:\n  DualSegmentTree()\
    \ {}\n  DualSegmentTree(int sz) {\n    n = 1;\n    while (n < sz) n <<= 1;\n \
    \   node.resize((n << 1) - 1, id());\n    ID = id();\n  }\n\n  void apply(int\
    \ l, int r, F x) {\n    Apply(l, r, x);\n  }\n\n  F getf(int p) {\n    p += (n\
    \ - 1);\n    F f = node[p];\n    while (p > 0) {\n      p = (p - 1) >> 1;\n  \
    \    f = composition(node[p], f);\n    }\n    return f;\n  }\n};\n\nstruct BitVector\
    \ {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned> bit, sum;\n\n \
    \ BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class S, class F, auto mapping, auto composition, auto id, class T>\nclass\
    \ WaveletMatrix {\n private:\n  unsigned n;\n  unsigned bitsize;\n  vector<BitVector>\
    \ b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n  vector<S> arr;\n  vector<DualSegmentTree<S,\
    \ F, mapping, composition, id>> seg;\n\n  inline unsigned compress(const T &x)\
    \ {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n  }\n\n\
    \ public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<T> v) {\n    n = v.size();\n    arr = v;\n    cmp\
    \ = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()),\
    \ cmp.end());\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n    b.resize(bitsize\
    \ + 1);\n    seg.resize(bitsize + 1, DualSegmentTree<S, F, mapping, composition,\
    \ id>(n));\n    zero.resize(bitsize, 0);\n    int cur = 0;\n    for (unsigned\
    \ i = 0; i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n      cur = 0;\n\
    \      for (unsigned j = 0; j < n; j++) {\n        if (compressed[j] & (1U <<\
    \ (bitsize - i - 1))) {\n          b[i].set(j);\n        } else {\n          zero[i]++;\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      b[i].build();\n      for (int j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          tmpc[cur] = compressed[j];\n     \
    \     cur++;\n        }\n      }\n      swap(tmpc, compressed);\n    }\n    b[bitsize]\
    \ = BitVector(n + 1);\n  }\n\n  WaveletMatrix(vector<T> v, vector<S> w) {\n  \
    \  n = v.size();\n    arr = w;\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n\
    \    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n    vector<T> tmpc(n);\n\
    \    vector<T> compressed(n);\n    for (unsigned i = 0; i < n; i++) {\n      compressed[i]\
    \ = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n\
    \    bitsize = bit_width(cmp.size());\n    seg.resize(bitsize + 1, DualSegmentTree<S,\
    \ F, mapping, composition, id>(n));\n    b.resize(bitsize + 1);\n    zero.resize(bitsize,\
    \ 0);\n    int cur = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      b[i]\
    \ = BitVector(n + 1);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          cur++;\n        }\n      }\n      b[i].build();\n      for (int j =\
    \ 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      swap(tmpc, compressed);\n    }\n    b[bitsize] = BitVector(n + 1);\n  }\n\
    \n  S get(unsigned k) {\n    F f = id();\n    S val = arr[k];\n    unsigned cur\
    \ = k;\n    for (unsigned i = 0; i < bitsize; i++) {\n      f = composition(seg[i].getf(cur),\
    \ f);\n      if (b[i].access(cur)) {\n        cur = zero[i] + b[i].rank(cur);\n\
    \      } else {\n        cur -= b[i].rank(cur);\n      }\n    }\n    f = composition(seg[bitsize].getf(cur),\
    \ f);\n    return mapping(f, val);\n  }\n\n  void range_apply(int l, int r, T\
    \ mink, T maxk, F x) {\n    int D = compress(mink);\n    int U = compress(maxk);\n\
    \    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {\n\
    \      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n       \
    \ seg[d].apply(L, R, x);\n        return;\n      }\n      if (d == bitsize) {\n\
    \        if (D <= A and A < U) {\n          seg[bitsize].apply(L, R, x);\n   \
    \     }\n        return;\n      }\n      int C = (A + B) >> 1;\n      int rank0_l\
    \ = L - b[d].rank(L);\n      int rank0_r = R - b[d].rank(R);\n      int rank1_l\
    \ = b[d].rank(L) + zero[d];\n      int rank1_r = b[d].rank(R) + zero[d];\n   \
    \   rec(rec, d + 1, rank0_l, rank0_r, A, C);\n      rec(rec, d + 1, rank1_l, rank1_r,\
    \ C, B);\n    };\n    dfs(dfs, 0, l, r, 0, 1 << bitsize);\n  }\n};\n"
  code: "template <class S, class F, auto mapping, auto composition, auto id>\nstruct\
    \ DualSegmentTree {\n private:\n  int n;\n  vector<F> node;\n  F ID;\n  void Apply(int\
    \ a, int b, F x, int k = 0, int l = 0, int r = -1) {\n    if (r < 0) r = n;\n\
    \    eval(k, l, r);\n    if (r <= a or b <= l) return;\n    if (a <= l and r <=\
    \ b) {\n      node[k] = composition(x, node[k]);\n      eval(k, l, r);\n     \
    \ return;\n    }\n    Apply(a, b, x, (k << 1) + 1, l, (l + r) >> 1);\n    Apply(a,\
    \ b, x, (k << 1) + 2, (l + r) >> 1, r);\n  }\n\n  void eval(int k, int l, int\
    \ r) {\n    if (r - l > 1) {\n      node[(k << 1) + 1] = composition(node[k],\
    \ node[(k << 1) + 1]);\n      node[(k << 1) + 2] = composition(node[k], node[(k\
    \ << 1) + 2]);\n      node[k] = ID;\n    }\n  }\n\n public:\n  DualSegmentTree()\
    \ {}\n  DualSegmentTree(int sz) {\n    n = 1;\n    while (n < sz) n <<= 1;\n \
    \   node.resize((n << 1) - 1, id());\n    ID = id();\n  }\n\n  void apply(int\
    \ l, int r, F x) {\n    Apply(l, r, x);\n  }\n\n  F getf(int p) {\n    p += (n\
    \ - 1);\n    F f = node[p];\n    while (p > 0) {\n      p = (p - 1) >> 1;\n  \
    \    f = composition(node[p], f);\n    }\n    return f;\n  }\n};\n\nstruct BitVector\
    \ {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned> bit, sum;\n\n \
    \ BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class S, class F, auto mapping, auto composition, auto id, class T>\nclass\
    \ WaveletMatrix {\n private:\n  unsigned n;\n  unsigned bitsize;\n  vector<BitVector>\
    \ b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n  vector<S> arr;\n  vector<DualSegmentTree<S,\
    \ F, mapping, composition, id>> seg;\n\n  inline unsigned compress(const T &x)\
    \ {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n  }\n\n\
    \ public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<T> v) {\n    n = v.size();\n    arr = v;\n    cmp\
    \ = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()),\
    \ cmp.end());\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n    b.resize(bitsize\
    \ + 1);\n    seg.resize(bitsize + 1, DualSegmentTree<S, F, mapping, composition,\
    \ id>(n));\n    zero.resize(bitsize, 0);\n    int cur = 0;\n    for (unsigned\
    \ i = 0; i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n      cur = 0;\n\
    \      for (unsigned j = 0; j < n; j++) {\n        if (compressed[j] & (1U <<\
    \ (bitsize - i - 1))) {\n          b[i].set(j);\n        } else {\n          zero[i]++;\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      b[i].build();\n      for (int j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          tmpc[cur] = compressed[j];\n     \
    \     cur++;\n        }\n      }\n      swap(tmpc, compressed);\n    }\n    b[bitsize]\
    \ = BitVector(n + 1);\n  }\n\n  WaveletMatrix(vector<T> v, vector<S> w) {\n  \
    \  n = v.size();\n    arr = w;\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n\
    \    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n    vector<T> tmpc(n);\n\
    \    vector<T> compressed(n);\n    for (unsigned i = 0; i < n; i++) {\n      compressed[i]\
    \ = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n\
    \    bitsize = bit_width(cmp.size());\n    seg.resize(bitsize + 1, DualSegmentTree<S,\
    \ F, mapping, composition, id>(n));\n    b.resize(bitsize + 1);\n    zero.resize(bitsize,\
    \ 0);\n    int cur = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      b[i]\
    \ = BitVector(n + 1);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          cur++;\n        }\n      }\n      b[i].build();\n      for (int j =\
    \ 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n\
    \          tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n\
    \      swap(tmpc, compressed);\n    }\n    b[bitsize] = BitVector(n + 1);\n  }\n\
    \n  S get(unsigned k) {\n    F f = id();\n    S val = arr[k];\n    unsigned cur\
    \ = k;\n    for (unsigned i = 0; i < bitsize; i++) {\n      f = composition(seg[i].getf(cur),\
    \ f);\n      if (b[i].access(cur)) {\n        cur = zero[i] + b[i].rank(cur);\n\
    \      } else {\n        cur -= b[i].rank(cur);\n      }\n    }\n    f = composition(seg[bitsize].getf(cur),\
    \ f);\n    return mapping(f, val);\n  }\n\n  void range_apply(int l, int r, T\
    \ mink, T maxk, F x) {\n    int D = compress(mink);\n    int U = compress(maxk);\n\
    \    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {\n\
    \      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n       \
    \ seg[d].apply(L, R, x);\n        return;\n      }\n      if (d == bitsize) {\n\
    \        if (D <= A and A < U) {\n          seg[bitsize].apply(L, R, x);\n   \
    \     }\n        return;\n      }\n      int C = (A + B) >> 1;\n      int rank0_l\
    \ = L - b[d].rank(L);\n      int rank0_r = R - b[d].rank(R);\n      int rank1_l\
    \ = b[d].rank(L) + zero[d];\n      int rank1_r = b[d].rank(R) + zero[d];\n   \
    \   rec(rec, d + 1, rank0_l, rank0_r, A, C);\n      rec(rec, d + 1, rank1_l, rank1_r,\
    \ C, B);\n    };\n    dfs(dfs, 0, l, r, 0, 1 << bitsize);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/rectangle/RectangleApplyPointGet.hpp
  timestamp: '2025-05-12 13:19:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
layout: document
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (+ \u53CC\u5BFE\u30BB\
  \u30B0\u30E1\u30F3\u30C8\u6728)"
---

## 概要

Wavelet Matrixと双対セグメント木を同時に持つことで、数列に対して高度な作用・一点取得のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<S, F, mapping, composition, id, T> wm(vector<T> v)
(2) WaveletMatrix<S, F, mapping, composition, id, T> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルと双対セグメント木を構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` から双対セグメント木を構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。
- テンプレート引数 F: 写像の型。
- mapping: $f(x)$ を返す関数 `S mapping(F f, S x)`
- composition: $f \circ g$ を返す関数 `F composition(F f, F g)`
- id: $id$ を返す関数 `F id()`
- 作用は可換である必要がある
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい


ドキュメントの計算量は、オラクルであるmapping, composition, idが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。

### 計算量
- $O(n\log{n})$



## range_apply

```cpp
void wm.range_apply(int l, int r, T mink, T maxk, F x)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対セグメント木のi番目のインデックスの要素にxを作用させる。 `v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` であり、 

```cpp
using S = int;
using F = int;
using T = int;

S mapping(F f, S x){
    return f*x;
}

F composition(F f, F g){
    return f*g;
}

F id(){
    return 1;
}
```
と定義されているならば、

```cpp
// 初期状態: {3, 1, 4, 1, 5, 9}

void wm.range_apply(1, 5, 2, 5, 10) // {3, 1, 40, 1, 5, 9}
void wm.range_apply(0, 4, 1, 4, 10) // {30, 10, 40, 10, 5, 9}
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対セグメント木のi番目のインデックスの要素にxを作用させる。`v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` であり、 

```cpp
using S = int;
using F = int;
using T = int;

S mapping(F f, S x){
    return f*x;
}

F composition(F f, F g){
    return f*g;
}

F id(){
    return 1;
}
```
と定義されているならば、

```cpp
// 初期状態: {2, 7, 1, 8, 2, 8}
void wm.range_apply(1, 5, 2, 6, 10) // {2, 7, 10, 8, 20, 8}
void wm.range_apply(2, 6, 1, 5, 10) // {2, 7, 100, 80, 20, 8}
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

(1) (2)  双対セグメント木の `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(\log^2{n})$




