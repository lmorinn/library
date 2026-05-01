---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
    title: verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-tree/SegmentTree.hpp\"\ntemplate\
    \ <class S, auto op, auto e>\nstruct segtree {\n private:\n  unsigned int seg_bit_ceil(unsigned\
    \ int n) {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n\
    \    return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  segtree()\
    \ : segtree(0) {}\n  explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    size\
    \ = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n  \
    \    update(i);\n    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p &&\
    \ p < _n);\n    p += size;\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) const {\n    assert(0 <= p && p < _n);\n\
    \    return d[p + size];\n  }\n\n  S prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= _n);\n    S sml = e(), smr = e();\n    l += size;\n \
    \   r += size;\n\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n\
    \  template <bool (*f)(S)>\n  int max_right(int l) const {\n    return max_right(l,\
    \ [](S x) { return f(x); });\n  }\n  template <class F>\n  int max_right(int l,\
    \ F f) const {\n    assert(0 <= l && l <= _n);\n    assert(f(e()));\n    if (l\
    \ == _n) return _n;\n    l += size;\n    S sm = e();\n    do {\n      while (l\
    \ % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < size)\
    \ {\n          l = (2 * l);\n          if (f(op(sm, d[l]))) {\n            sm\
    \ = op(sm, d[l]);\n            l++;\n          }\n        }\n        return l\
    \ - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l)\
    \ != l);\n    return _n;\n  }\n\n  template <bool (*f)(S)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n    S sm = e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r],\
    \ sm))) {\n        while (r < size) {\n          r = (2 * r + 1);\n          if\
    \ (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = op(d[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n,\
    \ size, log;\n  std::vector<S> d;\n\n  void update(int k) { d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n};\n#line 2 \"graph/tree/LowestCommonAncestor.hpp\"\nclass\
    \ TreeQuery {\n private:\n  struct S {\n    int val, id;\n  };\n  static S op(S\
    \ a, S b) {\n    if (a.val < b.val) {\n      return a;\n    }\n    return b;\n\
    \  }\n\n  static S e() {\n    return {100000000, -1};\n  }\n\n  vector<vector<int>>\
    \ g;\n  int n, root;\n  int cnt = 0;\n  vector<int> st, dep;\n  segtree<S, op,\
    \ e> rmq;\n\n  void build() {\n    int time = 0;\n    vector<S> v;\n    auto dfs\
    \ = [&](auto& self, int cur, int prev, int d) -> void {\n      st[cur] = time++;\n\
    \      dep[cur] = d;\n      v.emplace_back(d, cur);\n      for (auto nex : g[cur])\
    \ {\n        if (nex == prev) continue;\n        self(self, nex, cur, d + 1);\n\
    \        v.emplace_back(d, cur);\n        time++;\n      }\n    };\n    dfs(dfs,\
    \ root, -1, 0);\n    rmq = segtree<S, op, e>(v);\n  }\n\n public:\n  TreeQuery(int\
    \ n, int root = 0) : n(n), root(root) {\n    g.resize(n);\n    st.resize(n);\n\
    \    dep.resize(n);\n  }\n\n  void add_edge(int u, int v) {\n    assert(cnt <\
    \ n - 1);\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n    if (++cnt\
    \ == n - 1) build();\n  }\n\n  int lca(int u, int v) {\n    int l = st[u];\n \
    \   int r = st[v];\n    if (l > r) swap(l, r);\n    return rmq.prod(l, r + 1).id;\n\
    \  }\n\n  int dist(int u, int v) {\n    return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n  }\n\n  bool contains(int u, int v, int x) {\n    return dist(u, x) +\
    \ dist(x, v) == dist(u, v);\n  }\n};\n"
  code: "#include \"../../data-structure/segment-tree/SegmentTree.hpp\"\nclass TreeQuery\
    \ {\n private:\n  struct S {\n    int val, id;\n  };\n  static S op(S a, S b)\
    \ {\n    if (a.val < b.val) {\n      return a;\n    }\n    return b;\n  }\n\n\
    \  static S e() {\n    return {100000000, -1};\n  }\n\n  vector<vector<int>> g;\n\
    \  int n, root;\n  int cnt = 0;\n  vector<int> st, dep;\n  segtree<S, op, e> rmq;\n\
    \n  void build() {\n    int time = 0;\n    vector<S> v;\n    auto dfs = [&](auto&\
    \ self, int cur, int prev, int d) -> void {\n      st[cur] = time++;\n      dep[cur]\
    \ = d;\n      v.emplace_back(d, cur);\n      for (auto nex : g[cur]) {\n     \
    \   if (nex == prev) continue;\n        self(self, nex, cur, d + 1);\n       \
    \ v.emplace_back(d, cur);\n        time++;\n      }\n    };\n    dfs(dfs, root,\
    \ -1, 0);\n    rmq = segtree<S, op, e>(v);\n  }\n\n public:\n  TreeQuery(int n,\
    \ int root = 0) : n(n), root(root) {\n    g.resize(n);\n    st.resize(n);\n  \
    \  dep.resize(n);\n  }\n\n  void add_edge(int u, int v) {\n    assert(cnt < n\
    \ - 1);\n    g[u].emplace_back(v);\n    g[v].emplace_back(u);\n    if (++cnt ==\
    \ n - 1) build();\n  }\n\n  int lca(int u, int v) {\n    int l = st[u];\n    int\
    \ r = st[v];\n    if (l > r) swap(l, r);\n    return rmq.prod(l, r + 1).id;\n\
    \  }\n\n  int dist(int u, int v) {\n    return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n  }\n\n  bool contains(int u, int v, int x) {\n    return dist(u, x) +\
    \ dist(x, v) == dist(u, v);\n  }\n};"
  dependsOn:
  - data-structure/segment-tree/SegmentTree.hpp
  isVerificationFile: false
  path: graph/tree/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2026-05-01 18:46:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
documentation_of: graph/tree/LowestCommonAncestor.hpp
layout: document
title: Lowest Common Ancestor
---

## 概要

todo

## 計算量
todo