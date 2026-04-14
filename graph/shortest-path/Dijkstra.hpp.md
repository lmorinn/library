---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
    title: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest-path/Dijkstra.hpp\"\ntemplate <class T>\n\
    class Dijkstra {\n   private:\n    vector<vector<pair<int, T>>> g;\n    vector<T>\
    \ dist;\n    vector<int> prev;\n    int n;\n\n   public:\n    Dijkstra(vector<vector<pair<int,\
    \ T>>> _g, int start = 0) {\n        g = _g;\n        n = g.size();\n        dist.assign(n,\
    \ -1);\n        prev.assign(n, -1);\n        vector<bool> fin(n, false);\n   \
    \     priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T,\
    \ int, int>>> q;\n        dist[start] = 0;\n        q.emplace(0, start, -1);\n\
    \        while (!q.empty()) {\n            int cur = get<1>(q.top());\n      \
    \      int pre = get<2>(q.top());\n            q.pop();\n            if (fin[cur])\
    \ continue;\n            fin[cur] = true;\n            prev[cur] = pre;\n    \
    \        for (auto p : g[cur]) {\n                int nex = p.first;\n       \
    \         int weight = p.second;\n                if (dist[nex] == -1 or dist[nex]\
    \ > dist[cur] + weight) {\n                    dist[nex] = dist[cur] + weight;\n\
    \                    q.emplace(dist[nex], nex, cur);\n                }\n    \
    \        }\n        }\n    }\n\n    void rebuild(int start) {\n        dist.assign(n,\
    \ -1);\n        prev.assign(n, -1);\n        vector<bool> fin(n, false);\n   \
    \     priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T,\
    \ int, int>>> q;\n        dist[start] = 0;\n        q.emplace(0, start, -1);\n\
    \        while (!q.empty()) {\n            int cur = get<1>(q.top());\n      \
    \      int pre = get<2>(q.top());\n            q.pop();\n            if (fin[cur])\
    \ continue;\n            fin[cur] = true;\n            prev[cur] = pre;\n    \
    \        for (auto p : g[cur]) {\n                int nex = p.first;\n       \
    \         int weight = p.second;\n                if (dist[nex] == -1 or dist[nex]\
    \ > dist[cur] + weight) {\n                    dist[nex] = dist[cur] + weight;\n\
    \                    q.emplace(dist[nex], nex, cur);\n                }\n    \
    \        }\n        }\n    }\n\n    vector<T> get_dist() {\n        return dist;\n\
    \    }\n\n    T get_dist(int t) {\n        return dist[t];\n    }\n\n    vector<int>\
    \ get_route(int t) {\n        vector<int> ret;\n        if (dist[t] == -1) return\
    \ ret;\n\n        int cur = t;\n        while (cur != -1) {\n            ret.emplace_back(cur);\n\
    \            cur = prev[cur];\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n};\n"
  code: "template <class T>\nclass Dijkstra {\n   private:\n    vector<vector<pair<int,\
    \ T>>> g;\n    vector<T> dist;\n    vector<int> prev;\n    int n;\n\n   public:\n\
    \    Dijkstra(vector<vector<pair<int, T>>> _g, int start = 0) {\n        g = _g;\n\
    \        n = g.size();\n        dist.assign(n, -1);\n        prev.assign(n, -1);\n\
    \        vector<bool> fin(n, false);\n        priority_queue<tuple<T, int, int>,\
    \ vector<tuple<T, int, int>>, greater<tuple<T, int, int>>> q;\n        dist[start]\
    \ = 0;\n        q.emplace(0, start, -1);\n        while (!q.empty()) {\n     \
    \       int cur = get<1>(q.top());\n            int pre = get<2>(q.top());\n \
    \           q.pop();\n            if (fin[cur]) continue;\n            fin[cur]\
    \ = true;\n            prev[cur] = pre;\n            for (auto p : g[cur]) {\n\
    \                int nex = p.first;\n                int weight = p.second;\n\
    \                if (dist[nex] == -1 or dist[nex] > dist[cur] + weight) {\n  \
    \                  dist[nex] = dist[cur] + weight;\n                    q.emplace(dist[nex],\
    \ nex, cur);\n                }\n            }\n        }\n    }\n\n    void rebuild(int\
    \ start) {\n        dist.assign(n, -1);\n        prev.assign(n, -1);\n       \
    \ vector<bool> fin(n, false);\n        priority_queue<tuple<T, int, int>, vector<tuple<T,\
    \ int, int>>, greater<tuple<T, int, int>>> q;\n        dist[start] = 0;\n    \
    \    q.emplace(0, start, -1);\n        while (!q.empty()) {\n            int cur\
    \ = get<1>(q.top());\n            int pre = get<2>(q.top());\n            q.pop();\n\
    \            if (fin[cur]) continue;\n            fin[cur] = true;\n         \
    \   prev[cur] = pre;\n            for (auto p : g[cur]) {\n                int\
    \ nex = p.first;\n                int weight = p.second;\n                if (dist[nex]\
    \ == -1 or dist[nex] > dist[cur] + weight) {\n                    dist[nex] =\
    \ dist[cur] + weight;\n                    q.emplace(dist[nex], nex, cur);\n \
    \               }\n            }\n        }\n    }\n\n    vector<T> get_dist()\
    \ {\n        return dist;\n    }\n\n    T get_dist(int t) {\n        return dist[t];\n\
    \    }\n\n    vector<int> get_route(int t) {\n        vector<int> ret;\n     \
    \   if (dist[t] == -1) return ret;\n\n        int cur = t;\n        while (cur\
    \ != -1) {\n            ret.emplace_back(cur);\n            cur = prev[cur];\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest-path/Dijkstra.hpp
  requiredBy: []
  timestamp: '2024-11-29 03:35:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
documentation_of: graph/shortest-path/Dijkstra.hpp
layout: document
title: Dijkstra
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
