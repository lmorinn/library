---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/TwoEdgeConnectedComponents.hpp
    title: Two Edge Connected Components
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
    title: verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/others/LowLink.hpp\"\nclass LowLink {\n   public:\n\
    \    int n, time;\n    vector<vector<pair<int, int>>> g;\n    vector<bool> seen;\n\
    \    vector<int> order, low;\n    vector<int> articulation;\n    vector<int> bridge;\n\
    \n    LowLink(int _n) : n(_n), time(0) {\n        g.resize(n);\n        seen.assign(n,\
    \ false);\n        order.assign(n, -1);\n        low.assign(n, 0);\n    }\n\n\
    \    void add_edge(int u, int v, int eid) {\n        g[u].emplace_back(v, eid);\n\
    \        g[v].emplace_back(u, eid);\n    }\n\n    void dfs(int cur, int prev,\
    \ int prev_eid) {\n        seen[cur] = true;\n        order[cur] = low[cur] =\
    \ time++;\n        int child = 0;\n        bool is_articulation = false;\n   \
    \     for (auto &[nex, eid] : g[cur]) {\n            if (!seen[nex]) {\n     \
    \           child++;\n                dfs(nex, cur, eid);\n                low[cur]\
    \ = min(low[cur], low[nex]);\n                if (prev != -1 and order[cur] <=\
    \ low[nex]) is_articulation = true;\n                if (order[cur] < low[nex])\
    \ bridge.push_back(eid);\n            } else if (eid != prev_eid) {\n        \
    \        low[cur] = min(low[cur], order[nex]);\n            }\n        }\n   \
    \     if (prev == -1 and child > 1) is_articulation = true;\n        if (is_articulation)\
    \ articulation.push_back(cur);\n    }\n\n    void build() {\n        for (int\
    \ i = 0; i < n; i++) {\n            if (!seen[i]) dfs(i, -1, -1);\n        }\n\
    \    }\n};\n"
  code: "class LowLink {\n   public:\n    int n, time;\n    vector<vector<pair<int,\
    \ int>>> g;\n    vector<bool> seen;\n    vector<int> order, low;\n    vector<int>\
    \ articulation;\n    vector<int> bridge;\n\n    LowLink(int _n) : n(_n), time(0)\
    \ {\n        g.resize(n);\n        seen.assign(n, false);\n        order.assign(n,\
    \ -1);\n        low.assign(n, 0);\n    }\n\n    void add_edge(int u, int v, int\
    \ eid) {\n        g[u].emplace_back(v, eid);\n        g[v].emplace_back(u, eid);\n\
    \    }\n\n    void dfs(int cur, int prev, int prev_eid) {\n        seen[cur] =\
    \ true;\n        order[cur] = low[cur] = time++;\n        int child = 0;\n   \
    \     bool is_articulation = false;\n        for (auto &[nex, eid] : g[cur]) {\n\
    \            if (!seen[nex]) {\n                child++;\n                dfs(nex,\
    \ cur, eid);\n                low[cur] = min(low[cur], low[nex]);\n          \
    \      if (prev != -1 and order[cur] <= low[nex]) is_articulation = true;\n  \
    \              if (order[cur] < low[nex]) bridge.push_back(eid);\n           \
    \ } else if (eid != prev_eid) {\n                low[cur] = min(low[cur], order[nex]);\n\
    \            }\n        }\n        if (prev == -1 and child > 1) is_articulation\
    \ = true;\n        if (is_articulation) articulation.push_back(cur);\n    }\n\n\
    \    void build() {\n        for (int i = 0; i < n; i++) {\n            if (!seen[i])\
    \ dfs(i, -1, -1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/others/LowLink.hpp
  requiredBy:
  - graph/connected-components/TwoEdgeConnectedComponents.hpp
  timestamp: '2024-12-02 00:38:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
documentation_of: graph/others/LowLink.hpp
layout: document
title: Low Link
---

## 概要

todo

## 計算量
todo