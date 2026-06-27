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
  bundledCode: "#line 1 \"graph/others/CycleBasis.hpp\"\nvector<vector<int>> compress_graph(const\
    \ vector<vector<int>>& g) {\n  int n = (int)g.size();\n\n  vector<int> deg(n);\n\
    \  vector<char> alive(n, true);\n  queue<int> que;\n  vector<set<int>> h;\n  vector<char>\
    \ is_branch(n, false);\n  vector<int> id(n, -1);\n\n  auto new_vertex = [&]()\
    \ {\n    int id = (int)h.size();\n    h.emplace_back();\n    return id;\n  };\n\
    \n  auto add_edge = [&](int a, int b) {\n    if (a == b) return;\n    if (h[a].contains(b))\
    \ return;\n    h[a].insert(b);\n    h[b].insert(a);\n  };\n\n  auto add_compressed_path\
    \ = [&](int a, int b) {\n    if (a == b) {\n      int x = new_vertex();\n    \
    \  int y = new_vertex();\n      add_edge(a, x);\n      add_edge(x, y);\n     \
    \ add_edge(y, a);\n      return;\n    }\n\n    if (!h[a].contains(b)) {\n    \
    \  add_edge(a, b);\n    } else {\n      int x = new_vertex();\n      add_edge(a,\
    \ x);\n      add_edge(x, b);\n    }\n  };\n\n  auto edge_key = [&](int a, int\
    \ b) {\n    if (a > b) swap(a, b);\n    return 1LL * a * n + b;\n  };\n\n  for\
    \ (int i = 0; i < n; i++) {\n    deg[i] = (int)g[i].size();\n    if (deg[i] <=\
    \ 1) que.push(i);\n  }\n\n  while (!que.empty()) {\n    int cur = que.front();\n\
    \    que.pop();\n    if (!alive[cur] or deg[cur] > 1) continue;\n    alive[cur]\
    \ = false;\n    for (int nex : g[cur]) {\n      if (!alive[nex]) continue;\n \
    \     deg[nex]--;\n      if (deg[nex] == 1) que.push(nex);\n    }\n  }\n\n  for\
    \ (int i = 0; i < n; i++) {\n    if (!alive[i]) continue;\n    if (deg[i] != 2)\
    \ {\n      is_branch[i] = true;\n      id[i] = new_vertex();\n    }\n  }\n\n \
    \ unordered_set<long long> used_edge;\n  vector<char> visited(n, false);\n  for\
    \ (int i = 0; i < n; i++) {\n    if (!alive[i] or !is_branch[i]) continue;\n\n\
    \    for (int nex : g[i]) {\n      if (!alive[nex]) continue;\n      long long\
    \ hash = edge_key(i, nex);\n      if (used_edge.contains(hash)) continue;\n  \
    \    used_edge.insert(hash);\n\n      int prev = i;\n      int cur = nex;\n\n\
    \      while (!is_branch[cur]) {\n        visited[cur] = true;\n        int nxt\
    \ = -1;\n        for (int x : g[cur]) {\n          if (!alive[x] or x == prev)\
    \ continue;\n          nxt = x;\n          break;\n        }\n        used_edge.insert(edge_key(cur,\
    \ nxt));\n        prev = cur;\n        cur = nxt;\n      }\n      add_compressed_path(id[i],\
    \ id[cur]);\n    }\n  }\n\n  for (int i = 0; i < n; i++) {\n    if (!alive[i]\
    \ or is_branch[i] or visited[i]) continue;\n    int a = new_vertex();\n    int\
    \ b = new_vertex();\n    int c = new_vertex();\n\n    add_edge(a, b);\n    add_edge(b,\
    \ c);\n    add_edge(c, a);\n\n    queue<int> q;\n    q.push(i);\n    visited[i]\
    \ = true;\n\n    while (!q.empty()) {\n      int cur = q.front();\n      q.pop();\n\
    \      for (int nex : g[cur]) {\n        if (!alive[nex]) continue;\n        if\
    \ (is_branch[nex]) continue;\n        if (visited[nex]) continue;\n        visited[nex]\
    \ = true;\n        q.push(nex);\n      }\n    }\n  }\n\n  vector<vector<int>>\
    \ res(h.size());\n  for (int i = 0; i < (int)h.size(); i++) {\n    for (int nex\
    \ : h[i]) {\n      res[i].push_back(nex);\n    }\n  }\n\n  return res;\n}\n\n\
    struct cycle_basis {\n private:\n  int n, m, c;\n  int t = 0;\n  vector<vector<pair<int,\
    \ int>>> g;\n  vector<int> time;\n  vector<pair<int, int>> par;\n\n  void dfs(int\
    \ cur) {\n    time[cur] = ++t;\n    for (auto [nex, eid] : g[cur]) {\n      if\
    \ (time[nex] == 0) {\n        par[nex] = {cur, eid};\n        dfs(nex);\n    \
    \  } else if (time[cur] < time[nex]) {\n        //  out(\"getbasis\", cur, nex);\n\
    \        basis.emplace_back(get_basis(cur, nex, eid));\n        //  out(basis.back().to_string());\n\
    \      }\n    }\n  }\n\n  tr2::dynamic_bitset<> get_basis(int u, int v, int id)\
    \ {\n    tr2::dynamic_bitset<> b(m);\n    b[id] = 1;\n    while (u != v) {\n \
    \     if (time[u] < time[v]) {\n        auto [p, eid] = par[v];\n        b[eid]\
    \ = 1;\n        v = p;\n      } else {\n        auto [p, eid] = par[u];\n    \
    \    b[eid] = 1;\n        u = p;\n      }\n    }\n    return b;\n  }\n\n public:\n\
    \  vector<tr2::dynamic_bitset<>> basis;\n  vector<pair<int, int>> edge;\n\n  cycle_basis(int\
    \ n) : n(n), g(n), time(n), par(n, {-1, -1}), m(0) {}\n\n  void add_edge(int u,\
    \ int v) {\n    assert(0 <= u and u < n and 0 <= v and v < n);\n    g[u].emplace_back(v,\
    \ m);\n    g[v].emplace_back(u, m);\n    edge.emplace_back(u, v);\n    m++;\n\
    \  }\n\n  void build() {\n    for (int i = 0; i < n; i++) {\n      if (time[i]\
    \ == 0) {\n        c++;\n        dfs(i);\n      }\n    }\n  }\n\n  void solve()\
    \ {\n    int siz = int(basis.size());\n  }\n};\n"
  code: "vector<vector<int>> compress_graph(const vector<vector<int>>& g) {\n  int\
    \ n = (int)g.size();\n\n  vector<int> deg(n);\n  vector<char> alive(n, true);\n\
    \  queue<int> que;\n  vector<set<int>> h;\n  vector<char> is_branch(n, false);\n\
    \  vector<int> id(n, -1);\n\n  auto new_vertex = [&]() {\n    int id = (int)h.size();\n\
    \    h.emplace_back();\n    return id;\n  };\n\n  auto add_edge = [&](int a, int\
    \ b) {\n    if (a == b) return;\n    if (h[a].contains(b)) return;\n    h[a].insert(b);\n\
    \    h[b].insert(a);\n  };\n\n  auto add_compressed_path = [&](int a, int b) {\n\
    \    if (a == b) {\n      int x = new_vertex();\n      int y = new_vertex();\n\
    \      add_edge(a, x);\n      add_edge(x, y);\n      add_edge(y, a);\n      return;\n\
    \    }\n\n    if (!h[a].contains(b)) {\n      add_edge(a, b);\n    } else {\n\
    \      int x = new_vertex();\n      add_edge(a, x);\n      add_edge(x, b);\n \
    \   }\n  };\n\n  auto edge_key = [&](int a, int b) {\n    if (a > b) swap(a, b);\n\
    \    return 1LL * a * n + b;\n  };\n\n  for (int i = 0; i < n; i++) {\n    deg[i]\
    \ = (int)g[i].size();\n    if (deg[i] <= 1) que.push(i);\n  }\n\n  while (!que.empty())\
    \ {\n    int cur = que.front();\n    que.pop();\n    if (!alive[cur] or deg[cur]\
    \ > 1) continue;\n    alive[cur] = false;\n    for (int nex : g[cur]) {\n    \
    \  if (!alive[nex]) continue;\n      deg[nex]--;\n      if (deg[nex] == 1) que.push(nex);\n\
    \    }\n  }\n\n  for (int i = 0; i < n; i++) {\n    if (!alive[i]) continue;\n\
    \    if (deg[i] != 2) {\n      is_branch[i] = true;\n      id[i] = new_vertex();\n\
    \    }\n  }\n\n  unordered_set<long long> used_edge;\n  vector<char> visited(n,\
    \ false);\n  for (int i = 0; i < n; i++) {\n    if (!alive[i] or !is_branch[i])\
    \ continue;\n\n    for (int nex : g[i]) {\n      if (!alive[nex]) continue;\n\
    \      long long hash = edge_key(i, nex);\n      if (used_edge.contains(hash))\
    \ continue;\n      used_edge.insert(hash);\n\n      int prev = i;\n      int cur\
    \ = nex;\n\n      while (!is_branch[cur]) {\n        visited[cur] = true;\n  \
    \      int nxt = -1;\n        for (int x : g[cur]) {\n          if (!alive[x]\
    \ or x == prev) continue;\n          nxt = x;\n          break;\n        }\n \
    \       used_edge.insert(edge_key(cur, nxt));\n        prev = cur;\n        cur\
    \ = nxt;\n      }\n      add_compressed_path(id[i], id[cur]);\n    }\n  }\n\n\
    \  for (int i = 0; i < n; i++) {\n    if (!alive[i] or is_branch[i] or visited[i])\
    \ continue;\n    int a = new_vertex();\n    int b = new_vertex();\n    int c =\
    \ new_vertex();\n\n    add_edge(a, b);\n    add_edge(b, c);\n    add_edge(c, a);\n\
    \n    queue<int> q;\n    q.push(i);\n    visited[i] = true;\n\n    while (!q.empty())\
    \ {\n      int cur = q.front();\n      q.pop();\n      for (int nex : g[cur])\
    \ {\n        if (!alive[nex]) continue;\n        if (is_branch[nex]) continue;\n\
    \        if (visited[nex]) continue;\n        visited[nex] = true;\n        q.push(nex);\n\
    \      }\n    }\n  }\n\n  vector<vector<int>> res(h.size());\n  for (int i = 0;\
    \ i < (int)h.size(); i++) {\n    for (int nex : h[i]) {\n      res[i].push_back(nex);\n\
    \    }\n  }\n\n  return res;\n}\n\nstruct cycle_basis {\n private:\n  int n, m,\
    \ c;\n  int t = 0;\n  vector<vector<pair<int, int>>> g;\n  vector<int> time;\n\
    \  vector<pair<int, int>> par;\n\n  void dfs(int cur) {\n    time[cur] = ++t;\n\
    \    for (auto [nex, eid] : g[cur]) {\n      if (time[nex] == 0) {\n        par[nex]\
    \ = {cur, eid};\n        dfs(nex);\n      } else if (time[cur] < time[nex]) {\n\
    \        //  out(\"getbasis\", cur, nex);\n        basis.emplace_back(get_basis(cur,\
    \ nex, eid));\n        //  out(basis.back().to_string());\n      }\n    }\n  }\n\
    \n  tr2::dynamic_bitset<> get_basis(int u, int v, int id) {\n    tr2::dynamic_bitset<>\
    \ b(m);\n    b[id] = 1;\n    while (u != v) {\n      if (time[u] < time[v]) {\n\
    \        auto [p, eid] = par[v];\n        b[eid] = 1;\n        v = p;\n      }\
    \ else {\n        auto [p, eid] = par[u];\n        b[eid] = 1;\n        u = p;\n\
    \      }\n    }\n    return b;\n  }\n\n public:\n  vector<tr2::dynamic_bitset<>>\
    \ basis;\n  vector<pair<int, int>> edge;\n\n  cycle_basis(int n) : n(n), g(n),\
    \ time(n), par(n, {-1, -1}), m(0) {}\n\n  void add_edge(int u, int v) {\n    assert(0\
    \ <= u and u < n and 0 <= v and v < n);\n    g[u].emplace_back(v, m);\n    g[v].emplace_back(u,\
    \ m);\n    edge.emplace_back(u, v);\n    m++;\n  }\n\n  void build() {\n    for\
    \ (int i = 0; i < n; i++) {\n      if (time[i] == 0) {\n        c++;\n       \
    \ dfs(i);\n      }\n    }\n  }\n\n  void solve() {\n    int siz = int(basis.size());\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/others/CycleBasis.hpp
  requiredBy: []
  timestamp: '2026-06-27 20:53:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/others/CycleBasis.hpp
layout: document
title: Cycle Basis
---

## 概要

todo

## 計算量
todo