---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/SortPointsbyArgument.hpp
    title: Sort Points by Argument
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
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\
    #line 2 \"template/template.hpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    #include <tr2/dynamic_bitset>\n\nusing namespace std;\nusing namespace tr2;\n\
    using lint = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using int128 = __int128_t;\n#define all(x) (x).begin(), (x).end()\n#define uniqv(v)\
    \ v.erase(unique(all(v)), v.end())\n#define OVERLOAD_REP(_1, _2, _3, name, ...)\
    \ name\n#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n);\
    \ ++(i))\n#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))\n#define\
    \ rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define logfixed(x)\
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
    \ endregion\n#line 3 \"verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp\"\
    \nusing namespace std;\n#line 1 \"geometry/SortPointsbyArgument.hpp\"\nstruct\
    \ Point {\n  long long x, y;\n};\n\n__int128_t cross(const Point& a, const Point&\
    \ b) {\n  return (__int128_t)a.x * b.y - (__int128_t)a.y * b.x;\n}\n\ntemplate\
    \ <auto f = less()>\nbool cmp(const Point& a, const Point& b) {\n  int ah = (f(a.y,\
    \ 0) or (a.y == 0 and a.x > 0));\n  int bh = (f(b.y, 0) or (b.y == 0 and b.x >\
    \ 0));\n  if (ah != bh) return ah > bh;\n  __int128_t c = cross(a, b);\n  if (c\
    \ == 0) {\n    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);\n  } else {\n\
    \    return c > 0;\n  }\n}\n#line 5 \"verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp\"\
    \nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n;\n  in(n);\n  vector<Point>\
    \ p(n);\n  rep(i, n) in(p[i].x, p[i].y);\n  sort(all(p), cmp<less()>);\n  rep(i,\
    \ n) {\n    out(p[i].x, p[i].y);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n#include \"../../../template/template.hpp\"\nusing namespace std;\n#include\
    \ \"../../../geometry/SortPointsbyArgument.hpp\"\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int n;\n  in(n);\n  vector<Point> p(n);\n  rep(i, n) in(p[i].x, p[i].y);\n\
    \  sort(all(p), cmp<less()>);\n  rep(i, n) {\n    out(p[i].x, p[i].y);\n  }\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - geometry/SortPointsbyArgument.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
  requiredBy: []
  timestamp: '2026-03-25 13:12:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
- /verify/verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp.html
title: verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
---
