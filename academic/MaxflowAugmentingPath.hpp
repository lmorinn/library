template <class Cap>
class max_flow {
 private:
  struct Edge {
    int to;
    Cap cap, flow;
    int rev;
    bool is_rev;
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
    g[from].push_back({to, cap, 0, to_id, false});
    g[to].push_back({from, cap, cap, from_id, true});
  }

  const Edge get_edge(int id) {
    auto [vid, eid] = edge_id[id];
    return g[vid][eid];
  }

  Cap flow(int s, int t) {
    Cap res = 0;
    vector<bool> seen(n, false);
    while (1) {
      fill(seen.begin(), seen.end(), false);
      auto dfs = [&](auto& self, int cur, Cap epsilon) -> Cap {
        if (cur == t) return epsilon;
        seen[cur] = true;
        for (int i = 0; i < int(g[cur].size()); i++) {
          Edge& edge = g[cur][i];
          if (edge.cap - edge.flow <= 0 or seen[edge.to]) continue;
          Cap d = self(self, edge.to, min(epsilon, edge.cap - edge.flow));
          if (d > 0) {
            edge.flow += d;
            g[edge.to][edge.rev].flow -= d;
            return d;
          }
        }
        return 0;
      };
      Cap f = dfs(dfs, s, numeric_limits<Cap>::max());
      if (f == 0) break;
      res += f;
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