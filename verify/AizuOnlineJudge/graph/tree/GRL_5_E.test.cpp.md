---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: graph/tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
  bundledCode: "#line 1 \"verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n#line 1 \"data-structure/segment-tree/LazySegmentTree.hpp\"\
    \n\ntemplate <class S,\n          auto op,\n          auto e,\n          class\
    \ F,\n          auto mapping,\n          auto composition,\n          auto id>\n\
    struct lazy_segtree {\n private:\n  unsigned int seg_bit_ceil(unsigned int n)\
    \ {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n    return\
    \ x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  static_assert(\n\
    \      std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,\n   \
    \   \"mapping must work as F(F, S)\");\n  static_assert(\n      std::is_convertible_v<decltype(composition),\
    \ std::function<F(F, F)>>,\n      \"compostiion must work as F(F, F)\");\n  static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                \"id must work as F()\");\n  lazy_segtree()\
    \ : lazy_segtree(0) {}\n  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n    size = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    lz = std::vector<F>(size,\
    \ id());\n    for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    for (int i\
    \ = size - 1; i >= 1; i--) {\n      update(i);\n    }\n  }\n\n  void set(int p,\
    \ S x) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) {\n    assert(0 <= p && p < _n);\n  \
    \  p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n\
    \  }\n\n  S prod(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n \
    \   if (l == r) return e();\n\n    l += size;\n    r += size;\n\n    for (int\
    \ i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n   \
    \   if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    S sml = e(), smr\
    \ = e();\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n     \
    \ if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n    }\n\n\
    \    return op(sml, smr);\n  }\n\n  S all_prod() { return d[1]; }\n\n  void apply(int\
    \ p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = mapping(f, d[p]);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n  void apply(int l, int r, F f) {\n   \
    \ assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\n    l += size;\n\
    \    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if\
    \ (l & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r, f);\n        l\
    \ >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n \
    \   for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l\
    \ >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n\
    \  template <bool (*g)(S)>\n  int max_right(int l) {\n    return max_right(l,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int max_right(int l,\
    \ G g) {\n    assert(0 <= l && l <= _n);\n    assert(g(e()));\n    if (l == _n)\
    \ return _n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    S sm = e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n  \
    \          l++;\n          }\n        }\n        return l - size;\n      }\n \
    \     sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l) != l);\n    return\
    \ _n;\n  }\n\n  template <bool (*g)(S)>\n  int min_left(int r) {\n    return min_left(r,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int min_left(int r,\
    \ G g) {\n    assert(0 <= r && r <= _n);\n    assert(g(e()));\n    if (r == 0)\
    \ return 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >>\
    \ i);\n    S sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r\
    \ >>= 1;\n      if (!g(op(d[r], sm))) {\n        while (r < size) {\n        \
    \  push(r);\n          r = (2 * r + 1);\n          if (g(op(d[r], sm))) {\n  \
    \          sm = op(d[r], sm);\n            r--;\n          }\n        }\n    \
    \    return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n, size, log;\n  std::vector<S>\
    \ d;\n  std::vector<F> lz;\n\n  void update(int k) { d[k] = op(d[2 * k], d[2 *\
    \ k + 1]); }\n  void all_apply(int k, F f) {\n    d[k] = mapping(f, d[k]);\n \
    \   if (k < size) lz[k] = composition(f, lz[k]);\n  }\n  void push(int k) {\n\
    \    all_apply(2 * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n    lz[k] = id();\n\
    \  }\n};\n#line 2 \"graph/tree/HeavyLightDecomposition.hpp\"\ntemplate <class\
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
    \     }\n    }\n  }\n};\n#line 8 \"verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp\"\
    \n\nusing F = long long;\nstruct S {\n  long long val;\n  int siz;\n};\n\nS op(S\
    \ a, S b) {\n  return {a.val + b.val, a.siz + b.siz};\n}\n\nS e() {\n  return\
    \ {0, 0};\n}\n\nS mapping(F f, S x) { return {x.val + f * x.siz, x.siz}; }\nF\
    \ composition(F f, F g) { return f + g; }\nF id() { return 0; }\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  cin >> n;\n  vector<vector<pair<int,\
    \ S>>> g(n);\n  vector<S> nodew(n, e());\n  for (int i = 0; i < n; i++) {\n  \
    \  int k;\n    cin >> k;\n    for (int j = 0; j < k; j++) {\n      int c;\n  \
    \    cin >> c;\n      g[c].push_back({i, {0, 1}});\n      g[i].push_back({c, {0,\
    \ 1}});\n    }\n  }\n  hld<S, op, e, F, mapping, composition, id, S, op, e, F,\
    \ mapping, composition, id> h(g, nodew);\n  cin >> q;\n  for (int i = 0; i < q;\
    \ i++) {\n    int com;\n    cin >> com;\n    if (com == 0) {\n      int v, w;\n\
    \      cin >> v >> w;\n      h.apply_edge(0, v, w);\n    } else {\n      int u;\n\
    \      cin >> u;\n      cout << h.prod_edge(0, u).val << \"\\n\";\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n#include \"../../../../data-structure/segment-tree/LazySegmentTree.hpp\"\
    \n#include \"../../../../graph/tree/HeavyLightDecomposition.hpp\"\n\nusing F =\
    \ long long;\nstruct S {\n  long long val;\n  int siz;\n};\n\nS op(S a, S b) {\n\
    \  return {a.val + b.val, a.siz + b.siz};\n}\n\nS e() {\n  return {0, 0};\n}\n\
    \nS mapping(F f, S x) { return {x.val + f * x.siz, x.siz}; }\nF composition(F\
    \ f, F g) { return f + g; }\nF id() { return 0; }\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n;\n  vector<vector<pair<int, S>>> g(n);\n  vector<S> nodew(n,\
    \ e());\n  for (int i = 0; i < n; i++) {\n    int k;\n    cin >> k;\n    for (int\
    \ j = 0; j < k; j++) {\n      int c;\n      cin >> c;\n      g[c].push_back({i,\
    \ {0, 1}});\n      g[i].push_back({c, {0, 1}});\n    }\n  }\n  hld<S, op, e, F,\
    \ mapping, composition, id, S, op, e, F, mapping, composition, id> h(g, nodew);\n\
    \  cin >> q;\n  for (int i = 0; i < q; i++) {\n    int com;\n    cin >> com;\n\
    \    if (com == 0) {\n      int v, w;\n      cin >> v >> w;\n      h.apply_edge(0,\
    \ v, w);\n    } else {\n      int u;\n      cin >> u;\n      cout << h.prod_edge(0,\
    \ u).val << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - data-structure/segment-tree/LazySegmentTree.hpp
  - graph/tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 18:54:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
- /verify/verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp.html
title: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
---
