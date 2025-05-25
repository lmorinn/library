---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/connected-components/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#line 1 \"graph/connected-components/StronglyConnectedComponents.hpp\"\
    \n\nclass SCC {\n   private:\n    vector<vector<int>> g, r;\n    int time;\n \
    \   int n;\n    vector<bool> seen, seen2;\n    vector<int> idx;\n    int component_id;\n\
    \    vector<vector<int>> components;\n\n    void dfs(int cur) {\n        seen[cur]\
    \ = true;\n        for (auto nex : g[cur]) {\n            if (seen[nex] == false)\
    \ {\n                dfs(nex);\n            }\n        }\n        idx[time] =\
    \ cur;\n        time++;\n    }\n\n    void dfs2(int cur) {\n        seen2[cur]\
    \ = true;\n        components[component_id].emplace_back(cur);\n        for (auto\
    \ nex : r[cur]) {\n            if (seen2[nex] == false) {\n                dfs2(nex);\n\
    \            }\n        }\n    }\n\n   public:\n    SCC() {}\n    SCC(int siz)\
    \ {\n        n = siz;\n        g.resize(n);\n        r.resize(n);\n        time\
    \ = 0;\n        component_id = 0;\n        idx.assign(n, -1);\n        seen.assign(n,\
    \ false);\n        seen2.assign(n, false);\n    }\n\n    void add_edge(int u,\
    \ int v) {\n        g[u].emplace_back(v);\n        r[v].emplace_back(u);\n   \
    \ }\n\n    vector<vector<int>> decompose() {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (!seen[i]) {\n                dfs(i);\n            }\n   \
    \     }\n\n        for (int i = time - 1; i >= 0; i--) {\n            if (!seen2[idx[i]])\
    \ {\n                components.emplace_back(vector<int>());\n               \
    \ dfs2(idx[i]);\n                component_id++;\n            }\n        }\n\n\
    \        return components;\n    }\n};\n#line 4 \"verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n#include \"../../../../graph/connected-components/StronglyConnectedComponents.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/connected-components/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2025-05-26 06:11:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
- /verify/verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp.html
title: verify/LibraryChecker/graph/connected-components/StronglyConnectedComponents.test.cpp
---
