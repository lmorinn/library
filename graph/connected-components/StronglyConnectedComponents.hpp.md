---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/others/GraphReachability.hpp
    title: Directed Graph Reachability
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
    title: verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/connected-components/StronglyConnectedComponents.hpp\"\
    \n\nclass SCC {\n   private:\n    vector<vector<int>> g, r;\n    int time;\n \
    \   int n;\n    vector<bool> seen, seen2;\n    vector<int> idx;\n    int component_id;\n\
    \    vector<vector<int>> components;\n\n    void dfs(int cur) {\n        seen[cur]\
    \ = true;\n        for (auto nex : g[cur]) {\n            if (seen[nex] == false)\
    \ {\n                dfs(nex);\n            }\n        }\n        idx[time] =\
    \ cur;\n        time++;\n    }\n\n    void dfs2(int cur) {\n        seen2[cur]\
    \ = true;\n        components[component_id].emplace_back(cur);\n        for (auto\
    \ nex : r[cur]) {\n            if (seen2[nex] == false) {\n                dfs2(nex);\n\
    \            }\n        }\n    }\n\n   public:\n    SCC() {}\n    SCC(int siz)\
    \ {\n        n = siz;\n        g.resize(n);\n        r.resize(n);\n        time\
    \ = 0;\n        component_id = 0;\n        idx.assign(n, -1);\n        seen.assign(n,\
    \ false);\n        seen2.assign(n, false);\n    }\n\n    void add_edge(int u,\
    \ int v) {\n        g[u].emplace_back(v);\n        r[v].emplace_back(u);\n   \
    \ }\n\n    vector<vector<int>> decompose() {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (!seen[i]) {\n                dfs(i);\n            }\n   \
    \     }\n\n        for (int i = time - 1; i >= 0; i--) {\n            if (!seen2[idx[i]])\
    \ {\n                components.emplace_back(vector<int>());\n               \
    \ dfs2(idx[i]);\n                component_id++;\n            }\n        }\n\n\
    \        return components;\n    }\n};\n"
  code: "\nclass SCC {\n   private:\n    vector<vector<int>> g, r;\n    int time;\n\
    \    int n;\n    vector<bool> seen, seen2;\n    vector<int> idx;\n    int component_id;\n\
    \    vector<vector<int>> components;\n\n    void dfs(int cur) {\n        seen[cur]\
    \ = true;\n        for (auto nex : g[cur]) {\n            if (seen[nex] == false)\
    \ {\n                dfs(nex);\n            }\n        }\n        idx[time] =\
    \ cur;\n        time++;\n    }\n\n    void dfs2(int cur) {\n        seen2[cur]\
    \ = true;\n        components[component_id].emplace_back(cur);\n        for (auto\
    \ nex : r[cur]) {\n            if (seen2[nex] == false) {\n                dfs2(nex);\n\
    \            }\n        }\n    }\n\n   public:\n    SCC() {}\n    SCC(int siz)\
    \ {\n        n = siz;\n        g.resize(n);\n        r.resize(n);\n        time\
    \ = 0;\n        component_id = 0;\n        idx.assign(n, -1);\n        seen.assign(n,\
    \ false);\n        seen2.assign(n, false);\n    }\n\n    void add_edge(int u,\
    \ int v) {\n        g[u].emplace_back(v);\n        r[v].emplace_back(u);\n   \
    \ }\n\n    vector<vector<int>> decompose() {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (!seen[i]) {\n                dfs(i);\n            }\n   \
    \     }\n\n        for (int i = time - 1; i >= 0; i--) {\n            if (!seen2[idx[i]])\
    \ {\n                components.emplace_back(vector<int>());\n               \
    \ dfs2(idx[i]);\n                component_id++;\n            }\n        }\n\n\
    \        return components;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/connected-components/StronglyConnectedComponents.hpp
  requiredBy:
  - graph/others/GraphReachability.hpp
  timestamp: '2024-12-07 15:59:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
documentation_of: graph/connected-components/StronglyConnectedComponents.hpp
layout: document
title: Strongly Connected Components
---

## 概要

todo

## 計算量
todo