---
title: Persistent Lazy Segment Tree
documentation_of: //data-structure/segment-tree/PersistentLazySegmentTree.hpp
---

## 概要

永続遅延セグメント木

## コンストラクタ

```cpp
persistent_lazy_segtree<S, op, e, F, mapping, composition, id>(const vector<S>& v)
```

長さ `n = v.size()` の永続遅延セグメント木を構築する。`v` の内容が初期値となる。

### 制約
- $1 \leq n$
- `S` はモノイド
- `F` は恒等写像 `id` を含む
- `F` は写像の合成について閉じている
- 任意の $f \in F$, $x, y \in S$ に対して `mapping(f, op(x, y)) = op(mapping(f, x), mapping(f, y))`
- `composition(f, g)` は写像の合成 $f \circ g$ 

### 計算量
- $O(n)$

## get_root

```cpp
int seg.get_root()
```

初期列に対応する root id を返す。

### 計算量
- $O(1)$

## set

```cpp
int seg.set(int p, S x, int root_id)
```

バージョン `root_id` において `seg[p] = x` とした新しいバージョンのidを返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## apply

```cpp
int seg.apply(int l, int r, F f, int root_id)
```

バージョン `root_id` において、区間 $[l, r)$ の各要素に `f` を作用させた新しいバージョンのidを返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## prod

```cpp
S seg.prod(int l, int r, int root_id)
```

バージョン `root_id` における区間 $[l, r)$ の総積 `op(seg[l], ..., seg[r - 1])` を返す。`l = r` のときは `e()` を返す。


### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## get

```cpp
S seg.get(int p, int root_id)
```

バージョン `root_id` における `seg[p]` を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## rollback

```cpp
int seg.rollback(int a, int b, int root_id, int old_root)
```

バージョン `root_id` において、区間 $[a, b)$ を バージョン `old_root` の同区間で置き換えたときの新しいバージョンを返す。

### 制約
- $0 \leq a \leq b \leq n$

### 計算量
- $O(\log n)$

## status

```cpp
vector<S> seg.status(int root_id)
```

バージョン `root_id` に対応する数列を返す。

### 計算量
- $O(n \log n)$


## 参考文献

[Persistence Made Simple - Tutorial](https://discuss.codechef.com/t/persistence-made-simple-tutorial/14915)
