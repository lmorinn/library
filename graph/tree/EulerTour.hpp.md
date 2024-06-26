---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/others/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
    title: verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
    title: verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/SparseTable.hpp\"\ntemplate <class\
    \ T, auto f>\nclass SparseTable {\n private:\n  vector<vector<T>> st;\n  vector<int>\
    \ lookup;\n\n public:\n  SparseTable() {}\n\n  SparseTable(const vector<T> &v)\
    \ {\n    const int n = (int)v.size();\n    const int b = 32 - __builtin_clz(n);\n\
    \    st.assign(b, vector<T>(n));\n    for (int i = 0; i < v.size(); i++) {\n \
    \     st[0][i] = v[i];\n    }\n    \n    for (int i = 1; i < b; i++) {\n     \
    \ for (int j = 0; j + (1 << i) <= n; j++) {\n        st[i][j] = f(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n    lookup.resize(v.size()\
    \ + 1);\n    for (int i = 2; i < lookup.size(); i++) {\n      lookup[i] = lookup[i\
    \ >> 1] + 1;\n    }\n  }\n\n  inline T query(int l, int r) const {\n    int b\
    \ = lookup[r - l];\n    return f(st[b][l], st[b][r - (1 << b)]);\n  }\n};\n#line\
    \ 2 \"data-structure/segment-tree/SegmentTree.hpp\"\ntemplate <class S, auto op,\
    \ auto e>\nstruct segtree {\n private:\n  unsigned int seg_bit_ceil(unsigned int\
    \ n) {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n \
    \   return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
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
    \ d[2 * k + 1]); }\n};\n#line 4 \"graph/tree/EulerTour.hpp\"\nstruct SD {\n  int\
    \ depth;\n  int ind;\n};\nauto f = [](const SD x, const SD y) { if (x.depth <\
    \ y.depth) return x; else return y; };\ntemplate <class S, auto ops, auto es,\
    \ auto invs, class T, auto opt, auto et, auto invt>\nclass EulerTour {\n private:\n\
    \  int n;\n  vector<int> start, finish, parent, depth, euler_tour;\n  vector<SD>\
    \ depth_v;\n  vector<S> node_sum;\n  vector<T> edge_sum;\n  segtree<T, opt, et>\
    \ seg_e, pseg_e;\n  segtree<S, ops, es> seg_n, pseg_n;\n  SparseTable<SD, f> sp_d;\n\
    \  int time = 0;\n\n  void rec(int cur, int p, int d, vector<vector<pair<int,\
    \ S>>> &g) {\n    start[cur] = time++;\n    parent[cur] = p;\n    depth[cur] =\
    \ d;\n    for (auto nex : g[cur]) {\n      if (nex.first != p) {\n        rec(nex.first,\
    \ cur, d + 1, g);\n      }\n    }\n    finish[cur] = time++;\n  }\n\n  T root_path_edge(int\
    \ ind) {\n    return pseg_e.prod(1, start[ind] + 1);\n  }\n\n  S root_path_node(int\
    \ ind) {\n    return pseg_n.prod(0, start[ind] + 1);\n  }\n\n public:\n  ///@param\
    \ g g[from][j]={to,\u8FBA\u306E\u91CD\u307F}\n  ///@param node_num \u9802\u70B9\
    \u306E\u91CD\u307F\n  EulerTour(vector<vector<pair<int, S>>> &g, vector<S> node_num,\
    \ int root = 0) {\n    n = g.size();\n    start.resize(n);\n    finish.resize(n);\n\
    \    parent.resize(n);\n    euler_tour.resize(n * 2);\n    depth.resize(n);\n\
    \    node_sum.resize(n * 2, es());\n    edge_sum.resize(n * 2, et());\n    depth_v.resize(n\
    \ * 2, {INT_MAX / 10, -1});\n    rec(root, -1, 0, g);\n    for (int i = 0; i <\
    \ n; i++) {\n      euler_tour[start[i]] = i;\n      euler_tour[finish[i]] = -i;\n\
    \      node_sum[start[i]] = node_num[i];\n      depth_v[start[i]] = {depth[i],\
    \ start[i]};\n      if (i != root) {\n        for (auto nex : g[i]) {\n      \
    \    if (nex.first == parent[i]) {\n            edge_sum[start[i]] = nex.second;\n\
    \            break;\n          }\n        }\n      }\n    }\n    seg_e = segtree<T,\
    \ opt, et>(edge_sum);\n    seg_n = segtree<S, ops, es>(node_sum);\n\n    for (int\
    \ i = 0; i < n; i++) {\n      node_sum[finish[i]] = invs(node_num[i]);\n     \
    \ if (i != root) {\n        for (auto nex : g[i]) {\n          if (nex.first ==\
    \ parent[i]) {\n            edge_sum[finish[i]] = invt(nex.second);\n        \
    \    depth_v[finish[i]] = {depth[parent[-euler_tour[finish[i]]]], finish[i]};\n\
    \            break;\n          }\n        }\n      }\n    }\n    pseg_e = segtree<T,\
    \ opt, et>(edge_sum);\n    pseg_n = segtree<S, ops, es>(node_sum);\n    sp_d =\
    \ SparseTable<SD, f>(depth_v);\n  }\n\n  S get_node(int i) {\n    return seg_n.get(start[i]);\n\
    \  }\n\n  T subtree_edge(int ind) {\n    return seg_e.prod(start[ind] + 1, finish[ind]);\n\
    \  }\n\n  S subtree_node(int ind) {\n    return seg_n.prod(start[ind], finish[ind]);\n\
    \  }\n\n  T path_edge(int i, int j) {\n    int l = lca(i, j);\n    return root_path_edge(i)\
    \ + root_path_edge(j) - 2 * root_path_edge(l);\n  }\n\n  S path_node(int i, int\
    \ j) {\n    int l = lca(i, j);\n    return root_path_node(i) + root_path_node(j)\
    \ - 2 * root_path_node(l);\n  }\n\n  void update_weight_edge(int i, int j, T x)\
    \ {\n    if (i != parent[j]) swap(i, j);\n    seg_e.set(start[j], x);\n    pseg_e.set(start[j],\
    \ x);\n    pseg_e.set(finish[j], invt(x));\n  }\n\n  void update_weight_node(int\
    \ i, T x) {\n    seg_n.set(start[i], x);\n    pseg_n.set(start[i], x);\n    pseg_n.set(finish[i],\
    \ invt(x));\n  }\n\n  int lca(int i, int j) {\n    int res;\n    if (start[i]\
    \ > start[j]) swap(i, j);\n    SD id = sp_d.query(start[i], start[j] + 1);\n \
    \   if (euler_tour[id.ind] < 0) {\n      res = parent[-euler_tour[id.ind]];\n\
    \    } else {\n      res = euler_tour[id.ind];\n    }\n    return res;\n  }\n\
    };\n"
  code: "#pragma once\n#include \"../../data-structure/others/SparseTable.hpp\"\n\
    #include \"../../data-structure/segment-tree/SegmentTree.hpp\"\nstruct SD {\n\
    \  int depth;\n  int ind;\n};\nauto f = [](const SD x, const SD y) { if (x.depth\
    \ < y.depth) return x; else return y; };\ntemplate <class S, auto ops, auto es,\
    \ auto invs, class T, auto opt, auto et, auto invt>\nclass EulerTour {\n private:\n\
    \  int n;\n  vector<int> start, finish, parent, depth, euler_tour;\n  vector<SD>\
    \ depth_v;\n  vector<S> node_sum;\n  vector<T> edge_sum;\n  segtree<T, opt, et>\
    \ seg_e, pseg_e;\n  segtree<S, ops, es> seg_n, pseg_n;\n  SparseTable<SD, f> sp_d;\n\
    \  int time = 0;\n\n  void rec(int cur, int p, int d, vector<vector<pair<int,\
    \ S>>> &g) {\n    start[cur] = time++;\n    parent[cur] = p;\n    depth[cur] =\
    \ d;\n    for (auto nex : g[cur]) {\n      if (nex.first != p) {\n        rec(nex.first,\
    \ cur, d + 1, g);\n      }\n    }\n    finish[cur] = time++;\n  }\n\n  T root_path_edge(int\
    \ ind) {\n    return pseg_e.prod(1, start[ind] + 1);\n  }\n\n  S root_path_node(int\
    \ ind) {\n    return pseg_n.prod(0, start[ind] + 1);\n  }\n\n public:\n  ///@param\
    \ g g[from][j]={to,\u8FBA\u306E\u91CD\u307F}\n  ///@param node_num \u9802\u70B9\
    \u306E\u91CD\u307F\n  EulerTour(vector<vector<pair<int, S>>> &g, vector<S> node_num,\
    \ int root = 0) {\n    n = g.size();\n    start.resize(n);\n    finish.resize(n);\n\
    \    parent.resize(n);\n    euler_tour.resize(n * 2);\n    depth.resize(n);\n\
    \    node_sum.resize(n * 2, es());\n    edge_sum.resize(n * 2, et());\n    depth_v.resize(n\
    \ * 2, {INT_MAX / 10, -1});\n    rec(root, -1, 0, g);\n    for (int i = 0; i <\
    \ n; i++) {\n      euler_tour[start[i]] = i;\n      euler_tour[finish[i]] = -i;\n\
    \      node_sum[start[i]] = node_num[i];\n      depth_v[start[i]] = {depth[i],\
    \ start[i]};\n      if (i != root) {\n        for (auto nex : g[i]) {\n      \
    \    if (nex.first == parent[i]) {\n            edge_sum[start[i]] = nex.second;\n\
    \            break;\n          }\n        }\n      }\n    }\n    seg_e = segtree<T,\
    \ opt, et>(edge_sum);\n    seg_n = segtree<S, ops, es>(node_sum);\n\n    for (int\
    \ i = 0; i < n; i++) {\n      node_sum[finish[i]] = invs(node_num[i]);\n     \
    \ if (i != root) {\n        for (auto nex : g[i]) {\n          if (nex.first ==\
    \ parent[i]) {\n            edge_sum[finish[i]] = invt(nex.second);\n        \
    \    depth_v[finish[i]] = {depth[parent[-euler_tour[finish[i]]]], finish[i]};\n\
    \            break;\n          }\n        }\n      }\n    }\n    pseg_e = segtree<T,\
    \ opt, et>(edge_sum);\n    pseg_n = segtree<S, ops, es>(node_sum);\n    sp_d =\
    \ SparseTable<SD, f>(depth_v);\n  }\n\n  S get_node(int i) {\n    return seg_n.get(start[i]);\n\
    \  }\n\n  T subtree_edge(int ind) {\n    return seg_e.prod(start[ind] + 1, finish[ind]);\n\
    \  }\n\n  S subtree_node(int ind) {\n    return seg_n.prod(start[ind], finish[ind]);\n\
    \  }\n\n  T path_edge(int i, int j) {\n    int l = lca(i, j);\n    return root_path_edge(i)\
    \ + root_path_edge(j) - 2 * root_path_edge(l);\n  }\n\n  S path_node(int i, int\
    \ j) {\n    int l = lca(i, j);\n    return root_path_node(i) + root_path_node(j)\
    \ - 2 * root_path_node(l);\n  }\n\n  void update_weight_edge(int i, int j, T x)\
    \ {\n    if (i != parent[j]) swap(i, j);\n    seg_e.set(start[j], x);\n    pseg_e.set(start[j],\
    \ x);\n    pseg_e.set(finish[j], invt(x));\n  }\n\n  void update_weight_node(int\
    \ i, T x) {\n    seg_n.set(start[i], x);\n    pseg_n.set(start[i], x);\n    pseg_n.set(finish[i],\
    \ invt(x));\n  }\n\n  int lca(int i, int j) {\n    int res;\n    if (start[i]\
    \ > start[j]) swap(i, j);\n    SD id = sp_d.query(start[i], start[j] + 1);\n \
    \   if (euler_tour[id.ind] < 0) {\n      res = parent[-euler_tour[id.ind]];\n\
    \    } else {\n      res = euler_tour[id.ind];\n    }\n    return res;\n  }\n\
    };"
  dependsOn:
  - data-structure/others/SparseTable.hpp
  - data-structure/segment-tree/SegmentTree.hpp
  isVerificationFile: false
  path: graph/tree/EulerTour.hpp
  requiredBy: []
  timestamp: '2024-06-26 20:58:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
  - verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
documentation_of: graph/tree/EulerTour.hpp
layout: document
title: Euler Tour
---

## 概要

todo

## 計算量
todo