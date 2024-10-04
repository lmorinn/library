---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/connectivity/OfflineDynamicConnectivityLCT.hpp
    title: Offline Dynamic Connectivity (LCT base)
  - icon: ':x:'
    path: graph/dynamic-tree/LinkCutTreeEdge.hpp
    title: Link Cut Tree (Edge)
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235\"\
    \n#line 2 \"graph/dynamic-tree/LinkCutTreeEdge.hpp\"\n\n// u,v,val\u3092\u5B9A\
    \u7FA9\ntemplate <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id, auto reverseprod>\nstruct LinkCutTree {\n private:\n  struct Node {\n\
    \    Node *l = 0;\n    Node *r = 0;\n    Node *p = 0;\n    Node *pp = 0;\n   \
    \ // \u5024\u3001\u96C6\u7D04\u5024\u3001\u4F5C\u7528\u5024\n    S val = e();\n\
    \    S acc = e();\n    F lazy = id();\n    int idx = -1;\n    int z = 0;\n   \
    \ int sumz = 0;\n    int w = 0;\n    int sumw = 0;\n    bool rev = 0;\n    int\
    \ u = -1;\n    int v = -1;\n  };\n\n  using pNode = shared_ptr<Node>;\n  pNode\
    \ pNIL;\n  Node *NIL = nullptr;\n  vector<pNode> A;\n  vector<unordered_map<int,\
    \ Node *>> ed;\n  queue<int> unused;\n\n  void push(Node *v) {\n    if (v->l !=\
    \ NIL) {\n      v->l->val = mapping(v->lazy, v->l->val);\n      v->l->acc = mapping(v->lazy,\
    \ v->l->acc);\n      v->l->lazy = composition(v->lazy, v->l->lazy);\n    }\n \
    \   if (v->r != NIL) {\n      v->r->val = mapping(v->lazy, v->r->val);\n     \
    \ v->r->acc = mapping(v->lazy, v->r->acc);\n      v->r->lazy = composition(v->lazy,\
    \ v->r->lazy);\n    }\n    if (v->rev) {\n      swap(v->l, v->r);\n      if (v->l\
    \ != NIL) {\n        v->l->rev ^= 1;\n        reverseprod(v->l->acc);\n      }\n\
    \      if (v->r != NIL) {\n        v->r->rev ^= 1;\n        reverseprod(v->r->acc);\n\
    \      }\n      v->rev = 0;\n    }\n    v->lazy = id();\n  }\n\n  void update(Node\
    \ *v) {\n    v->sumz = v->l->sumz + v->r->sumz + 1;\n    v->sumw = v->l->sumw\
    \ + v->r->sumw + 1;\n    v->acc = op(op(v->l->acc, v->val), v->r->acc);\n  }\n\
    \n  Node *&parentchild(Node *v) {\n    if (v->p == NIL) return NIL;\n    if (v->p->l\
    \ == v) {\n      return v->p->l;\n    } else {\n      return v->p->r;\n    }\n\
    \  }\n\n  Node *at(int idx) {\n    return A[idx].get();\n  }\n\n  void rotL(Node\
    \ *v) {\n    Node *p = v->p;\n    if (p->p == NIL) {\n      swap(p->pp, v->pp);\n\
    \    } else {\n      parentchild(p) = v;\n    }\n    v->p = p->p;\n    p->p =\
    \ v;\n    if (v->l != NIL) v->l->p = p;\n    p->r = v->l;\n    v->l = p;\n  }\n\
    \n  void rotR(Node *v) {\n    Node *p = v->p;\n    if (p->p == NIL) {\n      swap(p->pp,\
    \ v->pp);\n    } else {\n      parentchild(p) = v;\n    }\n    v->p = p->p;\n\
    \    p->p = v;\n    if (v->r != NIL) v->r->p = p;\n    p->l = v->r;\n    v->r\
    \ = p;\n  }\n\n  void splay(Node *v) {\n    push(v);\n    while (v->p != NIL)\
    \ {\n      Node *p = v->p;\n      Node *pp = p->p;\n      if (pp != NIL) push(pp);\n\
    \      push(p);\n      push(v);\n\n      // zig zag\n      if (p->l == v) {\n\
    \        if (pp == NIL) {\n          rotR(v);\n        } else if (pp->l == p)\
    \ {\n          rotR(p);\n          rotR(v);\n        } else if (pp->r == p) {\n\
    \          rotR(v);\n          rotL(v);\n        }\n      } else {\n        if\
    \ (pp == NIL) {\n          rotL(v);\n        } else if (pp->r == p) {\n      \
    \    rotL(p);\n          rotL(v);\n        } else if (pp->l == p) {\n        \
    \  rotL(v);\n          rotR(v);\n        }\n      }\n\n      if (pp != NIL) update(pp);\n\
    \      update(p);\n    }\n    update(v);\n  }\n\n  Node *find_root(Node *v) {\n\
    \    expose(v);\n    while (v->l != NIL) {\n      push(v);\n      v = v->l;\n\
    \    }\n    splay(v);\n    return v;\n  }\n\n  void expose(Node *v) {\n    auto\
    \ p = v;\n    while (p != NIL) {\n      splay(p);\n      p = p->pp;\n    }\n \
    \   p = v;\n    while (p->pp != NIL) {\n      auto prev = p->pp->r;\n      if\
    \ (prev != NIL) swap(prev->pp, prev->p);\n      swap(p->p, p->pp);\n      p->p->r\
    \ = p;\n      p = p->p;\n    }\n    splay(v);\n  }\n\n  void evert(Node *v) {\n\
    \    expose(v);\n    if (v->r != NIL) {\n      v->r->pp = v->r->p;\n      v->r->p\
    \ = NIL;\n      v->r = NIL;\n    }\n    v->rev ^= 1;\n    reverseprod(v->acc);\n\
    \    push(v);\n  }\n\n  void link(Node *u, Node *v) {\n    evert(u);\n    evert(v);\n\
    \    if (u->p != NIL or u->pp != NIL) return;\n    u->pp = v;\n  }\n\n  void cut(Node\
    \ *v) {\n    expose(v);\n    if (v->l == NIL) return;\n    v->l->p = NIL;\n  \
    \  v->l = NIL;\n  }\n\n  Node *between(Node *u, Node *v) {\n    evert(u);\n  \
    \  expose(v);\n    push(v->l);\n    return v->l;\n  }\n\n  S prod(Node *u, Node\
    \ *v) {\n    S res = between(u, v)->acc;\n    res = op(res, v->val);\n    return\
    \ res;\n  }\n\n  S get(Node *v) {\n    expose(v);\n    return v->val;\n  }\n\n\
    \  void set(Node *v, S x) {\n    expose(v);\n    v->val = x;\n    update(v);\n\
    \  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  LinkCutTree()\
    \ {}\n  LinkCutTree(vector<S> &w) {\n    if (!pNIL) {\n      pNIL = make_shared<Node>();\n\
    \      NIL = pNIL.get();\n      NIL->l = NIL->r = NIL->p = NIL->pp = NIL;\n  \
    \  }\n    int n = w.size();\n    A.resize(2 * n + 1);\n    ed.resize(n);\n   \
    \ for (int i = 0; i < n; i++) {\n      A[i] = make_shared<Node>(*NIL);\n     \
    \ A[i]->w = A[i]->sumw = 0;\n      A[i]->z = A[i]->sumz = 1;\n      A[i]->idx\
    \ = i;\n      A[i]->val = A[i]->acc = w[i];\n    }\n\n    for (int i = n; i <\
    \ n * 2 - 1; i++) {\n      A[i] = make_shared<Node>(*NIL);\n      A[i]->w = A[i]->sumw\
    \ = 1;\n      A[i]->z = A[i]->sumz = 0;\n      A[i]->idx = i;\n      A[i]->val\
    \ = A[i]->acc = e();\n      unused.push(i);\n    }\n  }\n\n  // u,v\u9593\u306E\
    \u30D1\u30B9\u4E0A\u306B\u66F8\u304B\u308C\u305F\u7DCF\u7A4D\n  S prod(int u,\
    \ int v) {\n    return prod(at(u), at(v));\n  }\n\n  // \u9802\u70B9idx\u306B\
    x\u3092\u4EE3\u5165\n  void set(int idx, S x) {\n    set(at(idx), x);\n  }\n\n\
    \  // \u9802\u70B9u\u3068v\u3092\u76F4\u63A5\u7D50\u3076\u8FBA\u306Bx\u3092\u4EE3\
    \u5165\n  void set(int u, int v, S x) {\n    if (u > v) swap(u, v);\n    int edidx\
    \ = ed[u][v]->idx;\n    set(edidx, x);\n  }\n\n  // \u9802\u70B9idx\u306E\u5024\
    \u3092\u53D6\u5F97\n  S get(int idx) {\n    return get(at(idx));\n  }\n\n  //\
    \ \u9802\u70B9u\u3068v\u3092\u76F4\u63A5\u7D50\u3076\u8FBA\u306E\u5024\u3092\u53D6\
    \u5F97\n  S get(int u, int v) {\n    if (u > v) swap(u, v);\n    int edidx = ed[u][v]->idx;\n\
    \    return get(edidx);\n  }\n\n  // u\u3068v\u3092\u7D50\u3076\u91CD\u307Fx\u306E\
    \u8FBA\u3092\u8FFD\u52A0\n  void add(int u, int v, int x) {\n    if (u > v) swap(u,\
    \ v);\n    int edidx = unused.front();\n    unused.pop();\n    S newedge;\n  \
    \  newedge.u = u;\n    newedge.v = v;\n    newedge.val = x;\n    Node *edge =\
    \ A[edidx].get();\n    ed[u][v] = edge;\n    link(at(u), at(edidx));\n    link(at(edidx),\
    \ at(v));\n    set(edidx, newedge);\n    edge->u = u;\n    edge->v = v;\n  }\n\
    \n  // u\u3068v\u3092\u7D50\u3076\u8FBA\u3092\u524A\u9664\n  void erase(int u,\
    \ int v) {\n    if (u > v) swap(u, v);\n    Node *edge = ed[u][v];\n    int edidx\
    \ = edge->idx;\n    unused.push(edidx);\n    set(edidx, e());\n    ed[u].erase(v);\n\
    \    evert(at(u));\n    cut(at(edidx));\n    evert(at(edidx));\n    cut(at(v));\n\
    \    edge->u = -1;\n    edge->v = -1;\n  }\n\n  bool is_connected(int u, int v)\
    \ {\n    return find_root(at(u)) == find_root(at(v));\n  }\n};\n#line 3 \"graph/connectivity/OfflineDynamicConnectivityLCT.hpp\"\
    \n\nstruct S {\n  int u, v, val;\n};\n\nS op(S a, S b) {\n  if (a.val < b.val)\
    \ {\n    return a;\n  } else {\n    return b;\n  }\n}\n\nS e() {\n  return {-1,\
    \ -1, 10000000};\n}\n\nusing F = int;\nS mapping(F x, S a) {\n  return a;\n}\n\
    \nF composition(F g, F f) {\n  return f;\n}\n\nF id() {\n  return 0;\n}\n\nS reverseprod(S\
    \ a) {\n  return a;\n}\n\ntemplate <class R>\nclass OfflineDynamicConnectivity\
    \ {\n private:\n  struct Query {\n    int com;\n    int u, v;\n    int pos;\n\
    \    int finish;\n  };\n  int Q_INF = 1e8;\n  int n;\n  LinkCutTree<S, op, e,\
    \ F, mapping, composition, id, reverseprod> t;\n  vector<map<int, int>> ed;\n\
    \  vector<set<int>> msf;\n  int qtime;\n  vector<Query> q;\n\n public:\n  OfflineDynamicConnectivity()\
    \ {}\n\n  OfflineDynamicConnectivity(int siz) {\n    vector<S> nodew(siz, {int(1e8),\
    \ -1, -1});\n    t = LinkCutTree<S, op, e, F, mapping, composition, id, reverseprod>(nodew);\n\
    \    ed.resize(siz);\n    msf.resize(siz);\n    qtime = 0;\n  }\n\n  void link(int\
    \ u, int v) {\n    q.push_back({0, u, v, qtime, Q_INF});\n    ed[u][v] = qtime;\n\
    \    ed[v][u] = qtime;\n    qtime++;\n  }\n\n  void cut(int u, int v) {\n    q.push_back({1,\
    \ u, v, qtime, -1});\n    int idx = ed[u][v];\n    q[idx].finish = qtime;\n  \
    \  ed[u].erase(v);\n    ed[v].erase(u);\n    qtime++;\n  }\n\n  void same(int\
    \ u, int v) {\n    q.push_back({2, u, v, qtime, -1});\n    qtime++;\n  }\n\n \
    \ vector<R> build() {\n    int u, v, com;\n    vector<R> res;\n    for (int i\
    \ = 0; i < qtime; i++) {\n      com = q[i].com;\n      int u = q[i].u;\n     \
    \ int v = q[i].v;\n      int w = q[i].finish;\n      if (com == 0) {\n       \
    \ if (!t.is_connected(u, v)) {\n          t.add(u, v, w);\n          msf[u].insert(v);\n\
    \          msf[v].insert(u);\n        } else {\n          S path = t.prod(u, v);\n\
    \          if (path.val < w and path.u != -1 and path.v != -1) {\n           \
    \ t.erase(path.u, path.v);\n            t.add(u, v, w);\n            msf[path.u].erase(path.v);\n\
    \            msf[path.v].erase(path.u);\n            msf[u].insert(v);\n     \
    \       msf[v].insert(u);\n          }\n        }\n      } else if (com == 1)\
    \ {\n        if (msf[u].find(v) != msf[u].end()) {\n          int p = t.prod(u,\
    \ v).val;\n          t.erase(u, v);\n          msf[u].erase(v);\n          msf[v].erase(u);\n\
    \        }\n      } else if (com == 2) {\n        res.emplace_back(t.is_connected(u,\
    \ v));\n      }\n    }\n    return res;\n  }\n};\n#line 4 \"verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp\"\
    \n\nusing R = int;\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n,\
    \ q;\n  in(n, q);\n  OfflineDynamicConnectivity<R> g(n);\n\n  rep(i, q) {\n  \
    \  int com, u, v;\n    in(com, u, v);\n    if (com == 1) {\n      g.link(u, v);\n\
    \    } else if (com == 2) {\n      g.cut(u, v);\n    } else if (com == 3) {\n\
    \      g.same(u, v);\n    }\n  }\n\n  for (auto x : g.build()) {\n    out(x ?\
    \ \"YES\" : \"NO\");\n  }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235\"\
    \n#include \"../../../../graph/connectivity/OfflineDynamicConnectivityLCT.hpp\"\
    \n\nusing R = int;\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n,\
    \ q;\n  in(n, q);\n  OfflineDynamicConnectivity<R> g(n);\n\n  rep(i, q) {\n  \
    \  int com, u, v;\n    in(com, u, v);\n    if (com == 1) {\n      g.link(u, v);\n\
    \    } else if (com == 2) {\n      g.cut(u, v);\n    } else if (com == 3) {\n\
    \      g.same(u, v);\n    }\n  }\n\n  for (auto x : g.build()) {\n    out(x ?\
    \ \"YES\" : \"NO\");\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/connectivity/OfflineDynamicConnectivityLCT.hpp
  - graph/dynamic-tree/LinkCutTreeEdge.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
  requiredBy: []
  timestamp: '2024-10-04 22:52:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
- /verify/verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp.html
title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
---
