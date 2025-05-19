#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "../../../../math/number-theory/CountingPrimes.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  lint n;
  in(n);
  out(count_prime(n));
}
