---
title: ウェーブレット行列 (+ 双対セグメント木)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixDualSegtree.hpp
---

## 概要

Wavelet Matrixと双対セグメント木を同時に持つことで、数列に対して高度な作用・一点取得のクエリを処理できるようにしたデータ構造。


## コンストラクタ

```cpp
(1) WaveletMatrix<S, F, mapping, composition, id, T> wm(vector<T> v)
(2) WaveletMatrix<S, F, mapping, composition, id, T> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルと双対セグメント木を構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` から双対セグメント木を構築する。



### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。
- テンプレート引数 F: 写像の型。
- mapping: $f(x)$ を返す関数 `S mapping(F f, S x)`
- composition: $f \circ g$ を返す関数 `F composition(F f, F g)`
- id: $id$ を返す関数 `F id()`
- 作用は可換である必要がある
- (1) のとき、TとSの型は同一
- (2) のとき、vとwの数列のサイズは等しい


ドキュメントの計算量は、オラクルであるmapping, composition, idが定数時間で動くものと仮定したときのものである。オラクル内部の計算量が 
$O(f(n))$ である場合はすべての計算量が $O(f(n))$ 倍となる。

### 計算量
- $O(n\log{n})$



## range_apply

```cpp
void wm.range_apply(int l, int r, T mink, T maxk, F x)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対セグメント木のi番目のインデックスの要素にxを作用させる。 `v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` であり、 

```cpp
using S = int;
using F = int;
using T = int;

S mapping(F f, S x){
    return f*x;
}

F composition(F f, F g){
    return f*g;
}

F id(){
    return 1;
}
```
と定義されているならば、

```cpp
// 初期状態: {3, 1, 4, 1, 5, 9}

void wm.range_apply(1, 5, 2, 5, 10) // {3, 1, 40, 1, 5, 9}
void wm.range_apply(0, 4, 1, 4, 10) // {30, 10, 40, 10, 5, 9}
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \lt maxk$ を満たすすべての $i$ において、双対セグメント木のi番目のインデックスの要素にxを作用させる。`v[i]` の要素は変更しない。

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` であり、 

```cpp
using S = int;
using F = int;
using T = int;

S mapping(F f, S x){
    return f*x;
}

F composition(F f, F g){
    return f*g;
}

F id(){
    return 1;
}
```
と定義されているならば、

```cpp
// 初期状態: {2, 7, 1, 8, 2, 8}
void wm.range_apply(1, 5, 2, 6, 10) // {2, 7, 10, 8, 20, 8}
void wm.range_apply(2, 6, 1, 5, 10) // {2, 7, 100, 80, 20, 8}
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

(1) (2)  双対セグメント木の `p` 番目の値を返す。 


### 制約
- $0 \leq p \lt n$

### 計算量
- $O(\log^2{n})$




