---
title: 矩形総積・一点代入
documentation_of: //data-structure/wavelet-matrix/rectangle/RectangleProdPointSet.hpp
---

## 概要

[ウェーブレット行列 (+ セグメント木)](../WaveletMatrixSegtree.hpp) を拡張して、2次元平面のクエリに答えられるようにしたデータ構造。

事前に与えられた点の重みに対して矩形総積取得 / 一点更新が可能。


## コンストラクタ

```cpp
WaveletMatrix<S, op, e, T> wm(vector<T> x, vector<T> y, vector<S> w)
```
$i$ 番目の点の座標を $(x_i, y_i)$、重みを $w_i$ として、データ構造を構築する。

### 制約

- テンプレート引数 T: 座標の型。
- テンプレート引数 S: 重みの型。モノイドの代数構造の性質を満たす必要がある。
- op: 二項演算 `S op(S a, S b)`
- e: 単位元 `S e()`
- x, y, wの数列のサイズは等しい

ドキュメントの計算量は、オラクルであるop, eが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。


### 計算量
- $O(n\log{n})$

## rectangle_prod

```cpp
S wm.rectangle_prod(T lx, T rx, T ly, T ry)
```

矩形領域 $lx \leq x \lt rx$ かつ $ly \leq y \lt ry$ 内の点の重みの総積を返す。

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


## get

```cpp
S wm.get(int p)
```

`p` 番目の点の重みを返す。

### 制約

- $0 \leq p \lt n$ 


### 計算量
- $O(1)$