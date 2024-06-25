---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/tree/ALDS1_12_C.test.cpp
    title: verify/AizuOnlineJudge/graph/tree/ALDS1_12_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/Dijkstra.hpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <class T>\nvector<T> shortest_dijkstra(vector<vector<pair<T, T>>> &g,\
    \ T start = 0) {\n  int n = g.size();\n  vector<T> dist(n, numeric_limits<T>::max());\n\
    \  vector<bool> fin(n, false);\n  priority_queue<pair<T, T>, vector<pair<T, T>>,\
    \ greater<pair<T, T>>> q;\n  dist[start] = 0;\n  q.push({0, start});\n\n  while\
    \ (!q.empty()) {\n    T cur = q.top().second;\n    q.pop();\n    if (fin[cur])\
    \ continue;\n    fin[cur] = true;\n    for (auto p : g[cur]) {\n      T nex =\
    \ p.second;\n      T weight = p.first;\n      if (dist[nex] > dist[cur] + weight)\
    \ {\n        dist[nex] = dist[cur] + weight;\n        q.push({dist[nex], nex});\n\
    \      }\n    }\n  }\n  return dist;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\ntemplate <class T>\nvector<T> shortest_dijkstra(vector<vector<pair<T,\
    \ T>>> &g, T start = 0) {\n  int n = g.size();\n  vector<T> dist(n, numeric_limits<T>::max());\n\
    \  vector<bool> fin(n, false);\n  priority_queue<pair<T, T>, vector<pair<T, T>>,\
    \ greater<pair<T, T>>> q;\n  dist[start] = 0;\n  q.push({0, start});\n\n  while\
    \ (!q.empty()) {\n    T cur = q.top().second;\n    q.pop();\n    if (fin[cur])\
    \ continue;\n    fin[cur] = true;\n    for (auto p : g[cur]) {\n      T nex =\
    \ p.second;\n      T weight = p.first;\n      if (dist[nex] > dist[cur] + weight)\
    \ {\n        dist[nex] = dist[cur] + weight;\n        q.push({dist[nex], nex});\n\
    \      }\n    }\n  }\n  return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest-path/Dijkstra.hpp
  requiredBy: []
  timestamp: '2024-06-25 19:34:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/tree/ALDS1_12_C.test.cpp
documentation_of: graph/shortest-path/Dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortest-path/Dijkstra.hpp
- /library/graph/shortest-path/Dijkstra.hpp.html
title: graph/shortest-path/Dijkstra.hpp
---
