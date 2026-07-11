---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
    title: verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/MultiDimensionalSum.hpp\"\ntemplate\
    \ <class T>\nclass multi_dimensional_sum {\n private:\n  vector<T> sum;\n  vector<int>\
    \ mx;\n  vector<long long> prod;\n  int n, siz;\n\n  T idx(const vector<int>&\
    \ id) {\n    int ret = 0;\n    for (int i = 0; i < n; i++) ret += prod[i] * id[i];\n\
    \    return ret;\n  }\n\n public:\n  // [1, mx_0] x [1, mx_1] x ... x [1, mx_{n-1}]\n\
    \  multi_dimensional_sum(const vector<int>& mx) : mx(mx) {\n    n = int(mx.size());\n\
    \    siz = 1;\n    for (int i = 0; i < n; i++) siz *= mx[i];\n    sum.assign(siz,\
    \ 0);\n    prod.resize(n);\n    prod[n - 1] = 1;\n    for (int i = n - 1; i >\
    \ 0; i--) prod[i - 1] = prod[i] * mx[i];\n  };\n\n  void add(vector<int> id, T\
    \ x) {\n    assert(int(id.size()) == n);\n    int i = idx(id);\n    assert(i <\
    \ siz);\n    sum[i] += x;\n  }\n\n  void build() {\n    for (int i = 0; i < n;\
    \ i++) {\n      int j = prod[i];\n      for (int id = 0; id < siz; id++) {\n \
    \       if ((id / j) % mx[i] > 0) sum[id] += sum[id - j];\n      }\n    }\n  }\n\
    \n  // sum [l_0, r_0] x [l_1, r_1] x ... x [l_{n-1}, r_{n-1}]\n  T calc(const\
    \ vector<int>& l, const vector<int>& r) {\n    assert(int(l.size()) == n and int(r.size())\
    \ == n);\n    for (int i = 0; i < n; i++) {\n      if (l[i] > r[i]) return 0;\n\
    \    }\n\n    T ret = 0;\n    vector<int> id(n);\n    for (unsigned int bit =\
    \ 0; bit < (1u << n); bit++) {\n      bool ok = true;\n\n      for (int i = 0;\
    \ i < n; i++) {\n        if ((bit & (1 << i))) {\n          id[i] = r[i] - 1;\n\
    \        } else {\n          id[i] = l[i] - 2;\n        }\n\n        if (id[i]\
    \ < 0) {\n          ok = false;\n          break;\n        }\n      }\n      if\
    \ (!ok) continue;\n      int lcnt = n - popcount(bit);\n      ret += (lcnt % 2\
    \ ? -sum[idx(id)] : sum[idx(id)]);\n    }\n    return ret;\n  }\n};\n"
  code: "template <class T>\nclass multi_dimensional_sum {\n private:\n  vector<T>\
    \ sum;\n  vector<int> mx;\n  vector<long long> prod;\n  int n, siz;\n\n  T idx(const\
    \ vector<int>& id) {\n    int ret = 0;\n    for (int i = 0; i < n; i++) ret +=\
    \ prod[i] * id[i];\n    return ret;\n  }\n\n public:\n  // [1, mx_0] x [1, mx_1]\
    \ x ... x [1, mx_{n-1}]\n  multi_dimensional_sum(const vector<int>& mx) : mx(mx)\
    \ {\n    n = int(mx.size());\n    siz = 1;\n    for (int i = 0; i < n; i++) siz\
    \ *= mx[i];\n    sum.assign(siz, 0);\n    prod.resize(n);\n    prod[n - 1] = 1;\n\
    \    for (int i = n - 1; i > 0; i--) prod[i - 1] = prod[i] * mx[i];\n  };\n\n\
    \  void add(vector<int> id, T x) {\n    assert(int(id.size()) == n);\n    int\
    \ i = idx(id);\n    assert(i < siz);\n    sum[i] += x;\n  }\n\n  void build()\
    \ {\n    for (int i = 0; i < n; i++) {\n      int j = prod[i];\n      for (int\
    \ id = 0; id < siz; id++) {\n        if ((id / j) % mx[i] > 0) sum[id] += sum[id\
    \ - j];\n      }\n    }\n  }\n\n  // sum [l_0, r_0] x [l_1, r_1] x ... x [l_{n-1},\
    \ r_{n-1}]\n  T calc(const vector<int>& l, const vector<int>& r) {\n    assert(int(l.size())\
    \ == n and int(r.size()) == n);\n    for (int i = 0; i < n; i++) {\n      if (l[i]\
    \ > r[i]) return 0;\n    }\n\n    T ret = 0;\n    vector<int> id(n);\n    for\
    \ (unsigned int bit = 0; bit < (1u << n); bit++) {\n      bool ok = true;\n\n\
    \      for (int i = 0; i < n; i++) {\n        if ((bit & (1 << i))) {\n      \
    \    id[i] = r[i] - 1;\n        } else {\n          id[i] = l[i] - 2;\n      \
    \  }\n\n        if (id[i] < 0) {\n          ok = false;\n          break;\n  \
    \      }\n      }\n      if (!ok) continue;\n      int lcnt = n - popcount(bit);\n\
    \      ret += (lcnt % 2 ? -sum[idx(id)] : sum[idx(id)]);\n    }\n    return ret;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/MultiDimensionalSum.hpp
  requiredBy: []
  timestamp: '2026-07-11 14:54:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/others/HyperCubeDatabaseSystem.test.cpp
documentation_of: data-structure/others/MultiDimensionalSum.hpp
layout: document
title: Multi Dimensional Sum
---

## 概要

todo