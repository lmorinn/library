---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/dp/StaticRangeSum.test.cpp
    title: verify/LibraryChecker/dp/StaticRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/CumulativeSum.hpp\"\ntemplate <class T>\nclass CumulativeSum\
    \ {\n private:\n  int siz;\n  vector<T> s;\n\n public:\n  CumulativeSum() {}\n\
    \  CumulativeSum(vector<T> &a) {\n    siz = a.size();\n    s.resize(siz + 1, 0);\n\
    \    for (int i = 0; i < siz; i++) {\n      s[i + 1] = s[i] + a[i];\n    }\n \
    \ }\n\n  T sum(int r) {\n    return s[r];\n  }\n\n  T sum(int l, int r) {\n  \
    \  return s[r] - s[l];\n  }\n};\n"
  code: "#pragma once\ntemplate <class T>\nclass CumulativeSum {\n private:\n  int\
    \ siz;\n  vector<T> s;\n\n public:\n  CumulativeSum() {}\n  CumulativeSum(vector<T>\
    \ &a) {\n    siz = a.size();\n    s.resize(siz + 1, 0);\n    for (int i = 0; i\
    \ < siz; i++) {\n      s[i + 1] = s[i] + a[i];\n    }\n  }\n\n  T sum(int r) {\n\
    \    return s[r];\n  }\n\n  T sum(int l, int r) {\n    return s[r] - s[l];\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/CumulativeSum.hpp
  requiredBy: []
  timestamp: '2024-06-26 20:58:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/dp/StaticRangeSum.test.cpp
documentation_of: dp/CumulativeSum.hpp
layout: document
title: Cumulative Sum
---

## 概要

1次元の累積和を構築する。長さ $N$ の数列に対して、前計算 $O(N)$ の上で区間の和を $O(1)$ で求めることができる。

## コンストラクタ

```cpp
CumulativeSum<T>(vector<T> a)
```

長さ `n = a.size()` の数列に対して累積和を構築する。

### 制約
- テンプレート引数 `T` : データの型。群の代数構造を満たす必要がある。


### 計算量

- $O(n)$

## sum

```cpp
(1) T cum.sum(int l)
(2) T cum.sum(int l, int r)
```

- (1) 区間 $[0, l)$ の和を返す。
- (2) 区間 $[l, r)$ の和を返す。

### 制約

- $0 \leq l \leq r \leq n$



### 計算量
- $O(1)$