---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
    title: verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/MergeSortTree.hpp\"\n\nclass MergeSortTree\
    \ {\n private:\n  int n0;\n  int n;\n  int MA = 1e9 + 10;\n  vector<int> px;\n\
    \n  vector<vector<int>> node;\n\n  void _merge(vector<int> &par, vector<int> a,\
    \ vector<int> b) {\n    int siz_a = a.size();\n    int siz_b = b.size();\n   \
    \ par.resize(siz_a + siz_b);\n    int i = 0;\n    int j = 0;\n    for (int k =\
    \ 0; k < siz_a + siz_b; k++) {\n      if (i < siz_a and j < siz_b) {\n       \
    \ if (a[i] <= b[j]) {\n          par[k] = a[i];\n          i++;\n        } else\
    \ {\n          par[k] = b[j];\n          j++;\n        }\n      } else if (i <\
    \ siz_a) {\n        par[k] = a[i];\n        i++;\n      } else {\n        par[k]\
    \ = b[j];\n        j++;\n      }\n    }\n  }\n\n  int less_count(int a, int b,\
    \ int x, int k = 0, int l = 0, int r = -1) {\n    if (r < 0) r = n0;\n    if (r\
    \ <= a or b <= l) return 0;\n    if (a <= l and r <= b) return distance(node[k].begin(),\
    \ lower_bound(node[k].begin(), node[k].end(), x));\n\n    int cl = less_count(a,\
    \ b, x, k * 2 + 1, l, (l + r) / 2);\n    int cr = less_count(a, b, x, k * 2 +\
    \ 2, (l + r) / 2, r);\n\n    return cl + cr;\n  }\n\n public:\n  MergeSortTree()\
    \ {}\n  MergeSortTree(const vector<int> &v) {\n    n = v.size();\n    n0 = 1;\n\
    \    while (n0 < n) n0 *= 2;\n    node.resize(n0 * 2 - 1);\n    for (int i = 0;\
    \ i < n; i++) node[i + n0 - 1].emplace_back(v[i]);\n    for (int i = n0 - 2; i\
    \ >= 0; i--) _merge(node[i], node[i * 2 + 1], node[i * 2 + 2]);\n  }\n\n  MergeSortTree(vector<int>\
    \ x, vector<int> y) {\n    n = x.size();\n    n0 = 1;\n    while (n0 < n) n0 *=\
    \ 2;\n    vector<pair<int, int>> v(n);\n    for (int i = 0; i < n; i++) v[i] =\
    \ {x[i], y[i]};\n    sort(v.begin(), v.end());\n    px.resize(n);\n    for (int\
    \ i = 0; i < n; i++) {\n      px[i] = v[i].first;\n      y[i] = v[i].second;\n\
    \    }\n\n    node.resize(n0 * 2 - 1);\n    for (int i = 0; i < n; i++) node[i\
    \ + n0 - 1].emplace_back(y[i]);\n    for (int i = n0 - 2; i >= 0; i--) _merge(node[i],\
    \ node[i * 2 + 1], node[i * 2 + 2]);\n  }\n\n  int range_freq(int l, int r, int\
    \ mink, int maxk) {\n    return less_count(l, r, maxk) - less_count(l, r, mink);\n\
    \  }\n\n  int rectangle_freq(int lx, int rx, int ly, int ry) {\n    int l = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), lx));\n    int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), rx));\n    return less_count(l, r, ry) - less_count(l, r, ly);\n \
    \ }\n};\n"
  code: "\nclass MergeSortTree {\n private:\n  int n0;\n  int n;\n  int MA = 1e9 +\
    \ 10;\n  vector<int> px;\n\n  vector<vector<int>> node;\n\n  void _merge(vector<int>\
    \ &par, vector<int> a, vector<int> b) {\n    int siz_a = a.size();\n    int siz_b\
    \ = b.size();\n    par.resize(siz_a + siz_b);\n    int i = 0;\n    int j = 0;\n\
    \    for (int k = 0; k < siz_a + siz_b; k++) {\n      if (i < siz_a and j < siz_b)\
    \ {\n        if (a[i] <= b[j]) {\n          par[k] = a[i];\n          i++;\n \
    \       } else {\n          par[k] = b[j];\n          j++;\n        }\n      }\
    \ else if (i < siz_a) {\n        par[k] = a[i];\n        i++;\n      } else {\n\
    \        par[k] = b[j];\n        j++;\n      }\n    }\n  }\n\n  int less_count(int\
    \ a, int b, int x, int k = 0, int l = 0, int r = -1) {\n    if (r < 0) r = n0;\n\
    \    if (r <= a or b <= l) return 0;\n    if (a <= l and r <= b) return distance(node[k].begin(),\
    \ lower_bound(node[k].begin(), node[k].end(), x));\n\n    int cl = less_count(a,\
    \ b, x, k * 2 + 1, l, (l + r) / 2);\n    int cr = less_count(a, b, x, k * 2 +\
    \ 2, (l + r) / 2, r);\n\n    return cl + cr;\n  }\n\n public:\n  MergeSortTree()\
    \ {}\n  MergeSortTree(const vector<int> &v) {\n    n = v.size();\n    n0 = 1;\n\
    \    while (n0 < n) n0 *= 2;\n    node.resize(n0 * 2 - 1);\n    for (int i = 0;\
    \ i < n; i++) node[i + n0 - 1].emplace_back(v[i]);\n    for (int i = n0 - 2; i\
    \ >= 0; i--) _merge(node[i], node[i * 2 + 1], node[i * 2 + 2]);\n  }\n\n  MergeSortTree(vector<int>\
    \ x, vector<int> y) {\n    n = x.size();\n    n0 = 1;\n    while (n0 < n) n0 *=\
    \ 2;\n    vector<pair<int, int>> v(n);\n    for (int i = 0; i < n; i++) v[i] =\
    \ {x[i], y[i]};\n    sort(v.begin(), v.end());\n    px.resize(n);\n    for (int\
    \ i = 0; i < n; i++) {\n      px[i] = v[i].first;\n      y[i] = v[i].second;\n\
    \    }\n\n    node.resize(n0 * 2 - 1);\n    for (int i = 0; i < n; i++) node[i\
    \ + n0 - 1].emplace_back(y[i]);\n    for (int i = n0 - 2; i >= 0; i--) _merge(node[i],\
    \ node[i * 2 + 1], node[i * 2 + 2]);\n  }\n\n  int range_freq(int l, int r, int\
    \ mink, int maxk) {\n    return less_count(l, r, maxk) - less_count(l, r, mink);\n\
    \  }\n\n  int rectangle_freq(int lx, int rx, int ly, int ry) {\n    int l = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), lx));\n    int r = distance(px.begin(), lower_bound(px.begin(),\
    \ px.end(), rx));\n    return less_count(l, r, ry) - less_count(l, r, ly);\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/MergeSortTree.hpp
  requiredBy: []
  timestamp: '2024-12-13 12:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/others/StaticRangeFrequency.test.cpp
documentation_of: data-structure/others/MergeSortTree.hpp
layout: document
title: Merge Sort Tree
---

## 概要

todo

## 計算量
todo