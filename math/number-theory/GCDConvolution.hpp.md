---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/MultipleDivisorZetaMobiusTransform.hpp
    title: "Multiple/Divisor Zeta/M\xF6bius Transform"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/GCDConvolution.test.cpp
    title: verify/LibraryChecker/math/number-theory/GCDConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/MultipleDivisorZetaMobiusTransform.hpp\"\
    \ntemplate <class T>\nvector<T> divisor_zeta(vector<T> a) {\n  int n = int(a.size())\
    \ - 1;\n  vector<bool> prime(n + 1, true);\n  for (int p = 2; p <= n; p++) {\n\
    \    if (prime[p]) {\n      for (long long k = 1; k * p <= n; k++) {\n       \
    \ prime[k * p] = false;\n        a[k * p] += a[k];\n      }\n    }\n  }\n  return\
    \ a;\n}\n\ntemplate <class T>\nvector<T> divisor_mobius(vector<T> a) {\n  int\
    \ n = int(a.size()) - 1;\n  vector<bool> prime(n + 1, true);\n  for (int p = 2;\
    \ p <= n; p++) {\n    if (prime[p]) {\n      for (long long k = n / p; k > 0;\
    \ k--) {\n        prime[k * p] = false;\n        a[k * p] -= a[k];\n      }\n\
    \    }\n  }\n  return a;\n}\n\ntemplate <class T>\nvector<T> multiple_zeta(vector<T>\
    \ a) {\n  int n = int(a.size()) - 1;\n  vector<bool> prime(n + 1, true);\n  for\
    \ (int p = 2; p <= n; p++) {\n    if (prime[p]) {\n      for (long long k = n\
    \ / p; k > 0; k--) {\n        prime[k * p] = false;\n        a[k] += a[k * p];\n\
    \      }\n    }\n  }\n  return a;\n}\n\ntemplate <class T>\nvector<T> multiple_mobius(vector<T>\
    \ a) {\n  int n = int(a.size()) - 1;\n  vector<bool> prime(n + 1, true);\n  for\
    \ (int p = 2; p <= n; p++) {\n    if (prime[p]) {\n      for (long long k = 1;\
    \ k * p <= n; k++) {\n        prime[k * p] = false;\n        a[k] -= a[k * p];\n\
    \      }\n    }\n  }\n  return a;\n}\n#line 2 \"math/number-theory/GCDConvolution.hpp\"\
    \n\ntemplate <class T>\nvector<T> gcd_convolution(vector<T> a, vector<T> b) {\n\
    \  vector<T> za = multiple_zeta(a);\n  vector<T> zb = multiple_zeta(b);\n  vector<T>\
    \ d(a.size());\n  for (int i = 0; i < a.size(); i++) d[i] = za[i] * zb[i];\n \
    \ return multiple_mobius(d);\n}\n"
  code: "#include \"MultipleDivisorZetaMobiusTransform.hpp\"\n\ntemplate <class T>\n\
    vector<T> gcd_convolution(vector<T> a, vector<T> b) {\n  vector<T> za = multiple_zeta(a);\n\
    \  vector<T> zb = multiple_zeta(b);\n  vector<T> d(a.size());\n  for (int i =\
    \ 0; i < a.size(); i++) d[i] = za[i] * zb[i];\n  return multiple_mobius(d);\n\
    }\n"
  dependsOn:
  - math/number-theory/MultipleDivisorZetaMobiusTransform.hpp
  isVerificationFile: false
  path: math/number-theory/GCDConvolution.hpp
  requiredBy: []
  timestamp: '2026-04-18 20:38:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/number-theory/GCDConvolution.test.cpp
documentation_of: math/number-theory/GCDConvolution.hpp
layout: document
title: GCD Convolution
---

## 概要

todo

## 計算量
todo