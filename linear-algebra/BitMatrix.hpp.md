---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/DeterminantofMatrixMod2.test.cpp
    title: verify/LibraryChecker/linear-algebra/DeterminantofMatrixMod2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/InverseMatrixMod2.test.cpp
    title: verify/LibraryChecker/linear-algebra/InverseMatrixMod2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/MatrixProductMod2.test.cpp
    title: verify/LibraryChecker/linear-algebra/MatrixProductMod2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/RankofMatrixMod2.test.cpp
    title: verify/LibraryChecker/linear-algebra/RankofMatrixMod2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
    title: verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linear-algebra/BitMatrix.hpp\"\n\n\nstruct BitMatrix {\n\
    \ private:\n public:\n  vector<dynamic_bitset<>> A;\n  BitMatrix() {}\n  BitMatrix(int\
    \ n, int m) : A(n, dynamic_bitset<>(m)) {}\n  BitMatrix(int n) : A(n, dynamic_bitset<>(n))\
    \ {}\n\n  inline int size() const { return A.size(); }\n  inline int height()\
    \ const { return A.size(); }\n  inline int width() const { return A[0].size();\
    \ }\n  inline const dynamic_bitset<>& operator[](int h) const { return (A[h]);\
    \ }\n  inline dynamic_bitset<>& operator[](int h) { return (A[h]); }\n\n  BitMatrix&\
    \ operator+=(const BitMatrix& B) {\n    int h = height();\n    for (int i = 0;\
    \ i < h; i++) (*this)[i] ^= B[i];\n    return (*this);\n  }\n  BitMatrix& operator-=(const\
    \ BitMatrix& B) {\n    int h = height();\n    for (int i = 0; i < h; i++) (*this)[i]\
    \ ^= B[i];\n    return (*this);\n  }\n\n  BitMatrix& operator*=(const BitMatrix&\
    \ B) {\n    int h = height();\n    int w = B.width();\n    int c = width();\n\
    \    vector<dynamic_bitset<>> C(h, dynamic_bitset<>(w));\n    for (int i = 0;\
    \ i < h; i++) {\n      for (int j = 0; j < c; j++) {\n        if ((*this)[i][j])\
    \ C[i] ^= B[j];\n      }\n    }\n    A = move(C);\n    return (*this);\n  }\n\n\
    \  BitMatrix operator+(const BitMatrix& B) const { return (BitMatrix(*this) +=\
    \ B); }\n  BitMatrix operator-(const BitMatrix& B) const { return (BitMatrix(*this)\
    \ -= B); }\n  BitMatrix operator*(const BitMatrix& B) const { return (BitMatrix(*this)\
    \ *= B); }\n\n  int rank() {\n    BitMatrix B(*this);\n    if (B.height() == 0\
    \ or B.width() == 0) return 0;\n    int res = 0;\n    int h = height();\n    int\
    \ w = width();\n    int ch = 0;\n    int cw = 0;\n    while (ch < h and cw < w)\
    \ {\n      bool ok = false;\n      for (int j = cw; j < w; j++) {\n        for\
    \ (int i = ch; i < h; i++) {\n          if (B[i][j]) {\n            ok = true;\n\
    \            swap(B[ch], B[i]);\n            for (int i2 = 0; i2 < h; i2++) {\n\
    \              if (B[i2][j] != 0 and i2 != ch) B[i2] ^= B[ch];\n            }\n\
    \            res++;\n            ch++;\n            cw = j + 1;\n            break;\n\
    \          }\n        }\n        if (ok) break;\n      }\n      if (!ok) break;\n\
    \    }\n    return res;\n  }\n\n  int determinant() {\n    BitMatrix B(*this);\n\
    \    if (B.height() == 0 or B.width() == 0) return 0;\n    assert(B.height() ==\
    \ B.width());\n    int h = height();\n    int w = width();\n    int ch = 0;\n\
    \    int cw = 0;\n    while (ch < h and cw < w) {\n      bool ok = false;\n  \
    \    for (int j = cw; j < w; j++) {\n        for (int i = ch; i < h; i++) {\n\
    \          if (B[i][j]) {\n            ok = true;\n            swap(B[ch], B[i]);\n\
    \            for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) B[i2] ^= B[ch];\n            }\n            ch++;\n          \
    \  cw = j + 1;\n            break;\n          }\n        }\n        if (ok) {\n\
    \          break;\n        } else {\n          return 0;\n        }\n      }\n\
    \      if (!ok) break;\n    }\n    return 1;\n  }\n\n  pair<bool, BitMatrix> inverse()\
    \ {\n    int h = height();\n    int w = width();\n    assert(h == w);\n    BitMatrix\
    \ B(h, w * 2);\n    for (int i = 0; i < h; i++) {\n      dynamic_bitset<> tmp\
    \ = (*this)[i];\n      tmp.resize(w * 2);\n      tmp[i + w] = 1;\n      B[i] ^=\
    \ tmp;\n    }\n\n    w *= 2;\n    int rnk = 0;\n\n    int ch = 0;\n    int cw\
    \ = 0;\n    while (ch < h and cw < h) {\n      bool ok = false;\n      for (int\
    \ j = cw; j < h; j++) {\n        for (int i = ch; i < h; i++) {\n          if\
    \ (B[i][j] != 0) {\n            ok = true;\n            swap(B[ch], B[i]);\n \
    \           for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) B[i2] ^= B[ch];\n            }\n            rnk++;\n         \
    \   ch++;\n            cw = j + 1;\n            break;\n          }\n        }\n\
    \        if (ok) break;\n      }\n      if (!ok) break;\n    }\n    BitMatrix\
    \ res(h);\n    if (rnk == h) {\n      for (int i = 0; i < h; i++) {\n        B[i]\
    \ >>= h;\n        B[i].resize(h);\n        res[i] ^= B[i];\n      }\n      return\
    \ {true, res};\n    } else {\n      return {false, res};\n    }\n  }\n\n  BitMatrix\
    \ linear_equation(dynamic_bitset<> b) {\n    BitMatrix A(*this);\n    int rnk\
    \ = 0;\n    assert(A.height() == b.size());\n    int h = height();\n    int w\
    \ = width();\n    int ch = 0;\n    int cw = 0;\n    vector<int> pivot_row(w, -1);\n\
    \    while (ch < h and cw < w) {\n      bool ok = false;\n      for (int j = cw;\
    \ j < w; j++) {\n        for (int i = ch; i < h; i++) {\n          if (A[i][j]\
    \ != 0) {\n            ok = true;\n            swap(A[ch], A[i]);\n          \
    \  bool tmp = b[ch];\n            b[ch] = b[i];\n            b[i] = tmp;\n   \
    \         for (int i2 = 0; i2 < h; i2++) {\n              if (A[i2][j] != 0 and\
    \ i2 != ch) {\n                A[i2] ^= A[ch];\n                b[i2] = b[i2]\
    \ ^ b[ch];\n              }\n            }\n            pivot_row[j] = ch;\n \
    \           rnk++;\n            ch++;\n            cw = j + 1;\n            break;\n\
    \          }\n        }\n        if (ok) break;\n      }\n      if (!ok) break;\n\
    \    }\n\n    for (int i = rnk; i < h; i++) {\n      if (b[i] != 0) return BitMatrix(0);\n\
    \    }\n    BitMatrix sol(w - rnk + 1, w);\n    int idx = 1;\n    for (int j =\
    \ 0; j < w; j++) {\n      if (pivot_row[j] != -1) {\n        sol[0][j] = b[pivot_row[j]];\n\
    \      } else {\n        sol[idx][j] = 1;\n        for (int i = 0; i < w; i++)\
    \ {\n          if (pivot_row[i] != -1) {\n            sol[idx][i] = A[pivot_row[i]][j];\n\
    \          }\n        }\n        idx++;\n      }\n    }\n    return sol;\n  }\n\
    };\n"
  code: "\n\nstruct BitMatrix {\n private:\n public:\n  vector<dynamic_bitset<>> A;\n\
    \  BitMatrix() {}\n  BitMatrix(int n, int m) : A(n, dynamic_bitset<>(m)) {}\n\
    \  BitMatrix(int n) : A(n, dynamic_bitset<>(n)) {}\n\n  inline int size() const\
    \ { return A.size(); }\n  inline int height() const { return A.size(); }\n  inline\
    \ int width() const { return A[0].size(); }\n  inline const dynamic_bitset<>&\
    \ operator[](int h) const { return (A[h]); }\n  inline dynamic_bitset<>& operator[](int\
    \ h) { return (A[h]); }\n\n  BitMatrix& operator+=(const BitMatrix& B) {\n   \
    \ int h = height();\n    for (int i = 0; i < h; i++) (*this)[i] ^= B[i];\n   \
    \ return (*this);\n  }\n  BitMatrix& operator-=(const BitMatrix& B) {\n    int\
    \ h = height();\n    for (int i = 0; i < h; i++) (*this)[i] ^= B[i];\n    return\
    \ (*this);\n  }\n\n  BitMatrix& operator*=(const BitMatrix& B) {\n    int h =\
    \ height();\n    int w = B.width();\n    int c = width();\n    vector<dynamic_bitset<>>\
    \ C(h, dynamic_bitset<>(w));\n    for (int i = 0; i < h; i++) {\n      for (int\
    \ j = 0; j < c; j++) {\n        if ((*this)[i][j]) C[i] ^= B[j];\n      }\n  \
    \  }\n    A = move(C);\n    return (*this);\n  }\n\n  BitMatrix operator+(const\
    \ BitMatrix& B) const { return (BitMatrix(*this) += B); }\n  BitMatrix operator-(const\
    \ BitMatrix& B) const { return (BitMatrix(*this) -= B); }\n  BitMatrix operator*(const\
    \ BitMatrix& B) const { return (BitMatrix(*this) *= B); }\n\n  int rank() {\n\
    \    BitMatrix B(*this);\n    if (B.height() == 0 or B.width() == 0) return 0;\n\
    \    int res = 0;\n    int h = height();\n    int w = width();\n    int ch = 0;\n\
    \    int cw = 0;\n    while (ch < h and cw < w) {\n      bool ok = false;\n  \
    \    for (int j = cw; j < w; j++) {\n        for (int i = ch; i < h; i++) {\n\
    \          if (B[i][j]) {\n            ok = true;\n            swap(B[ch], B[i]);\n\
    \            for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) B[i2] ^= B[ch];\n            }\n            res++;\n         \
    \   ch++;\n            cw = j + 1;\n            break;\n          }\n        }\n\
    \        if (ok) break;\n      }\n      if (!ok) break;\n    }\n    return res;\n\
    \  }\n\n  int determinant() {\n    BitMatrix B(*this);\n    if (B.height() ==\
    \ 0 or B.width() == 0) return 0;\n    assert(B.height() == B.width());\n    int\
    \ h = height();\n    int w = width();\n    int ch = 0;\n    int cw = 0;\n    while\
    \ (ch < h and cw < w) {\n      bool ok = false;\n      for (int j = cw; j < w;\
    \ j++) {\n        for (int i = ch; i < h; i++) {\n          if (B[i][j]) {\n \
    \           ok = true;\n            swap(B[ch], B[i]);\n            for (int i2\
    \ = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0 and i2 != ch) B[i2] ^=\
    \ B[ch];\n            }\n            ch++;\n            cw = j + 1;\n        \
    \    break;\n          }\n        }\n        if (ok) {\n          break;\n   \
    \     } else {\n          return 0;\n        }\n      }\n      if (!ok) break;\n\
    \    }\n    return 1;\n  }\n\n  pair<bool, BitMatrix> inverse() {\n    int h =\
    \ height();\n    int w = width();\n    assert(h == w);\n    BitMatrix B(h, w *\
    \ 2);\n    for (int i = 0; i < h; i++) {\n      dynamic_bitset<> tmp = (*this)[i];\n\
    \      tmp.resize(w * 2);\n      tmp[i + w] = 1;\n      B[i] ^= tmp;\n    }\n\n\
    \    w *= 2;\n    int rnk = 0;\n\n    int ch = 0;\n    int cw = 0;\n    while\
    \ (ch < h and cw < h) {\n      bool ok = false;\n      for (int j = cw; j < h;\
    \ j++) {\n        for (int i = ch; i < h; i++) {\n          if (B[i][j] != 0)\
    \ {\n            ok = true;\n            swap(B[ch], B[i]);\n            for (int\
    \ i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0 and i2 != ch) B[i2]\
    \ ^= B[ch];\n            }\n            rnk++;\n            ch++;\n          \
    \  cw = j + 1;\n            break;\n          }\n        }\n        if (ok) break;\n\
    \      }\n      if (!ok) break;\n    }\n    BitMatrix res(h);\n    if (rnk ==\
    \ h) {\n      for (int i = 0; i < h; i++) {\n        B[i] >>= h;\n        B[i].resize(h);\n\
    \        res[i] ^= B[i];\n      }\n      return {true, res};\n    } else {\n \
    \     return {false, res};\n    }\n  }\n\n  BitMatrix linear_equation(dynamic_bitset<>\
    \ b) {\n    BitMatrix A(*this);\n    int rnk = 0;\n    assert(A.height() == b.size());\n\
    \    int h = height();\n    int w = width();\n    int ch = 0;\n    int cw = 0;\n\
    \    vector<int> pivot_row(w, -1);\n    while (ch < h and cw < w) {\n      bool\
    \ ok = false;\n      for (int j = cw; j < w; j++) {\n        for (int i = ch;\
    \ i < h; i++) {\n          if (A[i][j] != 0) {\n            ok = true;\n     \
    \       swap(A[ch], A[i]);\n            bool tmp = b[ch];\n            b[ch] =\
    \ b[i];\n            b[i] = tmp;\n            for (int i2 = 0; i2 < h; i2++) {\n\
    \              if (A[i2][j] != 0 and i2 != ch) {\n                A[i2] ^= A[ch];\n\
    \                b[i2] = b[i2] ^ b[ch];\n              }\n            }\n    \
    \        pivot_row[j] = ch;\n            rnk++;\n            ch++;\n         \
    \   cw = j + 1;\n            break;\n          }\n        }\n        if (ok) break;\n\
    \      }\n      if (!ok) break;\n    }\n\n    for (int i = rnk; i < h; i++) {\n\
    \      if (b[i] != 0) return BitMatrix(0);\n    }\n    BitMatrix sol(w - rnk +\
    \ 1, w);\n    int idx = 1;\n    for (int j = 0; j < w; j++) {\n      if (pivot_row[j]\
    \ != -1) {\n        sol[0][j] = b[pivot_row[j]];\n      } else {\n        sol[idx][j]\
    \ = 1;\n        for (int i = 0; i < w; i++) {\n          if (pivot_row[i] != -1)\
    \ {\n            sol[idx][i] = A[pivot_row[i]][j];\n          }\n        }\n \
    \       idx++;\n      }\n    }\n    return sol;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: linear-algebra/BitMatrix.hpp
  requiredBy: []
  timestamp: '2026-03-24 21:06:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/linear-algebra/MatrixProductMod2.test.cpp
  - verify/LibraryChecker/linear-algebra/RankofMatrixMod2.test.cpp
  - verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
  - verify/LibraryChecker/linear-algebra/InverseMatrixMod2.test.cpp
  - verify/LibraryChecker/linear-algebra/DeterminantofMatrixMod2.test.cpp
