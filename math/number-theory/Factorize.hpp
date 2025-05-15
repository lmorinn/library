#include "PrimalityTest.hpp"

long long find_prime_factor(long long n) {
  if ((n & 1) == 0) return 2;
  long long m = int64_t(powl(n, 0.125)) + 1;
  for (int i = 1; i < n; i++) {
    long long y = 0;
    long long g = 1;
    long long q = 1;
    long long r = 1;
    long long k = 0;
    long long ys = 0;
    long long x = 0;
    while (g == 1) {
      x = y;
      while (k < 3ll * r / 4) {
        y = (__int128_t(y) * y + i) % n;
        k++;
      }
      while (k < r and g == 1) {
        ys = y;
        for (int j = 0; j < min(m, r - k); j++) {
          y = (__int128_t(y) * y + i) % n;
          q = (__int128_t(q) * abs(x - y)) % n;
        }
        g = gcd(q, n);
        k += m;
      }
      k = r;
      r <<= 1;
    }
    if (g == n) {
      g = 1;
      y = ys;
      while (g == 1) {
        y = (__int128_t(y) * y + i) % n;
        g = gcd(abs(x - y), n);
      }
    }
    if (g == n) continue;
    if (is_prime(g)) return g;
    if (is_prime(n / g)) return n / g;
    return find_prime_factor(g);
  }
  return -1;
}

vector<long long> factorize(long long n) {
  vector<long long> res;
  while (!is_prime(n) and n > 1) {
    long long p = find_prime_factor(n);
    while (n % p == 0) {
      n /= p;
      res.emplace_back(p);
    }
  }
  if (n > 1) {
    res.emplace_back(n);
  }
  sort(res.begin(), res.end());
  return res;
}
