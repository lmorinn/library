#include "../../data-structure/segment-tree/SegmentTree.hpp"
class TreeQuery {
 private:
  struct S {
    int val, id;
  };
  static S op(S a, S b) {
    if (a.val < b.val) {
      return a;
    }
    return b;
  }

  static S e() {
    return {100000000, -1};
  }

  vector<vector<int>> g;
  int n, root;
  int cnt = 0;
  vector<int> st, dep;
  segtree<S, op, e> rmq;

  void build() {
    int time = 0;
    vector<S> v;
    auto dfs = [&](auto& self, int cur, int prev, int d) -> void {
      st[cur] = time++;
      dep[cur] = d;
      v.emplace_back(d, cur);
      for (auto nex : g[cur]) {
        if (nex == prev) continue;
        self(self, nex, cur, d + 1);
        v.emplace_back(d, cur);
        time++;
      }
    };
    dfs(dfs, root, -1, 0);
    rmq = segtree<S, op, e>(v);
  }

 public:
  TreeQuery(int n, int root = 0) : n(n), root(root) {
    g.resize(n);
    st.resize(n);
    dep.resize(n);
  }

  void add_edge(int u, int v) {
    assert(cnt < n - 1);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    if (++cnt == n - 1) build();
  }

  int lca(int u, int v) {
    int l = st[u];
    int r = st[v];
    if (l > r) swap(l, r);
    return rmq.prod(l, r + 1).id;
  }

  int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  bool contains(int u, int v, int x) {
    return dist(u, x) + dist(x, v) == dist(u, v);
  }
};