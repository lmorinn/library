#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../../../atcoder/modint.hpp"
#include "../../../../math/set-function/BitwiseANDConvolution.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<atcoder::modint998244353> a(1 << n), b(1 << n);
  rep(i, 1 << n) {
    int x;
    in(x);
    a[i] = x;
  }

  rep(i, 1 << n) {
    int x;
    in(x);
    b[i] = x;
  }

  vector<atcoder::modint998244353> c = and_convolution(n, a, b);
  rep(i, 1 << n) {
    cout << c[i].val();
    if (i != (1 << n) - 1) cout << " ";
  }
  out();
}
