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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../WaveletMatrixSegtree:\
    \ line -1: no such header\n"
  code: "\n#include \"./../WaveletMatrixSegtree\"\nusing S = int;\nS op(S a, S b)\
    \ {\n  return min(a, b);\n}\n\nS e() {\n  return INT_MAX;\n}\nclass RangeMex {\n\
    \ private:\n  int n;\n  WaveletMatrix<S, op, e> wm;\n\n public:\n  RangeMex(const\
    \ vector<int> &v) {\n    n = v.size();\n    vector<int> x, y, z;\n    vector<int>\
    \ last(n + 1, -1);\n    x.reserve(n * 2);\n    y.reserve(n * 2);\n    z.reserve(n\
    \ * 2);\n\n    for (int i = 0; i < n; i++) {\n      if (v[i] > n) continue;\n\
    \      x.emplace_back(last[v[i]]);\n      y.emplace_back(i);\n      z.emplace_back(v[i]);\n\
    \      last[v[i]] = i;\n    }\n\n    for (int i = 0; i < n + 1; i++) {\n     \
    \ x.emplace_back(last[i]);\n      y.emplace_back(n);\n      z.emplace_back(i);\n\
    \    }\n\n    wm = WaveletMatrix<S, op, e>(x, y, z);\n  }\n\n  int range_mex(int\
    \ l, int r) {\n    return wm.rectangle_prod(-1, l, r, n + 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/query/RangeMex.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/query/RangeMex.hpp
layout: document
title: Range Mex Query
---

## 概要

todo

## 計算量
todo