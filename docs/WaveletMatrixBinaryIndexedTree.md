---
title: Wavelet Matrix (BIT)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp
---

## 概要

Wavelet MatrixとBITを同時に持つことで、数列に対して高度な1点加算・区間和のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<T, S> wm(vector<T> v)
(2) WaveletMatrix<T, S> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルとBITを構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` からBITを構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。群の代数構造の性質を満たす必要がある。
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい

### 計算量
- $O(n\log^2{n})$



## range_sum

```cpp
S wm.range_sum(int l, int r, T mink, T maxk)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たす $i$ に対して、BITの和を計算して返す。条件を満たすインデックスがひとつも存在しないときは `0` を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
S wm.range_sum(1, 5, 2, 5) // 返り値は4
S wm.range_sum(0, 4, 1, 4) // 返り値は5
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たす $i$ に対して、BITの和を計算して返す。条件を満たすインデックスがひとつも存在しないときは `0` を返す。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` ならば、 

```cpp
S wm.range_prod(1, 5, 2, 6) // 返り値は3
S wm.range_prod(2, 6, 1, 5) // 返り値は9
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

(1) (2)  BITの `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(\log{n})$


## set

```cpp
S wm.set(int p, S x)
```

(1) (2)  BITの `p` 番目に `x` を代入する。`v[p]` の値は変更しない。


### 制約
- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$

## add

```cpp
S wm.add(int p, S x)
```

(1) (2)  BITの `p` 番目に `x` を加算する。`v[p]` の値は変更しない。


### 制約
- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$