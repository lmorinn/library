
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
      g[v].push_back({c, u});
    }
  }
  vector<long long> res = shortest_dijkstra<long long>(g);
  for (int i = 0; i < n; i++) {
    cout << i << " " << res[i] << endl;
  }
}