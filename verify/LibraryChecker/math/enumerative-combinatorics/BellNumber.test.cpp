#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;

#include "../../../../math/enumerative-combinatorics/BellNumber.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  FPS<mint> b = Bell_number<mint>(n);
  rep(i, n + 1) {
    cout << b[i].val();
    if (i != n) cout << " ";
  }
  out();
}
