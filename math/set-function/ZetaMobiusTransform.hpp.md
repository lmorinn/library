---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/set-function/BitwiseANDConvolution.hpp
    title: Bitwise AND Convolution
  - icon: ':warning:'
    path: math/set-function/BitwiseORConvolution.hpp
    title: Bitwise OR Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/set-function/BitwiseANDConvolution.test.cpp
    title: verify/LibraryChecker/math/set-function/BitwiseANDConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ a;\n}\n"
  code: "\ntemplate <class T>\nvector<T> subset_zeta(int n, vector<T> a) {\n  for\
    \ (int i = 0; i < n; i++) {\n    for (int t = 0; t < (1 << n); t++) {\n      if\
    \ (t & (1 << i)) a[t] += a[t ^ (1 << i)];\n    }\n  }\n  return a;\n}\n\ntemplate\
    \ <class T>\nvector<T> subset_mobius(int n, vector<T> a) {\n  for (int i = 0;\
    \ i < n; i++) {\n    for (int t = 0; t < (1 << n); t++) {\n      if (t & (1 <<\
    \ i)) a[t] -= a[t ^ (1 << i)];\n    }\n  }\n  return a;\n}\n\ntemplate <class\
    \ T>\nvector<T> superset_zeta(int n, vector<T> a) {\n  for (int i = 0; i < n;\
    \ i++) {\n    for (int t = 0; t < (1 << n); t++) {\n      if (!(t & (1 << i)))\
    \ a[t] += a[t | (1 << i)];\n    }\n  }\n  return a;\n}\n\ntemplate <class T>\n\
    vector<T> superset_mobius(int n, vector<T> a) {\n  for (int i = 0; i < n; i++)\
    \ {\n    for (int t = 0; t < (1 << n); t++) {\n      if (!(t & (1 << i))) a[t]\
    \ -= a[t | (1 << i)];\n    }\n  }\n  return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/set-function/ZetaMobiusTransform.hpp
  requiredBy:
  - math/set-function/BitwiseANDConvolution.hpp
  - math/set-function/BitwiseORConvolution.hpp
  timestamp: '2026-04-18 20:38:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/set-function/BitwiseANDConvolution.test.cpp
documentation_of: math/set-function/ZetaMobiusTransform.hpp
layout: document
title: "Superset/Subset Zeta/M\xF6bius Transform"
---

## 概要

todo

## 計算量
todo