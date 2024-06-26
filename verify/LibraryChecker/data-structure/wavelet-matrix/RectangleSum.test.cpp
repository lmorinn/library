#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixRectangle.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<unsigned> x(n), y(n), z(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  WaveletMatrix w(x, y, z);
  for (int i = 0; i < q; i++) {
    int l, d, r, u;
    cin >> l >> d >> r >> u;
    cout << w.rectangle_sum(l, r, d, u) << "\n";
  }
}
