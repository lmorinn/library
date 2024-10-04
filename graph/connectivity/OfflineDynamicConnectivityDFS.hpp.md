---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/union-find/UndoableUnionFind.hpp
    title: data-structure/union-find/UndoableUnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/union-find/UndoableUnionFind.hpp\"\n\ntemplate\
    \ <class S, auto op, auto e>\nclass UndoableUnionFind {\n private:\n  struct HistoryData\
    \ {\n    int u, datu;\n    S accu;\n    int v, datv;\n    S accv;\n    int comp_cnt;\n\
    \  };\n\n  vector<int> data;\n  vector<S> acc;\n  stack<HistoryData> history;\n\
    \  int cnt;\n  int snap;\n\n public:\n  UndoableUnionFind() {}\n  UndoableUnionFind(int\
    \ sz) {\n    data.assign(sz, -1);\n    cnt = sz;\n    acc.resize(sz, e());\n \
    \ }\n\n  bool unite(int u, int v) {\n    u = find(u), v = find(v);\n    history.emplace(u,\
    \ data[u], acc[u], v, data[v], acc[v], cnt);\n    if (u == v) return false;\n\
    \    if (data[u] > data[v]) swap(u, v);\n    data[u] += data[v];\n    data[v]\
    \ = u;\n    acc[u] = op(acc[u], acc[v]);\n    cnt--;\n    return true;\n  }\n\n\
    \  int find(int k) {\n    while (data[k] >= 0) {\n      k = data[k];\n    }\n\
    \    return k;\n  }\n\n  void update(int a, S x) {\n    a = find(a);\n    history.push({a,\
    \ data[a], acc[a], -1, -1, e(), -1});\n    acc[a] = op(acc[a], x);\n  }\n\n  S\
    \ prod_components(int a) {\n    return acc[find(a)];\n  }\n\n  bool same(int x,\
    \ int y) { return find(x) == find(y); }\n\n  int size(int k) { return (-data[find(k)]);\
    \ }\n\n  void undo() {\n    HistoryData h = history.top();\n    history.pop();\n\
    \    data[h.u] = h.datu;\n    acc[h.u] = h.accu;\n    if (h.v != -1) {\n     \
    \ data[h.v] = h.datv;\n      acc[h.v] = h.accv;\n      cnt = h.comp_cnt;\n   \
    \ }\n  }\n\n  int components() {\n    return cnt;\n  }\n};\n#line 3 \"graph/connectivity/OfflineDynamicConnectivityDFS.hpp\"\
    \n\n\ntemplate <class S, auto op, auto e>\nstruct OfflineDynamicConnectivity {\n\
    \ private:\n  struct Edge {\n    int from, to;\n  };\n\n  struct Query {\n   \
    \ int com;\n    int u, v;\n    int start;\n    int finish;\n    lint val;\n  };\n\
    \  vector<Query> q;\n  vector<S> res;\n  int outq = 0;\n  int n;\n  vector<unordered_map<int,\
    \ int>> ed;\n  vector<vector<Edge>> node;\n  vector<vector<pair<int, S>>> updates;\n\
    \  vector<int> val_idx;\n  UndoableUnionFind<S, op, e> d;\n  int vertex_siz;\n\
    \  int qtime;\n  int Q_INF = 1e8;\n  int idx = 0;\n\n  vector<vector<Query>> outputQuery;\n\
    \n  void add(int a, int b, Edge &ed, int k = 0, int l = 0, int r = -1) {\n   \
    \ if (r < 0) r = n;\n    if (r <= a || b <= l) return;\n    if (a <= l && r <=\
    \ b) {\n      node[k].emplace_back(ed);\n      return;\n    }\n    add(a, b, ed,\
    \ 2 * k + 1, l, (l + r) / 2);\n    add(a, b, ed, 2 * k + 2, (l + r) / 2, r);\n\
    \  }\n\n  void add_update(int a, int b, pair<int, S> x, int k = 0, int l = 0,\
    \ int r = -1) {\n    if (r < 0) r = n;\n    if (r <= a || b <= l) return;\n  \
    \  if (a <= l && r <= b) {\n      updates[k].emplace_back(x);\n      return;\n\
    \    }\n    add_update(a, b, x, 2 * k + 1, l, (l + r) / 2);\n    add_update(a,\
    \ b, x, 2 * k + 2, (l + r) / 2, r);\n  }\n\n  void execute(int k = 0) {\n    if\
    \ (outq == 0) return;\n    for (auto &ed : node[k]) {\n      d.unite(ed.from,\
    \ ed.to);\n    }\n\n    for (auto &p : updates[k]) {\n      d.update(p.first,\
    \ p.second);\n    }\n\n    if (k < n - 1) {\n      execute(2 * k + 1);\n     \
    \ execute(2 * k + 2);\n    } else if (k - (n - 1) < qtime) {\n      int qidx =\
    \ k - (n - 1);\n      for (auto cur : outputQuery[qidx]) {\n        int com =\
    \ cur.com;\n        int u = cur.u;\n        int v = cur.v;\n        if (com ==\
    \ 2) {\n          res.emplace_back(d.same(u, v));\n        } else if (com == 3)\
    \ {\n          res.emplace_back(d.components());\n        } else if (com == 4)\
    \ {\n          res.emplace_back(d.size(u));\n        } else if (com == 6) {\n\
    \          res.emplace_back(d.prod_components(u));\n        }\n      }\n    }\n\
    \    for (int i = 0; i < int(node[k].size() + updates[k].size()); i++) {\n   \
    \   d.undo();\n    }\n  }\n\n public:\n  OfflineDynamicConnectivity(int siz) {\n\
    \    d = UndoableUnionFind<S, op, e>(siz);\n    vertex_siz = siz;\n    ed.resize(siz);\n\
    \    val_idx.resize(siz, -1);\n  }\n\n  void link(int u, int v) {\n    if (u >\
    \ v) swap(u, v);\n    if (ed[u].find(v) != ed[u].end()) return;\n    qtime++;\n\
    \    q.push_back({0, u, v, qtime, Q_INF, 0});\n    ed[u][v] = idx;\n    idx++;\n\
    \  }\n\n  void cut(int u, int v) {\n    if (u > v) swap(u, v);\n    qtime++;\n\
    \    q.push_back({1, u, v, qtime, -1, 0});\n    int pos = ed[u][v];\n    q[pos].finish\
    \ = qtime;\n    ed[u].erase(v);\n    idx++;\n  }\n\n  void update(int u, lint\
    \ x) {\n    qtime++;\n    q.push_back({5, u, -1, qtime, Q_INF, x});\n    idx++;\n\
    \  }\n\n  void is_connected(int u, int v) {\n    if (u > v) swap(u, v);\n    q.push_back({2,\
    \ u, v, qtime, -1, 0});\n    idx++;\n    outq++;\n  }\n\n  void components() {\n\
    \    q.push_back({3, -1, -1, qtime, -1, 0});\n    idx++;\n    outq++;\n  }\n\n\
    \  void size(int u) {\n    q.push_back({4, u, -1, qtime, -1, 0});\n    idx++;\n\
    \    outq++;\n  }\n\n  void prod(int u) {\n    q.push_back({6, u, -1, qtime, -1,\
    \ 0});\n    idx++;\n    outq++;\n  }\n\n  vector<S> build() {\n    qtime++;\n\n\
    \    int sz = qtime;\n    n = 1;\n    while (n < sz) n *= 2;\n    node.resize(2\
    \ * n - 1);\n    updates.resize(2 * n - 1);\n    outputQuery.resize(qtime);\n\
    \    for (int i = 0; i < q.size(); i++) {\n      if (q[i].com == 0) {\n      \
    \  Edge ed = {q[i].u, q[i].v};\n        add(q[i].start, min(q[i].finish, qtime),\
    \ ed);\n      } else if (q[i].com == 5) {\n        add_update(q[i].start, q[i].finish,\
    \ {q[i].u, q[i].val});\n      } else if (q[i].com != 1) {\n        outputQuery[q[i].start].emplace_back(q[i]);\n\
    \      }\n    }\n    execute();\n    return res;\n  }\n};\n\n\n"
  code: "#pragma once\n#include \"../../data-structure/union-find/UndoableUnionFind.hpp\"\
    \n\n\ntemplate <class S, auto op, auto e>\nstruct OfflineDynamicConnectivity {\n\
    \ private:\n  struct Edge {\n    int from, to;\n  };\n\n  struct Query {\n   \
    \ int com;\n    int u, v;\n    int start;\n    int finish;\n    lint val;\n  };\n\
    \  vector<Query> q;\n  vector<S> res;\n  int outq = 0;\n  int n;\n  vector<unordered_map<int,\
    \ int>> ed;\n  vector<vector<Edge>> node;\n  vector<vector<pair<int, S>>> updates;\n\
    \  vector<int> val_idx;\n  UndoableUnionFind<S, op, e> d;\n  int vertex_siz;\n\
    \  int qtime;\n  int Q_INF = 1e8;\n  int idx = 0;\n\n  vector<vector<Query>> outputQuery;\n\
    \n  void add(int a, int b, Edge &ed, int k = 0, int l = 0, int r = -1) {\n   \
    \ if (r < 0) r = n;\n    if (r <= a || b <= l) return;\n    if (a <= l && r <=\
    \ b) {\n      node[k].emplace_back(ed);\n      return;\n    }\n    add(a, b, ed,\
    \ 2 * k + 1, l, (l + r) / 2);\n    add(a, b, ed, 2 * k + 2, (l + r) / 2, r);\n\
    \  }\n\n  void add_update(int a, int b, pair<int, S> x, int k = 0, int l = 0,\
    \ int r = -1) {\n    if (r < 0) r = n;\n    if (r <= a || b <= l) return;\n  \
    \  if (a <= l && r <= b) {\n      updates[k].emplace_back(x);\n      return;\n\
    \    }\n    add_update(a, b, x, 2 * k + 1, l, (l + r) / 2);\n    add_update(a,\
    \ b, x, 2 * k + 2, (l + r) / 2, r);\n  }\n\n  void execute(int k = 0) {\n    if\
    \ (outq == 0) return;\n    for (auto &ed : node[k]) {\n      d.unite(ed.from,\
    \ ed.to);\n    }\n\n    for (auto &p : updates[k]) {\n      d.update(p.first,\
    \ p.second);\n    }\n\n    if (k < n - 1) {\n      execute(2 * k + 1);\n     \
    \ execute(2 * k + 2);\n    } else if (k - (n - 1) < qtime) {\n      int qidx =\
    \ k - (n - 1);\n      for (auto cur : outputQuery[qidx]) {\n        int com =\
    \ cur.com;\n        int u = cur.u;\n        int v = cur.v;\n        if (com ==\
    \ 2) {\n          res.emplace_back(d.same(u, v));\n        } else if (com == 3)\
    \ {\n          res.emplace_back(d.components());\n        } else if (com == 4)\
    \ {\n          res.emplace_back(d.size(u));\n        } else if (com == 6) {\n\
    \          res.emplace_back(d.prod_components(u));\n        }\n      }\n    }\n\
    \    for (int i = 0; i < int(node[k].size() + updates[k].size()); i++) {\n   \
    \   d.undo();\n    }\n  }\n\n public:\n  OfflineDynamicConnectivity(int siz) {\n\
    \    d = UndoableUnionFind<S, op, e>(siz);\n    vertex_siz = siz;\n    ed.resize(siz);\n\
    \    val_idx.resize(siz, -1);\n  }\n\n  void link(int u, int v) {\n    if (u >\
    \ v) swap(u, v);\n    if (ed[u].find(v) != ed[u].end()) return;\n    qtime++;\n\
    \    q.push_back({0, u, v, qtime, Q_INF, 0});\n    ed[u][v] = idx;\n    idx++;\n\
    \  }\n\n  void cut(int u, int v) {\n    if (u > v) swap(u, v);\n    qtime++;\n\
    \    q.push_back({1, u, v, qtime, -1, 0});\n    int pos = ed[u][v];\n    q[pos].finish\
    \ = qtime;\n    ed[u].erase(v);\n    idx++;\n  }\n\n  void update(int u, lint\
    \ x) {\n    qtime++;\n    q.push_back({5, u, -1, qtime, Q_INF, x});\n    idx++;\n\
    \  }\n\n  void is_connected(int u, int v) {\n    if (u > v) swap(u, v);\n    q.push_back({2,\
    \ u, v, qtime, -1, 0});\n    idx++;\n    outq++;\n  }\n\n  void components() {\n\
    \    q.push_back({3, -1, -1, qtime, -1, 0});\n    idx++;\n    outq++;\n  }\n\n\
    \  void size(int u) {\n    q.push_back({4, u, -1, qtime, -1, 0});\n    idx++;\n\
    \    outq++;\n  }\n\n  void prod(int u) {\n    q.push_back({6, u, -1, qtime, -1,\
    \ 0});\n    idx++;\n    outq++;\n  }\n\n  vector<S> build() {\n    qtime++;\n\n\
    \    int sz = qtime;\n    n = 1;\n    while (n < sz) n *= 2;\n    node.resize(2\
    \ * n - 1);\n    updates.resize(2 * n - 1);\n    outputQuery.resize(qtime);\n\
    \    for (int i = 0; i < q.size(); i++) {\n      if (q[i].com == 0) {\n      \
    \  Edge ed = {q[i].u, q[i].v};\n        add(q[i].start, min(q[i].finish, qtime),\
    \ ed);\n      } else if (q[i].com == 5) {\n        add_update(q[i].start, q[i].finish,\
    \ {q[i].u, q[i].val});\n      } else if (q[i].com != 1) {\n        outputQuery[q[i].start].emplace_back(q[i]);\n\
    \      }\n    }\n    execute();\n    return res;\n  }\n};\n\n\n"
  dependsOn:
  - data-structure/union-find/UndoableUnionFind.hpp
  isVerificationFile: false
  path: graph/connectivity/OfflineDynamicConnectivityDFS.hpp
  requiredBy: []
  timestamp: '2024-10-04 18:45:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/connectivity/OfflineDynamicConnectivityDFS.hpp
layout: document
title: Offline Dynamic Connectivity (DSU base)
---

## 概要

todo

## 計算量
todo