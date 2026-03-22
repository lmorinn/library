inline static unsigned long long seed = 1235;
unsigned long long rand_gen(long long p) {
  unsigned long long x = seed;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  seed = x;
  return seed % p;
}