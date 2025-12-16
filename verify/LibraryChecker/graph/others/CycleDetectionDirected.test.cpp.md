---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/others/CycleDetection.hpp
    title: Cycle Detection
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#line 1\
    \ \"graph/others/CycleDetection.hpp\"\ntemplate <class T>\nclass CycleDetection\
    \ {\n   private:\n    struct Edge {\n        int from = -1, to = -1;\n       \
    \ T val;\n        Edge() {}\n        Edge(int f, int t, T v) {\n            from\
    \ = f;\n            to = t;\n            val = v;\n        }\n    };\n\n    vector<vector<Edge>>\
    \ g;\n    vector<unordered_map<int, int>> undirected_id;\n    int n;\n    bool\
    \ is_directed;\n    bool ud_two_edge_cycle = false;\n    stack<Edge> history;\n\
    \    pair<int, int> two_v;\n    T two_e;\n    vector<bool> seen, finished;\n\n\
    \    int dfs(int cur, Edge cur_e, bool is_prohibit_reverse) {\n        seen[cur]\
    \ = true;\n        history.emplace(cur_e);\n        for (const Edge &nex : g[cur])\
    \ {\n            if (is_prohibit_reverse and cur_e.from == nex.to) continue;\n\
    \            if (finished[nex.to]) continue;\n            if (seen[nex.to] and\
    \ !finished[nex.to]) {\n                history.emplace(nex);\n              \
    \  return nex.to;\n            }\n            int pos = dfs(nex.to, nex, is_prohibit_reverse);\n\
    \            if (pos != -1) return pos;\n        }\n        finished[cur] = true;\n\
    \        history.pop();\n        return -1;\n    }\n\n    vector<Edge> reconstruct(int\
    \ pos) {\n        vector<Edge> cycle;\n        while (!history.empty()) {\n  \
    \          const Edge &e = history.top();\n            history.pop();\n      \
    \      cycle.emplace_back(e);\n            if (e.from == pos) break;\n       \
    \ }\n        reverse(cycle.begin(), cycle.end());\n        return cycle;\n   \
    \ }\n\n    vector<Edge> detect(bool is_prohibit_reverse = true) {\n        seen.assign(n,\
    \ false);\n        finished.assign(n, false);\n        int pos = -1;\n       \
    \ for (int cur = 0; cur < n and pos == -1; cur++) {\n            if (seen[cur])\
    \ continue;\n            while (!history.empty()) history.pop();\n           \
    \ pos = dfs(cur, Edge(), is_prohibit_reverse);\n            if (pos != -1) return\
    \ reconstruct(pos);\n        }\n        return vector<Edge>();\n    }\n\n   public:\n\
    \    CycleDetection(int siz, bool is_directed_graph) {\n        n = siz;\n   \
    \     is_directed = is_directed_graph;\n        g.resize(n);\n        if (!is_directed)\
    \ undirected_id.resize(n);\n    }\n\n    void add_edge(int u, int v, T w) {\n\
    \        if (is_directed) {\n            g[u].emplace_back(Edge(u, v, w));\n \
    \       } else {\n            if (u > v) swap(u, v);\n            if (undirected_id[u].contains(v))\
    \ {\n                ud_two_edge_cycle = true;\n                two_v = {u, v};\n\
    \                two_e = w;\n            } else {\n                undirected_id[u][v]\
    \ = w;\n            }\n            g[u].emplace_back(Edge(u, v, w));\n       \
    \     g[v].emplace_back(Edge(v, u, w));\n        }\n    }\n\n    vector<Edge>\
    \ cycle() {\n        if (is_directed) {\n            return detect(false);\n \
    \       } else if (ud_two_edge_cycle) {\n            int u = two_v.first;\n  \
    \          int v = two_v.second;\n            vector<Edge> res = {Edge(u, v, undirected_id[u][v]),\
    \ Edge(v, u, two_e)};\n            return res;\n        } else {\n           \
    \ return detect(true);\n        }\n    }\n};\n#line 4 \"verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, m;\n    in(n,\
    \ m);\n    CycleDetection<int> g(n, true);\n    rep(i, m) {\n        int u, v;\n\
    \        in(u, v);\n        g.add_edge(u, v, i);\n    }\n\n    auto res = g.cycle();\n\
    \    int len = res.size();\n    if (len == 0) {\n        out(-1);\n    } else\
    \ {\n        out(len);\n        rep(i, len) {\n            out(res[i].val);\n\
    \        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\
    \n#include \"../../../../graph/others/CycleDetection.hpp\"\n\nint main() {\n \
    \   cin.tie(0)->sync_with_stdio(0);\n    int n, m;\n    in(n, m);\n    CycleDetection<int>\
    \ g(n, true);\n    rep(i, m) {\n        int u, v;\n        in(u, v);\n       \
    \ g.add_edge(u, v, i);\n    }\n\n    auto res = g.cycle();\n    int len = res.size();\n\
    \    if (len == 0) {\n        out(-1);\n    } else {\n        out(len);\n    \
    \    rep(i, len) {\n            out(res[i].val);\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/others/CycleDetection.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
  requiredBy: []
  timestamp: '2025-05-26 05:25:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
- /verify/verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp.html
title: verify/LibraryChecker/graph/others/CycleDetectionDirected.test.cpp
---
