
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
class dynamic_connectivity {
  class euler_tour_tree {
   private:
    struct Node {
      Node *l = nullptr;
      Node *r = nullptr;
      Node *p = nullptr;
      // 値、集約値、作用値
      S val = e();
      S acc = e();
      F lazy = id();
      int idx = -1;
      int z = 0;
      int sumz = 0;
      bool rev = 0;
      bool exact;
      bool child_exact;
      bool edge_connected = 0;
      bool child_edge_connected = 0;
      int from, to, sz;
      Node() {}
      Node(int from, int to) : from(from), to(to), sz(from == to), exact(from < to), child_exact(from < to) {}
      bool is_root() {
        return !p;
      }
    };

    using pNode = unique_ptr<Node>;
    pNode pNIL;
    Node *NIL = nullptr;
    vector<pNode> A;
    vector<unordered_map<int, pNode>> ptr;
    Node *R;

    Node *get_node(int from, int to) {
      if (ptr[from].find(to) == ptr[from].end()) {
        ptr[from][to] = make_unique<Node>(from, to);
      }
      return ptr[from][to].get();
    }

    Node *root(Node *t) {
      if (t == NIL) {
        return t;
      }
      while (t->p != NIL) {
        t = t->p;
      }
      return t;
    }

    bool same(Node *s, Node *t) {
      if (s != NIL) splay(s);
      if (t != NIL) splay(t);
      return root(s) == root(t);
    }

    Node *reroot(Node *t) {
      auto s = split(t);
      return merge(s.second, s.first);
    }

    pair<Node *, Node *> split(Node *s) {
      splay(s);
      Node *t = s->l;
      if (t != NIL) t->p = NIL;
      s->l = NIL;
      update(s);
      return {t, s};
    }

    pair<Node *, Node *> split2(Node *s) {
      splay(s);
      Node *t = s->l;
      Node *u = s->r;
      if (t != NIL) t->p = NIL;
      s->l = NIL;
      if (u != NIL) u->p = NIL;
      s->r = NIL;
      return {t, u};
    }

    tuple<Node *, Node *, Node *> split(Node *s, Node *t) {
      auto u = split2(s);
      if (same(u.first, t)) {
        auto r = split2(t);
        return {r.first, r.second, u.second};
      } else {
        auto r = split2(t);
        return {u.first, r.first, r.second};
      }
    }

    template <typename First, typename... Rest>
    Node *merge(First s, Rest... t) {
      return merge(s, merge(t...));
    }

    Node *merge(Node *s, Node *t) {
      if (s == NIL) return t;
      if (t == NIL) return s;

      while (s->r != NIL) s = s->r;
      splay(s);
      s->r = t;
      if (t != NIL) t->p = s;
      update(s);
      return s;
    }

    int size(Node *t) {
      return t ? t->sz : 0;
    }

    void push(Node *v) {
      if (v->lazy != id()) {
        if (v->l != NIL) {
          v->l->lazy = composition(v->lazy, v->l->lazy);
        }
        if (v->r != NIL) {
          v->r->lazy = composition(v->lazy, v->r->lazy);
        }
        v->val = mapping(v->lazy, v->val);
        v->acc = mapping(v->lazy, v->acc);
        v->lazy = id();
      }
      if (v->rev) {
        swap(v->l, v->r);
        if (v->l != NIL) v->l->rev ^= true;
        if (v->r != NIL) v->r->rev ^= true;
        v->rev = false;
      }
    }

    void update(Node *v) {
      v->acc = e();
      if (v->l != NIL) v->acc = op(v->acc, v->l->acc);
      if (v->from == v->to) v->acc = op(v->acc, v->val);
      if (v->r != NIL) v->acc = op(v->acc, v->r->acc);
      v->sz = size(v->l) + (v->from == v->to) + size(v->r);
      v->child_edge_connected = (v->l ? v->l->child_edge_connected : 0) or (v->edge_connected) or (v->r ? v->r->child_edge_connected : 0);
      v->child_exact = (v->l ? v->l->child_exact : 0) or (v->exact) or (v->r ? v->r->child_exact : 0);
      v->sumz = (v->l != NIL ? v->l->sumz : 0) + (v->r != NIL ? v->r->sumz : 0) + 1;
      v->acc = op(op(v->l != NIL ? v->l->acc : e(), v->val), v->r != NIL ? v->r->acc : e());
    }

