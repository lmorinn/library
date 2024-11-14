#include "../../../../template/template.hpp"
#define PROBLEM "https://atcoder.jp/contests/abc339/tasks/abc339_g"
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixTemplateSum.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  unsigned n;
  in(n);
  vector<ull> v(n);
  in(v);
  WaveletMatrix<ull, ull> w(v);
  unsigned q;
  in(q);
  ull b = 0;
  rep(i, q) {
    ull l, r, x;
    in(l, r, x);
    l ^= b;
    r ^= b;
    x ^= b;
    b = w.range_sum(l - 1, r, 0, x + 1);
    out(b);
  }
}