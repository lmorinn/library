---
title: Rolling Hash
documentation_of: //string/RollingHash.hpp
---

## 概要

文字列に対して、部分文字列のハッシュ値を扱う。

## コンストラクタ

```cpp
RollingHash(const string& s)
```

文字列 `s` に対する rolling hash を構築する。

### 制約
- `s` は `char` 列として扱える文字列

### 計算量
- $O(n)$

## range_hash

```cpp
int64_t rh.range_hash(int l, int r)
```

部分文字列 `s[l, r)` のハッシュ値を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(1)$
