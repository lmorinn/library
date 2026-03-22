#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A"
#include "../../../../graph/flow/MaximumMatchingSize.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, y, e;
  in(x, y, e);
  MaximumMatchingsize g(x + y);
  rep(i, e) {
    int u, v;
    in(u, v);
    v += x;
    g.add_edge(u, v);
  }
  out(g.maximum_matching());
}
