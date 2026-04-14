---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/EnumerateQuotients.test.cpp
    title: verify/LibraryChecker/math/number-theory/EnumerateQuotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/EnumerateQuotients.hpp\"\nvector<long\
    \ long> enumerate_quotients(long long n) {\n  long long sq = sqrtl(n);\n  vector<long\
    \ long> d(sq);\n  iota(d.begin(), d.end(), 1);\n  long long siz = d.size();\n\
    \  for (long long s = sq; s >= 1; s--) {\n    if (n / s != s) d.emplace_back(n\
    \ / s);\n  }\n  return d;\n}\n"
  code: "vector<long long> enumerate_quotients(long long n) {\n  long long sq = sqrtl(n);\n\
    \  vector<long long> d(sq);\n  iota(d.begin(), d.end(), 1);\n  long long siz =\
    \ d.size();\n  for (long long s = sq; s >= 1; s--) {\n    if (n / s != s) d.emplace_back(n\
    \ / s);\n  }\n  return d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/EnumerateQuotients.hpp
  requiredBy: []
  timestamp: '2025-05-20 01:52:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/number-theory/EnumerateQuotients.test.cpp
documentation_of: math/number-theory/EnumerateQuotients.hpp
layout: document
title: Enumerate Quotients
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
