---
title: Euler's Phi Function
documentation_of: //math/number-theory/EulersPhiFunction.hpp
---

## 概要

オイラーの $\varphi$ 関数を求める。

## 関数

```cpp
long long Eulers_phi_function(long long n)
```

$\varphi(n)$ を返す。すなわち、`1` 以上 `n` 以下の整数のうち `n` と互いに素なものの個数を返す。

### 制約
- $1 \leq n$

### 計算量
- ポラード・ロー法による素因数分解の計算量に依存する
