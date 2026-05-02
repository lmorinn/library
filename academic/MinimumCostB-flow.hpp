template <class Cap, class Cost>
class min_cost_flow {
 private:
  const Cost INF = numeric_limits<Cost>::max() / 4;
  struct Edge {
    int to;
    Cap cap, flow;
    Cost cost;
    int rev;
    bool is_rev;
  };

  vector<pair<int, int>> edge_id;
  vector<vector<Edge>> g;
  Cost base_cost = 0;
  int n;

 public:
  vector<Cost> p;
  min_cost_flow(int n) : n(n) {
    g.resize(n);
  }

  const Edge get_edge(int id) {
    auto [vid, eid] = edge_id[id];
    if (vid >= n) {
      int v = vid - n;
      return Edge{v, 0, eid, 0, 0, 0};
    }
    return g[vid][eid];
  }

  void edge_status() {
    for (int i = 0; i < n; i++) {
      for (auto [to, cap, flow, cost, rev, is_rev] : g[i]) {
        if (is_rev) continue;
        out(i, "->", to, " : ", flow);
      }
    }
  }

  void add_edge(int from, int to, Cap lower, Cap upper, Cost cost) {
    assert(lower <= upper);
    Cap x;
    if (cost >= 0) {
      x = lower;
    } else {
      x = upper;
    }

    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from != to) {
      edge_id.emplace_back(from, from_id);
    } else {
      edge_id.emplace_back(n + from, x);
    }
    if (from != to) {
      g[from].push_back({to, upper, x, cost, to_id, false});
      g[to].push_back({from, upper - lower, upper - x, -cost, from_id, true});
    } else {
      base_cost += x * cost;
      return;
    }
  }

  Cost flow(vector<Cap> e) {
    for (int i = 0; i < n; i++) {
      for (auto const& edge : g[i]) {
        if (edge.is_rev) continue;
        int to = edge.to;
        Cap x = edge.flow;
        e[i] -= x;
        e[to] += x;
      }
    }
    vector<Cost> pot(n);
    vector<Cost> dist(n, INF);
    vector<int> prev_v(n, -1);
    vector<int> prev_e(n, -1);
    vector<bool> fin(n, false);
    while (1) {
      int s = -1;
      for (int i = 0; i < n; i++) {
        if (e[i] > 0) {
          s = i;
          break;
        }
      }

      if (s != -1) {
        fill(dist.begin(), dist.end(), INF);
        fill(prev_v.begin(), prev_v.end(), -1);
        fill(prev_e.begin(), prev_e.end(), -1);
        fill(fin.begin(), fin.end(), false);
        dist[s] = 0;

        priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> q;
        q.emplace(0, s);
        while (!q.empty()) {
          auto [cur_d, cur] = q.top();
          q.pop();
          if (fin[cur]) continue;
          fin[cur] = true;
          for (int i = 0; i < int(g[cur].size()); i++) {
            const Edge& edge = g[cur][i];
            if (edge.cap - edge.flow <= 0) continue;
            Cost len = edge.cost - pot[cur] + pot[edge.to];
            if (!fin[edge.to] and dist[edge.to] > cur_d + len) {
              dist[edge.to] = cur_d + len;
              prev_v[edge.to] = cur;
              prev_e[edge.to] = i;
              q.emplace(dist[edge.to], edge.to);
            }
          }
        }

        int k = -1;
        for (int i = 0; i < n; i++) {
          if (e[i] < 0 and dist[i] != INF) {
            if (k == -1 or dist[i] < dist[k]) {
              k = i;
            }
          }
        }

        if (k != -1) {
          Cost D = dist[k];
          for (int i = 0; i < n; i++) {
            Cost delta = (dist[i] == INF ? D : min(dist[i], D));
            pot[i] -= delta;
          }
          Cap epsilon = min(e[s], -e[k]);
          int cur = k;
          while (cur != s) {
            int pv = prev_v[cur];
            int pe = prev_e[cur];
            const Edge& edge = g[pv][pe];
            Cap residual_cap = edge.cap - edge.flow;
            if (epsilon > residual_cap) epsilon = residual_cap;
            cur = pv;
          }

          cur = k;
          while (cur != s) {
            int pv = prev_v[cur];
            int pe = prev_e[cur];
            Edge& edge = g[pv][pe];
            edge.flow += epsilon;
            g[edge.to][edge.rev].flow -= epsilon;
            cur = prev_v[cur];
            cur = pv;
          }
          e[s] -= epsilon;
          e[k] += epsilon;
        } else {
          // 可能流が存在しない
          return numeric_limits<Cost>::max();
          break;
        }
      } else {
        break;
      }
    }

    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = -pot[i];
    }
    Cost z = base_cost;
    for (int i = 0; i < n; i++) {
      for (auto const& edge : g[i]) {
        if (edge.is_rev) continue;
        z += edge.flow * edge.cost;
      }
    }
    return z;
  }
};