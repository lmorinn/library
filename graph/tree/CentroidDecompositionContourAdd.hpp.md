---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
    title: Dual Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp\"\
    \ntemplate <class T>\nstruct RangeAddPointGet {\n   private:\n    fenwick_tree<T>\
    \ ft;\n\n   public:\n    RangeAddPointGet() {}\n    RangeAddPointGet(int siz)\
    \ : ft(siz + 1) {}\n\n    void range_add(int l, int r, T x) {\n        ft.add(l,\
    \ x);\n        ft.add(r, -x);\n    }\n\n    void add(int p, T x) {\n        ft.add(p,\
    \ x);\n        ft.add(p + 1, -x);\n    }\n\n    T point_get(int p) {\n       \
    \ return ft.sum(0, p + 1);\n    }\n};\n#line 2 \"graph/tree/CentroidDecompositionContourAdd.hpp\"\
    \n\nstatic const unsigned long long seed = chrono::steady_clock::now().time_since_epoch().count();\n\
    static mt19937_64 eng(seed);\n\ntemplate <class S>\nclass CentroidDecomposition\
    \ {\n   private:\n    vector<vector<int>> g;\n    vector<bool> dead;\n    vector<S>\
    \ leaf;\n    vector<int> ord;\n    vector<int> dinfo;\n    vector<int> parent;\n\
    \    vector<vector<RangeAddPointGet<S>>> subtrees;\n    vector<vector<int>> ds_size;\n\
    \    vector<int> subtree_size;\n    vector<vector<pair<int, int>>> info;\n\n \
    \   int n;\n    int node_idx;\n\n    void reorder(int s) {\n        ord.assign(n,\
    \ -1);\n        queue<int> q;\n        q.push(s);\n        int idx = 0;\n    \
    \    while (!q.empty()) {\n            int cur = q.front();\n            q.pop();\n\
    \            ord[cur] = idx++;\n            for (int nex : g[cur])\n         \
    \       if (ord[nex] == -1) q.push(nex);\n        }\n    }\n\n    void ds_add(RangeAddPointGet<S>\
    \ &fen, int siz, int l, int r, S x) {\n        l = max(0, l);\n        r = min(r,\
    \ siz);\n        if (l < r) fen.range_add(l, r, x);\n    }\n\n   public:\n   \
    \ CentroidDecomposition(int siz) {\n        n = siz;\n        g.resize(n);\n\n\
    \        node_idx = n;\n    }\n    CentroidDecomposition() {}\n\n    void add_edge(int\
    \ u, int v) {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n\n    void build(const vector<S> &a) {\n        parent.assign(n << 1,\
    \ -1);\n        info.resize(n, vector<pair<int, int>>(30));\n        subtrees.resize(n\
    \ << 1, vector<RangeAddPointGet<S>>(2));\n        ds_size.resize(n << 1, vector<int>(2));\n\
    \        dead.resize(n, false);\n        subtree_size.resize(n << 1);\n      \
    \  leaf.resize(n);\n        dinfo.resize(n);\n        reorder(uniform_int_distribution<int>(0,\
    \ n - 1)(eng));\n        vector<vector<int>> tmp(n);\n        vector<int> par_cr(n\
    \ << 1, -1);\n        vector<int> head(n << 1);\n        vector<int> tail(n <<\
    \ 1);\n        vector<int> link(n << 1, -1);\n        vector<S> d(n * 3);\n  \
    \      for (int i = 0; i < n; i++) {\n            head[i] = tail[i] = i;\n   \
    \     }\n\n        for (int u = 0; u < n; u++) {\n            for (const int v\
    \ : g[u]) {\n                tmp[ord[u]].emplace_back(ord[v]);\n            }\n\
    \            leaf[ord[u]] = a[u];\n        }\n        g = tmp;\n\n        function<int(int,\
    \ int)> rec = [&](int start, int sz) -> int {\n            int c = -1;\n     \
    \       const auto get_centroid = [&](auto &&self, int u, int p) -> void {\n \
    \               subtree_size[u] = 1;\n                for (const int v : g[u])\
    \ {\n                    if (v == p || dead[v]) continue;\n\n                \
    \    self(self, v, u);\n                    if (v == c) {\n                  \
    \      subtree_size[u] = sz - subtree_size[c];\n                        break;\n\
    \                    }\n\n                    subtree_size[u] += subtree_size[v];\n\
    \                }\n\n                if (c == -1 && subtree_size[u] * 2 > sz)\
    \ c = u;\n            };\n\n            get_centroid(get_centroid, start, -1);\n\
    \            dead[c] = true;\n            for (const int u : g[c]) {\n       \
    \         if (dead[u]) continue;\n                const int comp_sz = subtree_size[u];\n\
    \                par_cr[u] = rec(u, comp_sz);\n                subtree_size[u]\
    \ = comp_sz;\n            }\n\n            const auto compare = [&](int i, int\
    \ j) {\n                return subtree_size[i] > subtree_size[j];\n          \
    \  };\n\n            priority_queue<int, vector<int>, decltype(compare)> pq{compare};\n\
    \n            for (const int v : g[c]) {\n                if (dead[v]) continue;\n\
    \                link[v] = -1;\n                pq.push(v);\n            }\n\n\
    \            const auto build_data_structure = [&](const int root_head, const\
    \ int child_index) {\n                queue<pair<int, int>> q;\n             \
    \   for (int root = root_head; root >= 0; root = link[root]) {\n             \
    \       q.emplace(root, -1);\n                }\n\n                S x = 0;\n\
    \                int idx = 0;\n                int nxt = -1;\n               \
    \ while (!q.empty()) {\n                    int cur = q.front().first;\n     \
    \               int prev = q.front().second;\n                    q.pop();\n \
    \                   if (cur == nxt) {\n                        d[idx++] = exchange(x,\
    \ 0);\n                        nxt = -1;\n                    }\n\n          \
    \          info[cur][dinfo[cur]++] = {child_index, idx};\n                   \
    \ x += leaf[cur];\n\n                    for (const int v : g[cur]) {\n      \
    \                  if (v == prev or dead[v]) continue;\n                     \
    \   q.emplace(v, cur);\n                        if (nxt == -1) nxt = v;\n    \
    \                }\n                }\n                d[idx++] = x;\n       \
    \         return idx;\n            };\n\n            while (pq.size() >= 2) {\n\
    \                const int p1 = pq.top();\n                pq.pop();\n       \
    \         const int p2 = pq.top();\n                pq.pop();\n              \
    \  if (pq.empty()) {\n                    parent[par_cr[p1]] = parent[par_cr[p2]]\
    \ = c;\n                    ds_size[c][0] = build_data_structure(head[p1], 0);\n\
    \                    subtrees[c][0] = RangeAddPointGet<S>(ds_size[c][0]);\n  \
    \                  ds_size[c][1] = build_data_structure(head[p2], 1);\n      \
    \              subtrees[c][1] = RangeAddPointGet<S>(ds_size[c][1]);\n        \
    \            break;\n                }\n                subtree_size[node_idx]\
    \ = subtree_size[p1] + subtree_size[p2];\n                par_cr[node_idx] = node_idx;\n\
    \                parent[par_cr[p1]] = parent[par_cr[p2]] = node_idx;\n       \
    \         ds_size[node_idx][0] = build_data_structure(head[p1], 0);\n        \
    \        subtrees[node_idx][0] = RangeAddPointGet<S>(ds_size[node_idx][0]);\n\
    \                ds_size[node_idx][1] = build_data_structure(head[p2], 1);\n \
    \               subtrees[node_idx][1] = RangeAddPointGet<S>(ds_size[node_idx][1]);\n\
    \                head[node_idx] = head[p1];\n                tail[node_idx] =\
    \ tail[p2];\n                link[tail[p1]] = head[p2];\n                pq.push(node_idx);\n\
    \                node_idx++;\n            }\n\n            if (!pq.empty()) {\n\
    \                int u = pq.top();\n                pq.pop();\n              \
    \  parent[par_cr[u]] = c;\n                ds_size[c][0] = build_data_structure(head[u],\
    \ 0);\n                subtrees[c][0] = RangeAddPointGet<S>(ds_size[c][0]);\n\
    \            }\n            dead[c] = false;\n            return c;\n        };\n\
    \n        rec(0, n);\n        parent.resize(node_idx);\n        parent.shrink_to_fit();\n\
    \        subtrees.resize(node_idx);\n        subtrees.shrink_to_fit();\n    }\n\
    \n    S get(int p) {\n        S ret = 0;\n        p = ord[p];\n        ret +=\
    \ leaf[p];\n        int cur = parent[p];\n        for (int i = 0; i < dinfo[p];\
    \ i++) {\n            const auto &[b, dist] = info[p][i];\n            ret +=\
    \ subtrees[exchange(cur, parent[cur])][b].point_get(dist);\n        }\n      \
    \  return ret;\n    }\n\n    void add(int p, int lower, int upper, S x) {\n  \
    \      p = ord[p];\n        if (lower <= 0 and 0 < upper) leaf[p] += x;\n    \
    \    ds_add(subtrees[p][0], ds_size[p][0], lower - 1, upper - 1, x);\n       \
    \ ds_add(subtrees[p][1], ds_size[p][1], lower - 1, upper - 1, x);\n        int\
    \ v = parent[p];\n        for (int i = 0; i < dinfo[p]; i++) {\n            const\
    \ auto &[b, dist] = info[p][i];\n            int ql = lower - dist - 1;\n    \
    \        int qr = upper - dist - 1;\n            if (v < n and ql <= 0 and 0 <\
    \ qr) leaf[v] += x;\n            ds_add(subtrees[exchange(v, parent[v])][b ^ 1],\
    \ ds_size[v][b ^ 1], ql - 1, qr - 1, x);\n        }\n    }\n};\n"
  code: "#include \"../../data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp\"\
    \n\nstatic const unsigned long long seed = chrono::steady_clock::now().time_since_epoch().count();\n\
    static mt19937_64 eng(seed);\n\ntemplate <class S>\nclass CentroidDecomposition\
    \ {\n   private:\n    vector<vector<int>> g;\n    vector<bool> dead;\n    vector<S>\
    \ leaf;\n    vector<int> ord;\n    vector<int> dinfo;\n    vector<int> parent;\n\
    \    vector<vector<RangeAddPointGet<S>>> subtrees;\n    vector<vector<int>> ds_size;\n\
    \    vector<int> subtree_size;\n    vector<vector<pair<int, int>>> info;\n\n \
    \   int n;\n    int node_idx;\n\n    void reorder(int s) {\n        ord.assign(n,\
    \ -1);\n        queue<int> q;\n        q.push(s);\n        int idx = 0;\n    \
    \    while (!q.empty()) {\n            int cur = q.front();\n            q.pop();\n\
    \            ord[cur] = idx++;\n            for (int nex : g[cur])\n         \
    \       if (ord[nex] == -1) q.push(nex);\n        }\n    }\n\n    void ds_add(RangeAddPointGet<S>\
    \ &fen, int siz, int l, int r, S x) {\n        l = max(0, l);\n        r = min(r,\
    \ siz);\n        if (l < r) fen.range_add(l, r, x);\n    }\n\n   public:\n   \
    \ CentroidDecomposition(int siz) {\n        n = siz;\n        g.resize(n);\n\n\
    \        node_idx = n;\n    }\n    CentroidDecomposition() {}\n\n    void add_edge(int\
    \ u, int v) {\n        g[u].emplace_back(v);\n        g[v].emplace_back(u);\n\
    \    }\n\n    void build(const vector<S> &a) {\n        parent.assign(n << 1,\
    \ -1);\n        info.resize(n, vector<pair<int, int>>(30));\n        subtrees.resize(n\
    \ << 1, vector<RangeAddPointGet<S>>(2));\n        ds_size.resize(n << 1, vector<int>(2));\n\
    \        dead.resize(n, false);\n        subtree_size.resize(n << 1);\n      \
    \  leaf.resize(n);\n        dinfo.resize(n);\n        reorder(uniform_int_distribution<int>(0,\
    \ n - 1)(eng));\n        vector<vector<int>> tmp(n);\n        vector<int> par_cr(n\
    \ << 1, -1);\n        vector<int> head(n << 1);\n        vector<int> tail(n <<\
    \ 1);\n        vector<int> link(n << 1, -1);\n        vector<S> d(n * 3);\n  \
    \      for (int i = 0; i < n; i++) {\n            head[i] = tail[i] = i;\n   \
    \     }\n\n        for (int u = 0; u < n; u++) {\n            for (const int v\
    \ : g[u]) {\n                tmp[ord[u]].emplace_back(ord[v]);\n            }\n\
    \            leaf[ord[u]] = a[u];\n        }\n        g = tmp;\n\n        function<int(int,\
    \ int)> rec = [&](int start, int sz) -> int {\n            int c = -1;\n     \
    \       const auto get_centroid = [&](auto &&self, int u, int p) -> void {\n \
    \               subtree_size[u] = 1;\n                for (const int v : g[u])\
    \ {\n                    if (v == p || dead[v]) continue;\n\n                \
    \    self(self, v, u);\n                    if (v == c) {\n                  \
    \      subtree_size[u] = sz - subtree_size[c];\n                        break;\n\
    \                    }\n\n                    subtree_size[u] += subtree_size[v];\n\
    \                }\n\n                if (c == -1 && subtree_size[u] * 2 > sz)\
    \ c = u;\n            };\n\n            get_centroid(get_centroid, start, -1);\n\
    \            dead[c] = true;\n            for (const int u : g[c]) {\n       \
    \         if (dead[u]) continue;\n                const int comp_sz = subtree_size[u];\n\
    \                par_cr[u] = rec(u, comp_sz);\n                subtree_size[u]\
    \ = comp_sz;\n            }\n\n            const auto compare = [&](int i, int\
    \ j) {\n                return subtree_size[i] > subtree_size[j];\n          \
    \  };\n\n            priority_queue<int, vector<int>, decltype(compare)> pq{compare};\n\
    \n            for (const int v : g[c]) {\n                if (dead[v]) continue;\n\
    \                link[v] = -1;\n                pq.push(v);\n            }\n\n\
    \            const auto build_data_structure = [&](const int root_head, const\
    \ int child_index) {\n                queue<pair<int, int>> q;\n             \
    \   for (int root = root_head; root >= 0; root = link[root]) {\n             \
    \       q.emplace(root, -1);\n                }\n\n                S x = 0;\n\
    \                int idx = 0;\n                int nxt = -1;\n               \
    \ while (!q.empty()) {\n                    int cur = q.front().first;\n     \
    \               int prev = q.front().second;\n                    q.pop();\n \
    \                   if (cur == nxt) {\n                        d[idx++] = exchange(x,\
    \ 0);\n                        nxt = -1;\n                    }\n\n          \
    \          info[cur][dinfo[cur]++] = {child_index, idx};\n                   \
    \ x += leaf[cur];\n\n                    for (const int v : g[cur]) {\n      \
    \                  if (v == prev or dead[v]) continue;\n                     \
    \   q.emplace(v, cur);\n                        if (nxt == -1) nxt = v;\n    \
    \                }\n                }\n                d[idx++] = x;\n       \
    \         return idx;\n            };\n\n            while (pq.size() >= 2) {\n\
    \                const int p1 = pq.top();\n                pq.pop();\n       \
    \         const int p2 = pq.top();\n                pq.pop();\n              \
    \  if (pq.empty()) {\n                    parent[par_cr[p1]] = parent[par_cr[p2]]\
    \ = c;\n                    ds_size[c][0] = build_data_structure(head[p1], 0);\n\
    \                    subtrees[c][0] = RangeAddPointGet<S>(ds_size[c][0]);\n  \
    \                  ds_size[c][1] = build_data_structure(head[p2], 1);\n      \
    \              subtrees[c][1] = RangeAddPointGet<S>(ds_size[c][1]);\n        \
    \            break;\n                }\n                subtree_size[node_idx]\
    \ = subtree_size[p1] + subtree_size[p2];\n                par_cr[node_idx] = node_idx;\n\
    \                parent[par_cr[p1]] = parent[par_cr[p2]] = node_idx;\n       \
    \         ds_size[node_idx][0] = build_data_structure(head[p1], 0);\n        \
    \        subtrees[node_idx][0] = RangeAddPointGet<S>(ds_size[node_idx][0]);\n\
    \                ds_size[node_idx][1] = build_data_structure(head[p2], 1);\n \
    \               subtrees[node_idx][1] = RangeAddPointGet<S>(ds_size[node_idx][1]);\n\
    \                head[node_idx] = head[p1];\n                tail[node_idx] =\
    \ tail[p2];\n                link[tail[p1]] = head[p2];\n                pq.push(node_idx);\n\
    \                node_idx++;\n            }\n\n            if (!pq.empty()) {\n\
    \                int u = pq.top();\n                pq.pop();\n              \
    \  parent[par_cr[u]] = c;\n                ds_size[c][0] = build_data_structure(head[u],\
    \ 0);\n                subtrees[c][0] = RangeAddPointGet<S>(ds_size[c][0]);\n\
    \            }\n            dead[c] = false;\n            return c;\n        };\n\
    \n        rec(0, n);\n        parent.resize(node_idx);\n        parent.shrink_to_fit();\n\
    \        subtrees.resize(node_idx);\n        subtrees.shrink_to_fit();\n    }\n\
    \n    S get(int p) {\n        S ret = 0;\n        p = ord[p];\n        ret +=\
    \ leaf[p];\n        int cur = parent[p];\n        for (int i = 0; i < dinfo[p];\
    \ i++) {\n            const auto &[b, dist] = info[p][i];\n            ret +=\
    \ subtrees[exchange(cur, parent[cur])][b].point_get(dist);\n        }\n      \
    \  return ret;\n    }\n\n    void add(int p, int lower, int upper, S x) {\n  \
    \      p = ord[p];\n        if (lower <= 0 and 0 < upper) leaf[p] += x;\n    \
    \    ds_add(subtrees[p][0], ds_size[p][0], lower - 1, upper - 1, x);\n       \
    \ ds_add(subtrees[p][1], ds_size[p][1], lower - 1, upper - 1, x);\n        int\
    \ v = parent[p];\n        for (int i = 0; i < dinfo[p]; i++) {\n            const\
    \ auto &[b, dist] = info[p][i];\n            int ql = lower - dist - 1;\n    \
    \        int qr = upper - dist - 1;\n            if (v < n and ql <= 0 and 0 <\
    \ qr) leaf[v] += x;\n            ds_add(subtrees[exchange(v, parent[v])][b ^ 1],\
    \ ds_size[v][b ^ 1], ql - 1, qr - 1, x);\n        }\n    }\n};"
  dependsOn:
  - data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
  isVerificationFile: false
  path: graph/tree/CentroidDecompositionContourAdd.hpp
  requiredBy: []
  timestamp: '2025-05-03 17:00:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/CentroidDecompositionContourAdd.hpp
layout: document
title: Centroid Decomposition (Contour Add)
---

## 概要

todo

## 計算量
todo