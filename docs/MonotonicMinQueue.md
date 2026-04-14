---
title: Monotonic Queue (Min Queue)
documentation_of: //data-structure/others/MonotonicMinQueue.hpp
---

## 概要

キューに含まれる要素の最小値を効率的に管理するデータ構造。

## push

```cpp
void que.push(const T& x)
```

キューの末尾に `x` を追加する。

### 計算量
- amortized $O(1)$

## pop

```cpp
void que.pop()
```

キューの先頭の要素を削除する。

### 制約
- キューが空でない

### 計算量
- amortized $O(1)$

## front

```cpp
const T& que.front() const
```

キューの先頭の要素を返す。

### 制約
- キューが空でない

### 計算量
- $O(1)$

## empty

```cpp
bool que.empty() const
```

キューが空なら `true`、そうでなければ `false` を返す。

### 計算量
- $O(1)$

## minimum

```cpp
const T& que.minimum() const
```

キューに含まれる要素の最小値を返す。

### 制約
- キューが空でない

### 計算量
- $O(1)$
