---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dynamic-tree/LinkCutTreeEdge.hpp
    title: Link Cut Tree (Edge)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dynamic-tree/LinkCutTreeEdge.hpp\"\nstruct S {\n \
    \   unsigned long long val;\n    int u, v;\n};\nusing F = unsigned long long;\n\
    struct LinkCutTree {\n   private:\n    static S op(S a, S b) {\n        if (a.val\
    \ > b.val) {\n            return a;\n        } else {\n            return b;\n\
    \        }\n    }\n    static S e() {\n        return {0, -1, -1};\n    }\n\n\
    \    // \u53CD\u8EE2\u306E\u51E6\u7406\n    // \u5165\u529B\u6642\u306Bb2\u306E\
    \u5165\u529B\u3092\u5FD8\u308C\u306A\u3044\n    // \u4E00\u6B21\u95A2\u6570\u306E\
    \u5408\u6210\u306A\u3089,b1\u3068b2\u3092swap\n    static void reverseprod(S &x)\
    \ {\n    }\n\n    static S mapping(F f, S x) {\n        return x;\n    }\n   \
    \ static F composition(F f, F x) {\n        return x;\n    }\n    static F id()\
    \ {\n        return 0;\n    }\n\n    struct Node {\n        Node *l = 0;\n   \
    \     Node *r = 0;\n        Node *p = 0;\n        Node *pp = 0;\n        // \u5024\
    \u3001\u96C6\u7D04\u5024\u3001\u4F5C\u7528\u5024\n        S val = e();\n     \
    \   S acc = e();\n        F lazy = id();\n        int idx = -1;\n        int z\
    \ = 0;\n        int sumz = 0;\n        int w = 0;\n        int sumw = 0;\n   \
    \     bool rev = 0;\n        int u = -1;\n        int v = -1;\n    };\n\n    using\
    \ pNode = shared_ptr<Node>;\n    pNode pNIL;\n    Node *NIL = nullptr;\n    vector<pNode>\
    \ A;\n    vector<unordered_map<int, Node *>> ed;\n    queue<int> unused;\n\n \
    \   void push(Node *v) {\n        if (v->l != NIL) {\n            v->l->val =\
    \ mapping(v->lazy, v->l->val);\n            v->l->acc = mapping(v->lazy, v->l->acc);\n\
    \            v->l->lazy = composition(v->lazy, v->l->lazy);\n        }\n     \
    \   if (v->r != NIL) {\n            v->r->val = mapping(v->lazy, v->r->val);\n\
    \            v->r->acc = mapping(v->lazy, v->r->acc);\n            v->r->lazy\
    \ = composition(v->lazy, v->r->lazy);\n        }\n        if (v->rev) {\n    \
    \        swap(v->l, v->r);\n            if (v->l != NIL) {\n                v->l->rev\
    \ ^= 1;\n                reverseprod(v->l->acc);\n            }\n            if\
    \ (v->r != NIL) {\n                v->r->rev ^= 1;\n                reverseprod(v->r->acc);\n\
    \            }\n            v->rev = 0;\n        }\n        v->lazy = id();\n\
    \    }\n\n    void update(Node *v) {\n        v->sumz = v->l->sumz + v->r->sumz\
    \ + 1;\n        v->sumw = v->l->sumw + v->r->sumw + 1;\n        v->acc = op(op(v->l->acc,\
    \ v->val), v->r->acc);\n    }\n\n    Node *&parentchild(Node *v) {\n        if\
    \ (v->p == NIL) return NIL;\n        if (v->p->l == v) {\n            return v->p->l;\n\
    \        } else {\n            return v->p->r;\n        }\n    }\n\n    Node *at(int\
    \ idx) {\n        return A[idx].get();\n    }\n\n    void rotL(Node *v) {\n  \
    \      Node *p = v->p;\n        if (p->p == NIL) {\n            swap(p->pp, v->pp);\n\
    \        } else {\n            parentchild(p) = v;\n        }\n        v->p =\
    \ p->p;\n        p->p = v;\n        if (v->l != NIL) v->l->p = p;\n        p->r\
    \ = v->l;\n        v->l = p;\n    }\n\n    void rotR(Node *v) {\n        Node\
    \ *p = v->p;\n        if (p->p == NIL) {\n            swap(p->pp, v->pp);\n  \
    \      } else {\n            parentchild(p) = v;\n        }\n        v->p = p->p;\n\
    \        p->p = v;\n        if (v->r != NIL) v->r->p = p;\n        p->l = v->r;\n\
    \        v->r = p;\n    }\n\n    void splay(Node *v) {\n        push(v);\n   \
    \     while (v->p != NIL) {\n            Node *p = v->p;\n            Node *pp\
    \ = p->p;\n            if (pp != NIL) push(pp);\n            push(p);\n      \
    \      push(v);\n\n            // zig zag\n            if (p->l == v) {\n    \
    \            if (pp == NIL) {\n                    rotR(v);\n                }\
    \ else if (pp->l == p) {\n                    rotR(p);\n                    rotR(v);\n\
    \                } else if (pp->r == p) {\n                    rotR(v);\n    \
    \                rotL(v);\n                }\n            } else {\n         \
    \       if (pp == NIL) {\n                    rotL(v);\n                } else\
    \ if (pp->r == p) {\n                    rotL(p);\n                    rotL(v);\n\
    \                } else if (pp->l == p) {\n                    rotL(v);\n    \
    \                rotR(v);\n                }\n            }\n\n            if\
    \ (pp != NIL) update(pp);\n            update(p);\n        }\n        update(v);\n\
    \    }\n\n    void expose(Node *v) {\n        auto p = v;\n        while (p !=\
    \ NIL) {\n            splay(p);\n            p = p->pp;\n        }\n        p\
    \ = v;\n        while (p->pp != NIL) {\n            auto prev = p->pp->r;\n  \
    \          if (prev != NIL) swap(prev->pp, prev->p);\n            swap(p->p, p->pp);\n\
    \            p->p->r = p;\n            p = p->p;\n        }\n        splay(v);\n\
    \    }\n\n    void evert(Node *v) {\n        expose(v);\n        if (v->r != NIL)\
    \ {\n            v->r->pp = v->r->p;\n            v->r->p = NIL;\n           \
    \ v->r = NIL;\n        }\n        v->rev ^= 1;\n        reverseprod(v->acc);\n\
    \        push(v);\n    }\n\n    void link(Node *u, Node *v) {\n        evert(u);\n\
    \        evert(v);\n        if (u->p != NIL or u->pp != NIL) return;\n       \
    \ u->pp = v;\n    }\n\n    void cut(Node *v) {\n        expose(v);\n        if\
    \ (v->l == NIL) return;\n        v->l->p = NIL;\n        v->l = NIL;\n    }\n\n\
    \    Node *between(Node *u, Node *v) {\n        evert(u);\n        expose(v);\n\
    \        push(v->l);\n        return v->l;\n    }\n\n    S prod(Node *u, Node\
    \ *v) {\n        S res = between(u, v)->acc;\n        res = op(res, v->val);\n\
    \        return res;\n    }\n\n    S get(Node *v) {\n        expose(v);\n    \
    \    return v->val;\n    }\n\n    void set(Node *v, S x) {\n        expose(v);\n\
    \        v->val = x;\n        update(v);\n    }\n\n   public:\n    // \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n    LinkCutTree(vector<S> &w) {\n        if (!pNIL)\
    \ {\n            pNIL = make_shared<Node>();\n            NIL = pNIL.get();\n\
    \            NIL->l = NIL->r = NIL->p = NIL->pp = NIL;\n        }\n        int\
    \ n = w.size();\n        A.resize(2 * n + 1);\n        ed.resize(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            A[i] = make_shared<Node>(*NIL);\n\
    \            A[i]->w = A[i]->sumw = 0;\n            A[i]->z = A[i]->sumz = 1;\n\
    \            A[i]->idx = i;\n            A[i]->val = A[i]->acc = w[i];\n     \
    \   }\n\n        for (int i = n; i < n * 2 - 1; i++) {\n            A[i] = make_shared<Node>(*NIL);\n\
    \            A[i]->w = A[i]->sumw = 1;\n            A[i]->z = A[i]->sumz = 0;\n\
    \            A[i]->idx = i;\n            A[i]->val = A[i]->acc = e();\n      \
    \      unused.push(i);\n        }\n    }\n\n    // u,v\u9593\u306E\u30D1\u30B9\
    \u4E0A\u306B\u66F8\u304B\u308C\u305F\u7DCF\u7A4D\n    S prod(int u, int v) {\n\
    \        return prod(at(u), at(v));\n    }\n\n    // \u9802\u70B9idx\u306Bx\u3092\
    \u4EE3\u5165\n    void set(int idx, S x) {\n        set(at(idx), x);\n    }\n\n\
    \    // \u9802\u70B9u\u3068v\u3092\u76F4\u63A5\u7D50\u3076\u8FBA\u306Bx\u3092\u4EE3\
    \u5165\n    void set(int u, int v, S x) {\n        if (u > v) swap(u, v);\n  \
    \      int edidx = ed[u][v]->idx;\n        set(edidx, x);\n    }\n\n    // \u9802\
    \u70B9idx\u306E\u5024\u3092\u53D6\u5F97\n    S get(int idx) {\n        return\
    \ get(at(idx));\n    }\n\n    // \u9802\u70B9u\u3068v\u3092\u76F4\u63A5\u7D50\u3076\
    \u8FBA\u306E\u5024\u3092\u53D6\u5F97\n    S get(int u, int v) {\n        if (u\
    \ > v) swap(u, v);\n        int edidx = ed[u][v]->idx;\n        return get(edidx);\n\
    \    }\n\n    // u\u3068v\u3092\u7D50\u3076\u91CD\u307Fx\u306E\u8FBA\u3092\u8FFD\
    \u52A0\n    void add(int u, int v, int x) {\n        if (u > v) swap(u, v);\n\
    \        int edidx = unused.front();\n        unused.pop();\n        S newedge;\n\
    \        newedge.u = u;\n        newedge.v = v;\n        newedge.val = x;\n  \
    \      Node *edge = A[edidx].get();\n        ed[u][v] = edge;\n        link(at(u),\
    \ at(edidx));\n        link(at(edidx), at(v));\n        set(edidx, newedge);\n\
    \        edge->u = u;\n        edge->v = v;\n    }\n\n    // u\u3068v\u3092\u7D50\
    \u3076\u8FBA\u3092\u524A\u9664\n    void erase(int u, int v) {\n        if (u\
    \ > v) swap(u, v);\n        Node *edge = ed[u][v];\n        int edidx = edge->idx;\n\
    \        unused.push(edidx);\n        set(edidx, e());\n        ed[u].erase(v);\n\
    \        evert(at(u));\n        cut(at(edidx));\n        evert(at(edidx));\n \
    \       cut(at(v));\n        edge->u = -1;\n        edge->v = -1;\n    }\n};\n\
    #line 3 \"graph/connectivity/OfflineDynamicConnectivityLCT.hpp\"\n\ntemplate <class\
    \ R>\nclass offline_dynamic_connectivity {\n private:\n  struct Query {\n    int\
    \ com;\n    int u, v;\n    int pos;\n    int finish;\n  };\n  int Q_INF = 1e8;\n\
    \  int n;\n  LinkCutTree t;\n  vector<map<int, int>> ed;\n  vector<set<int>> msf;\n\
    \  int qtime;\n  vector<Query> q;\n\n public:\n  offline_dynamic_connectivity()\
    \ {}\n\n  offline_dynamic_connectivity(int siz) {\n    vector<S> nodew(siz, {int(1e8),\
    \ -1, -1});\n    t = LinkCutTree(nodew);\n    ed.resize(siz);\n    msf.resize(siz);\n\
    \    qtime = 0;\n  }\n\n  void link(int u, int v) {\n    q.push_back({0, u, v,\
    \ qtime, Q_INF});\n    ed[u][v] = qtime;\n    ed[v][u] = qtime;\n    qtime++;\n\
    \  }\n\n  void cut(int u, int v) {\n    q.push_back({1, u, v, qtime, -1});\n \
    \   int idx = ed[u][v];\n    q[idx].finish = qtime;\n    ed[u].erase(v);\n   \
    \ ed[v].erase(u);\n    qtime++;\n  }\n\n  void is_connected(int u, int v) {\n\
    \    q.push_back({2, u, v, qtime, -1});\n    qtime++;\n  }\n\n  vector<R> build()\
    \ {\n    int u, v, com;\n    vector<R> res;\n    for (int i = 0; i < qtime; i++)\
    \ {\n      com = q[i].com;\n      int u = q[i].u;\n      int v = q[i].v;\n   \
    \   int w = q[i].finish;\n      if (com == 0) {\n        if (!t.is_connected(u,\
    \ v)) {\n          t.add(u, v, w);\n          msf[u].insert(v);\n          msf[v].insert(u);\n\
    \        } else {\n          S path = t.prod(u, v);\n          if (path.val <\
    \ w and path.u != -1 and path.v != -1) {\n            t.erase(path.u, path.v);\n\
    \            t.add(u, v, w);\n            msf[path.u].erase(path.v);\n       \
    \     msf[path.v].erase(path.u);\n            msf[u].insert(v);\n            msf[v].insert(u);\n\
    \          }\n        }\n      } else if (com == 1) {\n        if (msf[u].find(v)\
    \ != msf[u].end()) {\n          int p = t.prod(u, v).val;\n          t.erase(u,\
    \ v);\n          msf[u].erase(v);\n          msf[v].erase(u);\n        }\n   \
    \   } else if (com == 2) {\n        res.emplace_back(t.is_connected(u, v));\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  code: "#pragma once\n#include \"../dynamic-tree/LinkCutTreeEdge.hpp\"\n\ntemplate\
    \ <class R>\nclass offline_dynamic_connectivity {\n private:\n  struct Query {\n\
    \    int com;\n    int u, v;\n    int pos;\n    int finish;\n  };\n  int Q_INF\
    \ = 1e8;\n  int n;\n  LinkCutTree t;\n  vector<map<int, int>> ed;\n  vector<set<int>>\
    \ msf;\n  int qtime;\n  vector<Query> q;\n\n public:\n  offline_dynamic_connectivity()\
    \ {}\n\n  offline_dynamic_connectivity(int siz) {\n    vector<S> nodew(siz, {int(1e8),\
    \ -1, -1});\n    t = LinkCutTree(nodew);\n    ed.resize(siz);\n    msf.resize(siz);\n\
    \    qtime = 0;\n  }\n\n  void link(int u, int v) {\n    q.push_back({0, u, v,\
    \ qtime, Q_INF});\n    ed[u][v] = qtime;\n    ed[v][u] = qtime;\n    qtime++;\n\
    \  }\n\n  void cut(int u, int v) {\n    q.push_back({1, u, v, qtime, -1});\n \
    \   int idx = ed[u][v];\n    q[idx].finish = qtime;\n    ed[u].erase(v);\n   \
    \ ed[v].erase(u);\n    qtime++;\n  }\n\n  void is_connected(int u, int v) {\n\
    \    q.push_back({2, u, v, qtime, -1});\n    qtime++;\n  }\n\n  vector<R> build()\
    \ {\n    int u, v, com;\n    vector<R> res;\n    for (int i = 0; i < qtime; i++)\
    \ {\n      com = q[i].com;\n      int u = q[i].u;\n      int v = q[i].v;\n   \
    \   int w = q[i].finish;\n      if (com == 0) {\n        if (!t.is_connected(u,\
    \ v)) {\n          t.add(u, v, w);\n          msf[u].insert(v);\n          msf[v].insert(u);\n\
    \        } else {\n          S path = t.prod(u, v);\n          if (path.val <\
    \ w and path.u != -1 and path.v != -1) {\n            t.erase(path.u, path.v);\n\
    \            t.add(u, v, w);\n            msf[path.u].erase(path.v);\n       \
    \     msf[path.v].erase(path.u);\n            msf[u].insert(v);\n            msf[v].insert(u);\n\
    \          }\n        }\n      } else if (com == 1) {\n        if (msf[u].find(v)\
    \ != msf[u].end()) {\n          int p = t.prod(u, v).val;\n          t.erase(u,\
    \ v);\n          msf[u].erase(v);\n          msf[v].erase(u);\n        }\n   \
    \   } else if (com == 2) {\n        res.emplace_back(t.is_connected(u, v));\n\
    \      }\n    }\n    return res;\n  }\n};"
  dependsOn:
  - graph/dynamic-tree/LinkCutTreeEdge.hpp
  isVerificationFile: false
  path: graph/connectivity/OfflineDynamicConnectivityLCT.hpp
  requiredBy: []
  timestamp: '2024-10-04 18:45:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/connectivity/OfflineDynamicConnectivityLCT.hpp
layout: document
title: Offline Dynamic Connectivity (LCT base)
---

## 概要

todo

## 計算量
todo