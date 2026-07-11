#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/4077"
#include "../../../../data-structure/others/MultiDimensionalSum.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<int> v(n);
  in(v);
  int siz = 1;
  multi_dimensional_sum<lint> sum(v);
  rep(i, n) siz *= v[i];

  vector<int> x(n, 0);
  rep(i, siz) {
    lint c;
    in(c);
    sum.add(x, c);
    x.back()++;
    if (x.back() >= v.back()) {
      for (int j = n - 1; j > 0; j--) {
        if (x[j] >= v[j]) {
          x[j] = 0;
          x[j - 1]++;
        }
      }
    }
  }
  sum.build();

  int q;
  in(q);
  vector<int> l(n), r(n);
  rep(i, q) {
    rep(j, n) in(l[j], r[j]);
    out(sum.calc(l, r));
  }
}