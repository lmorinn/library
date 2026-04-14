---
title: Warshall Floyd
documentation_of: //graph/shortest-path/WarshallFloyd.hpp
---

## 概要

グラフの全点対最短距離を求める。

## 関数

```cpp
(1) template <class T>
    vector<vector<T>> warshallFloyd(vector<vector<pair<int, int>>>& g)

(2) template <class T>
    vector<vector<T>> warshallFloyd(vector<vector<int>> g)
```

- (1) 隣接リスト形式の有向グラフ `g` を受け取り、全点対最短距離を返す。`g[u]` は頂点 `u` からの辺 `(to, cost)` の列とする。
- (2) 隣接行列 `g` を受け取り、全点対最短距離を返す。`g[i][j] < 0` のとき、頂点 `i` から頂点 `j` への辺が存在しないものとして扱う。

返り値の `i` 行 `j` 列は頂点 `i` から頂点 `j` への最短距離を表す。到達できないときは `numeric_limits<T>::max()` となる。

### 制約
- テンプレート引数 `T` は加算と比較ができる

### 計算量
- $O(n^3)$
