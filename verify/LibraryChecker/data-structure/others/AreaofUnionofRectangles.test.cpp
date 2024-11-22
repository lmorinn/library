#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include "../../../../data-structure/others/AreaofUnionofRectangles.hpp"

using S = lint;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<lint> x1(n), x2(n), y1(n), y2(n);
  rep(i, n) {
    in(x1[i], y1[i], x2[i], y2[i]);
  }
  AreaofUnionofRectangles t(x1, x2, y1, y2);
  out(t.ans());
}
