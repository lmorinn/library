---
title: Wavelet Matrix (Dual BIT)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixDualBinaryIndexedTree.hpp
---

## 概要

Wavelet Matrixと双対BITを同時に持つことで、数列に対して高度な加算・一点取得のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<S, T> wm(vector<T> v)
(2) WaveletMatrix<S, T> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルと双対BITを構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` から双対BITを構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい

### 計算量
- $O(n\log{n})$



## range_add

```cpp
void wm.range_add(int l, int r, T mink, T maxk, S x)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対BITで表される数列の $i$ 番目のインデックスの要素に `x` を加算する。 `v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` ならば、 


```cpp
// 初期状態: {3, 1, 4, 1, 5, 9}

void wm.range_add(1, 5, 2, 5, 10) // {3, 1, 14, 1, 5, 9}
void wm.range_add(0, 4, 1, 4, 10) // {13, 11, 14, 11, 5, 9}
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対BITで表される数列の $i$ 番目のインデックスの要素に `x` を加算する。`v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` ならば、 

```cpp
// 初期状態: {2, 7, 1, 8, 2, 8}
void wm.range_add(1, 5, 2, 6, 10) // {2, 7, 11, 8, 12, 8}
void wm.range_add(2, 6, 1, 5, 10) // {2, 7, 21, 18, 12, 8}
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- `std::numeric_limits<T>::min()` $\leq mink \leq maxk \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log^2{n})$


## get

```cpp
S wm.get(int p)
```

(1) (2)  双対BITで表される数列の `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(\log^2{n})$




