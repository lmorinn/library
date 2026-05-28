#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../../graph/tree/HLD.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  hld t(n);
  rep(i, n - 1) {
    int u, v;
    in(u, v);
    t.add_edge(u, v);
  }

  rep(i, q) {
    int u, v, d;
    in(u, v, d);
    out(t.jump(u, v, d));
  }
}
