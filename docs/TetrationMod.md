---
title: Tetration Mod
documentation_of: //math/number-theory/TetrationMod.hpp
---

## 概要

テトレーション $a^{a^{\cdot^{\cdot^a}}} \bmod m$ を求める。


## 関数

```cpp
long long tetration_mod(long long a, long long b, long long m)
```

$a$ を $b$ 段重ねた冪塔の値を $m$ で割った余りを返す。

### 制約
- $0 \leq a,b$
- $1 \leq m$
- $a,b,m$ は `long long` に収まる

### 計算量
- $O(\sqrt{m})$
