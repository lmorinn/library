#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 1e-8
#include "../../../geometry/Geometry.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c, d;
  in(a, b, c, d);
  Line l(Point(x1, y1), Point(x2, y2));
  int q;
  in(q);
  for (int i = 0; i < q; i++) {
    int x, y;
    in(x, y);
    outf(reflect(l, Point(x, y)));
  }
}
