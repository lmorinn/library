---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: academic/MinimumCostB-flow.hpp
    title: "Minimum Cost b-flow (\u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\n#include <tr2/dynamic_bitset>\n\nusing namespace std;\nusing\
    \ namespace tr2;\nusing lint = long long;\nusing ull = unsigned long long;\nusing\
    \ ld = long double;\nusing int128 = __int128_t;\n#define all(x) (x).begin(), (x).end()\n\
    #define uniqv(v) v.erase(unique(all(v)), v.end())\n#define OVERLOAD_REP(_1, _2,\
    \ _3, name, ...) name\n#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{};\
    \ (i) != (n); ++(i))\n#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))\n\
    #define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define logfixed(x)\
    \ cout << fixed << setprecision(10) << x << endl;\n\nostream &operator<<(ostream\
    \ &dest, __int128_t value) {\n  ostream::sentry s(dest);\n  if (s) {\n    __uint128_t\
    \ tmp = value < 0 ? -value : value;\n    char buffer[128];\n    char *d = end(buffer);\n\
    \    do {\n      --d;\n      *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n\
    \    } while (tmp != 0);\n    if (value < 0) {\n      --d;\n      *d = '-';\n\
    \    }\n    int len = end(buffer) - d;\n    if (dest.rdbuf()->sputn(d, len) !=\
    \ len) {\n      dest.setstate(ios_base::badbit);\n    }\n  }\n  return dest;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T> &v)\
    \ {\n  for (int i = 0; i < (int)v.size(); i++) {\n    os << v[i] << (i + 1 !=\
    \ (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, const set<T> &set_var) {\n  for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr !=\
    \ set_var.end()) os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &set_var) {\n  for\
    \ (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os << *itr;\n\
    \    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n  }\n  return\
    \ os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const map<T, U> &map_var) {\n  for (auto itr = map_var.begin(); itr != map_var.end();\
    \ itr++) {\n    os << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n\
    \  return os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const unordered_map<T, U> &map_var) {\n  for (auto itr = map_var.begin();\
    \ itr != map_var.end(); itr++) {\n    os << itr->first << \" -> \" << itr->second\
    \ << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &pair_var) {\n  os << pair_var.first\
    \ << \" \" << pair_var.second;\n  return os;\n}\n\nvoid out() { cout << '\\n';\
    \ }\ntemplate <class T, class... Ts>\nvoid out(const T &a, const Ts &...b) {\n\
    \  cout << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\nvoid\
    \ outf() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid outf(const\
    \ T &a, const Ts &...b) {\n  cout << fixed << setprecision(14) << a;\n  (cout\
    \ << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\ntemplate <typename T>\n\
    istream &operator>>(istream &is, vector<T> &v) {\n  for (T &in : v) is >> in;\n\
    \  return is;\n}\n\ninline void in(void) { return; }\ntemplate <typename First,\
    \ typename... Rest>\nvoid in(First &first, Rest &...rest) {\n  cin >> first;\n\
    \  in(rest...);\n  return;\n}\n\ntemplate <typename T>\nbool chmax(T &a, const\
    \ T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n\
    }\ntemplate <typename T>\nbool chmin(T &a, const T &b) {\n  if (a > b) {\n   \
    \ a = b;\n    return true;\n  }\n  return false;\n}\n\nvector<lint> dx8 = {1,\
    \ 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    vector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0, 1, 0, -1};\n\n#pragma\
    \ endregion\n#line 2 \"verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\n#line 1\
    \ \"academic/MinimumCostB-flow.hpp\"\ntemplate <class Cap, class Cost>\nclass\
    \ min_cost_flow {\n private:\n  const Cost INF = numeric_limits<Cost>::max() /\
    \ 4;\n  struct Edge {\n    int to;\n    Cap cap, flow;\n    Cost cost;\n    int\
    \ rev;\n    bool is_rev;\n  };\n\n  vector<pair<int, int>> edge_id;\n  vector<vector<Edge>>\
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
    \ }\n    }\n    return z;\n  }\n};\n#line 4 \"verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int x, y, e;\n  int inf\
    \ = 1e7;\n  in(x, y, e);\n  min_cost_flow<int, int> g(x + y + 2);\n  g.add_edge(x\
    \ + y + 1, x + y, 0, inf, -1);\n  rep(i, x) g.add_edge(x + y, i, 0, 1, 0);\n \
    \ rep(i, y) g.add_edge(x + i, x + y + 1, 0, 1, 0);\n\n  rep(i, e) {\n    int u,\
    \ v;\n    in(u, v);\n    g.add_edge(u, x + v, 0, 1, 0);\n  }\n  vector<int> b(x\
    \ + y + 2);\n  out(-g.flow(b));\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\
    \n#include \"../../../../academic/MinimumCostB-flow.hpp\"\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int x, y, e;\n  int inf = 1e7;\n  in(x, y, e);\n  min_cost_flow<int, int> g(x\
    \ + y + 2);\n  g.add_edge(x + y + 1, x + y, 0, inf, -1);\n  rep(i, x) g.add_edge(x\
    \ + y, i, 0, 1, 0);\n  rep(i, y) g.add_edge(x + i, x + y + 1, 0, 1, 0);\n\n  rep(i,\
    \ e) {\n    int u, v;\n    in(u, v);\n    g.add_edge(u, x + v, 0, 1, 0);\n  }\n\
    \  vector<int> b(x + y + 2);\n  out(-g.flow(b));\n}\n"
  dependsOn:
  - template/template.hpp
  - academic/MinimumCostB-flow.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp
  requiredBy: []
  timestamp: '2026-05-03 14:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp
- /verify/verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp.html
title: verify/AizuOnlineJudge/graph/flow/GRL_7_A_2.test.cpp
---
