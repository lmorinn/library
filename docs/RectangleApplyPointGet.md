---
title: 矩形作用・一点取得
documentation_of: //data-structure/wavelet-matrix/rectangle/RectangleApplyPointGet.hpp
---

## 概要

[ウェーブレット行列 (+ 双対セグメント木)](../WaveletMatrixDualSegtree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形作用 / 一点取得が可能。 

## コンストラクタ

```cpp
WaveletMatrix<S, F, mapping, composition, id, T> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 番目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。
- テンプレート引数 F: 写像の型。
- mapping: $f(x)$ を返す関数。 `S mapping(F f, S x)`
- composition: $f \circ g$ を返す関数。 `F composition(F f, F g)`
- id: $id$ を返す関数。 `F id()`
- 作用は可換である必要がある。
- x, y, wの数列のサイズは等しい


ドキュメントの計算量は、オラクルであるmapping, composition, idが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。


### 計算量
- $O(n\log{n})$

## rectangle_apply

```cpp
void wm.rectangle_apply(T lx, T rx, T ly, T ry, F x)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重み `w[i]` について、 `w[i] = f(w[i])` と更新する。

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