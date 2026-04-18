---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/set-function/ZetaMobiusTransform.hpp
    title: "Superset/Subset Zeta/M\xF6bius Transform"
  _extendedRequiredBy: []
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
    \ a;\n}\n#line 2 \"math/set-function/BitwiseANDConvolution.hpp\"\n\ntemplate <class\
    \ T>\nvector<T> and_convolution(int n, vector<T> a, vector<T> b) {\n  vector<T>\
    \ za = superset_zeta(n, a);\n  vector<T> zb = superset_zeta(n, b);\n  vector<T>\
    \ d(1 << n);\n  for (int i = 0; i < (1 << n); i++) d[i] = za[i] * zb[i];\n  return\
    \ superset_mobius(n, d);\n}\n"
  code: "#include \"ZetaMobiusTransform.hpp\"\n\ntemplate <class T>\nvector<T> and_convolution(int\
    \ n, vector<T> a, vector<T> b) {\n  vector<T> za = superset_zeta(n, a);\n  vector<T>\
    \ zb = superset_zeta(n, b);\n  vector<T> d(1 << n);\n  for (int i = 0; i < (1\
    \ << n); i++) d[i] = za[i] * zb[i];\n  return superset_mobius(n, d);\n}"
  dependsOn:
  - math/set-function/ZetaMobiusTransform.hpp
  isVerificationFile: false
  path: math/set-function/BitwiseANDConvolution.hpp
  requiredBy: []
  timestamp: '2026-04-18 20:38:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/set-function/BitwiseANDConvolution.test.cpp
documentation_of: math/set-function/BitwiseANDConvolution.hpp
layout: document
title: Bitwise AND Convolution
---

## 概要

todo

## 計算量
todo