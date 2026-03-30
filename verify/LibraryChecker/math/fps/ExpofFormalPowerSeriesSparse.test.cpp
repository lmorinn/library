#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;

#include "../../../../math/fps/FormalPowerSeries.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  in(n, k);
  SFPS<mint> h(k);
  rep(i, k) {
    int d, c;
    in(d, c);
    h[i] = {d, c};
  }
  FPS<mint> l = h.exp(n);

  rep(i, n) {
    cout << l[i].val();
    if (i != n - 1) cout << " ";
  }
  out();
}
