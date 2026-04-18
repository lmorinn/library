#include "ZetaMobiusTransform.hpp"

template <class T>
vector<T> or_convolution(int n, vector<T> a, vector<T> b) {
  vector<T> za = subset_zeta(n, a);
  vector<T> zb = subset_zeta(n, b);
  vector<T> d(1 << n);
  for (int i = 0; i < (1 << n); i++) d[i] = za[i] * zb[i];
  return subset_mobius(n, d);
}