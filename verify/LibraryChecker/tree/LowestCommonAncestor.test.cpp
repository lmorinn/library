#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/tree/EulerTour.hpp"

using S = int;
S op(S a, S b) {
  return a + b;
}

S e() {
  return 0;
}

S inv(S a) {
  return -a;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, S>>> g(n);
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    g[i].push_back({v, 1});
    g[v].push_back({i, 1});
  }
  vector<S> nodew(n, 1);
  EulerTour<S, op, e, inv, S, op, e, inv> t(g, nodew);

  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << t.lca(u, v) << "\n";
  }
}
