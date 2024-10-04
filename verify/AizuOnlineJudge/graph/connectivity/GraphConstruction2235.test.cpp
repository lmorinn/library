#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235"
#include "../../../../graph/connectivity/OfflineDynamicConnectivityDFS.hpp"

using S = int;

S op(S a, S b) {
  return a + b;
}

S e() {
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  OfflineDynamicConnectivity<S, op, e> g(n);

  rep(i, q) {
    int com, u, v;
    in(com, u, v);
    if (com == 1) {
      g.link(u, v);
    } else if (com == 2) {
      g.cut(u, v);
    } else if (com == 3) {
      g.is_connected(u, v);
    }
  }

  for (auto x : g.build()) {
    out(x ? "YES" : "NO");
  }
}
