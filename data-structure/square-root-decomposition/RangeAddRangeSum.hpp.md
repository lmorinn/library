---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeAddRangeSum.test.cpp
    title: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeAddRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/square-root-decomposition/RangeAddRangeSum.hpp\"\
    \n\ntemplate <class T>\nclass RangeAddRangeSum {\n   private:\n    int n;\n  \
    \  vector<T> a, add, sum;\n    int bsize;\n\n   public:\n    RangeAddRangeSum(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        bsize = sqrt(n)\
    \ + 1;\n        add.resize(bsize, 0);\n        sum.resize(bsize, 0);\n       \
    \ for (int i = 0; i < n; i++) {\n            sum[i / bsize] += v[i];\n       \
    \ }\n    }\n\n    T get(int p) {\n        return add[p / bsize] + a[p];\n    }\n\
    \n    T range_sum(int l, int r) {\n        T res = 0;\n        if (l / bsize ==\
    \ r / bsize) {\n            for (int i = l; i < r; i++) {\n                res\
    \ += a[i] + add[i / bsize];\n            }\n        } else {\n            for\
    \ (int i = l; i < l / bsize * bsize + bsize; i++) {\n                res += a[i]\
    \ + add[i / bsize];\n            }\n\n            for (int i = r / bsize * bsize;\
    \ i < r; i++) {\n                res += a[i] + add[i / bsize];\n            }\n\
    \n            for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize\
    \ and (i + 1) * bsize <= r) {\n                    res += sum[i] + add[i] * bsize;\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   void range_add(int l, int r, T x) {\n        if (l / bsize == r / bsize) {\n\
    \            for (int i = l; i < r; i++) {\n                a[i] += x;\n     \
    \           sum[i / bsize] += x;\n            }\n        } else {\n          \
    \  for (int i = l; i < l / bsize * bsize + bsize; i++) {\n                a[i]\
    \ += x;\n                sum[i / bsize] += x;\n            }\n\n            for\
    \ (int i = r / bsize * bsize; i < r; i++) {\n                a[i] += x;\n    \
    \            sum[i / bsize] += x;\n            }\n\n            for (int i = 0;\
    \ i < bsize; i++) {\n                if (l < i * bsize and (i + 1) * bsize <=\
    \ r) {\n                    add[i] += x;\n                }\n            }\n \
    \       }\n    }\n};\n"
  code: "\ntemplate <class T>\nclass RangeAddRangeSum {\n   private:\n    int n;\n\
    \    vector<T> a, add, sum;\n    int bsize;\n\n   public:\n    RangeAddRangeSum(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        bsize = sqrt(n)\
    \ + 1;\n        add.resize(bsize, 0);\n        sum.resize(bsize, 0);\n       \
    \ for (int i = 0; i < n; i++) {\n            sum[i / bsize] += v[i];\n       \
    \ }\n    }\n\n    T get(int p) {\n        return add[p / bsize] + a[p];\n    }\n\
    \n    T range_sum(int l, int r) {\n        T res = 0;\n        if (l / bsize ==\
    \ r / bsize) {\n            for (int i = l; i < r; i++) {\n                res\
    \ += a[i] + add[i / bsize];\n            }\n        } else {\n            for\
    \ (int i = l; i < l / bsize * bsize + bsize; i++) {\n                res += a[i]\
    \ + add[i / bsize];\n            }\n\n            for (int i = r / bsize * bsize;\
    \ i < r; i++) {\n                res += a[i] + add[i / bsize];\n            }\n\
    \n            for (int i = 0; i < bsize; i++) {\n                if (l < i * bsize\
    \ and (i + 1) * bsize <= r) {\n                    res += sum[i] + add[i] * bsize;\n\
    \                }\n            }\n        }\n        return res;\n    }\n\n \
    \   void range_add(int l, int r, T x) {\n        if (l / bsize == r / bsize) {\n\
    \            for (int i = l; i < r; i++) {\n                a[i] += x;\n     \
    \           sum[i / bsize] += x;\n            }\n        } else {\n          \
    \  for (int i = l; i < l / bsize * bsize + bsize; i++) {\n                a[i]\
    \ += x;\n                sum[i / bsize] += x;\n            }\n\n            for\
    \ (int i = r / bsize * bsize; i < r; i++) {\n                a[i] += x;\n    \
    \            sum[i / bsize] += x;\n            }\n\n            for (int i = 0;\
    \ i < bsize; i++) {\n                if (l < i * bsize and (i + 1) * bsize <=\
    \ r) {\n                    add[i] += x;\n                }\n            }\n \
    \       }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition/RangeAddRangeSum.hpp
  requiredBy: []
  timestamp: '2024-11-28 20:50:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeAddRangeSum.test.cpp
documentation_of: data-structure/square-root-decomposition/RangeAddRangeSum.hpp
layout: document
title: Range Add Range Sum
---

## 概要

todo

## 計算量
todo