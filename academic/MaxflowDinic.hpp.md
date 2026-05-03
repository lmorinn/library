---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/flow/GRL_6_A_2.test.cpp
    title: verify/AizuOnlineJudge/graph/flow/GRL_6_A_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"academic/MaxflowDinic.hpp\"\ntemplate <class Cap>\nclass\
    \ max_flow {\n private:\n  struct Edge {\n    int from, to;\n    Cap cap, flow;\n\
    \    int rev;\n  };\n\n  vector<pair<int, int>> edge_id;\n  vector<vector<Edge>>\
    \ g;\n  int n;\n\n public:\n  max_flow(int n) : n(n) {\n    g.resize(n);\n  }\n\
    \n  void add_edge(int from, int to, Cap cap) {\n    assert(from != to);\n    int\
    \ from_id = int(g[from].size());\n    int to_id = int(g[to].size());\n    edge_id.emplace_back(from,\
    \ from_id);\n    g[from].push_back({from, to, cap, 0, to_id});\n    g[to].push_back({to,\
    \ from, cap, cap, from_id});\n  }\n\n  const Edge& get_edge(int id) {\n    auto\
    \ [vid, eid] = edge_id[id];\n    return g[vid][eid];\n  }\n\n  Cap flow(int s,\
    \ int t) {\n    Cap res = 0;\n    vector<int> iter(n, -1);\n    vector<int> dist(n,\
    \ -1);\n\n    auto bfs = [&](int s) -> void {\n      fill(dist.begin(), dist.end(),\
    \ -1);\n      queue<int> q;\n      dist[s] = 0;\n      q.push(s);\n      while\
    \ (!q.empty()) {\n        int cur = q.front();\n        q.pop();\n        for\
    \ (int i = 0; i < int(g[cur].size()); i++) {\n          Edge& edge = g[cur][i];\n\
    \          if (edge.cap - edge.flow <= 0 or dist[edge.to] != -1) continue;\n \
    \         dist[edge.to] = dist[cur] + 1;\n          q.push(edge.to);\n       \
    \ }\n      }\n    };\n\n    auto dfs = [&](auto& self, int cur, Cap epsilon) ->\
    \ Cap {\n      if (cur == t) return epsilon;\n      for (int& i = iter[cur]; i\
    \ < int(g[cur].size()); i++) {\n        Edge& edge = g[cur][i];\n        if (edge.cap\
    \ - edge.flow <= 0 or dist[cur] >= dist[edge.to]) continue;\n        Cap d = self(self,\
    \ edge.to, min(epsilon, edge.cap - edge.flow));\n        if (d > 0) {\n      \
    \    edge.flow += d;\n          g[edge.to][edge.rev].flow -= d;\n          return\
    \ d;\n        }\n      }\n      return 0;\n    };\n\n    while (1) {\n      bfs(s);\n\
    \      if (dist[t] < 0) break;\n      fill(iter.begin(), iter.end(), 0);\n   \
    \   Cap f;\n      while (f = dfs(dfs, s, numeric_limits<Cap>::max())) res += f;\n\
    \    }\n\n    return res;\n  }\n\n  vector<bool> min_cut(int s) {\n    vector<bool>\
    \ reachable(n, false);\n    auto dfs = [&](auto& self, int cur) -> void {\n  \
    \    reachable[cur] = true;\n      for (int i = 0; i < int(g[cur].size()); i++)\
    \ {\n        const Edge& edge = g[cur][i];\n        if (edge.cap - edge.flow <=\
    \ 0 or reachable[edge.to]) continue;\n        self(self, edge.to);\n      }\n\
    \    };\n    dfs(dfs, s);\n    return reachable;\n  }\n};\n"
  code: "template <class Cap>\nclass max_flow {\n private:\n  struct Edge {\n    int\
    \ from, to;\n    Cap cap, flow;\n    int rev;\n  };\n\n  vector<pair<int, int>>\
    \ edge_id;\n  vector<vector<Edge>> g;\n  int n;\n\n public:\n  max_flow(int n)\
    \ : n(n) {\n    g.resize(n);\n  }\n\n  void add_edge(int from, int to, Cap cap)\
    \ {\n    assert(from != to);\n    int from_id = int(g[from].size());\n    int\
    \ to_id = int(g[to].size());\n    edge_id.emplace_back(from, from_id);\n    g[from].push_back({from,\
    \ to, cap, 0, to_id});\n    g[to].push_back({to, from, cap, cap, from_id});\n\
    \  }\n\n  const Edge& get_edge(int id) {\n    auto [vid, eid] = edge_id[id];\n\
    \    return g[vid][eid];\n  }\n\n  Cap flow(int s, int t) {\n    Cap res = 0;\n\
    \    vector<int> iter(n, -1);\n    vector<int> dist(n, -1);\n\n    auto bfs =\
    \ [&](int s) -> void {\n      fill(dist.begin(), dist.end(), -1);\n      queue<int>\
    \ q;\n      dist[s] = 0;\n      q.push(s);\n      while (!q.empty()) {\n     \
    \   int cur = q.front();\n        q.pop();\n        for (int i = 0; i < int(g[cur].size());\
    \ i++) {\n          Edge& edge = g[cur][i];\n          if (edge.cap - edge.flow\
    \ <= 0 or dist[edge.to] != -1) continue;\n          dist[edge.to] = dist[cur]\
    \ + 1;\n          q.push(edge.to);\n        }\n      }\n    };\n\n    auto dfs\
    \ = [&](auto& self, int cur, Cap epsilon) -> Cap {\n      if (cur == t) return\
    \ epsilon;\n      for (int& i = iter[cur]; i < int(g[cur].size()); i++) {\n  \
    \      Edge& edge = g[cur][i];\n        if (edge.cap - edge.flow <= 0 or dist[cur]\
    \ >= dist[edge.to]) continue;\n        Cap d = self(self, edge.to, min(epsilon,\
    \ edge.cap - edge.flow));\n        if (d > 0) {\n          edge.flow += d;\n \
    \         g[edge.to][edge.rev].flow -= d;\n          return d;\n        }\n  \
    \    }\n      return 0;\n    };\n\n    while (1) {\n      bfs(s);\n      if (dist[t]\
    \ < 0) break;\n      fill(iter.begin(), iter.end(), 0);\n      Cap f;\n      while\
    \ (f = dfs(dfs, s, numeric_limits<Cap>::max())) res += f;\n    }\n\n    return\
    \ res;\n  }\n\n  vector<bool> min_cut(int s) {\n    vector<bool> reachable(n,\
    \ false);\n    auto dfs = [&](auto& self, int cur) -> void {\n      reachable[cur]\
    \ = true;\n      for (int i = 0; i < int(g[cur].size()); i++) {\n        const\
    \ Edge& edge = g[cur][i];\n        if (edge.cap - edge.flow <= 0 or reachable[edge.to])\
    \ continue;\n        self(self, edge.to);\n      }\n    };\n    dfs(dfs, s);\n\
    \    return reachable;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: academic/MaxflowDinic.hpp
  requiredBy: []
  timestamp: '2026-05-03 20:10:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/flow/GRL_6_A_2.test.cpp
documentation_of: academic/MaxflowDinic.hpp
layout: document
title: "Maxflow (Dinic\u6CD5)"
---

## 概要

todo