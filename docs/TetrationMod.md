---
title: Tetration Mod
documentation_of: //math/number-theory/TetrationMod.hpp
---

## 概要

テトレーション $a^{a^{\cdot^{\cdot^a}}} \bmod m$ を求める。
オイラーの $\varphi$ 関数で法を順に落としながら計算する。

## 関数

```cpp
long long tetration_mod(long long a, long long b, long long m)
```

$a$ を $b$ 段重ねた冪塔の値を $m$ で割った余りを返す。

### 制約
- $0 \leq a$
- $0 \leq b$
- $1 \leq m$

### 計算量
- $O(\sqrt{m})$
