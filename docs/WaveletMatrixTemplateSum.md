---
title: Wavelet Matrix (Template Sum)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixTemplateSum.hpp
---

## 概要

長さ $N$ の静的な数列に対して、構築 $O(N\log{N})$ の上でさまざまなクエリを $O(\log{N})$ で処理するデータ構造。

累積和を同時に持つことで、和のクエリを処理することができる。


## コンストラクタ

```cpp
(1) WaveletMatrix<T, S> wm(vector<T> v)
(2) WaveletMatrix<T, S> wm(vector<T> v, vector<S> w)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。
- (1) 数列 `v` からビットベクトルと累積和を構築する。
- (2) 数列 `v` からビットベクトル、数列 `w` から累積和を構築する。


(2) で構築した場合、使用できる関数に限りがある。

- `kth_smallest`
- `kth_largest`
- `range_freq`
- `range_sum`
- `prev_value`
- `next_value`

上記で挙げた関数以外を呼んだときの返り値は未定義である。


### 制約

- テンプレート引数 T: データの型。
- テンプレート引数 S: データの型。
- (2) のとき、vとwの数列のサイズは等しい

### 計算量
- $O(n\log{n})$


## kth_smallest

```cpp
T wm.kth_smallest(unsigned l, unsigned r, unsigned k)
```
(1) (2) `v[l,r)` (0-origin)の中で`k`番目(1-origin)に小さい値を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.kth_smallest(1, 4, 2) // 返り値は1
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- $1 \leq k \leq r - l$

### 計算量
- $O(\log{n})$

## kth_largest

```cpp
T wm.kth_largest(unsigned l, unsigned r, unsigned k)
```
(1) (2) `v[l,r)` (0-origin)の中で`k`番目(1-origin)に大きい値を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.kth_largest(1, 5, 2) // 返り値は4
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- $1 \leq k \leq r - l$


### 計算量
- $O(\log{n})$



## kth_ascending_sum

```cpp
T wm.kth_ascending_sum(unsigned l, unsigned r, unsigned k)
```
(1) `v[l,r)` (0-origin) を昇順ソートしたときの先頭`k`個(1-origin)の総和を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.kth_ascending_sum(1, 5, 3) // 返り値は6
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- $1 \leq k \leq r - l$

### 計算量
- $O(\log{n})$


## kth_descending_sum

```cpp
T wm.kth_descending_sum(unsigned l, unsigned r, unsigned k)
```
(1) `v[l,r)` (0-origin) を降順ソートしたときの先頭`k`個(1-origin)の総和を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.kth_descending_sum(1, 5, 3) // 返り値は10
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- $1 \leq k \leq r - l$

### 計算量
- $O(\log{n})$



## range_freq

```cpp
unsigned wm.range_freq(int l, int r, T mink, T maxk)
```

(1) (2) `v[l, r)` の中で要素の値が `[mink, maxk)`に入る値の個数を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.range_freq(1, 5, 1, 2) // 返り値は2
T wm.range_freq(0, 4, 1, 4) // 返り値は3
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- `std::numeric_limits<T>::min()` $\leq mink \leq maxk \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log{n})$



## range_sum

```cpp
T wm.range_sum(int l, int r, T mink, T maxk)
```

(1)  $l\leq i \lt r$ かつ $mink \leq v_i \le maxk$ を満たす $i$ に対して、 $v_i$ の総和を返す

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.range_sum(1, 5, 1, 2) // 返り値は2
T wm.range_sum(0, 4, 1, 4) // 返り値は5
```

のようになる。

(2)  $l\leq i \lt r$ かつ $mink \leq v_i \le maxk$ を満たす $i$ に対して、 $w_i$ の総和を返す

例として、`v = {3, 1, 4, 1, 5, 9}` 、 `w = {2, 7, 1, 8, 2, 8}` ならば、 

```cpp
T wm.range_sum(1, 5, 1, 2) // 返り値は15
T wm.range_sum(0, 4, 1, 4) // 返り値は17
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- `std::numeric_limits<T>::min()` $\leq mink \leq maxk \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log{n})$



## range_abs

```cpp
T wm.range_abs(int l, int r, T b);
```

(1)  $\sum_{l \leq i \lt r} |v_i - b|$ を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.range_abs(1, 5, 2)  // 返り値は7
T wm.range_abs(0, 4, 10) // 返り値は31
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$
- `std::numeric_limits<T>::min()` $\leq b \leq$ `std::numeric_limits<T>::max()`


### 計算量
- $O(\log{n})$

## prev_value

```cpp
T wm.prev_value(unsigned l, unsigned r, T val);
```
(1) (2) `v[l,r)` の中で`val`未満の要素のうち最大のものを返す。
条件を満たす値が存在しない場合は`std::numeric_limits<T>::max()`を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.prev_value(1, 5, 4)    // 返り値は1
T wm.prev_value(1, 5, 1)    // 返り値はstd::numeric_limits<T>::max()
T wm.prev_value(1, 5, 100)  // 返り値は5
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$


### 計算量
- $O(\log{n})$


## next_value

```cpp
T wm.next_value(unsigned l, unsigned r, T val);
```
(1) (2) `v[l,r)` の中で`val`より大きい要素のうち最小のもの
を返す。
条件を満たす値が存在しない場合は`std::numeric_limits<T>::min()`を返す。

例として、`v = {3, 1, 4, 1, 5, 9}`ならば、 

```cpp
T wm.next_value(1, 5, 4)    // 返り値は5
T wm.next_value(1, 5, 1)    // 返り値は4
T wm.next_value(1, 5, 100)  // 返り値はstd::numeric_limits<T>::min()
```

のようになる。

### 制約
- $0 \leq l \lt r \leq n$


### 計算量
- $O(\log{n})$
