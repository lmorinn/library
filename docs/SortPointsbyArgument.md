---
title: Sort Points by Argument
documentation_of: //geometry/SortPointsbyArgument.hpp
---

## 概要

原点から見た偏角で点を並べるための比較関数と補助型を扱う。

## 構造体

```cpp
struct Point
```

2 次元平面上の点を表す。`x`, `y` はともに `long long` 型である。

## 関数

```cpp
__int128_t cross(const Point& a, const Point& b)
```

ベクトル `a` と `b` の外積を返す。

```cpp
template <auto f = less()>
bool cmp(const Point& a, const Point& b)
```

`Point` `a`, `b` を原点から見た偏角の昇順に比較する。
`f(a.y, 0)` と `f(b.y, 0)` を用いて上半平面と下半平面を分け、同じ半平面内では外積で順序を定める。
原点に対して同一直線上にある場合は、`abs(x) + abs(y)` が小さい方を先にする。

### 制約
- `Point` の `x`, `y` は `long long` の範囲に収まる
- `abs(x) + abs(y)` は `long long` の範囲に収まる
