---
title: Xorshift
documentation_of: //other/Xorshift.hpp
---

## 概要

Xorshift による疑似乱数を生成する。

## 変数

```cpp
inline static unsigned long long seed
```

乱数生成に用いる内部状態を表す。

## 関数

```cpp
unsigned long long rand_gen(long long p)
```

内部状態を更新し、`0` 以上 `p - 1` 以下の疑似乱数を返す。

### 制約
- $1 \leq p$

### 計算量
- $O(1)$
