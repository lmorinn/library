---
title: Persistent Segment Tree
documentation_of: //data-structure/segment-tree/PersistentSegmentTree.hpp
---

## 概要

永続セグメント木

## コンストラクタ

```cpp
persistent_segtree<S, op, e>(const vector<S>& v)
```

長さ `n = v.size()` の永続セグメント木を構築する。`v` の内容が初期値となる。

### 制約
-  $1 \leq n$
- `S` はモノイド
- `op` は `S` 上の二項演算
- `e()` は `op` の単位元

### 計算量
- $O(n)$

## replace

```cpp
int seg.replace(const vector<S>& v)
```

$i$ 番目の要素を `v[i]` とした新しいバージョンのidを返す。

### 制約
- `v.size()` は構築時の配列の長さと等しい

### 計算量
- $O(n)$

## get_root

```cpp
int seg.get_root()
```

初期バージョン（構築時の配列）に対応するidを返す。

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
