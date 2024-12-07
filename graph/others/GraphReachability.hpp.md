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
  bundledCode: "#line 1 \"graph/others/GraphReachability.hpp\"\nclass GraphReachability\
    \ {\n   private:\n    vector<vector<int>> r;\n    queue<pair<int, int>> q;\n \
    \   vector<int> compress_id;\n    SCC s;\n    int n;\n\n   public:\n    GraphReachability(const\
    \ vector<vector<int>> &v) {\n        int siz = v.size();\n        s = SCC(siz);\n\
    \        compress_id.resize(siz);\n        for (int i = 0; i < siz; i++) {\n \
    \           for (auto j : v[i]) {\n                s.add_edge(i, j);\n       \
    \     }\n        }\n\n        vector<vector<int>> components = s.decompose();\n\
    \        for (int i = 0; i < components.size(); i++) {\n            for (int idx\
    \ : components[i]) {\n                compress_id[idx] = i;\n            }\n \
    \       }\n\n        n = components.size();\n        r.resize(n);\n\n        for\
    \ (int i = 0; i < siz; i++) {\n            for (auto j : v[i]) {\n           \
    \     if (compress_id[i] != compress_id[j]) {\n                    r[compress_id[j]].emplace_back(compress_id[i]);\n\
    \                }\n            }\n        }\n\n        for (int i = 0; i < n;\
    \ i++) {\n            sort(r[i].begin(), r[i].end());\n            r[i].erase(unique(r[i].begin(),\
    \ r[i].end()), r[i].end());\n        }\n    }\n\n    void is_reachable(int from,\
    \ int to) {\n        q.emplace(from, to);\n    }\n\n    vector<bool> build() {\n\
    \        vector<bool> res(int(q.size()));\n        int res_idx = 0;\n        int\
    \ cnt = 0;\n        vector<unsigned long long> dp(n);\n        vector<int> goal(64);\n\
    \n        while (!q.empty()) {\n            int a = compress_id[q.front().first];\n\
    \            int b = compress_id[q.front().second];\n            q.pop();\n  \
    \          dp[a] |= (1ULL << cnt);\n            goal[cnt] = b;\n            cnt++;\n\
    \            if (cnt == 64 or q.empty()) {\n                for (int i = 0; i\
    \ < n; i++) {\n                    for (int prev : r[i]) {\n                 \
    \       dp[i] |= dp[prev];\n                    }\n                }\n       \
    \         for (int i = 0; i < cnt; i++) {\n                    if (dp[goal[i]]\
    \ & (1ULL << i)) {\n                        res[res_idx] = true;\n           \
    \         } else {\n                        res[res_idx] = false;\n          \
    \          }\n                    res_idx++;\n                }\n\n          \
    \      for (int i = 0; i < n; i++) {\n                    dp[i] = 0;\n       \
    \         }\n                cnt = 0;\n            }\n        }\n\n        return\
    \ res;\n    }\n};\n"
  code: "class GraphReachability {\n   private:\n    vector<vector<int>> r;\n    queue<pair<int,\
    \ int>> q;\n    vector<int> compress_id;\n    SCC s;\n    int n;\n\n   public:\n\
    \    GraphReachability(const vector<vector<int>> &v) {\n        int siz = v.size();\n\
    \        s = SCC(siz);\n        compress_id.resize(siz);\n        for (int i =\
    \ 0; i < siz; i++) {\n            for (auto j : v[i]) {\n                s.add_edge(i,\
    \ j);\n            }\n        }\n\n        vector<vector<int>> components = s.decompose();\n\
    \        for (int i = 0; i < components.size(); i++) {\n            for (int idx\
    \ : components[i]) {\n                compress_id[idx] = i;\n            }\n \
    \       }\n\n        n = components.size();\n        r.resize(n);\n\n        for\
    \ (int i = 0; i < siz; i++) {\n            for (auto j : v[i]) {\n           \
    \     if (compress_id[i] != compress_id[j]) {\n                    r[compress_id[j]].emplace_back(compress_id[i]);\n\
    \                }\n            }\n        }\n\n        for (int i = 0; i < n;\
    \ i++) {\n            sort(r[i].begin(), r[i].end());\n            r[i].erase(unique(r[i].begin(),\
    \ r[i].end()), r[i].end());\n        }\n    }\n\n    void is_reachable(int from,\
    \ int to) {\n        q.emplace(from, to);\n    }\n\n    vector<bool> build() {\n\
    \        vector<bool> res(int(q.size()));\n        int res_idx = 0;\n        int\
    \ cnt = 0;\n        vector<unsigned long long> dp(n);\n        vector<int> goal(64);\n\
    \n        while (!q.empty()) {\n            int a = compress_id[q.front().first];\n\
    \            int b = compress_id[q.front().second];\n            q.pop();\n  \
    \          dp[a] |= (1ULL << cnt);\n            goal[cnt] = b;\n            cnt++;\n\
    \            if (cnt == 64 or q.empty()) {\n                for (int i = 0; i\
    \ < n; i++) {\n                    for (int prev : r[i]) {\n                 \
    \       dp[i] |= dp[prev];\n                    }\n                }\n       \
    \         for (int i = 0; i < cnt; i++) {\n                    if (dp[goal[i]]\
    \ & (1ULL << i)) {\n                        res[res_idx] = true;\n           \
    \         } else {\n                        res[res_idx] = false;\n          \
    \          }\n                    res_idx++;\n                }\n\n          \
    \      for (int i = 0; i < n; i++) {\n                    dp[i] = 0;\n       \
    \         }\n                cnt = 0;\n            }\n        }\n\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/others/GraphReachability.hpp
  requiredBy: []
  timestamp: '2024-12-07 16:26:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/others/GraphReachability.hpp
layout: document
title: Directed Graph Reachability
---

## 概要

todo

## 計算量
todo