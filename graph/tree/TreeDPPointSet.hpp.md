---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
    title: verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
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
    \ d[2 * k + 1]); }\n};\n#line 2 \"graph/tree/TreeDPPointSet.hpp\"\n\ntemplate\
    \ <class Path, auto compress, auto Path_e, class Point, auto rake, auto Point_e,\
    \ auto add_v, auto add_e, auto vertex>\nstruct hld {\n private:\n  int n, root;\n\
    \  vector<vector<int>> g;\n  vector<int> heavy_p, heavy_l, light_p, idx, idx_c;\n\
    \  segtree<Path, compress, Path_e> seg;\n  segtree<Point, rake, Point_e> seg2;\n\
    \n  int dfs(int cur, int prev) {\n    int sub = 1;\n    for (int& nex : g[cur])\
    \ {\n      if (nex == prev) {\n        swap(g[cur].back(), nex);\n        g[cur].pop_back();\n\
    \        break;\n      }\n    }\n    int best = 0;\n    int idx = -1;\n    for\
    \ (int i = 0; i < int(g[cur].size()); i++) {\n      int cnt = dfs(g[cur][i], cur);\n\
    \      sub += cnt;\n      if (best < cnt) {\n        best = cnt;\n        idx\
    \ = i;\n      }\n    }\n    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());\n\
    \    for (int i = 1; i < int(g[cur].size()); i++) light_p[g[cur][i]] = cur;\n\
    \    return sub;\n  }\n\n  void dfs2(int cur, int top, int& id, int& id2) {\n\
    \    heavy_p[cur] = top;\n    idx[cur] = --id;\n    if (!g[cur].empty()) {\n \
    \     dfs2(g[cur].front(), top, id, id2);\n      heavy_l[cur] = heavy_l[g[cur].front()];\n\
    \    } else {\n      heavy_l[cur] = cur;\n    }\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) dfs2(g[cur][i], g[cur][i], id, id2);\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) idx_c[g[cur][i]] = id2++;\n  }\n\n  Point init_segtree(int top, vector<Path>&\
    \ init_path, vector<Point>& init_point) {\n    vector<int> heavy_path;\n    int\
    \ v = top;\n    while (1) {\n      heavy_path.emplace_back(v);\n      if (g[v].empty())\
    \ break;\n      v = g[v].front();\n    }\n    for (int v : heavy_path) {\n   \
    \   Point light = Point_e();\n      for (int i = 1; i < int(g[v].size()); i++)\
    \ {\n        int ch = g[v][i];\n        Point child_point = init_segtree(ch, init_path,\
    \ init_point);\n        init_point[idx_c[ch]] = child_point;\n        light =\
    \ rake(light, child_point);\n      }\n      if (g[v].size() > 1) {\n        init_path[idx[v]]\
    \ = add_v(v, light);\n      } else {\n        init_path[idx[v]] = vertex(v);\n\
    \      }\n    }\n    Path path = Path_e();\n    for (int i = int(heavy_path.size())\
    \ - 1; i >= 0; i--) {\n      int v = heavy_path[i];\n      path = compress(path,\
    \ init_path[idx[v]]);\n    }\n    return add_e(path);\n  }\n\n public:\n  hld(int\
    \ n, int root = 0) : n(n), root(root), g(n), heavy_p(n, -1), heavy_l(n, -1), light_p(n,\
    \ -1), idx(n), idx_c(n) {}\n\n  void add_edge(int u, int v) {\n    g[u].emplace_back(v);\n\
    \    g[v].emplace_back(u);\n  }\n\n  void build(int root = 0) {\n    int id =\
    \ n;\n    int id2 = 0;\n    dfs(root, -1);\n    dfs2(root, root, id, id2);\n \
    \   vector<Path> init_path(n, Path_e());\n    vector<Point> init_point(n, Point_e());\n\
    \    init_segtree(root, init_path, init_point);\n    seg = segtree<Path, compress,\
    \ Path_e>(init_path);\n    seg2 = segtree<Point, rake, Point_e>(init_point);\n\
    \  }\n\n  Path tree_dp() {\n    return seg.prod(idx[heavy_l[root]], idx[root]\
    \ + 1);\n  }\n\n  void set(int i) {\n    while (1) {\n      if (g[i].size() >\
    \ 1) {\n        int ch_num = int(g[i].size()) - 1;\n        if (ch_num == 1) {\n\
    \          seg.set(idx[i], add_v(i, seg2.get(idx_c[g[i][1]])));\n        } else\
    \ {\n          seg.set(idx[i], add_v(i, seg2.prod(idx_c[g[i][1]], idx_c[g[i][1]]\
    \ + ch_num)));\n        }\n      } else {\n        seg.set(idx[i], vertex(i));\n\
    \      }\n      int nex = light_p[heavy_p[i]];\n      if (nex == -1) break;\n\
    \      int l = idx[heavy_l[heavy_p[i]]];\n      int r = idx[heavy_p[i]] + 1;\n\
    \      if (r - l == 1) {\n        seg2.set(idx_c[heavy_p[i]], add_e(seg.get(l)));\n\
    \      } else {\n        seg2.set(idx_c[heavy_p[i]], add_e(seg.prod(l, r)));\n\
    \      }\n      i = nex;\n    }\n  }\n};\n"
  code: "#include \"../../data-structure/segment-tree/SegmentTree.hpp\"\n\ntemplate\
    \ <class Path, auto compress, auto Path_e, class Point, auto rake, auto Point_e,\
    \ auto add_v, auto add_e, auto vertex>\nstruct hld {\n private:\n  int n, root;\n\
    \  vector<vector<int>> g;\n  vector<int> heavy_p, heavy_l, light_p, idx, idx_c;\n\
    \  segtree<Path, compress, Path_e> seg;\n  segtree<Point, rake, Point_e> seg2;\n\
    \n  int dfs(int cur, int prev) {\n    int sub = 1;\n    for (int& nex : g[cur])\
    \ {\n      if (nex == prev) {\n        swap(g[cur].back(), nex);\n        g[cur].pop_back();\n\
    \        break;\n      }\n    }\n    int best = 0;\n    int idx = -1;\n    for\
    \ (int i = 0; i < int(g[cur].size()); i++) {\n      int cnt = dfs(g[cur][i], cur);\n\
    \      sub += cnt;\n      if (best < cnt) {\n        best = cnt;\n        idx\
    \ = i;\n      }\n    }\n    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());\n\
    \    for (int i = 1; i < int(g[cur].size()); i++) light_p[g[cur][i]] = cur;\n\
    \    return sub;\n  }\n\n  void dfs2(int cur, int top, int& id, int& id2) {\n\
    \    heavy_p[cur] = top;\n    idx[cur] = --id;\n    if (!g[cur].empty()) {\n \
    \     dfs2(g[cur].front(), top, id, id2);\n      heavy_l[cur] = heavy_l[g[cur].front()];\n\
    \    } else {\n      heavy_l[cur] = cur;\n    }\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) dfs2(g[cur][i], g[cur][i], id, id2);\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) idx_c[g[cur][i]] = id2++;\n  }\n\n  Point init_segtree(int top, vector<Path>&\
    \ init_path, vector<Point>& init_point) {\n    vector<int> heavy_path;\n    int\
    \ v = top;\n    while (1) {\n      heavy_path.emplace_back(v);\n      if (g[v].empty())\
    \ break;\n      v = g[v].front();\n    }\n    for (int v : heavy_path) {\n   \
    \   Point light = Point_e();\n      for (int i = 1; i < int(g[v].size()); i++)\
    \ {\n        int ch = g[v][i];\n        Point child_point = init_segtree(ch, init_path,\
    \ init_point);\n        init_point[idx_c[ch]] = child_point;\n        light =\
    \ rake(light, child_point);\n      }\n      if (g[v].size() > 1) {\n        init_path[idx[v]]\
    \ = add_v(v, light);\n      } else {\n        init_path[idx[v]] = vertex(v);\n\
    \      }\n    }\n    Path path = Path_e();\n    for (int i = int(heavy_path.size())\
    \ - 1; i >= 0; i--) {\n      int v = heavy_path[i];\n      path = compress(path,\
    \ init_path[idx[v]]);\n    }\n    return add_e(path);\n  }\n\n public:\n  hld(int\
    \ n, int root = 0) : n(n), root(root), g(n), heavy_p(n, -1), heavy_l(n, -1), light_p(n,\
    \ -1), idx(n), idx_c(n) {}\n\n  void add_edge(int u, int v) {\n    g[u].emplace_back(v);\n\
    \    g[v].emplace_back(u);\n  }\n\n  void build(int root = 0) {\n    int id =\
    \ n;\n    int id2 = 0;\n    dfs(root, -1);\n    dfs2(root, root, id, id2);\n \
    \   vector<Path> init_path(n, Path_e());\n    vector<Point> init_point(n, Point_e());\n\
    \    init_segtree(root, init_path, init_point);\n    seg = segtree<Path, compress,\
    \ Path_e>(init_path);\n    seg2 = segtree<Point, rake, Point_e>(init_point);\n\
    \  }\n\n  Path tree_dp() {\n    return seg.prod(idx[heavy_l[root]], idx[root]\
    \ + 1);\n  }\n\n  void set(int i) {\n    while (1) {\n      if (g[i].size() >\
    \ 1) {\n        int ch_num = int(g[i].size()) - 1;\n        if (ch_num == 1) {\n\
    \          seg.set(idx[i], add_v(i, seg2.get(idx_c[g[i][1]])));\n        } else\
    \ {\n          seg.set(idx[i], add_v(i, seg2.prod(idx_c[g[i][1]], idx_c[g[i][1]]\
    \ + ch_num)));\n        }\n      } else {\n        seg.set(idx[i], vertex(i));\n\
    \      }\n      int nex = light_p[heavy_p[i]];\n      if (nex == -1) break;\n\
    \      int l = idx[heavy_l[heavy_p[i]]];\n      int r = idx[heavy_p[i]] + 1;\n\
    \      if (r - l == 1) {\n        seg2.set(idx_c[heavy_p[i]], add_e(seg.get(l)));\n\
    \      } else {\n        seg2.set(idx_c[heavy_p[i]], add_e(seg.prod(l, r)));\n\
    \      }\n      i = nex;\n    }\n  }\n};"
  dependsOn:
  - data-structure/segment-tree/SegmentTree.hpp
  isVerificationFile: false
  path: graph/tree/TreeDPPointSet.hpp
  requiredBy: []
  timestamp: '2026-05-27 15:27:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
documentation_of: graph/tree/TreeDPPointSet.hpp
layout: document
title: Tree DP Point Set
---

## 概要

todo

## 計算量
todo