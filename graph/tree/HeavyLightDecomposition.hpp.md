---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
    title: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree/HeavyLightDecomposition.hpp\"\ntemplate <class\
    \ S, auto ops, auto es, class F, auto mappings, auto compositionf, auto idf, class\
    \ T, auto opt, auto et, class G, auto mappingt, auto compositiong, auto idg>\n\
    class hld {\n private:\n  int n;\n  vector<int> subtree, depth, hl, ind, parent,\
    \ top;\n  vector<bool> seen;\n  vector<T> dist_top_p;\n  lazy_segtree<S, ops,\
    \ es, F, mappings, compositionf, idf> nodeseg, noderseg;\n  lazy_segtree<T, opt,\
    \ et, G, mappingt, compositiong, idg> pathseg, pathrseg;\n\n  int indr(int x)\
    \ {\n    return abs(ind[x] - (n - 1)) - 1;\n  }\n\n  int indrn(int x) {\n    return\
    \ abs(ind[x] - (n - 1));\n  }\n\n  int rec_sub(vector<vector<pair<int, T>>> &g,\
    \ int cur, int d) {\n    int sub = 0;\n    for (auto nex : g[cur]) {\n      if\
    \ (seen[nex.first]) continue;\n      seen[nex.first] = 1;\n      parent[nex.first]\
    \ = cur;\n      sub += rec_sub(g, nex.first, d + 1);\n    }\n    subtree[cur]\
    \ = sub + 1;\n    depth[cur] = d;\n    return subtree[cur];\n  }\n\n  void rec_hld(vector<vector<pair<int,\
    \ T>>> &g, int cur) {\n    ind[cur] = int(hl.size());\n    seen[cur] = 1;\n  \
    \  hl.push_back(cur);\n    int sub = 0;\n    int ind = -1;\n    for (auto nex\
    \ : g[cur]) {\n      if (subtree[nex.first] > sub and !seen[nex.first]) {\n  \
    \      sub = subtree[nex.first];\n        ind = nex.first;\n      }\n    }\n \
    \   if (ind != -1) {\n      top[ind] = top[cur];\n      rec_hld(g, ind);\n   \
    \   for (auto nex : g[cur]) {\n        if (nex.first != ind and !seen[nex.first])\
    \ {\n          top[nex.first] = nex.first;\n          dist_top_p[nex.first] =\
    \ nex.second;\n          rec_hld(g, nex.first);\n        }\n      }\n    }\n \
    \ }\n\n public:\n  hld(vector<vector<pair<int, T>>> &g, vector<S> nodew, int root\
    \ = 0) {\n    n = g.size();\n    seen.resize(n, 0);\n    subtree.resize(n, 0);\n\
    \    ind.resize(n, 0);\n    depth.resize(n, 0);\n    top.resize(n, 0);\n    dist_top_p.resize(n,\
    \ et());\n    parent.resize(n, -1);\n    seen[root] = 1;\n    rec_sub(g, root,\
    \ 0);\n    for (int i = 0; i < n; i++) seen[i] = 0;\n    seen[root] = 1;\n   \
    \ top[root] = root;\n    rec_hld(g, root);\n    vector<S> v(n, es());\n    vector<T>\
    \ z(n, et());\n    for (int i = 0; i < n; i++) v[i] = nodew[hl[i]];\n    nodeseg\
    \ = lazy_segtree<S, ops, es, F, mappings, compositionf, idf>(v);\n    reverse(v.begin(),\
    \ v.end());\n    noderseg = lazy_segtree<S, ops, es, F, mappings, compositionf,\
    \ idf>(v);\n    for (int i = 1; i < n; i++) {\n      int prev = hl[i - 1];\n \
    \     int cur = hl[i];\n      if (top[prev] != top[cur]) continue;\n      for\
    \ (auto p : g[prev]) {\n        if (p.first == cur) {\n          z[i] = p.second;\n\
    \        }\n      }\n    }\n    pathseg = lazy_segtree<T, opt, et, G, mappingt,\
    \ compositiong, idg>(z);\n    reverse(z.begin(), z.end());\n    pathrseg = lazy_segtree<T,\
    \ opt, et, G, mappingt, compositiong, idg>(z);\n  }\n\n  // path i -> j\n  S prod_node(int\
    \ i, int j) {\n    S prodsl = es();\n    S prodsr = es();\n    while (1) {\n \
    \     if (top[i] == top[j]) {\n        if (depth[i] > depth[j]) {\n          prodsl\
    \ = ops(prodsl, noderseg.prod(indrn(i), indrn(j) + 1));\n        } else {\n  \
    \        prodsr = ops(nodeseg.prod(ind[i], ind[j] + 1), prodsr);\n        }\n\
    \        break;\n      }\n\n      if (depth[top[i]] > depth[top[j]]) {\n     \
    \   prodsl = ops(prodsl, noderseg.prod(indrn(i), indrn(top[i]) + 1));\n      \
    \  i = parent[top[i]];\n      } else {\n        prodsr = ops(nodeseg.prod(ind[top[j]],\
    \ ind[j] + 1), prodsr);\n        j = parent[top[j]];\n      }\n    }\n    return\
    \ ops(prodsl, prodsr);\n  }\n\n  // path i -> j\n  T prod_edge(int i, int j) {\n\
    \    T prodl = et();\n    T prodr = et();\n    while (1) {\n      if (top[i] ==\
    \ top[j]) {\n        if (depth[i] > depth[j]) {\n          prodl = opt(prodl,\
    \ pathrseg.prod(indr(i) + 1, indr(j) + 1));\n        } else {\n          prodr\
    \ = opt(pathseg.prod(ind[i] + 1, ind[j] + 1), prodr);\n        }\n        break;\n\
    \      }\n\n      if (depth[top[i]] > depth[top[j]]) {\n        prodl = opt(prodl,\
    \ pathrseg.prod(indr(i) + 1, indr(top[i]) + 1));\n        prodl = opt(prodl, dist_top_p[top[i]]);\n\
    \        i = parent[top[i]];\n      } else {\n        prodr = opt(pathseg.prod(ind[top[j]]\
    \ + 1, ind[j] + 1), prodr);\n        prodr = opt(dist_top_p[top[j]], prodr);\n\
    \        j = parent[top[j]];\n      }\n    }\n    return opt(prodl, prodr);\n\
    \  }\n\n  void set_edge(int u, int v, T w) {\n    if (top[u] == top[v]) {\n  \
    \    if (depth[u] > depth[v]) {\n        pathrseg.set(indr(v), w);\n        pathseg.set(ind[u],\
    \ w);\n      } else {\n        pathseg.set(ind[v], w);\n        pathrseg.set(indr(u),\
    \ w);\n      }\n    } else {\n      if (parent[v] == u) {\n        dist_top_p[v]\
    \ = w;\n      } else {\n        dist_top_p[u] = w;\n      }\n    }\n  }\n\n  void\
    \ set_node(int u, S x) {\n    nodeseg.set(ind[u], nodeseg.get(ind[u]) + x);\n\
    \    noderseg.set(indrn(u), noderseg.get(indrn(u)) + x);\n  }\n\n  // path i ->\
    \ j\n  void apply_edge(int i, int j, G x) {\n    while (1) {\n      if (top[i]\
    \ == top[j]) {\n        if (depth[i] > depth[j]) {\n          pathrseg.apply(indr(i)\
    \ + 1, indr(j) + 1, x);\n        } else {\n          pathseg.apply(ind[i] + 1,\
    \ ind[j] + 1, x);\n        }\n        break;\n      }\n\n      if (depth[top[i]]\
    \ > depth[top[j]]) {\n        pathrseg.apply(indr(i) + 1, indr(top[i]) + 1, x);\n\
    \        dist_top_p[top[i]] = mappingt(x, dist_top_p[top[i]]);\n        i = parent[top[i]];\n\
    \      } else {\n        pathseg.apply(ind[top[j]] + 1, ind[j] + 1, x);\n    \
    \    dist_top_p[top[j]] = mappingt(x, dist_top_p[top[j]]);\n        j = parent[top[j]];\n\
    \      }\n    }\n  }\n\n  // path i -> j\n  void apply_node(int i, int j, F x)\
    \ {\n    while (1) {\n      if (top[i] == top[j]) {\n        if (depth[i] > depth[j])\
    \ {\n          noderseg.apply(indrn(i), indrn(j) + 1, x);\n        } else {\n\
    \          nodeseg.apply(ind[i], ind[j] + 1, x);\n        }\n        break;\n\
    \      }\n\n      if (depth[top[i]] > depth[top[j]]) {\n        noderseg.apply(indrn(i),\
    \ indrn(top[i]) + 1, x);\n        i = parent[top[i]];\n      } else {\n      \
    \  nodeseg.apply(ind[top[j]], ind[j] + 1, x);\n        j = parent[top[j]];\n \
    \     }\n    }\n  }\n};\n"
  code: "#pragma once\ntemplate <class S, auto ops, auto es, class F, auto mappings,\
    \ auto compositionf, auto idf, class T, auto opt, auto et, class G, auto mappingt,\
    \ auto compositiong, auto idg>\nclass hld {\n private:\n  int n;\n  vector<int>\
    \ subtree, depth, hl, ind, parent, top;\n  vector<bool> seen;\n  vector<T> dist_top_p;\n\
    \  lazy_segtree<S, ops, es, F, mappings, compositionf, idf> nodeseg, noderseg;\n\
    \  lazy_segtree<T, opt, et, G, mappingt, compositiong, idg> pathseg, pathrseg;\n\
    \n  int indr(int x) {\n    return abs(ind[x] - (n - 1)) - 1;\n  }\n\n  int indrn(int\
    \ x) {\n    return abs(ind[x] - (n - 1));\n  }\n\n  int rec_sub(vector<vector<pair<int,\
    \ T>>> &g, int cur, int d) {\n    int sub = 0;\n    for (auto nex : g[cur]) {\n\
    \      if (seen[nex.first]) continue;\n      seen[nex.first] = 1;\n      parent[nex.first]\
    \ = cur;\n      sub += rec_sub(g, nex.first, d + 1);\n    }\n    subtree[cur]\
    \ = sub + 1;\n    depth[cur] = d;\n    return subtree[cur];\n  }\n\n  void rec_hld(vector<vector<pair<int,\
    \ T>>> &g, int cur) {\n    ind[cur] = int(hl.size());\n    seen[cur] = 1;\n  \
    \  hl.push_back(cur);\n    int sub = 0;\n    int ind = -1;\n    for (auto nex\
    \ : g[cur]) {\n      if (subtree[nex.first] > sub and !seen[nex.first]) {\n  \
    \      sub = subtree[nex.first];\n        ind = nex.first;\n      }\n    }\n \
    \   if (ind != -1) {\n      top[ind] = top[cur];\n      rec_hld(g, ind);\n   \
    \   for (auto nex : g[cur]) {\n        if (nex.first != ind and !seen[nex.first])\
    \ {\n          top[nex.first] = nex.first;\n          dist_top_p[nex.first] =\
    \ nex.second;\n          rec_hld(g, nex.first);\n        }\n      }\n    }\n \
    \ }\n\n public:\n  hld(vector<vector<pair<int, T>>> &g, vector<S> nodew, int root\
    \ = 0) {\n    n = g.size();\n    seen.resize(n, 0);\n    subtree.resize(n, 0);\n\
    \    ind.resize(n, 0);\n    depth.resize(n, 0);\n    top.resize(n, 0);\n    dist_top_p.resize(n,\
    \ et());\n    parent.resize(n, -1);\n    seen[root] = 1;\n    rec_sub(g, root,\
    \ 0);\n    for (int i = 0; i < n; i++) seen[i] = 0;\n    seen[root] = 1;\n   \
    \ top[root] = root;\n    rec_hld(g, root);\n    vector<S> v(n, es());\n    vector<T>\
    \ z(n, et());\n    for (int i = 0; i < n; i++) v[i] = nodew[hl[i]];\n    nodeseg\
    \ = lazy_segtree<S, ops, es, F, mappings, compositionf, idf>(v);\n    reverse(v.begin(),\
    \ v.end());\n    noderseg = lazy_segtree<S, ops, es, F, mappings, compositionf,\
    \ idf>(v);\n    for (int i = 1; i < n; i++) {\n      int prev = hl[i - 1];\n \
    \     int cur = hl[i];\n      if (top[prev] != top[cur]) continue;\n      for\
    \ (auto p : g[prev]) {\n        if (p.first == cur) {\n          z[i] = p.second;\n\
    \        }\n      }\n    }\n    pathseg = lazy_segtree<T, opt, et, G, mappingt,\
    \ compositiong, idg>(z);\n    reverse(z.begin(), z.end());\n    pathrseg = lazy_segtree<T,\
    \ opt, et, G, mappingt, compositiong, idg>(z);\n  }\n\n  // path i -> j\n  S prod_node(int\
    \ i, int j) {\n    S prodsl = es();\n    S prodsr = es();\n    while (1) {\n \
    \     if (top[i] == top[j]) {\n        if (depth[i] > depth[j]) {\n          prodsl\
    \ = ops(prodsl, noderseg.prod(indrn(i), indrn(j) + 1));\n        } else {\n  \
    \        prodsr = ops(nodeseg.prod(ind[i], ind[j] + 1), prodsr);\n        }\n\
    \        break;\n      }\n\n      if (depth[top[i]] > depth[top[j]]) {\n     \
    \   prodsl = ops(prodsl, noderseg.prod(indrn(i), indrn(top[i]) + 1));\n      \
    \  i = parent[top[i]];\n      } else {\n        prodsr = ops(nodeseg.prod(ind[top[j]],\
    \ ind[j] + 1), prodsr);\n        j = parent[top[j]];\n      }\n    }\n    return\
    \ ops(prodsl, prodsr);\n  }\n\n  // path i -> j\n  T prod_edge(int i, int j) {\n\
    \    T prodl = et();\n    T prodr = et();\n    while (1) {\n      if (top[i] ==\
    \ top[j]) {\n        if (depth[i] > depth[j]) {\n          prodl = opt(prodl,\
    \ pathrseg.prod(indr(i) + 1, indr(j) + 1));\n        } else {\n          prodr\
    \ = opt(pathseg.prod(ind[i] + 1, ind[j] + 1), prodr);\n        }\n        break;\n\
    \      }\n\n      if (depth[top[i]] > depth[top[j]]) {\n        prodl = opt(prodl,\
    \ pathrseg.prod(indr(i) + 1, indr(top[i]) + 1));\n        prodl = opt(prodl, dist_top_p[top[i]]);\n\
    \        i = parent[top[i]];\n      } else {\n        prodr = opt(pathseg.prod(ind[top[j]]\
    \ + 1, ind[j] + 1), prodr);\n        prodr = opt(dist_top_p[top[j]], prodr);\n\
    \        j = parent[top[j]];\n      }\n    }\n    return opt(prodl, prodr);\n\
    \  }\n\n  void set_edge(int u, int v, T w) {\n    if (top[u] == top[v]) {\n  \
    \    if (depth[u] > depth[v]) {\n        pathrseg.set(indr(v), w);\n        pathseg.set(ind[u],\
    \ w);\n      } else {\n        pathseg.set(ind[v], w);\n        pathrseg.set(indr(u),\
    \ w);\n      }\n    } else {\n      if (parent[v] == u) {\n        dist_top_p[v]\
    \ = w;\n      } else {\n        dist_top_p[u] = w;\n      }\n    }\n  }\n\n  void\
    \ set_node(int u, S x) {\n    nodeseg.set(ind[u], nodeseg.get(ind[u]) + x);\n\
    \    noderseg.set(indrn(u), noderseg.get(indrn(u)) + x);\n  }\n\n  // path i ->\
    \ j\n  void apply_edge(int i, int j, G x) {\n    while (1) {\n      if (top[i]\
    \ == top[j]) {\n        if (depth[i] > depth[j]) {\n          pathrseg.apply(indr(i)\
    \ + 1, indr(j) + 1, x);\n        } else {\n          pathseg.apply(ind[i] + 1,\
    \ ind[j] + 1, x);\n        }\n        break;\n      }\n\n      if (depth[top[i]]\
    \ > depth[top[j]]) {\n        pathrseg.apply(indr(i) + 1, indr(top[i]) + 1, x);\n\
    \        dist_top_p[top[i]] = mappingt(x, dist_top_p[top[i]]);\n        i = parent[top[i]];\n\
    \      } else {\n        pathseg.apply(ind[top[j]] + 1, ind[j] + 1, x);\n    \
    \    dist_top_p[top[j]] = mappingt(x, dist_top_p[top[j]]);\n        j = parent[top[j]];\n\
    \      }\n    }\n  }\n\n  // path i -> j\n  void apply_node(int i, int j, F x)\
    \ {\n    while (1) {\n      if (top[i] == top[j]) {\n        if (depth[i] > depth[j])\
    \ {\n          noderseg.apply(indrn(i), indrn(j) + 1, x);\n        } else {\n\
    \          nodeseg.apply(ind[i], ind[j] + 1, x);\n        }\n        break;\n\
    \      }\n\n      if (depth[top[i]] > depth[top[j]]) {\n        noderseg.apply(indrn(i),\
    \ indrn(top[i]) + 1, x);\n        i = parent[top[i]];\n      } else {\n      \
    \  nodeseg.apply(ind[top[j]], ind[j] + 1, x);\n        j = parent[top[j]];\n \
    \     }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2024-06-26 18:54:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
documentation_of: graph/tree/HeavyLightDecomposition.hpp
layout: document
title: Heavy Light Decomposition
---

## 概要

todo

## 計算量
todo