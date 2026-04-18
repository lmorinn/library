---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/set-function/ZetaMobiusTransform.hpp
    title: "Superset/Subset Zeta/M\xF6bius Transform"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/set-function/ZetaMobiusTransform.hpp\"\n\ntemplate\
    \ <class T>\nvector<T> subset_zeta(int n, vector<T> a) {\n  for (int i = 0; i\
    \ < n; i++) {\n    for (int t = 0; t < (1 << n); t++) {\n      if (t & (1 << i))\
    \ a[t] += a[t ^ (1 << i)];\n    }\n  }\n  return a;\n}\n\ntemplate <class T>\n\
    vector<T> subset_mobius(int n, vector<T> a) {\n  for (int i = 0; i < n; i++) {\n\
    \    for (int t = 0; t < (1 << n); t++) {\n      if (t & (1 << i)) a[t] -= a[t\
    \ ^ (1 << i)];\n    }\n  }\n  return a;\n}\n\ntemplate <class T>\nvector<T> superset_zeta(int\
    \ n, vector<T> a) {\n  for (int i = 0; i < n; i++) {\n    for (int t = 0; t <\
    \ (1 << n); t++) {\n      if (!(t & (1 << i))) a[t] += a[t | (1 << i)];\n    }\n\
    \  }\n  return a;\n}\n\ntemplate <class T>\nvector<T> superset_mobius(int n, vector<T>\
    \ a) {\n  for (int i = 0; i < n; i++) {\n    for (int t = 0; t < (1 << n); t++)\
    \ {\n      if (!(t & (1 << i))) a[t] -= a[t | (1 << i)];\n    }\n  }\n  return\
    \ a;\n}\n#line 2 \"math/set-function/BitwiseORConvolution.hpp\"\n\ntemplate <class\
    \ T>\nvector<T> or_convolution(int n, vector<T> a, vector<T> b) {\n  vector<T>\
    \ za = subset_zeta(n, a);\n  vector<T> zb = subset_zeta(n, b);\n  vector<T> d(1\
    \ << n);\n  for (int i = 0; i < (1 << n); i++) d[i] = za[i] * zb[i];\n  return\
    \ subset_mobius(n, d);\n}\n"
  code: "#include \"ZetaMobiusTransform.hpp\"\n\ntemplate <class T>\nvector<T> or_convolution(int\
    \ n, vector<T> a, vector<T> b) {\n  vector<T> za = subset_zeta(n, a);\n  vector<T>\
    \ zb = subset_zeta(n, b);\n  vector<T> d(1 << n);\n  for (int i = 0; i < (1 <<\
    \ n); i++) d[i] = za[i] * zb[i];\n  return subset_mobius(n, d);\n}"
  dependsOn:
  - math/set-function/ZetaMobiusTransform.hpp
  isVerificationFile: false
  path: math/set-function/BitwiseORConvolution.hpp
  requiredBy: []
  timestamp: '2026-04-18 20:38:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/set-function/BitwiseORConvolution.hpp
layout: document
title: Bitwise OR Convolution
---

## 概要

todo

## 計算量
todo