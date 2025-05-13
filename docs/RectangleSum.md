---
title: Rectangle Sum
documentation_of: //data-structure/wavelet-matrix/rectangle/RectangleSum.hpp
---

## 概要

[Wavelet Matrix (Template Sum)](../WaveletMatrixTemplateSum.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点に対して矩形総和取得が可能。

## コンストラクタ

```cpp
WaveletMatrix<T, S> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 個目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。
- xとyとwの数列のサイズはいずれも等しい


### 計算量
- $O(n\log{n})$

## rectangle_sum

```cpp
S wm.rectangle_sum(T lx, T rx, T ly, T ry)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重みの総和を返す。

### 制約

- `std::numeric_limits<T>::min()` $\leq lx \leq rx \leq$ `std::numeric_limits<T>::max()`
- `std::numeric_limits<T>::min()` $\leq ly \leq ry \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log{n})$