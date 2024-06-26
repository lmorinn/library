#define PROBLEM "https://atcoder.jp/contests/abc250/tasks/abc250_e"
#include <bits/stdc++.h>
using namespace std;
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixHash.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  unsigned n;
  cin >> n;
  vector<unsigned> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  WaveletMatrix w1(a), w2(b);
  unsigned q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    unsigned x, y;
    cin >> x >> y;
    if (w1.range_hash(0, x) == w2.range_hash(0, y)) {
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
}
