template <class Cap>
class max_flow {
 private:
  struct Edge {
    int from, to;
    Cap cap, flow;
    int rev;
  };

  vector<pair<int, int>> edge_id;
  vector<vector<Edge>> g;
  int n;

 public:
  max_flow(int n) : n(n) {
    g.resize(n);
  }

  void add_edge(int from, int to, Cap cap) {
    assert(from != to);
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    edge_id.emplace_back(from, from_id);
    g[from].push_back({from, to, cap, 0, to_id});
    g[to].push_back({to, from, cap, cap, from_id});
  }

  const Edge& get_edge(int id) {
    auto [vid, eid] = edge_id[id];
    return g[vid][eid];
  }

  Cap flow(int s, int t) {
    Cap res = 0;
    vector<int> iter(n, -1);
    vector<int> dist(n, -1);

    auto bfs = [&](int s) -> void {
      fill(dist.begin(), dist.end(), -1);
      queue<int> q;
      dist[s] = 0;
      q.push(s);
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < int(g[cur].size()); i++) {
          Edge& edge = g[cur][i];
          if (edge.cap - edge.flow <= 0 or dist[edge.to] != -1) continue;
          dist[edge.to] = dist[cur] + 1;
          q.push(edge.to);
        }
      }
    };

    auto dfs = [&](auto& self, int cur, Cap epsilon) -> Cap {
      if (cur == t) return epsilon;
      for (int& i = iter[cur]; i < int(g[cur].size()); i++) {
        Edge& edge = g[cur][i];
        if (edge.cap - edge.flow <= 0 or dist[cur] >= dist[edge.to]) continue;
        Cap d = self(self, edge.to, min(epsilon, edge.cap - edge.flow));
        if (d > 0) {
          edge.flow += d;
          g[edge.to][edge.rev].flow -= d;
          return d;
        }
      }
      return 0;
    };

    while (1) {
      bfs(s);
      if (dist[t] < 0) break;
      fill(iter.begin(), iter.end(), 0);
      Cap f;
      while (f = dfs(dfs, s, numeric_limits<Cap>::max())) res += f;
    }

    return res;
  }

  vector<bool> min_cut(int s) {
    vector<bool> reachable(n, false);
    auto dfs = [&](auto& self, int cur) -> void {
      reachable[cur] = true;
      for (int i = 0; i < int(g[cur].size()); i++) {
        const Edge& edge = g[cur][i];
        if (edge.cap - edge.flow <= 0 or reachable[edge.to]) continue;
        self(self, edge.to);
      }
    };
    dfs(dfs, s);
    return reachable;
  }
};