---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
    title: Wavelet Matrix (Dual BIT)
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
    title: Rectangle Add Point Get
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
  - data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
  - data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
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