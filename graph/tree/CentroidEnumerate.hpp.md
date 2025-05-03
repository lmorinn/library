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
  bundledCode: "#line 1 \"graph/tree/CentroidEnumerate.hpp\"\nvector<int> Centroid(const\
    \ vector<vector<int>> &g) {\n    int n = int(g.size());\n\n    vector<int> centroids;\n\
    \    vector<int> subtree_size(n, 1);\n    auto dfs = [&](int u, int prev) {\n\
    \        bool is_centroid = true;\n\n        for (auto v : g[u]) {\n         \
    \   if (v != prev) {\n                dfs(v, u);\n                subtree_size[u]\
    \ += subtree_size[v];\n                if (subtree_size[v] > n / 2) is_centroid\
    \ = false;\n            }\n        }\n        if (n - subtree_size[u] > n / 2)\
    \ is_centroid = false;\n        if (is_centroid) centroids.emplace_back(u);\n\
    \    };\n\n    dfs(0, -1);\n    return centroids;\n}\n"
  code: "vector<int> Centroid(const vector<vector<int>> &g) {\n    int n = int(g.size());\n\
    \n    vector<int> centroids;\n    vector<int> subtree_size(n, 1);\n    auto dfs\
    \ = [&](int u, int prev) {\n        bool is_centroid = true;\n\n        for (auto\
    \ v : g[u]) {\n            if (v != prev) {\n                dfs(v, u);\n    \
    \            subtree_size[u] += subtree_size[v];\n                if (subtree_size[v]\
    \ > n / 2) is_centroid = false;\n            }\n        }\n        if (n - subtree_size[u]\
    \ > n / 2) is_centroid = false;\n        if (is_centroid) centroids.emplace_back(u);\n\
    \    };\n\n    dfs(0, -1);\n    return centroids;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/CentroidEnumerate.hpp
  requiredBy: []
  timestamp: '2025-05-03 16:51:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/CentroidEnumerate.hpp
layout: document
title: Centroid Enumerate
---

## 概要

todo

## 計算量
todo