#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include <bits/stdc++.h>

using namespace std;
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  unsigned n, q;
  cin >> n >> q;
  vector<unsigned> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  WaveletMatrix<unsigned> w(v);
  for (int i = 0; i < q; i++) {
    unsigned l, r, k;
    cin >> l >> r >> k;
    cout << w.kth_smallest(l, r, k + 1) << "\n";
  }
}