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
  bundledCode: "#line 1 \"linear-algebra/XorBasis.hpp\"\ntemplate <class T>\nvector<T>\
    \ xor_basis(vector<T> a) {\n  vector<T> basis;\n  for (T e : a) {\n    for (T\
    \ b : basis) {\n      chmin(e, e ^ b);\n    }\n    if (e) basis.emplace_back(e);\n\
    \  }\n  return basis;\n}\n"
  code: "template <class T>\nvector<T> xor_basis(vector<T> a) {\n  vector<T> basis;\n\
    \  for (T e : a) {\n    for (T b : basis) {\n      chmin(e, e ^ b);\n    }\n \
    \   if (e) basis.emplace_back(e);\n  }\n  return basis;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linear-algebra/XorBasis.hpp
  requiredBy: []
  timestamp: '2026-07-03 11:19:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linear-algebra/XorBasis.hpp
layout: document
title: Xor Basis
---

## 概要

todo
