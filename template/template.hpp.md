---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_1_A.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_2_A.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_2_B.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_2_D.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_2_c.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_2_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_3_A.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_3_B.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_3_C.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_7_A.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/geometry/CGL_7_B.test.cpp
    title: verify/AizuOnlineJudge/geometry/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
    title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235dynamic.test.cpp
    title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235dynamic.test.cpp
  - icon: ':x:'
    path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
    title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/dynamic-tree/AOJ_2450.test.cpp
    title: verify/AizuOnlineJudge/graph/dynamic-tree/AOJ_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
    title: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.test.cpp
    title: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/string/SuffixArray.test.cpp
    title: verify/LibraryChecker/string/SuffixArray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
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
    \ 1, 0, -1};\n\n#pragma endregion\n"
  code: "#pragma once\n#pragma region Macros\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing lint = long long;\nusing ull = unsigned long long;\nusing ld = long\
    \ double;\nusing int128 = __int128_t;\n#define all(x) (x).begin(), (x).end()\n\
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
    \ endregion\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-06-28 15:04:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.test.cpp
  - verify/LibraryChecker/string/SuffixArray.test.cpp
  - verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_2_A.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_3_A.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_7_A.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_2_B.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_1_A.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_3_B.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_7_B.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_2_c.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_3_C.test.cpp
  - verify/AizuOnlineJudge/geometry/CGL_2_D.test.cpp
  - verify/AizuOnlineJudge/graph/dynamic-tree/AOJ_2450.test.cpp
  - verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235dynamic.test.cpp
  - verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235.test.cpp
  - verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235lct.test.cpp
documentation_of: template/template.hpp
layout: document
title: Template
---

## 概要

todo

## 計算量
todo