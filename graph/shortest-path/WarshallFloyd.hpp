#pragma once
template <class T>
vector<vector<T>> warshallFloyd(vector<vector<pair<int, int>>> &g) {
  int n = g.size();
  T inf = numeric_limits<T>::max();
  vector<vector<T>> a(n, vector<T>(n, inf));
  for (int i = 0; i < n; i++) {
    a[i][i] = 0;
    for (auto p : g[i]) {
      a[i][p.first] = p.second;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][k] == inf or a[k][j] == inf) continue;
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  return a;
}

template <class T>
vector<vector<T>> warshallFloyd(vector<vector<int>> g) {
  int n = g.size();
  T inf = numeric_limits<T>::max();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] < 0) g[i][j] = inf;
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][k] == inf or g[k][j] == inf) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  return g;
}