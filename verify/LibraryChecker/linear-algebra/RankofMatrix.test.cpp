#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "../../../atcoder/modint.hpp"
#include "../../../linear-algebra/Matrix.hpp"
using namespace atcoder;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  in(n, m);
  Matrix<modint998244353> a(n, m);
  rep(i, n) rep(j, m) {
    int x;
    in(x);
    a[i][j] = x;
  }
  out(a.rank());
}
