#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"
#include "../../../../academic/MaxflowAugmentingPath.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int v, e;
  in(v, e);
  max_flow<int> g(v);
  rep(i, e) {
    int u, v, c;
    in(u, v, c);
    g.add_edge(u, v, c);
  }
  out(g.flow(0, v - 1));
}