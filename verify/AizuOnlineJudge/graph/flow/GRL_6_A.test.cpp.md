---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: academic/MaxflowAugmentingPath.hpp
    title: "Maxflow (Ford-Fulkerson\u6CD5)"
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
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
    \ endregion\n#line 2 \"verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n#line 1\
    \ \"academic/MaxflowAugmentingPath.hpp\"\ntemplate <class Cap>\nclass max_flow\
    \ {\n private:\n  struct Edge {\n    int to;\n    Cap cap, flow;\n    int rev;\n\
    \    bool is_rev;\n  };\n\n  vector<pair<int, int>> edge_id;\n  vector<vector<Edge>>\
    \ g;\n  int n;\n\n public:\n  max_flow(int n) : n(n) {\n    g.resize(n);\n  }\n\
    \n  void add_edge(int from, int to, Cap cap) {\n    assert(from != to);\n    int\
    \ from_id = int(g[from].size());\n    int to_id = int(g[to].size());\n    edge_id.emplace_back(from,\
    \ from_id);\n    g[from].push_back({to, cap, 0, to_id, false});\n    g[to].push_back({from,\
    \ cap, cap, from_id, true});\n  }\n\n  const Edge get_edge(int id) {\n    auto\
    \ [vid, eid] = edge_id[id];\n    return g[vid][eid];\n  }\n\n  Cap flow(int s,\
    \ int t) {\n    Cap res = 0;\n    vector<bool> seen(n, false);\n    while (1)\
    \ {\n      fill(seen.begin(), seen.end(), false);\n      auto dfs = [&](auto&\
    \ self, int cur, Cap epsilon) -> Cap {\n        if (cur == t) return epsilon;\n\
    \        seen[cur] = true;\n        for (int i = 0; i < int(g[cur].size()); i++)\
    \ {\n          Edge& edge = g[cur][i];\n          if (edge.cap - edge.flow <=\
    \ 0 or seen[edge.to]) continue;\n          Cap d = self(self, edge.to, min(epsilon,\
    \ edge.cap - edge.flow));\n          if (d > 0) {\n            edge.flow += d;\n\
    \            g[edge.to][edge.rev].flow -= d;\n            return d;\n        \
    \  }\n        }\n        return 0;\n      };\n      Cap f = dfs(dfs, s, numeric_limits<Cap>::max());\n\
    \      if (f == 0) break;\n      res += f;\n    }\n    return res;\n  }\n\n  vector<bool>\
    \ min_cut(int s) {\n    vector<bool> reachable(n, false);\n    auto dfs = [&](auto&\
    \ self, int cur) -> void {\n      reachable[cur] = true;\n      for (int i = 0;\
    \ i < int(g[cur].size()); i++) {\n        const Edge& edge = g[cur][i];\n    \
    \    if (edge.cap - edge.flow <= 0 or reachable[edge.to]) continue;\n        self(self,\
    \ edge.to);\n      }\n    };\n    dfs(dfs, s);\n    return reachable;\n  }\n};\n\
    #line 4 \"verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp\"\n\nint main() {\n\
    \  cin.tie(0)->sync_with_stdio(0);\n  int v, e;\n  in(v, e);\n  max_flow<int>\
    \ g(v);\n  rep(i, e) {\n    int u, v, c;\n    in(u, v, c);\n    g.add_edge(u,\
    \ v, c);\n  }\n  out(g.flow(0, v - 1));\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \n#include \"../../../../academic/MaxflowAugmentingPath.hpp\"\n\nint main() {\n\
    \  cin.tie(0)->sync_with_stdio(0);\n  int v, e;\n  in(v, e);\n  max_flow<int>\
    \ g(v);\n  rep(i, e) {\n    int u, v, c;\n    in(u, v, c);\n    g.add_edge(u,\
    \ v, c);\n  }\n  out(g.flow(0, v - 1));\n}"
  dependsOn:
  - template/template.hpp
  - academic/MaxflowAugmentingPath.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2026-05-03 18:38:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp
- /verify/verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp.html
title: verify/AizuOnlineJudge/graph/flow/GRL_6_A.test.cpp
---
