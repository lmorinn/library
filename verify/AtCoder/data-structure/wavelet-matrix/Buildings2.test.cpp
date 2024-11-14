
#include "../../../../template/template.hpp"
#define PROBLEM "https://atcoder.jp/contests/abc379/tasks/abc379_f"
#include "../../../../data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  vector<int> h(n);
  vector<int> a(n, -1e9);
  in(h);
  stack<pair<int, int>> s;
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() and s.top().first < h[i]) {
      a[s.top().second] = i - 1;
      s.pop();
    }
    s.push({h[i], i});
  }

  WaveletMatrix<int> w(a);
  rep(i, q) {
    int l, r;
    in(l, r);
    out(w.range_freq(r, n, INT_MIN, l - 1));
  }
}