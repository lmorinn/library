---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
    title: verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/SortPointsbyArgument.hpp\"\nstruct Point {\n  long\
    \ long x, y;\n};\n\n__int128_t cross(const Point& a, const Point& b) {\n  return\
    \ (__int128_t)a.x * b.y - (__int128_t)a.y * b.x;\n}\n\ntemplate <auto f = less()>\n\
    bool cmp(const Point& a, const Point& b) {\n  int ah = (f(a.y, 0) or (a.y == 0\
    \ and a.x > 0));\n  int bh = (f(b.y, 0) or (b.y == 0 and b.x > 0));\n  if (ah\
    \ != bh) return ah > bh;\n  __int128_t c = cross(a, b);\n  if (c == 0) {\n   \
    \ return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);\n  } else {\n    return c\
    \ > 0;\n  }\n}\n"
  code: "struct Point {\n  long long x, y;\n};\n\n__int128_t cross(const Point& a,\
    \ const Point& b) {\n  return (__int128_t)a.x * b.y - (__int128_t)a.y * b.x;\n\
    }\n\ntemplate <auto f = less()>\nbool cmp(const Point& a, const Point& b) {\n\
    \  int ah = (f(a.y, 0) or (a.y == 0 and a.x > 0));\n  int bh = (f(b.y, 0) or (b.y\
    \ == 0 and b.x > 0));\n  if (ah != bh) return ah > bh;\n  __int128_t c = cross(a,\
    \ b);\n  if (c == 0) {\n    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);\n\
    \  } else {\n    return c > 0;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/SortPointsbyArgument.hpp
  requiredBy: []
  timestamp: '2026-03-25 13:12:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/geometry/SortPointsbyArgument.test.cpp
documentation_of: geometry/SortPointsbyArgument.hpp
layout: document
title: Sort Points by Argument
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
