#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E"

#include <bits/stdc++.h>

using namespace std;
#include "../../../../data-structure/segment-tree/LazySegmentTree.hpp"
#include "../../../../graph/tree/HeavyLightDecomposition.hpp"

using F = long long;
struct S {
  long long val;
  int siz;
};

S op(S a, S b) {
  return {a.val + b.val, a.siz + b.siz};
}

S e() {
  return {0, 0};
}

S mapping(F f, S x) { return {x.val + f * x.siz, x.siz}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n;
  vector<vector<pair<int, S>>> g(n);
  vector<S> nodew(n, e());
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      g[c].push_back({i, {0, 1}});
      g[i].push_back({c, {0, 1}});
    }
  }
  hld<S, op, e, F, mapping, composition, id, S, op, e, F, mapping, composition, id> h(g, nodew);
  cin >> q;
  for (int i = 0; i < q; i++) {
    int com;
    cin >> com;
    if (com == 0) {
      int v, w;
      cin >> v >> w;
      h.apply_edge(0, v, w);
    } else {
      int u;
      cin >> u;
      cout << h.prod_edge(0, u).val << "\n";
    }
  }
}