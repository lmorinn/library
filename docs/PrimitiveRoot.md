---
title: Primitive Root
documentation_of: //math/number-theory/PrimitiveRoot.hpp
---

## 概要

素数の原始根を求める。

## 関数

```cpp
long long primitive_root(long long p)
```

素数 `p` の原始根を 1 つ返す。

### 制約
- `p` は素数

### 計算量
- ポラード・ロー法による `p - 1` の素因数分解の計算量に依存する。
