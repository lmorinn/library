---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/others/LowLink.hpp
    title: Low Link
  _extendedRequiredBy: []
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
    \    }\n};\n#line 2 \"graph/connected-components/TwoEdgeConnectedComponents.hpp\"\
    \n\nclass TwoEdgeConnectedComponents {\n   private:\n    int n;\n    int m;\n\
    \    int eid;\n    vector<pair<int, int>> edges;\n    LowLink l;\n\n    void dfs(int\
    \ v, int prev, int prev_eid, const vector<bool> &is_bridge, int cid) {\n     \
    \   cmp[v] = cid;\n        for (auto &[nex, eid] : l.g[v]) {\n            if (cmp[nex]\
    \ == -1 and !is_bridge[eid]) {\n                dfs(nex, v, eid, is_bridge, cid);\n\
    \            }\n        }\n    }\n\n   public:\n    vector<int> cmp;\n    vector<vector<int>>\
    \ components;\n\n    TwoEdgeConnectedComponents(int _n) : n(_n), l(_n), eid(0)\
    \ {\n        cmp.assign(n, -1);\n    }\n\n    void add_edge(int u, int v) {\n\
    \        l.add_edge(u, v, eid);\n        edges.emplace_back(u, v);\n        eid++;\n\
    \    }\n\n    void build() {\n        l.build();\n        vector<bool> is_bridge(eid,\
    \ false);\n        for (int id : l.bridge) is_bridge[id] = true;\n\n        int\
    \ cid = 0;\n        for (int i = 0; i < n; i++) {\n            if (cmp[i] == -1)\
    \ {\n                dfs(i, -1, -1, is_bridge, cid++);\n            }\n      \
    \  }\n        components.resize(cid);\n        for (int i = 0; i < n; i++) {\n\
    \            components[cmp[i]].push_back(i);\n        }\n    }\n};\n"
  code: "#include \"../others/LowLink.hpp\"\n\nclass TwoEdgeConnectedComponents {\n\
    \   private:\n    int n;\n    int m;\n    int eid;\n    vector<pair<int, int>>\
    \ edges;\n    LowLink l;\n\n    void dfs(int v, int prev, int prev_eid, const\
    \ vector<bool> &is_bridge, int cid) {\n        cmp[v] = cid;\n        for (auto\
    \ &[nex, eid] : l.g[v]) {\n            if (cmp[nex] == -1 and !is_bridge[eid])\
    \ {\n                dfs(nex, v, eid, is_bridge, cid);\n            }\n      \
    \  }\n    }\n\n   public:\n    vector<int> cmp;\n    vector<vector<int>> components;\n\
    \n    TwoEdgeConnectedComponents(int _n) : n(_n), l(_n), eid(0) {\n        cmp.assign(n,\
    \ -1);\n    }\n\n    void add_edge(int u, int v) {\n        l.add_edge(u, v, eid);\n\
    \        edges.emplace_back(u, v);\n        eid++;\n    }\n\n    void build()\
    \ {\n        l.build();\n        vector<bool> is_bridge(eid, false);\n       \
    \ for (int id : l.bridge) is_bridge[id] = true;\n\n        int cid = 0;\n    \
    \    for (int i = 0; i < n; i++) {\n            if (cmp[i] == -1) {\n        \
    \        dfs(i, -1, -1, is_bridge, cid++);\n            }\n        }\n       \
    \ components.resize(cid);\n        for (int i = 0; i < n; i++) {\n           \
    \ components[cmp[i]].push_back(i);\n        }\n    }\n};"
  dependsOn:
  - graph/others/LowLink.hpp
  isVerificationFile: false
  path: graph/connected-components/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '2024-12-02 00:38:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
documentation_of: graph/connected-components/TwoEdgeConnectedComponents.hpp
layout: document
title: Two Edge Connected Components
---

## 概要

todo

## 計算量
todo