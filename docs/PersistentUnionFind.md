---
title: Persistent Union Find
documentation_of: //data-structure/union-find/PersistentUnionFind.hpp
---

## 概要

完全永続 Union-Find

## コンストラクタ

```cpp
PersistentUnionfind(int n)
```

`n` 頂点のグラフに対する完全永続 Union-Find を構築する。

### 制約

* $1 \le n$

### 計算量

* $O(n \log n)$

## get_root

```cpp
Node* get_root()
```

初期バージョンのポインタを返す。

### 計算量

* $O(1)$


## merge

```cpp
Node* merge(Node* p, int a, int b)
```

バージョン `p` において `a` と `b` を連結した新しいバージョンのポインタを返す。すでに同じ連結成分に属している場合は `p` を返す。

### 制約

* $0 \leq a, b < n$

### 計算量

* $O(\log^2 n)$


## same

```cpp
bool same(Node* p, int a, int b)
```

バージョン `p` において `a` と `b` が同じ連結成分に属していれば `true` を返す。

### 制約

* $0 \leq a, b < n$

### 計算量

* $O(\log^2 n)$

## leader
```cpp
int leader(Node* p, int a)
```

バージョン `p` において、`a` が属する連結成分の代表元を返す。

### 制約

* $0 \leq a < n$

### 計算量

* $O(\log^2 n)$


## size
```cpp
int size(Node* p, int a)
```

バージョン `p` において、`a` が属する連結成分の頂点数を返す。

### 制約

* $0 \leq a < n$

### 計算量

* $O(\log^2 n)$

## groups
```cpp
vector<vector<int>> groups(Node* p)
```

バージョン `p` における各連結成分の頂点列を返す。

### 制約


### 計算量

* $O(n \log^2 n)$
