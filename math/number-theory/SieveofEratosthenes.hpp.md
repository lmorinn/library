---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/SieveofEratosthenes.hpp\"\nvector<bool>\
    \ prime_table(int n) {\n  vector<bool> prime(n + 1, true);\n  prime[0] = false;\n\
    \  if (n >= 1) prime[1] = false;\n  for (int i = 2; i * i <= n; i++) {\n    if\
    \ (!prime[i]) continue;\n    for (int j = i * i; j <= n; j += i) {\n      prime[j]\
    \ = false;\n    }\n  }\n  return prime;\n}\n"
  code: "vector<bool> prime_table(int n) {\n  vector<bool> prime(n + 1, true);\n \
    \ prime[0] = false;\n  if (n >= 1) prime[1] = false;\n  for (int i = 2; i * i\
    \ <= n; i++) {\n    if (!prime[i]) continue;\n    for (int j = i * i; j <= n;\
    \ j += i) {\n      prime[j] = false;\n    }\n  }\n  return prime;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/SieveofEratosthenes.hpp
  requiredBy: []
  timestamp: '2025-05-20 01:52:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/SieveofEratosthenes.hpp
layout: document
title: Sieve of Eratosthenes
---

## 概要

todo

## 計算量
todo