#include "MultipleDivisorZetaMobiusTransform.hpp"

template <class T>
vector<T> lcm_convolution(vector<T> a, vector<T> b) {
  vector<T> za = divisor_zeta(a);
  vector<T> zb = divisor_zeta(b);
  vector<T> d(a.size());
  for (int i = 0; i < a.size(); i++) d[i] = za[i] * zb[i];
  return divisor_mobius(d);
}