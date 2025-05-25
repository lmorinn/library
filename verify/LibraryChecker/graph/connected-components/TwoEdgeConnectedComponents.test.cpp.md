---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/connected-components/TwoEdgeConnectedComponents.hpp
    title: Two Edge Connected Components
  - icon: ':heavy_check_mark:'
    path: graph/others/LowLink.hpp
    title: Low Link
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
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing lint = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n#define\
    \ all(x) (x).begin(), (x).end()\n#define uniqv(v) v.erase(unique(all(v)), v.end())\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP1(i, n) for (auto\
    \ i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))\n#define REP2(i, l, r) for\
    \ (auto i = (l); (i) != (r); ++(i))\n#define rep(...) OVERLOAD_REP(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define logfixed(x) cout << fixed << setprecision(10)\
    \ << x << endl;\n\nostream &operator<<(ostream &dest, __int128_t value) {\n  ostream::sentry\
    \ s(dest);\n  if (s) {\n    __uint128_t tmp = value < 0 ? -value : value;\n  \
    \  char buffer[128];\n    char *d = end(buffer);\n    do {\n      --d;\n     \
    \ *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n    } while (tmp != 0);\n\
    \    if (value < 0) {\n      --d;\n      *d = '-';\n    }\n    int len = end(buffer)\
    \ - d;\n    if (dest.rdbuf()->sputn(d, len) != len) {\n      dest.setstate(ios_base::badbit);\n\
    \    }\n  }\n  return dest;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n  for (int i = 0; i < (int)v.size(); i++) {\n  \
    \  os << v[i] << (i + 1 != (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\n  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os\
    \ << *itr;\n    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n\
    \  }\n  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const unordered_set<T> &set_var) {\n  for (auto itr = set_var.begin(); itr !=\
    \ set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr != set_var.end())\
    \ os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const map<T, U> &map_var) {\n  for (auto\
    \ itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os << itr->first\
    \ << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const unordered_map<T, U> &map_var)\
    \ {\n  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os\
    \ << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\
    \ntemplate <typename T, typename U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &pair_var) {\n  os << pair_var.first << \" \" << pair_var.second;\n  return\
    \ os;\n}\n\nvoid out() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid\
    \ out(const T &a, const Ts &...b) {\n  cout << a;\n  (cout << ... << (cout <<\
    \ ' ', b));\n  cout << '\\n';\n}\n\nvoid outf() { cout << '\\n'; }\ntemplate <class\
    \ T, class... Ts>\nvoid outf(const T &a, const Ts &...b) {\n  cout << fixed <<\
    \ setprecision(14) << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\\
    n';\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v)\
    \ {\n  for (T &in : v) is >> in;\n  return is;\n}\n\ninline void in(void) { return;\
    \ }\ntemplate <typename First, typename... Rest>\nvoid in(First &first, Rest &...rest)\
    \ {\n  cin >> first;\n  in(rest...);\n  return;\n}\n\ntemplate <typename T>\n\
    bool chmax(T &a, const T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <typename T>\nbool chmin(T &a, const T &b)\
    \ {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\n\
    vector<lint> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1,\
    \ 1, 0, -1, -1, -1};\nvector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0,\
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#line 1 \"graph/others/LowLink.hpp\"\nclass LowLink {\n   public:\n    int n,\
    \ time;\n    vector<vector<pair<int, int>>> g;\n    vector<bool> seen;\n    vector<int>\
    \ order, low;\n    vector<int> articulation;\n    vector<int> bridge;\n\n    LowLink(int\
    \ _n) : n(_n), time(0) {\n        g.resize(n);\n        seen.assign(n, false);\n\
    \        order.assign(n, -1);\n        low.assign(n, 0);\n    }\n\n    void add_edge(int\
    \ u, int v, int eid) {\n        g[u].emplace_back(v, eid);\n        g[v].emplace_back(u,\
    \ eid);\n    }\n\n    void dfs(int cur, int prev, int prev_eid) {\n        seen[cur]\
    \ = true;\n        order[cur] = low[cur] = time++;\n        int child = 0;\n \
    \       bool is_articulation = false;\n        for (auto &[nex, eid] : g[cur])\
    \ {\n            if (!seen[nex]) {\n                child++;\n               \
    \ dfs(nex, cur, eid);\n                low[cur] = min(low[cur], low[nex]);\n \
    \               if (prev != -1 and order[cur] <= low[nex]) is_articulation = true;\n\
    \                if (order[cur] < low[nex]) bridge.push_back(eid);\n         \
    \   } else if (eid != prev_eid) {\n                low[cur] = min(low[cur], order[nex]);\n\
    \            }\n        }\n        if (prev == -1 and child > 1) is_articulation\
    \ = true;\n        if (is_articulation) articulation.push_back(cur);\n    }\n\n\
    \    void build() {\n        for (int i = 0; i < n; i++) {\n            if (!seen[i])\
    \ dfs(i, -1, -1);\n        }\n    }\n};\n#line 2 \"graph/connected-components/TwoEdgeConnectedComponents.hpp\"\
    \n\nclass TwoEdgeConnectedComponents {\n   private:\n    int n;\n    int m;\n\
    \    int eid;\n    vector<pair<int, int>> edges;\n    LowLink l;\n\n    void dfs(int\
    \ v, int prev, int prev_eid, const vector<bool> &is_bridge, int cid) {\n     \
    \   cmp[v] = cid;\n        for (auto &[nex, eid] : l.g[v]) {\n            if (cmp[nex]\
    \ == -1 and !is_bridge[eid]) {\n                dfs(nex, v, eid, is_bridge, cid);\n\
    \            }\n        }\n    }\n\n   public:\n    vector<int> cmp;\n    vector<vector<int>>\
    \ components;\n\n    TwoEdgeConnectedComponents(int _n) : n(_n), l(_n), eid(0)\
    \ {\n        cmp.assign(n, -1);\n    }\n\n    void add_edge(int u, int v) {\n\
    \        l.add_edge(u, v, eid);\n        edges.emplace_back(u, v);\n        eid++;\n\
    \    }\n\n    void build() {\n        l.build();\n        vector<bool> is_bridge(eid,\
    \ false);\n        for (int id : l.bridge) is_bridge[id] = true;\n\n        int\
    \ cid = 0;\n        for (int i = 0; i < n; i++) {\n            if (cmp[i] == -1)\
    \ {\n                dfs(i, -1, -1, is_bridge, cid++);\n            }\n      \
    \  }\n        components.resize(cid);\n        for (int i = 0; i < n; i++) {\n\
    \            components[cmp[i]].push_back(i);\n        }\n    }\n};\n#line 4 \"\
    verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, m;\n    in(n,\
    \ m);\n    TwoEdgeConnectedComponents g(n);\n\n    rep(i, m) {\n        int u,\
    \ v;\n        in(u, v);\n        g.add_edge(u, v);\n    }\n    g.build();\n\n\
    \    out(g.components.size());\n    for (auto &v : g.components) {\n        out(v.size(),\
    \ v);\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include \"../../../../graph/connected-components/TwoEdgeConnectedComponents.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, m;\n    in(n,\
    \ m);\n    TwoEdgeConnectedComponents g(n);\n\n    rep(i, m) {\n        int u,\
    \ v;\n        in(u, v);\n        g.add_edge(u, v);\n    }\n    g.build();\n\n\
    \    out(g.components.size());\n    for (auto &v : g.components) {\n        out(v.size(),\
    \ v);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/connected-components/TwoEdgeConnectedComponents.hpp
  - graph/others/LowLink.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2024-12-02 00:38:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
- /verify/verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp.html
title: verify/LibraryChecker/graph/connected-components/TwoEdgeConnectedComponents.test.cpp
---
