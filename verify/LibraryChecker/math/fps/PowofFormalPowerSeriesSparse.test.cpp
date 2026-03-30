#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;
#include "../../../../math/fps/FormalPowerSeries.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  lint n, k, m;
  in(n, k, m);
  SFPS f(k);
  rep(i, k) {
    int d, c;
    in(d, c);
    f[i] = {d, c};
  }

  FPS res = f.pow(m, n);
  rep(i, n) {
    cout << res[i].val();
    if (i != n - 1) cout << " ";
  }
  out();
}
