---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp
    title: Segment Tree Beats
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#line 1 \"data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp\"\ntemplate\
    \ <class T>\nclass SegtreeBeats {\n   private:\n    T MA, MI;\n    int n;\n  \
    \  int n0;\n    vector<T> max_1_val, max_2_val, min_1_val, min_2_val, sum, add;\n\
    \    vector<int> max_1_cnt, min_1_cnt, len;\n\n    void query_chmin(int a, int\
    \ b, int k, int l, int r, T x) {\n        if (b <= l or r <= a or max_1_val[k]\
    \ <= x) {\n            return;\n        }\n\n        if (a <= l and r <= b and\
    \ max_2_val[k] < x) {\n            update_node_max(k, x);\n            return;\n\
    \        }\n\n        push(k);\n\n        query_chmin(a, b, (k << 1) | 1, l, (l\
    \ + r) >> 1, x);\n        query_chmin(a, b, (k + 1) << 1, (l + r) >> 1, r, x);\n\
    \n        update(k);\n    }\n\n    void query_chmax(int a, int b, int k, int l,\
    \ int r, T x) {\n        if (b <= l or r <= a or x <= min_1_val[k]) {\n      \
    \      return;\n        }\n\n        if (a <= l and r <= b and x < min_2_val[k])\
    \ {\n            update_node_min(k, x);\n            return;\n        }\n\n  \
    \      push(k);\n\n        query_chmax(a, b, (k << 1) | 1, l, (l + r) >> 1, x);\n\
    \        query_chmax(a, b, (k + 1) << 1, (l + r) >> 1, r, x);\n\n        update(k);\n\
    \    }\n\n    T query_max(int a, int b, int k, int l, int r) {\n        if (b\
    \ <= l or r <= a) {\n            return MI;\n        }\n\n        if (a <= l and\
    \ r <= b) {\n            return max_1_val[k];\n        }\n\n        push(k);\n\
    \        T l_max = query_max(a, b, (k << 1) | 1, l, (l + r) >> 1);\n        T\
    \ r_max = query_max(a, b, (k + 1) << 1, (l + r) >> 1, r);\n        return max(l_max,\
    \ r_max);\n    }\n\n    T query_min(int a, int b, int k, int l, int r) {\n   \
    \     if (b <= l or r <= a) {\n            return MA;\n        }\n\n        if\
    \ (a <= l and r <= b) {\n            return min_1_val[k];\n        }\n\n     \
    \   push(k);\n        T l_max = query_min(a, b, (k << 1) | 1, l, (l + r) >> 1);\n\
    \        T r_max = query_min(a, b, (k + 1) << 1, (l + r) >> 1, r);\n        return\
    \ min(l_max, r_max);\n    }\n\n    T query_sum(int a, int b, int k, int l, int\
    \ r) {\n        if (b <= l or r <= a) {\n            return 0;\n        }\n\n\
    \        if (a <= l and r <= b) {\n            return sum[k];\n        }\n\n \
    \       push(k);\n        T l_sum = query_sum(a, b, (k << 1) | 1, l, (l + r) >>\
    \ 1);\n        T r_sum = query_sum(a, b, (k + 1) << 1, (l + r) >> 1, r);\n   \
    \     return l_sum + r_sum;\n    }\n\n    void query_add(int a, int b, int k,\
    \ int l, int r, T x) {\n        if (b <= l or r <= a) {\n            return;\n\
    \        }\n\n        if (a <= l and r <= b) {\n            add_node(k, x);\n\
    \            return;\n        }\n\n        push(k);\n        query_add(a, b, (k\
    \ << 1) | 1, l, (l + r) >> 1, x);\n        query_add(a, b, (k + 1) << 1, (l +\
    \ r) >> 1, r, x);\n        update(k);\n    }\n\n    void update_node_max(int k,\
    \ T x) {\n        sum[k] += (x - max_1_val[k]) * max_1_cnt[k];\n        if (max_1_val[k]\
    \ == min_1_val[k]) {\n            max_1_val[k] = x;\n            min_1_val[k]\
    \ = x;\n        } else if (max_1_val[k] == min_2_val[k]) {\n            max_1_val[k]\
    \ = x;\n            min_2_val[k] = x;\n        } else {\n            max_1_val[k]\
    \ = x;\n        }\n    }\n\n    void update_node_min(int k, T x) {\n        sum[k]\
    \ += (x - min_1_val[k]) * min_1_cnt[k];\n\n        if (max_1_val[k] == min_1_val[k])\
    \ {\n            max_1_val[k] = x;\n            min_1_val[k] = x;\n        } else\
    \ if (max_2_val[k] == min_1_val[k]) {\n            max_2_val[k] = x;\n       \
    \     min_1_val[k] = x;\n        } else {\n            min_1_val[k] = x;\n   \
    \     }\n    }\n\n    void add_node(int k, T x) {\n        max_1_val[k] += x;\n\
    \        if (max_2_val[k] != MI) {\n            max_2_val[k] += x;\n        }\n\
    \        min_1_val[k] += x;\n        if (min_2_val[k] != MA) {\n            min_2_val[k]\
    \ += x;\n        }\n\n        sum[k] += len[k] * x;\n        add[k] += x;\n  \
    \  }\n\n    void push(int k) {\n        if (add[k] != 0) {\n            add_node((k\
    \ << 1) | 1, add[k]);\n            add_node((k + 1) << 1, add[k]);\n         \
    \   add[k] = 0;\n        }\n\n        if (max_1_val[k] < max_1_val[(k << 1) |\
    \ 1]) {\n            update_node_max((k << 1) | 1, max_1_val[k]);\n        }\n\
    \n        if (max_1_val[k] < max_1_val[(k + 1) << 1]) {\n            update_node_max((k\
    \ + 1) << 1, max_1_val[k]);\n        }\n\n        if (min_1_val[k] > min_1_val[(k\
    \ << 1) | 1]) {\n            update_node_min((k << 1) | 1, min_1_val[k]);\n  \
    \      }\n\n        if (min_1_val[k] > min_1_val[(k + 1) << 1]) {\n          \
    \  update_node_min((k + 1) << 1, min_1_val[k]);\n        }\n    }\n\n    void\
    \ update(int k) {\n        sum[k] = sum[(k << 1) | 1] + sum[(k + 1) << 1];\n\n\
    \        if (max_1_val[(k << 1) | 1] < max_1_val[(k + 1) << 1]) {\n          \
    \  max_1_val[k] = max_1_val[(k + 1) << 1];\n            max_1_cnt[k] = max_1_cnt[(k\
    \ + 1) << 1];\n            max_2_val[k] = max(max_1_val[(k << 1) | 1], max_2_val[(k\
    \ + 1) << 1]);\n        } else if (max_1_val[(k << 1) | 1] > max_1_val[(k + 1)\
    \ << 1]) {\n            max_1_val[k] = max_1_val[(k << 1) | 1];\n            max_1_cnt[k]\
    \ = max_1_cnt[(k << 1) | 1];\n            max_2_val[k] = max(max_2_val[(k << 1)\
    \ | 1], max_1_val[(k + 1) << 1]);\n        } else {\n            max_1_val[k]\
    \ = max_1_val[(k << 1) | 1];\n            max_1_cnt[k] = max_1_cnt[(k << 1) |\
    \ 1] + max_1_cnt[(k + 1) << 1];\n            max_2_val[k] = max(max_2_val[(k <<\
    \ 1) | 1], max_2_val[(k + 1) << 1]);\n        }\n\n        if (min_1_val[(k <<\
    \ 1) | 1] < min_1_val[(k + 1) << 1]) {\n            min_1_val[k] = min_1_val[(k\
    \ << 1) | 1];\n            min_1_cnt[k] = min_1_cnt[(k << 1) | 1];\n         \
    \   min_2_val[k] = min(min_2_val[(k << 1) | 1], min_1_val[(k + 1) << 1]);\n  \
    \      } else if (min_1_val[(k << 1) | 1] > min_1_val[(k + 1) << 1]) {\n     \
    \       min_1_val[k] = min_1_val[(k + 1) << 1];\n            min_1_cnt[k] = min_1_cnt[(k\
    \ + 1) << 1];\n            min_2_val[k] = min(min_1_val[(k << 1) | 1], min_2_val[(k\
    \ + 1) << 1]);\n        } else {\n            min_1_val[k] = min_1_val[(k << 1)\
    \ | 1];\n            min_1_cnt[k] = min_1_cnt[(k << 1) | 1] + min_1_cnt[(k + 1)\
    \ << 1];\n            min_2_val[k] = min(min_2_val[(k << 1) | 1], min_2_val[(k\
    \ + 1) << 1]);\n        }\n    }\n\n   public:\n    SegtreeBeats(const vector<T>\
    \ &v) {\n        MA = numeric_limits<T>::max();\n        MI = numeric_limits<T>::min();\n\
    \        n = v.size();\n        n0 = 1;\n        while (n0 < n) {\n          \
    \  n0 <<= 1;\n        }\n        sum.assign((n0 << 1), 0);\n        add.assign((n0\
    \ << 1), 0);\n        len.assign((n0 << 1), 0);\n        max_1_val.assign((n0\
    \ << 1), MI);\n        max_2_val.assign((n0 << 1), MI);\n        min_1_val.assign((n0\
    \ << 1), MA);\n        min_2_val.assign((n0 << 1), MA);\n        max_1_cnt.assign((n0\
    \ << 1), 0);\n        min_1_cnt.assign((n0 << 1), 0);\n\n        for (int i =\
    \ 0; i < (n0 << 1); i++) {\n            add[i] = 0;\n        }\n        len[0]\
    \ = n0;\n        for (int i = 0; i < n0 - 1; i++) {\n            len[(i << 1)\
    \ | 1] = (len[i] >> 1);\n            len[(i + 1) << 1] = (len[i] >> 1);\n    \
    \    }\n\n        for (int i = 0; i < n; i++) {\n            max_1_val[n0 - 1\
    \ + i] = v[i];\n            min_1_val[n0 - 1 + i] = v[i];\n            sum[n0\
    \ - 1 + i] = v[i];\n            max_1_cnt[n0 - 1 + i] = 1;\n            min_1_cnt[n0\
    \ - 1 + i] = 1;\n        }\n\n        for (int i = n0 - 2; i >= 0; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void range_chmin(int l, int r,\
    \ T x) {\n        query_chmin(l, r, 0, 0, n0, x);\n    }\n\n    void range_chmax(int\
    \ l, int r, T x) {\n        query_chmax(l, r, 0, 0, n0, x);\n    }\n\n    void\
    \ range_add(int l, int r, T x) {\n        query_add(l, r, 0, 0, n0, x);\n    }\n\
    \n    void range_update(int l, int r, T x) {\n        query_chmax(l, r, MA);\n\
    \        query_chmin(l, r, x);\n    }\n\n    T range_max(int l, int r) {\n   \
    \     return query_max(l, r, 0, 0, n0);\n    }\n\n    T range_min(int l, int r)\
    \ {\n        return query_min(l, r, 0, 0, n0);\n    }\n\n    T range_sum(int l,\
    \ int r) {\n        return query_sum(l, r, 0, 0, n0);\n    }\n\n    T get(int\
    \ p) {\n        return range_sum(p, p + 1);\n    }\n\n    T set(int p, T x) {\n\
    \        range_update(p, p + 1, x);\n    }\n\n    void print() {\n        for\
    \ (int i = 0; i < n; i++) {\n            cout << get(i) << (i == n - 1) ? '\\\
    n' : \" \";\n        }\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<lint> a(n);\n    in(a);\n    SegtreeBeats<lint> seg(a);\n\n\
    \    rep(i, q) {\n        int com, l, r;\n        lint x;\n        in(com, l,\
    \ r);\n        if (com == 0) {\n            in(x);\n            seg.range_chmin(l,\
    \ r, x);\n        } else if (com == 1) {\n            in(x);\n            seg.range_chmax(l,\
    \ r, x);\n        } else if (com == 2) {\n            in(x);\n            seg.range_add(l,\
    \ r, x);\n        } else if (com == 3) {\n            out(seg.range_sum(l, r));\n\
    \        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"../../../../data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<lint> a(n);\n    in(a);\n    SegtreeBeats<lint> seg(a);\n\n\
    \    rep(i, q) {\n        int com, l, r;\n        lint x;\n        in(com, l,\
    \ r);\n        if (com == 0) {\n            in(x);\n            seg.range_chmin(l,\
    \ r, x);\n        } else if (com == 1) {\n            in(x);\n            seg.range_chmax(l,\
    \ r, x);\n        } else if (com == 2) {\n            in(x);\n            seg.range_add(l,\
    \ r, x);\n        } else if (com == 3) {\n            out(seg.range_sum(l, r));\n\
    \        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-12-12 00:16:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
- /verify/verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp.html
title: verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
---
