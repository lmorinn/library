---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/Dijkstra.hpp
    title: Dijkstra
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C\"\
    \n\n#line 1 \"graph/shortest-path/Dijkstra.hpp\"\ntemplate <class T>\nclass Dijkstra\
    \ {\n   private:\n    vector<vector<pair<int, T>>> g;\n    vector<T> dist;\n \
    \   vector<int> prev;\n    int n;\n\n   public:\n    Dijkstra(vector<vector<pair<int,\
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
    \        return ret;\n    }\n};\n#line 5 \"verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp\"\
    \n\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\n    int n;\n    in(n);\n\
    \    vector<vector<pair<int, lint>>> g(n);\n    rep(i, n) {\n        int u, k;\n\
    \        in(u, k);\n        rep(j, k) {\n            int v, c;\n            in(v,\
    \ c);\n            g[u].emplace_back(v, c);\n        }\n    }\n\n    Dijkstra<lint>\
    \ d(g);\n    rep(i, n) {\n        out(i, d.get_dist(i));\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C\"\
    \n\n#include \"../../../../graph/shortest-path/Dijkstra.hpp\"\n\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n\n    int n;\n    in(n);\n    vector<vector<pair<int,\
    \ lint>>> g(n);\n    rep(i, n) {\n        int u, k;\n        in(u, k);\n     \
    \   rep(j, k) {\n            int v, c;\n            in(v, c);\n            g[u].emplace_back(v,\
    \ c);\n        }\n    }\n\n    Dijkstra<lint> d(g);\n    rep(i, n) {\n       \
    \ out(i, d.get_dist(i));\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/shortest-path/Dijkstra.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
  requiredBy: []
  timestamp: '2025-09-28 01:10:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
- /verify/verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp.html
title: verify/AizuOnlineJudge/graph/shortest-path/ALDS1_12_C.test.cpp
---
