#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"
#include <bits/stdc++.h>
using namespace std;
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixSum.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  unsigned n, m, k;
  cin >> n >> m >> k;
  vector<unsigned> a(n);
  vector<unsigned long long> res(n - m + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  WaveletMatrix w(a);
  for (int i = 0; i < n - m + 1; i++) {
    res[i] = w.kth_sum(i, i + m, k);
  }
  for (int i = 0; i < n - m + 1; i++) {
    cout << res[i];
    if (i == n - m) {
      cout << "\n";
    } else {
      cout << " ";
    }
  }
}
