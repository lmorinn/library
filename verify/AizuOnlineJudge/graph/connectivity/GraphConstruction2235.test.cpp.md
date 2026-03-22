---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find/UndoableUnionFind.hpp
    title: Undoable Union Find
  - icon: ':heavy_check_mark:'
    path: graph/connectivity/OfflineDynamicConnectivityDFS.hpp
    title: Offline Dynamic Connectivity (DSU base)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing lint = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n#define\
    \ all(x) (x).begin(), (x).end()\n#define uniqv(v) v.erase(unique(all(v)), v.end())\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP1(i, n) for (auto\
    \ i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))\n#define REP2(i, l, r) for\
    \ (auto i = (l); (i) != (r); ++(i))\n#define rep(...) OVERLOAD_REP(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define logfixed(x) cout << fixed << setprecision(10)\
    \ << x << endl;\n\nostream &operator<<(ostream &dest, __int128_t value) {\n  ostream::sentry\
    \ s(dest);\n  if (s) {\n    __uint128_t tmp = value < 0 ? -value : value;\n  \
    \  char buffer[128];\n    char *d = end(buffer);\n    do {\n      --d;\n     \
    \ *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n    } while (tmp != 0);\n\
    \    if (value < 0) {\n      --d;\n      *d = '-';\n    }\n    int len = end(buffer)\
    \ - d;\n    if (dest.rdbuf()->sputn(d, len) != len) {\n      dest.setstate(ios_base::badbit);\n\
    \    }\n  }\n  return dest;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n  for (int i = 0; i < (int)v.size(); i++) {\n  \
    \  os << v[i] << (i + 1 != (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\n  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os\
    \ << *itr;\n    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n\
    \  }\n  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const unordered_set<T> &set_var) {\n  for (auto itr = set_var.begin(); itr !=\
    \ set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr != set_var.end())\
    \ os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const map<T, U> &map_var) {\n  for (auto\
    \ itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os << itr->first\
    \ << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const unordered_map<T, U> &map_var)\
    \ {\n  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os\
    \ << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\
    \ntemplate <typename T, typename U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &pair_var) {\n  os << pair_var.first << \" \" << pair_var.second;\n  return\
    \ os;\n}\n\nvoid out() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid\
    \ out(const T &a, const Ts &...b) {\n  cout << a;\n  (cout << ... << (cout <<\
    \ ' ', b));\n  cout << '\\n';\n}\n\nvoid outf() { cout << '\\n'; }\ntemplate <class\
    \ T, class... Ts>\nvoid outf(const T &a, const Ts &...b) {\n  cout << fixed <<\
    \ setprecision(14) << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\\
    n';\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v)\
    \ {\n  for (T &in : v) is >> in;\n  return is;\n}\n\ninline void in(void) { return;\
    \ }\ntemplate <typename First, typename... Rest>\nvoid in(First &first, Rest &...rest)\
    \ {\n  cin >> first;\n  in(rest...);\n  return;\n}\n\ntemplate <typename T>\n\
    bool chmax(T &a, const T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <typename T>\nbool chmin(T &a, const T &b)\
    \ {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\n\
    vector<lint> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1,\
    \ 1, 0, -1, -1, -1};\nvector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0,\
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235\"\
    \n#line 1 \"data-structure/union-find/UndoableUnionFind.hpp\"\n\ntemplate <class\
    \ S, auto op, auto e>\nclass UndoableUnionFind {\n private:\n  struct HistoryData\
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
    \      }\n    }\n    execute();\n    return res;\n  }\n};\n\n\n#line 4 \"verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp\"\
    \n\nusing S = int;\n\nS op(S a, S b) {\n  return a + b;\n}\n\nS e() {\n  return\
    \ 0;\n}\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n,\
    \ q);\n  OfflineDynamicConnectivity<S, op, e> g(n);\n\n  rep(i, q) {\n    int\
    \ com, u, v;\n    in(com, u, v);\n    if (com == 1) {\n      g.link(u, v);\n \
    \   } else if (com == 2) {\n      g.cut(u, v);\n    } else if (com == 3) {\n \
    \     g.is_connected(u, v);\n    }\n  }\n\n  for (auto x : g.build()) {\n    out(x\
    \ ? \"YES\" : \"NO\");\n  }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235\"\
    \n#include \"../../../../graph/connectivity/OfflineDynamicConnectivityDFS.hpp\"\
    \n\nusing S = int;\n\nS op(S a, S b) {\n  return a + b;\n}\n\nS e() {\n  return\
    \ 0;\n}\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n,\
    \ q);\n  OfflineDynamicConnectivity<S, op, e> g(n);\n\n  rep(i, q) {\n    int\
    \ com, u, v;\n    in(com, u, v);\n    if (com == 1) {\n      g.link(u, v);\n \
    \   } else if (com == 2) {\n      g.cut(u, v);\n    } else if (com == 3) {\n \
    \     g.is_connected(u, v);\n    }\n  }\n\n  for (auto x : g.build()) {\n    out(x\
    \ ? \"YES\" : \"NO\");\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/connectivity/OfflineDynamicConnectivityDFS.hpp
  - data-structure/union-find/UndoableUnionFind.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
  requiredBy: []
  timestamp: '2024-10-04 22:52:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
- /verify/verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp.html
title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
---
