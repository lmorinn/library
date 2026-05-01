#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../graph/tree/LowestCommonAncestor.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  TreeQuery t(n);
  rep(i, 1, n) {
    int p;
    in(p);
    t.add_edge(i, p);
  }
  rep(i, q) {
    int u, v;
    in(u, v);
    out(t.lca(u, v));
  }
}
