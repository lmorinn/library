---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/TrinarySearch.hpp\"\ntemplate <class S, class T, class\
    \ F>\nS find_min_convex_function(T l, T r, F f) {\n  while (abs(l - r) > 2) {\n\
    \    T m1 = (2 * l + r) / T(3);\n    T m2 = (l + 2 * r) / T(3);\n    S s1 = f(m1);\n\
    \    S s2 = f(m2);\n    if (s1 < s2) {\n      r = m2;\n    } else {\n      l =\
    \ m1;\n    }\n  }\n  S res = f(l);\n  for (T i = l + 1; i < r + 2; i++) {\n  \
    \  S v = f(i);\n    if (res > v) res = v;\n  }\n  return res;\n}\n"
  code: "template <class S, class T, class F>\nS find_min_convex_function(T l, T r,\
    \ F f) {\n  while (abs(l - r) > 2) {\n    T m1 = (2 * l + r) / T(3);\n    T m2\
    \ = (l + 2 * r) / T(3);\n    S s1 = f(m1);\n    S s2 = f(m2);\n    if (s1 < s2)\
    \ {\n      r = m2;\n    } else {\n      l = m1;\n    }\n  }\n  S res = f(l);\n\
    \  for (T i = l + 1; i < r + 2; i++) {\n    S v = f(i);\n    if (res > v) res\
    \ = v;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/TrinarySearch.hpp
  requiredBy: []
  timestamp: '2026-07-09 14:41:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/TrinarySearch.hpp
layout: document
title: Trinary Search
---

## 概要

todo
