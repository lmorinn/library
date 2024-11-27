---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/square-root-decomposition/PointSetRangeSum.test.cpp
    title: verify/AizuOnlineJudge/data-structure/square-root-decomposition/PointSetRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/square-root-decomposition/PointSetRangeSum.hpp\"\
    \ntemplate <class T>\nclass PointSetRangeSum {\n   private:\n    int n;\n    vector<T>\
    \ a, sum;\n    int bsize;\n\n   public:\n    PointSetRangeSum(const vector<T>\
    \ &v) {\n        a = v;\n        n = a.size();\n        bsize = sqrt(n) + 1;\n\
    \        sum.resize(bsize);\n        for (int i = 0; i < n; i++) {\n         \
    \   sum[i / bsize] += a[i];\n        }\n    }\n\n    T get(int p) {\n        return\
    \ a[p];\n    }\n\n    void set(int p, T val) {\n        sum[p / bsize] -= a[p];\n\
    \        sum[p / bsize] += val;\n        a[p] = val;\n    }\n\n    void add(int\
    \ p, T val) {\n        sum[p / bsize] += val;\n        a[p] += val;\n    }\n\n\
    \    T range_sum(int l, int r) {\n        if (l / bsize == r / bsize) {\n    \
    \        T s = 0;\n            for (int i = l; i < r; i++) {\n               \
    \ s += a[i];\n            }\n            return s;\n        } else {\n       \
    \     T l_sum = 0;\n            for (int i = l; i < l / bsize * bsize + bsize;\
    \ i++) {\n                l_sum += a[i];\n            }\n\n            T r_sum\
    \ = 0;\n            for (int i = r / bsize * bsize; i < r; i++) {\n          \
    \      r_sum += a[i];\n            }\n            T mid_sum = 0;\n\n         \
    \   for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize and (i\
    \ + 1) * bsize <= r) {\n                    mid_sum += sum[i];\n             \
    \   }\n            }\n            return l_sum + mid_sum + r_sum;\n        }\n\
    \    }\n};\n"
  code: "template <class T>\nclass PointSetRangeSum {\n   private:\n    int n;\n \
    \   vector<T> a, sum;\n    int bsize;\n\n   public:\n    PointSetRangeSum(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        bsize = sqrt(n)\
    \ + 1;\n        sum.resize(bsize);\n        for (int i = 0; i < n; i++) {\n  \
    \          sum[i / bsize] += a[i];\n        }\n    }\n\n    T get(int p) {\n \
    \       return a[p];\n    }\n\n    void set(int p, T val) {\n        sum[p / bsize]\
    \ -= a[p];\n        sum[p / bsize] += val;\n        a[p] = val;\n    }\n\n   \
    \ void add(int p, T val) {\n        sum[p / bsize] += val;\n        a[p] += val;\n\
    \    }\n\n    T range_sum(int l, int r) {\n        if (l / bsize == r / bsize)\
    \ {\n            T s = 0;\n            for (int i = l; i < r; i++) {\n       \
    \         s += a[i];\n            }\n            return s;\n        } else {\n\
    \            T l_sum = 0;\n            for (int i = l; i < l / bsize * bsize +\
    \ bsize; i++) {\n                l_sum += a[i];\n            }\n\n           \
    \ T r_sum = 0;\n            for (int i = r / bsize * bsize; i < r; i++) {\n  \
    \              r_sum += a[i];\n            }\n            T mid_sum = 0;\n\n \
    \           for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize\
    \ and (i + 1) * bsize <= r) {\n                    mid_sum += sum[i];\n      \
    \          }\n            }\n            return l_sum + mid_sum + r_sum;\n   \
    \     }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition/PointSetRangeSum.hpp
  requiredBy: []
  timestamp: '2024-11-28 00:17:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/square-root-decomposition/PointSetRangeSum.test.cpp
documentation_of: data-structure/square-root-decomposition/PointSetRangeSum.hpp
layout: document
title: Point Set Range Sum
---

## 概要

todo

## 計算量
todo