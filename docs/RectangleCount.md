---
title: 矩形カウント
documentation_of: //data-structure/wavelet-matrix/rectangle/RectangleCount.hpp
---

## 概要

[ウェーブレット行列](../WaveletMatrixTemplate.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点に対して矩形カウントが可能。


## コンストラクタ

```cpp
WaveletMatrix<T> wm(vector<T> x, vector<T> y)
```
$i$ 個目の点を $(x_i, y_i)$として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- xとyの数列のサイズは等しい


### 計算量
- $O(n\log{n})$

## rectangle_count

```cpp
int wm.rectangle_count(T lx, T rx, T ly, T ry)
```

矩形領域　$lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の個数を返す。

### 制約

- `std::numeric_limits<T>::min()` $\leq lx \leq rx \leq$ `std::numeric_limits<T>::max()`
- `std::numeric_limits<T>::min()` $\leq ly \leq ry \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log{n})$
