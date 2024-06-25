#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C"
#include <bits/stdc++.h>

using namespace std;
#include "../../../../graph/shortest-path/Dijkstra.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<pair<long long, long long>>> g(n);
  for (int i = 0; i < n; i++) {
    int u, k, c, v;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      g[u].push_back({c, v});
    }
  }
  vector<long long> res = shortest_dijkstra<long long>(g);
  for (int i = 0; i < n; i++) {
    cout << i << " " << res[i] << "\n";
  }
}