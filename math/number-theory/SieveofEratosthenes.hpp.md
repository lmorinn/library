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
  bundledCode: "#line 2 \"math/number-theory/SieveofEratosthenes.hpp\"\nclass Eratosthenes\
    \ {\n  vector<bool> table;\n  vector<int> minfactor;\n  Eratosthenes(int n) {\n\
    \    table.resize(n + 1, true);\n    minfactor.resize(n + 1, -1);\n    table[1]\
    \ = false;\n    minfactor[1] = 1;\n    for (int i = 2; i <= n; ++i) {\n      if\
    \ (!table[i]) continue;\n      minfactor[i] = i;\n      for (int j = i * 2; j\
    \ <= n; j += i) {\n        table[j] = false;\n        if (minfactor[j] == -1)\
    \ minfactor[j] = i;\n      }\n    }\n  }\n\n  // \u9AD8\u901F\u7D20\u56E0\u6570\
    \u5206\u89E3\n  vector<pair<int, int>> factorize(int n) {\n    vector<pair<int,\
    \ int>> res;\n    while (n > 1) {\n      int p = minfactor[n];\n      int exp\
    \ = 0;\n      while (minfactor[n] == p) {\n        n /= p;\n        exp++;\n \
    \     }\n      res.emplace_back(p, exp);\n    }\n    return res;\n  }\n\n  //\
    \ \u7D20\u56E0\u6570\u306E\u7A2E\u985E\n  int primefactor_num(int n) {\n    int\
    \ res = 0;\n    while (n > 1) {\n      int p = minfactor[n];\n      int exp =\
    \ 0;\n      while (minfactor[n] == p) {\n        n /= p;\n        exp++;\n   \
    \   }\n      res++;\n    }\n    return res;\n  }\n\n  // \u7D04\u6570\u306E\u500B\
    \u6570\n  long long divisor_num(int n) {\n    long long res = 1;\n    while (n\
    \ > 1) {\n      int p = minfactor[n];\n      int exp = 0;\n      while (minfactor[n]\
    \ == p) {\n        n /= p;\n        ++exp;\n      }\n      res *= (exp + 1);\n\
    \    }\n    return res;\n  }\n\n  // \u7D04\u6570\u306E\u7DCF\u548C\n  long long\
    \ divisor_sum(int n) {\n    long long res = 1;\n    while (n > 1) {\n      int\
    \ p = minfactor[n];\n      int pw = 1;\n      long long sum = 0;\n      while\
    \ (minfactor[n] == p) {\n        n /= p;\n        sum += pw;\n        pw *= p;\n\
    \      }\n      res *= sum;\n    }\n    return res;\n  }\n};\n"
  code: "#pragma once\nclass Eratosthenes {\n  vector<bool> table;\n  vector<int>\
    \ minfactor;\n  Eratosthenes(int n) {\n    table.resize(n + 1, true);\n    minfactor.resize(n\
    \ + 1, -1);\n    table[1] = false;\n    minfactor[1] = 1;\n    for (int i = 2;\
    \ i <= n; ++i) {\n      if (!table[i]) continue;\n      minfactor[i] = i;\n  \
    \    for (int j = i * 2; j <= n; j += i) {\n        table[j] = false;\n      \
    \  if (minfactor[j] == -1) minfactor[j] = i;\n      }\n    }\n  }\n\n  // \u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3\n  vector<pair<int, int>> factorize(int n)\
    \ {\n    vector<pair<int, int>> res;\n    while (n > 1) {\n      int p = minfactor[n];\n\
    \      int exp = 0;\n      while (minfactor[n] == p) {\n        n /= p;\n    \
    \    exp++;\n      }\n      res.emplace_back(p, exp);\n    }\n    return res;\n\
    \  }\n\n  // \u7D20\u56E0\u6570\u306E\u7A2E\u985E\n  int primefactor_num(int n)\
    \ {\n    int res = 0;\n    while (n > 1) {\n      int p = minfactor[n];\n    \
    \  int exp = 0;\n      while (minfactor[n] == p) {\n        n /= p;\n        exp++;\n\
    \      }\n      res++;\n    }\n    return res;\n  }\n\n  // \u7D04\u6570\u306E\
    \u500B\u6570\n  long long divisor_num(int n) {\n    long long res = 1;\n    while\
    \ (n > 1) {\n      int p = minfactor[n];\n      int exp = 0;\n      while (minfactor[n]\
    \ == p) {\n        n /= p;\n        ++exp;\n      }\n      res *= (exp + 1);\n\
    \    }\n    return res;\n  }\n\n  // \u7D04\u6570\u306E\u7DCF\u548C\n  long long\
    \ divisor_sum(int n) {\n    long long res = 1;\n    while (n > 1) {\n      int\
    \ p = minfactor[n];\n      int pw = 1;\n      long long sum = 0;\n      while\
    \ (minfactor[n] == p) {\n        n /= p;\n        sum += pw;\n        pw *= p;\n\
    \      }\n      res *= sum;\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/SieveofEratosthenes.hpp
  requiredBy: []
  timestamp: '2024-06-27 14:44:32+09:00'
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