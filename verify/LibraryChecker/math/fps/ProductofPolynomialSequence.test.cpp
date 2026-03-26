#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include "../../../../math/fps/ProductofPolynomialSequence.hpp"

using namespace atcoder;
using mint = modint998244353;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<vector<mint>> poly(n);
  rep(i, n) {
    int d;
    in(d);
    poly[i].resize(d + 1);
    rep(j, d + 1) {
      int c;
      in(c);
      poly[i][j] = c;
    }
  }
  vector<mint> res = product_of_polynomial_sequence(poly);
  int siz = res.size();
  rep(i, siz) {
    cout << res[i].val();
    if (i != siz - 1) cout << " ";
  }
  out();
}
