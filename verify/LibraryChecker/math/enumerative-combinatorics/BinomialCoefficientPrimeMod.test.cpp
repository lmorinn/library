#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;

#include "../../../../math/enumerative-combinatorics/BinomialCoefficientPrimeMod.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t, m, inf = 1e7;
  in(t, m);
  modint::set_mod(m);
  BinomialCoefficient<modint> b(min(inf, m - 1));
  rep(z, t) {
    int n, r;
    in(n, r);
    out(b.nCr(n, r).val());
  }
}
