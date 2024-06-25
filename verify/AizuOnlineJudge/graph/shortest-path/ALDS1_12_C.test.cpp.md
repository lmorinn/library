---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/Dijkstra.hpp
    title: Dijkstra
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C
  bundledCode: "#line 1 \"verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n#line 2 \"graph/shortest-path/Dijkstra.hpp\"\
    \n\ntemplate <class T>\nvector<T> shortest_dijkstra(vector<vector<pair<T, T>>>\
    \ &g, T start = 0) {\n  int n = g.size();\n  vector<T> dist(n, numeric_limits<T>::max());\n\
    \  vector<bool> fin(n, false);\n  priority_queue<pair<T, T>, vector<pair<T, T>>,\
    \ greater<pair<T, T>>> q;\n  dist[start] = 0;\n  q.push({0, start});\n\n  while\
    \ (!q.empty()) {\n    T cur = q.top().second;\n    q.pop();\n    if (fin[cur])\
    \ continue;\n    fin[cur] = true;\n    for (auto p : g[cur]) {\n      T nex =\
    \ p.second;\n      T weight = p.first;\n      if (dist[nex] > dist[cur] + weight)\
    \ {\n        dist[nex] = dist[cur] + weight;\n        q.push({dist[nex], nex});\n\
    \      }\n    }\n  }\n  return dist;\n}\n#line 6 \"verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  vector<vector<pair<long long, long\
    \ long>>> g(n);\n  for (int i = 0; i < n; i++) {\n    int u, k, c, v;\n    cin\
    \ >> u >> k;\n    for (int j = 0; j < k; j++) {\n      cin >> v >> c;\n      g[u].push_back({c,\
    \ v});\n    }\n  }\n  vector<long long> res = shortest_dijkstra<long long>(g);\n\
    \  for (int i = 0; i < n; i++) {\n    cout << i << \" \" << res[i] << \"\\n\"\
    ;\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n#include \"../../../../graph/shortest-path/Dijkstra.hpp\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  vector<vector<pair<long long, long\
    \ long>>> g(n);\n  for (int i = 0; i < n; i++) {\n    int u, k, c, v;\n    cin\
    \ >> u >> k;\n    for (int j = 0; j < k; j++) {\n      cin >> v >> c;\n      g[u].push_back({c,\
    \ v});\n    }\n  }\n  vector<long long> res = shortest_dijkstra<long long>(g);\n\
    \  for (int i = 0; i < n; i++) {\n    cout << i << \" \" << res[i] << \"\\n\"\
    ;\n  }\n}"
  dependsOn:
  - graph/shortest-path/Dijkstra.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 23:59:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
- /verify/verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp.html
title: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
---
