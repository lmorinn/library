template <class Cost>
class BellmanFord {
 private:
  int n;
  vector<tuple<int, int, Cost>> edges;

 public:
  vector<Cost> dist;
  Cost mx;
  BellmanFord() {}
  BellmanFord(int n) : n(n) {
    mx = numeric_limits<Cost>::max();
  }

  void add_edge(int u, int v, Cost c) {
    assert(0 <= u and u < n and 0 <= v and v < n);
    edges.emplace_back(u, v, c);
  }

  bool shortest_path(int s) {
    assert(0 <= s and s < n);
    dist.assign(n, mx);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
      for (const auto& [u, v, c] : edges) {
        if (dist[u] != mx and dist[v] > dist[u] + c) dist[v] = dist[u] + c;
      }
    }
    for (const auto& [u, v, c] : edges) {
      if (dist[u] != mx and dist[u] + c < dist[v]) {
        return false;
      }
    }
    return true;
  }
};