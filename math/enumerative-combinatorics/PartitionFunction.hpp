#include "../fps/FormalPowerSeries.hpp"

template <class S>
FPS<S> partition_function(int n) {
  FPS<S> log_f(n + 1);
  vector<S> iv(n + 1);
  iv[1] = 1;
  for (int i = 2; i < n + 1; i++) iv[i] = iv[S::mod() % i] * (-(S::mod() / i));
  for (long long k = 1; k < n + 1; k++) {
    for (long long i = 1; k * i < n + 1; i++) {
      log_f[k * i] += iv[i];
    }
  }
  return log_f.exp();
}
