---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/CountingPrimes.test.cpp
    title: verify/LibraryChecker/math/number-theory/CountingPrimes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/CountingPrimes.hpp\"\nlong long count_prime(long\
    \ long n) {\n  long long sq = sqrtl(n);\n  vector<long long> d(sq * 2 + 1);\n\
    \  long long siz = d.size();\n  vector<long long> dp(siz);\n  for (long long s\
    \ = 1; s <= sq; s++) d[s] = n / s;\n  for (long long s = 1; s <= sq; s++) d[siz\
    \ - s] = s;\n  for (int i = 1; i < siz; i++) dp[i] = d[i] - 1;\n\n  for (long\
    \ long p = 2; p <= sq; p++) {\n    long long p2 = p * p;\n    if (dp[siz - p +\
    \ 1] == dp[siz - p]) continue;\n    for (int i = 1; i < siz; i++) {\n      if\
    \ (d[i] < p2) break;\n      long long prev = d[i] / p;\n      if (prev > sq) {\n\
    \        dp[i] -= dp[n / prev] - dp[siz - p + 1];\n      } else {\n        dp[i]\
    \ -= dp[siz - prev] - dp[siz - p + 1];\n      }\n    }\n  }\n  return dp[1];\n\
    }\n"
  code: "long long count_prime(long long n) {\n  long long sq = sqrtl(n);\n  vector<long\
    \ long> d(sq * 2 + 1);\n  long long siz = d.size();\n  vector<long long> dp(siz);\n\
    \  for (long long s = 1; s <= sq; s++) d[s] = n / s;\n  for (long long s = 1;\
    \ s <= sq; s++) d[siz - s] = s;\n  for (int i = 1; i < siz; i++) dp[i] = d[i]\
    \ - 1;\n\n  for (long long p = 2; p <= sq; p++) {\n    long long p2 = p * p;\n\
    \    if (dp[siz - p + 1] == dp[siz - p]) continue;\n    for (int i = 1; i < siz;\
    \ i++) {\n      if (d[i] < p2) break;\n      long long prev = d[i] / p;\n    \
    \  if (prev > sq) {\n        dp[i] -= dp[n / prev] - dp[siz - p + 1];\n      }\
    \ else {\n        dp[i] -= dp[siz - prev] - dp[siz - p + 1];\n      }\n    }\n\
    \  }\n  return dp[1];\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/CountingPrimes.hpp
  requiredBy: []
  timestamp: '2025-05-20 01:52:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/number-theory/CountingPrimes.test.cpp
documentation_of: math/number-theory/CountingPrimes.hpp
layout: document
title: Counting Primes
---

## 概要

todo

## 計算量
todo