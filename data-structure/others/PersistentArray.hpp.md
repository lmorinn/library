---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/union-find/PersistentUnionFind.hpp
    title: Persistent Union Find
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/PersistentArray.hpp\"\n\ntemplate\
    \ <class T>\nclass PersistentArray {\n public:\n  struct Node {\n    Node *l,\
    \ *r;\n    T val;\n    Node() : l(nullptr), r(nullptr) {\n    }\n  };\n  PersistentArray()\
    \ {}\n  PersistentArray(int siz) {\n    n = siz;\n    vector<T> v(n);\n    root\
    \ = new Node();\n    for (int i = 0; i < n; i++) {\n      init_set(root, i, v[i],\
    \ 0, n);\n    }\n  }\n\n  PersistentArray(int siz, T x) {\n    n = siz;\n    root\
    \ = new Node();\n    for (int i = 0; i < n; i++) {\n      init_set(root, i, x,\
    \ 0, n);\n    }\n  }\n\n  PersistentArray(const vector<T> &v) {\n    n = int(v.size());\n\
    \    root = new Node();\n    for (int i = 0; i < n; i++) {\n      init_set(root,\
    \ i, v[i], 0, n);\n    }\n  }\n\n  T get(Node *ptr, int p) {\n    return get(ptr,\
    \ p, 0, n)->val;\n  }\n\n  Node *get_root() {\n    return root;\n  }\n\n  Node\
    \ *set(Node *ptr, int p, T x) {\n    Node *new_root = new Node();\n    Node *cur\
    \ = new_root;\n    int l = 0;\n    int r = n;\n    while (r - l > 1) {\n     \
    \ int m = (l + r) >> 1;\n      if (l <= p and p < m) {\n        if (!cur->l) cur->l\
    \ = new Node();\n        cur->r = ptr->r;\n        cur = cur->l;\n        ptr\
    \ = ptr->l;\n        r = m;\n      } else {\n        if (!cur->r) cur->r = new\
    \ Node();\n        cur->l = ptr->l;\n        cur = cur->r;\n        ptr = ptr->r;\n\
    \        l = m;\n      }\n    }\n    cur->val = x;\n    return new_root;\n  }\n\
    \n private:\n  int n;\n\n  Node *root;\n\n  void init_set(Node *cur, int p, T\
    \ x, int l, int r) {\n    while (r - l > 1) {\n      int m = (l + r) >> 1;\n \
    \     if (l <= p and p < m) {\n        if (!cur->l) cur->l = new Node();\n   \
    \     cur = cur->l;\n        r = m;\n      } else {\n        if (!cur->r) cur->r\
    \ = new Node();\n        cur = cur->r;\n        l = m;\n      }\n    }\n    cur->val\
    \ = x;\n  }\n\n  Node *get(Node *cur, int p, int l, int r) {\n    while (r - l\
    \ > 1) {\n      int m = (l + r) >> 1;\n      if (l <= p and p < m) {\n       \
    \ cur = cur->l;\n        r = m;\n      } else {\n        cur = cur->r;\n     \
    \   l = m;\n      }\n    }\n    return cur;\n  }\n};\n"
  code: "\ntemplate <class T>\nclass PersistentArray {\n public:\n  struct Node {\n\
    \    Node *l, *r;\n    T val;\n    Node() : l(nullptr), r(nullptr) {\n    }\n\
    \  };\n  PersistentArray() {}\n  PersistentArray(int siz) {\n    n = siz;\n  \
    \  vector<T> v(n);\n    root = new Node();\n    for (int i = 0; i < n; i++) {\n\
    \      init_set(root, i, v[i], 0, n);\n    }\n  }\n\n  PersistentArray(int siz,\
    \ T x) {\n    n = siz;\n    root = new Node();\n    for (int i = 0; i < n; i++)\
    \ {\n      init_set(root, i, x, 0, n);\n    }\n  }\n\n  PersistentArray(const\
    \ vector<T> &v) {\n    n = int(v.size());\n    root = new Node();\n    for (int\
    \ i = 0; i < n; i++) {\n      init_set(root, i, v[i], 0, n);\n    }\n  }\n\n \
    \ T get(Node *ptr, int p) {\n    return get(ptr, p, 0, n)->val;\n  }\n\n  Node\
    \ *get_root() {\n    return root;\n  }\n\n  Node *set(Node *ptr, int p, T x) {\n\
    \    Node *new_root = new Node();\n    Node *cur = new_root;\n    int l = 0;\n\
    \    int r = n;\n    while (r - l > 1) {\n      int m = (l + r) >> 1;\n      if\
    \ (l <= p and p < m) {\n        if (!cur->l) cur->l = new Node();\n        cur->r\
    \ = ptr->r;\n        cur = cur->l;\n        ptr = ptr->l;\n        r = m;\n  \
    \    } else {\n        if (!cur->r) cur->r = new Node();\n        cur->l = ptr->l;\n\
    \        cur = cur->r;\n        ptr = ptr->r;\n        l = m;\n      }\n    }\n\
    \    cur->val = x;\n    return new_root;\n  }\n\n private:\n  int n;\n\n  Node\
    \ *root;\n\n  void init_set(Node *cur, int p, T x, int l, int r) {\n    while\
    \ (r - l > 1) {\n      int m = (l + r) >> 1;\n      if (l <= p and p < m) {\n\
    \        if (!cur->l) cur->l = new Node();\n        cur = cur->l;\n        r =\
    \ m;\n      } else {\n        if (!cur->r) cur->r = new Node();\n        cur =\
    \ cur->r;\n        l = m;\n      }\n    }\n    cur->val = x;\n  }\n\n  Node *get(Node\
    \ *cur, int p, int l, int r) {\n    while (r - l > 1) {\n      int m = (l + r)\
    \ >> 1;\n      if (l <= p and p < m) {\n        cur = cur->l;\n        r = m;\n\
    \      } else {\n        cur = cur->r;\n        l = m;\n      }\n    }\n    return\
    \ cur;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/PersistentArray.hpp
  requiredBy:
  - data-structure/union-find/PersistentUnionFind.hpp
  timestamp: '2025-06-25 05:31:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/others/PersistentArray.hpp
layout: document
title: Persistent Array
---

## 概要

todo

## 計算量
todo