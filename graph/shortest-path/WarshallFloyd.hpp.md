---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
    title: verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/WarshallFloyd.hpp\"\ntemplate <class\
    \ T>\nvector<vector<T>> warshallFloyd(vector<vector<pair<int, int>>> &g) {\n \
    \ int n = g.size();\n  T inf = numeric_limits<T>::max();\n  vector<vector<T>>\
    \ a(n, vector<T>(n, inf));\n  for (int i = 0; i < n; i++) {\n    a[i][i] = 0;\n\
    \    for (auto p : g[i]) {\n      a[i][p.first] = p.second;\n    }\n  }\n  for\
    \ (int k = 0; k < n; k++) {\n    for (int i = 0; i < n; i++) {\n      for (int\
    \ j = 0; j < n; j++) {\n        if (a[i][k] == inf or a[k][j] == inf) continue;\n\
    \        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);\n      }\n    }\n  }\n  return\
    \ a;\n}\n\ntemplate <class T>\nvector<vector<T>> warshallFloyd(vector<vector<int>>\
    \ g) {\n  int n = g.size();\n  T inf = numeric_limits<T>::max();\n  for (int i\
    \ = 0; i < n; i++) {\n    for (int j = 0; j < n; j++) {\n      if (g[i][j] < 0)\
    \ g[i][j] = inf;\n    }\n  }\n  for (int k = 0; k < n; k++) {\n    for (int i\
    \ = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n        if (g[i][k]\
    \ == inf or g[k][j] == inf) continue;\n        g[i][j] = min(g[i][j], g[i][k]\
    \ + g[k][j]);\n      }\n    }\n  }\n  return g;\n}\n"
  code: "#pragma once\ntemplate <class T>\nvector<vector<T>> warshallFloyd(vector<vector<pair<int,\
    \ int>>> &g) {\n  int n = g.size();\n  T inf = numeric_limits<T>::max();\n  vector<vector<T>>\
    \ a(n, vector<T>(n, inf));\n  for (int i = 0; i < n; i++) {\n    a[i][i] = 0;\n\
    \    for (auto p : g[i]) {\n      a[i][p.first] = p.second;\n    }\n  }\n  for\
    \ (int k = 0; k < n; k++) {\n    for (int i = 0; i < n; i++) {\n      for (int\
    \ j = 0; j < n; j++) {\n        if (a[i][k] == inf or a[k][j] == inf) continue;\n\
    \        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);\n      }\n    }\n  }\n  return\
    \ a;\n}\n\ntemplate <class T>\nvector<vector<T>> warshallFloyd(vector<vector<int>>\
    \ g) {\n  int n = g.size();\n  T inf = numeric_limits<T>::max();\n  for (int i\
    \ = 0; i < n; i++) {\n    for (int j = 0; j < n; j++) {\n      if (g[i][j] < 0)\
    \ g[i][j] = inf;\n    }\n  }\n  for (int k = 0; k < n; k++) {\n    for (int i\
    \ = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n        if (g[i][k]\
    \ == inf or g[k][j] == inf) continue;\n        g[i][j] = min(g[i][j], g[i][k]\
    \ + g[k][j]);\n      }\n    }\n  }\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest-path/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2024-06-26 17:11:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
documentation_of: graph/shortest-path/WarshallFloyd.hpp
layout: document
title: Warshall Floyd
---

## 概要

todo

## 計算量
todo