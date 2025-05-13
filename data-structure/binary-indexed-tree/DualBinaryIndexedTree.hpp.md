---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217 (+ \u53CC\u5BFE\
      BIT)"
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
    title: "\u77E9\u5F62\u52A0\u7B97\u30FB\u4E00\u70B9\u53D6\u5F97"
  - icon: ':heavy_check_mark:'
    path: graph/tree/CentroidDecompositionContourAdd.hpp
    title: Centroid Decomposition (Contour Add)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/VertexGetRangeContourAddonTree.test.cpp
    title: verify/LibraryChecker/tree/VertexGetRangeContourAddonTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp\"\
    \ntemplate <class T>\nstruct RangeAddPointGet {\n   private:\n    fenwick_tree<T>\
    \ ft;\n\n   public:\n    RangeAddPointGet() {}\n    RangeAddPointGet(int siz)\
    \ : ft(siz + 1) {}\n\n    void range_add(int l, int r, T x) {\n        ft.add(l,\
    \ x);\n        ft.add(r, -x);\n    }\n\n    void add(int p, T x) {\n        ft.add(p,\
    \ x);\n        ft.add(p + 1, -x);\n    }\n\n    T point_get(int p) {\n       \
    \ return ft.sum(0, p + 1);\n    }\n};\n"
  code: "template <class T>\nstruct RangeAddPointGet {\n   private:\n    fenwick_tree<T>\
    \ ft;\n\n   public:\n    RangeAddPointGet() {}\n    RangeAddPointGet(int siz)\
    \ : ft(siz + 1) {}\n\n    void range_add(int l, int r, T x) {\n        ft.add(l,\
    \ x);\n        ft.add(r, -x);\n    }\n\n    void add(int p, T x) {\n        ft.add(p,\
    \ x);\n        ft.add(p + 1, -x);\n    }\n\n    T point_get(int p) {\n       \
    \ return ft.sum(0, p + 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
  - data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
  - graph/tree/CentroidDecompositionContourAdd.hpp
  timestamp: '2025-05-03 16:54:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/tree/VertexGetRangeContourAddonTree.test.cpp
documentation_of: data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp
layout: document
title: Dual Binary Indexed Tree
---

## 概要

todo

## 計算量
todo