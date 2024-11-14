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
  bundledCode: "#line 1 \"data-structure/others/SqrtTree.hpp\"\n\ntemplate <class\
    \ S, auto op>\nclass SqrtTree {\n   private:\n    vector<vector<S>> prefix, suffix,\
    \ between;\n    vector<S> v;\n    vector<int> layerlg, layerv;\n\n   public:\n\
    \    SqrtTree() = default;\n    SqrtTree(vector<S> &a) {\n        v = a;\n   \
    \     int n = v.size();\n        int lg = 0;\n        lg = bit_width(ull(n));\n\
    \        int n_layer = 0;\n        layerv.resize(lg + 1);\n        for (int i\
    \ = lg; i > 1; i = (i + 1) >> 1) {\n            layerv[i] = n_layer++;\n     \
    \       layerlg.push_back(i);\n        }\n        for (int i = lg - 1; i >= 0;\
    \ --i) layerv[i] = max(layerv[i], layerv[i + 1]);\n        prefix.resize(n_layer,\
    \ vector<S>(n));\n        suffix.resize(n_layer, vector<S>(n));\n        between.resize(n_layer,\
    \ vector<S>(1 << lg));\n\n        for (int layer = 0; layer < n_layer; ++layer)\
    \ {\n            int current_lg = layerlg[layer];\n            int prev_b_sz =\
    \ 1 << current_lg;\n            int b_sz_shift = (current_lg + 1) >> 1;\n    \
    \        int b_cnt_shift = current_lg >> 1;\n            int b_sz = 1 << b_sz_shift;\n\
    \            int b_cnt = 1 << b_cnt_shift;\n            for (int l = 0; l < n;\
    \ l += prev_b_sz) {\n                int r = min(l + prev_b_sz, n);\n        \
    \        for (int a = l; a < r; a += b_sz) {\n                    int b = min(a\
    \ + b_sz, r);\n                    prefix[layer][a] = v[a];\n                \
    \    for (int i = a + 1; i < b; ++i) {\n                        prefix[layer][i]\
    \ = op(prefix[layer][i - 1], v[i]);\n                    }\n                 \
    \   suffix[layer][b - 1] = v[b - 1];\n                    for (int i = b - 2;\
    \ i >= a; --i) {\n                        suffix[layer][i] = op(v[i], suffix[layer][i\
    \ + 1]);\n                    }\n                }\n                for (int i\
    \ = 0; i < b_cnt; ++i) {\n                    int idx = l + (i << b_sz_shift);\n\
    \                    S val = suffix[layer][idx];\n                    between[layer][(i\
    \ << b_cnt_shift) + i] = val;\n                    for (int j = i + 1; j < b_cnt;\
    \ ++j) {\n                        int suffix_idx = l + (j << b_sz_shift);\n  \
    \                      val = op(val, suffix[layer][suffix_idx]);\n           \
    \             between[layer][(i << b_cnt_shift) + j] = val;\n                \
    \    }\n                }\n            }\n        }\n    }\n\n    S prod(int l,\
    \ int r) const {\n        --r;\n        if (l == r) return v[l];\n        if (l\
    \ + 1 == r) return op(v[l], v[r]);\n        int xor_val = l ^ r;\n        int\
    \ highest_bit = 32 - __builtin_clz(xor_val);\n        int layer = layerv[highest_bit];\n\
    \        int current_lg = layerlg[layer];\n        int b_sz_shift = (current_lg\
    \ + 1) >> 1;\n        int b_cnt_shift = current_lg >> 1;\n        int b_sz = 1\
    \ << b_sz_shift;\n        int b_cnt = 1 << b_cnt_shift;\n        int a = l & (~((1\
    \ << current_lg) - 1));\n        int lblock = ((l - a) >> b_sz_shift) + 1;\n \
    \       int rblock = ((r - a) >> b_sz_shift) - 1;\n        S val = suffix[layer][l];\n\
    \        if (lblock <= rblock) val = op(val, between[layer][a + (lblock << b_cnt_shift)\
    \ + rblock]);\n        val = op(val, prefix[layer][r]);\n        return val;\n\
    \    }\n};\n"
  code: "\ntemplate <class S, auto op>\nclass SqrtTree {\n   private:\n    vector<vector<S>>\
    \ prefix, suffix, between;\n    vector<S> v;\n    vector<int> layerlg, layerv;\n\
    \n   public:\n    SqrtTree() = default;\n    SqrtTree(vector<S> &a) {\n      \
    \  v = a;\n        int n = v.size();\n        int lg = 0;\n        lg = bit_width(ull(n));\n\
    \        int n_layer = 0;\n        layerv.resize(lg + 1);\n        for (int i\
    \ = lg; i > 1; i = (i + 1) >> 1) {\n            layerv[i] = n_layer++;\n     \
    \       layerlg.push_back(i);\n        }\n        for (int i = lg - 1; i >= 0;\
    \ --i) layerv[i] = max(layerv[i], layerv[i + 1]);\n        prefix.resize(n_layer,\
    \ vector<S>(n));\n        suffix.resize(n_layer, vector<S>(n));\n        between.resize(n_layer,\
    \ vector<S>(1 << lg));\n\n        for (int layer = 0; layer < n_layer; ++layer)\
    \ {\n            int current_lg = layerlg[layer];\n            int prev_b_sz =\
    \ 1 << current_lg;\n            int b_sz_shift = (current_lg + 1) >> 1;\n    \
    \        int b_cnt_shift = current_lg >> 1;\n            int b_sz = 1 << b_sz_shift;\n\
    \            int b_cnt = 1 << b_cnt_shift;\n            for (int l = 0; l < n;\
    \ l += prev_b_sz) {\n                int r = min(l + prev_b_sz, n);\n        \
    \        for (int a = l; a < r; a += b_sz) {\n                    int b = min(a\
    \ + b_sz, r);\n                    prefix[layer][a] = v[a];\n                \
    \    for (int i = a + 1; i < b; ++i) {\n                        prefix[layer][i]\
    \ = op(prefix[layer][i - 1], v[i]);\n                    }\n                 \
    \   suffix[layer][b - 1] = v[b - 1];\n                    for (int i = b - 2;\
    \ i >= a; --i) {\n                        suffix[layer][i] = op(v[i], suffix[layer][i\
    \ + 1]);\n                    }\n                }\n                for (int i\
    \ = 0; i < b_cnt; ++i) {\n                    int idx = l + (i << b_sz_shift);\n\
    \                    S val = suffix[layer][idx];\n                    between[layer][(i\
    \ << b_cnt_shift) + i] = val;\n                    for (int j = i + 1; j < b_cnt;\
    \ ++j) {\n                        int suffix_idx = l + (j << b_sz_shift);\n  \
    \                      val = op(val, suffix[layer][suffix_idx]);\n           \
    \             between[layer][(i << b_cnt_shift) + j] = val;\n                \
    \    }\n                }\n            }\n        }\n    }\n\n    S prod(int l,\
    \ int r) const {\n        --r;\n        if (l == r) return v[l];\n        if (l\
    \ + 1 == r) return op(v[l], v[r]);\n        int xor_val = l ^ r;\n        int\
    \ highest_bit = 32 - __builtin_clz(xor_val);\n        int layer = layerv[highest_bit];\n\
    \        int current_lg = layerlg[layer];\n        int b_sz_shift = (current_lg\
    \ + 1) >> 1;\n        int b_cnt_shift = current_lg >> 1;\n        int b_sz = 1\
    \ << b_sz_shift;\n        int b_cnt = 1 << b_cnt_shift;\n        int a = l & (~((1\
    \ << current_lg) - 1));\n        int lblock = ((l - a) >> b_sz_shift) + 1;\n \
    \       int rblock = ((r - a) >> b_sz_shift) - 1;\n        S val = suffix[layer][l];\n\
    \        if (lblock <= rblock) val = op(val, between[layer][a + (lblock << b_cnt_shift)\
    \ + rblock]);\n        val = op(val, prefix[layer][r]);\n        return val;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/SqrtTree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp
  timestamp: '2024-11-15 00:33:05+09:00'
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