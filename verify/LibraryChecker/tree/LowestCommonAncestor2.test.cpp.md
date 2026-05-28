---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: graph/tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\n#include <tr2/dynamic_bitset>\n\nusing namespace std;\nusing\
    \ namespace tr2;\nusing lint = long long;\nusing ull = unsigned long long;\nusing\
    \ ld = long double;\nusing int128 = __int128_t;\n#define all(x) (x).begin(), (x).end()\n\
    #define uniqv(v) v.erase(unique(all(v)), v.end())\n#define OVERLOAD_REP(_1, _2,\
    \ _3, name, ...) name\n#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{};\
    \ (i) != (n); ++(i))\n#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))\n\
    #define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define logfixed(x)\
    \ cout << fixed << setprecision(10) << x << endl;\n\nostream &operator<<(ostream\
    \ &dest, __int128_t value) {\n  ostream::sentry s(dest);\n  if (s) {\n    __uint128_t\
    \ tmp = value < 0 ? -value : value;\n    char buffer[128];\n    char *d = end(buffer);\n\
    \    do {\n      --d;\n      *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n\
    \    } while (tmp != 0);\n    if (value < 0) {\n      --d;\n      *d = '-';\n\
    \    }\n    int len = end(buffer) - d;\n    if (dest.rdbuf()->sputn(d, len) !=\
    \ len) {\n      dest.setstate(ios_base::badbit);\n    }\n  }\n  return dest;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T> &v)\
    \ {\n  for (int i = 0; i < (int)v.size(); i++) {\n    os << v[i] << (i + 1 !=\
    \ (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, const set<T> &set_var) {\n  for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr !=\
    \ set_var.end()) os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &set_var) {\n  for\
    \ (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os << *itr;\n\
    \    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n  }\n  return\
    \ os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const map<T, U> &map_var) {\n  for (auto itr = map_var.begin(); itr != map_var.end();\
    \ itr++) {\n    os << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n\
    \  return os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const unordered_map<T, U> &map_var) {\n  for (auto itr = map_var.begin();\
    \ itr != map_var.end(); itr++) {\n    os << itr->first << \" -> \" << itr->second\
    \ << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &pair_var) {\n  os << pair_var.first\
    \ << \" \" << pair_var.second;\n  return os;\n}\n\nvoid out() { cout << '\\n';\
    \ }\ntemplate <class T, class... Ts>\nvoid out(const T &a, const Ts &...b) {\n\
    \  cout << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\nvoid\
    \ outf() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid outf(const\
    \ T &a, const Ts &...b) {\n  cout << fixed << setprecision(14) << a;\n  (cout\
    \ << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\ntemplate <typename T>\n\
    istream &operator>>(istream &is, vector<T> &v) {\n  for (T &in : v) is >> in;\n\
    \  return is;\n}\n\ninline void in(void) { return; }\ntemplate <typename First,\
    \ typename... Rest>\nvoid in(First &first, Rest &...rest) {\n  cin >> first;\n\
    \  in(rest...);\n  return;\n}\n\ntemplate <typename T>\nbool chmax(T &a, const\
    \ T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n\
    }\ntemplate <typename T>\nbool chmin(T &a, const T &b) {\n  if (a > b) {\n   \
    \ a = b;\n    return true;\n  }\n  return false;\n}\n\nvector<lint> dx8 = {1,\
    \ 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    vector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0, 1, 0, -1};\n\n#pragma\
    \ endregion\n#line 2 \"verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"data-structure/segment-tree/SegmentTree.hpp\"\
    \ntemplate <class S, auto op, auto e>\nstruct segtree {\n private:\n  unsigned\
    \ int seg_bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x <\
    \ (unsigned int)(n)) x *= 2;\n    return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
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
    \ dist(x, v) == dist(u, v);\n  }\n};\n#line 4 \"verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n, q);\n\
    \  TreeQuery t(n);\n  rep(i, 1, n) {\n    int p;\n    in(p);\n    t.add_edge(i,\
    \ p);\n  }\n  rep(i, q) {\n    int u, v;\n    in(u, v);\n    out(t.lca(u, v));\n\
    \  }\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#include \"../../../graph/tree/LowestCommonAncestor.hpp\"\n\nint main() {\n\
    \  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n, q);\n  TreeQuery t(n);\n\
    \  rep(i, 1, n) {\n    int p;\n    in(p);\n    t.add_edge(i, p);\n  }\n  rep(i,\
    \ q) {\n    int u, v;\n    in(u, v);\n    out(t.lca(u, v));\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/tree/LowestCommonAncestor.hpp
  - data-structure/segment-tree/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
  requiredBy: []
  timestamp: '2026-05-01 18:46:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
- /verify/verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp.html
title: verify/LibraryChecker/tree/LowestCommonAncestor2.test.cpp
---
