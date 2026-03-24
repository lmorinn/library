#include "../tree/CountingSpanningTrees.hpp"

template <class S>
struct CountingEulerianCircuits {
 private:
  int n;
  vector<vector<long long>> g;
  vector<S> fac;
  int out_mx = 1;

 public:
  CountingEulerianCircuits(int n) : n(n), g(n, vector<long long>(n)), fac(1) { fac[0] = 1; }
  void add_edge(int u, int v, int w = 1) {
    g[u][v] += w;
  }

  S count_eulerian_circuits() {
    vector<long long> ods(n);
    vector<int> ids;
    for (int i = 0; i < n; i++) {
      long long diff = 0;
      long long outdeg = 0;
      for (int j = 0; j < n; j++) {
        diff += g[i][j] - g[j][i];
        outdeg += g[i][j];
      }
      if (diff != 0) return 0;
      if (out_mx < outdeg) out_mx = outdeg;
      ods[i] = outdeg;
    }

    if (fac.size() < out_mx) {
      int siz = fac.size();
      fac.resize(out_mx);
      for (int i = siz; i < out_mx; i++) {
        fac[i] = fac[i - 1] * i;
      }
    }
    S res = 1;
    for (int i = 0; i < n; i++) {
      if (ods[i]) {
        ids.emplace_back(i);
        res *= fac[ods[i] - 1];
      }
    }

    int siz = ids.size();
    CountingSpanningTrees<S> t(siz, false, 0);
    for (int i = 0; i < siz; i++) {
      for (int j = 0; j < siz; j++) {
        t.add_edge(i, j, g[ids[i]][ids[j]]);
      }
    }
    res *= t.count_spanning_trees();
    return res;
  }
};