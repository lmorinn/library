#include "../../../../atcoder/modint.hpp"
#include "../../../../template/template.hpp"
using namespace atcoder;
#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"
#include "../../../../graph/tree/CountingSpanningTrees.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  in(n, m);
  CountingSpanningTrees<modint998244353> t(n);
  rep(i, m) {
    int u, v;
    in(u, v);
    t.add_edge(v, u);
  }
  out(t.count_spanning_trees().val());
}
