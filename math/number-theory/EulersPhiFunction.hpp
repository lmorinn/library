#include "Factorize.hpp"

long long Eulers_phi_function(long long n) {
  __uint128_t upper = n;
  __uint128_t lower = 1;
  for (const long long p : factorize(n, true)) {
    upper *= (p - 1);
    lower *= p;
  }
  return upper / lower;
}