---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/square-root-decomposition/PointSetRangeMin.test.cpp
    title: verify/AizuOnlineJudge/data-structure/square-root-decomposition/PointSetRangeMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/square-root-decomposition/PointSetRangeMin.hpp\"\
    \ntemplate <class T>\nclass PointSetRangeMin {\n   private:\n    int n;\n    vector<T>\
    \ a, mi;\n    T ma;\n    int bsize;\n\n   public:\n    PointSetRangeMin(const\
    \ vector<T> &v) {\n        ma = numeric_limits<T>::max();\n        a = v;\n  \
    \      n = a.size();\n        bsize = sqrt(n) + 1;\n        mi.resize(bsize, ma);\n\
    \        for (int i = 0; i < n; i++) {\n            mi[i / bsize] = min(mi[i /\
    \ bsize], a[i]);\n        }\n    }\n\n    T get(int p) {\n        return a[p];\n\
    \    }\n\n    void set(int p, T val) {\n        a[p] = val;\n        int bidx\
    \ = p / bsize;\n        mi[bidx] = ma;\n        int start = bidx * bsize;\n  \
    \      int end = min(n, start + bsize);\n        for (int i = start; i < end;\
    \ i++) {\n            mi[bidx] = min(mi[bidx], a[i]);\n        }\n    }\n\n  \
    \  void add(int p, T val) {\n        a[p] += val;\n        int bidx = p / bsize;\n\
    \        mi[bidx] = ma;\n        int start = bidx * bsize;\n        int end =\
    \ min(n, start + bsize);\n        for (int i = start; i < end; i++) {\n      \
    \      mi[bidx] = min(mi[bidx], a[i]);\n        }\n    }\n\n    T range_min(int\
    \ l, int r) {\n        T res = ma;\n        if (l / bsize == r / bsize) {\n  \
    \          for (int i = l; i < r; i++) {\n                if (res > a[i]) {\n\
    \                    res = a[i];\n                }\n            }\n         \
    \   return res;\n        } else {\n            for (int i = l; i < l / bsize *\
    \ bsize + bsize; i++) {\n                if (res > a[i]) {\n                 \
    \   res = a[i];\n                }\n            }\n\n            for (int i =\
    \ r / bsize * bsize; i < r; i++) {\n                if (res > a[i]) {\n      \
    \              res = a[i];\n                }\n            }\n\n            for\
    \ (int i = 0; i < bsize; i++) {\n                if (l < i * bsize and (i + 1)\
    \ * bsize <= r) {\n                    if (res > mi[i]) {\n                  \
    \      res = mi[i];\n                    }\n                }\n            }\n\
    \            return res;\n        }\n    }\n};\n"
  code: "template <class T>\nclass PointSetRangeMin {\n   private:\n    int n;\n \
    \   vector<T> a, mi;\n    T ma;\n    int bsize;\n\n   public:\n    PointSetRangeMin(const\
    \ vector<T> &v) {\n        ma = numeric_limits<T>::max();\n        a = v;\n  \
    \      n = a.size();\n        bsize = sqrt(n) + 1;\n        mi.resize(bsize, ma);\n\
    \        for (int i = 0; i < n; i++) {\n            mi[i / bsize] = min(mi[i /\
    \ bsize], a[i]);\n        }\n    }\n\n    T get(int p) {\n        return a[p];\n\
    \    }\n\n    void set(int p, T val) {\n        a[p] = val;\n        int bidx\
    \ = p / bsize;\n        mi[bidx] = ma;\n        int start = bidx * bsize;\n  \
    \      int end = min(n, start + bsize);\n        for (int i = start; i < end;\
    \ i++) {\n            mi[bidx] = min(mi[bidx], a[i]);\n        }\n    }\n\n  \
    \  void add(int p, T val) {\n        a[p] += val;\n        int bidx = p / bsize;\n\
    \        mi[bidx] = ma;\n        int start = bidx * bsize;\n        int end =\
    \ min(n, start + bsize);\n        for (int i = start; i < end; i++) {\n      \
    \      mi[bidx] = min(mi[bidx], a[i]);\n        }\n    }\n\n    T range_min(int\
    \ l, int r) {\n        T res = ma;\n        if (l / bsize == r / bsize) {\n  \
    \          for (int i = l; i < r; i++) {\n                if (res > a[i]) {\n\
    \                    res = a[i];\n                }\n            }\n         \
    \   return res;\n        } else {\n            for (int i = l; i < l / bsize *\
    \ bsize + bsize; i++) {\n                if (res > a[i]) {\n                 \
    \   res = a[i];\n                }\n            }\n\n            for (int i =\
    \ r / bsize * bsize; i < r; i++) {\n                if (res > a[i]) {\n      \
    \              res = a[i];\n                }\n            }\n\n            for\
    \ (int i = 0; i < bsize; i++) {\n                if (l < i * bsize and (i + 1)\
    \ * bsize <= r) {\n                    if (res > mi[i]) {\n                  \
    \      res = mi[i];\n                    }\n                }\n            }\n\
    \            return res;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition/PointSetRangeMin.hpp
  requiredBy: []
  timestamp: '2024-11-28 00:17:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/square-root-decomposition/PointSetRangeMin.test.cpp
documentation_of: data-structure/square-root-decomposition/PointSetRangeMin.hpp
layout: document
title: Point Set Range Sum
---

## 概要

todo

## 計算量
todo