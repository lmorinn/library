---
title: Counting Primes
documentation_of: //math/number-theory/CountingPrimes.hpp
---

## 概要

Lucy DP により `n` 以下の素数の個数を求める。

## 関数

```cpp
long long count_prime(long long n)
```

`n` 以下の素数の個数を返す。

### 制約
- $1 \leq n$

### 計算量
- $O(n^{3/4})$
