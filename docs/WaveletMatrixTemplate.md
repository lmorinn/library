---
title: Wavelet Matrix (Template)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
---

## 概要

長さ $N$ の静的な数列に対して、構築 $O(N\log{N})$ の上でさまざまなクエリを $O(\log{N})$ で処理するデータ構造。

## コンストラクタ

```cpp
WaveletMatrix<T> wm(vector<T> v)
```

長さ `n = v.size()` の数列 `v` に対してWavelet Matrixを構築する。

### 制約

- テンプレート引数 T: データの型。

### 計算量
- $O(n\log{n})$

## access

```cpp
T wm.access(int p)
```

`v[p]` を返す。

### 制約
- $0 \leq p \lt n$

### 計算量
- $O(\log{n})$

## kth_smallest

```cpp
T wm.kth_smallest(unsigned l, unsigned r, unsigned k)
```
`v[l,r)` (0-origin)の中で`k`番目(1-origin)に小さい値を返す。

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
T wm.kth_largest(unsigned l, unsigned r, unsigned k);
```
`v[l,r)` (0-origin)の中で`k`番目(1-origin)に大きい値を返す。

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


## range_freq

```cpp
unsigned wm.range_freq(int l, int r, T mink, T maxk);
```

`v[l, r)` の中で要素の値が `[mink, maxk)`に入る値の個数を返す。

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


## prev_value

```cpp
T wm.prev_value(unsigned l, unsigned r, T val);
```
`v[l,r)` の中で`val`未満の要素のうち最大のものを返す。
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
`v[l,r)` の中で`val`より大きい要素のうち最小のもの
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
