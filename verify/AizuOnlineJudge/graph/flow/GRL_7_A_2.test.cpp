#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A"
#include "../../../../academic/MinimumCostB-flow.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, y, e;
  int inf = 1e7;
  in(x, y, e);
  min_cost_flow<int, int> g(x + y + 2);
  g.add_edge(x + y + 1, x + y, 0, inf, -1);
  rep(i, x) g.add_edge(x + y, i, 0, 1, 0);
  rep(i, y) g.add_edge(x + i, x + y + 1, 0, 1, 0);

  rep(i, e) {
    int u, v;
    in(u, v);
    g.add_edge(u, x + v, 0, 1, 0);
  }
  vector<int> b(x + y + 2);
  out(-g.flow(b));
}
