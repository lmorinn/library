---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/PersistentArray.hpp
    title: Persistent Array
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find/PersistentUnionFind.hpp
    title: Persistent Union Find
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line\
    \ 1 \"data-structure/others/PersistentArray.hpp\"\n\ntemplate <class T>\nclass\
    \ PersistentArray {\n public:\n  struct Node {\n    Node *l, *r;\n    T val;\n\
    \    Node() : l(nullptr), r(nullptr) {\n    }\n  };\n  PersistentArray() {}\n\
    \  PersistentArray(int siz) {\n    n = siz;\n    vector<T> v(n);\n    root = new\
    \ Node();\n    for (int i = 0; i < n; i++) {\n      init_set(root, i, v[i], 0,\
    \ n);\n    }\n  }\n\n  PersistentArray(int siz, T x) {\n    n = siz;\n    root\
    \ = new Node();\n    for (int i = 0; i < n; i++) {\n      init_set(root, i, x,\
    \ 0, n);\n    }\n  }\n\n  PersistentArray(const vector<T> &v) {\n    n = int(v.size());\n\
    \    root = new Node();\n    for (int i = 0; i < n; i++) {\n      init_set(root,\
    \ i, v[i], 0, n);\n    }\n  }\n\n  T get(Node *ptr, int p) {\n    return get(ptr,\
    \ p, 0, n)->val;\n  }\n\n  Node *get_root() {\n    return root;\n  }\n\n  Node\
    \ *set(Node *ptr, int p, T x) {\n    Node *new_root = new Node();\n    Node *cur\
    \ = new_root;\n    int l = 0;\n    int r = n;\n    while (r - l > 1) {\n     \
    \ int m = (l + r) >> 1;\n      if (l <= p and p < m) {\n        if (!cur->l) cur->l\
    \ = new Node();\n        cur->r = ptr->r;\n        cur = cur->l;\n        ptr\
    \ = ptr->l;\n        r = m;\n      } else {\n        if (!cur->r) cur->r = new\
    \ Node();\n        cur->l = ptr->l;\n        cur = cur->r;\n        ptr = ptr->r;\n\
    \        l = m;\n      }\n    }\n    cur->val = x;\n    return new_root;\n  }\n\
    \n private:\n  int n;\n\n  Node *root;\n\n  void init_set(Node *cur, int p, T\
    \ x, int l, int r) {\n    while (r - l > 1) {\n      int m = (l + r) >> 1;\n \
    \     if (l <= p and p < m) {\n        if (!cur->l) cur->l = new Node();\n   \
    \     cur = cur->l;\n        r = m;\n      } else {\n        if (!cur->r) cur->r\
    \ = new Node();\n        cur = cur->r;\n        l = m;\n      }\n    }\n    cur->val\
    \ = x;\n  }\n\n  Node *get(Node *cur, int p, int l, int r) {\n    while (r - l\
    \ > 1) {\n      int m = (l + r) >> 1;\n      if (l <= p and p < m) {\n       \
    \ cur = cur->l;\n        r = m;\n      } else {\n        cur = cur->r;\n     \
    \   l = m;\n      }\n    }\n    return cur;\n  }\n};\n#line 2 \"data-structure/union-find/PersistentUnionFind.hpp\"\
    \n\nstruct PersistentUnionfind {\n public:\n  using Node = PersistentArray<int>::Node;\n\
    \  PersistentUnionfind() : _n(0) {}\n  explicit PersistentUnionfind(int n) : _n(n),\
    \ parent_or_size(n, -1) {\n    root = parent_or_size.get_root();\n  }\n\n  Node\
    \ *get_root() {\n    return root;\n  }\n\n  Node *merge(Node *p, int a, int b)\
    \ {\n    assert(0 <= a && a < _n);\n    assert(0 <= b && b < _n);\n    int x =\
    \ leader(p, a), y = leader(p, b);\n    if (x == y) return p;\n    int px = parent_or_size.get(p,\
    \ x);\n    int py = parent_or_size.get(p, y);\n    if (-px < -py) std::swap(x,\
    \ y);\n    // Node *ret = parent_or_size.set(p, x, px + py);\n    return parent_or_size.set(parent_or_size.set(p,\
    \ x, px + py), y, x);\n  }\n\n  bool same(Node *p, int a, int b) {\n    assert(0\
    \ <= a && a < _n);\n    assert(0 <= b && b < _n);\n    return leader(p, a) ==\
    \ leader(p, b);\n  }\n\n  int leader(Node *p, int a) {\n    assert(0 <= a && a\
    \ < _n);\n    if (parent_or_size.get(p, a) < 0) return a;\n    return leader(p,\
    \ parent_or_size.get(p, a));\n  }\n\n  int size(Node *p, int a) {\n    assert(0\
    \ <= a && a < _n);\n    return -parent_or_size.get(p, leader(p, a));\n  }\n\n\
    \  std::vector<std::vector<int>> groups(Node *p) {\n    std::vector<int> leader_buf(_n),\
    \ group_size(_n);\n    for (int i = 0; i < _n; i++) {\n      leader_buf[i] = leader(p,\
    \ i);\n      group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<int>>\
    \ result(_n);\n    for (int i = 0; i < _n; i++) {\n      result[i].reserve(group_size[i]);\n\
    \    }\n    for (int i = 0; i < _n; i++) {\n      result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(\n        std::remove_if(result.begin(), result.end(),\n\
    \                       [&](const std::vector<int> &v) { return v.empty(); }),\n\
    \        result.end());\n    return result;\n  }\n\n private:\n  int _n;\n  //\
    \ root node: -1 * component size\n  // otherwise: parent\n\n  PersistentArray<int>\
    \ parent_or_size;\n  Node *root;\n};\n#line 4 \"verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp\"\
    \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    PersistentUnionfind uf(n);\n    vector<PersistentUnionfind::Node *>\
    \ g(q + 1);\n    g[0] = uf.get_root();\n\n    rep(i, q) {\n        int t, k, u,\
    \ v;\n        in(t, k, u, v);\n        k++;\n        if (t == 0) {\n         \
    \   g[i + 1] = uf.merge(g[k], u, v);\n        } else {\n            out(uf.same(g[k],\
    \ u, v));\n        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\
    \n#include \"../../../../data-structure/union-find/PersistentUnionFind.hpp\"\n\
    int main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n, q);\n\
    \    PersistentUnionfind uf(n);\n    vector<PersistentUnionfind::Node *> g(q +\
    \ 1);\n    g[0] = uf.get_root();\n\n    rep(i, q) {\n        int t, k, u, v;\n\
    \        in(t, k, u, v);\n        k++;\n        if (t == 0) {\n            g[i\
    \ + 1] = uf.merge(g[k], u, v);\n        } else {\n            out(uf.same(g[k],\
    \ u, v));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/union-find/PersistentUnionFind.hpp
  - data-structure/others/PersistentArray.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
  requiredBy: []
  timestamp: '2025-09-23 18:41:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
- /verify/verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp.html
title: verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
---
