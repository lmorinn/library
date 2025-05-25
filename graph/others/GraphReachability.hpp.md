---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/connected-components/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \        return components;\n    }\n};\n#line 2 \"graph/others/GraphReachability.hpp\"\
    \nclass GraphReachability {\n   private:\n    vector<vector<int>> r;\n    queue<pair<int,\
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
    \ cnt = 0;\n        vector<bitset<2048>> dp(n);\n        vector<int> goal(2048);\n\
    \n        while (!q.empty()) {\n            int a = compress_id[q.front().first];\n\
    \            int b = compress_id[q.front().second];\n            q.pop();\n  \
    \          dp[a].set(cnt);\n            goal[cnt] = b;\n            cnt++;\n \
    \           if (cnt == 2048 or q.empty()) {\n                for (int i = 0; i\
    \ < n; i++) {\n                    for (int prev : r[i]) {\n                 \
    \       dp[i] |= dp[prev];\n                    }\n                }\n       \
    \         for (int i = 0; i < cnt; i++) {\n                    if (dp[goal[i]][i])\
    \ {\n                        res[res_idx] = true;\n                    } else\
    \ {\n                        res[res_idx] = false;\n                    }\n  \
    \                  res_idx++;\n                }\n\n                for (int i\
    \ = 0; i < n; i++) {\n                    dp[i].reset();\n                }\n\
    \                cnt = 0;\n            }\n        }\n\n        return res;\n \
    \   }\n};\n"
  code: "#include \"../connected-components/StronglyConnectedComponents.hpp\"\nclass\
    \ GraphReachability {\n   private:\n    vector<vector<int>> r;\n    queue<pair<int,\
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
    \ cnt = 0;\n        vector<bitset<2048>> dp(n);\n        vector<int> goal(2048);\n\
    \n        while (!q.empty()) {\n            int a = compress_id[q.front().first];\n\
    \            int b = compress_id[q.front().second];\n            q.pop();\n  \
    \          dp[a].set(cnt);\n            goal[cnt] = b;\n            cnt++;\n \
    \           if (cnt == 2048 or q.empty()) {\n                for (int i = 0; i\
    \ < n; i++) {\n                    for (int prev : r[i]) {\n                 \
    \       dp[i] |= dp[prev];\n                    }\n                }\n       \
    \         for (int i = 0; i < cnt; i++) {\n                    if (dp[goal[i]][i])\
    \ {\n                        res[res_idx] = true;\n                    } else\
    \ {\n                        res[res_idx] = false;\n                    }\n  \
    \                  res_idx++;\n                }\n\n                for (int i\
    \ = 0; i < n; i++) {\n                    dp[i].reset();\n                }\n\
    \                cnt = 0;\n            }\n        }\n\n        return res;\n \
    \   }\n};\n"
  dependsOn:
  - graph/connected-components/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: graph/others/GraphReachability.hpp
  requiredBy: []
  timestamp: '2024-12-07 20:14:42+09:00'
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