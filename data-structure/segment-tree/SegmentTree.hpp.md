---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/LongestIncreasingSubsequence.hpp
    title: Longest Increasing Subsequence
  - icon: ':heavy_check_mark:'
    path: graph/tree/EulerTour.hpp
    title: Euler Tour
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
    title: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/dp/DPL_1_D.test.cpp
    title: verify/AizuOnlineJudge/dp/DPL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
    title: verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
    title: verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-tree/SegmentTree.hpp\"\ntemplate\
    \ <class S, auto op, auto e>\nstruct segtree {\n private:\n  unsigned int seg_bit_ceil(unsigned\
    \ int n) {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n\
    \    return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  segtree()\
    \ : segtree(0) {}\n  explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    size\
    \ = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n  \
    \    update(i);\n    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p &&\
    \ p < _n);\n    p += size;\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) const {\n    assert(0 <= p && p < _n);\n\
    \    return d[p + size];\n  }\n\n  S prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= _n);\n    S sml = e(), smr = e();\n    l += size;\n \
    \   r += size;\n\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n\
    \  template <bool (*f)(S)>\n  int max_right(int l) const {\n    return max_right(l,\
    \ [](S x) { return f(x); });\n  }\n  template <class F>\n  int max_right(int l,\
    \ F f) const {\n    assert(0 <= l && l <= _n);\n    assert(f(e()));\n    if (l\
    \ == _n) return _n;\n    l += size;\n    S sm = e();\n    do {\n      while (l\
    \ % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < size)\
    \ {\n          l = (2 * l);\n          if (f(op(sm, d[l]))) {\n            sm\
    \ = op(sm, d[l]);\n            l++;\n          }\n        }\n        return l\
    \ - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l)\
    \ != l);\n    return _n;\n  }\n\n  template <bool (*f)(S)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n    S sm = e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r],\
    \ sm))) {\n        while (r < size) {\n          r = (2 * r + 1);\n          if\
    \ (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = op(d[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n,\
    \ size, log;\n  std::vector<S> d;\n\n  void update(int k) { d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n};\n"
  code: "#pragma once\ntemplate <class S, auto op, auto e>\nstruct segtree {\n private:\n\
    \  unsigned int seg_bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while\
    \ (x < (unsigned int)(n)) x *= 2;\n    return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  segtree()\
    \ : segtree(0) {}\n  explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    size\
    \ = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n  \
    \    update(i);\n    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p &&\
    \ p < _n);\n    p += size;\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) const {\n    assert(0 <= p && p < _n);\n\
    \    return d[p + size];\n  }\n\n  S prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= _n);\n    S sml = e(), smr = e();\n    l += size;\n \
    \   r += size;\n\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n\
    \  template <bool (*f)(S)>\n  int max_right(int l) const {\n    return max_right(l,\
    \ [](S x) { return f(x); });\n  }\n  template <class F>\n  int max_right(int l,\
    \ F f) const {\n    assert(0 <= l && l <= _n);\n    assert(f(e()));\n    if (l\
    \ == _n) return _n;\n    l += size;\n    S sm = e();\n    do {\n      while (l\
    \ % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < size)\
    \ {\n          l = (2 * l);\n          if (f(op(sm, d[l]))) {\n            sm\
    \ = op(sm, d[l]);\n            l++;\n          }\n        }\n        return l\
    \ - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l)\
    \ != l);\n    return _n;\n  }\n\n  template <bool (*f)(S)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n    S sm = e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r],\
    \ sm))) {\n        while (r < size) {\n          r = (2 * r + 1);\n          if\
    \ (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = op(d[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n,\
    \ size, log;\n  std::vector<S> d;\n\n  void update(int k) { d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/SegmentTree.hpp
  requiredBy:
  - dp/LongestIncreasingSubsequence.hpp
  - graph/tree/EulerTour.hpp
  timestamp: '2024-06-26 17:49:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
  - verify/AizuOnlineJudge/dp/DPL_1_D.test.cpp
  - verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
  - verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
documentation_of: data-structure/segment-tree/SegmentTree.hpp
layout: document
title: Segment Tree
---

## 概要

長さ $N$ の数列に対して、一点更新と区間の総積を扱うデータ構造。

## コンストラクタ

```cpp
(1) segtree<S, op, e>(int n)
(2) segtree<S, op, e>(const vector<S>& v)
```

- (1) 長さ `n` の数列を構築する。初期値はすべて `e()` となる。
- (2) 長さ `n = v.size()` の数列を構築する。`v` の内容が初期値となる。

### 制約
- テンプレート引数 `S` : モノイド
- `op` は `S` 上の二項演算
- `e()` は `op` の単位元

### 計算量
- $O(n)$

## set

```cpp
void seg.set(int p, S x)
```

`a[p] = x` とする。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## get

```cpp
S seg.get(int p) const
```

`a[p]` を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(1)$

## prod

```cpp
S seg.prod(int l, int r) const
```

区間 $[l, r)$ の総積 `op(a[l], ..., a[r - 1])` を返す。`l = r` のときは `e()` を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## all_prod

```cpp
S seg.all_prod() const
```

区間 $[0, n)$ の総積 `op(a[0], ..., a[n - 1])` を返す。`n = 0` のときは `e()` を返す。

### 計算量
- $O(1)$

## max_right

```cpp
(1) int seg.max_right<f>(int l) const
(2) int seg.max_right<F>(int l, F f) const
```

- (1) 関数 `bool f(S x)` を用いて二分探索を行う。
- (2) `S` を引数に取り `bool` を返す関数オブジェクト `f` を用いて二分探索を行う。

以下の条件を両方満たす `r` を返す。

- `r = l` または `f(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = n` または `f(op(a[l], a[l + 1], ..., a[r])) = false`

`f` が単調なら、`f(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最大の `r` とみなせる。

### 制約
- `f` は同じ引数に対して常に同じ値を返す
- `f(e()) = true`
- $0 \leq l \leq n$

### 計算量
- $O(\log n)$

## min_left

```cpp
(1) int seg.min_left<f>(int r) const
(2) int seg.min_left<F>(int r, F f) const
```

- (1) 関数 `bool f(S x)` を用いて二分探索を行う。
- (2) `S` を引数に取り `bool` を返す関数オブジェクト `f` を用いて二分探索を行う。

以下の条件を両方満たす `l` を返す。

- `l = r` または `f(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` または `f(op(a[l - 1], a[l], ..., a[r - 1])) = false`

`f` が単調なら、`f(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最小の `l` とみなせる。

### 制約
- `f` は同じ引数に対して常に同じ値を返す
- `f(e()) = true`
- $0 \leq r \leq n$

### 計算量
- $O(\log n)$
