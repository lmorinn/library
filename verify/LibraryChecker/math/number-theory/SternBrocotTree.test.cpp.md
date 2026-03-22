---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/SternBrocotTree.hpp
    title: "Stern\u2013Brocot Tree"
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n#line\
    \ 1 \"math/number-theory/SternBrocotTree.hpp\"\n\n// m/n\nvector<pair<char, int>>\
    \ encode_path(lint m, lint n) {\n    vector<pair<char, int>> res;\n    while (m\
    \ != 1 or n != 1) {\n        if (m < n) {\n            int num = (n - 1) / m;\n\
    \            res.emplace_back('L', num);\n            n -= m * num;\n        }\
    \ else {\n            int num = (m - 1) / n;\n            res.emplace_back('R',\
    \ num);\n            m -= n * num;\n        }\n    }\n    return res;\n}\n\npair<long\
    \ long, long long> decode_path(const vector<pair<char, int>>& path) {\n    long\
    \ long n = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ =\
    \ 1;\n    if (path.empty()) return {1, 1};\n    for (const auto [c, num] : path)\
    \ {\n        if (c == 'L') {\n            n_ += n * num;\n            m_ += m\
    \ * num;\n        } else {\n            n += n_ * num;\n            m += m_ *\
    \ num;\n        }\n    }\n\n    return {m + m_, n + n_};\n}\n\n// a/b, c/d\npair<long\
    \ long, long long> sbt_lca(long long a, long long b, long long c, long long d)\
    \ {\n    vector<pair<char, int>> p1 = encode_path(a, b);\n    vector<pair<char,\
    \ int>> p2 = encode_path(c, d);\n    int siz = min(int(p1.size()), int(p2.size()));\n\
    \    if (siz == 0) return {1, 1};\n    long long n = 1;\n    long long m = 0;\n\
    \    long long n_ = 0;\n    long long m_ = 1;\n    for (int i = 0; i < siz; i++)\
    \ {\n        if (p1[i].first != p2[i].first) {\n            break;\n        }\
    \ else {\n            long long num = min(p1[i].second, p2[i].second);\n     \
    \       if (p1[i].first == 'L') {\n                n_ += n * num;\n          \
    \      m_ += m * num;\n            } else {\n                n += n_ * num;\n\
    \                m += m_ * num;\n            }\n            if (p1[i].second !=\
    \ p2[i].second) break;\n        }\n    }\n\n    return {m + m_, n + n_};\n}\n\n\
    // a/b\npair<long long, long long> sbt_ancestor(int k, long long a, long long\
    \ b) {\n    vector<pair<char, int>> path = encode_path(a, b);\n    long long n\
    \ = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n \
    \   for (auto [c, num] : path) {\n        long long len = min(k, num);\n     \
    \   if (c == 'L') {\n            n_ += n * len;\n            m_ += m * len;\n\
    \        } else {\n            n += n_ * len;\n            m += m_ * len;\n  \
    \      }\n        k -= len;\n        if (k == 0) break;\n    }\n    if (k == 0)\
    \ {\n        return {m + m_, n + n_};\n    } else {\n        return {-1, 1};\n\
    \    }\n}\n\nvector<pair<long long, long long>> sbt_range(long long a, long long\
    \ b) {\n    vector<pair<char, int>> path = encode_path(a, b);\n    long long n\
    \ = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n\n\
    \    if (path.empty()) return {{0, 1}, {1, 0}};\n    for (const auto [c, num]\
    \ : path) {\n        if (c == 'L') {\n            n_ += n * num;\n           \
    \ m_ += m * num;\n        } else {\n            n += n_ * num;\n            m\
    \ += m_ * num;\n        }\n    }\n    return {{m, n}, {m_, n_}};\n}\n#line 4 \"\
    verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    int t;\n    in(t);\n    rep(i, t)\
    \ {\n        string q;\n        in(q);\n        if (q == \"ENCODE_PATH\") {\n\
    \            int a, b;\n            in(a, b);\n            auto res = encode_path(a,\
    \ b);\n            if (res.empty()) {\n                out(0);\n            }\
    \ else {\n                cout << res.size() << \" \";\n                rep(j,\
    \ res.size()) {\n                    cout << res[j].first << \" \" << res[j].second;\n\
    \                    if (j + 1 != res.size()) {\n                        cout\
    \ << \" \";\n                    } else {\n                        cout << \"\\\
    n\";\n                    }\n                }\n            }\n        } else\
    \ if (q == \"DECODE_PATH\") {\n            int k;\n            in(k);\n      \
    \      vector<pair<char, int>> path(k);\n            rep(j, k) {\n           \
    \     in(path[j].first, path[j].second);\n            }\n            auto res\
    \ = decode_path(path);\n            out(res.first, res.second);\n        } else\
    \ if (q == \"LCA\") {\n            int a, b, c, d;\n            in(a, b, c, d);\n\
    \            auto res = sbt_lca(a, b, c, d);\n            out(res.first, res.second);\n\
    \        } else if (q == \"ANCESTOR\") {\n            int k, a, b;\n         \
    \   in(k, a, b);\n            auto res = sbt_ancestor(k, a, b);\n            if\
    \ (res.first == -1) {\n                out(-1);\n            } else {\n      \
    \          out(res.first, res.second);\n            }\n        } else {\n    \
    \        int a, b;\n            in(a, b);\n            auto res = sbt_range(a,\
    \ b);\n            out(res[0].first, res[0].second, res[1].first, res[1].second);\n\
    \        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\
    \n#include \"../../../../math/number-theory/SternBrocotTree.hpp\"\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    int t;\n    in(t);\n    rep(i, t)\
    \ {\n        string q;\n        in(q);\n        if (q == \"ENCODE_PATH\") {\n\
    \            int a, b;\n            in(a, b);\n            auto res = encode_path(a,\
    \ b);\n            if (res.empty()) {\n                out(0);\n            }\
    \ else {\n                cout << res.size() << \" \";\n                rep(j,\
    \ res.size()) {\n                    cout << res[j].first << \" \" << res[j].second;\n\
    \                    if (j + 1 != res.size()) {\n                        cout\
    \ << \" \";\n                    } else {\n                        cout << \"\\\
    n\";\n                    }\n                }\n            }\n        } else\
    \ if (q == \"DECODE_PATH\") {\n            int k;\n            in(k);\n      \
    \      vector<pair<char, int>> path(k);\n            rep(j, k) {\n           \
    \     in(path[j].first, path[j].second);\n            }\n            auto res\
    \ = decode_path(path);\n            out(res.first, res.second);\n        } else\
    \ if (q == \"LCA\") {\n            int a, b, c, d;\n            in(a, b, c, d);\n\
    \            auto res = sbt_lca(a, b, c, d);\n            out(res.first, res.second);\n\
    \        } else if (q == \"ANCESTOR\") {\n            int k, a, b;\n         \
    \   in(k, a, b);\n            auto res = sbt_ancestor(k, a, b);\n            if\
    \ (res.first == -1) {\n                out(-1);\n            } else {\n      \
    \          out(res.first, res.second);\n            }\n        } else {\n    \
    \        int a, b;\n            in(a, b);\n            auto res = sbt_range(a,\
    \ b);\n            out(res[0].first, res[0].second, res[1].first, res[1].second);\n\
    \        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - math/number-theory/SternBrocotTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp
  requiredBy: []
  timestamp: '2025-10-30 23:04:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp
- /verify/verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp.html
title: verify/LibraryChecker/math/number-theory/SternBrocotTree.test.cpp
---
