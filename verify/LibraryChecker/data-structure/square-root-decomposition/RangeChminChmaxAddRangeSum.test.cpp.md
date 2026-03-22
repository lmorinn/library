---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp
    title: Range Chmin Chmax Add Range Sum
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#line 1 \"data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp\"\
    \n\ntemplate <class T>\nclass RangeChminChmaxAddRangeSum {\n   private:\n    int\
    \ n;\n    vector<T> a, sum, offset;\n    vector<int> divi;\n    vector<bool> modulo;\n\
    \n    vector<deque<pair<T, int>>> deq;\n    int bsize, bnum;\n\n    inline void\
    \ build(int bidx) {\n        sum[bidx] = 0;\n        offset[bidx] = 0;\n     \
    \   map<T, int> cnt;\n        int l = bidx * bsize;\n        int r = min(n, l\
    \ + bsize);\n        for (int i = l; i < r; i++) {\n            cnt[a[i]]++;\n\
    \            sum[bidx] += a[i];\n        }\n        deq[bidx].assign(begin(cnt),\
    \ end(cnt));\n    }\n\n    inline void push(int bidx) {\n        sum[bidx] +=\
    \ offset[bidx] * (min((bidx + 1) * bsize, n) - bidx * bsize);\n        T lower\
    \ = offset[bidx] + deq[bidx].front().first;\n        T upper = offset[bidx] +\
    \ deq[bidx].back().first;\n        for (int i = bidx * bsize; i < min((bidx +\
    \ 1) * bsize, n); i++) {\n            a[i] = min(max(a[i] + offset[bidx], lower),\
    \ upper);\n        }\n    }\n\n   public:\n    RangeChminChmaxAddRangeSum(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        divi.resize(n\
    \ + 1);\n        modulo.assign(n + 1, false);\n        bsize = 250;\n        bnum\
    \ = (n + bsize - 1) / bsize;\n        deq.resize(bnum);\n        sum.assign(bnum,\
    \ 0);\n        offset.assign(bnum, 0);\n        for (int i = 0; i < n + 1; i++)\
    \ {\n            divi[i] = i / bsize;\n            modulo[i] = ((i % bsize) !=\
    \ 0);\n        }\n\n        for (int i = 0; i < bnum; i++) {\n            build(i);\n\
    \        }\n    }\n\n    void range_chmin(int l, int r, T x) {\n        // \u5DE6\
    \u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n            while\
    \ (l < r and modulo[l]) {\n                a[l] = min(a[l], x);\n            \
    \    l++;\n            }\n            build(divi[l - 1]);\n        }\n\n     \
    \   // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n  \
    \          while (l < r and modulo[r]) {\n                r--;\n             \
    \   a[r] = min(a[r], x);\n            }\n            build(divi[r]);\n       \
    \ }\n\n        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r)\
    \ {\n            int i = divi[l];\n            while (offset[i] + deq[i].back().first\
    \ > x) {\n                auto p = deq[i].back();\n                deq[i].pop_back();\n\
    \                if (deq[i].empty() or offset[i] + deq[i].back().first < x) {\n\
    \                    deq[i].emplace_back(x - offset[i], 0);\n                }\n\
    \                sum[i] -= (p.first - deq[i].back().first) * p.second;\n     \
    \           deq[i].back().second += p.second;\n            }\n            l +=\
    \ bsize;\n        }\n    }\n\n    void range_chmax(int l, int r, T x) {\n    \
    \    // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n \
    \           while (l < r and modulo[l]) {\n                a[l] = max(a[l], x);\n\
    \                l++;\n            }\n            build(divi[l - 1]);\n      \
    \  }\n\n        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     a[r] = max(a[r], x);\n            }\n            build(divi[r]);\n     \
    \   }\n\n        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r)\
    \ {\n            int i = divi[l];\n            while (offset[i] + deq[i].front().first\
    \ < x) {\n                auto p = deq[i].front();\n                deq[i].pop_front();\n\
    \                if (deq[i].empty() or offset[i] + deq[i].front().first > x) {\n\
    \                    deq[i].emplace_front(x - offset[i], 0);\n               \
    \ }\n                sum[i] += (deq[i].front().first - p.first) * p.second;\n\
    \                deq[i].front().second += p.second;\n            }\n         \
    \   l += bsize;\n        }\n    }\n\n    void range_add(int l, int r, T x) {\n\
    \        // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n\
    \            while (l < r and modulo[l]) {\n                a[l] += x;\n     \
    \           l++;\n            }\n            build(divi[l - 1]);\n        }\n\n\
    \        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     a[r] += x;\n            }\n            build(divi[r]);\n        }\n\n  \
    \      // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r) {\n    \
    \        int i = divi[l];\n            offset[i] += x;\n            l += bsize;\n\
    \        }\n    }\n\n    T range_sum(int l, int r) {\n        T res = 0;\n   \
    \     // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n\
    \            while (l < r and modulo[l]) {\n                res += a[l];\n   \
    \             l++;\n            }\n            build(divi[l - 1]);\n        }\n\
    \n        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     res += a[r];\n            }\n            build(divi[r]);\n        }\n\n\
    \        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r) {\n  \
    \          int i = divi[l];\n            res += offset[i] * (min((i + 1) * bsize,\
    \ n) - i * bsize) + sum[i];\n            l += bsize;\n        }\n        return\
    \ res;\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<lint> a(n);\n    in(a);\n    RangeChminChmaxAddRangeSum<lint>\
    \ rc(a);\n    while (q--) {\n        int tp, l, r;\n        in(tp, l, r);\n  \
    \      if (tp == 0) {\n            lint x;\n            in(x);\n            rc.range_chmin(l,\
    \ r, x);\n        } else if (tp == 1) {\n            lint x;\n            in(x);\n\
    \            rc.range_chmax(l, r, x);\n        } else if (tp == 2) {\n       \
    \     lint x;\n            in(x);\n            rc.range_add(l, r, x);\n      \
    \  } else {\n            out(rc.range_sum(l, r));\n        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"../../../../data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<lint> a(n);\n    in(a);\n    RangeChminChmaxAddRangeSum<lint>\
    \ rc(a);\n    while (q--) {\n        int tp, l, r;\n        in(tp, l, r);\n  \
    \      if (tp == 0) {\n            lint x;\n            in(x);\n            rc.range_chmin(l,\
    \ r, x);\n        } else if (tp == 1) {\n            lint x;\n            in(x);\n\
    \            rc.range_chmax(l, r, x);\n        } else if (tp == 2) {\n       \
    \     lint x;\n            in(x);\n            rc.range_add(l, r, x);\n      \
    \  } else {\n            out(rc.range_sum(l, r));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-11-28 20:50:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
- /verify/verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp.html
title: verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
---
