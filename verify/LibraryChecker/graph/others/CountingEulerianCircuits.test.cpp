#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"
#include "../../../../atcoder/modint.hpp"
#include "../../../../graph/others/CountingEulerianCircuits.hpp"
using namespace atcoder;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  in(n, m);
  CountingEulerianCircuits<modint998244353> g(n);
  rep(i, m) {
    int u, v;
    in(u, v);
    g.add_edge(u, v);
  }
  out(g.count_eulerian_circuits().val());
}
