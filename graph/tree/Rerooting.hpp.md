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
  bundledCode: "#line 1 \"graph/tree/Rerooting.hpp\"\ntemplate <class S, auto op,\
    \ auto e, auto put_vertex, auto put_edge>\nclass Rerooting {\n   private:\n  \
    \  int n;\n    vector<vector<int>> idx;\n    vector<vector<int>> g, e_id, rev_id;\n\
    \    vector<vector<S>> dp, acc_r;\n    vector<S> ans;\n\n    S postorder_dfs(int\
    \ u, int prev = -1) {\n        S res = e();\n        int deg = int(g[u].size());\n\
    \        dp[u].resize(deg, e());\n        for (int i = 0; i < deg; i++) {\n  \
    \          int v = g[u][i];\n            if (v == prev) continue;\n          \
    \  dp[u][i] = put_edge(postorder_dfs(v, u), e_id[u][i]);\n            res = op(res,\
    \ dp[u][i]);\n        }\n        return put_vertex(res, u);\n    }\n\n    void\
    \ preorder_dfs(int u, int prev = -1) {\n        int deg = int(g[u].size());\n\
    \        acc_r[u].resize(deg + 1, e());\n        S acc_l = e();\n        for (int\
    \ i = deg - 1; i >= 0; i--) {\n            acc_r[u][i] = op(acc_r[u][i + 1], dp[u][i]);\n\
    \        }\n        ans[u] = put_vertex(acc_r[u][0], u);\n\n        for (int i\
    \ = 0; i < deg; i++) {\n            int v = g[u][i];\n            if (v != prev)\
    \ {\n                dp[v][idx[u][i]] = put_edge(op(acc_l, acc_r[u][i + 1]), e_id[v][idx[u][i]]);\n\
    \                preorder_dfs(v, u);\n            }\n            acc_l = op(acc_l,\
    \ dp[u][i]);\n        }\n    }\n\n   public:\n    Rerooting(int n) : n(n) {\n\
    \        g.resize(n);\n        idx.resize(n);\n        dp.resize(n);\n       \
    \ acc_r.resize(n);\n        ans.resize(n);\n        e_id.resize(n);\n        rev_id.resize(n);\n\
    \    }\n\n    void add_edge(int u, int v, int u_v_id, int v_u_id) {\n        idx[u].emplace_back(int(g[v].size()));\n\
    \        idx[v].emplace_back(int(g[u].size()));\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n        e_id[u].emplace_back(u_v_id);\n      \
    \  e_id[v].emplace_back(v_u_id);\n    }\n\n    vector<S> build() {\n        postorder_dfs(0);\n\
    \        preorder_dfs(0);\n        return ans;\n    }\n};\n"
  code: "template <class S, auto op, auto e, auto put_vertex, auto put_edge>\nclass\
    \ Rerooting {\n   private:\n    int n;\n    vector<vector<int>> idx;\n    vector<vector<int>>\
    \ g, e_id, rev_id;\n    vector<vector<S>> dp, acc_r;\n    vector<S> ans;\n\n \
    \   S postorder_dfs(int u, int prev = -1) {\n        S res = e();\n        int\
    \ deg = int(g[u].size());\n        dp[u].resize(deg, e());\n        for (int i\
    \ = 0; i < deg; i++) {\n            int v = g[u][i];\n            if (v == prev)\
    \ continue;\n            dp[u][i] = put_edge(postorder_dfs(v, u), e_id[u][i]);\n\
    \            res = op(res, dp[u][i]);\n        }\n        return put_vertex(res,\
    \ u);\n    }\n\n    void preorder_dfs(int u, int prev = -1) {\n        int deg\
    \ = int(g[u].size());\n        acc_r[u].resize(deg + 1, e());\n        S acc_l\
    \ = e();\n        for (int i = deg - 1; i >= 0; i--) {\n            acc_r[u][i]\
    \ = op(acc_r[u][i + 1], dp[u][i]);\n        }\n        ans[u] = put_vertex(acc_r[u][0],\
    \ u);\n\n        for (int i = 0; i < deg; i++) {\n            int v = g[u][i];\n\
    \            if (v != prev) {\n                dp[v][idx[u][i]] = put_edge(op(acc_l,\
    \ acc_r[u][i + 1]), e_id[v][idx[u][i]]);\n                preorder_dfs(v, u);\n\
    \            }\n            acc_l = op(acc_l, dp[u][i]);\n        }\n    }\n\n\
    \   public:\n    Rerooting(int n) : n(n) {\n        g.resize(n);\n        idx.resize(n);\n\
    \        dp.resize(n);\n        acc_r.resize(n);\n        ans.resize(n);\n   \
    \     e_id.resize(n);\n        rev_id.resize(n);\n    }\n\n    void add_edge(int\
    \ u, int v, int u_v_id, int v_u_id) {\n        idx[u].emplace_back(int(g[v].size()));\n\
    \        idx[v].emplace_back(int(g[u].size()));\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n        e_id[u].emplace_back(u_v_id);\n      \
    \  e_id[v].emplace_back(v_u_id);\n    }\n\n    vector<S> build() {\n        postorder_dfs(0);\n\
    \        preorder_dfs(0);\n        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2025-09-25 02:57:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/Rerooting.hpp
layout: document
title: Rerooting DP
---

## 概要

todo

## 計算量
todo