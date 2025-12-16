---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/square-root-decomposition/RangeSetRangeMin.hpp
    title: Range Set Range Min
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n#line 1 \"data-structure/square-root-decomposition/RangeSetRangeMin.hpp\"\n\n\
    template <class T>\nclass RangeSetRangeMin {\n   private:\n    int n;\n    vector<T>\
    \ a, mi, lazy;\n    int bsize;\n    T ma;\n\n    void push(int bidx) {\n     \
    \   if (lazy[bidx] != ma) {\n            int start = bidx * bsize;\n         \
    \   int end = min(n, start + bsize);\n            for (int i = start; i < end;\
    \ i++) {\n                a[i] = lazy[bidx];\n            }\n            lazy[bidx]\
    \ = ma;\n        }\n    }\n\n    void update(int bidx) {\n        mi[bidx] = ma;\n\
    \        int start = bidx * bsize;\n        int end = min(n, start + bsize);\n\
    \        for (int i = start; i < end; i++) {\n            mi[bidx] = min(mi[bidx],\
    \ a[i]);\n        }\n    }\n\n   public:\n    RangeSetRangeMin(const vector<T>\
    \ &v) {\n        ma = numeric_limits<T>::max();\n        a = v;\n        n = a.size();\n\
    \        bsize = sqrt(n) + 1;\n        lazy.resize(bsize, ma);\n        mi.resize(bsize,\
    \ ma);\n        for (int i = 0; i < n; i++) mi[i / bsize] = min(mi[i / bsize],\
    \ a[i]);\n    }\n\n    T range_min(int l, int r) {\n        T res = ma;\n    \
    \    if (l / bsize == r / bsize) {\n            push(l / bsize);\n           \
    \ for (int i = l; i < r; i++) res = min(res, a[i]);\n        } else {\n      \
    \      push(l / bsize);\n            for (int i = l; i < l / bsize * bsize + bsize;\
    \ i++) res = min(res, a[i]);\n\n            push(r / bsize);\n            for\
    \ (int i = r / bsize * bsize; i < r; i++) res = min(res, a[i]);\n\n          \
    \  for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize and (i\
    \ + 1) * bsize <= r) {\n                    res = min(res, mi[i]);\n         \
    \       }\n            }\n        }\n        return res;\n    }\n\n    void range_set(int\
    \ l, int r, T x) {\n        if (l / bsize == r / bsize) {\n            push(l\
    \ / bsize);\n            for (int i = l; i < r; i++) a[i] = x;\n            update(l\
    \ / bsize);\n        } else {\n            push(l / bsize);\n            for (int\
    \ i = l; i < l / bsize * bsize + bsize; i++) a[i] = x;\n            update(l /\
    \ bsize);\n\n            push(r / bsize);\n            for (int i = r / bsize\
    \ * bsize; i < r; i++) a[i] = x;\n            update(r / bsize);\n\n         \
    \   for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize and (i\
    \ + 1) * bsize <= r) {\n                    lazy[i] = x;\n                   \
    \ mi[i] = x;\n                }\n            }\n        }\n    }\n};\n#line 4\
    \ \"verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<lint> a(n, (1LL << 31) - 1);\n    RangeSetRangeMin<lint> w(a);\n\
    \n    rep(i, q) {\n        int com;\n        in(com);\n        if (com == 0) {\n\
    \            int l, r, x;\n            in(l, r, x);\n            w.range_set(l,\
    \ r + 1, x);\n        } else {\n            int l, r;\n            in(l, r);\n\
    \            out(w.range_min(l, r + 1));\n        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n#include \"../../../../data-structure/square-root-decomposition/RangeSetRangeMin.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<lint> a(n, (1LL << 31) - 1);\n    RangeSetRangeMin<lint> w(a);\n\
    \n    rep(i, q) {\n        int com;\n        in(com);\n        if (com == 0) {\n\
    \            int l, r, x;\n            in(l, r, x);\n            w.range_set(l,\
    \ r + 1, x);\n        } else {\n            int l, r;\n            in(l, r);\n\
    \            out(w.range_min(l, r + 1));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/square-root-decomposition/RangeSetRangeMin.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
  requiredBy: []
  timestamp: '2024-11-28 20:50:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
- /verify/verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp.html
title: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
---
