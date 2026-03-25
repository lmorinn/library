#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "../../../../atcoder/modint.hpp"
#include "../../../../atcoder/convolution.hpp"
using namespace atcoder;
using mint = modint998244353;
#include "../../../../math/fps/FormalPowerSeries.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  FPS f(n);
  rep(i, n) {
    int x;
    in(x);
    f[i] = x;
  }

  f = f.inv();
  rep(i, n) {
    cout << f[i].val() << (i + 1 != n ? " " : "\n");
  }
}
