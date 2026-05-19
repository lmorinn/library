#include "../linear-algebra/Matrix.hpp"
#include "BostanMori.hpp"

// a.size() == d*2
template <class S>
S nth_term_find(const vector<S>& a, long long n) {
  int d = int(a.size()) / 2;
  Matrix<S> A(d);
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) A[i][j] = a[d - j - 1 + i];
  }
  vector<S> coef = A.linear_equation({a.begin() + d, a.end()})[0];
  FPS<S> l = {a.begin(), a.begin() + d};
  FPS<S> q(d + 1);
  q[0] = 1;
  for (int i = 0; i < d; i++) q[i + 1] = -coef[i];
  l *= q;
  return bostan_mori<S>(l, q, n);
}

// a.size() == d*2
template <class S>
S nth_term_find_2(const vector<S>& a, long long n) {
  int d = int(a.size()) / 2;
  Matrix<S> A(d);
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) A[i][j] = a[d - j - 1 + i];
  }
  vector<S> coef = A.linear_equation({a.begin() + d, a.end()})[0];
  FPS<S> l = {a.begin(), a.begin() + d};
  FPS<S> q(d + 1);
  q[0] = 1;
  for (int i = 0; i < d; i++) q[i + 1] = -coef[i];
  l = multiply(l, q, d);
  return bostan_mori_naive<S>(l, q, n);
}