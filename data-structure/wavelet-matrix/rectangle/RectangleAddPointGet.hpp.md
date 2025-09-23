---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
    title: Dual Binary Indexed Tree
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (+ \u53CC\u5BFE\
      BIT)"
  _extendedRequiredBy: []
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
    \ l, r, 0, 1 << bitsize);\n  }\n};\n#line 2 \"data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp\"\
    \n\ntemplate <class S, class T>\nclass RectangleAddPointGet {\n private:\n  WaveletMatrix<S,\
    \ T> wm;\n  vector<T> px;\n  vector<int> ord;\n\n public:\n  RectangleAddPointGet()\
    \ {}\n  RectangleAddPointGet(vector<T> x, vector<T> y, vector<S> w) {\n    int\
    \ n = int(x.size());\n    ord.resize(n);\n    vector<tuple<T, T, S, int>> v(n);\n\
    \    for (int i = 0; i < n; i++) v[i] = {x[i], y[i], w[i], i};\n    sort(v.begin(),\
    \ v.end(), [](const auto &a, const auto &b) {\n      return get<0>(a) < get<0>(b);\n\
    \    });\n    px.resize(n);\n    for (int i = 0; i < n; i++) {\n      px[i] =\
    \ get<0>(v[i]);\n      y[i] = get<1>(v[i]);\n      w[i] = get<2>(v[i]);\n    \
    \  ord[i] = get<3>(v[i]);\n    }\n    wm = WaveletMatrix<S, T>(y, w);\n  }\n\n\
    \  void rectangle_add(T xl, T xr, T yl, T yr, S x) {\n    int l = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xl));\n    int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xr));\n    wm.range_add(l, r, yl, yr, x);\n  }\n\n  S get(int p) {\n\
    \    return wm.get(ord[p]);\n  }\n};\n"
  code: "#include \"../WaveletMatrixDualBinaryIndexedTree.hpp\"\n\ntemplate <class\
    \ S, class T>\nclass RectangleAddPointGet {\n private:\n  WaveletMatrix<S, T>\
    \ wm;\n  vector<T> px;\n  vector<int> ord;\n\n public:\n  RectangleAddPointGet()\
    \ {}\n  RectangleAddPointGet(vector<T> x, vector<T> y, vector<S> w) {\n    int\
    \ n = int(x.size());\n    ord.resize(n);\n    vector<tuple<T, T, S, int>> v(n);\n\
    \    for (int i = 0; i < n; i++) v[i] = {x[i], y[i], w[i], i};\n    sort(v.begin(),\
    \ v.end(), [](const auto &a, const auto &b) {\n      return get<0>(a) < get<0>(b);\n\
    \    });\n    px.resize(n);\n    for (int i = 0; i < n; i++) {\n      px[i] =\
    \ get<0>(v[i]);\n      y[i] = get<1>(v[i]);\n      w[i] = get<2>(v[i]);\n    \
    \  ord[i] = get<3>(v[i]);\n    }\n    wm = WaveletMatrix<S, T>(y, w);\n  }\n\n\
    \  void rectangle_add(T xl, T xr, T yl, T yr, S x) {\n    int l = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xl));\n    int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xr));\n    wm.range_add(l, r, yl, yr, x);\n  }\n\n  S get(int p) {\n\
    \    return wm.get(ord[p]);\n  }\n};"
  dependsOn:
  - data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
  - data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
  requiredBy: []
  timestamp: '2025-05-12 15:13:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
layout: document
title: Rectangle Add Point Get
---

## 概要

[ウェーブレット行列 (+ 双対BIT)](../WaveletMatrixDualBinaryIndexedTree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形加算 / 一点取得が可能。 


## コンストラクタ

```cpp
WaveletMatrix<S, T> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 番目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。
- x, y, wの数列のサイズは等しい。


### 計算量
- $O(n\log^2{n})$

## rectangle_add

```cpp
void wm.rectangle_add(T lx, T rx, T ly, T ry, S x)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重みに `x` を加算する。

### 制約

- `std::numeric_limits<T>::min()` $\leq lx \leq rx \leq$ `std::numeric_limits<T>::max()`
- `std::numeric_limits<T>::min()` $\leq ly \leq ry \leq$ `std::numeric_limits<T>::max()`


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
- $O(\log^2{n})$


