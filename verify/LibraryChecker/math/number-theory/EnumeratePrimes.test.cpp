#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../../../../math/number-theory/SieveofEratosthenes.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b;
  in(n, a, b);
  vector<bool> prime = prime_table(n);
  vector<int> res;
  int cnt = 0;
  int k = 0;
  rep(i, 1, n + 1) {
    if (prime[i]) {
      cnt++;
      if (cnt - 1 == a * k + b) {
        res.emplace_back(i);
        k++;
      }
    }
  }

  out(cnt, res.size());
  out(res);
}