    Node *&parentchild(Node *v) {
      if (v->p == NIL) return R;
      if (v->p->l == v) {
        return v->p->l;
      } else {
        return v->p->r;
      }
    }

    void rotL(Node *v) {
      Node *p = v->p;
      parentchild(p) = v;
      v->p = p->p;
      p->p = v;
      if (v->l != NIL) v->l->p = p;
      p->r = v->l;
      v->l = p;
    }

    void rotR(Node *v) {
      Node *p = v->p;
      parentchild(p) = v;
      v->p = p->p;
      p->p = v;
      if (v->r != NIL) v->r->p = p;
      p->l = v->r;
      v->r = p;
    }

    void splay(Node *v) {
      push(v);
      while (v->p != NIL) {
        Node *p = v->p;
        Node *pp = p->p;
        if (pp != NIL) push(pp);
        if (p != NIL) push(p);
        push(v);

        // zig zag
        if (p->l == v) {
          if (pp == NIL) {
            rotR(v);
          } else if (pp->l == p) {
            rotR(p);
            rotR(v);
          } else if (pp->r == p) {
            rotR(v);
            rotL(v);
          }
        } else {
          if (pp == NIL) {
            rotL(v);
          } else if (pp->r == p) {
            rotL(p);
            rotL(v);
          } else if (pp->l == p) {
            rotL(v);
            rotR(v);
          }
        }

        if (pp != NIL) update(pp);
        if (p != NIL) update(p);
        update(v);
      }
      update(v);
    }

    Node *access(int k) {
      Node *c = R;
      while (true) {
        push(c);
        if (c->l->sumz == k) break;
        if (c->l->sumz > k) {
          c = c->l;
          continue;
        }
        k -= c->l->sumz + 1;
        c = c->r;
      }
      push(c);
      splay(c);
      return c;
    }

   public:
    euler_tour_tree() {}
    euler_tour_tree(int siz) {
      ptr.resize(siz);
      for (int i = 0; i < siz; i++) {
        ptr[i][i] = make_unique<Node>(i, i);
      }
    }

    int size(int s) {
      Node *t = get_node(s, s);
      splay(t);
      return t->sz;
    }

    bool same(int s, int t) {
      return same(get_node(s, s), get_node(t, t));
    }

    void set_size(int sz) {
      ptr.resize(sz);
      for (int i = 0; i < sz; i++) {
        ptr[i][i] = make_unique<Node>(i, i);
      }
    }

    void update(int s, F x) {
      Node *t = get_node(s, s);
      splay(t);
      t->val = mapping(x, t->val);
      update(t);
    }

    void set(int s, S x) {
      Node *t = get_node(s, s);
      splay(t);
      t->val = x;
      update(t);
    }

    void edge_update(int s, auto g) {
      Node *t = get_node(s, s);
      splay(t);
      function<void(Node *)> dfs = [&](Node *t) {
        assert(t);
        if (t->from < t->to and t->exact) {
          splay(t);
          t->exact = 0;
          update(t);
          g(t->from, t->to);
          return;
        }
        if (t->l and t->l->child_exact)
          dfs(t->l);
        else
          dfs(t->r);
      };
      while (t and t->child_exact) {
        dfs(t);
        splay(t);
      }
    }

    bool try_reconnect(int s, auto f) {
      Node *t = get_node(s, s);
      splay(t);
      function<bool(Node *)> dfs = [&](Node *t) -> bool {
        assert(t);
        if (t->edge_connected) {
          splay(t);
          return f(t->from);
        }
        if (t->l && t->l->child_edge_connected)
          return dfs(t->l);
        else
          return dfs(t->r);
      };
      while (t->child_edge_connected) {
        if (dfs(t)) return 1;
        splay(t);
      }
      return 0;
    }

    void edge_connected_update(int s, bool b) {
      Node *t = get_node(s, s);
      splay(t);
      t->edge_connected = b;
      update(t);
    }

    bool link(int from, int to) {
      if (same(from, to)) return 0;
      merge(reroot(get_node(from, from)), get_node(from, to), reroot(get_node(to, to)), get_node(to, from));
      return 1;
    }

