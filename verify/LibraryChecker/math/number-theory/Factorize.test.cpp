#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../../../math/number-theory/Factorize.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q;
  in(q);

  rep(i, q) {
    long long a;
    in(a);
    vector<long long> v = factorize(a);
    out(v.size(), v);
  }
}