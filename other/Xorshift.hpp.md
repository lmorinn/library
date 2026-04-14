---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/flow/MaximumMatchingSize.hpp
    title: Maximum Matching Size (Randomized)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/flow/GRL_7_A.test.cpp
    title: verify/AizuOnlineJudge/graph/flow/GRL_7_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/Xorshift.hpp\"\ninline static unsigned long long seed\
    \ = 1235;\nunsigned long long rand_gen(long long p) {\n  unsigned long long x\
    \ = seed;\n  x ^= x << 13;\n  x ^= x >> 7;\n  x ^= x << 17;\n  seed = x;\n  return\
    \ seed % p;\n}\n"
  code: "inline static unsigned long long seed = 1235;\nunsigned long long rand_gen(long\
    \ long p) {\n  unsigned long long x = seed;\n  x ^= x << 13;\n  x ^= x >> 7;\n\
    \  x ^= x << 17;\n  seed = x;\n  return seed % p;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/Xorshift.hpp
  requiredBy:
  - graph/flow/MaximumMatchingSize.hpp
  timestamp: '2026-03-22 12:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/flow/GRL_7_A.test.cpp
documentation_of: other/Xorshift.hpp
layout: document
title: Xorshift
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
