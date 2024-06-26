#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <bits/stdc++.h>
using namespace std;
#include "../../../graph/tree/EulerTour.hpp"

using S = long long;
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
  vector<S> nodew(n);
  for (int i = 0; i < n; i++) {
    cin >> nodew[i];
  }
  for (int i = 1; i < n; i++) {
    int v;
    cin >> v;
    g[i].push_back({v, 0});
    g[v].push_back({i, 0});
  }

  EulerTour<S, op, e, inv, S, op, e, inv> t(g, nodew);

  for (int i = 0; i < q; i++) {
    int com;
    cin >> com;
    if (com == 0) {
      int u, x;
      cin >> u >> x;
      t.update_weight_node(u, t.get_node(u) + x);
    } else if (com == 1) {
      int u;
      cin >> u;
      cout << t.subtree_node(u) << "\n";
    }
  }
}
