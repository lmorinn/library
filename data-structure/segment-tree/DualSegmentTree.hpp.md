---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.test.cpp
    title: verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segment-tree/DualSegmentTree.hpp\"\ntemplate\
    \ <class S, class F, auto mapping, auto composition, auto id>\nstruct DualSegmentTree\
    \ {\n   private:\n    int n;\n    vector<F> node;\n    vector<S> ar;\n    F ID;\n\
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
    \ f);\n        }\n        return f;\n    }\n};\n"
  code: "#pragma once\ntemplate <class S, class F, auto mapping, auto composition,\
    \ auto id>\nstruct DualSegmentTree {\n   private:\n    int n;\n    vector<F> node;\n\
    \    vector<S> ar;\n    F ID;\n    void Apply(int a, int b, F x, int k = 0, int\
    \ l = 0, int r = -1) {\n        if (r < 0) r = n;\n        eval(k, l, r);\n  \
    \      if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n      \
    \      node[k] = composition(x, node[k]);\n            eval(k, l, r);\n      \
    \      return;\n        }\n        Apply(a, b, x, 2 * k + 1, l, (l + r) / 2);\n\
    \        Apply(a, b, x, 2 * k + 2, (l + r) / 2, r);\n    }\n\n    void eval(int\
    \ k, int l, int r) {\n        if (r - l > 1) {\n            node[k * 2 + 1] =\
    \ composition(node[k], node[k * 2 + 1]);\n            node[k * 2 + 2] = composition(node[k],\
    \ node[k * 2 + 2]);\n        } else {\n            ar[k - n + 1] = mapping(node[k],\
    \ ar[k - n + 1]);\n        }\n        node[k] = ID;\n    }\n\n   public:\n   \
    \ DualSegmentTree() {}\n    DualSegmentTree(vector<S> &v) {\n        int sz =\
    \ v.size();\n        n = 1;\n        while (n < sz) n *= 2;\n        node.resize(2\
    \ * n - 1, id());\n        ar.resize(sz);\n        for (int i = 0; i < sz; i++)\
    \ {\n            ar[i] = v[i];\n        }\n        ID = id();\n    }\n\n    void\
    \ apply(int l, int r, F x) {\n        Apply(l, r, x);\n    }\n\n    S get(int\
    \ p) {\n        S ret = ar[p];\n        int l = p;\n        int r = p + 1;\n \
    \       p += (n - 1);\n        F f = node[p];\n        while (p > 0) {\n     \
    \       p = (p - 1) / 2;\n            f = composition(node[p], f);\n        }\n\
    \        return mapping(f, ret);\n    }\n\n    F getf(int p) {\n        p += (n\
    \ - 1);\n        F f = node[p];\n        while (p > 0) {\n            p = (p -\
    \ 1) / 2;\n            f = composition(node[p], f);\n        }\n        return\
    \ f;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2024-08-24 12:35:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/segment-tree/RangeAffinePointGet.test.cpp
documentation_of: data-structure/segment-tree/DualSegmentTree.hpp
layout: document
title: Dual Segment Tree
---

## 概要

長さ $N$ の数列に対して、区間への作用と一点取得を扱うデータ構造。

## コンストラクタ

```cpp
DualSegmentTree<S, F, mapping, composition, id>(vector<S>& v)
```

長さ `n = v.size()` の数列`a`を構築する。`v` の内容が初期値となる。

### 制約
- `S` は値の型
- `F` は写像の合成について閉じている
- `composition` は写像の合成
- `id()` は恒等写像

### 計算量
- $O(n)$

## apply

```cpp
void seg.apply(int l, int r, F x)
```

-  `i = l, l + 1, ..., r - 1` について `a[i] = mapping(f, a[i])` とする。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## get

```cpp
S seg.get(int p)
```

`a[p]` を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## getf

```cpp
F seg.getf(int p)
```

`a[p]` に対するこれまでの作用の合成を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$
