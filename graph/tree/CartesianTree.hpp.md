---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/tree/CartesianTree.test.cpp
    title: verify/LibraryChecker/tree/CartesianTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/CartesianTree.hpp\"\ntemplate <class T, auto\
    \ compare = std::less()>\nclass CartesianTree {\n public:\n  int root;\n  vector<int>\
    \ parent, left, right;\n\n  CartesianTree() : root(0) {}\n  CartesianTree(const\
    \ vector<T>& v) : root(0), parent(int(v.size()), -1), left(int(v.size()), -1),\
    \ right(int(v.size()), -1) {\n    stack<pair<lint, int>> st;\n    int n = int(v.size());\n\
    \    for (int i = 0; i < n; i++) {\n      if (!st.empty()) {\n        int pop_idx\
    \ = -1;\n        while (!st.empty() and compare(v[i], st.top().first)) {\n   \
    \       pop_idx = st.top().second;\n          st.pop();\n        }\n        if\
    \ (pop_idx != -1) {\n          left[i] = pop_idx;\n          parent[pop_idx] =\
    \ i;\n        }\n        if (!st.empty()) {\n          int idx = st.top().second;\n\
    \          parent[i] = idx;\n          right[idx] = i;\n        }\n      }\n \
    \     st.emplace(v[i], i);\n    }\n\n    for (int i = 0; i < n; i++) {\n     \
    \ if (parent[i] == -1) {\n        root = i;\n        parent[i] = i;\n        break;\n\
    \      }\n    }\n  }\n};\n"
  code: "template <class T, auto compare = std::less()>\nclass CartesianTree {\n public:\n\
    \  int root;\n  vector<int> parent, left, right;\n\n  CartesianTree() : root(0)\
    \ {}\n  CartesianTree(const vector<T>& v) : root(0), parent(int(v.size()), -1),\
    \ left(int(v.size()), -1), right(int(v.size()), -1) {\n    stack<pair<lint, int>>\
    \ st;\n    int n = int(v.size());\n    for (int i = 0; i < n; i++) {\n      if\
    \ (!st.empty()) {\n        int pop_idx = -1;\n        while (!st.empty() and compare(v[i],\
    \ st.top().first)) {\n          pop_idx = st.top().second;\n          st.pop();\n\
    \        }\n        if (pop_idx != -1) {\n          left[i] = pop_idx;\n     \
    \     parent[pop_idx] = i;\n        }\n        if (!st.empty()) {\n          int\
    \ idx = st.top().second;\n          parent[i] = idx;\n          right[idx] = i;\n\
    \        }\n      }\n      st.emplace(v[i], i);\n    }\n\n    for (int i = 0;\
    \ i < n; i++) {\n      if (parent[i] == -1) {\n        root = i;\n        parent[i]\
    \ = i;\n        break;\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/CartesianTree.hpp
  requiredBy: []
  timestamp: '2026-03-11 19:33:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/tree/CartesianTree.test.cpp
documentation_of: graph/tree/CartesianTree.hpp
layout: document
title: Cartesian Tree
---

## 概要

todo

## 計算量
todo