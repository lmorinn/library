---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/CartesianTree.hpp
    title: Cartesian Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/tree/CartesianTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#line 1\
    \ \"graph/tree/CartesianTree.hpp\"\ntemplate <class T, auto compare = std::less()>\n\
    class CartesianTree {\n public:\n  int root;\n  vector<int> parent, left, right;\n\
    \n  CartesianTree() : root(0) {}\n  CartesianTree(const vector<T>& v) : root(0),\
    \ parent(int(v.size()), -1), left(int(v.size()), -1), right(int(v.size()), -1)\
    \ {\n    stack<pair<lint, int>> st;\n    int n = int(v.size());\n    for (int\
    \ i = 0; i < n; i++) {\n      if (!st.empty()) {\n        int pop_idx = -1;\n\
    \        while (!st.empty() and compare(v[i], st.top().first)) {\n          pop_idx\
    \ = st.top().second;\n          st.pop();\n        }\n        if (pop_idx != -1)\
    \ {\n          left[i] = pop_idx;\n          parent[pop_idx] = i;\n        }\n\
    \        if (!st.empty()) {\n          int idx = st.top().second;\n          parent[i]\
    \ = idx;\n          right[idx] = i;\n        }\n      }\n      st.emplace(v[i],\
    \ i);\n    }\n\n    for (int i = 0; i < n; i++) {\n      if (parent[i] == -1)\
    \ {\n        root = i;\n        parent[i] = i;\n        break;\n      }\n    }\n\
    \  }\n};\n#line 4 \"verify/LibraryChecker/tree/CartesianTree.test.cpp\"\n\nint\
    \ main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n;\n  in(n);\n  vector<int>\
    \ a(n);\n  in(a);\n  CartesianTree<int> c(a);\n  out(c.parent);\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\
    \n#include \"../../../graph/tree/CartesianTree.hpp\"\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int n;\n  in(n);\n  vector<int> a(n);\n  in(a);\n  CartesianTree<int> c(a);\n\
    \  out(c.parent);\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/tree/CartesianTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/tree/CartesianTree.test.cpp
  requiredBy: []
  timestamp: '2026-03-11 19:33:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/tree/CartesianTree.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/tree/CartesianTree.test.cpp
- /verify/verify/LibraryChecker/tree/CartesianTree.test.cpp.html
title: verify/LibraryChecker/tree/CartesianTree.test.cpp
---
