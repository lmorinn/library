---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/tree/FrequencyTableofTreeDistance.test.cpp
    title: verify/LibraryChecker/graph/tree/FrequencyTableofTreeDistance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/TreeDistanceFreqency.hpp\"\n\nclass TreeDistFreq\
    \ {\n   private:\n    vector<vector<int>> g;\n    vector<bool> dead;\n    int\
    \ n;\n\n    int find_centroid(int root) {\n        static vector<int> subtree_size(g.size());\n\
    \        function<void(int, int)> subtree_size_dp = [&](int u, int prev) {\n \
    \           subtree_size[u] = 1;\n            for (int v : g[u]) {\n         \
    \       if (v != prev and !dead[v]) {\n                    subtree_size_dp(v,\
    \ u);\n                    subtree_size[u] += subtree_size[v];\n             \
    \   }\n            }\n        };\n        subtree_size_dp(root, -1);\n       \
    \ int n = subtree_size[root];\n        function<int(int, int)> dfs = [&](int u,\
    \ int prev) {\n            for (int v : g[u]) {\n                if (v != prev\
    \ and !dead[v]) {\n                    if (subtree_size[v] > n / 2) {\n      \
    \                  return dfs(v, u);\n                    }\n                }\n\
    \            }\n            return u;\n        };\n\n        return dfs(root,\
    \ -1);\n    }\n\n    vector<long long> centroid_decomposition(int start) {\n \
    \       vector<long long> ans(g.size());\n        function<void(int)> rec = [&](int\
    \ start) {\n            int c = find_centroid(start);\n            dead[c] = true;\n\
    \            for (int u : g[c]) {\n                if (!dead[u]) rec(u);\n   \
    \         }\n            vector<vector<long long>> subtree_dist;\n\n         \
    \   int alive_sub = 0;\n            for (int u : g[c]) {\n                if (!dead[u])\
    \ {\n                    subtree_dist.emplace_back();\n                    calc_freq(c,\
    \ u, subtree_dist[alive_sub]);\n                    for (int i = 0; i < int(subtree_dist[alive_sub].size());\
    \ i++) {\n                        ans[i] += subtree_dist[alive_sub][i];\n    \
    \                }\n                    alive_sub++;\n                }\n    \
    \        }\n\n            sort(subtree_dist.begin(), subtree_dist.end(), [](const\
    \ vector<long long> &a, const vector<long long> &b) {\n                return\
    \ int(a.size()) < int(b.size());\n            });\n\n            if (alive_sub\
    \ >= 2) {\n                vector<long long> l = subtree_dist[0];\n          \
    \      for (int i = 0; i < alive_sub - 1; i++) {\n                    int idx\
    \ = 0;\n                    for (long long x : convolution_ll(l, subtree_dist[i\
    \ + 1])) {\n                        ans[idx] += x;\n                        idx++;\n\
    \                        if (idx == n) break;\n                    }\n       \
    \             int nex_size = subtree_dist[i + 1].size();\n                   \
    \ l.resize(nex_size);\n                    for (int j = 0; j < nex_size; j++)\
    \ {\n                        l[j] += subtree_dist[i + 1][j];\n               \
    \     }\n                }\n            }\n            dead[c] = false;\n    \
    \    };\n        rec(0);\n        return ans;\n    }\n\n    void calc_freq(int\
    \ c, int u, vector<long long> &freq) {\n        freq.resize(2);\n        freq[1]\
    \ = 1;\n        auto dfs = [&](auto &&self, int v, int prev, int dist) -> void\
    \ {\n            for (int nex : g[v]) {\n                if (nex != prev and !dead[nex])\
    \ {\n                    if (int(freq.size()) <= dist + 1) {\n               \
    \         freq.emplace_back(1);\n                    } else {\n              \
    \          freq[dist + 1]++;\n                    }\n                    self(self,\
    \ nex, v, dist + 1);\n                }\n            }\n        };\n        dfs(dfs,\
    \ u, c, 1);\n    }\n\n   public:\n    TreeDistFreq(int siz) {\n        n = siz;\n\
    \        g.resize(n);\n        dead.resize(n, false);\n    }\n    TreeDistFreq()\
    \ {}\n\n    void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n   \
    \     g[v].emplace_back(u);\n    }\n\n    vector<long long> get_table() {\n  \
    \      return centroid_decomposition(0);\n    }\n};\n"
  code: "\nclass TreeDistFreq {\n   private:\n    vector<vector<int>> g;\n    vector<bool>\
    \ dead;\n    int n;\n\n    int find_centroid(int root) {\n        static vector<int>\
    \ subtree_size(g.size());\n        function<void(int, int)> subtree_size_dp =\
    \ [&](int u, int prev) {\n            subtree_size[u] = 1;\n            for (int\
    \ v : g[u]) {\n                if (v != prev and !dead[v]) {\n               \
    \     subtree_size_dp(v, u);\n                    subtree_size[u] += subtree_size[v];\n\
    \                }\n            }\n        };\n        subtree_size_dp(root, -1);\n\
    \        int n = subtree_size[root];\n        function<int(int, int)> dfs = [&](int\
    \ u, int prev) {\n            for (int v : g[u]) {\n                if (v != prev\
    \ and !dead[v]) {\n                    if (subtree_size[v] > n / 2) {\n      \
    \                  return dfs(v, u);\n                    }\n                }\n\
    \            }\n            return u;\n        };\n\n        return dfs(root,\
    \ -1);\n    }\n\n    vector<long long> centroid_decomposition(int start) {\n \
    \       vector<long long> ans(g.size());\n        function<void(int)> rec = [&](int\
    \ start) {\n            int c = find_centroid(start);\n            dead[c] = true;\n\
    \            for (int u : g[c]) {\n                if (!dead[u]) rec(u);\n   \
    \         }\n            vector<vector<long long>> subtree_dist;\n\n         \
    \   int alive_sub = 0;\n            for (int u : g[c]) {\n                if (!dead[u])\
    \ {\n                    subtree_dist.emplace_back();\n                    calc_freq(c,\
    \ u, subtree_dist[alive_sub]);\n                    for (int i = 0; i < int(subtree_dist[alive_sub].size());\
    \ i++) {\n                        ans[i] += subtree_dist[alive_sub][i];\n    \
    \                }\n                    alive_sub++;\n                }\n    \
    \        }\n\n            sort(subtree_dist.begin(), subtree_dist.end(), [](const\
    \ vector<long long> &a, const vector<long long> &b) {\n                return\
    \ int(a.size()) < int(b.size());\n            });\n\n            if (alive_sub\
    \ >= 2) {\n                vector<long long> l = subtree_dist[0];\n          \
    \      for (int i = 0; i < alive_sub - 1; i++) {\n                    int idx\
    \ = 0;\n                    for (long long x : convolution_ll(l, subtree_dist[i\
    \ + 1])) {\n                        ans[idx] += x;\n                        idx++;\n\
    \                        if (idx == n) break;\n                    }\n       \
    \             int nex_size = subtree_dist[i + 1].size();\n                   \
    \ l.resize(nex_size);\n                    for (int j = 0; j < nex_size; j++)\
    \ {\n                        l[j] += subtree_dist[i + 1][j];\n               \
    \     }\n                }\n            }\n            dead[c] = false;\n    \
    \    };\n        rec(0);\n        return ans;\n    }\n\n    void calc_freq(int\
    \ c, int u, vector<long long> &freq) {\n        freq.resize(2);\n        freq[1]\
    \ = 1;\n        auto dfs = [&](auto &&self, int v, int prev, int dist) -> void\
    \ {\n            for (int nex : g[v]) {\n                if (nex != prev and !dead[nex])\
    \ {\n                    if (int(freq.size()) <= dist + 1) {\n               \
    \         freq.emplace_back(1);\n                    } else {\n              \
    \          freq[dist + 1]++;\n                    }\n                    self(self,\
    \ nex, v, dist + 1);\n                }\n            }\n        };\n        dfs(dfs,\
    \ u, c, 1);\n    }\n\n   public:\n    TreeDistFreq(int siz) {\n        n = siz;\n\
    \        g.resize(n);\n        dead.resize(n, false);\n    }\n    TreeDistFreq()\
    \ {}\n\n    void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n   \
    \     g[v].emplace_back(u);\n    }\n\n    vector<long long> get_table() {\n  \
    \      return centroid_decomposition(0);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/TreeDistanceFreqency.hpp
  requiredBy: []
  timestamp: '2025-05-03 16:53:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/tree/FrequencyTableofTreeDistance.test.cpp
documentation_of: graph/tree/TreeDistanceFreqency.hpp
layout: document
title: Frequency Table of Tree Distance
---

## 概要

todo

## 計算量
todo