#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#include "../../../../math/number-theory/TetrationMod.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  in(t);
  rep(i, t) {
    long long a, b, m;
    in(a, b, m);
    out(tetration_mod(a, b, m));
  }
}