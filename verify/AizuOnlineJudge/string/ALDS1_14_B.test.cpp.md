---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: Rolling Hash
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#line 1 \"string/RollingHash.hpp\"\nclass RollingHash {\n   private:\n    int64_t\
    \ n;\n    int64_t mod = (1LL << 61) - 1;\n    int64_t base = 58347;\n    vector<int64_t>\
    \ invb;\n    vector<int64_t> sum;\n\n    __int128_t mod_pow(__int128_t a, int64_t\
    \ p) {\n        __int128_t res = 1;\n        while (p) {\n            if (p &\
    \ 1) res = (res * a) % mod;\n            a = (a * a) % mod;\n            p >>=\
    \ 1;\n        }\n        return res;\n    }\n\n   public:\n    RollingHash(const\
    \ string &s) {\n        __int128_t b_p = 1;\n        n = int64_t(s.size());\n\
    \        invb.resize(n + 1);\n        sum.resize(n + 1);\n\n        for (int i\
    \ = 0; i < n; i++) {\n            int64_t h_i = (b_p * int(s[i])) % mod;\n   \
    \         sum[i + 1] = (sum[i] + h_i) % mod;\n            b_p = (b_p * base) %\
    \ mod;\n        }\n        invb[n] = mod_pow(b_p, mod - 2);\n        for (int\
    \ i = n - 1; i >= 0; i--) {\n            invb[i] = (__int128_t(invb[i + 1]) *\
    \ base) % mod;\n        }\n    }\n\n    int64_t range_hash(int l, int r) {\n \
    \       return (__int128_t(sum[r] - sum[l] + mod) * invb[l]) % mod;\n    }\n};\n\
    #line 4 \"verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp\"\n\nint main() {\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    string t, p;\n    in(t, p);\n    int\
    \ n = t.size();\n    int m = p.size();\n\n    if (n < m) return 0;\n\n    RollingHash\
    \ tmp(p);\n    int64_t h = tmp.range_hash(0, m);\n\n    RollingHash rh(t);\n\n\
    \    rep(i, n - m + 1) {\n        if (rh.range_hash(i, i + m) == h) {\n      \
    \      out(i);\n        }\n    }\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#include \"../../../string/RollingHash.hpp\"\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    string t, p;\n    in(t, p);\n    int n = t.size();\n    int m = p.size();\n\
    \n    if (n < m) return 0;\n\n    RollingHash tmp(p);\n    int64_t h = tmp.range_hash(0,\
    \ m);\n\n    RollingHash rh(t);\n\n    rep(i, n - m + 1) {\n        if (rh.range_hash(i,\
    \ i + m) == h) {\n            out(i);\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - string/RollingHash.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2025-09-24 16:29:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
- /verify/verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp.html
title: verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
---
