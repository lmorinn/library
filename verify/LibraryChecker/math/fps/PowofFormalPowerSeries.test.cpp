#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;
#include "../../../../math/fps/FormalPowerSeries.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  lint n, m;
  in(n, m);
  FPS<mint> a(n);
  rep(i, n) {
    int x;
    in(x);
    a[i] = x;
  }

  a = a.pow(m);
  rep(i, n) {
    cout << a[i].val();
    if (i != n - 1) cout << " ";
  }
  out();
}
