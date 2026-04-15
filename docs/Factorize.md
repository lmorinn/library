---
title: Factorize
documentation_of: //math/number-theory/Factorize.hpp
---

## 概要

整数の素因数分解を行う。

## 関数

```cpp
vector<long long> factorize(long long n, bool set = false)
```

`n` の素因数を小さい順に返す。`set = false` のときは素因数が指数分重複してvectorに格納される。 `set = true` のときは素因数の集合がvectorに格納される。

### 制約
- $1 \leq n$

### 計算量
- ポラード・ロー法による素因数分解の計算量に依存する。
