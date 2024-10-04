---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235dynamic.test.cpp
    title: verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235dynamic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/connectivity/OnlineDynamicConnectivity.hpp\"\n\ntemplate\
    \ <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>\n\
    class dynamic_connectivity {\n  class euler_tour_tree {\n   private:\n    struct\
    \ Node {\n      Node *l = nullptr;\n      Node *r = nullptr;\n      Node *p =\
    \ nullptr;\n      // \u5024\u3001\u96C6\u7D04\u5024\u3001\u4F5C\u7528\u5024\n\
    \      S val = e();\n      S acc = e();\n      F lazy = id();\n      int idx =\
    \ -1;\n      int z = 0;\n      int sumz = 0;\n      bool rev = 0;\n      bool\
    \ exact;\n      bool child_exact;\n      bool edge_connected = 0;\n      bool\
    \ child_edge_connected = 0;\n      int from, to, sz;\n      Node() {}\n      Node(int\
    \ from, int to) : from(from), to(to), sz(from == to), exact(from < to), child_exact(from\
    \ < to) {}\n      bool is_root() {\n        return !p;\n      }\n    };\n\n  \
    \  using pNode = unique_ptr<Node>;\n    pNode pNIL;\n    Node *NIL = nullptr;\n\
    \    vector<pNode> A;\n    vector<unordered_map<int, pNode>> ptr;\n    Node *R;\n\
    \n    Node *get_node(int from, int to) {\n      if (ptr[from].find(to) == ptr[from].end())\
    \ {\n        ptr[from][to] = make_unique<Node>(from, to);\n      }\n      return\
    \ ptr[from][to].get();\n    }\n\n    Node *root(Node *t) {\n      if (t == NIL)\
    \ {\n        return t;\n      }\n      while (t->p != NIL) {\n        t = t->p;\n\
    \      }\n      return t;\n    }\n\n    bool same(Node *s, Node *t) {\n      if\
    \ (s != NIL) splay(s);\n      if (t != NIL) splay(t);\n      return root(s) ==\
    \ root(t);\n    }\n\n    Node *reroot(Node *t) {\n      auto s = split(t);\n \
    \     return merge(s.second, s.first);\n    }\n\n    pair<Node *, Node *> split(Node\
    \ *s) {\n      splay(s);\n      Node *t = s->l;\n      if (t != NIL) t->p = NIL;\n\
    \      s->l = NIL;\n      update(s);\n      return {t, s};\n    }\n\n    pair<Node\
    \ *, Node *> split2(Node *s) {\n      splay(s);\n      Node *t = s->l;\n     \
    \ Node *u = s->r;\n      if (t != NIL) t->p = NIL;\n      s->l = NIL;\n      if\
    \ (u != NIL) u->p = NIL;\n      s->r = NIL;\n      return {t, u};\n    }\n\n \
    \   tuple<Node *, Node *, Node *> split(Node *s, Node *t) {\n      auto u = split2(s);\n\
    \      if (same(u.first, t)) {\n        auto r = split2(t);\n        return {r.first,\
    \ r.second, u.second};\n      } else {\n        auto r = split2(t);\n        return\
    \ {u.first, r.first, r.second};\n      }\n    }\n\n    template <typename First,\
    \ typename... Rest>\n    Node *merge(First s, Rest... t) {\n      return merge(s,\
    \ merge(t...));\n    }\n\n    Node *merge(Node *s, Node *t) {\n      if (s ==\
    \ NIL) return t;\n      if (t == NIL) return s;\n\n      while (s->r != NIL) s\
    \ = s->r;\n      splay(s);\n      s->r = t;\n      if (t != NIL) t->p = s;\n \
    \     update(s);\n      return s;\n    }\n\n    int size(Node *t) {\n      return\
    \ t ? t->sz : 0;\n    }\n\n    void push(Node *v) {\n      if (v->lazy != id())\
    \ {\n        if (v->l != NIL) {\n          v->l->lazy = composition(v->lazy, v->l->lazy);\n\
    \        }\n        if (v->r != NIL) {\n          v->r->lazy = composition(v->lazy,\
    \ v->r->lazy);\n        }\n        v->val = mapping(v->lazy, v->val);\n      \
    \  v->acc = mapping(v->lazy, v->acc);\n        v->lazy = id();\n      }\n    \
    \  if (v->rev) {\n        swap(v->l, v->r);\n        if (v->l != NIL) v->l->rev\
    \ ^= true;\n        if (v->r != NIL) v->r->rev ^= true;\n        v->rev = false;\n\
    \      }\n    }\n\n    void update(Node *v) {\n      v->acc = e();\n      if (v->l\
    \ != NIL) v->acc = op(v->acc, v->l->acc);\n      if (v->from == v->to) v->acc\
    \ = op(v->acc, v->val);\n      if (v->r != NIL) v->acc = op(v->acc, v->r->acc);\n\
    \      v->sz = size(v->l) + (v->from == v->to) + size(v->r);\n      v->child_edge_connected\
    \ = (v->l ? v->l->child_edge_connected : 0) or (v->edge_connected) or (v->r ?\
    \ v->r->child_edge_connected : 0);\n      v->child_exact = (v->l ? v->l->child_exact\
    \ : 0) or (v->exact) or (v->r ? v->r->child_exact : 0);\n      v->sumz = (v->l\
    \ != NIL ? v->l->sumz : 0) + (v->r != NIL ? v->r->sumz : 0) + 1;\n      v->acc\
    \ = op(op(v->l != NIL ? v->l->acc : e(), v->val), v->r != NIL ? v->r->acc : e());\n\
    \    }\n\n    Node *&parentchild(Node *v) {\n      if (v->p == NIL) return R;\n\
    \      if (v->p->l == v) {\n        return v->p->l;\n      } else {\n        return\
    \ v->p->r;\n      }\n    }\n\n    void rotL(Node *v) {\n      Node *p = v->p;\n\
    \      parentchild(p) = v;\n      v->p = p->p;\n      p->p = v;\n      if (v->l\
    \ != NIL) v->l->p = p;\n      p->r = v->l;\n      v->l = p;\n    }\n\n    void\
    \ rotR(Node *v) {\n      Node *p = v->p;\n      parentchild(p) = v;\n      v->p\
    \ = p->p;\n      p->p = v;\n      if (v->r != NIL) v->r->p = p;\n      p->l =\
    \ v->r;\n      v->r = p;\n    }\n\n    void splay(Node *v) {\n      push(v);\n\
    \      while (v->p != NIL) {\n        Node *p = v->p;\n        Node *pp = p->p;\n\
    \        if (pp != NIL) push(pp);\n        if (p != NIL) push(p);\n        push(v);\n\
    \n        // zig zag\n        if (p->l == v) {\n          if (pp == NIL) {\n \
    \           rotR(v);\n          } else if (pp->l == p) {\n            rotR(p);\n\
    \            rotR(v);\n          } else if (pp->r == p) {\n            rotR(v);\n\
    \            rotL(v);\n          }\n        } else {\n          if (pp == NIL)\
    \ {\n            rotL(v);\n          } else if (pp->r == p) {\n            rotL(p);\n\
    \            rotL(v);\n          } else if (pp->l == p) {\n            rotL(v);\n\
    \            rotR(v);\n          }\n        }\n\n        if (pp != NIL) update(pp);\n\
    \        if (p != NIL) update(p);\n        update(v);\n      }\n      update(v);\n\
    \    }\n\n    Node *access(int k) {\n      Node *c = R;\n      while (true) {\n\
    \        push(c);\n        if (c->l->sumz == k) break;\n        if (c->l->sumz\
    \ > k) {\n          c = c->l;\n          continue;\n        }\n        k -= c->l->sumz\
    \ + 1;\n        c = c->r;\n      }\n      push(c);\n      splay(c);\n      return\
    \ c;\n    }\n\n   public:\n    euler_tour_tree() {}\n    euler_tour_tree(int siz)\
    \ {\n      ptr.resize(siz);\n      for (int i = 0; i < siz; i++) {\n        ptr[i][i]\
    \ = make_unique<Node>(i, i);\n      }\n    }\n\n    int size(int s) {\n      Node\
    \ *t = get_node(s, s);\n      splay(t);\n      return t->sz;\n    }\n\n    bool\
    \ same(int s, int t) {\n      return same(get_node(s, s), get_node(t, t));\n \
    \   }\n\n    void set_size(int sz) {\n      ptr.resize(sz);\n      for (int i\
    \ = 0; i < sz; i++) {\n        ptr[i][i] = make_unique<Node>(i, i);\n      }\n\
    \    }\n\n    void update(int s, F x) {\n      Node *t = get_node(s, s);\n   \
    \   splay(t);\n      t->val = mapping(x, t->val);\n      update(t);\n    }\n\n\
    \    void set(int s, S x) {\n      Node *t = get_node(s, s);\n      splay(t);\n\
    \      t->val = x;\n      update(t);\n    }\n\n    void edge_update(int s, auto\
    \ g) {\n      Node *t = get_node(s, s);\n      splay(t);\n      function<void(Node\
    \ *)> dfs = [&](Node *t) {\n        assert(t);\n        if (t->from < t->to and\
    \ t->exact) {\n          splay(t);\n          t->exact = 0;\n          update(t);\n\
    \          g(t->from, t->to);\n          return;\n        }\n        if (t->l\
    \ and t->l->child_exact)\n          dfs(t->l);\n        else\n          dfs(t->r);\n\
    \      };\n      while (t and t->child_exact) {\n        dfs(t);\n        splay(t);\n\
    \      }\n    }\n\n    bool try_reconnect(int s, auto f) {\n      Node *t = get_node(s,\
    \ s);\n      splay(t);\n      function<bool(Node *)> dfs = [&](Node *t) -> bool\
    \ {\n        assert(t);\n        if (t->edge_connected) {\n          splay(t);\n\
    \          return f(t->from);\n        }\n        if (t->l && t->l->child_edge_connected)\n\
    \          return dfs(t->l);\n        else\n          return dfs(t->r);\n    \
    \  };\n      while (t->child_edge_connected) {\n        if (dfs(t)) return 1;\n\
    \        splay(t);\n      }\n      return 0;\n    }\n\n    void edge_connected_update(int\
    \ s, bool b) {\n      Node *t = get_node(s, s);\n      splay(t);\n      t->edge_connected\
    \ = b;\n      update(t);\n    }\n\n    bool link(int from, int to) {\n      if\
    \ (same(from, to)) return 0;\n      merge(reroot(get_node(from, from)), get_node(from,\
    \ to), reroot(get_node(to, to)), get_node(to, from));\n      return 1;\n    }\n\
    \n    bool cut(int from, int to) {\n      if (ptr[from].find(to) == ptr[from].end())\
    \ return 0;\n      Node *s, *t, *u;\n      tie(s, t, u) = split(get_node(from,\
    \ to), get_node(to, from));\n      merge(s, u);\n      Node *p = ptr[from][to].get();\n\
    \      Node *q = ptr[to][from].get();\n      ptr[from].erase(to);\n      ptr[to].erase(from);\n\
    \      return 1;\n    }\n\n    S get_sum(int p, int v) {\n      cut(p, v);\n \
    \     Node *t = get_node(v, v);\n      splay(t);\n      S res = t->acc;\n    \
    \  link(p, v);\n      return res;\n    }\n    S get_sum(int s) {\n      Node *t\
    \ = get_node(s, s);\n      splay(t);\n      return t->acc;\n    }\n  };\n  int\
    \ dep = 1;\n  vector<euler_tour_tree> ett;\n  vector<vector<unordered_set<int>>>\
    \ edges;\n  int sz;\n\n  int connected_components;\n\n  bool try_reconnect(int\
    \ s, int t, int k) {\n    for (int i = 0; i < k; i++) {\n      ett[i].cut(s, t);\n\
    \    }\n    for (int i = k; i >= 0; i--) {\n      if (ett[i].size(s) > ett[i].size(t))\
    \ swap(s, t);\n      auto g = [&](int s, int t) { ett[i + 1].link(s, t); };\n\
    \      ett[i].edge_update(s, g);\n      auto f = [&](int x) -> bool {\n      \
    \  for (auto itr = edges[i][x].begin(); itr != edges[i][x].end();) {\n       \
    \   auto y = *itr;\n          itr = edges[i][x].erase(itr);\n          edges[i][y].erase(x);\n\
    \          if (edges[i][x].size() == 0) ett[i].edge_connected_update(x, 0);\n\
    \          if (edges[i][y].size() == 0) ett[i].edge_connected_update(y, 0);\n\
    \          if (ett[i].same(x, y)) {\n            edges[i + 1][x].insert(y);\n\
    \            edges[i + 1][y].insert(x);\n            if (edges[i + 1][x].size()\
    \ == 1) ett[i + 1].edge_connected_update(x, 1);\n            if (edges[i + 1][y].size()\
    \ == 1) ett[i + 1].edge_connected_update(y, 1);\n          } else {\n        \
    \    for (int j = 0; j <= i; j++) {\n              ett[j].link(x, y);\n      \
    \      }\n            return 1;\n          }\n        }\n        return 0;\n \
    \     };\n      if (ett[i].try_reconnect(s, f)) return 1;\n    }\n    return 0;\n\
    \  }\n\n public:\n  dynamic_connectivity(int sz) : sz(sz), connected_components(sz)\
    \ {\n    ett.emplace_back(sz);\n    edges.emplace_back(sz);\n  }\n  bool link(int\
    \ s, int t) {\n    if (s == t) return 0;\n    if (ett[0].link(s, t)) {\n     \
    \ connected_components--;\n      return 1;\n    }\n    edges[0][s].insert(t);\n\
    \    edges[0][t].insert(s);\n    if (edges[0][s].size() == 1) ett[0].edge_connected_update(s,\
    \ 1);\n    if (edges[0][t].size() == 1) ett[0].edge_connected_update(t, 1);\n\
    \    return 0;\n  }\n\n  bool is_connected(int s, int t) {\n    return ett[0].same(s,\
    \ t);\n  }\n\n  int size(int s) {\n    return ett[0].size(s);\n  }\n  vector<int>\
    \ get_vertex(int s) {\n    return ett[0].vertex_list(s);\n  }\n  void update(int\
    \ s, F x) {\n    ett[0].update(s, x);\n  }\n\n  void set(int s, S x) {\n    ett[0].set(s,\
    \ x);\n  }\n\n  S prod(int s) {\n    return ett[0].get_sum(s);\n  }\n\n  int components()\
    \ {\n    return connected_components;\n  }\n\n  bool cut(int s, int t) {\n   \
    \ if (s == t) return 0;\n    for (int i = 0; i < dep; i++) {\n      edges[i][s].erase(t);\n\
    \      edges[i][t].erase(s);\n      if (edges[i][s].size() == 0) ett[i].edge_connected_update(s,\
    \ 0);\n      if (edges[i][t].size() == 0) ett[i].edge_connected_update(t, 0);\n\
    \    }\n    for (int i = dep - 1; i >= 0; i--) {\n      if (ett[i].cut(s, t))\
    \ {\n        if (dep - 1 == i) {\n          dep++;\n          ett.emplace_back(sz);\n\
    \          edges.emplace_back(sz);\n        }\n        bool reconnected = try_reconnect(s,\
    \ t, i);\n        if (!reconnected) {\n          connected_components++;\n   \
    \     }\n        return !reconnected;\n      }\n    }\n    return 0;\n  }\n};\n"
  code: "\ntemplate <class S, auto op, auto e, class F, auto mapping, auto composition,\
    \ auto id>\nclass dynamic_connectivity {\n  class euler_tour_tree {\n   private:\n\
    \    struct Node {\n      Node *l = nullptr;\n      Node *r = nullptr;\n     \
    \ Node *p = nullptr;\n      // \u5024\u3001\u96C6\u7D04\u5024\u3001\u4F5C\u7528\
    \u5024\n      S val = e();\n      S acc = e();\n      F lazy = id();\n      int\
    \ idx = -1;\n      int z = 0;\n      int sumz = 0;\n      bool rev = 0;\n    \
    \  bool exact;\n      bool child_exact;\n      bool edge_connected = 0;\n    \
    \  bool child_edge_connected = 0;\n      int from, to, sz;\n      Node() {}\n\
    \      Node(int from, int to) : from(from), to(to), sz(from == to), exact(from\
    \ < to), child_exact(from < to) {}\n      bool is_root() {\n        return !p;\n\
    \      }\n    };\n\n    using pNode = unique_ptr<Node>;\n    pNode pNIL;\n   \
    \ Node *NIL = nullptr;\n    vector<pNode> A;\n    vector<unordered_map<int, pNode>>\
    \ ptr;\n    Node *R;\n\n    Node *get_node(int from, int to) {\n      if (ptr[from].find(to)\
    \ == ptr[from].end()) {\n        ptr[from][to] = make_unique<Node>(from, to);\n\
    \      }\n      return ptr[from][to].get();\n    }\n\n    Node *root(Node *t)\
    \ {\n      if (t == NIL) {\n        return t;\n      }\n      while (t->p != NIL)\
    \ {\n        t = t->p;\n      }\n      return t;\n    }\n\n    bool same(Node\
    \ *s, Node *t) {\n      if (s != NIL) splay(s);\n      if (t != NIL) splay(t);\n\
    \      return root(s) == root(t);\n    }\n\n    Node *reroot(Node *t) {\n    \
    \  auto s = split(t);\n      return merge(s.second, s.first);\n    }\n\n    pair<Node\
    \ *, Node *> split(Node *s) {\n      splay(s);\n      Node *t = s->l;\n      if\
    \ (t != NIL) t->p = NIL;\n      s->l = NIL;\n      update(s);\n      return {t,\
    \ s};\n    }\n\n    pair<Node *, Node *> split2(Node *s) {\n      splay(s);\n\
    \      Node *t = s->l;\n      Node *u = s->r;\n      if (t != NIL) t->p = NIL;\n\
    \      s->l = NIL;\n      if (u != NIL) u->p = NIL;\n      s->r = NIL;\n     \
    \ return {t, u};\n    }\n\n    tuple<Node *, Node *, Node *> split(Node *s, Node\
    \ *t) {\n      auto u = split2(s);\n      if (same(u.first, t)) {\n        auto\
    \ r = split2(t);\n        return {r.first, r.second, u.second};\n      } else\
    \ {\n        auto r = split2(t);\n        return {u.first, r.first, r.second};\n\
    \      }\n    }\n\n    template <typename First, typename... Rest>\n    Node *merge(First\
    \ s, Rest... t) {\n      return merge(s, merge(t...));\n    }\n\n    Node *merge(Node\
    \ *s, Node *t) {\n      if (s == NIL) return t;\n      if (t == NIL) return s;\n\
    \n      while (s->r != NIL) s = s->r;\n      splay(s);\n      s->r = t;\n    \
    \  if (t != NIL) t->p = s;\n      update(s);\n      return s;\n    }\n\n    int\
    \ size(Node *t) {\n      return t ? t->sz : 0;\n    }\n\n    void push(Node *v)\
    \ {\n      if (v->lazy != id()) {\n        if (v->l != NIL) {\n          v->l->lazy\
    \ = composition(v->lazy, v->l->lazy);\n        }\n        if (v->r != NIL) {\n\
    \          v->r->lazy = composition(v->lazy, v->r->lazy);\n        }\n       \
    \ v->val = mapping(v->lazy, v->val);\n        v->acc = mapping(v->lazy, v->acc);\n\
    \        v->lazy = id();\n      }\n      if (v->rev) {\n        swap(v->l, v->r);\n\
    \        if (v->l != NIL) v->l->rev ^= true;\n        if (v->r != NIL) v->r->rev\
    \ ^= true;\n        v->rev = false;\n      }\n    }\n\n    void update(Node *v)\
    \ {\n      v->acc = e();\n      if (v->l != NIL) v->acc = op(v->acc, v->l->acc);\n\
    \      if (v->from == v->to) v->acc = op(v->acc, v->val);\n      if (v->r != NIL)\
    \ v->acc = op(v->acc, v->r->acc);\n      v->sz = size(v->l) + (v->from == v->to)\
    \ + size(v->r);\n      v->child_edge_connected = (v->l ? v->l->child_edge_connected\
    \ : 0) or (v->edge_connected) or (v->r ? v->r->child_edge_connected : 0);\n  \
    \    v->child_exact = (v->l ? v->l->child_exact : 0) or (v->exact) or (v->r ?\
    \ v->r->child_exact : 0);\n      v->sumz = (v->l != NIL ? v->l->sumz : 0) + (v->r\
    \ != NIL ? v->r->sumz : 0) + 1;\n      v->acc = op(op(v->l != NIL ? v->l->acc\
    \ : e(), v->val), v->r != NIL ? v->r->acc : e());\n    }\n\n    Node *&parentchild(Node\
    \ *v) {\n      if (v->p == NIL) return R;\n      if (v->p->l == v) {\n       \
    \ return v->p->l;\n      } else {\n        return v->p->r;\n      }\n    }\n\n\
    \    void rotL(Node *v) {\n      Node *p = v->p;\n      parentchild(p) = v;\n\
    \      v->p = p->p;\n      p->p = v;\n      if (v->l != NIL) v->l->p = p;\n  \
    \    p->r = v->l;\n      v->l = p;\n    }\n\n    void rotR(Node *v) {\n      Node\
    \ *p = v->p;\n      parentchild(p) = v;\n      v->p = p->p;\n      p->p = v;\n\
    \      if (v->r != NIL) v->r->p = p;\n      p->l = v->r;\n      v->r = p;\n  \
    \  }\n\n    void splay(Node *v) {\n      push(v);\n      while (v->p != NIL) {\n\
    \        Node *p = v->p;\n        Node *pp = p->p;\n        if (pp != NIL) push(pp);\n\
    \        if (p != NIL) push(p);\n        push(v);\n\n        // zig zag\n    \
    \    if (p->l == v) {\n          if (pp == NIL) {\n            rotR(v);\n    \
    \      } else if (pp->l == p) {\n            rotR(p);\n            rotR(v);\n\
    \          } else if (pp->r == p) {\n            rotR(v);\n            rotL(v);\n\
    \          }\n        } else {\n          if (pp == NIL) {\n            rotL(v);\n\
    \          } else if (pp->r == p) {\n            rotL(p);\n            rotL(v);\n\
    \          } else if (pp->l == p) {\n            rotL(v);\n            rotR(v);\n\
    \          }\n        }\n\n        if (pp != NIL) update(pp);\n        if (p !=\
    \ NIL) update(p);\n        update(v);\n      }\n      update(v);\n    }\n\n  \
    \  Node *access(int k) {\n      Node *c = R;\n      while (true) {\n        push(c);\n\
    \        if (c->l->sumz == k) break;\n        if (c->l->sumz > k) {\n        \
    \  c = c->l;\n          continue;\n        }\n        k -= c->l->sumz + 1;\n \
    \       c = c->r;\n      }\n      push(c);\n      splay(c);\n      return c;\n\
    \    }\n\n   public:\n    euler_tour_tree() {}\n    euler_tour_tree(int siz) {\n\
    \      ptr.resize(siz);\n      for (int i = 0; i < siz; i++) {\n        ptr[i][i]\
    \ = make_unique<Node>(i, i);\n      }\n    }\n\n    int size(int s) {\n      Node\
    \ *t = get_node(s, s);\n      splay(t);\n      return t->sz;\n    }\n\n    bool\
    \ same(int s, int t) {\n      return same(get_node(s, s), get_node(t, t));\n \
    \   }\n\n    void set_size(int sz) {\n      ptr.resize(sz);\n      for (int i\
    \ = 0; i < sz; i++) {\n        ptr[i][i] = make_unique<Node>(i, i);\n      }\n\
    \    }\n\n    void update(int s, F x) {\n      Node *t = get_node(s, s);\n   \
    \   splay(t);\n      t->val = mapping(x, t->val);\n      update(t);\n    }\n\n\
    \    void set(int s, S x) {\n      Node *t = get_node(s, s);\n      splay(t);\n\
    \      t->val = x;\n      update(t);\n    }\n\n    void edge_update(int s, auto\
    \ g) {\n      Node *t = get_node(s, s);\n      splay(t);\n      function<void(Node\
    \ *)> dfs = [&](Node *t) {\n        assert(t);\n        if (t->from < t->to and\
    \ t->exact) {\n          splay(t);\n          t->exact = 0;\n          update(t);\n\
    \          g(t->from, t->to);\n          return;\n        }\n        if (t->l\
    \ and t->l->child_exact)\n          dfs(t->l);\n        else\n          dfs(t->r);\n\
    \      };\n      while (t and t->child_exact) {\n        dfs(t);\n        splay(t);\n\
    \      }\n    }\n\n    bool try_reconnect(int s, auto f) {\n      Node *t = get_node(s,\
    \ s);\n      splay(t);\n      function<bool(Node *)> dfs = [&](Node *t) -> bool\
    \ {\n        assert(t);\n        if (t->edge_connected) {\n          splay(t);\n\
    \          return f(t->from);\n        }\n        if (t->l && t->l->child_edge_connected)\n\
    \          return dfs(t->l);\n        else\n          return dfs(t->r);\n    \
    \  };\n      while (t->child_edge_connected) {\n        if (dfs(t)) return 1;\n\
    \        splay(t);\n      }\n      return 0;\n    }\n\n    void edge_connected_update(int\
    \ s, bool b) {\n      Node *t = get_node(s, s);\n      splay(t);\n      t->edge_connected\
    \ = b;\n      update(t);\n    }\n\n    bool link(int from, int to) {\n      if\
    \ (same(from, to)) return 0;\n      merge(reroot(get_node(from, from)), get_node(from,\
    \ to), reroot(get_node(to, to)), get_node(to, from));\n      return 1;\n    }\n\
    \n    bool cut(int from, int to) {\n      if (ptr[from].find(to) == ptr[from].end())\
    \ return 0;\n      Node *s, *t, *u;\n      tie(s, t, u) = split(get_node(from,\
    \ to), get_node(to, from));\n      merge(s, u);\n      Node *p = ptr[from][to].get();\n\
    \      Node *q = ptr[to][from].get();\n      ptr[from].erase(to);\n      ptr[to].erase(from);\n\
    \      return 1;\n    }\n\n    S get_sum(int p, int v) {\n      cut(p, v);\n \
    \     Node *t = get_node(v, v);\n      splay(t);\n      S res = t->acc;\n    \
    \  link(p, v);\n      return res;\n    }\n    S get_sum(int s) {\n      Node *t\
    \ = get_node(s, s);\n      splay(t);\n      return t->acc;\n    }\n  };\n  int\
    \ dep = 1;\n  vector<euler_tour_tree> ett;\n  vector<vector<unordered_set<int>>>\
    \ edges;\n  int sz;\n\n  int connected_components;\n\n  bool try_reconnect(int\
    \ s, int t, int k) {\n    for (int i = 0; i < k; i++) {\n      ett[i].cut(s, t);\n\
    \    }\n    for (int i = k; i >= 0; i--) {\n      if (ett[i].size(s) > ett[i].size(t))\
    \ swap(s, t);\n      auto g = [&](int s, int t) { ett[i + 1].link(s, t); };\n\
    \      ett[i].edge_update(s, g);\n      auto f = [&](int x) -> bool {\n      \
    \  for (auto itr = edges[i][x].begin(); itr != edges[i][x].end();) {\n       \
    \   auto y = *itr;\n          itr = edges[i][x].erase(itr);\n          edges[i][y].erase(x);\n\
    \          if (edges[i][x].size() == 0) ett[i].edge_connected_update(x, 0);\n\
    \          if (edges[i][y].size() == 0) ett[i].edge_connected_update(y, 0);\n\
    \          if (ett[i].same(x, y)) {\n            edges[i + 1][x].insert(y);\n\
    \            edges[i + 1][y].insert(x);\n            if (edges[i + 1][x].size()\
    \ == 1) ett[i + 1].edge_connected_update(x, 1);\n            if (edges[i + 1][y].size()\
    \ == 1) ett[i + 1].edge_connected_update(y, 1);\n          } else {\n        \
    \    for (int j = 0; j <= i; j++) {\n              ett[j].link(x, y);\n      \
    \      }\n            return 1;\n          }\n        }\n        return 0;\n \
    \     };\n      if (ett[i].try_reconnect(s, f)) return 1;\n    }\n    return 0;\n\
    \  }\n\n public:\n  dynamic_connectivity(int sz) : sz(sz), connected_components(sz)\
    \ {\n    ett.emplace_back(sz);\n    edges.emplace_back(sz);\n  }\n  bool link(int\
    \ s, int t) {\n    if (s == t) return 0;\n    if (ett[0].link(s, t)) {\n     \
    \ connected_components--;\n      return 1;\n    }\n    edges[0][s].insert(t);\n\
    \    edges[0][t].insert(s);\n    if (edges[0][s].size() == 1) ett[0].edge_connected_update(s,\
    \ 1);\n    if (edges[0][t].size() == 1) ett[0].edge_connected_update(t, 1);\n\
    \    return 0;\n  }\n\n  bool is_connected(int s, int t) {\n    return ett[0].same(s,\
    \ t);\n  }\n\n  int size(int s) {\n    return ett[0].size(s);\n  }\n  vector<int>\
    \ get_vertex(int s) {\n    return ett[0].vertex_list(s);\n  }\n  void update(int\
    \ s, F x) {\n    ett[0].update(s, x);\n  }\n\n  void set(int s, S x) {\n    ett[0].set(s,\
    \ x);\n  }\n\n  S prod(int s) {\n    return ett[0].get_sum(s);\n  }\n\n  int components()\
    \ {\n    return connected_components;\n  }\n\n  bool cut(int s, int t) {\n   \
    \ if (s == t) return 0;\n    for (int i = 0; i < dep; i++) {\n      edges[i][s].erase(t);\n\
    \      edges[i][t].erase(s);\n      if (edges[i][s].size() == 0) ett[i].edge_connected_update(s,\
    \ 0);\n      if (edges[i][t].size() == 0) ett[i].edge_connected_update(t, 0);\n\
    \    }\n    for (int i = dep - 1; i >= 0; i--) {\n      if (ett[i].cut(s, t))\
    \ {\n        if (dep - 1 == i) {\n          dep++;\n          ett.emplace_back(sz);\n\
    \          edges.emplace_back(sz);\n        }\n        bool reconnected = try_reconnect(s,\
    \ t, i);\n        if (!reconnected) {\n          connected_components++;\n   \
    \     }\n        return !reconnected;\n      }\n    }\n    return 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/connectivity/OnlineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2024-10-04 18:45:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/connectivity/GraphConstruction2235dynamic.test.cpp
documentation_of: graph/connectivity/OnlineDynamicConnectivity.hpp
layout: document
title: Online Dynamic Connectivity
---

## 概要

todo

## 計算量
todo