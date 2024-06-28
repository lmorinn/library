#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"
#include "../../../geometry/Geometry.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c, d, e, f;
  in(a, b, c, d, e, f);
  Circle c1(Point(a, b), c);
  Circle c2(Point(d, e), f);
  out(intersect(c1, c2));
}
