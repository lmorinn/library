#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../../atcoder/modint.hpp"
#include "../../../linear-algebra/Matrix.hpp"
using namespace atcoder;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  in(n, m, k);
  Matrix<modint998244353> a(n, m), b(m, k);
  rep(i, n) rep(j, m) {
    int x;
    in(x);
    a[i][j] = x;
  }

  rep(i, m) rep(j, k) {
    int x;
    in(x);
    b[i][j] = x;
  }

  Matrix<modint998244353> c = a * b;
  rep(i, n) {
    rep(j, k) {
      cout << c[i][j].val();
      if (j != k - 1) cout << " ";
    }
    out();
  }
}
