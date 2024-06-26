#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../../dp/CumulativeSum.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  CumulativeSum s(a);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << s.sum(l, r) << "\n";
  }
}