    bool cut(int from, int to) {
      if (ptr[from].find(to) == ptr[from].end()) return 0;
      Node *s, *t, *u;
      tie(s, t, u) = split(get_node(from, to), get_node(to, from));
      merge(s, u);
      Node *p = ptr[from][to].get();
      Node *q = ptr[to][from].get();
      ptr[from].erase(to);
      ptr[to].erase(from);
      return 1;
    }

    S get_sum(int p, int v) {
      cut(p, v);
      Node *t = get_node(v, v);
      splay(t);
      S res = t->acc;
      link(p, v);
      return res;
    }
    S get_sum(int s) {
      Node *t = get_node(s, s);
      splay(t);
      return t->acc;
    }
  };
  int dep = 1;
  vector<euler_tour_tree> ett;
  vector<vector<unordered_set<int>>> edges;
  int sz;

  int connected_components;

  bool try_reconnect(int s, int t, int k) {
    for (int i = 0; i < k; i++) {
      ett[i].cut(s, t);
    }
    for (int i = k; i >= 0; i--) {
      if (ett[i].size(s) > ett[i].size(t)) swap(s, t);
      auto g = [&](int s, int t) { ett[i + 1].link(s, t); };
      ett[i].edge_update(s, g);
      auto f = [&](int x) -> bool {
        for (auto itr = edges[i][x].begin(); itr != edges[i][x].end();) {
          auto y = *itr;
          itr = edges[i][x].erase(itr);
          edges[i][y].erase(x);
          if (edges[i][x].size() == 0) ett[i].edge_connected_update(x, 0);
          if (edges[i][y].size() == 0) ett[i].edge_connected_update(y, 0);
          if (ett[i].same(x, y)) {
            edges[i + 1][x].insert(y);
            edges[i + 1][y].insert(x);
            if (edges[i + 1][x].size() == 1) ett[i + 1].edge_connected_update(x, 1);
            if (edges[i + 1][y].size() == 1) ett[i + 1].edge_connected_update(y, 1);
          } else {
            for (int j = 0; j <= i; j++) {
              ett[j].link(x, y);
            }
            return 1;
          }
        }
        return 0;
      };
      if (ett[i].try_reconnect(s, f)) return 1;
    }
    return 0;
  }

 public:
  dynamic_connectivity(int sz) : sz(sz), connected_components(sz) {
    ett.emplace_back(sz);
    edges.emplace_back(sz);
  }
  bool link(int s, int t) {
    if (s == t) return 0;
    if (ett[0].link(s, t)) {
      connected_components--;
      return 1;
    }
    edges[0][s].insert(t);
    edges[0][t].insert(s);
    if (edges[0][s].size() == 1) ett[0].edge_connected_update(s, 1);
    if (edges[0][t].size() == 1) ett[0].edge_connected_update(t, 1);
    return 0;
  }

  bool is_connected(int s, int t) {
    return ett[0].same(s, t);
  }

  int size(int s) {
    return ett[0].size(s);
  }
  vector<int> get_vertex(int s) {
    return ett[0].vertex_list(s);
  }
  void update(int s, F x) {
    ett[0].update(s, x);
  }

  void set(int s, S x) {
    ett[0].set(s, x);
  }

  S prod(int s) {
    return ett[0].get_sum(s);
  }

  int components() {
    return connected_components;
  }

  bool cut(int s, int t) {
    if (s == t) return 0;
    for (int i = 0; i < dep; i++) {
      edges[i][s].erase(t);
      edges[i][t].erase(s);
      if (edges[i][s].size() == 0) ett[i].edge_connected_update(s, 0);
      if (edges[i][t].size() == 0) ett[i].edge_connected_update(t, 0);
    }
    for (int i = dep - 1; i >= 0; i--) {
      if (ett[i].cut(s, t)) {
        if (dep - 1 == i) {
          dep++;
          ett.emplace_back(sz);
          edges.emplace_back(sz);
        }
        bool reconnected = try_reconnect(s, t, i);
        if (!reconnected) {
          connected_components++;
        }
        return !reconnected;
      }
    }
    return 0;
  }
};
