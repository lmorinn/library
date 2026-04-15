---
title: Matrix
documentation_of: //linear-algebra/Matrix.hpp
---

## 概要

素数 mod 上の行列を扱う。

## コンストラクタ

```cpp
(1) Matrix<S>(int n, int m)
(2) Matrix<S>(int n)
```

- (1) `n` 行 `m` 列の行列を構築する。
- (2) `n` 行 `n` 列の行列を構築する。

### 制約
- `S` は素数 mod 上の四則演算ができる型

### 計算量
- (1) $O(nm)$
- (2) $O(n^2)$

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
(1) const vector<S>& mat.operator[](int h) const
(2) vector<S>& mat.operator[](int h)
```

`h` 行目を返す。

### 制約
- $0 \leq h < \mathrm{height}()$


## operator+ / operator-

```cpp
Matrix mat.operator+(const Matrix& B) const
Matrix mat.operator-(const Matrix& B) const
```

行列の和または差を返す。

### 制約
- 2 つの行列のサイズが等しい

### 計算量
- $O(hw)$

ここで、`h = mat.height()`、`w = mat.width()` とする。

## operator*

```cpp
Matrix mat.operator*(const Matrix& B) const
```

行列積を返す。

### 制約
- `mat.width() = B.height()`

### 計算量
- $O(hwc)$

ここで、`h = mat.height()`、`w = B.width()`、`c = mat.width()` とする。

## rank

```cpp
int mat.rank()
```

行列の階数を返す。

### 計算量
- $O(hw \min(h, w))$

ここで、`h = mat.height()`、`w = mat.width()` とする。

## determinant

```cpp
S mat.determinant()
```

正方行列の行列式を返す。

### 制約
- `mat.height() = mat.width()`

### 計算量
- $O(n^3)$

## inverse

```cpp
pair<bool, Matrix<S>> mat.inverse()
```

正方行列の逆行列を求める。逆行列が存在するとき、返り値の `first` は `true`、`second` は逆行列となる。存在しないとき、返り値の `first` は `false` となる。

### 制約
- `mat.height() = mat.width()`

### 計算量
- $O(n^3)$

## linear_equation

```cpp
Matrix<S> mat.linear_equation(vector<S> b)
```

線形方程式 `mat x = b` を解く。解が存在しないときは `Matrix<S>(0)` を返す。解が存在するとき、返り値の 0 行目は特殊解を表し、1 行目以降は解空間の基底を表す。

### 制約
- `mat.height() = b.size()`

### 計算量
- $O(hw \min(h, w))$

ここで、`h = mat.height()`、`w = mat.width()` とする。
