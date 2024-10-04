---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/connectivity/OfflineDynamicConnectivityDFS.hpp
    title: Offline Dynamic Connectivity (DSU base)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
    title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find/UndoableUnionFind.hpp\"\n\ntemplate\
    \ <class S, auto op, auto e>\nclass UndoableUnionFind {\n private:\n  struct HistoryData\
    \ {\n    int u, datu;\n    S accu;\n    int v, datv;\n    S accv;\n    int comp_cnt;\n\
    \  };\n\n  vector<int> data;\n  vector<S> acc;\n  stack<HistoryData> history;\n\
    \  int cnt;\n  int snap;\n\n public:\n  UndoableUnionFind() {}\n  UndoableUnionFind(int\
    \ sz) {\n    data.assign(sz, -1);\n    cnt = sz;\n    acc.resize(sz, e());\n \
    \ }\n\n  bool unite(int u, int v) {\n    u = find(u), v = find(v);\n    history.emplace(u,\
    \ data[u], acc[u], v, data[v], acc[v], cnt);\n    if (u == v) return false;\n\
    \    if (data[u] > data[v]) swap(u, v);\n    data[u] += data[v];\n    data[v]\
    \ = u;\n    acc[u] = op(acc[u], acc[v]);\n    cnt--;\n    return true;\n  }\n\n\
    \  int find(int k) {\n    while (data[k] >= 0) {\n      k = data[k];\n    }\n\
    \    return k;\n  }\n\n  void update(int a, S x) {\n    a = find(a);\n    history.push({a,\
    \ data[a], acc[a], -1, -1, e(), -1});\n    acc[a] = op(acc[a], x);\n  }\n\n  S\
    \ prod_components(int a) {\n    return acc[find(a)];\n  }\n\n  bool same(int x,\
    \ int y) { return find(x) == find(y); }\n\n  int size(int k) { return (-data[find(k)]);\
    \ }\n\n  void undo() {\n    HistoryData h = history.top();\n    history.pop();\n\
    \    data[h.u] = h.datu;\n    acc[h.u] = h.accu;\n    if (h.v != -1) {\n     \
    \ data[h.v] = h.datv;\n      acc[h.v] = h.accv;\n      cnt = h.comp_cnt;\n   \
    \ }\n  }\n\n  int components() {\n    return cnt;\n  }\n};\n"
  code: "\ntemplate <class S, auto op, auto e>\nclass UndoableUnionFind {\n private:\n\
    \  struct HistoryData {\n    int u, datu;\n    S accu;\n    int v, datv;\n   \
    \ S accv;\n    int comp_cnt;\n  };\n\n  vector<int> data;\n  vector<S> acc;\n\
    \  stack<HistoryData> history;\n  int cnt;\n  int snap;\n\n public:\n  UndoableUnionFind()\
    \ {}\n  UndoableUnionFind(int sz) {\n    data.assign(sz, -1);\n    cnt = sz;\n\
    \    acc.resize(sz, e());\n  }\n\n  bool unite(int u, int v) {\n    u = find(u),\
    \ v = find(v);\n    history.emplace(u, data[u], acc[u], v, data[v], acc[v], cnt);\n\
    \    if (u == v) return false;\n    if (data[u] > data[v]) swap(u, v);\n    data[u]\
    \ += data[v];\n    data[v] = u;\n    acc[u] = op(acc[u], acc[v]);\n    cnt--;\n\
    \    return true;\n  }\n\n  int find(int k) {\n    while (data[k] >= 0) {\n  \
    \    k = data[k];\n    }\n    return k;\n  }\n\n  void update(int a, S x) {\n\
    \    a = find(a);\n    history.push({a, data[a], acc[a], -1, -1, e(), -1});\n\
    \    acc[a] = op(acc[a], x);\n  }\n\n  S prod_components(int a) {\n    return\
    \ acc[find(a)];\n  }\n\n  bool same(int x, int y) { return find(x) == find(y);\
    \ }\n\n  int size(int k) { return (-data[find(k)]); }\n\n  void undo() {\n   \
    \ HistoryData h = history.top();\n    history.pop();\n    data[h.u] = h.datu;\n\
    \    acc[h.u] = h.accu;\n    if (h.v != -1) {\n      data[h.v] = h.datv;\n   \
    \   acc[h.v] = h.accv;\n      cnt = h.comp_cnt;\n    }\n  }\n\n  int components()\
    \ {\n    return cnt;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find/UndoableUnionFind.hpp
  requiredBy:
  - graph/connectivity/OfflineDynamicConnectivityDFS.hpp
  timestamp: '2024-10-04 18:45:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
documentation_of: data-structure/union-find/UndoableUnionFind.hpp
layout: document
title: Undoable Union Find
---

## 概要

todo

## 計算量
todo