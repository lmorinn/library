---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/math/number-theory/FareySequence2286.test.cpp
    title: verify/AizuOnlineJudge/math/number-theory/FareySequence2286.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/EulersPhiFunctionTable.hpp\"\nvector<int>\
    \ Eulers_phi_function_table(int n) {\n  vector<int> table(n + 1);\n  iota(table.begin(),\
    \ table.end(), 0);\n\n  for (int i = 2; i <= n; i++) {\n    if (table[i] == i)\
    \ {\n      for (int j = i; j <= n; j += i) {\n        table[j] = table[j] / i\
    \ * (i - 1);\n      }\n    }\n  }\n  return table;\n}\n"
  code: "vector<int> Eulers_phi_function_table(int n) {\n  vector<int> table(n + 1);\n\
    \  iota(table.begin(), table.end(), 0);\n\n  for (int i = 2; i <= n; i++) {\n\
    \    if (table[i] == i) {\n      for (int j = i; j <= n; j += i) {\n        table[j]\
    \ = table[j] / i * (i - 1);\n      }\n    }\n  }\n  return table;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/EulersPhiFunctionTable.hpp
  requiredBy: []
  timestamp: '2025-05-20 03:07:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/math/number-theory/FareySequence2286.test.cpp
documentation_of: math/number-theory/EulersPhiFunctionTable.hpp
layout: document
title: Euler's Phi Function Table
---

## 概要

オイラーの $\varphi$ 関数のテーブルを構築する。

## 関数

```cpp
vector<int> Eulers_phi_function_table(int n)
```

長さ `n + 1` の配列を返す。返り値の `i` 番目は $\varphi(i)$ を表す。`0` 番目は `0` である。

### 制約
- $0 \leq n$

### 計算量
- $O(n \log \log n)$
