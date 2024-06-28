#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 1e-8
#include <bits/stdc++.h>
using namespace std;
#include "../../../geometry/Geometry.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  Line l(Point(x1, y1), Point(x2, y2));
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    outf(reflect(l, Point(x, y)));
  }
}
