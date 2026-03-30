#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;

#include "../../../../math/enumerative-combinatorics/StirlingNumberoftheSecondKind.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  FPS<mint> res = Stirling_number_2nd<mint>(n);
  rep(i, n + 1) {
    cout << res[i].val();
    if (i != n) cout << " ";
  }
  out();
}
