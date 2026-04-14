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

グラフの全点対最短距離を求める。

## 関数

```cpp
(1) template <class T>
    vector<vector<T>> warshallFloyd(vector<vector<pair<int, int>>>& g)

(2) template <class T>
    vector<vector<T>> warshallFloyd(vector<vector<int>> g)
```

- (1) 隣接リスト形式の有向グラフ `g` を受け取り、全点対最短距離を返す。`g[u]` は頂点 `u` からの辺 `(to, cost)` の列とする。
- (2) 隣接行列 `g` を受け取り、全点対最短距離を返す。`g[i][j] < 0` のとき、頂点 `i` から頂点 `j` への辺が存在しないものとして扱う。

返り値の `i` 行 `j` 列は頂点 `i` から頂点 `j` への最短距離を表す。到達できないときは `numeric_limits<T>::max()` となる。

### 制約
- テンプレート引数 `T` は加算と比較ができる

### 計算量
- $O(n^3)$
