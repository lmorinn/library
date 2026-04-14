---
title: Euler's Phi Function Table
documentation_of: //math/number-theory/EulersPhiFunctionTable.hpp
---

## 概要

オイラーの $\varphi$ 関数のテーブルを構築する。

## 関数

```cpp
vector<int> Eulers_phi_function_table(int n)
```

長さ `n + 1` の配列を返す。返り値の `i` 番目は $\varphi(i)$ を表す。`0` 番目は `0` である。

### 制約
- $0 \leq n$

### 計算量
- $O(n \log \log n)$
