#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include "../../../template/template.hpp"
using namespace std;
#include "../../../geometry/SortPointsbyArgument.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<Point> p(n);
  rep(i, n) in(p[i].x, p[i].y);
  sort(all(p), cmp<less()>);
  rep(i, n) {
    out(p[i].x, p[i].y);
  }
}
