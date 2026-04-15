---
title: Primality Test
documentation_of: //math/number-theory/PrimalityTest.hpp
---

## 概要

整数の素数判定を行う。

## 関数

```cpp
bool is_prime(long long n)
```

`n` が素数なら `true` を返す。

### 制約
- $0 \leq n$ かつ、 $n$ は `long long` の範囲

### 計算量
- $O(\log n)$
