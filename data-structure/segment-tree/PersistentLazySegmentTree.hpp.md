---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LibraryChecker/data-structure/segment-tree/PersistentRangeAffineRangeSum.test.cpp
    title: verify/LibraryChecker/data-structure/segment-tree/PersistentRangeAffineRangeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree/PersistentLazySegmentTree.hpp\"\
    \n\ntemplate <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id>\nclass persistent_lazy_segtree {\n   private:\n    vector<S> node;\n\
    \    vector<F> lazy;\n\n    vector<int> l_id, r_id;\n    int idx = 0;\n    int\
    \ n, root;\n    int NODE_SIZE = 45000000;\n\n    inline int newleaf(S x) {\n \
    \       int pos = idx++;\n        node[pos] = x;\n        return pos;\n    }\n\
    \n    inline int newparent(int l, int r) {\n        int pos = idx++;\n       \
    \ l_id[pos] = l;\n        r_id[pos] = r;\n        node[pos] = op(node[l], node[r]);\n\
    \        return pos;\n    }\n\n    inline int newlazy(int node_id, F f, int l,\
    \ int r) {\n        int pos = idx++;\n        l_id[pos] = l_id[node_id];\n   \
    \     r_id[pos] = r_id[node_id];\n        lazy[pos] = composition(f, lazy[node_id]);\n\
    \        node[pos] = mapping(f, node[node_id]);\n\n        return pos;\n    }\n\
    \n    inline void push(int root_id, int l, int r) {\n        if (l + 1 < r and\
    \ lazy[root_id] != id()) {\n            l_id[root_id] = newlazy(l_id[root_id],\
    \ lazy[root_id], l, (l + r) >> 1);\n            r_id[root_id] = newlazy(r_id[root_id],\
    \ lazy[root_id], (l + r) >> 1, r);\n            lazy[root_id] = id();\n      \
    \  }\n    }\n\n    int build(const vector<S> &v, int l, int r) {\n        if (r\
    \ - l == 1) {\n            return newleaf(v[l]);\n        } else {\n         \
    \   return newparent(build(v, l, (l + r) >> 1), build(v, (l + r) >> 1, r));\n\
    \        }\n    }\n\n    int set_query(int i, S x, int root_id, int l, int r)\
    \ {\n        if (r - l == 1) {\n            return newleaf(x);\n        }\n  \
    \      int mid = (l + r) >> 1;\n        if (i < mid) {\n            return newparent(set_query(i,\
    \ x, l_id[root_id], l, mid), r_id[root_id]);\n        } else {\n            return\
    \ newparent(l_id[root_id], set_query(i, x, r_id[root_id], mid, r));\n        }\n\
    \    }\n\n    int apply_query(int a, int b, F f, int root_id, int l = 0, int r\
    \ = -1) {\n        if (r == -1) r = n;\n        if (r <= a or b <= l) return root_id;\n\
    \        if (a <= l and r <= b) return newlazy(root_id, f, l, r);\n        push(root_id,\
    \ l, r);\n        int mid = (l + r) >> 1;\n        return newparent(apply_query(a,\
    \ b, f, l_id[root_id], l, mid), apply_query(a, b, f, r_id[root_id], mid, r));\n\
    \    }\n\n    S prod_query(int a, int b, int root_id, int l = 0, int r = -1) {\n\
    \        if (r == -1) r = n;\n        if (r <= a or b <= l) return e();\n    \
    \    if (a <= l and r <= b) return node[root_id];\n        push(root_id, l, r);\n\
    \        int mid = (l + r) >> 1;\n        return op(prod_query(a, b, l_id[root_id],\
    \ l, mid), prod_query(a, b, r_id[root_id], mid, r));\n    }\n\n    S get_query(int\
    \ i, int root_id, int l = 0, int r = -1) {\n        if (r == -1) r = n;\n    \
    \    if (r - l == 1) return node[root_id];\n        push(root_id, l, r);\n\n \
    \       int mid = (l + r) >> 1;\n        if (i < mid) {\n            return get_query(i,\
    \ l_id[root_id], l, mid);\n        } else {\n            return get_query(i, r_id[root_id],\
    \ mid, r);\n        }\n    }\n\n    int rollback_query(int a, int b, int root,\
    \ int old_root, int l = 0, int r = -1) {\n        if (r == -1) r = n;\n      \
    \  if (r <= a or b <= l) return root;\n        if (a <= l and r <= b) return old_root;\n\
    \        push(root, l, r);\n        push(old_root, l, r);\n        return newparent(rollback_query(a,\
    \ b, l_id[root], l_id[old_root], l, (l + r) >> 1), rollback_query(a, b, r_id[root],\
    \ r_id[old_root], (l + r) >> 1, r));\n    }\n\n   public:\n    persistent_lazy_segtree()\
    \ {}\n    persistent_lazy_segtree(const vector<S> &v) {\n        node.resize(NODE_SIZE);\n\
    \        lazy.resize(NODE_SIZE, id());\n        l_id.resize(NODE_SIZE);\n    \
    \    r_id.resize(NODE_SIZE);\n        n = v.size();\n        root = build(v, 0,\
    \ n);\n    }\n\n    int get_root() {\n        return root;\n    }\n\n    int set(int\
    \ p, S x, int root_id) {\n        return set_query(p, x, root_id, 0, n);\n   \
    \ }\n\n    int apply(int l, int r, F f, int root_id) {\n        return apply_query(l,\
    \ r, f, root_id, 0, n);\n    }\n\n    S prod(int l, int r, int root_id) {\n  \
    \      return prod_query(l, r, root_id);\n    }\n\n    S get(int p, int root_id)\
    \ {\n        return get_query(p, root_id);\n    }\n\n    int rollback(int a, int\
    \ b, int root_id, int old_root) {\n        return rollback_query(a, b, root_id,\
    \ old_root, 0, n);\n    }\n\n    vector<S> status(int root_id) {\n        vector<S>\
    \ res(n);\n\n        for (int i = 0; i < n; i++) {\n            res[i] = get(i,\
    \ root_id);\n        }\n        return res;\n    }\n};\n"
  code: "\ntemplate <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id>\nclass persistent_lazy_segtree {\n   private:\n    vector<S> node;\n\
    \    vector<F> lazy;\n\n    vector<int> l_id, r_id;\n    int idx = 0;\n    int\
    \ n, root;\n    int NODE_SIZE = 45000000;\n\n    inline int newleaf(S x) {\n \
    \       int pos = idx++;\n        node[pos] = x;\n        return pos;\n    }\n\
    \n    inline int newparent(int l, int r) {\n        int pos = idx++;\n       \
    \ l_id[pos] = l;\n        r_id[pos] = r;\n        node[pos] = op(node[l], node[r]);\n\
    \        return pos;\n    }\n\n    inline int newlazy(int node_id, F f, int l,\
    \ int r) {\n        int pos = idx++;\n        l_id[pos] = l_id[node_id];\n   \
    \     r_id[pos] = r_id[node_id];\n        lazy[pos] = composition(f, lazy[node_id]);\n\
    \        node[pos] = mapping(f, node[node_id]);\n\n        return pos;\n    }\n\
    \n    inline void push(int root_id, int l, int r) {\n        if (l + 1 < r and\
    \ lazy[root_id] != id()) {\n            l_id[root_id] = newlazy(l_id[root_id],\
    \ lazy[root_id], l, (l + r) >> 1);\n            r_id[root_id] = newlazy(r_id[root_id],\
    \ lazy[root_id], (l + r) >> 1, r);\n            lazy[root_id] = id();\n      \
    \  }\n    }\n\n    int build(const vector<S> &v, int l, int r) {\n        if (r\
    \ - l == 1) {\n            return newleaf(v[l]);\n        } else {\n         \
    \   return newparent(build(v, l, (l + r) >> 1), build(v, (l + r) >> 1, r));\n\
    \        }\n    }\n\n    int set_query(int i, S x, int root_id, int l, int r)\
    \ {\n        if (r - l == 1) {\n            return newleaf(x);\n        }\n  \
    \      int mid = (l + r) >> 1;\n        if (i < mid) {\n            return newparent(set_query(i,\
    \ x, l_id[root_id], l, mid), r_id[root_id]);\n        } else {\n            return\
    \ newparent(l_id[root_id], set_query(i, x, r_id[root_id], mid, r));\n        }\n\
    \    }\n\n    int apply_query(int a, int b, F f, int root_id, int l = 0, int r\
    \ = -1) {\n        if (r == -1) r = n;\n        if (r <= a or b <= l) return root_id;\n\
    \        if (a <= l and r <= b) return newlazy(root_id, f, l, r);\n        push(root_id,\
    \ l, r);\n        int mid = (l + r) >> 1;\n        return newparent(apply_query(a,\
    \ b, f, l_id[root_id], l, mid), apply_query(a, b, f, r_id[root_id], mid, r));\n\
    \    }\n\n    S prod_query(int a, int b, int root_id, int l = 0, int r = -1) {\n\
    \        if (r == -1) r = n;\n        if (r <= a or b <= l) return e();\n    \
    \    if (a <= l and r <= b) return node[root_id];\n        push(root_id, l, r);\n\
    \        int mid = (l + r) >> 1;\n        return op(prod_query(a, b, l_id[root_id],\
    \ l, mid), prod_query(a, b, r_id[root_id], mid, r));\n    }\n\n    S get_query(int\
    \ i, int root_id, int l = 0, int r = -1) {\n        if (r == -1) r = n;\n    \
    \    if (r - l == 1) return node[root_id];\n        push(root_id, l, r);\n\n \
    \       int mid = (l + r) >> 1;\n        if (i < mid) {\n            return get_query(i,\
    \ l_id[root_id], l, mid);\n        } else {\n            return get_query(i, r_id[root_id],\
    \ mid, r);\n        }\n    }\n\n    int rollback_query(int a, int b, int root,\
    \ int old_root, int l = 0, int r = -1) {\n        if (r == -1) r = n;\n      \
    \  if (r <= a or b <= l) return root;\n        if (a <= l and r <= b) return old_root;\n\
    \        push(root, l, r);\n        push(old_root, l, r);\n        return newparent(rollback_query(a,\
    \ b, l_id[root], l_id[old_root], l, (l + r) >> 1), rollback_query(a, b, r_id[root],\
    \ r_id[old_root], (l + r) >> 1, r));\n    }\n\n   public:\n    persistent_lazy_segtree()\
    \ {}\n    persistent_lazy_segtree(const vector<S> &v) {\n        node.resize(NODE_SIZE);\n\
    \        lazy.resize(NODE_SIZE, id());\n        l_id.resize(NODE_SIZE);\n    \
    \    r_id.resize(NODE_SIZE);\n        n = v.size();\n        root = build(v, 0,\
    \ n);\n    }\n\n    int get_root() {\n        return root;\n    }\n\n    int set(int\
    \ p, S x, int root_id) {\n        return set_query(p, x, root_id, 0, n);\n   \
    \ }\n\n    int apply(int l, int r, F f, int root_id) {\n        return apply_query(l,\
    \ r, f, root_id, 0, n);\n    }\n\n    S prod(int l, int r, int root_id) {\n  \
    \      return prod_query(l, r, root_id);\n    }\n\n    S get(int p, int root_id)\
    \ {\n        return get_query(p, root_id);\n    }\n\n    int rollback(int a, int\
    \ b, int root_id, int old_root) {\n        return rollback_query(a, b, root_id,\
    \ old_root, 0, n);\n    }\n\n    vector<S> status(int root_id) {\n        vector<S>\
    \ res(n);\n\n        for (int i = 0; i < n; i++) {\n            res[i] = get(i,\
    \ root_id);\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/PersistentLazySegmentTree.hpp
  requiredBy: []
  timestamp: '2024-12-16 04:24:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LibraryChecker/data-structure/segment-tree/PersistentRangeAffineRangeSum.test.cpp
documentation_of: data-structure/segment-tree/PersistentLazySegmentTree.hpp
layout: document
title: Persistent Lazy Segment Tree
---

## 概要

todo

## 計算量
todo