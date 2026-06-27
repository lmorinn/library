vector<vector<int>> compress_graph(const vector<vector<int>>& g) {
  int n = (int)g.size();

  vector<int> deg(n);
  vector<char> alive(n, true);
  queue<int> que;
  vector<set<int>> h;
  vector<char> is_branch(n, false);
  vector<int> id(n, -1);

  auto new_vertex = [&]() {
    int id = (int)h.size();
    h.emplace_back();
    return id;
  };

  auto add_edge = [&](int a, int b) {
    if (a == b) return;
    if (h[a].contains(b)) return;
    h[a].insert(b);
    h[b].insert(a);
  };

  auto add_compressed_path = [&](int a, int b) {
    if (a == b) {
      int x = new_vertex();
      int y = new_vertex();
      add_edge(a, x);
      add_edge(x, y);
      add_edge(y, a);
      return;
    }

    if (!h[a].contains(b)) {
      add_edge(a, b);
    } else {
      int x = new_vertex();
      add_edge(a, x);
      add_edge(x, b);
    }
  };

  auto edge_key = [&](int a, int b) {
    if (a > b) swap(a, b);
    return 1LL * a * n + b;
  };

  for (int i = 0; i < n; i++) {
    deg[i] = (int)g[i].size();
    if (deg[i] <= 1) que.push(i);
  }

  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    if (!alive[cur] or deg[cur] > 1) continue;
    alive[cur] = false;
    for (int nex : g[cur]) {
      if (!alive[nex]) continue;
      deg[nex]--;
      if (deg[nex] == 1) que.push(nex);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!alive[i]) continue;
    if (deg[i] != 2) {
      is_branch[i] = true;
      id[i] = new_vertex();
    }
  }

  unordered_set<long long> used_edge;
  vector<char> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!alive[i] or !is_branch[i]) continue;

    for (int nex : g[i]) {
      if (!alive[nex]) continue;
      long long hash = edge_key(i, nex);
      if (used_edge.contains(hash)) continue;
      used_edge.insert(hash);

      int prev = i;
      int cur = nex;

      while (!is_branch[cur]) {
        visited[cur] = true;
        int nxt = -1;
        for (int x : g[cur]) {
          if (!alive[x] or x == prev) continue;
          nxt = x;
          break;
        }
        used_edge.insert(edge_key(cur, nxt));
        prev = cur;
        cur = nxt;
      }
      add_compressed_path(id[i], id[cur]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!alive[i] or is_branch[i] or visited[i]) continue;
    int a = new_vertex();
    int b = new_vertex();
    int c = new_vertex();

    add_edge(a, b);
    add_edge(b, c);
    add_edge(c, a);

    queue<int> q;
    q.push(i);
    visited[i] = true;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nex : g[cur]) {
        if (!alive[nex]) continue;
        if (is_branch[nex]) continue;
        if (visited[nex]) continue;
        visited[nex] = true;
        q.push(nex);
      }
    }
  }

  vector<vector<int>> res(h.size());
  for (int i = 0; i < (int)h.size(); i++) {
    for (int nex : h[i]) {
      res[i].push_back(nex);
    }
  }

  return res;
}

struct cycle_basis {
 private:
  int n, m, c;
  int t = 0;
  vector<vector<pair<int, int>>> g;
  vector<int> time;
  vector<pair<int, int>> par;

  void dfs(int cur) {
    time[cur] = ++t;
    for (auto [nex, eid] : g[cur]) {
      if (time[nex] == 0) {
        par[nex] = {cur, eid};
        dfs(nex);
      } else if (time[cur] < time[nex]) {
        //  out("getbasis", cur, nex);
        basis.emplace_back(get_basis(cur, nex, eid));
        //  out(basis.back().to_string());
      }
    }
  }

  tr2::dynamic_bitset<> get_basis(int u, int v, int id) {
    tr2::dynamic_bitset<> b(m);
    b[id] = 1;
    while (u != v) {
      if (time[u] < time[v]) {
        auto [p, eid] = par[v];
        b[eid] = 1;
        v = p;
      } else {
        auto [p, eid] = par[u];
        b[eid] = 1;
        u = p;
      }
    }
    return b;
  }

 public:
  vector<tr2::dynamic_bitset<>> basis;
  vector<pair<int, int>> edge;

  cycle_basis(int n) : n(n), g(n), time(n), par(n, {-1, -1}), m(0) {}

  void add_edge(int u, int v) {
    assert(0 <= u and u < n and 0 <= v and v < n);
    g[u].emplace_back(v, m);
    g[v].emplace_back(u, m);
    edge.emplace_back(u, v);
    m++;
  }

  void build() {
    for (int i = 0; i < n; i++) {
      if (time[i] == 0) {
        c++;
        dfs(i);
      }
    }
  }

  void solve() {
    int siz = int(basis.size());
  }
};