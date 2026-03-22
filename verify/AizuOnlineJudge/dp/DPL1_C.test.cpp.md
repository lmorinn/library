---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/KnapsackProblemNoLimit.hpp
    title: Knapsack Problem
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/dp/DPL1_C.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C\"\
    \n#line 1 \"dp/KnapsackProblemNoLimit.hpp\"\ntemplate <class T>\nvector<T> knapsack(const\
    \ vector<int> &w, const vector<T> &v, const int W) {\n    int n = int(v.size());\n\
    \    T ng = numeric_limits<T>::min();\n    vector<vector<T>> dp(n + 1, vector(W\
    \ + 2, ng));\n    dp[0][0] = 0;\n    for (int i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j <= W; j++) {\n            if (dp[i][j] != ng) dp[i + 1][j] = max(dp[i\
    \ + 1][j], dp[i][j]);\n            if (dp[i + 1][j] != ng) dp[i + 1][min(j + w[i],\
    \ W + 1)] = max(dp[i + 1][min(j + w[i], W + 1)], dp[i + 1][j] + v[i]);\n     \
    \   }\n    }\n    return {dp[n].begin(), dp[n].end() - 1};\n}\n#line 4 \"verify/AizuOnlineJudge/dp/DPL1_C.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, W;\n    in(n,\
    \ W);\n    vector<int> v(n), w(n);\n    rep(i, n) in(v[i], w[i]);\n    vector<int>\
    \ res = knapsack<int>(w, v, W);\n    int ans = 0;\n    for (auto x : res) chmax(ans,\
    \ x);\n    out(ans);\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C\"\
    \n#include \"../../../dp/KnapsackProblemNoLimit.hpp\"\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, W;\n    in(n, W);\n    vector<int> v(n), w(n);\n    rep(i, n) in(v[i],\
    \ w[i]);\n    vector<int> res = knapsack<int>(w, v, W);\n    int ans = 0;\n  \
    \  for (auto x : res) chmax(ans, x);\n    out(ans);\n}"
  dependsOn:
  - template/template.hpp
  - dp/KnapsackProblemNoLimit.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
  requiredBy: []
  timestamp: '2025-09-30 00:05:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
- /verify/verify/AizuOnlineJudge/dp/DPL1_C.test.cpp.html
title: verify/AizuOnlineJudge/dp/DPL1_C.test.cpp
---
