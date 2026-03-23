#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
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
  vector<modint998244353> b(n);
  rep(i, n) {
    int x;
    in(x);
    b[i] = x;
  }
  Matrix<modint998244353> sol = a.linear_equation(b);
  if (sol.size() == 0) {
    out(-1);
  } else {
    out(sol.size() - 1);
    rep(i, sol.size()) {
      rep(j, m) {
        cout << sol[i][j].val();
        if (j != m - 1) cout << " ";
      }
      out();
    }
  }
}
