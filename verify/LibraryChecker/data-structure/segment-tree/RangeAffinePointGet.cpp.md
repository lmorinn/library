---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/segment-tree/DualSegmentTree.hpp
    title: data-structure/segment-tree/DualSegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    #line 2 \"data-structure/segment-tree/DualSegmentTree.hpp\"\ntemplate <class S,\
    \ class F, auto mapping, auto composition, auto id>\nstruct DualSegmentTree {\n\
    \   private:\n    int n;\n    vector<F> node;\n    vector<S> ar;\n    F ID;\n\
    \    void Apply(int a, int b, F x, int k = 0, int l = 0, int r = -1) {\n     \
    \   if (r < 0) r = n;\n        eval(k, l, r);\n        if (r <= a || b <= l) return;\n\
    \        if (a <= l && r <= b) {\n            node[k] = composition(x, node[k]);\n\
    \            eval(k, l, r);\n            return;\n        }\n        Apply(a,\
    \ b, x, 2 * k + 1, l, (l + r) / 2);\n        Apply(a, b, x, 2 * k + 2, (l + r)\
    \ / 2, r);\n    }\n\n    void eval(int k, int l, int r) {\n        if (r - l >\
    \ 1) {\n            node[k * 2 + 1] = composition(node[k], node[k * 2 + 1]);\n\
    \            node[k * 2 + 2] = composition(node[k], node[k * 2 + 2]);\n      \
    \  } else {\n            ar[k - n + 1] = mapping(node[k], ar[k - n + 1]);\n  \
    \      }\n        node[k] = ID;\n    }\n\n   public:\n    DualSegmentTree() {}\n\
    \    DualSegmentTree(vector<S> &v) {\n        int sz = v.size();\n        n =\
    \ 1;\n        while (n < sz) n *= 2;\n        node.resize(2 * n - 1, id());\n\
    \        ar.resize(sz);\n        for (int i = 0; i < sz; i++) {\n            ar[i]\
    \ = v[i];\n        }\n        ID = id();\n    }\n\n    void apply(int l, int r,\
    \ F x) {\n        Apply(l, r, x);\n    }\n\n    S get(int p) {\n        S ret\
    \ = ar[p];\n        int l = p;\n        int r = p + 1;\n        p += (n - 1);\n\
    \        F f = node[p];\n        while (p > 0) {\n            p = (p - 1) / 2;\n\
    \            f = composition(node[p], f);\n        }\n        return mapping(f,\
    \ ret);\n    }\n\n    F getf(int p) {\n        p += (n - 1);\n        F f = node[p];\n\
    \        while (p > 0) {\n            p = (p - 1) / 2;\n            f = composition(node[p],\
    \ f);\n        }\n        return f;\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp\"\
    \n\n#define MOD 998244353\nusing S = lint;\n\nstruct F {\n    lint a;\n    lint\
    \ b;\n};\n\nS mapping(F f, S x) {\n    return ((x * f.a) % MOD + f.b) % MOD;\n\
    }\n\nF composition(F f, F g) {\n    return {(f.a * g.a) % MOD, ((f.a * g.b) %\
    \ MOD + f.b) % MOD};\n}\n\nF id() {\n    return {1, 0};\n}\n\nint main() {\n \
    \   cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n, q);\n    vector<S>\
    \ a(n);\n    in(a);\n    DualSegmentTree<S, F, mapping, composition, id> seg(a);\n\
    \    rep(i, q) {\n        int com;\n        in(com);\n        if (com == 0) {\n\
    \            int l, r;\n            lint b, c;\n            in(l, r, b, c);\n\
    \            seg.apply(l, r, {b, c});\n        } else {\n            int p;\n\
    \            in(p);\n            out(seg.get(p));\n        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include \"../../../../data-structure/segment-tree/DualSegmentTree.hpp\"\n\n\
    #define MOD 998244353\nusing S = lint;\n\nstruct F {\n    lint a;\n    lint b;\n\
    };\n\nS mapping(F f, S x) {\n    return ((x * f.a) % MOD + f.b) % MOD;\n}\n\n\
    F composition(F f, F g) {\n    return {(f.a * g.a) % MOD, ((f.a * g.b) % MOD +\
    \ f.b) % MOD};\n}\n\nF id() {\n    return {1, 0};\n}\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, q;\n    in(n, q);\n    vector<S> a(n);\n    in(a);\n    DualSegmentTree<S,\
    \ F, mapping, composition, id> seg(a);\n    rep(i, q) {\n        int com;\n  \
    \      in(com);\n        if (com == 0) {\n            int l, r;\n            lint\
    \ b, c;\n            in(l, r, b, c);\n            seg.apply(l, r, {b, c});\n \
    \       } else {\n            int p;\n            in(p);\n            out(seg.get(p));\n\
    \        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/segment-tree/DualSegmentTree.hpp
  isVerificationFile: false
  path: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp
  requiredBy: []
  timestamp: '2024-08-24 12:35:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp
layout: document
redirect_from:
- /library/verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp
- /library/verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp.html
title: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.cpp
---
