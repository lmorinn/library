#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "../../../../math/number-theory/EnumerateQuotients.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n;
  in(n);
  vector<long long> res = enumerate_quotients(n);
  out(res.size());
  out(res);
}