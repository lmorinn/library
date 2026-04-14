---
title: Low Link
documentation_of: //graph/others/LowLink.hpp
---

## 概要

無向グラフの関節点と橋を求める。

## コンストラクタ

```cpp
LowLink(int n)
```

`n` 頂点の空グラフに対する low-link を構築する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$

## add_edge

```cpp
void ll.add_edge(int u, int v, int eid)
```

無向辺 `(u, v)` を追加する。`eid` は辺番号として保持され、橋の列挙結果に用いられる。

### 制約
- $0 \leq u, v < n$

### 計算量
- $O(1)$

## build

```cpp
void ll.build()
```

low-link を構築する。構築後、`articulation` に関節点の頂点番号が、`bridge` に橋の辺番号が格納される。

### 計算量
- $O(n + m)$
