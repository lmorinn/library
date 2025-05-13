---
title: Rectangle Add Point Get
documentation_of: //data-structure/wavelet-matrix/rectangle/RectangleAddPointGet.hpp
---

## 概要

[Wavelet Matrix (Dual Binary Indexed Tree)](../WaveletMatrixDualBinaryIndexedTree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形加算 / 1点取得が可能。 


## コンストラクタ

```cpp
WaveletMatrix<S, T> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 番目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。
- x, y, wの数列のサイズは等しい。


### 計算量
- $O(n\log^2{n})$

## rectangle_add

```cpp
void wm.rectangle_add(T lx, T rx, T ly, T ry, S x)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重みに `x` を加算する。

### 制約

- `std::numeric_limits<T>::min()` $\leq lx \leq rx \leq$ `std::numeric_limits<T>::max()`
- `std::numeric_limits<T>::min()` $\leq ly \leq ry \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log^2{n})$

## get

```cpp
S wm.get(int p)
```

`p` 番目の点の重みを返す。

### 制約

- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$


