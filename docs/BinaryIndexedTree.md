---
title: Binary Indexed Tree
documentation_of: //data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
---

## 概要

長さ $N$ の数列に対して、一点加算と区間和を扱うデータ構造。

## コンストラクタ

```cpp
fenwick_tree<T>(int n)
```

長さ `n` の数列を構築する。初期値はすべて `0` となる。

### 制約
- テンプレート引数 `T` : 加法に関する可換群

### 計算量
- $O(n)$

## add

```cpp
void bit.add(int p, T x)
```

`a[p] += x` とする。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## sum

```cpp
T bit.sum(int l, int r)
```

区間 $[l, r)$ の和を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$
