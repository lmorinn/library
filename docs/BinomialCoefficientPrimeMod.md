---
title: Binomial Coefficient (Prime Mod)
documentation_of: //math/enumerative-combinatorics/BinomialCoefficientPrimeMod.hpp
---

## 概要

素数 mod における二項係数を、階乗と階乗逆元の前計算により求める。

## コンストラクタ

```cpp
BinomialCoefficient(int n)
```

$[0, n]$ の階乗 `fac` と逆元階乗 `inv` を前計算する。前計算のテーブルがすでに存在する場合は、不足分を拡張する。

### 制約
- `S` は `inv()` を持つ型
- $0 \leq n$

### 計算量
- $O(n)$

## nCr

```cpp
S binom.nCr(int n, int r)
```

二項係数 $\binom{n}{r}$ を返す。$n < r$ のとき $0$ を返す。

### 制約
- $0 \leq n$
- $0 \leq r$
- `n` は前計算したテーブルの範囲内

### 計算量
- $O(1)$
