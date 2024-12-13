#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "../../../../data-structure/others/MergeSortTree.hpp"

using S = lint;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);

  MergeSortTree t(a);
  rep(i, q) {
    int l, r, x;
    in(l, r, x);
    out(t.range_freq(l, r, x, x + 1));
  }
}
