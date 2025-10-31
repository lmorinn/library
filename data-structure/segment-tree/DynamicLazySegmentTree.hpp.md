---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/segment-tree/RangeAffineRangeSumLargeArray.test.cpp
    title: verify/LibraryChecker/data-structure/segment-tree/RangeAffineRangeSumLargeArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree/DynamicLazySegmentTree.hpp\"\
    \ntemplate <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id, auto filled>\nclass DynamicLazySegmentTree {\n   private:\n    struct\
    \ Node {\n        S value;\n        F lazy;\n        Node* left;\n        Node*\
    \ right;\n        Node(S value) : value(value), left(nullptr), right(nullptr),\
    \ lazy(id()) {}\n    };\n    long long n;\n    Node* root = nullptr;\n    vector<S>\
    \ identity;\n\n    void set(S x, Node*& t, long long a, long long b, int d, long\
    \ long l = 0, long long r = -1) {\n        if (r < 0) r = n;\n        if (!t)\
    \ t = new Node(identity[d]);\n        eval(t, l, r, d);\n        if (r <= a or\
    \ b <= l) return;\n\n        if (r - l == 1) {\n            t->value = x;\n  \
    \          return;\n        }\n        long long m = (l + r) >> 1ll;\n       \
    \ set(x, t->left, a, b, l, m);\n        set(x, t->right, a, b, m, r);\n      \
    \  if (t->left and t->right) {\n            t->value = op(t->left->value, t->right->value);\n\
    \        } else if (t->left) {\n            t->value = t->left->value;\n     \
    \   } else if (t->right) {\n            t->value = t->right->value;\n        }\n\
    \    }\n\n    void apply(Node*& t, F x, long long a, long long b, int d, long\
    \ long l = 0, long long r = -1) {\n        if (r < 0) r = n;\n        if (!t)\
    \ t = new Node(identity[d]);\n        eval(t, l, r, d);\n        if (r <= a or\
    \ b <= l) return;\n        if (a <= l and r <= b) {\n            t->lazy = composition(x,\
    \ t->lazy);\n            eval(t, l, r, d);\n        } else {\n            long\
    \ long m = (l + r) >> 1;\n            apply(t->left, x, a, b, d + 1, l, m);\n\
    \            apply(t->right, x, a, b, d + 1, m, r);\n            t->value = op(t->left->value,\
    \ t->right->value);\n        }\n    }\n\n    S prod(Node*& t, long long a, long\
    \ long b, int d, long long l = 0, long long r = -1) {\n        if (r < 0) r =\
    \ n;\n        if (r <= a or b <= l) return e();\n        if (!t) t = new Node(identity[d]);\n\
    \        eval(t, l, r, d);\n        if (a <= l and r <= b) {\n            return\
    \ t->value;\n        }\n        long long m = (l + r) >> 1ll;\n        return\
    \ op(prod(t->left, a, b, d + 1, l, m), prod(t->right, a, b, d + 1, m, r));\n \
    \   }\n\n    void eval(Node* t, long long l, long long r, int d) {\n        if\
    \ (!t) return;\n        t->value = mapping(t->lazy, t->value);\n        if (r\
    \ - l > 1) {\n            if (!t->left) t->left = new Node(identity[d + 1]);\n\
    \            if (!t->right) t->right = new Node(identity[d + 1]);\n          \
    \  t->left->lazy = composition(t->lazy, t->left->lazy);\n            t->right->lazy\
    \ = composition(t->lazy, t->right->lazy);\n        }\n        t->lazy = id();\n\
    \    }\n\n   public:\n    DynamicLazySegmentTree() {}\n    DynamicLazySegmentTree(long\
    \ long n_) {\n        n = bit_ceil(uint64_t(n_));\n        int log = bit_width(uint64_t(n));\n\
    \        identity.resize(log);\n        identity[log - 1] = filled();\n      \
    \  for (int i = log - 2; i >= 0; i--) {\n            identity[i] = op(identity[i\
    \ + 1], identity[i + 1]);\n        }\n    }\n    void set(long long p, S x) {\n\
    \        set(x, root, p, p + 1, 0);\n    }\n\n    S get(long long p) {\n     \
    \   return prod(root, p, p + 1, 0);\n    }\n\n    S prod(long long l, long long\
    \ r) {\n        return prod(root, l, r, 0);\n    }\n\n    void apply(long long\
    \ l, long long r, F x) {\n        apply(root, x, l, r, 0);\n    }\n};\n"
  code: "template <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id, auto filled>\nclass DynamicLazySegmentTree {\n   private:\n    struct\
    \ Node {\n        S value;\n        F lazy;\n        Node* left;\n        Node*\
    \ right;\n        Node(S value) : value(value), left(nullptr), right(nullptr),\
    \ lazy(id()) {}\n    };\n    long long n;\n    Node* root = nullptr;\n    vector<S>\
    \ identity;\n\n    void set(S x, Node*& t, long long a, long long b, int d, long\
    \ long l = 0, long long r = -1) {\n        if (r < 0) r = n;\n        if (!t)\
    \ t = new Node(identity[d]);\n        eval(t, l, r, d);\n        if (r <= a or\
    \ b <= l) return;\n\n        if (r - l == 1) {\n            t->value = x;\n  \
    \          return;\n        }\n        long long m = (l + r) >> 1ll;\n       \
    \ set(x, t->left, a, b, l, m);\n        set(x, t->right, a, b, m, r);\n      \
    \  if (t->left and t->right) {\n            t->value = op(t->left->value, t->right->value);\n\
    \        } else if (t->left) {\n            t->value = t->left->value;\n     \
    \   } else if (t->right) {\n            t->value = t->right->value;\n        }\n\
    \    }\n\n    void apply(Node*& t, F x, long long a, long long b, int d, long\
    \ long l = 0, long long r = -1) {\n        if (r < 0) r = n;\n        if (!t)\
    \ t = new Node(identity[d]);\n        eval(t, l, r, d);\n        if (r <= a or\
    \ b <= l) return;\n        if (a <= l and r <= b) {\n            t->lazy = composition(x,\
    \ t->lazy);\n            eval(t, l, r, d);\n        } else {\n            long\
    \ long m = (l + r) >> 1;\n            apply(t->left, x, a, b, d + 1, l, m);\n\
    \            apply(t->right, x, a, b, d + 1, m, r);\n            t->value = op(t->left->value,\
    \ t->right->value);\n        }\n    }\n\n    S prod(Node*& t, long long a, long\
    \ long b, int d, long long l = 0, long long r = -1) {\n        if (r < 0) r =\
    \ n;\n        if (r <= a or b <= l) return e();\n        if (!t) t = new Node(identity[d]);\n\
    \        eval(t, l, r, d);\n        if (a <= l and r <= b) {\n            return\
    \ t->value;\n        }\n        long long m = (l + r) >> 1ll;\n        return\
    \ op(prod(t->left, a, b, d + 1, l, m), prod(t->right, a, b, d + 1, m, r));\n \
    \   }\n\n    void eval(Node* t, long long l, long long r, int d) {\n        if\
    \ (!t) return;\n        t->value = mapping(t->lazy, t->value);\n        if (r\
    \ - l > 1) {\n            if (!t->left) t->left = new Node(identity[d + 1]);\n\
    \            if (!t->right) t->right = new Node(identity[d + 1]);\n          \
    \  t->left->lazy = composition(t->lazy, t->left->lazy);\n            t->right->lazy\
    \ = composition(t->lazy, t->right->lazy);\n        }\n        t->lazy = id();\n\
    \    }\n\n   public:\n    DynamicLazySegmentTree() {}\n    DynamicLazySegmentTree(long\
    \ long n_) {\n        n = bit_ceil(uint64_t(n_));\n        int log = bit_width(uint64_t(n));\n\
    \        identity.resize(log);\n        identity[log - 1] = filled();\n      \
    \  for (int i = log - 2; i >= 0; i--) {\n            identity[i] = op(identity[i\
    \ + 1], identity[i + 1]);\n        }\n    }\n    void set(long long p, S x) {\n\
    \        set(x, root, p, p + 1, 0);\n    }\n\n    S get(long long p) {\n     \
    \   return prod(root, p, p + 1, 0);\n    }\n\n    S prod(long long l, long long\
    \ r) {\n        return prod(root, l, r, 0);\n    }\n\n    void apply(long long\
    \ l, long long r, F x) {\n        apply(root, x, l, r, 0);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/DynamicLazySegmentTree.hpp
  requiredBy: []
  timestamp: '2025-10-31 22:26:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/segment-tree/RangeAffineRangeSumLargeArray.test.cpp
documentation_of: data-structure/segment-tree/DynamicLazySegmentTree.hpp
layout: document
title: Dynamic Lazy Segment Tree
---

## 概要

todo

## 計算量
todo