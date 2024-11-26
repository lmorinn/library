#include "../../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"
#include "../../../../../data-structure/wavelet-matrix/query/PointSetRangeFreq.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  vector<int> a(n);
  in(a);
  PointSetRangeFreq<int> wm(a, q);

  int com, pos, val, l, r;
  rep(i, q) {
    in(com);
    if (com == 0) {
      in(pos, val);
      wm.set(pos, val);
    } else {
      in(l, r, val);
      wm.range_freq(l, r, val);
    }
  }

  for (const unsigned &res : wm.build()) {
    out(res);
  }
}
