#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
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
  out(a.determinant().val());
}
