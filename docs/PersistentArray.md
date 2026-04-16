---
title: Persistent Array
documentation_of: //data-structure/others/PersistentArray.hpp
---

## 概要

永続配列

## コンストラクタ

```cpp
PersistentArray(int siz)
```

`siz` の永続配列を構築する。



```cpp
PersistentArray(int siz, T x)
```

配列のすべての値を `x` として、サイズ `siz` の永続配列を構築する。


```cpp
PersistentArray(const vector<T>& v)
```

`v` から永続配列を構築する。

### 制約
- $0 \leq n$

### 計算量
- $O(n \log n)$

## get

```cpp
T get(Node* ptr, int p)
```

`ptr` を根とするバージョンの `p` 番目の要素を返す。

### 制約
-  $0 \leq p < n$

### 計算量
- $O(\log n)$

## get_root

```cpp
Node* get_root()
```

初期状態の根を返す。

### 計算量
- $O(1)$

## set

```cpp
Node* set(Node* ptr, int p, T x)
```

`ptr` を根とするバージョンの `p` 番目を `x` に更新した新しい根を返す。

### 制約
-  $0 \leq p < n$

### 計算量
- $O(\log n)$