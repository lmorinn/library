---
title: Longest Increasing Subsequence
documentation_of: //dp/LongestIncreasingSubsequence.hpp
---

## 概要

数列の最長狭義増加部分列の長さを求める。

## 関数

```cpp
template <typename T>
int lis(vector<T> a)
```

数列 `a` の最長狭義増加部分列の長さを返す。

### 制約
- テンプレート引数 `T` は大小比較できる

### 計算量
- $O(n \log n)$
