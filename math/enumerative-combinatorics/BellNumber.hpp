#include "../fps/FormalPowerSeries.hpp"

template <class S>
FPS<S> Bell_number(int n) {
  vector<S> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i < n + 1; i++) fac[i] = fac[i - 1] * i;
  FPS<S> f(n + 1);
  f[1] = 1;
  f.exp_inplace();
  f[0]--;
  f.exp_inplace();
  for (int i = 0; i < n + 1; i++) f[i] *= fac[i];
  return f;
}