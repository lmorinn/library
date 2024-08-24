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
  bundledCode: "#line 2 \"data-structure/balanced-binary-search-tree/ReversibleLazySplayTree.hpp\"\
    \ntemplate <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id>\nstruct SplayTree {\n   private:\n    struct Node {\n        Node *l\
    \ = 0;\n        Node *r = 0;\n        Node *p = 0;\n        // \u5024\u3001\u96C6\
    \u7D04\u5024\u3001\u4F5C\u7528\u5024\n        S val = e();\n        S acc = e();\n\
    \        F lazy = id();\n        int idx = -1;\n        int z = 0;\n        int\
    \ sumz = 0;\n        bool rev = 0;\n    };\n\n    using pNode = unique_ptr<Node>;\n\
    \    pNode pNIL;\n    Node *NIL = nullptr;\n    vector<pNode> A;\n    Node *R;\n\
    \n    void push(Node *v) {\n        if (v->l != NIL) {\n            v->l->val\
    \ = mapping(v->lazy, v->l->val);\n            v->l->acc = mapping(v->lazy, v->l->acc);\n\
    \            v->l->lazy = composition(v->lazy, v->l->lazy);\n        }\n     \
    \   if (v->r != NIL) {\n            v->r->val = mapping(v->lazy, v->r->val);\n\
    \            v->r->acc = mapping(v->lazy, v->r->acc);\n            v->r->lazy\
    \ = composition(v->lazy, v->r->lazy);\n        }\n        if (v->rev) {\n    \
    \        swap(v->l, v->r);\n            if (v->l != NIL) v->l->rev ^= 1;\n   \
    \         if (v->r != NIL) v->r->rev ^= 1;\n\n            v->rev = 0;\n      \
    \  }\n        v->lazy = id();\n    }\n\n    void update(Node *v) {\n        v->sumz\
    \ = v->l->sumz + v->r->sumz + 1;\n        v->acc = op(op(v->l->acc, v->val), v->r->acc);\n\
    \    }\n\n    Node *&parentchild(Node *v) {\n        if (v->p == NIL) return R;\n\
    \        if (v->p->l == v) {\n            return v->p->l;\n        } else {\n\
    \            return v->p->r;\n        }\n    }\n\n    void rotL(Node *v) {\n \
    \       Node *p = v->p;\n        parentchild(p) = v;\n        v->p = p->p;\n \
    \       p->p = v;\n        if (v->l != NIL) v->l->p = p;\n        p->r = v->l;\n\
    \        v->l = p;\n    }\n\n    void rotR(Node *v) {\n        Node *p = v->p;\n\
    \        parentchild(p) = v;\n        v->p = p->p;\n        p->p = v;\n      \
    \  if (v->r != NIL) v->r->p = p;\n        p->l = v->r;\n        v->r = p;\n  \
    \  }\n\n    void splay(Node *v) {\n        push(v);\n        while (v->p != NIL)\
    \ {\n            Node *p = v->p;\n            Node *pp = p->p;\n            if\
    \ (pp != NIL) push(pp);\n            if (p != NIL) push(p);\n            push(v);\n\
    \n            // zig zag\n            if (p->l == v) {\n                if (pp\
    \ == NIL) {\n                    rotR(v);\n                } else if (pp->l ==\
    \ p) {\n                    rotR(p);\n                    rotR(v);\n         \
    \       } else if (pp->r == p) {\n                    rotR(v);\n             \
    \       rotL(v);\n                }\n            } else {\n                if\
    \ (pp == NIL) {\n                    rotL(v);\n                } else if (pp->r\
    \ == p) {\n                    rotL(p);\n                    rotL(v);\n      \
    \          } else if (pp->l == p) {\n                    rotL(v);\n          \
    \          rotR(v);\n                }\n            }\n\n            if (pp !=\
    \ NIL) update(pp);\n            if (p != NIL) update(p);\n            update(v);\n\
    \        }\n        update(v);\n    }\n\n    Node *access(int k) {\n        Node\
    \ *c = R;\n        while (true) {\n            push(c);\n            if (c->l->sumz\
    \ == k) break;\n            if (c->l->sumz > k) {\n                c = c->l;\n\
    \                continue;\n            }\n            k -= c->l->sumz + 1;\n\
    \            c = c->r;\n        }\n        push(c);\n        splay(c);\n     \
    \   return c;\n    }\n\n    Node *between(int l, int r) {\n        if (l == 0\
    \ and r == R->sumz) return R;\n        if (l == 0) return access(r)->l;\n    \
    \    if (r == R->sumz) return access(l - 1)->r;\n        auto rp = access(r);\n\
    \        auto lp = rp->l;\n        R = lp;\n        lp->p = NIL;\n        lp =\
    \ access(l - 1);\n        R = rp;\n        rp->l = lp;\n        lp->p = rp;\n\
    \        update(rp);\n        return lp->r;\n    }\n\n   public:\n    // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    SplayTree() {\n        if (!pNIL) {\n\
    \            pNIL = make_unique<Node>();\n            NIL = pNIL.get();\n    \
    \        NIL->l = NIL->r = NIL->p = NIL;\n            R = NIL;\n        }\n  \
    \  }\n\n    // \u5DE6\u304B\u3089k-1\u756A\u76EE\u306E\u8981\u7D20\u306E\u3059\
    \u3050\u53F3\u5074\u306B\u8981\u7D20x\u3092\u633F\u5165\u3059\u308B\uFF080-indexed\uFF09\
    \n    void insert_at(int k, S x) {\n        pNode pnx = make_unique<Node>(*NIL);\n\
    \        Node *nx = pnx.get();\n        nx->z = nx->sumz = 1;\n        nx->idx\
    \ = A.size();\n        nx->val = nx->acc = x;\n        A.emplace_back(move(pnx));\n\
    \        if (k == 0) {\n            nx->r = R;\n            if (R != NIL) R->p\
    \ = nx;\n            R = nx;\n            update(nx);\n            return;\n \
    \       }\n        if (k == R->sumz) {\n            nx->l = R;\n            if\
    \ (R != NIL) R->p = nx;\n            R = nx;\n            update(nx);\n      \
    \      return;\n        }\n        auto p = access(k);\n        nx->l = p->l;\n\
    \        nx->r = p;\n        R = nx;\n        p->l->p = nx;\n        p->p = nx;\n\
    \        p->l = NIL;\n        update(p);\n        update(nx);\n    }\n\n    //\
    \ \u5DE6\u304B\u3089k\u756A\u76EE\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\
    \ (0-indexed)\n    void erase_at(int k) {\n        auto p = access(k);\n     \
    \   if (k == 0) {\n            R = p->r;\n            if (R != NIL) R->p = NIL;\n\
    \        } else if (k == R->sumz - 1) {\n            R = p->l;\n            if\
    \ (R != NIL) R->p = NIL;\n        } else {\n            auto l = p->l;\n     \
    \       auto r = p->r;\n            r->p = NIL;\n            R = r;\n        \
    \    access(0);\n            r = R;\n            r->l = l;\n            l->p =\
    \ r;\n            update(r);\n        }\n        swap(p->idx, A.back()->idx);\n\
    \        swap(A[p->idx], A[A.back()->idx]);\n        A.pop_back();\n    }\n\n\
    \    // [l,r)\u306E\u533A\u9593\u3092\u53CD\u8EE2\n    void reverse(int l, int\
    \ r) {\n        auto c = between(l, r);\n        c->rev ^= 1;\n        splay(c);\n\
    \    }\n\n    // [l,r)\u306E\u533A\u9593\u306Bf\u3092\u4F5C\u7528\n    void apply(int\
    \ l, int r, F f) {\n        auto c = between(l, r);\n        c->val = mapping(f,\
    \ c->val);\n        c->acc = mapping(f, c->acc);\n        c->lazy = composition(f,\
    \ c->lazy);\n        splay(c);\n    }\n\n    // [l,r)\u306E\u533A\u9593\u306E\u7DCF\
    \u7A4D\n    S prod(int l, int r) {\n        return between(l, r)->acc;\n    }\n\
    \n    // \u6DFB\u5B57\u30A2\u30AF\u30BB\u30B9\n    S operator[](int k) {\n   \
    \     return access(k)->val;\n    }\n};\n"
  code: "#pragma once\ntemplate <class S, auto op, auto e, class F, auto mapping,\
    \ auto composition, auto id>\nstruct SplayTree {\n   private:\n    struct Node\
    \ {\n        Node *l = 0;\n        Node *r = 0;\n        Node *p = 0;\n      \
    \  // \u5024\u3001\u96C6\u7D04\u5024\u3001\u4F5C\u7528\u5024\n        S val =\
    \ e();\n        S acc = e();\n        F lazy = id();\n        int idx = -1;\n\
    \        int z = 0;\n        int sumz = 0;\n        bool rev = 0;\n    };\n\n\
    \    using pNode = unique_ptr<Node>;\n    pNode pNIL;\n    Node *NIL = nullptr;\n\
    \    vector<pNode> A;\n    Node *R;\n\n    void push(Node *v) {\n        if (v->l\
    \ != NIL) {\n            v->l->val = mapping(v->lazy, v->l->val);\n          \
    \  v->l->acc = mapping(v->lazy, v->l->acc);\n            v->l->lazy = composition(v->lazy,\
    \ v->l->lazy);\n        }\n        if (v->r != NIL) {\n            v->r->val =\
    \ mapping(v->lazy, v->r->val);\n            v->r->acc = mapping(v->lazy, v->r->acc);\n\
    \            v->r->lazy = composition(v->lazy, v->r->lazy);\n        }\n     \
    \   if (v->rev) {\n            swap(v->l, v->r);\n            if (v->l != NIL)\
    \ v->l->rev ^= 1;\n            if (v->r != NIL) v->r->rev ^= 1;\n\n          \
    \  v->rev = 0;\n        }\n        v->lazy = id();\n    }\n\n    void update(Node\
    \ *v) {\n        v->sumz = v->l->sumz + v->r->sumz + 1;\n        v->acc = op(op(v->l->acc,\
    \ v->val), v->r->acc);\n    }\n\n    Node *&parentchild(Node *v) {\n        if\
    \ (v->p == NIL) return R;\n        if (v->p->l == v) {\n            return v->p->l;\n\
    \        } else {\n            return v->p->r;\n        }\n    }\n\n    void rotL(Node\
    \ *v) {\n        Node *p = v->p;\n        parentchild(p) = v;\n        v->p =\
    \ p->p;\n        p->p = v;\n        if (v->l != NIL) v->l->p = p;\n        p->r\
    \ = v->l;\n        v->l = p;\n    }\n\n    void rotR(Node *v) {\n        Node\
    \ *p = v->p;\n        parentchild(p) = v;\n        v->p = p->p;\n        p->p\
    \ = v;\n        if (v->r != NIL) v->r->p = p;\n        p->l = v->r;\n        v->r\
    \ = p;\n    }\n\n    void splay(Node *v) {\n        push(v);\n        while (v->p\
    \ != NIL) {\n            Node *p = v->p;\n            Node *pp = p->p;\n     \
    \       if (pp != NIL) push(pp);\n            if (p != NIL) push(p);\n       \
    \     push(v);\n\n            // zig zag\n            if (p->l == v) {\n     \
    \           if (pp == NIL) {\n                    rotR(v);\n                }\
    \ else if (pp->l == p) {\n                    rotR(p);\n                    rotR(v);\n\
    \                } else if (pp->r == p) {\n                    rotR(v);\n    \
    \                rotL(v);\n                }\n            } else {\n         \
    \       if (pp == NIL) {\n                    rotL(v);\n                } else\
    \ if (pp->r == p) {\n                    rotL(p);\n                    rotL(v);\n\
    \                } else if (pp->l == p) {\n                    rotL(v);\n    \
    \                rotR(v);\n                }\n            }\n\n            if\
    \ (pp != NIL) update(pp);\n            if (p != NIL) update(p);\n            update(v);\n\
    \        }\n        update(v);\n    }\n\n    Node *access(int k) {\n        Node\
    \ *c = R;\n        while (true) {\n            push(c);\n            if (c->l->sumz\
    \ == k) break;\n            if (c->l->sumz > k) {\n                c = c->l;\n\
    \                continue;\n            }\n            k -= c->l->sumz + 1;\n\
    \            c = c->r;\n        }\n        push(c);\n        splay(c);\n     \
    \   return c;\n    }\n\n    Node *between(int l, int r) {\n        if (l == 0\
    \ and r == R->sumz) return R;\n        if (l == 0) return access(r)->l;\n    \
    \    if (r == R->sumz) return access(l - 1)->r;\n        auto rp = access(r);\n\
    \        auto lp = rp->l;\n        R = lp;\n        lp->p = NIL;\n        lp =\
    \ access(l - 1);\n        R = rp;\n        rp->l = lp;\n        lp->p = rp;\n\
    \        update(rp);\n        return lp->r;\n    }\n\n   public:\n    // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    SplayTree() {\n        if (!pNIL) {\n\
    \            pNIL = make_unique<Node>();\n            NIL = pNIL.get();\n    \
    \        NIL->l = NIL->r = NIL->p = NIL;\n            R = NIL;\n        }\n  \
    \  }\n\n    // \u5DE6\u304B\u3089k-1\u756A\u76EE\u306E\u8981\u7D20\u306E\u3059\
    \u3050\u53F3\u5074\u306B\u8981\u7D20x\u3092\u633F\u5165\u3059\u308B\uFF080-indexed\uFF09\
    \n    void insert_at(int k, S x) {\n        pNode pnx = make_unique<Node>(*NIL);\n\
    \        Node *nx = pnx.get();\n        nx->z = nx->sumz = 1;\n        nx->idx\
    \ = A.size();\n        nx->val = nx->acc = x;\n        A.emplace_back(move(pnx));\n\
    \        if (k == 0) {\n            nx->r = R;\n            if (R != NIL) R->p\
    \ = nx;\n            R = nx;\n            update(nx);\n            return;\n \
    \       }\n        if (k == R->sumz) {\n            nx->l = R;\n            if\
    \ (R != NIL) R->p = nx;\n            R = nx;\n            update(nx);\n      \
    \      return;\n        }\n        auto p = access(k);\n        nx->l = p->l;\n\
    \        nx->r = p;\n        R = nx;\n        p->l->p = nx;\n        p->p = nx;\n\
    \        p->l = NIL;\n        update(p);\n        update(nx);\n    }\n\n    //\
    \ \u5DE6\u304B\u3089k\u756A\u76EE\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\
    \ (0-indexed)\n    void erase_at(int k) {\n        auto p = access(k);\n     \
    \   if (k == 0) {\n            R = p->r;\n            if (R != NIL) R->p = NIL;\n\
    \        } else if (k == R->sumz - 1) {\n            R = p->l;\n            if\
    \ (R != NIL) R->p = NIL;\n        } else {\n            auto l = p->l;\n     \
    \       auto r = p->r;\n            r->p = NIL;\n            R = r;\n        \
    \    access(0);\n            r = R;\n            r->l = l;\n            l->p =\
    \ r;\n            update(r);\n        }\n        swap(p->idx, A.back()->idx);\n\
    \        swap(A[p->idx], A[A.back()->idx]);\n        A.pop_back();\n    }\n\n\
    \    // [l,r)\u306E\u533A\u9593\u3092\u53CD\u8EE2\n    void reverse(int l, int\
    \ r) {\n        auto c = between(l, r);\n        c->rev ^= 1;\n        splay(c);\n\
    \    }\n\n    // [l,r)\u306E\u533A\u9593\u306Bf\u3092\u4F5C\u7528\n    void apply(int\
    \ l, int r, F f) {\n        auto c = between(l, r);\n        c->val = mapping(f,\
    \ c->val);\n        c->acc = mapping(f, c->acc);\n        c->lazy = composition(f,\
    \ c->lazy);\n        splay(c);\n    }\n\n    // [l,r)\u306E\u533A\u9593\u306E\u7DCF\
    \u7A4D\n    S prod(int l, int r) {\n        return between(l, r)->acc;\n    }\n\
    \n    // \u6DFB\u5B57\u30A2\u30AF\u30BB\u30B9\n    S operator[](int k) {\n   \
    \     return access(k)->val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/balanced-binary-search-tree/ReversibleLazySplayTree.hpp
  requiredBy: []
  timestamp: '2024-08-24 16:53:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/balanced-binary-search-tree/ReversibleLazySplayTree.hpp
layout: document
title: Reversible Lazy Splay Tree
---

## 概要

todo

## 計算量
todo