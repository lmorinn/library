---
title: Dijkstra
documentation_of: //graph/shortest-path/Dijkstra.hpp
---

## 概要

非負辺重みのグラフに対して、単一始点最短路を求める。

## コンストラクタ

```cpp
Dijkstra<T>(vector<vector<pair<int, T>>> g, int start = 0)
```

グラフ `g` と始点 `start` を受け取り、`start` から各頂点への最短距離と最短路を構築する。`g[u]` は頂点 `u` からの辺 `(to, cost)` の列とする。

### 制約
- テンプレート引数 `T` : 辺重みを表す数値型
- すべての辺重みは非負
- $0 \leq \mathrm{start} < n$

### 計算量
- $O((n + m)\log n)$

## rebuild

```cpp
void d.rebuild(int start)
```

始点を `start` に変更して、最短距離と最短路を再構築する。

### 制約
- すべての辺重みは非負
- $0 \leq \mathrm{start} < n$

### 計算量
- $O((n + m)\log n)$

## get_dist

```cpp
(1) vector<T> d.get_dist()
(2) T d.get_dist(int t)
```

- (1) 始点から各頂点への最短距離を返す。
- (2) 始点から頂点 `t` への最短距離を返す。

到達できない頂点の距離は `-1` となる。

### 制約
- (2) $0 \leq t < n$

### 計算量
- (1) $O(n)$
- (2) $O(1)$

## get_route

```cpp
vector<int> d.get_route(int t)
```

始点から頂点 `t` への最短路を頂点列として返す。返り値には始点と `t` を含む。頂点 `t` に到達できないときは空配列を返す。

### 制約
- $0 \leq t < n$

### 計算量
- $O(k)$

ここで、`k` は返される頂点列の長さ。
