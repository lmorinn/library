#include "Factorize.hpp"

inline static unsigned long long seed = 12345;
unsigned long long rand_gen(long long p) {
  unsigned long long x = seed;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  seed = x;
  return seed % p;
}

long long primitive_root(long long p) {
  while (1) {
    long long a = rand_gen(p);
    while (a == 0) a = rand_gen(p);
    bool ng = false;
    for (const long long x : factorize(p - 1, true)) {
      if (mod_pow(a, (p - 1) / x, p) == 1) {
        ng = true;
        break;
      }
    }
    if (!ng) return a;
  }
}
