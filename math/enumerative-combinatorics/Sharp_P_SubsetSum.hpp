#include "../fps/FormalPowerSeries.hpp"

template <class S>
FPS<S> sharp_p_subset_sum(const vector<long long>& s, long long t) {
  int n = int(s.size());
  FPS<S> log_f(t + 1);
  vector<int> freq(t + 1);
  for (int i = 0; i < n; i++) {
    assert(0 < s[i]);
    if (s[i] <= t) freq[s[i]]++;
  }
  vector<S> iv(t + 1);
  iv[1] = 1;
  for (int i = 2; i < t + 1; i++) iv[i] = iv[S::mod() % i] * (-(S::mod() / i));
  for (long long k = 1; k < t + 1; k++) {
    if (freq[k] == 0) continue;
    for (long long i = 1; k * i < t + 1; i++) {
      log_f[k * i] += (i % 2 ? 1 : -1) * iv[i] * freq[k];
    }
  }
  return log_f.exp();
}