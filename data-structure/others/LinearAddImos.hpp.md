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
  bundledCode: "#line 1 \"data-structure/others/LinearAddImos.hpp\"\ntemplate <class\
    \ T>\nclass linearimos {\n private:\n  int n;\n\n public:\n  vector<T> imos;\n\
    \  linearimos(int n) : n(n) {\n    imos.assign(n + 2, 0);\n  }\n\n  void add_line(int\
    \ l, int r, T a, T d) {\n    assert(l <= r and 0 <= l and r <= n);\n    imos[l]\
    \ += a;\n    imos[l + 1] += d - a;\n    imos[r] -= (d * T(r - l) + a);\n    imos[r\
    \ + 1] += d * T(r - l - 1) + a;\n  }\n\n  void build() {\n    int siz = imos.size();\n\
    \    for (int k = 0; k < 2; k++) {\n      for (int i = 0; i < siz - 1; i++) {\n\
    \        imos[i + 1] += imos[i];\n      }\n    }\n  }\n};\n"
  code: "template <class T>\nclass linearimos {\n private:\n  int n;\n\n public:\n\
    \  vector<T> imos;\n  linearimos(int n) : n(n) {\n    imos.assign(n + 2, 0);\n\
    \  }\n\n  void add_line(int l, int r, T a, T d) {\n    assert(l <= r and 0 <=\
    \ l and r <= n);\n    imos[l] += a;\n    imos[l + 1] += d - a;\n    imos[r] -=\
    \ (d * T(r - l) + a);\n    imos[r + 1] += d * T(r - l - 1) + a;\n  }\n\n  void\
    \ build() {\n    int siz = imos.size();\n    for (int k = 0; k < 2; k++) {\n \
    \     for (int i = 0; i < siz - 1; i++) {\n        imos[i + 1] += imos[i];\n \
    \     }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/LinearAddImos.hpp
  requiredBy: []
  timestamp: '2026-05-10 18:04:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/others/LinearAddImos.hpp
layout: document
title: "\u533A\u9593\u7B49\u5DEE\u6570\u5217\u52A0\u7B97 (imos\u6CD5)"
---

## 概要

todo

## 計算量
todo