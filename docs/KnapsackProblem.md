---
title: 01 Knapsack Problem
documentation_of: //dp/KnapsackProblem.hpp
---

## 概要

0/1 ナップサック問題を解く。

## 関数

```cpp
template <class T>
vector<T> knapsack(const vector<int>& w, const vector<T>& v, const int W)
```

重さ `w[i]`、価値 `v[i]` の各品物を高々 1 個ずつ使えるときのナップサック DP を行う。返り値の `j` 番目は、重さの総和がちょうど `j` となる選び方の価値の最大値を表す。到達できない重さには `numeric_limits<T>::min()` が入る。

### 制約
- `w.size() = v.size()`
- $0 \leq W$
- テンプレート引数 `T` は加算と比較ができる

### 計算量
- $O(nW)$
