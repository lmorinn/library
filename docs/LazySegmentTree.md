---
title: Lazy Segment Tree
documentation_of: //data-structure/segment-tree/LazySegmentTree.hpp
---

## 概要

長さ $N$ の数列に対して、区間への作用と区間の総積を扱うデータ構造。

## コンストラクタ

```cpp
(1) lazy_segtree<S, op, e, F, mapping, composition, id>(int n)
(2) lazy_segtree<S, op, e, F, mapping, composition, id>(const vector<S>& v)
```

- (1) 長さ `n` の数列を構築する。初期値はすべて `e()` となる。
- (2) 長さ `n = v.size()` の数列を構築する。`v` の内容が初期値となる。

`S`, `op`, `e`, `F`, `mapping`, `composition`, `id` は次を満たす必要がある。

- `S` はモノイド
- `F` は恒等写像 `id` を含む
- `F` は写像の合成について閉じている
- 任意の $f \in F$, $x, y \in S$ に対して `mapping(f, op(x, y)) = op(mapping(f, x), mapping(f, y))`
- `composition(f, g)` は写像の合成 $f \circ g$ を表す

### 制約
- $0 \leq n$

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
S seg.get(int p)
```

`a[p]` を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## prod

```cpp
S seg.prod(int l, int r)
```

区間 $[l, r)$ の総積 `op(a[l], ..., a[r - 1])` を返す。`l = r` のときは `e()` を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## all_prod

```cpp
S seg.all_prod()
```

区間 $[0, n)$ の総積 `op(a[0], ..., a[n - 1])` を返す。`n = 0` のときは `e()` を返す。

### 計算量
- $O(1)$

## apply

```cpp
(1) void seg.apply(int p, F f)
(2) void seg.apply(int l, int r, F f)
```

- (1) `a[p] = mapping(f, a[p])` とする。
- (2) `i = l, l + 1, ..., r - 1` について `a[i] = mapping(f, a[i])` とする。

### 制約
- (1) $0 \leq p < n$
- (2) $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## max_right

```cpp
(1) int seg.max_right<g>(int l)
(2) int seg.max_right<G>(int l, G g)
```

- (1) 関数 `bool g(S x)` を用いて二分探索を行う。
- (2) `S` を引数に取り `bool` を返す関数オブジェクト `g` を用いて二分探索を行う。

以下の条件を両方満たす `r` を返す。

- `r = l` または `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = n` または `g(op(a[l], a[l + 1], ..., a[r])) = false`

`g` が単調なら、`g(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最大の `r` とみなせる。

### 制約
- `g` は同じ引数に対して常に同じ値を返す
- `g(e()) = true`
- $0 \leq l \leq n$

### 計算量
- $O(\log n)$

## min_left

```cpp
(1) int seg.min_left<g>(int r)
(2) int seg.min_left<G>(int r, G g)
```

- (1) 関数 `bool g(S x)` を用いて二分探索を行う。
- (2) `S` を引数に取り `bool` を返す関数オブジェクト `g` を用いて二分探索を行う。

以下の条件を両方満たす `l` を返す。

- `l = r` または `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` または `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

`g` が単調なら、`g(op(a[l], a[l + 1], ..., a[r - 1])) = true` となる最小の `l` とみなせる。

### 制約
- `g` は同じ引数に対して常に同じ値を返す
- `g(e()) = true`
- $0 \leq r \leq n$

### 計算量
- $O(\log n)$
