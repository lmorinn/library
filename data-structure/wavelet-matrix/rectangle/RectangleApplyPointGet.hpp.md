---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (+ \u53CC\u5BFE\
      \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
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
    \ C, B);\n    };\n    dfs(dfs, 0, l, r, 0, 1 << bitsize);\n  }\n};\n#line 2 \"\
    data-structure/wavelet-matrix/rectangle/RectangleApplyPointGet.hpp\"\n\ntemplate\
    \ <class S, class F, auto mapping, auto composition, auto id, class T>\nclass\
    \ RectangleApplyPointGet {\n private:\n  WaveletMatrix<S, F, mapping, composition,\
    \ id, T> wm;\n  vector<T> px;\n  vector<int> ord;\n\n public:\n  RectangleApplyPointGet()\
    \ {}\n  RectangleApplyPointGet(vector<T> x, vector<T> y, vector<S> w) {\n    int\
    \ n = int(x.size());\n    ord.resize(n);\n    vector<tuple<T, T, S, int>> v(n);\n\
    \    for (int i = 0; i < n; i++) v[i] = {x[i], y[i], w[i], i};\n    sort(v.begin(),\
    \ v.end(), [](const auto &a, const auto &b) {\n      return get<0>(a) < get<0>(b);\n\
    \    });\n    px.resize(n);\n    for (int i = 0; i < n; i++) {\n      px[i] =\
    \ get<0>(v[i]);\n      y[i] = get<1>(v[i]);\n      w[i] = get<2>(v[i]);\n    \
    \  ord[i] = get<3>(v[i]);\n    }\n    wm = WaveletMatrix<S, F, mapping, composition,\
    \ id, T>(y, w);\n  }\n\n  void rectangle_apply(T xl, T xr, T yl, T yr, F x) {\n\
    \    int l = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));\n  \
    \  int r = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));\n    wm.range_apply(l,\
    \ r, yl, yr, x);\n  }\n\n  S get(int p) {\n    return wm.get(ord[p]);\n  }\n};\n"
  code: "#include \"../WaveletMatrixDualSegtree.hpp\"\n\ntemplate <class S, class\
    \ F, auto mapping, auto composition, auto id, class T>\nclass RectangleApplyPointGet\
    \ {\n private:\n  WaveletMatrix<S, F, mapping, composition, id, T> wm;\n  vector<T>\
    \ px;\n  vector<int> ord;\n\n public:\n  RectangleApplyPointGet() {}\n  RectangleApplyPointGet(vector<T>\
    \ x, vector<T> y, vector<S> w) {\n    int n = int(x.size());\n    ord.resize(n);\n\
    \    vector<tuple<T, T, S, int>> v(n);\n    for (int i = 0; i < n; i++) v[i] =\
    \ {x[i], y[i], w[i], i};\n    sort(v.begin(), v.end(), [](const auto &a, const\
    \ auto &b) {\n      return get<0>(a) < get<0>(b);\n    });\n    px.resize(n);\n\
    \    for (int i = 0; i < n; i++) {\n      px[i] = get<0>(v[i]);\n      y[i] =\
    \ get<1>(v[i]);\n      w[i] = get<2>(v[i]);\n      ord[i] = get<3>(v[i]);\n  \
    \  }\n    wm = WaveletMatrix<S, F, mapping, composition, id, T>(y, w);\n  }\n\n\
    \  void rectangle_apply(T xl, T xr, T yl, T yr, F x) {\n    int l = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xl));\n    int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), xr));\n    wm.range_apply(l, r, yl, yr, x);\n  }\n\n  S get(int p)\
    \ {\n    return wm.get(ord[p]);\n  }\n};"
  dependsOn:
  - data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/rectangle/RectangleApplyPointGet.hpp
  requiredBy: []
  timestamp: '2025-05-12 15:13:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/rectangle/RectangleApplyPointGet.hpp
layout: document
title: Rectangle Apply Point Get
---

## 概要

[ウェーブレット行列 (+ 双対セグメント木)](../WaveletMatrixDualSegtree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形作用 / 一点取得が可能。 

## コンストラクタ

```cpp
WaveletMatrix<S, F, mapping, composition, id, T> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 番目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。
- テンプレート引数 F: 写像の型。
- mapping: $f(x)$ を返す関数。 `S mapping(F f, S x)`
- composition: $f \circ g$ を返す関数。 `F composition(F f, F g)`
- id: $id$ を返す関数。 `F id()`
- 作用は可換である必要がある。
- x, y, wの数列のサイズは等しい


ドキュメントの計算量は、オラクルであるmapping, composition, idが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。


### 計算量
- $O(n\log{n})$

## rectangle_apply

```cpp
void wm.rectangle_apply(T lx, T rx, T ly, T ry, F x)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重み `w[i]` について、 `w[i] = f(w[i])` と更新する。

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