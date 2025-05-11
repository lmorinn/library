---
title: Cumulative Sum
documentation_of: //dp/CumulativeSum.hpp
---

## 概要

1次元の累積和を構築する。長さ $N$ の数列に対して、前計算 $O(N)$ の上で区間の和を $O(1)$ で求めることができる。

## コンストラクタ

```cpp
CumulativeSum<T>(vector<T> a)
```

長さ `n = a.size()` の数列に対して累積和を構築する。

### 制約
- テンプレート引数 `T` : データの型。群の代数構造を満たす必要がある。


### 計算量

- $O(n)$

## sum

```cpp
(1) T cum.sum(int l)
(2) T cum.sum(int l, int r)
```

- (1) 区間 $[0, l)$ の和を返す。
- (2) 区間 $[l, r)$ の和を返す。

### 制約

- $0 \leq l \leq r \leq n$



### 計算量
- $O(1)$