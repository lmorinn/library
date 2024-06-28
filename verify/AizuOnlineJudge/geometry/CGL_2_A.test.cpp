#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"
#include "../../../geometry/Geometry.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q;
  in(q);
  rep(i, q) {
    int a, b, c, d, e, f, g, h;
    in(a, b, c, d, e, f, g, h);
    Line l1(Point(a, b), Point(c, d));
    Line l2(Point(e, f), Point(g, h));
    if (isParallel(l1, l2)) {
      out(2);
    } else if (isOrthogonal(l1, l2)) {
      out(1);
    } else {
      out(0);
    }
  }
}
