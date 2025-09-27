---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/SqrtTree.hpp
    title: Sqrt Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"data-structure/others/SqrtTree.hpp\"\
    \ntemplate <class S, auto op>\nclass SqrtTree {\n   private:\n    int n, lg, indexSz;\n\
    \    vector<S> v;\n    vector<int> clz, layers, onLayer;\n    vector<vector<S>>\
    \ prefix, suffix, between;\n\n    void build(int layer, int lBound, int rBound,\
    \ int betweenOffs) {\n        if (layer >= (int)layers.size()) {\n           \
    \ return;\n        }\n        int bSz = 1 << ((layers[layer] + 1) >> 1);\n   \
    \     for (int l = lBound; l < rBound; l += bSz) {\n            int r = min(l\
    \ + bSz, rBound);\n            prefix[layer][l] = v[l];\n            for (int\
    \ i = l + 1; i < r; i++) {\n                prefix[layer][i] = op(prefix[layer][i\
    \ - 1], v[i]);\n            }\n            suffix[layer][r - 1] = v[r - 1];\n\
    \            for (int i = r - 2; i >= l; i--) {\n                suffix[layer][i]\
    \ = op(v[i], suffix[layer][i + 1]);\n            }\n            build(layer +\
    \ 1, l, r, betweenOffs);\n        }\n        if (layer == 0) {\n            int\
    \ bSzLog = (lg + 1) >> 1;\n            for (int i = 0; i < indexSz; i++) {\n \
    \               v[n + i] = suffix[0][i << bSzLog];\n            }\n          \
    \  build(1, n, n + indexSz, (1 << lg) - n);\n        } else {\n            int\
    \ bSzLog = (layers[layer] + 1) >> 1;\n            int bCntLog = layers[layer]\
    \ >> 1;\n            int bSz = 1 << bSzLog;\n            int bCnt = (rBound -\
    \ lBound + bSz - 1) >> bSzLog;\n            for (int i = 0; i < bCnt; i++) {\n\
    \                S ans;\n                for (int j = i; j < bCnt; j++) {\n  \
    \                  S add = suffix[layer][lBound + (j << bSzLog)];\n          \
    \          ans = (i == j) ? add : op(ans, add);\n                    between[layer\
    \ - 1][betweenOffs + lBound + (i << bCntLog) + j] = ans;\n                }\n\
    \            }\n        }\n    }\n\n    inline S query(int l, int r, int betweenOffs,\
    \ int base) {\n        if (l == r) {\n            return v[l];\n        }\n  \
    \      if (l + 1 == r) {\n            return op(v[l], v[r]);\n        }\n    \
    \    int layer = onLayer[clz[(l - base) ^ (r - base)]];\n        int bSzLog =\
    \ (layers[layer] + 1) >> 1;\n        int bCntLog = layers[layer] >> 1;\n     \
    \   int lBound = (((l - base) >> layers[layer]) << layers[layer]) + base;\n  \
    \      int lBlock = ((l - lBound) >> bSzLog) + 1;\n        int rBlock = ((r -\
    \ lBound) >> bSzLog) - 1;\n        S ans = suffix[layer][l];\n        if (lBlock\
    \ <= rBlock) {\n            S add = (layer == 0) ? (\n                       \
    \                query(n + lBlock, n + rBlock, (1 << lg) - n, n))\n          \
    \                       : (\n                                       between[layer\
    \ - 1][betweenOffs + lBound + (lBlock << bCntLog) + rBlock]);\n            ans\
    \ = op(ans, add);\n        }\n        ans = op(ans, prefix[layer][r]);\n     \
    \   return ans;\n    }\n\n   public:\n    inline S prod(int l, int r) {\n    \
    \    return query(l, r - 1, 0, 0);\n    }\n    SqrtTree() {}\n\n    SqrtTree(const\
    \ vector<S> a)\n        : n((int)a.size()), v(a) {\n        lg = 0;\n        while\
    \ ((1 << lg) < n) lg++;\n        clz.assign(1 << lg, 0);\n        onLayer.assign(lg\
    \ + 1, 0);\n        clz[0] = 0;\n        for (int i = 1; i < (int)clz.size();\
    \ i++) {\n            clz[i] = clz[i >> 1] + 1;\n        }\n        int tlg =\
    \ lg;\n        while (tlg > 1) {\n            onLayer[tlg] = (int)layers.size();\n\
    \            layers.push_back(tlg);\n            tlg = (tlg + 1) >> 1;\n     \
    \   }\n        for (int i = lg - 1; i >= 0; i--) {\n            onLayer[i] = max(onLayer[i],\
    \ onLayer[i + 1]);\n        }\n        int betweenLayers = max(0, (int)layers.size()\
    \ - 1);\n        int bSzLog = (lg + 1) >> 1;\n        int bSz = 1 << bSzLog;\n\
    \        indexSz = (n + bSz - 1) >> bSzLog;\n        v.resize(n + indexSz);\n\
    \        prefix.assign(layers.size(), vector<S>(n + indexSz));\n        suffix.assign(layers.size(),\
    \ vector<S>(n + indexSz));\n        between.assign(betweenLayers, vector<S>((1\
    \ << lg) + bSz));\n        build(0, 0, n, 0);\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp\"\
    \n\nusing S = int;\nS op(S a, S b) {\n    return min(a, b);\n}\n\nint main() {\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n, q);\n    vector<int>\
    \ a(n);\n    in(a);\n    SqrtTree<S, op> t(a);\n\n    rep(i, q) {\n        int\
    \ l, r;\n        in(l, r);\n        out(t.prod(l, r));\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#include \"../../../../data-structure/others/SqrtTree.hpp\"\n\nusing S = int;\n\
    S op(S a, S b) {\n    return min(a, b);\n}\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    int n, q;\n    in(n, q);\n    vector<int> a(n);\n    in(a);\n    SqrtTree<S,\
    \ op> t(a);\n\n    rep(i, q) {\n        int l, r;\n        in(l, r);\n       \
    \ out(t.prod(l, r));\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/others/SqrtTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp
  requiredBy: []
  timestamp: '2025-09-28 00:58:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp
- /verify/verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp.html
title: verify/LibraryChecker/data-structure/others/StaticRMQ_SqrtTree.test.cpp
---