documentation_of: linear-algebra/BitMatrix.hpp
layout: document
title: Matrix (Mod 2)
---

## 概要

mod 2 上の行列を扱う。

## コンストラクタ

```cpp
(1) BitMatrix(int n, int m)
(2) BitMatrix(int n)
```

- (1) `n` 行 `m` 列の行列を構築する。
- (2) `n` 行 `n` 列の行列を構築する。

### 計算量
- $O(nm / \omega)$

ここで、$\omega$ は machine word の bit 数とする。

## size / height / width

```cpp
int mat.size() const
int mat.height() const
int mat.width() const
```

- `size()` は行数を返す。
- `height()` は行数を返す。
- `width()` は列数を返す。

### 計算量
- $O(1)$

## operator[]

```cpp
(1) const dynamic_bitset<>& mat.operator[](int h) const
(2) dynamic_bitset<>& mat.operator[](int h)
```

`h` 行目を返す。

### 制約
- $0 \leq h < \mathrm{height}()$


## operator+ / operator-

```cpp
BitMatrix mat.operator+(const BitMatrix& B) const
BitMatrix mat.operator-(const BitMatrix& B) const
```

mod 2 上で行列の和または差を返す。

### 制約
- 2 つの行列のサイズが等しい

### 計算量
- $O(hm / \omega)$

