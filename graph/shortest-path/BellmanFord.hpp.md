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
  bundledCode: "#line 1 \"graph/shortest-path/BellmanFord.hpp\"\ntemplate <class Cost>\n\
    class BellmanFord {\n private:\n  int n;\n  vector<tuple<int, int, Cost>> edges;\n\
    \n public:\n  vector<Cost> dist;\n  Cost mx;\n  BellmanFord() {}\n  BellmanFord(int\
    \ n) : n(n) {\n    mx = numeric_limits<Cost>::max();\n  }\n\n  void add_edge(int\
    \ u, int v, Cost c) {\n    assert(0 <= u and u < n and 0 <= v and v < n);\n  \
    \  edges.emplace_back(u, v, c);\n  }\n\n  bool shortest_path(int s) {\n    assert(0\
    \ <= s and s < n);\n    dist.assign(n, mx);\n    dist[s] = 0;\n    for (int i\
    \ = 0; i < n - 1; i++) {\n      for (const auto& [u, v, c] : edges) {\n      \
    \  if (dist[u] != mx and dist[v] > dist[u] + c) dist[v] = dist[u] + c;\n     \
    \ }\n    }\n    for (const auto& [u, v, c] : edges) {\n      if (dist[u] != mx\
    \ and dist[u] + c < dist[v]) {\n        return false;\n      }\n    }\n    return\
    \ true;\n  }\n};\n"
  code: "template <class Cost>\nclass BellmanFord {\n private:\n  int n;\n  vector<tuple<int,\
    \ int, Cost>> edges;\n\n public:\n  vector<Cost> dist;\n  Cost mx;\n  BellmanFord()\
    \ {}\n  BellmanFord(int n) : n(n) {\n    mx = numeric_limits<Cost>::max();\n \
    \ }\n\n  void add_edge(int u, int v, Cost c) {\n    assert(0 <= u and u < n and\
    \ 0 <= v and v < n);\n    edges.emplace_back(u, v, c);\n  }\n\n  bool shortest_path(int\
    \ s) {\n    assert(0 <= s and s < n);\n    dist.assign(n, mx);\n    dist[s] =\
    \ 0;\n    for (int i = 0; i < n - 1; i++) {\n      for (const auto& [u, v, c]\
    \ : edges) {\n        if (dist[u] != mx and dist[v] > dist[u] + c) dist[v] = dist[u]\
    \ + c;\n      }\n    }\n    for (const auto& [u, v, c] : edges) {\n      if (dist[u]\
    \ != mx and dist[u] + c < dist[v]) {\n        return false;\n      }\n    }\n\
    \    return true;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest-path/BellmanFord.hpp
  requiredBy: []
  timestamp: '2026-05-07 15:15:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest-path/BellmanFord.hpp
layout: document
title: Bellman Ford
---

## 概要

todo
