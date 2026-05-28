---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/HLD.hpp
    title: Heavy Light Decomposition
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
    \ endregion\n#line 2 \"verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 1 \"graph/tree/HLD.hpp\"\
    \n\nstruct hld {\n private:\n  int n, root, edge;\n  vector<vector<int>> g;\n\
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
    \ = st.top();\n      st.push(i);\n    }\n    return {par, v};\n  }\n};\n#line\
    \ 4 \"verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp\"\n\nint\
    \ main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n, q);\n  hld\
    \ t(n);\n  rep(i, 1, n) {\n    int p;\n    in(p);\n    t.add_edge(i, p);\n  }\n\
    \n  rep(i, q) {\n    int u, v;\n    in(u, v);\n    out(t.lca(u, v));\n  }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#include \"../../../../graph/tree/HLD.hpp\"\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int n, q;\n  in(n, q);\n  hld t(n);\n  rep(i, 1, n) {\n    int p;\n    in(p);\n\
    \    t.add_edge(i, p);\n  }\n\n  rep(i, q) {\n    int u, v;\n    in(u, v);\n \
    \   out(t.lca(u, v));\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/tree/HLD.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2026-05-28 17:17:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
- /verify/verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp.html
title: verify/LibraryChecker/graph/tree/LowestCommonAncestor.test.cpp
---
