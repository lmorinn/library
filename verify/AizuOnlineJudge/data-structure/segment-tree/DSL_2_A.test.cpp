#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include <bits/stdc++.h>

using namespace std;
#include "../../../../data-structure/segment-tree/SegmentTree.hpp"

using S = int;
S op(S a, S b) {
  return min(a, b);
}

S e() {
  return (1LL << 31) - 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<S> v(n, e());
  segtree<S, op, e> seg(v);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      seg.set(x, y);
    } else if (com == 1) {
      cout << seg.prod(x, y + 1) << "\n";
    }
  }
}