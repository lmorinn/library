#include "BostanMori.hpp"

template <class S>
S nth_term(const vector<S>& a, const vector<S>& c, long long n) {
  assert(a.size() == c.size());
  int d = int(c.size());
  FPS<S> l = {a.begin(), a.begin() + d};
  FPS<S> q(d + 1);
  q[0] = 1;
  for (int i = 0; i < d; i++) q[i + 1] = -c[i];
  l *= q;
  return bostan_mori<S>(l, q, n);
}

template <class S>
S nth_term_2(const vector<S>& a, const vector<S>& c, long long n) {
  assert(a.size() == c.size());
  int d = int(c.size());
  FPS<S> l = {a.begin(), a.begin() + d};
  FPS<S> q(d + 1);
  q[0] = 1;
  for (int i = 0; i < d; i++) q[i + 1] = -c[i];
  l = multiply(l, q, d);
  return bostan_mori_naive<S>(l, q, n);
}
