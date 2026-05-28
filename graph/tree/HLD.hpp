
struct hld {
 private:
  int n, root, edge;
  vector<vector<int>> g;
  vector<int> heavy_p, heavy_l, light_p, idx, xdi, sub_siz;

  int dfs(int cur, int prev) {
    int sub = 1;
    for (int& nex : g[cur]) {
      if (nex == prev) {
        swap(g[cur].back(), nex);
        g[cur].pop_back();
        break;
      }
    }
    int best = 0;
    int idx = -1;
    for (int i = 0; i < int(g[cur].size()); i++) {
      int cnt = dfs(g[cur][i], cur);
      sub += cnt;
      if (best < cnt) {
        best = cnt;
        idx = i;
      }
    }
    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());
    for (int i = 1; i < int(g[cur].size()); i++) light_p[g[cur][i]] = cur;
    sub_siz[cur] = sub;
    return sub;
  }

  void dfs2(int cur, int top, int& id) {
    heavy_p[cur] = top;
    idx[cur] = id;
    xdi[id] = cur;
    id++;
    if (!g[cur].empty()) {
      dfs2(g[cur].front(), top, id);
      heavy_l[cur] = heavy_l[g[cur].front()];
    } else {
      heavy_l[cur] = cur;
    }
    for (int i = 1; i < int(g[cur].size()); i++) dfs2(g[cur][i], g[cur][i], id);
  }

  void build() {
    int id = 0;
    dfs(root, -1);
    dfs2(root, root, id);
  }

 public:
  hld(int n, int root = 0) : n(n), root(root), edge(0), g(n), heavy_p(n, -1), heavy_l(n, -1), light_p(n, -1), idx(n), xdi(n), sub_siz(n) {}

  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    edge++;
    if (edge == n - 1) build();
  }

  int lca(int u, int v) {
    while (heavy_p[u] != heavy_p[v]) {
      if (idx[u] > idx[v]) swap(u, v);
      v = light_p[heavy_p[v]];
    }
    return idx[u] < idx[v] ? u : v;
  }

  int dist(int u, int v) {
    int res = 0;
    while (heavy_p[u] != heavy_p[v]) {
      if (idx[u] > idx[v]) swap(u, v);
      res += idx[v] - idx[heavy_p[v]] + 1;
      v = light_p[heavy_p[v]];
    }
    res += abs(idx[u] - idx[v]);
    return res;
  }

  int meet(int r, int u, int v) {
    return lca(r, u) ^ lca(u, v) ^ lca(v, r);
  }

  int jump(int u, int v, int64_t d) {
    int from = u;
    int to = v;
    bool p = false;
    int ul_dist = 0;
    int lv_dist = 0;
    while (heavy_p[u] != heavy_p[v]) {
      if (idx[u] > idx[v]) {
        p = !p;
        swap(u, v);
        swap(ul_dist, lv_dist);
      }
      ul_dist += idx[v] - idx[heavy_p[v]] + 1;
      v = light_p[heavy_p[v]];
    }
    if (idx[u] > idx[v]) {
      p = !p;
      swap(u, v);
      swap(ul_dist, lv_dist);
    }
    ul_dist += idx[v] - idx[u];
    if (!p) {
      swap(ul_dist, lv_dist);
    }
    if (d <= ul_dist) {
      return la(from, d);
    }
    d -= ul_dist;
    if (d <= lv_dist) {
      return la(to, lv_dist - d);
    }
    return -1;
  }

  int la(int v, int64_t k) {
    while (v != -1) {
      int p = heavy_p[v];
      if (idx[v] - idx[p] >= k) {
        v = xdi[idx[v] - k];
        break;
      }
      k -= (idx[v] - idx[p] + 1);
      v = (p == root ? -1 : light_p[p]);
    }

    return v;
  }

  int subtree_size(int v) {
    return sub_siz[v];
  }

  int traverse_begin(int v) {
    return idx[v];
  }

  int traverse_end(int v) {
    return idx[v] + sub_siz[v];
  }

  bool contains_path(int from, int to, int v) {
    return meet(v, from, to) == v;
  }

  bool contains_subtree(int r, int v) {
    return traverse_begin(r) <= traverse_begin(v) and traverse_end(v) <= traverse_end(r);
  }

  pair<vector<int>, vector<int>> lca_based_auxiliary_tree(vector<int> v) {
    if (v.empty()) return {{}, {}};
    int siz = int(v.size());
    auto pre_order = [&](int i, int j) -> bool { return idx[i] < idx[j]; };
    sort(v.begin(), v.end(), pre_order);
    for (int i = 0; i < siz - 1; i++) v.emplace_back(lca(v[i], v[i + 1]));
    sort(v.begin(), v.end(), pre_order);
    v.erase(unique(v.begin(), v.end()), v.end());

    siz = int(v.size());
    vector<int> par(siz, -1);
    stack<int> st;
    st.emplace(0);
    for (int i = 1; i < siz; i++) {
      while (!st.empty() and traverse_end(v[st.top()]) <= traverse_begin(v[i])) st.pop();
      par[i] = st.top();
      st.push(i);
    }
    return {par, v};
  }
};