---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/tree/JumponTree.test.cpp
    title: verify/LibraryChecker/graph/tree/JumponTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
    title: verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/tree/VertexAddSubtreeSum.test.cpp
    title: verify/LibraryChecker/graph/tree/VertexAddSubtreeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/HLD.hpp\"\n\nstruct hld {\n private:\n  int n,\
    \ root, edge;\n  vector<vector<int>> g;\n  vector<int> heavy_p, heavy_l, light_p,\
    \ idx, xdi, sub_siz;\n\n  int dfs(int cur, int prev) {\n    int sub = 1;\n   \
    \ for (int& nex : g[cur]) {\n      if (nex == prev) {\n        swap(g[cur].back(),\
    \ nex);\n        g[cur].pop_back();\n        break;\n      }\n    }\n    int best\
    \ = 0;\n    int idx = -1;\n    for (int i = 0; i < int(g[cur].size()); i++) {\n\
    \      int cnt = dfs(g[cur][i], cur);\n      sub += cnt;\n      if (best < cnt)\
    \ {\n        best = cnt;\n        idx = i;\n      }\n    }\n    if (!g[cur].empty())\
    \ swap(g[cur][idx], g[cur].front());\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) light_p[g[cur][i]] = cur;\n    sub_siz[cur] = sub;\n    return sub;\n \
    \ }\n\n  void dfs2(int cur, int top, int& id) {\n    heavy_p[cur] = top;\n   \
    \ idx[cur] = id;\n    xdi[id] = cur;\n    id++;\n    if (!g[cur].empty()) {\n\
    \      dfs2(g[cur].front(), top, id);\n      heavy_l[cur] = heavy_l[g[cur].front()];\n\
    \    } else {\n      heavy_l[cur] = cur;\n    }\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) dfs2(g[cur][i], g[cur][i], id);\n  }\n\n  void build() {\n    int id =\
    \ 0;\n    dfs(root, -1);\n    dfs2(root, root, id);\n  }\n\n public:\n  hld(int\
    \ n, int root = 0) : n(n), root(root), edge(0), g(n), heavy_p(n, -1), heavy_l(n,\
    \ -1), light_p(n, -1), idx(n), xdi(n), sub_siz(n) {}\n\n  void add_edge(int u,\
    \ int v) {\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n    edge++;\n\
    \    if (edge == n - 1) build();\n  }\n\n  int lca(int u, int v) {\n    while\
    \ (heavy_p[u] != heavy_p[v]) {\n      if (idx[u] > idx[v]) swap(u, v);\n     \
    \ v = light_p[heavy_p[v]];\n    }\n    return idx[u] < idx[v] ? u : v;\n  }\n\n\
    \  int dist(int u, int v) {\n    int res = 0;\n    while (heavy_p[u] != heavy_p[v])\
    \ {\n      if (idx[u] > idx[v]) swap(u, v);\n      res += idx[v] - idx[heavy_p[v]]\
    \ + 1;\n      v = light_p[heavy_p[v]];\n    }\n    res += abs(idx[u] - idx[v]);\n\
    \    return res;\n  }\n\n  int meet(int r, int u, int v) {\n    return lca(r,\
    \ u) ^ lca(u, v) ^ lca(v, r);\n  }\n\n  int jump(int u, int v, int64_t d) {\n\
    \    int from = u;\n    int to = v;\n    bool p = false;\n    int ul_dist = 0;\n\
    \    int lv_dist = 0;\n    while (heavy_p[u] != heavy_p[v]) {\n      if (idx[u]\
    \ > idx[v]) {\n        p = !p;\n        swap(u, v);\n        swap(ul_dist, lv_dist);\n\
    \      }\n      ul_dist += idx[v] - idx[heavy_p[v]] + 1;\n      v = light_p[heavy_p[v]];\n\
    \    }\n    if (idx[u] > idx[v]) {\n      p = !p;\n      swap(u, v);\n      swap(ul_dist,\
    \ lv_dist);\n    }\n    ul_dist += idx[v] - idx[u];\n    if (!p) {\n      swap(ul_dist,\
    \ lv_dist);\n    }\n    if (d <= ul_dist) {\n      return la(from, d);\n    }\n\
    \    d -= ul_dist;\n    if (d <= lv_dist) {\n      return la(to, lv_dist - d);\n\
    \    }\n    return -1;\n  }\n\n  int la(int v, int64_t k) {\n    while (v != -1)\
    \ {\n      int p = heavy_p[v];\n      if (idx[v] - idx[p] >= k) {\n        v =\
    \ xdi[idx[v] - k];\n        break;\n      }\n      k -= (idx[v] - idx[p] + 1);\n\
    \      v = (p == root ? -1 : light_p[p]);\n    }\n\n    return v;\n  }\n\n  int\
    \ subtree_size(int v) {\n    return sub_siz[v];\n  }\n\n  int traverse_begin(int\
    \ v) {\n    return idx[v];\n  }\n\n  int traverse_end(int v) {\n    return idx[v]\
    \ + sub_siz[v];\n  }\n\n  bool contains_path(int from, int to, int v) {\n    return\
    \ meet(v, from, to) == v;\n  }\n\n  bool contains_subtree(int r, int v) {\n  \
    \  return traverse_begin(r) <= traverse_begin(v) and traverse_end(v) <= traverse_end(r);\n\
    \  }\n\n  pair<vector<int>, vector<int>> lca_based_auxiliary_tree(vector<int>\
    \ v) {\n    if (v.empty()) return {{}, {}};\n    int siz = int(v.size());\n  \
    \  auto pre_order = [&](int i, int j) -> bool { return idx[i] < idx[j]; };\n \
    \   sort(v.begin(), v.end(), pre_order);\n    for (int i = 0; i < siz - 1; i++)\
    \ v.emplace_back(lca(v[i], v[i + 1]));\n    sort(v.begin(), v.end(), pre_order);\n\
    \    v.erase(unique(v.begin(), v.end()), v.end());\n\n    siz = int(v.size());\n\
    \    vector<int> par(siz, -1);\n    stack<int> st;\n    st.emplace(0);\n    for\
    \ (int i = 1; i < siz; i++) {\n      while (!st.empty() and traverse_end(v[st.top()])\
    \ <= traverse_begin(v[i])) st.pop();\n      par[i] = st.top();\n      st.push(i);\n\
    \    }\n    return {par, v};\n  }\n};\n"
  code: "\nstruct hld {\n private:\n  int n, root, edge;\n  vector<vector<int>> g;\n\
    \  vector<int> heavy_p, heavy_l, light_p, idx, xdi, sub_siz;\n\n  int dfs(int\
    \ cur, int prev) {\n    int sub = 1;\n    for (int& nex : g[cur]) {\n      if\
    \ (nex == prev) {\n        swap(g[cur].back(), nex);\n        g[cur].pop_back();\n\
    \        break;\n      }\n    }\n    int best = 0;\n    int idx = -1;\n    for\
    \ (int i = 0; i < int(g[cur].size()); i++) {\n      int cnt = dfs(g[cur][i], cur);\n\
    \      sub += cnt;\n      if (best < cnt) {\n        best = cnt;\n        idx\
    \ = i;\n      }\n    }\n    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());\n\
    \    for (int i = 1; i < int(g[cur].size()); i++) light_p[g[cur][i]] = cur;\n\
    \    sub_siz[cur] = sub;\n    return sub;\n  }\n\n  void dfs2(int cur, int top,\
    \ int& id) {\n    heavy_p[cur] = top;\n    idx[cur] = id;\n    xdi[id] = cur;\n\
    \    id++;\n    if (!g[cur].empty()) {\n      dfs2(g[cur].front(), top, id);\n\
    \      heavy_l[cur] = heavy_l[g[cur].front()];\n    } else {\n      heavy_l[cur]\
    \ = cur;\n    }\n    for (int i = 1; i < int(g[cur].size()); i++) dfs2(g[cur][i],\
    \ g[cur][i], id);\n  }\n\n  void build() {\n    int id = 0;\n    dfs(root, -1);\n\
    \    dfs2(root, root, id);\n  }\n\n public:\n  hld(int n, int root = 0) : n(n),\
    \ root(root), edge(0), g(n), heavy_p(n, -1), heavy_l(n, -1), light_p(n, -1), idx(n),\
    \ xdi(n), sub_siz(n) {}\n\n  void add_edge(int u, int v) {\n    g[u].emplace_back(v);\n\
    \    g[v].emplace_back(u);\n    edge++;\n    if (edge == n - 1) build();\n  }\n\
    \n  int lca(int u, int v) {\n    while (heavy_p[u] != heavy_p[v]) {\n      if\
    \ (idx[u] > idx[v]) swap(u, v);\n      v = light_p[heavy_p[v]];\n    }\n    return\
    \ idx[u] < idx[v] ? u : v;\n  }\n\n  int dist(int u, int v) {\n    int res = 0;\n\
    \    while (heavy_p[u] != heavy_p[v]) {\n      if (idx[u] > idx[v]) swap(u, v);\n\
    \      res += idx[v] - idx[heavy_p[v]] + 1;\n      v = light_p[heavy_p[v]];\n\
    \    }\n    res += abs(idx[u] - idx[v]);\n    return res;\n  }\n\n  int meet(int\
    \ r, int u, int v) {\n    return lca(r, u) ^ lca(u, v) ^ lca(v, r);\n  }\n\n \
    \ int jump(int u, int v, int64_t d) {\n    int from = u;\n    int to = v;\n  \
    \  bool p = false;\n    int ul_dist = 0;\n    int lv_dist = 0;\n    while (heavy_p[u]\
    \ != heavy_p[v]) {\n      if (idx[u] > idx[v]) {\n        p = !p;\n        swap(u,\
    \ v);\n        swap(ul_dist, lv_dist);\n      }\n      ul_dist += idx[v] - idx[heavy_p[v]]\
    \ + 1;\n      v = light_p[heavy_p[v]];\n    }\n    if (idx[u] > idx[v]) {\n  \
    \    p = !p;\n      swap(u, v);\n      swap(ul_dist, lv_dist);\n    }\n    ul_dist\
    \ += idx[v] - idx[u];\n    if (!p) {\n      swap(ul_dist, lv_dist);\n    }\n \
    \   if (d <= ul_dist) {\n      return la(from, d);\n    }\n    d -= ul_dist;\n\
    \    if (d <= lv_dist) {\n      return la(to, lv_dist - d);\n    }\n    return\
    \ -1;\n  }\n\n  int la(int v, int64_t k) {\n    while (v != -1) {\n      int p\
    \ = heavy_p[v];\n      if (idx[v] - idx[p] >= k) {\n        v = xdi[idx[v] - k];\n\
    \        break;\n      }\n      k -= (idx[v] - idx[p] + 1);\n      v = (p == root\
    \ ? -1 : light_p[p]);\n    }\n\n    return v;\n  }\n\n  int subtree_size(int v)\
    \ {\n    return sub_siz[v];\n  }\n\n  int traverse_begin(int v) {\n    return\
    \ idx[v];\n  }\n\n  int traverse_end(int v) {\n    return idx[v] + sub_siz[v];\n\
    \  }\n\n  bool contains_path(int from, int to, int v) {\n    return meet(v, from,\
    \ to) == v;\n  }\n\n  bool contains_subtree(int r, int v) {\n    return traverse_begin(r)\
    \ <= traverse_begin(v) and traverse_end(v) <= traverse_end(r);\n  }\n\n  pair<vector<int>,\
    \ vector<int>> lca_based_auxiliary_tree(vector<int> v) {\n    if (v.empty()) return\
    \ {{}, {}};\n    int siz = int(v.size());\n    auto pre_order = [&](int i, int\
    \ j) -> bool { return idx[i] < idx[j]; };\n    sort(v.begin(), v.end(), pre_order);\n\
    \    for (int i = 0; i < siz - 1; i++) v.emplace_back(lca(v[i], v[i + 1]));\n\
    \    sort(v.begin(), v.end(), pre_order);\n    v.erase(unique(v.begin(), v.end()),\
    \ v.end());\n\n    siz = int(v.size());\n    vector<int> par(siz, -1);\n    stack<int>\
    \ st;\n    st.emplace(0);\n    for (int i = 1; i < siz; i++) {\n      while (!st.empty()\
    \ and traverse_end(v[st.top()]) <= traverse_begin(v[i])) st.pop();\n      par[i]\
    \ = st.top();\n      st.push(i);\n    }\n    return {par, v};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/HLD.hpp
  requiredBy: []
  timestamp: '2026-05-28 17:17:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
  - verify/LibraryChecker/graph/tree/JumponTree.test.cpp
  - verify/LibraryChecker/graph/tree/VertexAddSubtreeSum.test.cpp
documentation_of: graph/tree/HLD.hpp
layout: document
title: Heavy Light Decomposition
---

## 概要

todo

## 計算量
todo