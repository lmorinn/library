---
title: Dual Segment Tree
documentation_of: //data-structure/segment-tree/DualSegmentTree.hpp
---

## 概要

長さ $N$ の数列に対して、区間への作用と一点取得を扱うデータ構造。

## コンストラクタ

```cpp
DualSegmentTree<S, F, mapping, composition, id>(vector<S>& v)
```

長さ `n = v.size()` の数列`a`を構築する。`v` の内容が初期値となる。

### 制約
- `S` は値の型
- `F` は写像の合成について閉じている
- `composition` は写像の合成
- `id()` は恒等写像

### 計算量
- $O(n)$

## apply

```cpp
void seg.apply(int l, int r, F x)
```

-  `i = l, l + 1, ..., r - 1` について `a[i] = mapping(f, a[i])` とする。

### 制約
- $0 \leq l \leq r \leq n$

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

## getf

```cpp
F seg.getf(int p)
```

`a[p]` に対するこれまでの作用の合成を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$
