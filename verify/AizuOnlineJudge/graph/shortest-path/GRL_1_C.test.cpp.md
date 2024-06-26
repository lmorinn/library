---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/WarshallFloyd.hpp
    title: Warshall Floyd
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#line 2 \"graph/shortest-path/WarshallFloyd.hpp\"\
    \ntemplate <class T>\nvector<vector<T>> warshallFloyd(vector<vector<pair<int,\
    \ int>>> &g) {\n  int n = g.size();\n  T inf = numeric_limits<T>::max();\n  vector<vector<T>>\
    \ a(n, vector<T>(n, inf));\n  for (int i = 0; i < n; i++) {\n    a[i][i] = 0;\n\
    \    for (auto p : g[i]) {\n      a[i][p.first] = p.second;\n    }\n  }\n  for\
    \ (int k = 0; k < n; k++) {\n    for (int i = 0; i < n; i++) {\n      for (int\
    \ j = 0; j < n; j++) {\n        if (a[i][k] == inf or a[k][j] == inf) continue;\n\
    \        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);\n      }\n    }\n  }\n  return\
    \ a;\n}\n\ntemplate <class T>\nvector<vector<T>> warshallFloyd(vector<vector<int>>\
    \ g) {\n  int n = g.size();\n  T inf = numeric_limits<T>::max();\n  for (int i\
    \ = 0; i < n; i++) {\n    for (int j = 0; j < n; j++) {\n      if (g[i][j] < 0)\
    \ g[i][j] = inf;\n    }\n  }\n  for (int k = 0; k < n; k++) {\n    for (int i\
    \ = 0; i < n; i++) {\n      for (int j = 0; j < n; j++) {\n        if (g[i][k]\
    \ == inf or g[k][j] == inf) continue;\n        g[i][j] = min(g[i][j], g[i][k]\
    \ + g[k][j]);\n      }\n    }\n  }\n  return g;\n}\n#line 5 \"verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int v, e;\n  long long\
    \ inf = numeric_limits<long long>::max();\n  cin >> v >> e;\n  vector<vector<pair<int,\
    \ int>>> g(v);\n  for (int i = 0; i < e; i++) {\n    int s, t, d;\n    cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  vector<vector<long long>>\
    \ res = warshallFloyd<long long>(g);\n  for (int i = 0; i < v; i++) {\n    if\
    \ (res[i][i] < 0) {\n      cout << \"NEGATIVE CYCLE\" << \"\\n\";\n      return\
    \ 0;\n    }\n  }\n  for (int i = 0; i < v; i++) {\n    for (int j = 0; j < v;\
    \ j++) {\n      if (res[i][j] == inf) {\n        cout << \"INF\";\n      } else\
    \ {\n        cout << res[i][j];\n      }\n      if (j == v - 1) {\n        cout\
    \ << \"\\n\";\n      } else {\n        cout << \" \";\n      }\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../../../graph/shortest-path/WarshallFloyd.hpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int v, e;\n  long long\
    \ inf = numeric_limits<long long>::max();\n  cin >> v >> e;\n  vector<vector<pair<int,\
    \ int>>> g(v);\n  for (int i = 0; i < e; i++) {\n    int s, t, d;\n    cin >>\
    \ s >> t >> d;\n    g[s].push_back({t, d});\n  }\n  vector<vector<long long>>\
    \ res = warshallFloyd<long long>(g);\n  for (int i = 0; i < v; i++) {\n    if\
    \ (res[i][i] < 0) {\n      cout << \"NEGATIVE CYCLE\" << \"\\n\";\n      return\
    \ 0;\n    }\n  }\n  for (int i = 0; i < v; i++) {\n    for (int j = 0; j < v;\
    \ j++) {\n      if (res[i][j] == inf) {\n        cout << \"INF\";\n      } else\
    \ {\n        cout << res[i][j];\n      }\n      if (j == v - 1) {\n        cout\
    \ << \"\\n\";\n      } else {\n        cout << \" \";\n      }\n    }\n  }\n}"
  dependsOn:
  - graph/shortest-path/WarshallFloyd.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 17:11:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
- /verify/verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp.html
title: verify/AizuOnlineJudge/graph/shortest-path/GRL_1_C.test.cpp
---
