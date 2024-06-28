#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#include "../../../geometry/Geometry.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q;
  in(q);
  rep(i, q) {
    int a, b, c, d, e, f, g, h;
    in(a, b, c, d, e, f, g, h);
    Segment l1(Point(a, b), Point(c, d));
    Segment l2(Point(e, f), Point(g, h));
    outf(CrossPoint(l1, l2));
  }
}
