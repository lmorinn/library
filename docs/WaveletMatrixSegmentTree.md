---
title: Wavelet Matrix (Segment Tree)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
---

## 概要

Wavelet Matrixとセグメント木を同時に持つことで、数列に対して高度な1点更新・区間演算のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<T, S> wm(vector<T> v)
(2) WaveletMatrix<T, S> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルとセグメント木を構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` からセグメント木を構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。モノイドの代数構造の性質を満たす必要がある。
- op: 二項演算 `S op(S a, S b)`
- e: 単位元 `S e()`
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい

ドキュメントの計算量は、オラクルであるop, eが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。

### 計算量
- $O(n\log{n})$



## range_prod

```cpp
S wm.range_prod(int l, int r, T mink, T maxk)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たす $i$ に対して、セグメント木の総積を計算して返す。条件を満たすインデックスがひとつも存在しないときは `e()` を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`であり、Range Max Queryならば、 

```cpp
S wm.range_prod(1, 5, 2, 5) // 返り値は4
S wm.range_prod(0, 4, 1, 4) // 返り値は3
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たす $i$ に対して、セグメント木の総積を計算して返す。条件を満たすインデックスがひとつも存在しないときは `e()` を返す。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` であり、Range Max Query ならば、 

```cpp
S wm.range_prod(1, 5, 2, 6) // 返り値は2
S wm.range_prod(2, 6, 1, 5) // 返り値は8
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

(1) (2)  セグメント木の `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(1)$


## set

```cpp
S wm.set(int p, S x)
```

(1) (2)  セグメント木の `p` 番目に `x` を代入する。`v[p]` の値は変更しない。


### 制約
- $0 \leq p \lt n$


### 計算量
- $O(\log^2{n})$




