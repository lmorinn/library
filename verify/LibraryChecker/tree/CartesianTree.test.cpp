#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "../../../graph/tree/CartesianTree.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<int> a(n);
  in(a);
  CartesianTree<int> c(a);
  out(c.parent);
}
