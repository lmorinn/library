---
title: Segment Tree
documentation_of: //data-structure/segment-tree/SegmentTree.hpp
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
