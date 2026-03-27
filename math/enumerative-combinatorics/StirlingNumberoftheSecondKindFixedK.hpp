#include "../fps/FormalPowerSeries.hpp"

FPS Stirling_number_2nd_fixed_k(int n, int k) {
  FPS f(n + 1);
  f[1] = 1;
  f.exp_inplace();
  f[0]--;
  f.pow_inplace(k);
  atcoder::modint998244353 k_;
  atcoder::modint998244353 fac = 1;
  for (int i = 0; i < n + 1; i++) {
    if (i == k) k_ = fac.inv();
    f[i] *= fac;
    fac *= (i + 1);
  }
  for (int i = 0; i < n + 1; i++) f[i] *= k_;
  return f;
}