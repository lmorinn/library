#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"
#define ERROR 1e-8
#include "../../../geometry/Geometry.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  Polygon p(n);
  rep(i, n) {
    int x, y;
    in(x, y);
    p[i] = Point(x, y);
  }
  outf(PolygonArea(p));
}
