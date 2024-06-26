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

todo

## 計算量
todo