#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "../../../../atcoder/modint.hpp"
#include "../../../../math/number-theory/GCDConvolution.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  vector<atcoder::modint998244353> a(n + 1), b(n + 1);
  rep(i, 1, n + 1) {
    int x;
    in(x);
    a[i] = x;
  }
  rep(i, 1, n + 1) {
    int x;
    in(x);
    b[i] = x;
  }

  vector<atcoder::modint998244353> c = gcd_convolution(a, b);

  rep(i, 1, n + 1) {
    cout << c[i].val();
    if (i != n) cout << " ";
  }
  out();
}