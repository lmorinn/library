#include "../../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"
#include "../../../../../data-structure/wavelet-matrix/query/RectangleAddPointGet.hpp"

using S = lint;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  vector<S> x1(n), y1(n), x2(n), y2(n), w(n);
  rep(i, n) {
    in(x1[i], y1[i], x2[i], y2[i], w[i]);
  }

  RectangleAddPointGet<S> t(x1, y1, x2, y2, w, q);

  rep(i, q) {
    int com;
    in(com);
    if (com == 0) {
      S lx, ly, rx, ry, weight;
      in(lx, ly, rx, ry, weight);
      t.rectangle_add(lx, ly, rx, ry, weight);
    } else {
      S x, y;
      in(x, y);
      t.get(x, y);
    }
  }

  for (const S &res : t.build()) {
    out(res);
  }
}
