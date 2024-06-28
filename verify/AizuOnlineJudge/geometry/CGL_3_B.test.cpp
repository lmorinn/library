#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"
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
  out(isConvex(p));
}
