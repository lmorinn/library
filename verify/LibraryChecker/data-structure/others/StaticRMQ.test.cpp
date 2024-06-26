#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;
#include "../../../../data-structure/others/SparseTable.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  auto f = [=](const int &x, const int &y) { return min(x, y); };
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SparseTable s(a, f);

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << s.query(l, r) << "\n";
  }
}
