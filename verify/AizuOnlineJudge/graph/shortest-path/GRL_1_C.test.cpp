#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"
#include <bits/stdc++.h>
using namespace std;
#include "../../../../graph/shortest-path/WarshallFloyd.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int v, e;
  long long inf = numeric_limits<long long>::max();
  cin >> v >> e;
  vector<vector<pair<int, int>>> g(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    g[s].push_back({t, d});
  }
  vector<vector<long long>> res = warshallFloyd<long long>(g);
  for (int i = 0; i < v; i++) {
    if (res[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << "\n";
      return 0;
    }
  }
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (res[i][j] == inf) {
        cout << "INF";
      } else {
        cout << res[i][j];
      }
      if (j == v - 1) {
        cout << "\n";
      } else {
        cout << " ";
      }
    }
  }
}