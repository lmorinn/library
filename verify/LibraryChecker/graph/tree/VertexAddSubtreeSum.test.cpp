#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../../../data-structure/binary-indexed-tree/BinaryIndexedTree.hpp"
#include "../../../../graph/tree/HLD.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  hld t(n);
  fenwick_tree<lint> f(n);
  vector<int> a(n);

  in(a);
  rep(i, 1, n) {
    int p;
    in(p);
    t.add_edge(i, p);
  }

  rep(i, n) f.add(t.traverse_begin(i), a[i]);
  rep(i, q) {
    int com;
    in(com);
    if (com == 0) {
      int u, x;
      in(u, x);
      f.add(t.traverse_begin(u), x);
    } else {
      int u;
      in(u);
      out(f.sum(t.traverse_begin(u), t.traverse_end(u)));
    }
  }
}