ここで、`h = mat.height()`、`m = mat.width()`、$\omega$ は machine word の bit 数とする。

## operator*

```cpp
BitMatrix mat.operator*(const BitMatrix& B) const
```

mod 2 上で行列積を返す。

### 制約
- `mat.width() = B.height()`

### 計算量
- $O(hc + hcm / \omega)$

ここで、`h = mat.height()`、`c = mat.width()`、`m = B.width()`、$\omega$ は machine word の bit 数とする。

## rank

```cpp
int mat.rank()
```

行列の階数を返す。

### 計算量
- $O(hm + h \min(h, m)m / \omega)$

ここで、`h = mat.height()`、`m = mat.width()`、$\omega$ は machine word の bit 数とする。

## determinant

```cpp
int mat.determinant()
```

正方行列の行列式を mod 2 で返す。

### 制約
- `mat.height() = mat.width()`

### 計算量
- $O(n^3 / \omega)$

ここで、$\omega$ は machine word の bit 数とする。

## inverse

```cpp
pair<bool, BitMatrix> mat.inverse()
```

正方行列の逆行列を mod 2 で求める。逆行列が存在するとき、返り値の `first` は `true`、`second` は逆行列となる。存在しないとき、返り値の `first` は `false` となる。

### 制約
- `mat.height() = mat.width()`

### 計算量
- $O(n^3 / \omega)$

ここで、$\omega$ は machine word の bit 数とする。

## linear_equation

```cpp
BitMatrix mat.linear_equation(dynamic_bitset<> b)
```

線形方程式 `mat x = b` を mod 2 で解く。解が存在しないときは `BitMatrix(0)` を返す。解が存在するとき、返り値の 0 行目は特殊解を表し、1 行目以降は解空間の基底を表す。

### 制約
- `mat.height() = b.size()`

### 計算量
- $O(hm + h \min(h, m)m / \omega)$

ここで、`h = mat.height()`、`m = mat.width()`、$\omega$ は machine word の bit 数とする。
