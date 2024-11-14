---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/4059\"\
    \n#include \"../../../../data-structure/segment-tree/SegmentTree.hpp\"\n#include\
    \ \"../../../data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp\"\n\nusing\
    \ S = lint;\n\nS op(S a, S b) {\n  return a + b;\n}\n\nS e() {\n  return 0;\n\
    }\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n, q);\n\
    \  vector Q(q, vector(6, 0LL));\n  vector<S> x, y, w;\n\n  int cur = 0;\n  rep(i,\
    \ q) {\n    int com;\n    in(com);\n    Q[i][0] = com;\n    if (com == 1) {\n\
    \      in(Q[i][1], Q[i][2], Q[i][3], Q[i][4]);\n      x.emplace_back(Q[i][1]);\n\
    \      y.emplace_back(Q[i][3]);\n      x.emplace_back(Q[i][2] + 1);\n      y.emplace_back(Q[i][3]);\n\
    \      Q[i][5] = cur;\n      cur++;\n    } else {\n      in(Q[i][1], Q[i][2]);\n\
    \    }\n  }\n  w.resize(x.size());\n\n  WaveletMatrix<S, op, e> wm(x, y, w);\n\
    \  rep(i, q) {\n    int com = Q[i][0];\n    if (com == 1) {\n      wm.set(Q[i][5]\
    \ * 2, Q[i][4]);\n      wm.set(Q[i][5] * 2 + 1, -Q[i][4]);\n    } else {\n   \
    \   int l = 0;\n      int r = Q[i][1] + 1;\n      auto F = [&](int cnt, S prod)\
    \ {\n        return prod < Q[i][2];\n      };\n      out(wm.max_y(l, r, F));\n\
    \    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/AizuOnlineJudge/data-structure/wavelet-matrix/WarehouseManagementRobot.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/data-structure/wavelet-matrix/WarehouseManagementRobot.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/data-structure/wavelet-matrix/WarehouseManagementRobot.test.cpp
- /verify/verify/AizuOnlineJudge/data-structure/wavelet-matrix/WarehouseManagementRobot.test.cpp.html
title: verify/AizuOnlineJudge/data-structure/wavelet-matrix/WarehouseManagementRobot.test.cpp
---
