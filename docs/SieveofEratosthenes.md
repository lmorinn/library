---
title: Sieve of Eratosthenes
documentation_of: //math/number-theory/SieveofEratosthenes.hpp
---

## 概要

エラトステネスの篩で素数判定表を構築する。

## 関数

```cpp
vector<bool> prime_table(int n)
```

長さ `n + 1` の配列を返す。返り値の `i` 番目は、`i` が素数なら `true`、そうでなければ `false` となる。

### 制約
- $0 \leq n$

### 計算量
- $O(n \log \log n)$
