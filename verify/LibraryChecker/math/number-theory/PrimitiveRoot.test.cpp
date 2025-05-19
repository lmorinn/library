#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../../math/number-theory/PrimitiveRoot.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q;
  in(q);
  rep(i, q) {
    long long p;
    in(p);
    out(primitive_root(p));
  }
}
