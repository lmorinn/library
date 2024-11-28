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
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n#line 1 \"graph/shortest-path/Dijkstra.hpp\"\
    \ntemplate <class T>\nclass Dijkstra {\n   private:\n    vector<vector<pair<int,\
    \ T>>> g;\n    vector<T> dist;\n    vector<int> prev;\n    int n;\n\n   public:\n\
    \    Dijkstra(vector<vector<pair<int, T>>> _g, int start = 0) {\n        g = _g;\n\
    \        n = g.size();\n        dist.assign(n, -1);\n        prev.assign(n, -1);\n\
    \        vector<bool> fin(n, false);\n        priority_queue<tuple<T, int, int>,\
    \ vector<tuple<T, int, int>>, greater<tuple<T, int, int>>> q;\n        dist[start]\
    \ = 0;\n        q.emplace(0, start, -1);\n        while (!q.empty()) {\n     \
    \       int cur = get<1>(q.top());\n            int pre = get<2>(q.top());\n \
    \           q.pop();\n            if (fin[cur]) continue;\n            fin[cur]\
    \ = true;\n            prev[cur] = pre;\n            for (auto p : g[cur]) {\n\
    \                int nex = p.first;\n                int weight = p.second;\n\
    \                if (dist[nex] == -1 or dist[nex] > dist[cur] + weight) {\n  \
    \                  dist[nex] = dist[cur] + weight;\n                    q.emplace(dist[nex],\
    \ nex, cur);\n                }\n            }\n        }\n    }\n\n    void rebuild(int\
    \ start) {\n        dist.assign(n, -1);\n        prev.assign(n, -1);\n       \
    \ vector<bool> fin(n, false);\n        priority_queue<tuple<T, int, int>, vector<tuple<T,\
    \ int, int>>, greater<tuple<T, int, int>>> q;\n        dist[start] = 0;\n    \
    \    q.emplace(0, start, -1);\n        while (!q.empty()) {\n            int cur\
    \ = get<1>(q.top());\n            int pre = get<2>(q.top());\n            q.pop();\n\
    \            if (fin[cur]) continue;\n            fin[cur] = true;\n         \
    \   prev[cur] = pre;\n            for (auto p : g[cur]) {\n                int\
    \ nex = p.first;\n                int weight = p.second;\n                if (dist[nex]\
    \ == -1 or dist[nex] > dist[cur] + weight) {\n                    dist[nex] =\
    \ dist[cur] + weight;\n                    q.emplace(dist[nex], nex, cur);\n \
    \               }\n            }\n        }\n    }\n\n    vector<T> get_dist()\
    \ {\n        return dist;\n    }\n\n    T get_dist(int t) {\n        return dist[t];\n\
    \    }\n\n    vector<int> get_route(int t) {\n        vector<int> ret;\n     \
    \   if (dist[t] == -1) return ret;\n\n        int cur = t;\n        while (cur\
    \ != -1) {\n            ret.emplace_back(cur);\n            cur = prev[cur];\n\
    \        }\n        reverse(ret.begin(), ret.end());\n        return ret;\n  \
    \  }\n};\n#line 6 \"verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n;\n    cin >>\
    \ n;\n    vector<vector<pair<int, long long>>> g(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        int u, k, c, v;\n        cin >> u >> k;\n        for (int\
    \ j = 0; j < k; j++) {\n            cin >> v >> c;\n            g[u].emplace_back(v,\
    \ c);\n        }\n    }\n    Dijkstra<long long> d(g);\n    vector<long long>\
    \ res = d.get_dist();\n    for (int i = 0; i < n; i++) {\n        cout << i <<\
    \ \" \" << res[i] << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n#include \"../../../../graph/shortest-path/Dijkstra.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n;\n    cin >>\
    \ n;\n    vector<vector<pair<int, long long>>> g(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        int u, k, c, v;\n        cin >> u >> k;\n        for (int\
    \ j = 0; j < k; j++) {\n            cin >> v >> c;\n            g[u].emplace_back(v,\
    \ c);\n        }\n    }\n    Dijkstra<long long> d(g);\n    vector<long long>\
    \ res = d.get_dist();\n    for (int i = 0; i < n; i++) {\n        cout << i <<\
    \ \" \" << res[i] << \"\\n\";\n    }\n}"
  dependsOn:
  - graph/shortest-path/Dijkstra.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 03:35:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
- /verify/verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp.html
title: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
---
