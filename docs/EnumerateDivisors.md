---
title: Enumerate Divisors
documentation_of: //math/number-theory/EnumerateDivisors.hpp
---

## 概要

整数の約数を列挙する。

## 関数

```cpp
vector<long long> enumerate_divisors(long long n, bool sorted_result = false)
```

`n` の正の約数を列挙して返す。`sorted_result = true` のとき、返り値は昇順にソートされる。

### 制約
- $1 \leq n$

### 計算量
- ポラード・ロー法による素因数分解の計算量に依存する
