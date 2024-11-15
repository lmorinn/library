---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp
    title: Wavelet Matrix (Sqrt Tree)
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/SqrtTree.hpp\"\ntemplate <class S,\
    \ auto op>\nclass SqrtTree {\n   private:\n    int n, lg, indexSz;\n    vector<S>\
    \ v;\n    vector<int> clz, layers, onLayer;\n    vector<vector<S>> prefix, suffix,\
    \ between;\n\n    void build(int layer, int lBound, int rBound, int betweenOffs)\
    \ {\n        if (layer >= (int)layers.size()) {\n            return;\n       \
    \ }\n        int bSz = 1 << ((layers[layer] + 1) >> 1);\n        for (int l =\
    \ lBound; l < rBound; l += bSz) {\n            int r = min(l + bSz, rBound);\n\
    \            prefix[layer][l] = v[l];\n            for (int i = l + 1; i < r;\
    \ i++) {\n                prefix[layer][i] = op(prefix[layer][i - 1], v[i]);\n\
    \            }\n            suffix[layer][r - 1] = v[r - 1];\n            for\
    \ (int i = r - 2; i >= l; i--) {\n                suffix[layer][i] = op(v[i],\
    \ suffix[layer][i + 1]);\n            }\n            build(layer + 1, l, r, betweenOffs);\n\
    \        }\n        if (layer == 0) {\n            int bSzLog = (lg + 1) >> 1;\n\
    \            for (int i = 0; i < indexSz; i++) {\n                v[n + i] = suffix[0][i\
    \ << bSzLog];\n            }\n            build(1, n, n + indexSz, (1 << lg) -\
    \ n);\n        } else {\n            int bSzLog = (layers[layer] + 1) >> 1;\n\
    \            int bCntLog = layers[layer] >> 1;\n            int bSz = 1 << bSzLog;\n\
    \            int bCnt = (rBound - lBound + bSz - 1) >> bSzLog;\n            for\
    \ (int i = 0; i < bCnt; i++) {\n                S ans;\n                for (int\
    \ j = i; j < bCnt; j++) {\n                    S add = suffix[layer][lBound +\
    \ (j << bSzLog)];\n                    ans = (i == j) ? add : op(ans, add);\n\
    \                    between[layer - 1][betweenOffs + lBound + (i << bCntLog)\
    \ + j] = ans;\n                }\n            }\n        }\n    }\n\n    inline\
    \ S query(int l, int r, int betweenOffs, int base) {\n        if (l == r) {\n\
    \            return v[l];\n        }\n        if (l + 1 == r) {\n            return\
    \ op(v[l], v[r]);\n        }\n        int layer = onLayer[clz[(l - base) ^ (r\
    \ - base)]];\n        int bSzLog = (layers[layer] + 1) >> 1;\n        int bCntLog\
    \ = layers[layer] >> 1;\n        int lBound = (((l - base) >> layers[layer]) <<\
    \ layers[layer]) + base;\n        int lBlock = ((l - lBound) >> bSzLog) + 1;\n\
    \        int rBlock = ((r - lBound) >> bSzLog) - 1;\n        S ans = suffix[layer][l];\n\
    \        if (lBlock <= rBlock) {\n            S add = (layer == 0) ? (\n     \
    \                                  query(n + lBlock, n + rBlock, (1 << lg) - n,\
    \ n))\n                                 : (\n                                \
    \       between[layer - 1][betweenOffs + lBound + (lBlock << bCntLog) + rBlock]);\n\
    \            ans = op(ans, add);\n        }\n        ans = op(ans, prefix[layer][r]);\n\
    \        return ans;\n    }\n\n   public:\n    inline S prod(int l, int r) {\n\
    \        return query(l, r - 1, 0, 0);\n    }\n    SqrtTree() {}\n\n    SqrtTree(const\
    \ vector<S> a)\n        : n((int)a.size()), v(a) {\n        lg = 0;\n        while\
    \ ((1 << lg) < n) lg++;\n        clz.assign(1 << lg, 0);\n        onLayer.assign(lg\
    \ + 1, 0);\n        clz[0] = 0;\n        for (int i = 1; i < (int)clz.size();\
    \ i++) {\n            clz[i] = clz[i >> 1] + 1;\n        }\n        int tlg =\
    \ lg;\n        while (tlg > 1) {\n            onLayer[tlg] = (int)layers.size();\n\
    \            layers.push_back(tlg);\n            tlg = (tlg + 1) >> 1;\n     \
    \   }\n        for (int i = lg - 1; i >= 0; i--) {\n            onLayer[i] = max(onLayer[i],\
    \ onLayer[i + 1]);\n        }\n        int betweenLayers = max(0, (int)layers.size()\
    \ - 1);\n        int bSzLog = (lg + 1) >> 1;\n        int bSz = 1 << bSzLog;\n\
    \        indexSz = (n + bSz - 1) >> bSzLog;\n        v.resize(n + indexSz);\n\
    \        prefix.assign(layers.size(), vector<S>(n + indexSz));\n        suffix.assign(layers.size(),\
    \ vector<S>(n + indexSz));\n        between.assign(betweenLayers, vector<S>((1\
    \ << lg) + bSz));\n        build(0, 0, n, 0);\n    }\n};\n"
  code: "template <class S, auto op>\nclass SqrtTree {\n   private:\n    int n, lg,\
    \ indexSz;\n    vector<S> v;\n    vector<int> clz, layers, onLayer;\n    vector<vector<S>>\
    \ prefix, suffix, between;\n\n    void build(int layer, int lBound, int rBound,\
    \ int betweenOffs) {\n        if (layer >= (int)layers.size()) {\n           \
    \ return;\n        }\n        int bSz = 1 << ((layers[layer] + 1) >> 1);\n   \
    \     for (int l = lBound; l < rBound; l += bSz) {\n            int r = min(l\
    \ + bSz, rBound);\n            prefix[layer][l] = v[l];\n            for (int\
    \ i = l + 1; i < r; i++) {\n                prefix[layer][i] = op(prefix[layer][i\
    \ - 1], v[i]);\n            }\n            suffix[layer][r - 1] = v[r - 1];\n\
    \            for (int i = r - 2; i >= l; i--) {\n                suffix[layer][i]\
    \ = op(v[i], suffix[layer][i + 1]);\n            }\n            build(layer +\
    \ 1, l, r, betweenOffs);\n        }\n        if (layer == 0) {\n            int\
    \ bSzLog = (lg + 1) >> 1;\n            for (int i = 0; i < indexSz; i++) {\n \
    \               v[n + i] = suffix[0][i << bSzLog];\n            }\n          \
    \  build(1, n, n + indexSz, (1 << lg) - n);\n        } else {\n            int\
    \ bSzLog = (layers[layer] + 1) >> 1;\n            int bCntLog = layers[layer]\
    \ >> 1;\n            int bSz = 1 << bSzLog;\n            int bCnt = (rBound -\
    \ lBound + bSz - 1) >> bSzLog;\n            for (int i = 0; i < bCnt; i++) {\n\
    \                S ans;\n                for (int j = i; j < bCnt; j++) {\n  \
    \                  S add = suffix[layer][lBound + (j << bSzLog)];\n          \
    \          ans = (i == j) ? add : op(ans, add);\n                    between[layer\
    \ - 1][betweenOffs + lBound + (i << bCntLog) + j] = ans;\n                }\n\
    \            }\n        }\n    }\n\n    inline S query(int l, int r, int betweenOffs,\
    \ int base) {\n        if (l == r) {\n            return v[l];\n        }\n  \
    \      if (l + 1 == r) {\n            return op(v[l], v[r]);\n        }\n    \
    \    int layer = onLayer[clz[(l - base) ^ (r - base)]];\n        int bSzLog =\
    \ (layers[layer] + 1) >> 1;\n        int bCntLog = layers[layer] >> 1;\n     \
    \   int lBound = (((l - base) >> layers[layer]) << layers[layer]) + base;\n  \
    \      int lBlock = ((l - lBound) >> bSzLog) + 1;\n        int rBlock = ((r -\
    \ lBound) >> bSzLog) - 1;\n        S ans = suffix[layer][l];\n        if (lBlock\
    \ <= rBlock) {\n            S add = (layer == 0) ? (\n                       \
    \                query(n + lBlock, n + rBlock, (1 << lg) - n, n))\n          \
    \                       : (\n                                       between[layer\
    \ - 1][betweenOffs + lBound + (lBlock << bCntLog) + rBlock]);\n            ans\
    \ = op(ans, add);\n        }\n        ans = op(ans, prefix[layer][r]);\n     \
    \   return ans;\n    }\n\n   public:\n    inline S prod(int l, int r) {\n    \
    \    return query(l, r - 1, 0, 0);\n    }\n    SqrtTree() {}\n\n    SqrtTree(const\
    \ vector<S> a)\n        : n((int)a.size()), v(a) {\n        lg = 0;\n        while\
    \ ((1 << lg) < n) lg++;\n        clz.assign(1 << lg, 0);\n        onLayer.assign(lg\
    \ + 1, 0);\n        clz[0] = 0;\n        for (int i = 1; i < (int)clz.size();\
    \ i++) {\n            clz[i] = clz[i >> 1] + 1;\n        }\n        int tlg =\
    \ lg;\n        while (tlg > 1) {\n            onLayer[tlg] = (int)layers.size();\n\
    \            layers.push_back(tlg);\n            tlg = (tlg + 1) >> 1;\n     \
    \   }\n        for (int i = lg - 1; i >= 0; i--) {\n            onLayer[i] = max(onLayer[i],\
    \ onLayer[i + 1]);\n        }\n        int betweenLayers = max(0, (int)layers.size()\
    \ - 1);\n        int bSzLog = (lg + 1) >> 1;\n        int bSz = 1 << bSzLog;\n\
    \        indexSz = (n + bSz - 1) >> bSzLog;\n        v.resize(n + indexSz);\n\
    \        prefix.assign(layers.size(), vector<S>(n + indexSz));\n        suffix.assign(layers.size(),\
    \ vector<S>(n + indexSz));\n        between.assign(betweenLayers, vector<S>((1\
    \ << lg) + bSz));\n        build(0, 0, n, 0);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/SqrtTree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp
  timestamp: '2024-11-15 13:36:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/others/SqrtTree.hpp
layout: document
title: Sqrt Tree
---

## 概要

todo

## 計算量
todo