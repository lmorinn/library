#include "../fps/FormalPowerSeries.hpp"

FPS partition_function(int n) {
  FPS log_f(n + 1);
  vector<atcoder::modint998244353> iv(n + 1);
  iv[1] = 1;
  for (int i = 2; i < n + 1; i++) iv[i] = iv[998244353 % i] * (-(998244353 / i));
  for (long long k = 1; k < n + 1; k++) {
    for (long long i = 1; k * i < n + 1; i++) {
      log_f[k * i] += iv[i];
    }
  }
  return log_f.exp();
}
