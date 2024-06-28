#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B"
#define ERROR 1e-8
#include "../../../geometry/Geometry.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c, d, e, f;
  in(a, b, c, d, e, f);
  Point p1(a, b);
  Point p2(c, d);
  Point p3(e, f);
  Circle res = inCircle(p1, p2, p3);
  outf(res.c, res.r);
}
