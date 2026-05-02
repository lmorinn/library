#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"
#include "../../../../academic/MinimumCostB-flow.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  lint v, e, f;
  in(v, e, f);
  min_cost_flow<lint, lint> g(v);
  rep(i, e) {
    lint from, to, cap, d;
    in(from, to, cap, d);
    g.add_edge(from, to, 0, cap, d);
  }
  vector<lint> b(v);
  b[0] = f;
  b[v - 1] = -f;
  lint res = g.flow(b);
  if (res == LLONG_MAX) {
    out(-1);
  } else {
    out(res);
  }
}
