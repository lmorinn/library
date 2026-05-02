---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/flow/GRL_6_B.test.cpp
    title: verify/AizuOnlineJudge/graph/flow/GRL_6_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"academic/MinimumCostB-flow.hpp\"\ntemplate <class Cap, class\
    \ Cost>\nclass min_cost_flow {\n private:\n  const Cost INF = numeric_limits<Cost>::max()\
    \ / 4;\n  struct Edge {\n    int to;\n    Cap cap, flow;\n    Cost cost;\n   \
    \ int rev;\n    bool is_rev;\n  };\n\n  vector<pair<int, int>> edge_id;\n  vector<vector<Edge>>\
    \ g;\n  Cost base_cost = 0;\n  int n;\n\n public:\n  vector<Cost> p;\n  min_cost_flow(int\
    \ n) : n(n) {\n    g.resize(n);\n  }\n\n  const Edge get_edge(int id) {\n    auto\
    \ [vid, eid] = edge_id[id];\n    if (vid >= n) {\n      int v = vid - n;\n   \
    \   return Edge{v, 0, eid, 0, 0, 0};\n    }\n    return g[vid][eid];\n  }\n\n\
    \  void edge_status() {\n    for (int i = 0; i < n; i++) {\n      for (auto [to,\
    \ cap, flow, cost, rev, is_rev] : g[i]) {\n        if (is_rev) continue;\n   \
    \     out(i, \"->\", to, \" : \", flow);\n      }\n    }\n  }\n\n  void add_edge(int\
    \ from, int to, Cap lower, Cap upper, Cost cost) {\n    assert(lower <= upper);\n\
    \    Cap x;\n    if (cost >= 0) {\n      x = lower;\n    } else {\n      x = upper;\n\
    \    }\n\n    int from_id = int(g[from].size());\n    int to_id = int(g[to].size());\n\
    \    if (from != to) {\n      edge_id.emplace_back(from, from_id);\n    } else\
    \ {\n      edge_id.emplace_back(n + from, x);\n    }\n    if (from != to) {\n\
    \      g[from].push_back({to, upper, x, cost, to_id, false});\n      g[to].push_back({from,\
    \ upper - lower, upper - x, -cost, from_id, true});\n    } else {\n      base_cost\
    \ += x * cost;\n      return;\n    }\n  }\n\n  Cost flow(vector<Cap> e) {\n  \
    \  for (int i = 0; i < n; i++) {\n      for (auto const& edge : g[i]) {\n    \
    \    if (edge.is_rev) continue;\n        int to = edge.to;\n        Cap x = edge.flow;\n\
    \        e[i] -= x;\n        e[to] += x;\n      }\n    }\n    vector<Cost> pot(n);\n\
    \    vector<Cost> dist(n, INF);\n    vector<int> prev_v(n, -1);\n    vector<int>\
    \ prev_e(n, -1);\n    vector<bool> fin(n, false);\n    while (1) {\n      int\
    \ s = -1;\n      for (int i = 0; i < n; i++) {\n        if (e[i] > 0) {\n    \
    \      s = i;\n          break;\n        }\n      }\n\n      if (s != -1) {\n\
    \        fill(dist.begin(), dist.end(), INF);\n        fill(prev_v.begin(), prev_v.end(),\
    \ -1);\n        fill(prev_e.begin(), prev_e.end(), -1);\n        fill(fin.begin(),\
    \ fin.end(), false);\n        dist[s] = 0;\n\n        priority_queue<pair<Cost,\
    \ int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> q;\n        q.emplace(0,\
    \ s);\n        while (!q.empty()) {\n          auto [cur_d, cur] = q.top();\n\
    \          q.pop();\n          if (fin[cur]) continue;\n          fin[cur] = true;\n\
    \          for (int i = 0; i < int(g[cur].size()); i++) {\n            const Edge&\
    \ edge = g[cur][i];\n            if (edge.cap - edge.flow <= 0) continue;\n  \
    \          Cost len = edge.cost - pot[cur] + pot[edge.to];\n            if (!fin[edge.to]\
    \ and dist[edge.to] > cur_d + len) {\n              dist[edge.to] = cur_d + len;\n\
    \              prev_v[edge.to] = cur;\n              prev_e[edge.to] = i;\n  \
    \            q.emplace(dist[edge.to], edge.to);\n            }\n          }\n\
    \        }\n\n        int k = -1;\n        for (int i = 0; i < n; i++) {\n   \
    \       if (e[i] < 0 and dist[i] != INF) {\n            if (k == -1 or dist[i]\
    \ < dist[k]) {\n              k = i;\n            }\n          }\n        }\n\n\
    \        if (k != -1) {\n          Cost D = dist[k];\n          for (int i = 0;\
    \ i < n; i++) {\n            Cost delta = (dist[i] == INF ? D : min(dist[i], D));\n\
    \            pot[i] -= delta;\n          }\n          Cap epsilon = min(e[s],\
    \ -e[k]);\n          int cur = k;\n          while (cur != s) {\n            int\
    \ pv = prev_v[cur];\n            int pe = prev_e[cur];\n            const Edge&\
    \ edge = g[pv][pe];\n            Cap residual_cap = edge.cap - edge.flow;\n  \
    \          if (epsilon > residual_cap) epsilon = residual_cap;\n            cur\
    \ = pv;\n          }\n\n          cur = k;\n          while (cur != s) {\n   \
    \         int pv = prev_v[cur];\n            int pe = prev_e[cur];\n         \
    \   Edge& edge = g[pv][pe];\n            edge.flow += epsilon;\n            g[edge.to][edge.rev].flow\
    \ -= epsilon;\n            cur = prev_v[cur];\n            cur = pv;\n       \
    \   }\n          e[s] -= epsilon;\n          e[k] += epsilon;\n        } else\
    \ {\n          // \u53EF\u80FD\u6D41\u304C\u5B58\u5728\u3057\u306A\u3044\n   \
    \       return numeric_limits<Cost>::max();\n          break;\n        }\n   \
    \   } else {\n        break;\n      }\n    }\n\n    p.resize(n);\n    for (int\
    \ i = 0; i < n; i++) {\n      p[i] = -pot[i];\n    }\n    Cost z = base_cost;\n\
    \    for (int i = 0; i < n; i++) {\n      for (auto const& edge : g[i]) {\n  \
    \      if (edge.is_rev) continue;\n        z += edge.flow * edge.cost;\n     \
    \ }\n    }\n    return z;\n  }\n};\n"
  code: "template <class Cap, class Cost>\nclass min_cost_flow {\n private:\n  const\
    \ Cost INF = numeric_limits<Cost>::max() / 4;\n  struct Edge {\n    int to;\n\
    \    Cap cap, flow;\n    Cost cost;\n    int rev;\n    bool is_rev;\n  };\n\n\
    \  vector<pair<int, int>> edge_id;\n  vector<vector<Edge>> g;\n  Cost base_cost\
    \ = 0;\n  int n;\n\n public:\n  vector<Cost> p;\n  min_cost_flow(int n) : n(n)\
    \ {\n    g.resize(n);\n  }\n\n  const Edge get_edge(int id) {\n    auto [vid,\
    \ eid] = edge_id[id];\n    if (vid >= n) {\n      int v = vid - n;\n      return\
    \ Edge{v, 0, eid, 0, 0, 0};\n    }\n    return g[vid][eid];\n  }\n\n  void edge_status()\
    \ {\n    for (int i = 0; i < n; i++) {\n      for (auto [to, cap, flow, cost,\
    \ rev, is_rev] : g[i]) {\n        if (is_rev) continue;\n        out(i, \"->\"\
    , to, \" : \", flow);\n      }\n    }\n  }\n\n  void add_edge(int from, int to,\
    \ Cap lower, Cap upper, Cost cost) {\n    assert(lower <= upper);\n    Cap x;\n\
    \    if (cost >= 0) {\n      x = lower;\n    } else {\n      x = upper;\n    }\n\
    \n    int from_id = int(g[from].size());\n    int to_id = int(g[to].size());\n\
    \    if (from != to) {\n      edge_id.emplace_back(from, from_id);\n    } else\
    \ {\n      edge_id.emplace_back(n + from, x);\n    }\n    if (from != to) {\n\
    \      g[from].push_back({to, upper, x, cost, to_id, false});\n      g[to].push_back({from,\
    \ upper - lower, upper - x, -cost, from_id, true});\n    } else {\n      base_cost\
    \ += x * cost;\n      return;\n    }\n  }\n\n  Cost flow(vector<Cap> e) {\n  \
    \  for (int i = 0; i < n; i++) {\n      for (auto const& edge : g[i]) {\n    \
    \    if (edge.is_rev) continue;\n        int to = edge.to;\n        Cap x = edge.flow;\n\
    \        e[i] -= x;\n        e[to] += x;\n      }\n    }\n    vector<Cost> pot(n);\n\
    \    vector<Cost> dist(n, INF);\n    vector<int> prev_v(n, -1);\n    vector<int>\
    \ prev_e(n, -1);\n    vector<bool> fin(n, false);\n    while (1) {\n      int\
    \ s = -1;\n      for (int i = 0; i < n; i++) {\n        if (e[i] > 0) {\n    \
    \      s = i;\n          break;\n        }\n      }\n\n      if (s != -1) {\n\
    \        fill(dist.begin(), dist.end(), INF);\n        fill(prev_v.begin(), prev_v.end(),\
    \ -1);\n        fill(prev_e.begin(), prev_e.end(), -1);\n        fill(fin.begin(),\
    \ fin.end(), false);\n        dist[s] = 0;\n\n        priority_queue<pair<Cost,\
    \ int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> q;\n        q.emplace(0,\
    \ s);\n        while (!q.empty()) {\n          auto [cur_d, cur] = q.top();\n\
    \          q.pop();\n          if (fin[cur]) continue;\n          fin[cur] = true;\n\
    \          for (int i = 0; i < int(g[cur].size()); i++) {\n            const Edge&\
    \ edge = g[cur][i];\n            if (edge.cap - edge.flow <= 0) continue;\n  \
    \          Cost len = edge.cost - pot[cur] + pot[edge.to];\n            if (!fin[edge.to]\
    \ and dist[edge.to] > cur_d + len) {\n              dist[edge.to] = cur_d + len;\n\
    \              prev_v[edge.to] = cur;\n              prev_e[edge.to] = i;\n  \
    \            q.emplace(dist[edge.to], edge.to);\n            }\n          }\n\
    \        }\n\n        int k = -1;\n        for (int i = 0; i < n; i++) {\n   \
    \       if (e[i] < 0 and dist[i] != INF) {\n            if (k == -1 or dist[i]\
    \ < dist[k]) {\n              k = i;\n            }\n          }\n        }\n\n\
    \        if (k != -1) {\n          Cost D = dist[k];\n          for (int i = 0;\
    \ i < n; i++) {\n            Cost delta = (dist[i] == INF ? D : min(dist[i], D));\n\
    \            pot[i] -= delta;\n          }\n          Cap epsilon = min(e[s],\
    \ -e[k]);\n          int cur = k;\n          while (cur != s) {\n            int\
    \ pv = prev_v[cur];\n            int pe = prev_e[cur];\n            const Edge&\
    \ edge = g[pv][pe];\n            Cap residual_cap = edge.cap - edge.flow;\n  \
    \          if (epsilon > residual_cap) epsilon = residual_cap;\n            cur\
    \ = pv;\n          }\n\n          cur = k;\n          while (cur != s) {\n   \
    \         int pv = prev_v[cur];\n            int pe = prev_e[cur];\n         \
    \   Edge& edge = g[pv][pe];\n            edge.flow += epsilon;\n            g[edge.to][edge.rev].flow\
    \ -= epsilon;\n            cur = prev_v[cur];\n            cur = pv;\n       \
    \   }\n          e[s] -= epsilon;\n          e[k] += epsilon;\n        } else\
    \ {\n          // \u53EF\u80FD\u6D41\u304C\u5B58\u5728\u3057\u306A\u3044\n   \
    \       return numeric_limits<Cost>::max();\n          break;\n        }\n   \
    \   } else {\n        break;\n      }\n    }\n\n    p.resize(n);\n    for (int\
    \ i = 0; i < n; i++) {\n      p[i] = -pot[i];\n    }\n    Cost z = base_cost;\n\
    \    for (int i = 0; i < n; i++) {\n      for (auto const& edge : g[i]) {\n  \
    \      if (edge.is_rev) continue;\n        z += edge.flow * edge.cost;\n     \
    \ }\n    }\n    return z;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: academic/MinimumCostB-flow.hpp
  requiredBy: []
  timestamp: '2026-05-02 20:17:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/graph/flow/GRL_6_B.test.cpp
documentation_of: academic/MinimumCostB-flow.hpp
layout: document
title: "Minimum Cost b-flow (\u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5)"
---

## 概要

todo