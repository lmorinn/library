---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/LiChaoTree.hpp
    title: Li Chao Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 1 \"data-structure/others/LiChaoTree.hpp\"\n\nclass LiChaoTree {\n   private:\n\
    \    struct Node {\n        long long a, b;\n        Node *left;\n        Node\
    \ *right;\n        Node(long long a, long long b) : a(a), b(b), left(nullptr),\
    \ right(nullptr) {}\n    };\n    long long lower_x, upper_x;\n    Node *root =\
    \ nullptr;\n\n    inline long long f(long long a, long long b, long long x) {\n\
    \        return a * x + b;\n    }\n\n    void add_line(long long line_a, long\
    \ long line_b, Node *&t, long long l, long long r) {\n        if (!t) {\n    \
    \        t = new Node(line_a, line_b);\n            return;\n        }\n\n   \
    \     if (r - l == 1) {\n            if (f(line_a, line_b, l) < f(t->a, t->b,\
    \ l)) {\n                t->a = line_a;\n                t->b = line_b;\n    \
    \        }\n            return;\n        }\n        long long m = (l + r) >> 1ll;\n\
    \n        bool left_min = f(line_a, line_b, l) < f(t->a, t->b, l);\n        bool\
    \ mid_min = f(line_a, line_b, m) < f(t->a, t->b, m);\n        bool right_min =\
    \ f(line_a, line_b, r) < f(t->a, t->b, r);\n\n        if (left_min and right_min)\
    \ {\n            t->a = line_a;\n            t->b = line_b;\n            return;\n\
    \        }\n        if (!left_min and !right_min) {\n            return;\n   \
    \     }\n\n        if (mid_min) {\n            swap(t->a, line_a);\n         \
    \   swap(t->b, line_b);\n        }\n        if (left_min != mid_min) {\n     \
    \       add_line(line_a, line_b, t->left, l, m);\n        } else {\n         \
    \   add_line(line_a, line_b, t->right, m, r);\n        }\n    }\n\n    void add_segment(long\
    \ long line_a, long long line_b, Node *&t, long long a, long long b, long long\
    \ l, long long r) {\n        if (r <= a or b <= l) return;\n        if (!t) t\
    \ = new Node(0, LLONG_MAX);\n\n        long long m = (l + r) >> 1ll;\n       \
    \ if (!(a <= l and r <= b)) {\n            add_segment(line_a, line_b, t->left,\
    \ a, b, l, m);\n            add_segment(line_a, line_b, t->right, a, b, m, r);\n\
    \            return;\n        }\n        if (t->a == 0 and t->b == LLONG_MAX)\
    \ {\n            t->a = line_a;\n            t->b = line_b;\n        } else {\n\
    \            add_line(line_a, line_b, t, l, r);\n        }\n    }\n\n    long\
    \ long get_min(long long x, Node *t, long long l, long long r) {\n        if (!t)\
    \ return LLONG_MAX;\n        long long y = f(t->a, t->b, x);\n        if (r -\
    \ l == 1) return y;\n        long long m = (l + r) >> 1ll;\n        if (x < m)\
    \ {\n            return min(y, get_min(x, t->left, l, m));\n        } else {\n\
    \            return min(y, get_min(x, t->right, m, r));\n        }\n    }\n\n\
    \   public:\n    LiChaoTree() {}\n    LiChaoTree(long long lower_x, long long\
    \ upper_x) : lower_x(lower_x), upper_x(upper_x) {\n    }\n\n    void add_line(long\
    \ long a, long long b) {\n        add_line(a, b, root, lower_x, upper_x);\n  \
    \  }\n\n    void add_segment(long long l, long long r, long long a, long long\
    \ b) {\n        add_segment(a, b, root, l, r, lower_x, upper_x);\n    }\n\n  \
    \  long long get_min(long long x) {\n        return get_min(x, root, lower_x,\
    \ upper_x);\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    LiChaoTree t(-1e9,\
    \ 1e9 + 1);\n    int n, q;\n    in(n, q);\n    rep(i, n) {\n        lint a, b;\n\
    \        in(a, b);\n        t.add_line(a, b);\n    }\n\n    rep(i, q) {\n    \
    \    int com;\n        in(com);\n        if (com == 0) {\n            lint a,\
    \ b;\n            in(a, b);\n            t.add_line(a, b);\n        } else {\n\
    \            lint p;\n            in(p);\n            out(t.get_min(p));\n   \
    \     }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n#include \"../../../../data-structure/others/LiChaoTree.hpp\"\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    LiChaoTree t(-1e9, 1e9 + 1);\n \
    \   int n, q;\n    in(n, q);\n    rep(i, n) {\n        lint a, b;\n        in(a,\
    \ b);\n        t.add_line(a, b);\n    }\n\n    rep(i, q) {\n        int com;\n\
    \        in(com);\n        if (com == 0) {\n            lint a, b;\n         \
    \   in(a, b);\n            t.add_line(a, b);\n        } else {\n            lint\
    \ p;\n            in(p);\n            out(t.get_min(p));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/others/LiChaoTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
  requiredBy: []
  timestamp: '2025-09-23 18:49:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
- /verify/verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp.html
title: verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
---
