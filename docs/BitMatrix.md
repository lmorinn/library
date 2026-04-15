---
title: Matrix (Mod 2)
documentation_of: //linear-algebra/BitMatrix.hpp
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
