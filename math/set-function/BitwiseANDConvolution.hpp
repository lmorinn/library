#include "ZetaMobiusTransform.hpp"

template <class T>
vector<T> and_convolution(int n, vector<T> a, vector<T> b) {
  vector<T> za = superset_zeta(n, a);
  vector<T> zb = superset_zeta(n, b);
  vector<T> d(1 << n);
  for (int i = 0; i < (1 << n); i++) d[i] = za[i] * zb[i];
  return superset_mobius(n, d);
}