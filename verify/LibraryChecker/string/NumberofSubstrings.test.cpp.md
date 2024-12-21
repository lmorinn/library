---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/SuffixAutomaton.hpp
    title: Suffix Automaton (Directed Acyclic Word Graph)
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
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/string/NumberofSubstrings.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n#line\
    \ 1 \"string/SuffixAutomaton.hpp\"\nclass SuffixAutomaton {\n   private:\n   \
    \ struct state {\n        int len, slink, cnt;\n        bool is_clone;\n     \
    \   char back;\n        map<char, int> next;\n    };\n\n    // sz: \u72B6\u614B\
    \u6570\n    int sz, last;\n    vector<state> st;\n    vector<int> stat;\n    vector<int>\
    \ topological;\n\n    // \u73FE\u5728\u306E\u72B6\u614B\u3092\u542B\u3081\u3066\
    \u3001\u3044\u304F\u3064\u306E\u72B6\u614B\u3078\u9077\u79FB\u3067\u304D\u308B\
    \u304B\uFF1F\n    vector<int> reach;\n\n    void init() {\n        st[0].len =\
    \ 0;\n        st[0].slink = -1;\n        // cnt: endpos\u96C6\u5408\u306E\u5927\
    \u304D\u3055\n        st[0].cnt = 0;\n        st[0].is_clone = false;\n      \
    \  sz = 1;\n        last = 0;\n        stat.emplace_back(0);\n    }\n\n    void\
    \ extend(char c) {\n        int cur = sz++;\n        st[cur].len = st[last].len\
    \ + 1;\n        st[cur].cnt = 1;\n        st[cur].is_clone = false;\n        st[cur].back\
    \ = c;\n        stat.emplace_back(cur);\n        int p = last;\n        while\
    \ (p != -1 and !st[p].next[c]) {\n            st[p].next[c] = cur;\n         \
    \   p = st[p].slink;\n        }\n        if (p == -1) {\n            st[cur].slink\
    \ = 0;\n        } else {\n            int q = st[p].next[c];\n            if (st[p].len\
    \ + 1 == st[q].len) {\n                st[cur].slink = q;\n            } else\
    \ {\n                int clone = sz++;\n                st[clone].len = st[p].len\
    \ + 1;\n                st[clone].next = st[q].next;\n                st[clone].slink\
    \ = st[q].slink;\n                st[clone].cnt = 0;\n                st[clone].is_clone\
    \ = true;\n                st[clone].back = c;\n                stat.emplace_back(clone);\n\
    \                while (p != -1 and st[p].next[c] == q) {\n                  \
    \  st[p].next[c] = clone;\n                    p = st[p].slink;\n            \
    \    }\n                st[q].slink = st[cur].slink = clone;\n            }\n\
    \        }\n        last = cur;\n    }\n\n    void topo_sort() {\n        topological.resize(sz);\n\
    \        vector<int> in(sz);\n        for (int i = 0; i < sz; i++) {\n       \
    \     for (auto [c, nex] : st[i].next) {\n                in[nex]++;\n       \
    \     }\n        }\n        queue<int> que;\n        for (int i = 0; i < sz; i++)\
    \ {\n            if (in[i] == 0) {\n                que.push(i);\n           \
    \ }\n        }\n        int idx = 0;\n        while (!que.empty()) {\n       \
    \     int cur = que.front();\n            que.pop();\n            topological[idx++]\
    \ = cur;\n            for (auto [c, nex] : st[cur].next) {\n                in[nex]--;\n\
    \                if (in[nex] == 0) {\n                    que.push(nex);\n   \
    \             }\n            }\n        }\n    }\n\n   public:\n    SuffixAutomaton()\
    \ {\n        st.resize(2);\n        init();\n    }\n\n    // S\u306ESuffix Automaton\u3092\
    \u69CB\u7BC9\n    SuffixAutomaton(const string &s) {\n        int n = int(s.size());\n\
    \        st.resize(n << 1 + 1);\n        init();\n        for (int i = 0; i <\
    \ n; i++) {\n            extend(s[i]);\n        }\n        sort(stat.begin(),\
    \ stat.end(), [&](int i, int j) { return st[i].len < st[j].len; });\n        for\
    \ (int i = sz - 1; i >= 0; i--) {\n            if (st[stat[i]].slink != -1) {\n\
    \                st[st[stat[i]].slink].cnt += st[stat[i]].cnt;\n            }\n\
    \        }\n\n        topo_sort();\n        reach.resize(topological.size());\n\
    \n        reach[topological[0]] = 1;\n        for (int i = sz - 1; i >= 0; i--)\
    \ {\n            reach[topological[i]] = 1;\n            int cur = topological[i];\n\
    \            for (auto [c, nex] : st[cur].next) {\n                reach[cur]\
    \ += reach[nex];\n            }\n        }\n    }\n\n    // S\u306E\u76F8\u7570\
    \u306A\u308B\u9023\u7D9A\u90E8\u5206\u6587\u5B57\u5217\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\n    long long number_of_substrings() {\n        long long res =\
    \ 0;\n        for (int i = 1; i < sz; i++) {\n            res += st[i].len - st[st[i].slink].len;\n\
    \        }\n        return res;\n    }\n\n    // T\u306FS\u306E\u9023\u7D9A\u90E8\
    \u5206\u6587\u5B57\u5217\u3067\u3042\u308B\u304B\u5426\u304B\u3092\u8FD4\u3059\
    \n    bool is_substring(const string &t) {\n        int m = int(t.size());\n \
    \       int cur = 0;\n        for (int i = 0; i < m; i++) {\n            if (!st[cur].next[t[i]])\
    \ {\n                return false;\n            }\n            cur = st[cur].next[t[i]];\n\
    \        }\n        return true;\n    }\n\n    // T\u304CS\u306E\u9023\u7D9A\u90E8\
    \u5206\u6587\u5B57\u5217\u3068\u3057\u3066\u4F55\u56DE\u51FA\u73FE\u3059\u308B\
    \u304B\u3092\u8FD4\u3059\n    int count_substring(const string &t) {\n       \
    \ int m = int(t.size());\n        int cur = 0;\n        for (int i = 0; i < m;\
    \ i++) {\n            if (!st[cur].next[t[i]]) {\n                return 0;\n\
    \            }\n            cur = st[cur].next[t[i]];\n        }\n        return\
    \ st[cur].cnt;\n    }\n\n    // S\u306E\u9023\u7D9A\u90E8\u5206\u6587\u5B57\u5217\
    \u306E\u4E2D\u3067s\u304B\u3089\u59CB\u307E\u3063\u3066t\u3067\u7D42\u308F\u308B\
    \u3082\u306E\u306E\u500B\u6570 or \u7A2E\u985E\u6570\u3092\u8FD4\u3059\n    long\
    \ long count_substring(char s, char t, bool distinct = false) {\n        long\
    \ long res = 0;\n        vector<int> dp(sz);\n        if (!st[0].next[s]) {\n\
    \            return 0;\n        }\n\n        dp[st[0].next[s]] = 1;\n        for\
    \ (int i = 0; i < sz; i++) {\n            int cur = topological[i];\n        \
    \    for (auto [c, nex] : st[cur].next) {\n                dp[nex] += dp[cur];\n\
    \            }\n            if (st[cur].back == t) {\n                out(st[cur].len,\
    \ st[cur].cnt, st[cur].back, dp[cur]);\n                if (distinct) {\n    \
    \                res += dp[cur];\n                } else {\n                 \
    \   res += int64_t(dp[cur]) * st[cur].cnt;\n                }\n            }\n\
    \        }\n\n        return res;\n    }\n\n    // t\u3092prefix\u3068\u3057\u3066\
    \u3082\u3064\u9023\u7D9A\u90E8\u5206\u6587\u5B57\u5217\u306E\u7A2E\u985E\u6570\
    \u3092\u8FD4\u3059\n    int count_prefix(const string &t) {\n        int m = int(t.size());\n\
    \        int cur = 0;\n        for (int i = 0; i < m; i++) {\n            if (!st[cur].next[t[i]])\
    \ {\n                return 0;\n            }\n            cur = st[cur].next[t[i]];\n\
    \        }\n        return reach[cur];\n    }\n\n    // S\u306E\u9023\u7D9A\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u4E2D\u3067\u8F9E\u66F8\u9806\u3067k\u756A\u76EE\
    \u306E\u3082\u306E\u3092\u8FD4\u3059\n    string kth_substring(long long k, bool\
    \ distinct = false) {\n        vector<long long> dp(sz);\n\n        dp[topological[0]]\
    \ = 1;\n        for (int i = sz - 1; i >= 0; i--) {\n            dp[topological[i]]\
    \ = st[topological[i]].cnt;\n            int cur = topological[i];\n         \
    \   for (auto [c, nex] : st[cur].next) {\n                dp[cur] += dp[nex];\n\
    \            }\n        }\n        string res;\n        int cur = 0;\n       \
    \ while (k > 0) {\n            for (auto [c, nex] : st[cur].next) {\n        \
    \        if ((distinct ? reach[nex] : dp[nex]) >= k) {\n                    res.push_back(c);\n\
    \                    k -= (distinct ? 1 : st[nex].cnt);\n                    cur\
    \ = nex;\n                    break;\n                } else {\n             \
    \       k -= (distinct ? reach[nex] : dp[nex]);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n\n    // S\u306Eexclude\u914D\u5217\
    \u4EE5\u5916\u306E\u6587\u5B57\u304B\u3089\u306A\u308B\u9023\u7D9A\u90E8\u5206\
    \u6587\u5B57\u5217\u306E\u4E2D\u3067k\u756A\u76EE\u306E\u3082\u306E\u3092\u8FD4\
    \u3059\n    string kth_substring(int k, const vector<char> &exclude) {\n     \
    \   set<char> ex;\n        for (char c : exclude) {\n            ex.insert(c);\n\
    \        }\n        vector<int> dp(sz);\n        dp[topological[0]] = 1;\n   \
    \     for (int i = sz - 1; i >= 0; i--) {\n            dp[topological[i]] = 1;\n\
    \            int cur = topological[i];\n            for (auto [c, nex] : st[cur].next)\
    \ {\n                if (!ex.contains(c)) {\n                    dp[cur] += dp[nex];\n\
    \                }\n            }\n        }\n\n        string res;\n        int\
    \ cur = 0;\n        while (k > 0) {\n            bool nex_exist = false;\n   \
    \         for (auto [c, nex] : st[cur].next) {\n                if (!ex.contains(c))\
    \ {\n                    if (dp[nex] >= k) {\n                        nex_exist\
    \ = true;\n                        res.push_back(c);\n                       \
    \ k--;\n                        cur = nex;\n                        break;\n \
    \                   } else {\n                        k -= dp[nex];\n        \
    \            }\n                } else {\n                    continue;\n    \
    \            }\n            }\n\n            if (!nex_exist) {\n             \
    \   break;\n            }\n        }\n\n        if (k > 0) {\n            return\
    \ \"\";\n        }\n        return res;\n    }\n};\n#line 4 \"verify/LibraryChecker/string/NumberofSubstrings.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  string s;\n  in(s);\n \
    \ out(SuffixAutomaton(s).number_of_substrings());\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \n#include \"../../../string/SuffixAutomaton.hpp\"\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  string s;\n  in(s);\n  out(SuffixAutomaton(s).number_of_substrings());\n}\n"
  dependsOn:
  - template/template.hpp
  - string/SuffixAutomaton.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/string/NumberofSubstrings.test.cpp
  requiredBy: []
  timestamp: '2024-12-21 23:38:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/string/NumberofSubstrings.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/string/NumberofSubstrings.test.cpp
- /verify/verify/LibraryChecker/string/NumberofSubstrings.test.cpp.html
title: verify/LibraryChecker/string/NumberofSubstrings.test.cpp
---
