#include "../fps/FormalPowerSeries.hpp"

FPS Stirling_number_2nd(int n) {
  FPS f(n + 1), g(n + 1);
  atcoder::modint998244353 inv = 1;
  for (int i = 1; i < n + 1; i++) inv *= i;
  inv = inv.inv();
  for (int i = n; i >= 0; i--) {
    f[i] = atcoder::modint998244353(i).pow(n) * inv;
    g[i] = (i % 2) ? -inv : inv;
    inv *= i;
  }
  f *= g;
  return f;
}