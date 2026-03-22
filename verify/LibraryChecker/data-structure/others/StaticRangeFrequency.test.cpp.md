---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/MergeSortTree.hpp
    title: Merge Sort Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    #line 1 \"data-structure/others/MergeSortTree.hpp\"\n\nclass MergeSortTree {\n\
    \ private:\n  int n0;\n  int n;\n  int MA = 1e9 + 10;\n  vector<int> px;\n\n \
    \ vector<vector<int>> node;\n\n  void _merge(vector<int> &par, vector<int> a,\
    \ vector<int> b) {\n    int siz_a = a.size();\n    int siz_b = b.size();\n   \
    \ par.resize(siz_a + siz_b);\n    int i = 0;\n    int j = 0;\n    for (int k =\
    \ 0; k < siz_a + siz_b; k++) {\n      if (i < siz_a and j < siz_b) {\n       \
    \ if (a[i] <= b[j]) {\n          par[k] = a[i];\n          i++;\n        } else\
    \ {\n          par[k] = b[j];\n          j++;\n        }\n      } else if (i <\
    \ siz_a) {\n        par[k] = a[i];\n        i++;\n      } else {\n        par[k]\
    \ = b[j];\n        j++;\n      }\n    }\n  }\n\n  int less_count(int a, int b,\
    \ int x, int k = 0, int l = 0, int r = -1) {\n    if (r < 0) r = n0;\n    if (r\
    \ <= a or b <= l) return 0;\n    if (a <= l and r <= b) return distance(node[k].begin(),\
    \ lower_bound(node[k].begin(), node[k].end(), x));\n\n    int cl = less_count(a,\
    \ b, x, k * 2 + 1, l, (l + r) / 2);\n    int cr = less_count(a, b, x, k * 2 +\
    \ 2, (l + r) / 2, r);\n\n    return cl + cr;\n  }\n\n public:\n  MergeSortTree()\
    \ {}\n  MergeSortTree(const vector<int> &v) {\n    n = v.size();\n    n0 = 1;\n\
    \    while (n0 < n) n0 *= 2;\n    node.resize(n0 * 2 - 1);\n    for (int i = 0;\
    \ i < n; i++) node[i + n0 - 1].emplace_back(v[i]);\n    for (int i = n0 - 2; i\
    \ >= 0; i--) _merge(node[i], node[i * 2 + 1], node[i * 2 + 2]);\n  }\n\n  MergeSortTree(vector<int>\
    \ x, vector<int> y) {\n    n = x.size();\n    n0 = 1;\n    while (n0 < n) n0 *=\
    \ 2;\n    vector<pair<int, int>> v(n);\n    for (int i = 0; i < n; i++) v[i] =\
    \ {x[i], y[i]};\n    sort(v.begin(), v.end());\n    px.resize(n);\n    for (int\
    \ i = 0; i < n; i++) {\n      px[i] = v[i].first;\n      y[i] = v[i].second;\n\
    \    }\n\n    node.resize(n0 * 2 - 1);\n    for (int i = 0; i < n; i++) node[i\
    \ + n0 - 1].emplace_back(y[i]);\n    for (int i = n0 - 2; i >= 0; i--) _merge(node[i],\
    \ node[i * 2 + 1], node[i * 2 + 2]);\n  }\n\n  int range_freq(int l, int r, int\
    \ mink, int maxk) {\n    return less_count(l, r, maxk) - less_count(l, r, mink);\n\
    \  }\n\n  int rectangle_freq(int lx, int rx, int ly, int ry) {\n    int l = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), lx));\n    int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), rx));\n    return less_count(l, r, ry) - less_count(l, r, ly);\n \
    \ }\n};\n#line 4 \"verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp\"\
    \n\nusing S = lint;\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n,\
    \ q;\n  in(n, q);\n  vector<int> a(n);\n  in(a);\n\n  MergeSortTree t(a);\n  rep(i,\
    \ q) {\n    int l, r, x;\n    in(l, r, x);\n    out(t.range_freq(l, r, x, x +\
    \ 1));\n  }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n#include \"../../../../data-structure/others/MergeSortTree.hpp\"\n\nusing S\
    \ = lint;\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n,\
    \ q);\n  vector<int> a(n);\n  in(a);\n\n  MergeSortTree t(a);\n  rep(i, q) {\n\
    \    int l, r, x;\n    in(l, r, x);\n    out(t.range_freq(l, r, x, x + 1));\n\
    \  }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/others/MergeSortTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 12:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
- /verify/verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp.html
title: verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
---
