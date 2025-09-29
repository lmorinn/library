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
title: Knapsack Problem
---

## 概要
todo

## 計算量
todo