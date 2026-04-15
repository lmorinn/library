---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
    title: verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/KnapsackProblemNoLimit.hpp\"\ntemplate <class T>\nvector<T>\
    \ knapsack(const vector<int> &w, const vector<T> &v, const int W) {\n    int n\
    \ = int(v.size());\n    T ng = numeric_limits<T>::min();\n    vector<vector<T>>\
    \ dp(n + 1, vector(W + 2, ng));\n    dp[0][0] = 0;\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j <= W; j++) {\n            if (dp[i][j] !=\
    \ ng) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);\n            if (dp[i + 1][j]\
    \ != ng) dp[i + 1][min(j + w[i], W + 1)] = max(dp[i + 1][min(j + w[i], W + 1)],\
    \ dp[i + 1][j] + v[i]);\n        }\n    }\n    return {dp[n].begin(), dp[n].end()\
    \ - 1};\n}\n"
  code: "template <class T>\nvector<T> knapsack(const vector<int> &w, const vector<T>\
    \ &v, const int W) {\n    int n = int(v.size());\n    T ng = numeric_limits<T>::min();\n\
    \    vector<vector<T>> dp(n + 1, vector(W + 2, ng));\n    dp[0][0] = 0;\n    for\
    \ (int i = 0; i < n; i++) {\n        for (int j = 0; j <= W; j++) {\n        \
    \    if (dp[i][j] != ng) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);\n       \
    \     if (dp[i + 1][j] != ng) dp[i + 1][min(j + w[i], W + 1)] = max(dp[i + 1][min(j\
    \ + w[i], W + 1)], dp[i + 1][j] + v[i]);\n        }\n    }\n    return {dp[n].begin(),\
    \ dp[n].end() - 1};\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/KnapsackProblemNoLimit.hpp
  requiredBy: []
  timestamp: '2025-09-30 00:05:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
documentation_of: dp/KnapsackProblemNoLimit.hpp
layout: document
title: Knapsack Problem No Limit
---

## 概要

個数制限なしナップサック問題を解く。

## 関数

```cpp
template <class T>
vector<T> knapsack(const vector<int>& w, const vector<T>& v, const int W)
```

重さ `w[i]`、価値 `v[i]` の各品物を任意個使えるときのナップサック DP を行う。返り値の `j` 番目は、重さの総和がちょうど `j` となる選び方の価値の最大値を表す。到達できない重さには `numeric_limits<T>::min()` が入る。

### 制約
- `w.size() = v.size()`
- $0 \leq W$
- テンプレート引数 `T` は加算と比較ができる

### 計算量
- $O(nW)$
