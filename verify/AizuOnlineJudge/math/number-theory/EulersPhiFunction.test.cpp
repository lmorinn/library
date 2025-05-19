#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"
#include "../../../../math/number-theory/EulersPhiFunction.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n;
  in(n);
  out(Eulers_phi_function(n));
}