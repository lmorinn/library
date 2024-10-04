#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235"
#include "../../../../graph/connectivity/OnlineDynamicConnectivity.hpp"

using S = bool;

S op(S a, S b) {
  return a;
}

S e() {
  return 0;
}

using F = bool;

S mapping(F x, S a) {
  return a;
}

F composition(F g, F f) {
  return f;
}

F id() {
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  dynamic_connectivity<S, op, e, F, mapping, composition, id> g(n);

  rep(i, q) {
    int com, u, v;
    in(com, u, v);
    if (com == 1) {
      g.link(u, v);
    } else if (com == 2) {
      g.cut(u, v);
    } else if (com == 3) {
      out(g.is_connected(u, v) ? "YES" : "NO");
    }
  }
}
