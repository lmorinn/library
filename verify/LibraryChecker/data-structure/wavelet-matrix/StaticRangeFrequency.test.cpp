#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include <bits/stdc++.h>

using namespace std;
#include "../../../../data-structure/wavelet-matrix/WaveletMatrix.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  unsigned n, q;
  cin >> n >> q;
  vector<unsigned> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  WaveletMatrix w(a);
  for (int i = 0; i < q; i++) {
    unsigned l, r, x;
    cin >> l >> r >> x;
    cout << w.range_freq(l, r, x, x + 1) << "\n";
  }
}