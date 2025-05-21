#include "EulersPhiFunction.hpp"

long long tetration_mod(long long a, long long b, long long m) {
  if (m == 1) return 0;
  if (a == 0) return ((b & 1) == 0);
  if (b == 0) return 1;
  if (b == 1) return a % m;
  if (b == 2) return mod_pow(a, a, m);
  long long phi = Eulers_phi_function(m);
  long long power = tetration_mod(a, b - 1, phi);
  return mod_pow(a, (power == 0 ? phi : power), m);
}
