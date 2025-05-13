---
title: 矩形和・一点加算
documentation_of: //data-structure/wavelet-matrix/rectangle/RectangleSumPointAdd.hpp
---

## 概要

[ウェーブレット行列 (+ BIT)](../WaveletMatrixBinaryIndexedTree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形総和取得 / 一点加算が可能。


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

## rectangle_sum

```cpp
S wm.rectangle_sum(T lx, T rx, T ly, T ry)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重みの総和を返す。

### 制約

- `std::numeric_limits<T>::min()` $\leq lx \leq rx \leq$ `std::numeric_limits<T>::max()`
- `std::numeric_limits<T>::min()` $\leq ly \leq ry \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log^2{n})$

## set

```cpp
void wm.set(int p, S x)
```

`p` 番目の点の重みを `x` に変更する。

### 制約

- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$


## add

```cpp
void wm.add(int p, S x)
```

`p` 番目の点の重みに `x` を加算する。

### 制約

- $0 \leq p \lt n$ 


### 計算量
- $O(\log^2{n})$