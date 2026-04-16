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
  bundledCode: "#line 1 \"data-structure/segment-tree/PersistentSegmentTree.hpp\"\n\
    template <class S, auto op, auto e>\nclass persistent_segtree {\n   private:\n\
    \    vector<S> node;\n    vector<int> l_id, r_id;\n    int id = 0;\n    int n,\
    \ root;\n    int NODE_SIZE = 20000000;\n\n    inline int newleaf(S x) {\n    \
    \    int pos = id++;\n        node[pos] = x;\n        return pos;\n    }\n\n \
    \   inline int newparent(int l, int r) {\n        int pos = id++;\n        l_id[pos]\
    \ = l;\n        r_id[pos] = r;\n        node[pos] = op(node[l], node[r]);\n  \
    \      return pos;\n    }\n\n    int build(const vector<S> &v, int l, int r) {\n\
    \        if (r - l == 1) {\n            return newleaf(v[l]);\n        } else\
    \ {\n            return newparent(build(v, l, (l + r) >> 1), build(v, (l + r)\
    \ >> 1, r));\n        }\n    }\n\n    int set_query(int i, S x, int root_id, int\
    \ l, int r) {\n        if (r - l == 1) {\n            return newleaf(x);\n   \
    \     }\n        int mid = (l + r) >> 1;\n        if (i < mid) {\n           \
    \ return newparent(set_query(i, x, l_id[root_id], l, mid), r_id[root_id]);\n \
    \       } else {\n            return newparent(l_id[root_id], set_query(i, x,\
    \ r_id[root_id], mid, r));\n        }\n    }\n\n    S prod_query(int a, int b,\
    \ int root_id, int l = 0, int r = -1) {\n        if (r == -1) r = n;\n       \
    \ if (r <= a or b <= l) return e();\n        if (a <= l and r <= b) return node[root_id];\n\
    \        int mid = (l + r) >> 1;\n        return op(prod_query(a, b, l_id[root_id],\
    \ l, mid), prod_query(a, b, r_id[root_id], mid, r));\n    }\n\n    int rollback_query(int\
    \ a, int b, int root, int old_root, int l = 0, int r = -1) {\n        if (r ==\
    \ -1) r = n;\n        if (r <= a or b <= l) return root;\n        if (a <= l and\
    \ r <= b) return old_root;\n        return newparent(rollback_query(a, b, l_id[root],\
    \ l_id[old_root], l, (l + r) >> 1), rollback_query(a, b, r_id[root], r_id[old_root],\
    \ (l + r) >> 1, r));\n    }\n\n   public:\n    persistent_segtree() {}\n    persistent_segtree(const\
    \ vector<S> &v) {\n        node.resize(NODE_SIZE);\n        l_id.resize(NODE_SIZE);\n\
    \        r_id.resize(NODE_SIZE);\n        n = v.size();\n        root = build(v,\
    \ 0, n);\n    }\n\n    int replace(const vector<S>& v) {\n        return build(v,\
    \ 0, int(v.size()));\n    }\n\n    int get_root() {\n        return root;\n  \
    \  }\n\n    int set(int p, S x, int root_id) {\n        return set_query(p, x,\
    \ root_id, 0, n);\n    }\n\n    S prod(int l, int r, int root_id) {\n        return\
    \ prod_query(l, r, root_id);\n    }\n\n    S get(int p, int root_id) {\n     \
    \   return prod(p, p + 1, root_id);\n    }\n\n    int rollback(int a, int b, int\
    \ root_id, int old_root) {\n        return rollback_query(a, b, root_id, old_root,\
    \ 0, n);\n    }\n\n    vector<S> status(int root_id) {\n        vector<S> res(n);\n\
    \        for (int i = 0; i < n; i++) {\n            res[i] = get(i, root_id);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "template <class S, auto op, auto e>\nclass persistent_segtree {\n   private:\n\
    \    vector<S> node;\n    vector<int> l_id, r_id;\n    int id = 0;\n    int n,\
    \ root;\n    int NODE_SIZE = 20000000;\n\n    inline int newleaf(S x) {\n    \
    \    int pos = id++;\n        node[pos] = x;\n        return pos;\n    }\n\n \
    \   inline int newparent(int l, int r) {\n        int pos = id++;\n        l_id[pos]\
    \ = l;\n        r_id[pos] = r;\n        node[pos] = op(node[l], node[r]);\n  \
    \      return pos;\n    }\n\n    int build(const vector<S> &v, int l, int r) {\n\
    \        if (r - l == 1) {\n            return newleaf(v[l]);\n        } else\
    \ {\n            return newparent(build(v, l, (l + r) >> 1), build(v, (l + r)\
    \ >> 1, r));\n        }\n    }\n\n    int set_query(int i, S x, int root_id, int\
    \ l, int r) {\n        if (r - l == 1) {\n            return newleaf(x);\n   \
    \     }\n        int mid = (l + r) >> 1;\n        if (i < mid) {\n           \
    \ return newparent(set_query(i, x, l_id[root_id], l, mid), r_id[root_id]);\n \
    \       } else {\n            return newparent(l_id[root_id], set_query(i, x,\
    \ r_id[root_id], mid, r));\n        }\n    }\n\n    S prod_query(int a, int b,\
    \ int root_id, int l = 0, int r = -1) {\n        if (r == -1) r = n;\n       \
    \ if (r <= a or b <= l) return e();\n        if (a <= l and r <= b) return node[root_id];\n\
    \        int mid = (l + r) >> 1;\n        return op(prod_query(a, b, l_id[root_id],\
    \ l, mid), prod_query(a, b, r_id[root_id], mid, r));\n    }\n\n    int rollback_query(int\
    \ a, int b, int root, int old_root, int l = 0, int r = -1) {\n        if (r ==\
    \ -1) r = n;\n        if (r <= a or b <= l) return root;\n        if (a <= l and\
    \ r <= b) return old_root;\n        return newparent(rollback_query(a, b, l_id[root],\
    \ l_id[old_root], l, (l + r) >> 1), rollback_query(a, b, r_id[root], r_id[old_root],\
    \ (l + r) >> 1, r));\n    }\n\n   public:\n    persistent_segtree() {}\n    persistent_segtree(const\
    \ vector<S> &v) {\n        node.resize(NODE_SIZE);\n        l_id.resize(NODE_SIZE);\n\
    \        r_id.resize(NODE_SIZE);\n        n = v.size();\n        root = build(v,\
    \ 0, n);\n    }\n\n    int replace(const vector<S>& v) {\n        return build(v,\
    \ 0, int(v.size()));\n    }\n\n    int get_root() {\n        return root;\n  \
    \  }\n\n    int set(int p, S x, int root_id) {\n        return set_query(p, x,\
    \ root_id, 0, n);\n    }\n\n    S prod(int l, int r, int root_id) {\n        return\
    \ prod_query(l, r, root_id);\n    }\n\n    S get(int p, int root_id) {\n     \
    \   return prod(p, p + 1, root_id);\n    }\n\n    int rollback(int a, int b, int\
    \ root_id, int old_root) {\n        return rollback_query(a, b, root_id, old_root,\
    \ 0, n);\n    }\n\n    vector<S> status(int root_id) {\n        vector<S> res(n);\n\
    \        for (int i = 0; i < n; i++) {\n            res[i] = get(i, root_id);\n\
    \        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/PersistentSegmentTree.hpp
  requiredBy: []
  timestamp: '2026-04-17 01:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segment-tree/PersistentSegmentTree.hpp
layout: document
title: Persistent Segment Tree
---

## 概要

永続セグメント木

## コンストラクタ

```cpp
persistent_segtree<S, op, e>(const vector<S>& v)
```

長さ `n = v.size()` の永続セグメント木を構築する。`v` の内容が初期値となる。

### 制約
-  $1 \leq n$
- `S` はモノイド
- `op` は `S` 上の二項演算
- `e()` は `op` の単位元

### 計算量
- $O(n)$

## replace

```cpp
int seg.replace(const vector<S>& v)
```

$i$ 番目の要素を `v[i]` とした新しいバージョンのidを返す。

### 制約
- `v.size()` は構築時の配列の長さと等しい

### 計算量
- $O(n)$

## get_root

```cpp
int seg.get_root()
```

初期バージョン（構築時の配列）に対応するidを返す。

### 計算量
- $O(1)$

## set

```cpp
int seg.set(int p, S x, int root_id)
```

バージョン `root_id` において `seg[p] = x` とした新しいバージョンのidを返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## prod

```cpp
S seg.prod(int l, int r, int root_id)
```

バージョン `root_id` における区間 $[l, r)$ の総積 `op(seg[l], ..., seg[r - 1])` を返す。`l = r` のときは `e()` を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$

## get

```cpp
S seg.get(int p, int root_id)
```

バージョン `root_id` における `seg[p]` を返す。

### 制約
- $0 \leq p < n$

### 計算量
- $O(\log n)$

## rollback

```cpp
int seg.rollback(int a, int b, int root_id, int old_root)
```

バージョン `root_id` において、区間 $[a, b)$ を バージョン `old_root` の同区間で置き換えたときの新しいバージョンを返す。

### 制約
- $0 \leq a \leq b \leq n$

### 計算量
- $O(\log n)$

## status

```cpp
vector<S> seg.status(int root_id)
```

バージョン `root_id` に対応する数列を返す。

### 計算量
- $O(n \log n)$

## 参考文献

[Persistence Made Simple - Tutorial](https://discuss.codechef.com/t/persistence-made-simple-tutorial/14915)
