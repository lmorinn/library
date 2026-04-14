---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/EulerTour.hpp
    title: Euler Tour
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
    title: verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
    title: verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
    title: verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/SparseTable.hpp\"\ntemplate <class\
    \ T, auto f>\nclass SparseTable {\n private:\n  vector<vector<T>> st;\n  vector<int>\
    \ lookup;\n\n public:\n  SparseTable() {}\n\n  SparseTable(const vector<T> &v)\
    \ {\n    const int n = (int)v.size();\n    const int b = 32 - __builtin_clz(n);\n\
    \    st.assign(b, vector<T>(n));\n    for (int i = 0; i < v.size(); i++) {\n \
    \     st[0][i] = v[i];\n    }\n    \n    for (int i = 1; i < b; i++) {\n     \
    \ for (int j = 0; j + (1 << i) <= n; j++) {\n        st[i][j] = f(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n    lookup.resize(v.size()\
    \ + 1);\n    for (int i = 2; i < lookup.size(); i++) {\n      lookup[i] = lookup[i\
    \ >> 1] + 1;\n    }\n  }\n\n  inline T query(int l, int r) const {\n    int b\
    \ = lookup[r - l];\n    return f(st[b][l], st[b][r - (1 << b)]);\n  }\n};\n"
  code: "template <class T, auto f>\nclass SparseTable {\n private:\n  vector<vector<T>>\
    \ st;\n  vector<int> lookup;\n\n public:\n  SparseTable() {}\n\n  SparseTable(const\
    \ vector<T> &v) {\n    const int n = (int)v.size();\n    const int b = 32 - __builtin_clz(n);\n\
    \    st.assign(b, vector<T>(n));\n    for (int i = 0; i < v.size(); i++) {\n \
    \     st[0][i] = v[i];\n    }\n    \n    for (int i = 1; i < b; i++) {\n     \
    \ for (int j = 0; j + (1 << i) <= n; j++) {\n        st[i][j] = f(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n    lookup.resize(v.size()\
    \ + 1);\n    for (int i = 2; i < lookup.size(); i++) {\n      lookup[i] = lookup[i\
    \ >> 1] + 1;\n    }\n  }\n\n  inline T query(int l, int r) const {\n    int b\
    \ = lookup[r - l];\n    return f(st[b][l], st[b][r - (1 << b)]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/SparseTable.hpp
  requiredBy:
  - graph/tree/EulerTour.hpp
  timestamp: '2024-06-26 20:58:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/tree/LowestCommonAncestor.test.cpp
  - verify/LibraryChecker/tree/VertexAddSubtreeSum.test.cpp
  - verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
documentation_of: data-structure/others/SparseTable.hpp
layout: document
title: Sparse Table
---

## 概要

長さ $N$ の数列に対して、静的な区間の総積を扱うデータ構造。

## コンストラクタ

```cpp
SparseTable<T, f>(const vector<T>& v)
```

長さ `n = v.size()` の数列を構築する。`v` の内容が初期値となる。

### 制約
- テンプレート引数 `T` : 冪等な二項演算を持つ集合
- `f` は `T` 上の二項演算
- 任意の $x, y, z \in T$ に対して `f(f(x, y), z) = f(x, f(y, z))`
- 任意の $x \in T$ に対して `f(x, x) = x`
- $1 \leq n$

### 計算量
- $O(n \log n)$

## query

```cpp
T st.query(int l, int r) const
```

区間 $[l, r)$ の総積を返す。

### 制約
- $0 \leq l < r \leq n$

### 計算量
- $O(1)$
