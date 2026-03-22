#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "../../../atcoder/modint.hpp"
#include "../../../linear-algebra/Matrix.hpp"
using namespace atcoder;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  Matrix<modint998244353> a(n);
  rep(i, n) rep(j, n) {
    int x;
    in(x);
    a[i][j] = x;
  }
  auto [res, inverse] = a.inverse();
  if (res) {
    rep(i, n) {
      rep(j, n) {
        cout << inverse[i][j].val();
        if (j != n - 1) cout << ' ';
      }
      out();
    }
  } else {
    out(-1);
  }
}
