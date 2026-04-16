---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/enumerative-combinatorics/BinomialCoefficientPrimeMod.test.cpp
    title: verify/LibraryChecker/math/enumerative-combinatorics/BinomialCoefficientPrimeMod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/enumerative-combinatorics/BinomialCoefficientPrimeMod.hpp\"\
    \n\ntemplate <class S>\nstruct BinomialCoefficient {\n private:\n  inline static\
    \ vector<S> fac, inv;\n\n public:\n  BinomialCoefficient(int n) {\n    int p =\
    \ int(fac.size());\n    if (p <= n) {\n      fac.resize(n + 1);\n      inv.resize(n\
    \ + 1);\n      if (p == 0) fac[0] = 1;\n      for (int i = p; i < n + 1; i++)\
    \ {\n        if (i == 0) continue;\n        fac[i] = fac[i - 1] * i;\n      }\n\
    \      inv[n] = fac[n].inv();\n      for (int i = n; i > p; i--) {\n        if\
    \ (i == 0) continue;\n        inv[i - 1] = inv[i] * i;\n      }\n    }\n  }\n\n\
    \  S nCr(int n, int r) {\n    if (n < r) return S(0);\n    assert(fac.size() >\
    \ n and fac.size() > r);\n    return fac[n] * inv[r] * inv[n - r];\n  }\n};\n"
  code: "\ntemplate <class S>\nstruct BinomialCoefficient {\n private:\n  inline static\
    \ vector<S> fac, inv;\n\n public:\n  BinomialCoefficient(int n) {\n    int p =\
    \ int(fac.size());\n    if (p <= n) {\n      fac.resize(n + 1);\n      inv.resize(n\
    \ + 1);\n      if (p == 0) fac[0] = 1;\n      for (int i = p; i < n + 1; i++)\
    \ {\n        if (i == 0) continue;\n        fac[i] = fac[i - 1] * i;\n      }\n\
    \      inv[n] = fac[n].inv();\n      for (int i = n; i > p; i--) {\n        if\
    \ (i == 0) continue;\n        inv[i - 1] = inv[i] * i;\n      }\n    }\n  }\n\n\
    \  S nCr(int n, int r) {\n    if (n < r) return S(0);\n    assert(fac.size() >\
    \ n and fac.size() > r);\n    return fac[n] * inv[r] * inv[n - r];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/enumerative-combinatorics/BinomialCoefficientPrimeMod.hpp
  requiredBy: []
  timestamp: '2026-04-13 13:43:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/enumerative-combinatorics/BinomialCoefficientPrimeMod.test.cpp
documentation_of: math/enumerative-combinatorics/BinomialCoefficientPrimeMod.hpp
layout: document
title: Binomial Coefficient (Prime Mod)
---

## 概要

素数 mod における二項係数を、階乗と階乗逆元の前計算により求める。

## コンストラクタ

```cpp
BinomialCoefficient(int n)
```

$[0, n]$ の階乗 `fac` と逆元階乗 `inv` を前計算する。前計算のテーブルがすでに存在する場合は、不足分を拡張する。

### 制約
- `S` は `inv()` を持つ型
- $0 \leq n$

### 計算量
- $O(n)$

## nCr

```cpp
S binom.nCr(int n, int r)
```

二項係数 $\binom{n}{r}$ を返す。$n < r$ のとき $0$ を返す。

### 制約
- $0 \leq n$
- $0 \leq r$
- `n` は前計算したテーブルの範囲内

### 計算量
- $O(1)$
