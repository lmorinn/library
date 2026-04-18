#include "MultipleDivisorZetaMobiusTransform.hpp"

template <class T>
vector<T> gcd_convolution(vector<T> a, vector<T> b) {
  vector<T> za = multiple_zeta(a);
  vector<T> zb = multiple_zeta(b);
  vector<T> d(a.size());
  for (int i = 0; i < a.size(); i++) d[i] = za[i] * zb[i];
  return multiple_mobius(d);
}
