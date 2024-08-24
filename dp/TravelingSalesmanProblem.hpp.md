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
  bundledCode: "#line 2 \"dp/TravelingSalesmanProblem.hpp\"\ntemplate <class T>\n\
    vector<vector<T>> tsp(vector<vector<T>> &w, int n) {\n    T INF = numeric_limits<T>::max();\n\
    \    vector<vector<T>> dp(n, vector<T>((1 << (n + 1)), INF));\n    dp[0][0] =\
    \ 0;\n    for (int bit = 0; bit < (1 << n); bit++) {\n        for (int cur = 0;\
    \ cur < n; cur++) {\n            if (dp[cur][bit] == INF) continue;\n        \
    \    for (int nex = 0; nex < n; nex++) {\n                if ((bit / (1 << nex))\
    \ % 2 == 1) continue;\n                dp[nex][bit | (1 << nex)] = min(dp[nex][bit\
    \ | (1 << nex)], dp[cur][bit] + w[cur][nex]);\n            }\n        }\n    }\n\
    \    return dp;\n}\n"
  code: "#pragma once\ntemplate <class T>\nvector<vector<T>> tsp(vector<vector<T>>\
    \ &w, int n) {\n    T INF = numeric_limits<T>::max();\n    vector<vector<T>> dp(n,\
    \ vector<T>((1 << (n + 1)), INF));\n    dp[0][0] = 0;\n    for (int bit = 0; bit\
    \ < (1 << n); bit++) {\n        for (int cur = 0; cur < n; cur++) {\n        \
    \    if (dp[cur][bit] == INF) continue;\n            for (int nex = 0; nex < n;\
    \ nex++) {\n                if ((bit / (1 << nex)) % 2 == 1) continue;\n     \
    \           dp[nex][bit | (1 << nex)] = min(dp[nex][bit | (1 << nex)], dp[cur][bit]\
    \ + w[cur][nex]);\n            }\n        }\n    }\n    return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/TravelingSalesmanProblem.hpp
  requiredBy: []
  timestamp: '2024-08-24 16:53:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/TravelingSalesmanProblem.hpp
layout: document
title: Traveling Salesman Problem
---

## 概要

todo

## 計算量
todo