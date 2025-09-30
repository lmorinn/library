---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/dp/DSL_3_D.test.cpp
    title: verify/AizuOnlineJudge/dp/DSL_3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/SlidingWindowMinimum.hpp\"\ntemplate <class T>\nvector<T>\
    \ sliding_window_minimum(const vector<T> &a, int k) {\n    int n = int(a.size());\n\
    \    if (n < k) return {};\n    deque<int> q;\n    vector<T> res(n - k + 1);\n\
    \    rep(i, k) {\n        while (!q.empty() and a[q.back()] >= a[i]) {\n     \
    \       q.pop_back();\n        }\n        q.emplace_back(i);\n    }\n\n    rep(i,\
    \ n - k + 1) {\n        res[i] = a[q.front()];\n        if (i == q.front()) q.pop_front();\n\
    \        while (!q.empty() and a[q.back()] >= a[i + k]) {\n            q.pop_back();\n\
    \        }\n        q.emplace_back(i + k);\n    }\n\n    return res;\n}\n"
  code: "template <class T>\nvector<T> sliding_window_minimum(const vector<T> &a,\
    \ int k) {\n    int n = int(a.size());\n    if (n < k) return {};\n    deque<int>\
    \ q;\n    vector<T> res(n - k + 1);\n    rep(i, k) {\n        while (!q.empty()\
    \ and a[q.back()] >= a[i]) {\n            q.pop_back();\n        }\n        q.emplace_back(i);\n\
    \    }\n\n    rep(i, n - k + 1) {\n        res[i] = a[q.front()];\n        if\
    \ (i == q.front()) q.pop_front();\n        while (!q.empty() and a[q.back()] >=\
    \ a[i + k]) {\n            q.pop_back();\n        }\n        q.emplace_back(i\
    \ + k);\n    }\n\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/SlidingWindowMinimum.hpp
  requiredBy: []
  timestamp: '2025-10-01 01:04:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/dp/DSL_3_D.test.cpp
documentation_of: dp/SlidingWindowMinimum.hpp
layout: document
title: Sliding Window (Minimum)
---

## 概要
todo

## 計算量
todo