#include "../fps/FormalPowerSeries.hpp"

template <class S>
FPS<S> Stirling_number_2nd(int n) {
  FPS<S> f(n + 1), g(n + 1);
  S inv = 1;
  for (int i = 1; i < n + 1; i++) inv *= i;
  inv = inv.inv();
  for (int i = n; i >= 0; i--) {
    f[i] = S(i).pow(n) * inv;
    g[i] = (i % 2) ? -inv : inv;
    inv *= i;
  }
  f *= g;
  return f;
}