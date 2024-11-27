---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeAddPointGet.test.cpp
    title: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeAddPointGet.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/square-root-decomposition/RangeAddPointGet.hpp\"\
    \ntemplate <class T>\nclass RangeAddPointGet {\n   private:\n    int n;\n    vector<T>\
    \ a, add;\n    int bsize;\n\n   public:\n    RangeAddPointGet(const vector<T>\
    \ &v) {\n        a = v;\n        n = a.size();\n        bsize = sqrt(n) + 1;\n\
    \        add.resize(bsize, 0);\n    }\n\n    T get(int p) {\n        return add[p\
    \ / bsize] + a[p];\n    }\n\n    void set(int p, T val) {\n        int bidx =\
    \ p / bsize;\n        if (add[bidx] != 0) {\n            int start = bidx * bsize;\n\
    \            int end = min(n, start + bsize);\n            for (int i = start;\
    \ i < end; i++) {\n                a[i] += add[bidx];\n            }\n       \
    \     add[bidx] = 0;\n        }\n        a[p] = val;\n    }\n\n    void range_add(int\
    \ l, int r, T x) {\n        if (l / bsize == r / bsize) {\n            for (int\
    \ i = l; i < r; i++) {\n                a[i] += x;\n            }\n        } else\
    \ {\n            for (int i = l; i < l / bsize * bsize + bsize; i++) {\n     \
    \           a[i] += x;\n            }\n\n            for (int i = r / bsize *\
    \ bsize; i < r; i++) {\n                a[i] += x;\n            }\n\n        \
    \    for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize and\
    \ (i + 1) * bsize <= r) {\n                    add[i] += x;\n                }\n\
    \            }\n        }\n    }\n};\n"
  code: "template <class T>\nclass RangeAddPointGet {\n   private:\n    int n;\n \
    \   vector<T> a, add;\n    int bsize;\n\n   public:\n    RangeAddPointGet(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        bsize = sqrt(n)\
    \ + 1;\n        add.resize(bsize, 0);\n    }\n\n    T get(int p) {\n        return\
    \ add[p / bsize] + a[p];\n    }\n\n    void set(int p, T val) {\n        int bidx\
    \ = p / bsize;\n        if (add[bidx] != 0) {\n            int start = bidx *\
    \ bsize;\n            int end = min(n, start + bsize);\n            for (int i\
    \ = start; i < end; i++) {\n                a[i] += add[bidx];\n            }\n\
    \            add[bidx] = 0;\n        }\n        a[p] = val;\n    }\n\n    void\
    \ range_add(int l, int r, T x) {\n        if (l / bsize == r / bsize) {\n    \
    \        for (int i = l; i < r; i++) {\n                a[i] += x;\n         \
    \   }\n        } else {\n            for (int i = l; i < l / bsize * bsize + bsize;\
    \ i++) {\n                a[i] += x;\n            }\n\n            for (int i\
    \ = r / bsize * bsize; i < r; i++) {\n                a[i] += x;\n           \
    \ }\n\n            for (int i = 0; i < bsize; i++) {\n                if (l <\
    \ i * bsize and (i + 1) * bsize <= r) {\n                    add[i] += x;\n  \
    \              }\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition/RangeAddPointGet.hpp
  requiredBy: []
  timestamp: '2024-11-28 00:17:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeAddPointGet.test.cpp
documentation_of: data-structure/square-root-decomposition/RangeAddPointGet.hpp
layout: document
title: Range Add Point Get
---

## 概要

todo

## 計算量
todo