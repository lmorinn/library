---
title: Wavelet Matrix (Template)
documentation_of: //data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
---

## 概要

長さ $n$ の静的な数列に対してオンラインでクエリを処理するデータ構造です。
要素の値が負であってもクエリを処理できるようにしています。

## コンストラクタ

```cpp
WaveletMatrix<T> wm(v);
```

型 `T` の数列 `v` からWavelet Matrixを構築します。

### 計算量
- $O(n\log{n})$

## access

```cpp
T wm.access(int p);
```

`v[p]` を復元して返します。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log{n})$

## kth_smallest

```cpp
T wm.kth_smallest(unsigned l, unsigned r, unsigned k);
```
`v[l,r)` (0-origin)の中で`k`番目(1-origin)に小さい値を返します。

### 制約
- $0 \leq l < r \leq n$
- $1 \leq k \leq r - l$

### 計算量
- $O(\log{n})$

## kth_largest

```cpp
T wm.kth_largest(unsigned l, unsigned r, unsigned k);
```
`v[l,r)` (0-origin)の中で`k`番目(1-origin)に大きい値を返します。

### 制約
- $0 \leq l < r \leq n$
- $1 \leq k \leq r - l$


### 計算量
- $O(\log{n})$



## range_freq

```cpp
unsigned wm.range_freq(int vl, int vr, T mink, T maxk);
```

`v[l, r) の中で要素の値が[mink, maxk)`に入る値の個数を返します。

### 制約
- $0 \leq l < r \leq n$
- $mink \leq maxk$


### 計算量
- $O(\log{n})$


## prev_value

```cpp
T wm.prev_value(unsigned l, unsigned r, T val);
```
`v[l,r)` の中で`val`の次に小さい要素を返します。
条件を満たす値が存在しない場合は`std::numeric_limits<T>::max()`を返します。

### 制約
- $0 \leq l < r \leq n$


### 計算量
- $O(\log{n})$


## next_value

```cpp
T wm.next_value(unsigned l, unsigned r, T val);
```
`v[l,r)` の中で`val`の次に大きい要素を返します。
条件を満たす値が存在しない場合は`std::numeric_limits<T>::min()`を返します。

### 制約
- $0 \leq l < r \leq n$


### 計算量
- $O(\log{n})$
