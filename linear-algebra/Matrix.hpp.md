---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/flow/MaximumMatchingSize.hpp
    title: Maximum Matching Size (Randomized)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/flow/GRL_7_A.test.cpp
    title: verify/AizuOnlineJudge/graph/flow/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/DeterminantofMatrix.test.cpp
    title: verify/LibraryChecker/linear-algebra/DeterminantofMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/InverseMatrix.test.cpp
    title: verify/LibraryChecker/linear-algebra/InverseMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/RankofMatrix.test.cpp
    title: verify/LibraryChecker/linear-algebra/RankofMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ B) const { return (Matrix(*this) *= B); }\n\n  int rank() {\n    Matrix B(*this);\n\
    \    if (B.height() == 0 or B.width() == 0) return 0;\n    int res = 0;\n    int\
    \ h = height();\n    int w = width();\n    int ch = 0;\n    int cw = 0;\n    while\
    \ (ch < h and cw < w) {\n      bool ok = false;\n      for (int j = cw; j < w;\
    \ j++) {\n        for (int i = ch; i < h; i++) {\n          if (B[i][j] != 0)\
    \ {\n            ok = true;\n            swap(B[ch], B[i]);\n            S d =\
    \ B[ch][j];\n            for (int j2 = j; j2 < w; j2++) {\n              B[ch][j2]\
    \ /= d;\n            }\n            for (int i2 = 0; i2 < h; i2++) {\n       \
    \       if (B[i2][j] != 0 and i2 != ch) {\n                S m = B[i2][j];\n \
    \               for (int j2 = j; j2 < w; j2++) {\n                  B[i2][j2]\
    \ -= B[ch][j2] * m;\n                }\n              }\n            }\n     \
    \       res++;\n            ch++;\n            cw = j + 1;\n            break;\n\
    \          }\n        }\n        if (ok) break;\n      }\n      if (!ok) break;\n\
    \    }\n    return res;\n  }\n\n  S determinant() {\n    Matrix B(*this);\n  \
    \  if (B.height() == 0 or B.width() == 0) return 0;\n    assert(B.height() ==\
    \ B.width());\n    int h = height();\n    int w = width();\n    int ch = 0;\n\
    \    int cw = 0;\n    S div = 1;\n    bool neg = false;\n    while (ch < h and\
    \ cw < w) {\n      bool ok = false;\n      for (int j = cw; j < w; j++) {\n  \
    \      for (int i = ch; i < h; i++) {\n          if (B[i][j] != 0) {\n       \
    \     ok = true;\n            if (ch != i) neg = !neg;\n            swap(B[ch],\
    \ B[i]);\n            S d = B[ch][j];\n            div /= d;\n            for\
    \ (int j2 = j; j2 < w; j2++) {\n              B[ch][j2] /= d;\n            }\n\
    \            for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) {\n                S m = B[i2][j];\n                for (int j2\
    \ = j; j2 < w; j2++) {\n                  B[i2][j2] -= B[ch][j2] * m;\n      \
    \          }\n              }\n            }\n            ch++;\n            cw\
    \ = j + 1;\n            break;\n          }\n        }\n        if (ok) {\n  \
    \        break;\n        } else {\n          return S(0);\n        }\n      }\n\
    \      if (!ok) break;\n    }\n    S res = (neg ? -B[0][0] : B[0][0]) / div;\n\
    \    for (int i = 1; i < h; i++) {\n      res = res * B[i][i];\n    }\n    return\
    \ res;\n  }\n\n  pair<bool, Matrix<S>> inverse() {\n    int h = height();\n  \
    \  int w = width();\n    assert(h == w);\n    Matrix<S> B(h, w * 2);\n    for\
    \ (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n        B[i][j]\
    \ = (*this)[i][j];\n      }\n    }\n    for (int i = 0; i < h; i++) {\n      B[i][i\
    \ + w] = 1;\n    }\n    w *= 2;\n    int rnk = 0;\n\n    int ch = 0;\n    int\
    \ cw = 0;\n    while (ch < h and cw < h) {\n      bool ok = false;\n      for\
    \ (int j = cw; j < h; j++) {\n        for (int i = ch; i < h; i++) {\n       \
    \   if (B[i][j] != 0) {\n            ok = true;\n            swap(B[ch], B[i]);\n\
    \            S d = B[ch][j];\n            for (int j2 = j; j2 < w; j2++) {\n \
    \             B[ch][j2] /= d;\n            }\n            for (int i2 = 0; i2\
    \ < h; i2++) {\n              if (B[i2][j] != 0 and i2 != ch) {\n            \
    \    S m = B[i2][j];\n                for (int j2 = j; j2 < w; j2++) {\n     \
    \             B[i2][j2] -= B[ch][j2] * m;\n                }\n              }\n\
    \            }\n            rnk++;\n            ch++;\n            cw = j + 1;\n\
    \            break;\n          }\n        }\n        if (ok) break;\n      }\n\
    \      if (!ok) break;\n    }\n    Matrix<S> res(h);\n    if (rnk == h) {\n  \
    \    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < h; j++) {\n  \
    \        res[i][j] = B[i][j + h];\n        }\n      }\n      return {true, res};\n\
    \    } else {\n      return {false, res};\n    }\n  }\n};\n"
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
    \ }\n\n  int rank() {\n    Matrix B(*this);\n    if (B.height() == 0 or B.width()\
    \ == 0) return 0;\n    int res = 0;\n    int h = height();\n    int w = width();\n\
    \    int ch = 0;\n    int cw = 0;\n    while (ch < h and cw < w) {\n      bool\
    \ ok = false;\n      for (int j = cw; j < w; j++) {\n        for (int i = ch;\
    \ i < h; i++) {\n          if (B[i][j] != 0) {\n            ok = true;\n     \
    \       swap(B[ch], B[i]);\n            S d = B[ch][j];\n            for (int\
    \ j2 = j; j2 < w; j2++) {\n              B[ch][j2] /= d;\n            }\n    \
    \        for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0 and\
    \ i2 != ch) {\n                S m = B[i2][j];\n                for (int j2 =\
    \ j; j2 < w; j2++) {\n                  B[i2][j2] -= B[ch][j2] * m;\n        \
    \        }\n              }\n            }\n            res++;\n            ch++;\n\
    \            cw = j + 1;\n            break;\n          }\n        }\n       \
    \ if (ok) break;\n      }\n      if (!ok) break;\n    }\n    return res;\n  }\n\
    \n  S determinant() {\n    Matrix B(*this);\n    if (B.height() == 0 or B.width()\
    \ == 0) return 0;\n    assert(B.height() == B.width());\n    int h = height();\n\
    \    int w = width();\n    int ch = 0;\n    int cw = 0;\n    S div = 1;\n    bool\
    \ neg = false;\n    while (ch < h and cw < w) {\n      bool ok = false;\n    \
    \  for (int j = cw; j < w; j++) {\n        for (int i = ch; i < h; i++) {\n  \
    \        if (B[i][j] != 0) {\n            ok = true;\n            if (ch != i)\
    \ neg = !neg;\n            swap(B[ch], B[i]);\n            S d = B[ch][j];\n \
    \           div /= d;\n            for (int j2 = j; j2 < w; j2++) {\n        \
    \      B[ch][j2] /= d;\n            }\n            for (int i2 = 0; i2 < h; i2++)\
    \ {\n              if (B[i2][j] != 0 and i2 != ch) {\n                S m = B[i2][j];\n\
    \                for (int j2 = j; j2 < w; j2++) {\n                  B[i2][j2]\
    \ -= B[ch][j2] * m;\n                }\n              }\n            }\n     \
    \       ch++;\n            cw = j + 1;\n            break;\n          }\n    \
    \    }\n        if (ok) {\n          break;\n        } else {\n          return\
    \ S(0);\n        }\n      }\n      if (!ok) break;\n    }\n    S res = (neg ?\
    \ -B[0][0] : B[0][0]) / div;\n    for (int i = 1; i < h; i++) {\n      res = res\
    \ * B[i][i];\n    }\n    return res;\n  }\n\n  pair<bool, Matrix<S>> inverse()\
    \ {\n    int h = height();\n    int w = width();\n    assert(h == w);\n    Matrix<S>\
    \ B(h, w * 2);\n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w;\
    \ j++) {\n        B[i][j] = (*this)[i][j];\n      }\n    }\n    for (int i = 0;\
    \ i < h; i++) {\n      B[i][i + w] = 1;\n    }\n    w *= 2;\n    int rnk = 0;\n\
    \n    int ch = 0;\n    int cw = 0;\n    while (ch < h and cw < h) {\n      bool\
    \ ok = false;\n      for (int j = cw; j < h; j++) {\n        for (int i = ch;\
    \ i < h; i++) {\n          if (B[i][j] != 0) {\n            ok = true;\n     \
    \       swap(B[ch], B[i]);\n            S d = B[ch][j];\n            for (int\
    \ j2 = j; j2 < w; j2++) {\n              B[ch][j2] /= d;\n            }\n    \
    \        for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0 and\
    \ i2 != ch) {\n                S m = B[i2][j];\n                for (int j2 =\
    \ j; j2 < w; j2++) {\n                  B[i2][j2] -= B[ch][j2] * m;\n        \
    \        }\n              }\n            }\n            rnk++;\n            ch++;\n\
    \            cw = j + 1;\n            break;\n          }\n        }\n       \
    \ if (ok) break;\n      }\n      if (!ok) break;\n    }\n    Matrix<S> res(h);\n\
    \    if (rnk == h) {\n      for (int i = 0; i < h; i++) {\n        for (int j\
    \ = 0; j < h; j++) {\n          res[i][j] = B[i][j + h];\n        }\n      }\n\
    \      return {true, res};\n    } else {\n      return {false, res};\n    }\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: linear-algebra/Matrix.hpp
  requiredBy:
  - graph/flow/MaximumMatchingSize.hpp
  timestamp: '2026-03-22 22:45:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/flow/GRL_7_A.test.cpp
  - verify/LibraryChecker/linear-algebra/RankofMatrix.test.cpp
  - verify/LibraryChecker/linear-algebra/InverseMatrix.test.cpp
  - verify/LibraryChecker/linear-algebra/DeterminantofMatrix.test.cpp
documentation_of: linear-algebra/Matrix.hpp
layout: document
title: Matrix
---

## 概要

todo

## 計算量
todo