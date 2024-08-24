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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/segment-tree/DualSegmentTree2D.hpp: line 2: #pragma once found\
    \ in a non-first line\n"
  code: "#include <./DualSegmentTree.hpp>\n#pragma once\n\ntemplate <class S, class\
    \ F, auto mapping, auto composition, auto id>\nclass DualSegmentTree2D {\n   private:\n\
    \    int n;\n    vector<DualSegmentTree<S, F, mapping, composition, id>> node;\n\
    \    vector<vector<S>> ar;\n\n    void Apply(int x1, int y1, int x2, int y2, F\
    \ x, int k = 0, int l = 0, int r = -1) {\n        if (r < 0) r = n;\n        if\
    \ (r <= y1 || y2 <= l) return;\n        if (y1 <= l && r <= y2) {\n          \
    \  node[k].apply(x1, x2, x);\n            return;\n        }\n        Apply(x1,\
    \ y1, x2, y2, x, 2 * k + 1, l, (l + r) / 2);\n        Apply(x1, y1, x2, y2, x,\
    \ 2 * k + 2, (l + r) / 2, r);\n    }\n\n   public:\n    DualSegmentTree2D(vector<vector<S>>\
    \ v) {\n        int sz = v.size();\n        n = 1;\n        while (n < sz) n *=\
    \ 2;\n        ar.resize(sz);\n        vector<S> idv(v[0].size(), id());\n    \
    \    node.resize(n * 2 - 1);\n        for (int i = 0; i < sz; i++) {\n       \
    \     ar[i].resize(ar[i].size());\n            ar[i] = v[i];\n        }\n    \
    \    for (int i = 0; i < n * 2 - 1; i++) {\n            node[i] = DualSegmentTree<S,\
    \ F, mapping, composition, id>(idv);\n        }\n    }\n\n    void apply(int x1,\
    \ int y1, int x2, int y2, F x) {\n        Apply(x1, y1, x2, y2, x);\n    }\n\n\
    \    S get2d(int x, int y) {\n        S ret = ar[y][x];\n        y += (n - 1);\n\
    \        F f = node[y].getf(x);\n        while (y > 0) {\n            y = (y -\
    \ 1) / 2;\n            f = composition(node[y].getf(x), f);\n        }\n     \
    \   return mapping(f, ret);\n    }\n\n    void print() {\n        for (int i =\
    \ 0; i < ar.size(); i++) {\n            for (int j = 0; j < ar[i].size(); j++)\
    \ {\n                cout << get2d(j, i);\n                if (j + 1 == ar[i].size())\
    \ {\n                    cout << \"\\n\";\n                } else {\n        \
    \            cout << \" \";\n                }\n            }\n        }\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/DualSegmentTree2D.hpp
  requiredBy: []
  timestamp: '2024-08-24 12:35:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segment-tree/DualSegmentTree2D.hpp
layout: document
title: Dual Segment Tree (2D)
---

## 概要

todo

## 計算量
todo