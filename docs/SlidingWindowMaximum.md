---
title: Sliding Window (Maximum)
documentation_of: //dp/SlidingWindowMaximum.hpp
---

## 概要

長さ `k` の各連続部分列の最大値を求める。

## 関数

```cpp
template <class T>
vector<T> sliding_window_maximum(const vector<T>& a, int k)
```

数列 `a` の各長さ `k` の連続部分列に対する最大値を返す。返り値の `i` 番目は区間 `[i, i + k)` の最大値を表す。`a.size() < k` のときは空配列を返す。

### 制約
- テンプレート引数 `T` は大小比較できる
- $1 \leq k$

### 計算量
- $O(n)$
