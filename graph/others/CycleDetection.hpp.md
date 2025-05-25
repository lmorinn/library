---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
    title: verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/others/CycleDetectionUndirected.test.cpp
    title: verify/LibraryChecker/graph/others/CycleDetectionUndirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/others/CycleDetection.hpp\"\ntemplate <class T>\n\
    class CycleDetection {\n   private:\n    struct Edge {\n        int from = -1,\
    \ to = -1;\n        T val;\n        Edge() {}\n        Edge(int f, int t, T v)\
    \ {\n            from = f;\n            to = t;\n            val = v;\n      \
    \  }\n    };\n\n    vector<vector<Edge>> g;\n    vector<unordered_map<int, int>>\
    \ undirected_id;\n    int n;\n    bool is_directed;\n    bool ud_two_edge_cycle\
    \ = false;\n    stack<Edge> history;\n    pair<int, int> two_v;\n    T two_e;\n\
    \    vector<bool> seen, finished;\n\n    int dfs(int cur, Edge cur_e, bool is_prohibit_reverse)\
    \ {\n        seen[cur] = true;\n        history.emplace(cur_e);\n        for (const\
    \ Edge &nex : g[cur]) {\n            if (is_prohibit_reverse and cur_e.from ==\
    \ nex.to) continue;\n            if (finished[nex.to]) continue;\n           \
    \ if (seen[nex.to] and !finished[nex.to]) {\n                history.emplace(nex);\n\
    \                return nex.to;\n            }\n            int pos = dfs(nex.to,\
    \ nex, is_prohibit_reverse);\n            if (pos != -1) return pos;\n       \
    \ }\n        finished[cur] = true;\n        history.pop();\n        return -1;\n\
    \    }\n\n    vector<Edge> reconstruct(int pos) {\n        vector<Edge> cycle;\n\
    \        while (!history.empty()) {\n            const Edge &e = history.top();\n\
    \            history.pop();\n            cycle.emplace_back(e);\n            if\
    \ (e.from == pos) break;\n        }\n        reverse(cycle.begin(), cycle.end());\n\
    \        return cycle;\n    }\n\n    vector<Edge> detect(bool is_prohibit_reverse\
    \ = true) {\n        seen.assign(n, false);\n        finished.assign(n, false);\n\
    \        int pos = -1;\n        for (int cur = 0; cur < n and pos == -1; cur++)\
    \ {\n            if (seen[cur]) continue;\n            while (!history.empty())\
    \ history.pop();\n            pos = dfs(cur, Edge(), is_prohibit_reverse);\n \
    \           if (pos != -1) return reconstruct(pos);\n        }\n        return\
    \ vector<Edge>();\n    }\n\n   public:\n    CycleDetection(int siz, bool is_directed_graph)\
    \ {\n        n = siz;\n        is_directed = is_directed_graph;\n        g.resize(n);\n\
    \        if (!is_directed) undirected_id.resize(n);\n    }\n\n    void add_edge(int\
    \ u, int v, T w) {\n        if (is_directed) {\n            g[u].emplace_back(Edge(u,\
    \ v, w));\n        } else {\n            if (u > v) swap(u, v);\n            if\
    \ (undirected_id[u].contains(v)) {\n                ud_two_edge_cycle = true;\n\
    \                two_v = {u, v};\n                two_e = w;\n            } else\
    \ {\n                undirected_id[u][v] = w;\n            }\n            g[u].emplace_back(Edge(u,\
    \ v, w));\n            g[v].emplace_back(Edge(v, u, w));\n        }\n    }\n\n\
    \    vector<Edge> cycle() {\n        if (is_directed) {\n            return detect(false);\n\
    \        } else if (ud_two_edge_cycle) {\n            int u = two_v.first;\n \
    \           int v = two_v.second;\n            vector<Edge> res = {Edge(u, v,\
    \ undirected_id[u][v]), Edge(v, u, two_e)};\n            return res;\n       \
    \ } else {\n            return detect(true);\n        }\n    }\n};\n"
  code: "template <class T>\nclass CycleDetection {\n   private:\n    struct Edge\
    \ {\n        int from = -1, to = -1;\n        T val;\n        Edge() {}\n    \
    \    Edge(int f, int t, T v) {\n            from = f;\n            to = t;\n \
    \           val = v;\n        }\n    };\n\n    vector<vector<Edge>> g;\n    vector<unordered_map<int,\
    \ int>> undirected_id;\n    int n;\n    bool is_directed;\n    bool ud_two_edge_cycle\
    \ = false;\n    stack<Edge> history;\n    pair<int, int> two_v;\n    T two_e;\n\
    \    vector<bool> seen, finished;\n\n    int dfs(int cur, Edge cur_e, bool is_prohibit_reverse)\
    \ {\n        seen[cur] = true;\n        history.emplace(cur_e);\n        for (const\
    \ Edge &nex : g[cur]) {\n            if (is_prohibit_reverse and cur_e.from ==\
    \ nex.to) continue;\n            if (finished[nex.to]) continue;\n           \
    \ if (seen[nex.to] and !finished[nex.to]) {\n                history.emplace(nex);\n\
    \                return nex.to;\n            }\n            int pos = dfs(nex.to,\
    \ nex, is_prohibit_reverse);\n            if (pos != -1) return pos;\n       \
    \ }\n        finished[cur] = true;\n        history.pop();\n        return -1;\n\
    \    }\n\n    vector<Edge> reconstruct(int pos) {\n        vector<Edge> cycle;\n\
    \        while (!history.empty()) {\n            const Edge &e = history.top();\n\
    \            history.pop();\n            cycle.emplace_back(e);\n            if\
    \ (e.from == pos) break;\n        }\n        reverse(cycle.begin(), cycle.end());\n\
    \        return cycle;\n    }\n\n    vector<Edge> detect(bool is_prohibit_reverse\
    \ = true) {\n        seen.assign(n, false);\n        finished.assign(n, false);\n\
    \        int pos = -1;\n        for (int cur = 0; cur < n and pos == -1; cur++)\
    \ {\n            if (seen[cur]) continue;\n            while (!history.empty())\
    \ history.pop();\n            pos = dfs(cur, Edge(), is_prohibit_reverse);\n \
    \           if (pos != -1) return reconstruct(pos);\n        }\n        return\
    \ vector<Edge>();\n    }\n\n   public:\n    CycleDetection(int siz, bool is_directed_graph)\
    \ {\n        n = siz;\n        is_directed = is_directed_graph;\n        g.resize(n);\n\
    \        if (!is_directed) undirected_id.resize(n);\n    }\n\n    void add_edge(int\
    \ u, int v, T w) {\n        if (is_directed) {\n            g[u].emplace_back(Edge(u,\
    \ v, w));\n        } else {\n            if (u > v) swap(u, v);\n            if\
    \ (undirected_id[u].contains(v)) {\n                ud_two_edge_cycle = true;\n\
    \                two_v = {u, v};\n                two_e = w;\n            } else\
    \ {\n                undirected_id[u][v] = w;\n            }\n            g[u].emplace_back(Edge(u,\
    \ v, w));\n            g[v].emplace_back(Edge(v, u, w));\n        }\n    }\n\n\
    \    vector<Edge> cycle() {\n        if (is_directed) {\n            return detect(false);\n\
    \        } else if (ud_two_edge_cycle) {\n            int u = two_v.first;\n \
    \           int v = two_v.second;\n            vector<Edge> res = {Edge(u, v,\
    \ undirected_id[u][v]), Edge(v, u, two_e)};\n            return res;\n       \
    \ } else {\n            return detect(true);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/others/CycleDetection.hpp
  requiredBy: []
  timestamp: '2025-05-26 05:25:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
  - verify/LibraryChecker/graph/others/CycleDetectionUndirected.test.cpp
documentation_of: graph/others/CycleDetection.hpp
layout: document
title: Cycle Detection
---

## 概要

todo

## 計算量
todo