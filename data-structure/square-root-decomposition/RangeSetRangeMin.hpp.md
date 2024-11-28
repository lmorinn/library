---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
    title: verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/square-root-decomposition/RangeSetRangeMin.hpp\"\
    \n\ntemplate <class T>\nclass RangeSetRangeMin {\n   private:\n    int n;\n  \
    \  vector<T> a, mi, lazy;\n    int bsize;\n    T ma;\n\n    void push(int bidx)\
    \ {\n        if (lazy[bidx] != ma) {\n            int start = bidx * bsize;\n\
    \            int end = min(n, start + bsize);\n            for (int i = start;\
    \ i < end; i++) {\n                a[i] = lazy[bidx];\n            }\n       \
    \     lazy[bidx] = ma;\n        }\n    }\n\n    void update(int bidx) {\n    \
    \    mi[bidx] = ma;\n        int start = bidx * bsize;\n        int end = min(n,\
    \ start + bsize);\n        for (int i = start; i < end; i++) {\n            mi[bidx]\
    \ = min(mi[bidx], a[i]);\n        }\n    }\n\n   public:\n    RangeSetRangeMin(const\
    \ vector<T> &v) {\n        ma = numeric_limits<T>::max();\n        a = v;\n  \
    \      n = a.size();\n        bsize = sqrt(n) + 1;\n        lazy.resize(bsize,\
    \ ma);\n        mi.resize(bsize, ma);\n        for (int i = 0; i < n; i++) mi[i\
    \ / bsize] = min(mi[i / bsize], a[i]);\n    }\n\n    T range_min(int l, int r)\
    \ {\n        T res = ma;\n        if (l / bsize == r / bsize) {\n            push(l\
    \ / bsize);\n            for (int i = l; i < r; i++) res = min(res, a[i]);\n \
    \       } else {\n            push(l / bsize);\n            for (int i = l; i\
    \ < l / bsize * bsize + bsize; i++) res = min(res, a[i]);\n\n            push(r\
    \ / bsize);\n            for (int i = r / bsize * bsize; i < r; i++) res = min(res,\
    \ a[i]);\n\n            for (int i = 0; i < bsize; i++) {\n                if\
    \ (l < i * bsize and (i + 1) * bsize <= r) {\n                    res = min(res,\
    \ mi[i]);\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n    void range_set(int l, int r, T x) {\n        if (l / bsize == r\
    \ / bsize) {\n            push(l / bsize);\n            for (int i = l; i < r;\
    \ i++) a[i] = x;\n            update(l / bsize);\n        } else {\n         \
    \   push(l / bsize);\n            for (int i = l; i < l / bsize * bsize + bsize;\
    \ i++) a[i] = x;\n            update(l / bsize);\n\n            push(r / bsize);\n\
    \            for (int i = r / bsize * bsize; i < r; i++) a[i] = x;\n         \
    \   update(r / bsize);\n\n            for (int i = 0; i < bsize; i++) {\n    \
    \            if (l < i * bsize and (i + 1) * bsize <= r) {\n                 \
    \   lazy[i] = x;\n                    mi[i] = x;\n                }\n        \
    \    }\n        }\n    }\n};\n"
  code: "\ntemplate <class T>\nclass RangeSetRangeMin {\n   private:\n    int n;\n\
    \    vector<T> a, mi, lazy;\n    int bsize;\n    T ma;\n\n    void push(int bidx)\
    \ {\n        if (lazy[bidx] != ma) {\n            int start = bidx * bsize;\n\
    \            int end = min(n, start + bsize);\n            for (int i = start;\
    \ i < end; i++) {\n                a[i] = lazy[bidx];\n            }\n       \
    \     lazy[bidx] = ma;\n        }\n    }\n\n    void update(int bidx) {\n    \
    \    mi[bidx] = ma;\n        int start = bidx * bsize;\n        int end = min(n,\
    \ start + bsize);\n        for (int i = start; i < end; i++) {\n            mi[bidx]\
    \ = min(mi[bidx], a[i]);\n        }\n    }\n\n   public:\n    RangeSetRangeMin(const\
    \ vector<T> &v) {\n        ma = numeric_limits<T>::max();\n        a = v;\n  \
    \      n = a.size();\n        bsize = sqrt(n) + 1;\n        lazy.resize(bsize,\
    \ ma);\n        mi.resize(bsize, ma);\n        for (int i = 0; i < n; i++) mi[i\
    \ / bsize] = min(mi[i / bsize], a[i]);\n    }\n\n    T range_min(int l, int r)\
    \ {\n        T res = ma;\n        if (l / bsize == r / bsize) {\n            push(l\
    \ / bsize);\n            for (int i = l; i < r; i++) res = min(res, a[i]);\n \
    \       } else {\n            push(l / bsize);\n            for (int i = l; i\
    \ < l / bsize * bsize + bsize; i++) res = min(res, a[i]);\n\n            push(r\
    \ / bsize);\n            for (int i = r / bsize * bsize; i < r; i++) res = min(res,\
    \ a[i]);\n\n            for (int i = 0; i < bsize; i++) {\n                if\
    \ (l < i * bsize and (i + 1) * bsize <= r) {\n                    res = min(res,\
    \ mi[i]);\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n    void range_set(int l, int r, T x) {\n        if (l / bsize == r\
    \ / bsize) {\n            push(l / bsize);\n            for (int i = l; i < r;\
    \ i++) a[i] = x;\n            update(l / bsize);\n        } else {\n         \
    \   push(l / bsize);\n            for (int i = l; i < l / bsize * bsize + bsize;\
    \ i++) a[i] = x;\n            update(l / bsize);\n\n            push(r / bsize);\n\
    \            for (int i = r / bsize * bsize; i < r; i++) a[i] = x;\n         \
    \   update(r / bsize);\n\n            for (int i = 0; i < bsize; i++) {\n    \
    \            if (l < i * bsize and (i + 1) * bsize <= r) {\n                 \
    \   lazy[i] = x;\n                    mi[i] = x;\n                }\n        \
    \    }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition/RangeSetRangeMin.hpp
  requiredBy: []
  timestamp: '2024-11-28 20:50:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/data-structure/square-root-decomposition/RangeSetRangeMin.test.cpp
documentation_of: data-structure/square-root-decomposition/RangeSetRangeMin.hpp
layout: document
title: Range Set Range Min
---

## 概要

todo

## 計算量
todo