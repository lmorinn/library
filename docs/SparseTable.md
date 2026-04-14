---
title: Sparse Table
documentation_of: //data-structure/others/SparseTable.hpp
---

## 概要

長さ $N$ の数列に対して、静的な区間の総積を扱うデータ構造。

## コンストラクタ

```cpp
SparseTable<T, f>(const vector<T>& v)
```

長さ `n = v.size()` の数列を構築する。`v` の内容が初期値となる。

### 制約
- テンプレート引数 `T` : 冪等な二項演算を持つ集合
- `f` は `T` 上の二項演算
- 任意の $x, y, z \in T$ に対して `f(f(x, y), z) = f(x, f(y, z))`
- 任意の $x \in T$ に対して `f(x, x) = x`
- $1 \leq n$

### 計算量
- $O(n \log n)$

## query

```cpp
T st.query(int l, int r) const
```

区間 $[l, r)$ の総積を返す。

### 制約
- $0 \leq l < r \leq n$

### 計算量
- $O(1)$
