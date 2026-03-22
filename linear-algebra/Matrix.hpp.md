---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LibraryChecker/linear-algebra/MatrixProduct.test.cpp
    title: verify/LibraryChecker/linear-algebra/MatrixProduct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linear-algebra/Matrix.hpp\"\ntemplate <class S>\nstruct\
    \ Matrix {\n private:\n public:\n  vector<vector<S>> A;\n  Matrix() {}\n  Matrix(int\
    \ n, int m) : A(n, vector<S>(m)) {}\n  Matrix(int n) : A(n, vector<S>(n)) {}\n\
    \n  inline int size() const { return A.size(); }\n  inline int height() const\
    \ { return A.size(); }\n  inline int width() const { return A[0].size(); }\n \
    \ inline const vector<S>& operator[](int h) const { return (A[h]); }\n  inline\
    \ vector<S>& operator[](int h) { return (A[h]); }\n\n  Matrix& operator+=(const\
    \ Matrix& B) {\n    int h = height();\n    int w = width();\n    for (int i =\
    \ 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n        (*this)[i][j]\
    \ += B[i][j];\n      }\n    }\n    return (*this);\n  }\n  Matrix& operator-=(const\
    \ Matrix& B) {\n    int h = height();\n    int w = width();\n    for (int i =\
    \ 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n        (*this)[i][j]\
    \ -= B[i][j];\n      }\n    }\n    return (*this);\n  }\n\n  Matrix& operator*=(const\
    \ Matrix& B) {\n    int h = height();\n    int w = B.width();\n    int c = width();\n\
    \    vector<vector<S>> C(h, vector<S>(w));\n    for (int i = 0; i < h; i++) {\n\
    \      for (int j = 0; j < w; j++) {\n        for (int k = 0; k < c; k++) {\n\
    \          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n        }\n      }\n\
    \    }\n    A = move(C);\n    return (*this);\n  }\n  Matrix operator+(const Matrix&\
    \ B) const { return (Matrix(*this) += B); }\n  Matrix operator-(const Matrix&\
    \ B) const { return (Matrix(*this) -= B); }\n  Matrix operator*(const Matrix&\
    \ B) const { return (Matrix(*this) *= B); }\n};\n"
  code: "template <class S>\nstruct Matrix {\n private:\n public:\n  vector<vector<S>>\
    \ A;\n  Matrix() {}\n  Matrix(int n, int m) : A(n, vector<S>(m)) {}\n  Matrix(int\
    \ n) : A(n, vector<S>(n)) {}\n\n  inline int size() const { return A.size(); }\n\
    \  inline int height() const { return A.size(); }\n  inline int width() const\
    \ { return A[0].size(); }\n  inline const vector<S>& operator[](int h) const {\
    \ return (A[h]); }\n  inline vector<S>& operator[](int h) { return (A[h]); }\n\
    \n  Matrix& operator+=(const Matrix& B) {\n    int h = height();\n    int w =\
    \ width();\n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++)\
    \ {\n        (*this)[i][j] += B[i][j];\n      }\n    }\n    return (*this);\n\
    \  }\n  Matrix& operator-=(const Matrix& B) {\n    int h = height();\n    int\
    \ w = width();\n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w;\
    \ j++) {\n        (*this)[i][j] -= B[i][j];\n      }\n    }\n    return (*this);\n\
    \  }\n\n  Matrix& operator*=(const Matrix& B) {\n    int h = height();\n    int\
    \ w = B.width();\n    int c = width();\n    vector<vector<S>> C(h, vector<S>(w));\n\
    \    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n    \
    \    for (int k = 0; k < c; k++) {\n          C[i][j] = (C[i][j] + (*this)[i][k]\
    \ * B[k][j]);\n        }\n      }\n    }\n    A = move(C);\n    return (*this);\n\
    \  }\n  Matrix operator+(const Matrix& B) const { return (Matrix(*this) += B);\
    \ }\n  Matrix operator-(const Matrix& B) const { return (Matrix(*this) -= B);\
    \ }\n  Matrix operator*(const Matrix& B) const { return (Matrix(*this) *= B);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linear-algebra/Matrix.hpp
  requiredBy: []
  timestamp: '2026-03-22 10:42:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LibraryChecker/linear-algebra/MatrixProduct.test.cpp
documentation_of: linear-algebra/Matrix.hpp
layout: document
title: Matrix
---

## 概要

todo

## 計算量
todo