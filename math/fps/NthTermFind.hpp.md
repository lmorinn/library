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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../linear-algebra/Matrix.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../linear-algebra/Matrix.hpp\"\n#include \"BostanMori.hpp\"\n\n\
    // a.size() == d*2\ntemplate <class S>\nS nth_term_find(const vector<S>& a, long\
    \ long n) {\n  int d = int(a.size()) / 2;\n  Matrix<S> A(d);\n  for (int i = 0;\
    \ i < d; i++) {\n    for (int j = 0; j < d; j++) A[i][j] = a[d - j - 1 + i];\n\
    \  }\n  vector<S> coef = A.linear_equation({a.begin() + d, a.end()})[0];\n  FPS<S>\
    \ l = {a.begin(), a.begin() + d};\n  FPS<S> q(d + 1);\n  q[0] = 1;\n  for (int\
    \ i = 0; i < d; i++) q[i + 1] = -coef[i];\n  l *= q;\n  return bostan_mori<S>(l,\
    \ q, n);\n}\n\n// a.size() == d*2\ntemplate <class S>\nS nth_term_find_2(const\
    \ vector<S>& a, long long n) {\n  int d = int(a.size()) / 2;\n  Matrix<S> A(d);\n\
    \  for (int i = 0; i < d; i++) {\n    for (int j = 0; j < d; j++) A[i][j] = a[d\
    \ - j - 1 + i];\n  }\n  vector<S> coef = A.linear_equation({a.begin() + d, a.end()})[0];\n\
    \  FPS<S> l = {a.begin(), a.begin() + d};\n  FPS<S> q(d + 1);\n  q[0] = 1;\n \
    \ for (int i = 0; i < d; i++) q[i + 1] = -coef[i];\n  l = multiply(l, q, d);\n\
    \  return bostan_mori_naive<S>(l, q, n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/NthTermFind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/NthTermFind.hpp
layout: document
title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u6301\u3064\u6570\u5217\u306E\u7B2C $n$\
  \ \u9805\u76EE\u306E\u8A08\u7B97"
---

## 概要

todo

## 計算量
todo