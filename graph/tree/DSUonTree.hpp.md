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
  bundledCode: "#line 1 \"graph/tree/DSUonTree.hpp\"\n// add(c): \u9802\u70B9 c \u306E\
    \u60C5\u5831\u3092\u30C6\u30FC\u30D6\u30EB\u306B\u8FFD\u52A0\u3059\u308B\n// query(c):\
    \ \u9802\u70B9 c \u306E\u90E8\u5206\u6728\u5168\u4F53\u306E\u60C5\u5831\u304C\u8F09\
    \u3063\u305F\u30C6\u30FC\u30D6\u30EB\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B\n// reset(): \u30C6\u30FC\u30D6\u30EB\u3092\u30EA\u30BB\
    \u30C3\u30C8\u3059\u308B\ntemplate <auto add, auto query, auto reset>\nstruct\
    \ dsu_on_tree {\n private:\n  int n, root, edge;\n  vector<vector<int>> g;\n \
    \ int dfs(int cur, int prev) {\n    int sub = 1;\n    for (int& nex : g[cur])\
    \ {\n      if (nex == prev) {\n        swap(g[cur].back(), nex);\n        g[cur].pop_back();\n\
    \        break;\n      }\n    }\n    int best = 0;\n    int idx = -1;\n    for\
    \ (int i = 0; i < int(g[cur].size()); i++) {\n      int cnt = dfs(g[cur][i], cur);\n\
    \      sub += cnt;\n      if (best < cnt) {\n        best = cnt;\n        idx\
    \ = i;\n      }\n    }\n    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());\n\
    \    return sub;\n  }\n\n  void dfs2(int cur) {\n    for (int nex : g[cur]) dfs2(nex);\n\
    \    add(cur);\n  }\n\n  void build() {\n    int id = 0;\n    dfs(root, -1);\n\
    \  }\n\n public:\n  dsu_on_tree(int n, int root = 0) : n(n), root(root), edge(0),\
    \ g(n) {}\n\n  void add_edge(int u, int v) {\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n\
    \    edge++;\n    if (edge == n - 1) build();\n  }\n\n  void calc(int cur) {\n\
    \    for (int i = 1; i < int(g[cur].size()); i++) {\n      calc(g[cur][i]);\n\
    \      reset();\n    }\n    if (!g[cur].empty()) calc(g[cur].front());\n    for\
    \ (int i = 1; i < int(g[cur].size()); i++) dfs2(g[cur][i]);\n    add(cur);\n \
    \   query(cur);\n  }\n};\n"
  code: "// add(c): \u9802\u70B9 c \u306E\u60C5\u5831\u3092\u30C6\u30FC\u30D6\u30EB\
    \u306B\u8FFD\u52A0\u3059\u308B\n// query(c): \u9802\u70B9 c \u306E\u90E8\u5206\
    \u6728\u5168\u4F53\u306E\u60C5\u5831\u304C\u8F09\u3063\u305F\u30C6\u30FC\u30D6\
    \u30EB\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n// reset():\
    \ \u30C6\u30FC\u30D6\u30EB\u3092\u30EA\u30BB\u30C3\u30C8\u3059\u308B\ntemplate\
    \ <auto add, auto query, auto reset>\nstruct dsu_on_tree {\n private:\n  int n,\
    \ root, edge;\n  vector<vector<int>> g;\n  int dfs(int cur, int prev) {\n    int\
    \ sub = 1;\n    for (int& nex : g[cur]) {\n      if (nex == prev) {\n        swap(g[cur].back(),\
    \ nex);\n        g[cur].pop_back();\n        break;\n      }\n    }\n    int best\
    \ = 0;\n    int idx = -1;\n    for (int i = 0; i < int(g[cur].size()); i++) {\n\
    \      int cnt = dfs(g[cur][i], cur);\n      sub += cnt;\n      if (best < cnt)\
    \ {\n        best = cnt;\n        idx = i;\n      }\n    }\n    if (!g[cur].empty())\
    \ swap(g[cur][idx], g[cur].front());\n    return sub;\n  }\n\n  void dfs2(int\
    \ cur) {\n    for (int nex : g[cur]) dfs2(nex);\n    add(cur);\n  }\n\n  void\
    \ build() {\n    int id = 0;\n    dfs(root, -1);\n  }\n\n public:\n  dsu_on_tree(int\
    \ n, int root = 0) : n(n), root(root), edge(0), g(n) {}\n\n  void add_edge(int\
    \ u, int v) {\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n    edge++;\n\
    \    if (edge == n - 1) build();\n  }\n\n  void calc(int cur) {\n    for (int\
    \ i = 1; i < int(g[cur].size()); i++) {\n      calc(g[cur][i]);\n      reset();\n\
    \    }\n    if (!g[cur].empty()) calc(g[cur].front());\n    for (int i = 1; i\
    \ < int(g[cur].size()); i++) dfs2(g[cur][i]);\n    add(cur);\n    query(cur);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/DSUonTree.hpp
  requiredBy: []
  timestamp: '2026-07-03 11:19:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/DSUonTree.hpp
layout: document
title: DSU on Tree
---

## 概要

todo

## 計算量
todo