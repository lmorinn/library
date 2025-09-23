---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LibraryChecker/data-structure/segment-tree/PointSetRangeCompositeLargeArray.test.cpp
    title: verify/LibraryChecker/data-structure/segment-tree/PointSetRangeCompositeLargeArray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree/DynamicSegmentTree.hpp\"\ntemplate\
    \ <class S, auto op, auto e>\nclass DynamicSegmentTree {\n private:\n  struct\
    \ Node {\n    S value;\n    Node *left;\n    Node *right;\n    Node(S value) :\
    \ value(value), left(nullptr), right(nullptr) {}\n  };\n  long long n;\n  Node\
    \ *root = nullptr;\n\n  void set(S x, Node *&t, long long a, long long b, long\
    \ long l = 0, long long r = -1) {\n    if (r < 0) r = n;\n    if (r <= a or b\
    \ <= l) return;\n    if (!t) t = new Node(e());\n    if (r - l == 1) {\n     \
    \ t->value = x;\n      return;\n    }\n    long long m = (l + r) >> 1ll;\n   \
    \ set(x, t->left, a, b, l, m);\n    set(x, t->right, a, b, m, r);\n    if (t->left\
    \ and t->right) {\n      t->value = op(t->left->value, t->right->value);\n   \
    \ } else if (t->left) {\n      t->value = t->left->value;\n    } else if (t->right)\
    \ {\n      t->value = t->right->value;\n    }\n  }\n\n  S prod(Node *&t, long\
    \ long a, long long b, long long l = 0, long long r = -1) {\n    if (r < 0) r\
    \ = n;\n    if (!t or r <= a or b <= l) return e();\n    if (a <= l and r <= b)\
    \ {\n      return t->value;\n    }\n    long long m = (l + r) >> 1ll;\n    return\
    \ op(prod(t->left, a, b, l, m), prod(t->right, a, b, m, r));\n  }\n\n  template\
    \ <auto f>\n  long long max_right(bool &fin, S &p, Node *&t, long long a, long\
    \ long l = 0, long long r = -1) {\n    if (r < 0) r = n;\n    if (l >= r) {\n\
    \      fin = true;\n      return r;\n    }\n    if (fin or r <= a) return l;\n\
    \    if (!t) {\n      S val = op(p, e());\n      if (f(val)) {\n        p = val;\n\
    \        return r;\n      } else {\n        fin = true;\n        return l;\n \
    \     }\n    }\n    if (a <= l) {\n      S val = op(p, t->value);\n      if (f(val))\
    \ {\n        p = val;\n        return r;\n      }\n    }\n    long long m = (l\
    \ + r) >> 1ll;\n    long long res = max_right<f>(fin, p, t->left, a, l, m);\n\
    \    if (fin) return res;\n    return max_right<f>(fin, p, t->right, a, m, r);\n\
    \  }\n\n public:\n  DynamicSegmentTree() {}\n  DynamicSegmentTree(long long n_)\
    \ {\n    n = bit_ceil(uint64_t(n_));\n  }\n  void set(long long p, S x) {\n  \
    \  set(x, root, p, p + 1);\n  }\n\n  S get(long long p) {\n    return prod(root,\
    \ p, p + 1);\n  }\n\n  S prod(long long l, long long r) {\n    return prod(root,\
    \ l, r);\n  }\n\n  template <auto g>\n  long long max_right(long long l) {\n \
    \   S p = e();\n    bool fin = false;\n    return max_right<g>(fin, p, root, l);\n\
    \  }\n};\n"
  code: "template <class S, auto op, auto e>\nclass DynamicSegmentTree {\n private:\n\
    \  struct Node {\n    S value;\n    Node *left;\n    Node *right;\n    Node(S\
    \ value) : value(value), left(nullptr), right(nullptr) {}\n  };\n  long long n;\n\
    \  Node *root = nullptr;\n\n  void set(S x, Node *&t, long long a, long long b,\
    \ long long l = 0, long long r = -1) {\n    if (r < 0) r = n;\n    if (r <= a\
    \ or b <= l) return;\n    if (!t) t = new Node(e());\n    if (r - l == 1) {\n\
    \      t->value = x;\n      return;\n    }\n    long long m = (l + r) >> 1ll;\n\
    \    set(x, t->left, a, b, l, m);\n    set(x, t->right, a, b, m, r);\n    if (t->left\
    \ and t->right) {\n      t->value = op(t->left->value, t->right->value);\n   \
    \ } else if (t->left) {\n      t->value = t->left->value;\n    } else if (t->right)\
    \ {\n      t->value = t->right->value;\n    }\n  }\n\n  S prod(Node *&t, long\
    \ long a, long long b, long long l = 0, long long r = -1) {\n    if (r < 0) r\
    \ = n;\n    if (!t or r <= a or b <= l) return e();\n    if (a <= l and r <= b)\
    \ {\n      return t->value;\n    }\n    long long m = (l + r) >> 1ll;\n    return\
    \ op(prod(t->left, a, b, l, m), prod(t->right, a, b, m, r));\n  }\n\n  template\
    \ <auto f>\n  long long max_right(bool &fin, S &p, Node *&t, long long a, long\
    \ long l = 0, long long r = -1) {\n    if (r < 0) r = n;\n    if (l >= r) {\n\
    \      fin = true;\n      return r;\n    }\n    if (fin or r <= a) return l;\n\
    \    if (!t) {\n      S val = op(p, e());\n      if (f(val)) {\n        p = val;\n\
    \        return r;\n      } else {\n        fin = true;\n        return l;\n \
    \     }\n    }\n    if (a <= l) {\n      S val = op(p, t->value);\n      if (f(val))\
    \ {\n        p = val;\n        return r;\n      }\n    }\n    long long m = (l\
    \ + r) >> 1ll;\n    long long res = max_right<f>(fin, p, t->left, a, l, m);\n\
    \    if (fin) return res;\n    return max_right<f>(fin, p, t->right, a, m, r);\n\
    \  }\n\n public:\n  DynamicSegmentTree() {}\n  DynamicSegmentTree(long long n_)\
    \ {\n    n = bit_ceil(uint64_t(n_));\n  }\n  void set(long long p, S x) {\n  \
    \  set(x, root, p, p + 1);\n  }\n\n  S get(long long p) {\n    return prod(root,\
    \ p, p + 1);\n  }\n\n  S prod(long long l, long long r) {\n    return prod(root,\
    \ l, r);\n  }\n\n  template <auto g>\n  long long max_right(long long l) {\n \
    \   S p = e();\n    bool fin = false;\n    return max_right<g>(fin, p, root, l);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/DynamicSegmentTree.hpp
  requiredBy: []
  timestamp: '2025-06-17 01:30:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LibraryChecker/data-structure/segment-tree/PointSetRangeCompositeLargeArray.test.cpp
documentation_of: data-structure/segment-tree/DynamicSegmentTree.hpp
layout: document
title: Dynamic Segment Tree
---

## 概要

todo

## 計算量
todo