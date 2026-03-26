#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;

#include "../../../../math/enumerative-combinatorics/Sharp_P_SubsetSum.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, t;
  in(n, t);
  vector<long long> s(n);
  in(s);
  FPS res = sharp_p_subset_sum(s, t);
  rep(i, 1, t + 1) {
    cout << res[i].val();
    if (i != t) cout << " ";
  }
  out();
}
