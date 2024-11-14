#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/4059"
#include "../../../../data-structure/segment-tree/SegmentTree.hpp"
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp"

using S = lint;

S op(S a, S b) {
  return a + b;
}

S e() {
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  vector Q(q, vector(6, 0LL));
  vector<S> x, y, w;

  int cur = 0;
  rep(i, q) {
    int com;
    in(com);
    Q[i][0] = com;
    if (com == 1) {
      in(Q[i][1], Q[i][2], Q[i][3], Q[i][4]);
      x.emplace_back(Q[i][1]);
      y.emplace_back(Q[i][3]);
      x.emplace_back(Q[i][2] + 1);
      y.emplace_back(Q[i][3]);
      Q[i][5] = cur;
      cur++;
    } else {
      in(Q[i][1], Q[i][2]);
    }
  }
  w.resize(x.size());

  WaveletMatrix<S, op, e> wm(x, y, w);
  rep(i, q) {
    int com = Q[i][0];
    if (com == 1) {
      wm.set(Q[i][5] * 2, Q[i][4]);
      wm.set(Q[i][5] * 2 + 1, -Q[i][4]);
    } else {
      int l = 0;
      int r = Q[i][1] + 1;
      auto F = [&](int cnt, S prod) {
        return prod < Q[i][2];
      };
      out(wm.max_y(l, r, F));
    }
  }
}