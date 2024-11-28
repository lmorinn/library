---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest-path/Dijkstra.hpp\"\ntemplate <class T>\n\
    class Dijkstra {\n   private:\n    vector<vector<pair<int, T>>> g;\n    vector<T>\
    \ dist;\n    vector<int> prev;\n    int n;\n\n   public:\n    Dijkstra(vector<vector<pair<int,\
    \ T>>> _g, int start = 0) {\n        g = _g;\n        n = g.size();\n        dist.assign(n,\
    \ -1);\n        prev.assign(n, -1);\n        vector<bool> fin(n, false);\n   \
    \     priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T,\
    \ int, int>>> q;\n        dist[start] = 0;\n        q.emplace(0, start, -1);\n\
    \        while (!q.empty()) {\n            int cur = get<1>(q.top());\n      \
    \      int pre = get<2>(q.top());\n            q.pop();\n            if (fin[cur])\
    \ continue;\n            fin[cur] = true;\n            prev[cur] = pre;\n    \
    \        for (auto p : g[cur]) {\n                int nex = p.first;\n       \
    \         int weight = p.second;\n                if (dist[nex] == -1 or dist[nex]\
    \ > dist[cur] + weight) {\n                    dist[nex] = dist[cur] + weight;\n\
    \                    q.emplace(dist[nex], nex, cur);\n                }\n    \
    \        }\n        }\n    }\n\n    void rebuild(int start) {\n        dist.assign(n,\
    \ -1);\n        prev.assign(n, -1);\n        vector<bool> fin(n, false);\n   \
    \     priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T,\
    \ int, int>>> q;\n        dist[start] = 0;\n        q.emplace(0, start, -1);\n\
    \        while (!q.empty()) {\n            int cur = get<1>(q.top());\n      \
    \      int pre = get<2>(q.top());\n            q.pop();\n            if (fin[cur])\
    \ continue;\n            fin[cur] = true;\n            prev[cur] = pre;\n    \
    \        for (auto p : g[cur]) {\n                int nex = p.first;\n       \
    \         int weight = p.second;\n                if (dist[nex] == -1 or dist[nex]\
    \ > dist[cur] + weight) {\n                    dist[nex] = dist[cur] + weight;\n\
    \                    q.emplace(dist[nex], nex, cur);\n                }\n    \
    \        }\n        }\n    }\n\n    vector<T> get_dist() {\n        return dist;\n\
    \    }\n\n    T get_dist(int t) {\n        return dist[t];\n    }\n\n    vector<int>\
    \ get_route(int t) {\n        vector<int> ret;\n        if (dist[t] == -1) return\
    \ ret;\n\n        int cur = t;\n        while (cur != -1) {\n            ret.emplace_back(cur);\n\
    \            cur = prev[cur];\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n};\n"
  code: "template <class T>\nclass Dijkstra {\n   private:\n    vector<vector<pair<int,\
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
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest-path/Dijkstra.hpp
  requiredBy: []
  timestamp: '2024-11-29 03:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest-path/Dijkstra.hpp
layout: document
title: Dijkstra
---

## 概要

todo

## 計算量
todo