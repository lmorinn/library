#pragma once

template <class T>
vector<T> shortest_dijkstra(vector<vector<pair<T, T>>> &g, T start = 0) {
  int n = g.size();
  vector<T> dist(n, numeric_limits<T>::max());
  vector<bool> fin(n, false);
  priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;
  dist[start] = 0;
  q.push({0, start});

  while (!q.empty()) {
    T cur = q.top().second;
    q.pop();
    if (fin[cur]) continue;
    fin[cur] = true;
    for (auto p : g[cur]) {
      T nex = p.second;
      T weight = p.first;
      if (dist[nex] > dist[cur] + weight) {
        dist[nex] = dist[cur] + weight;
        q.push({dist[nex], nex});
      }
    }
  }
  return dist;
}