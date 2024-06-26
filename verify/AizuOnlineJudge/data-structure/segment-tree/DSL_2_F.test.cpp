#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include <bits/stdc++.h>

using namespace std;
#include "../../../../data-structure/segment-tree/LazySegmentTree.hpp"

using S = long long;
using F = long long;

const S INF = (1LL << 31) - 1;
const F ID = (1LL << 31) + 1;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<S> v(n, e());
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  for (int i = 0; i < q; i++) {
    int com, x, y, z;
    cin >> com;
    if (com == 0) {
      cin >> x >> y >> z;
      seg.apply(x, y + 1, z);
    } else if (com == 1) {
      cin >> x >> y;
      cout << seg.prod(x, y + 1) << "\n";
    }
  }
}