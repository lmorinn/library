---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree/BinaryIndexedTree.hpp\"\
    \n\ntemplate <class T>\nstruct fenwick_tree {\n   public:\n    fenwick_tree()\
    \ : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n) {}\n\n    void\
    \ add(int p, T x) {\n        p++;\n        while (p <= _n) {\n            data[p\
    \ - 1] += x;\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int\
    \ r) {\n        return sum(r) - sum(l);\n    }\n\n   private:\n    int _n;\n \
    \   vector<T> data;\n\n    T sum(int r) {\n        T s = 0;\n        while (r\
    \ > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n\
    \        return s;\n    }\n};\n"
  code: "\ntemplate <class T>\nstruct fenwick_tree {\n   public:\n    fenwick_tree()\
    \ : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n) {}\n\n    void\
    \ add(int p, T x) {\n        p++;\n        while (p <= _n) {\n            data[p\
    \ - 1] += x;\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int\
    \ r) {\n        return sum(r) - sum(l);\n    }\n\n   private:\n    int _n;\n \
    \   vector<T> data;\n\n    T sum(int r) {\n        T s = 0;\n        while (r\
    \ > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n\
    \        return s;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2024-11-18 02:13:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
layout: document
title: Binary Indexed Tree
---

## 概要

todo

## 計算量
todo