---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/MultiDimensionalSum.hpp
    title: Multi Dimensional Sum
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/4077
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/4077
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
    \ endregion\n#line 2 \"verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4077\"\n#line 1\
    \ \"data-structure/others/MultiDimensionalSum.hpp\"\ntemplate <class T>\nclass\
    \ multi_dimensional_sum {\n private:\n  vector<T> sum;\n  vector<int> mx;\n  vector<long\
    \ long> prod;\n  int n, siz;\n\n  T idx(const vector<int>& id) {\n    int ret\
    \ = 0;\n    for (int i = 0; i < n; i++) ret += prod[i] * id[i];\n    return ret;\n\
    \  }\n\n public:\n  // [1, mx_0] x [1, mx_1] x ... x [1, mx_{n-1}]\n  multi_dimensional_sum(const\
    \ vector<int>& mx) : mx(mx) {\n    n = int(mx.size());\n    siz = 1;\n    for\
    \ (int i = 0; i < n; i++) siz *= mx[i];\n    sum.assign(siz, 0);\n    prod.resize(n);\n\
    \    prod[n - 1] = 1;\n    for (int i = n - 1; i > 0; i--) prod[i - 1] = prod[i]\
    \ * mx[i];\n  };\n\n  void add(vector<int> id, T x) {\n    assert(int(id.size())\
    \ == n);\n    int i = idx(id);\n    assert(i < siz);\n    sum[i] += x;\n  }\n\n\
    \  void build() {\n    for (int i = 0; i < n; i++) {\n      int j = prod[i];\n\
    \      for (int id = 0; id < siz; id++) {\n        if ((id / j) % mx[i] > 0) sum[id]\
    \ += sum[id - j];\n      }\n    }\n  }\n\n  // sum [l_0, r_0] x [l_1, r_1] x ...\
    \ x [l_{n-1}, r_{n-1}]\n  T calc(const vector<int>& l, const vector<int>& r) {\n\
    \    assert(int(l.size()) == n and int(r.size()) == n);\n    for (int i = 0; i\
    \ < n; i++) {\n      if (l[i] > r[i]) return 0;\n    }\n\n    T ret = 0;\n   \
    \ vector<int> id(n);\n    for (unsigned int bit = 0; bit < (1u << n); bit++) {\n\
    \      bool ok = true;\n\n      for (int i = 0; i < n; i++) {\n        if ((bit\
    \ & (1 << i))) {\n          id[i] = r[i] - 1;\n        } else {\n          id[i]\
    \ = l[i] - 2;\n        }\n\n        if (id[i] < 0) {\n          ok = false;\n\
    \          break;\n        }\n      }\n      if (!ok) continue;\n      int lcnt\
    \ = n - popcount(bit);\n      ret += (lcnt % 2 ? -sum[idx(id)] : sum[idx(id)]);\n\
    \    }\n    return ret;\n  }\n};\n#line 4 \"verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n;\n  in(n);\n  vector<int>\
    \ v(n);\n  in(v);\n  int siz = 1;\n  multi_dimensional_sum<lint> sum(v);\n  rep(i,\
    \ n) siz *= v[i];\n\n  vector<int> x(n, 0);\n  rep(i, siz) {\n    lint c;\n  \
    \  in(c);\n    sum.add(x, c);\n    x.back()++;\n    if (x.back() >= v.back())\
    \ {\n      for (int j = n - 1; j > 0; j--) {\n        if (x[j] >= v[j]) {\n  \
    \        x[j] = 0;\n          x[j - 1]++;\n        }\n      }\n    }\n  }\n  sum.build();\n\
    \n  int q;\n  in(q);\n  vector<int> l(n), r(n);\n  rep(i, q) {\n    rep(j, n)\
    \ in(l[j], r[j]);\n    out(sum.calc(l, r));\n  }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4077\"\
    \n#include \"../../../../data-structure/others/MultiDimensionalSum.hpp\"\n\nint\
    \ main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n;\n  in(n);\n  vector<int>\
    \ v(n);\n  in(v);\n  int siz = 1;\n  multi_dimensional_sum<lint> sum(v);\n  rep(i,\
    \ n) siz *= v[i];\n\n  vector<int> x(n, 0);\n  rep(i, siz) {\n    lint c;\n  \
    \  in(c);\n    sum.add(x, c);\n    x.back()++;\n    if (x.back() >= v.back())\
    \ {\n      for (int j = n - 1; j > 0; j--) {\n        if (x[j] >= v[j]) {\n  \
    \        x[j] = 0;\n          x[j - 1]++;\n        }\n      }\n    }\n  }\n  sum.build();\n\
    \n  int q;\n  in(q);\n  vector<int> l(n), r(n);\n  rep(i, q) {\n    rep(j, n)\
    \ in(l[j], r[j]);\n    out(sum.calc(l, r));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/others/MultiDimensionalSum.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
  requiredBy: []
  timestamp: '2026-07-11 14:54:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
- /verify/verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp.html
title: verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
---
