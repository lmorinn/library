#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;
#include "../../../../math/fps/FormalPowerSeries.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  in(n, k);
  FPS<mint> f(n);
  f[0] = 1;
  SFPS<mint> h(k);
  rep(i, k) {
    int d, c;
    in(d, c);
    h[i] = {d, c};
  }
  f /= h;

  rep(i, n) {
    cout << f[i].val();
    if (i != n - 1) cout << " ";
  }
  out();
}
