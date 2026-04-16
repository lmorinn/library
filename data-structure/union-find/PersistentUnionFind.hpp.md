---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/PersistentArray.hpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
    title: verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \   l = m;\n      }\n    }\n    return cur;\n  }\n};\n#line 2 \"data-structure/union-find/PersistentUnionFind.hpp\"\
    \n\nstruct PersistentUnionfind {\n public:\n  using Node = PersistentArray<int>::Node;\n\
    \  PersistentUnionfind() : _n(0) {}\n  explicit PersistentUnionfind(int n) : _n(n),\
    \ parent_or_size(n, -1) {\n    root = parent_or_size.get_root();\n  }\n\n  Node\
    \ *get_root() {\n    return root;\n  }\n\n  Node *merge(Node *p, int a, int b)\
    \ {\n    assert(0 <= a && a < _n);\n    assert(0 <= b && b < _n);\n    int x =\
    \ leader(p, a), y = leader(p, b);\n    if (x == y) return p;\n    int px = parent_or_size.get(p,\
    \ x);\n    int py = parent_or_size.get(p, y);\n    if (-px < -py) std::swap(x,\
    \ y);\n    // Node *ret = parent_or_size.set(p, x, px + py);\n    return parent_or_size.set(parent_or_size.set(p,\
    \ x, px + py), y, x);\n  }\n\n  bool same(Node *p, int a, int b) {\n    assert(0\
    \ <= a && a < _n);\n    assert(0 <= b && b < _n);\n    return leader(p, a) ==\
    \ leader(p, b);\n  }\n\n  int leader(Node *p, int a) {\n    assert(0 <= a && a\
    \ < _n);\n    if (parent_or_size.get(p, a) < 0) return a;\n    return leader(p,\
    \ parent_or_size.get(p, a));\n  }\n\n  int size(Node *p, int a) {\n    assert(0\
    \ <= a && a < _n);\n    return -parent_or_size.get(p, leader(p, a));\n  }\n\n\
    \  std::vector<std::vector<int>> groups(Node *p) {\n    std::vector<int> leader_buf(_n),\
    \ group_size(_n);\n    for (int i = 0; i < _n; i++) {\n      leader_buf[i] = leader(p,\
    \ i);\n      group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<int>>\
    \ result(_n);\n    for (int i = 0; i < _n; i++) {\n      result[i].reserve(group_size[i]);\n\
    \    }\n    for (int i = 0; i < _n; i++) {\n      result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(\n        std::remove_if(result.begin(), result.end(),\n\
    \                       [&](const std::vector<int> &v) { return v.empty(); }),\n\
    \        result.end());\n    return result;\n  }\n\n private:\n  int _n;\n  //\
    \ root node: -1 * component size\n  // otherwise: parent\n\n  PersistentArray<int>\
    \ parent_or_size;\n  Node *root;\n};\n"
  code: "#include \"../others/PersistentArray.hpp\"\n\nstruct PersistentUnionfind\
    \ {\n public:\n  using Node = PersistentArray<int>::Node;\n  PersistentUnionfind()\
    \ : _n(0) {}\n  explicit PersistentUnionfind(int n) : _n(n), parent_or_size(n,\
    \ -1) {\n    root = parent_or_size.get_root();\n  }\n\n  Node *get_root() {\n\
    \    return root;\n  }\n\n  Node *merge(Node *p, int a, int b) {\n    assert(0\
    \ <= a && a < _n);\n    assert(0 <= b && b < _n);\n    int x = leader(p, a), y\
    \ = leader(p, b);\n    if (x == y) return p;\n    int px = parent_or_size.get(p,\
    \ x);\n    int py = parent_or_size.get(p, y);\n    if (-px < -py) std::swap(x,\
    \ y);\n    // Node *ret = parent_or_size.set(p, x, px + py);\n    return parent_or_size.set(parent_or_size.set(p,\
    \ x, px + py), y, x);\n  }\n\n  bool same(Node *p, int a, int b) {\n    assert(0\
    \ <= a && a < _n);\n    assert(0 <= b && b < _n);\n    return leader(p, a) ==\
    \ leader(p, b);\n  }\n\n  int leader(Node *p, int a) {\n    assert(0 <= a && a\
    \ < _n);\n    if (parent_or_size.get(p, a) < 0) return a;\n    return leader(p,\
    \ parent_or_size.get(p, a));\n  }\n\n  int size(Node *p, int a) {\n    assert(0\
    \ <= a && a < _n);\n    return -parent_or_size.get(p, leader(p, a));\n  }\n\n\
    \  std::vector<std::vector<int>> groups(Node *p) {\n    std::vector<int> leader_buf(_n),\
    \ group_size(_n);\n    for (int i = 0; i < _n; i++) {\n      leader_buf[i] = leader(p,\
    \ i);\n      group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<int>>\
    \ result(_n);\n    for (int i = 0; i < _n; i++) {\n      result[i].reserve(group_size[i]);\n\
    \    }\n    for (int i = 0; i < _n; i++) {\n      result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(\n        std::remove_if(result.begin(), result.end(),\n\
    \                       [&](const std::vector<int> &v) { return v.empty(); }),\n\
    \        result.end());\n    return result;\n  }\n\n private:\n  int _n;\n  //\
    \ root node: -1 * component size\n  // otherwise: parent\n\n  PersistentArray<int>\
    \ parent_or_size;\n  Node *root;\n};"
  dependsOn:
  - data-structure/others/PersistentArray.hpp
  isVerificationFile: false
  path: data-structure/union-find/PersistentUnionFind.hpp
  requiredBy: []
  timestamp: '2025-06-25 05:31:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/union-find/PersistentUnionfind.test.cpp
documentation_of: data-structure/union-find/PersistentUnionFind.hpp
layout: document
title: Persistent Union Find
---

## 概要

完全永続 Union-Find

## コンストラクタ

```cpp
PersistentUnionfind(int n)
```

`n` 頂点のグラフに対する完全永続 Union-Find を構築する。

### 制約

* $1 \le n$

### 計算量

* $O(n \log n)$

## get_root

```cpp
Node* get_root()
```

初期バージョンのポインタを返す。

### 計算量

* $O(1)$


## merge

```cpp
Node* merge(Node* p, int a, int b)
```

バージョン `p` において `a` と `b` を連結した新しいバージョンのポインタを返す。すでに同じ連結成分に属している場合は `p` を返す。

### 制約

* $0 \leq a, b < n$

### 計算量

* $O(\log^2 n)$


## same

```cpp
bool same(Node* p, int a, int b)
```

バージョン `p` において `a` と `b` が同じ連結成分に属していれば `true` を返す。

### 制約

* $0 \leq a, b < n$

### 計算量

* $O(\log^2 n)$

## leader
```cpp
int leader(Node* p, int a)
```

バージョン `p` において、`a` が属する連結成分の代表元を返す。

### 制約

* $0 \leq a < n$

### 計算量

* $O(\log^2 n)$


## size
```cpp
int size(Node* p, int a)
```

バージョン `p` において、`a` が属する連結成分の頂点数を返す。

### 制約

* $0 \leq a < n$

### 計算量

* $O(\log^2 n)$

## groups
```cpp
vector<vector<int>> groups(Node* p)
```

バージョン `p` における各連結成分の頂点列を返す。

### 制約


### 計算量

* $O(n \log^2 n)$
