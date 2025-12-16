---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/LCPArray.hpp
    title: LCP Array
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.hpp
    title: Suffix Array
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/string/NumberofSubstrings2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#line\
    \ 2 \"string/SuffixArray.hpp\"\n\n#define tget(i) (((t)[(i) >> 3] >> (7 - ((i)\
    \ & 7))) & 1)\n\n#define tset(i, b)                                    \\\n  \
    \  do {                                              \\\n        if (b)      \
    \                                  \\\n            (t)[(i) >> 3] |= (1 << (7 -\
    \ ((i) & 7)));  \\\n        else                                          \\\n\
    \            (t)[(i) >> 3] &= ~(1 << (7 - ((i) & 7))); \\\n    } while (0)\n\n\
    #define chr(i) (cs == sizeof(int) ? ((int *)s)[i] : ((unsigned char *)s)[i])\n\
    #define isLMS(i) (i > 0 and tget(i) and !tget(i - 1))\n\nvoid getBuckets(unsigned\
    \ char *s, int *bkt, int n, int K, int cs, bool end) {\n    int sum = 0;\n   \
    \ for (int i = 0; i <= K; i++) {\n        bkt[i] = 0;\n    }\n    for (int i =\
    \ 0; i < n; i++) {\n        bkt[chr(i)]++;\n    }\n    for (int i = 0; i <= K;\
    \ i++) {\n        sum += bkt[i];\n        bkt[i] = end ? sum : sum - bkt[i];\n\
    \    }\n}\n\nvoid induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt,\
    \ int n, int K, int cs, bool end) {\n    getBuckets(s, bkt, n, K, cs, end);\n\
    \    for (int i = 0; i < n; i++) {\n        int j = SA[i] - 1;\n        if (j\
    \ >= 0 and !tget(j)) {\n            SA[bkt[chr(j)]++] = j;\n        }\n    }\n\
    }\n\nvoid induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt, int\
    \ n, int K, int cs, bool end) {\n    getBuckets(s, bkt, n, K, cs, end);\n    for\
    \ (int i = n - 1; i >= 0; i--) {\n        int j = SA[i] - 1;\n        if (j >=\
    \ 0 and tget(j)) {\n            SA[--bkt[chr(j)]] = j;\n        }\n    }\n}\n\n\
    void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {\n    unsigned char\
    \ *t = (unsigned char *)malloc(n / 8 + 1);\n    tset(n - 2, 0);\n    tset(n -\
    \ 1, 1);\n    for (int i = n - 3; i >= 0; i--) {\n        tset(i, (chr(i) < chr(i\
    \ + 1) or (chr(i) == chr(i + 1) and tget(i + 1) == 1)) ? 1 : 0);\n    }\n\n  \
    \  int *bkt = (int *)malloc(sizeof(int) * (K + 1));\n    getBuckets(s, bkt, n,\
    \ K, cs, true);\n    for (int i = 0; i < n; i++) {\n        SA[i] = -1;\n    }\n\
    \    for (int i = 1; i < n; i++) {\n        if (isLMS(i)) {\n            SA[--bkt[chr(i)]]\
    \ = i;\n        }\n    }\n    induceSAl(t, SA, s, bkt, n, K, cs, false);\n   \
    \ induceSAs(t, SA, s, bkt, n, K, cs, true);\n    free(bkt);\n\n    int n1 = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        if (isLMS(SA[i])) {\n            SA[n1++]\
    \ = SA[i];\n        }\n    }\n\n    for (int i = n1; i < n; i++) {\n        SA[i]\
    \ = -1;\n    }\n    int name = 0;\n    int prev = -1;\n    for (int i = 0; i <\
    \ n1; i++) {\n        int pos = SA[i];\n        bool diff = false;\n        for\
    \ (int d = 0; d < n; d++) {\n            if (prev == -1 or chr(pos + d) != chr(prev\
    \ + d) or tget(pos + d) != tget(prev + d)) {\n                diff = true;\n \
    \               break;\n            } else if (d > 0 and (isLMS(pos + d) or isLMS(prev\
    \ + d))) {\n                break;\n            }\n        }\n        if (diff)\
    \ {\n            name++;\n            prev = pos;\n        }\n        pos = (pos\
    \ % 2 == 0) ? pos / 2 : (pos - 1) / 2;\n        SA[n1 + pos] = name - 1;\n   \
    \ }\n    for (int i = n - 1, j = n - 1; i >= n1; i--) {\n        if (SA[i] >=\
    \ 0) {\n            SA[j--] = SA[i];\n        }\n    }\n\n    int *SA1 = SA;\n\
    \    int *s1 = SA + n - n1;\n    if (name < n1) {\n        SA_IS((unsigned char\
    \ *)s1, SA1, n1, name - 1, sizeof(int));\n    } else {\n        for (int i = 0;\
    \ i < n1; i++) {\n            SA1[s1[i]] = i;\n        }\n    }\n    bkt = (int\
    \ *)malloc(sizeof(int) * (K + 1));\n    getBuckets(s, bkt, n, K, cs, true);\n\
    \    for (int i = 1, j = 0; i < n; i++) {\n        if (isLMS(i)) {\n         \
    \   s1[j++] = i;\n        }\n    }\n    for (int i = 0; i < n1; i++) {\n     \
    \   SA1[i] = s1[SA1[i]];\n    }\n    for (int i = n1; i < n; i++) {\n        SA[i]\
    \ = -1;\n    }\n    for (int i = n1 - 1; i >= 0; i--) {\n        int j = SA[i];\n\
    \        SA[i] = -1;\n        SA[--bkt[chr(j)]] = j;\n    }\n    induceSAl(t,\
    \ SA, s, bkt, n, K, cs, false);\n    induceSAs(t, SA, s, bkt, n, K, cs, true);\n\
    \    free(bkt);\n    free(t);\n}\n\nvector<int> suffixArray(string &str) {\n \
    \   int n = str.size() + 1;\n    int *sa = (int *)malloc(sizeof(int) * n);\n \
    \   unsigned char *s = (unsigned char *)malloc(sizeof(unsigned char) * (n + 2));\n\
    \    int k = 256;\n    int cs = sizeof(unsigned char);\n    for (int i = 0; i\
    \ < str.size(); i++) {\n        s[i] = str[i];\n    }\n    s[int(str.size())]\
    \ = 0;\n    SA_IS((unsigned char *)(s), sa, n, k, cs);\n    vector<int> res(n\
    \ - 1);\n    for (int i = 0; i < n - 1; i++) {\n        res[i] = sa[i + 1];\n\
    \    }\n    free(sa);\n    free(s);\n    return res;\n}\n#line 2 \"string/LCPArray.hpp\"\
    \nvector<int> LCPArray(const string& s, const vector<int>& sa) {\n  int n = int(s.size());\n\
    \  vector<int> rank(n);\n  for (int i = 0; i < n; i++) rank[sa[i]] = i;\n  vector<int>\
    \ lcp(n - 1);\n  int h = 0;\n  for (int i = 0; i < n; i++) {\n    if (h > 0) h--;\n\
    \    if (rank[i] == 0) continue;\n    int j = sa[rank[i] - 1];\n    for (; j +\
    \ h < n and i + h < n; h++) {\n      if (s[j + h] != s[i + h]) break;\n    }\n\
    \    lcp[rank[i] - 1] = h;\n  }\n  return lcp;\n}\n#line 4 \"verify/LibraryChecker/string/NumberofSubstrings2.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  string s;\n  in(s);\n \
    \ vector<int> l = LCPArray(s, suffixArray(s));\n  lint n = s.size();\n  lint res\
    \ = n * (n + 1) / 2;\n  for (auto x : l) res -= x;\n  out(res);\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \n#include \"../../../string/LCPArray.hpp\"\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  string s;\n  in(s);\n  vector<int> l = LCPArray(s, suffixArray(s));\n  lint\
    \ n = s.size();\n  lint res = n * (n + 1) / 2;\n  for (auto x : l) res -= x;\n\
    \  out(res);\n}\n"
  dependsOn:
  - template/template.hpp
  - string/LCPArray.hpp
  - string/SuffixArray.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
  requiredBy: []
  timestamp: '2025-12-14 23:58:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
- /verify/verify/LibraryChecker/string/NumberofSubstrings2.test.cpp.html
title: verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
---
