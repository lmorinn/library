---
title: Strongly Connected Components
documentation_of: //graph/connected-components/StronglyConnectedComponents.hpp
---

## 概要

有向グラフの強連結成分分解を求める。

## コンストラクタ

```cpp
SCC(int siz)
```

`siz` 頂点の空グラフに対する強連結成分分解を構築する。

### 制約
- $0 \leq \mathrm{siz}$

### 計算量
- $O(\mathrm{siz})$

## add_edge

```cpp
void scc.add_edge(int u, int v)
```

有向辺 `u -> v` を追加する。

### 制約
- $0 \leq u, v < n$

### 計算量
- $O(1)$

## decompose

```cpp
vector<vector<int>> scc.decompose()
```

強連結成分分解を行い、各強連結成分に含まれる頂点列を返す。

### 計算量
- $O(n + m)$
