---
title: Enumerate Quotients
documentation_of: //math/number-theory/EnumerateQuotients.hpp
---

## 概要

整数除算で現れる商を列挙する。

## 関数

```cpp
vector<long long> enumerate_quotients(long long n)
```

$\left\lfloor \dfrac{n}{i} \right\rfloor (i = 1, 2, \ldots, n) $ として現れる異なる値を昇順に列挙して返す。

### 制約
- $1 \leq n$

### 計算量
- $O(\sqrt n)$
