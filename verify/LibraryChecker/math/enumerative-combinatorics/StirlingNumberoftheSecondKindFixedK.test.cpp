#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;

#include "../../../../math/enumerative-combinatorics/StirlingNumberoftheSecondKindFixedK.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  in(n, k);
  FPS<mint> res = Stirling_number_2nd_fixed_k<mint>(n, k);
  rep(i, k, n + 1) {
    cout << res[i].val();
    if (i != n) cout << " ";
  }
  out();
}
