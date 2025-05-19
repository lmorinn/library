#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "../../../../math/number-theory/PrimalityTest.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q;
  in(q);
  rep(i, q) {
    long long n;
    in(n);
    if (is_prime(n)) {
      out("Yes");
    } else {
      out("No");
    }
  }
}