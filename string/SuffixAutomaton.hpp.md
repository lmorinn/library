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
  bundledCode: "#line 1 \"string/SuffixAutomaton.hpp\"\nclass SuffixAutomaton {\n\
    \   private:\n    struct state {\n        int len, slink, cnt;\n        bool is_clone;\n\
    \        map<char, int> next;\n    };\n\n    // sz: \u72B6\u614B\u6570\n    int\
    \ sz, last;\n    vector<state> st;\n    vector<int> stat;\n    vector<int> topological;\n\
    \n    void\n    init() {\n        st[0].len = 0;\n        st[0].slink = -1;\n\
    \        st[0].cnt = 0;\n        st[0].is_clone = false;\n        sz = 1;\n  \
    \      last = 0;\n    }\n\n    void extend(char c) {\n        int cur = sz++;\n\
    \        st[cur].len = st[last].len + 1;\n        st[cur].cnt = 1;\n        st[cur].is_clone\
    \ = false;\n        stat.emplace_back(cur);\n        int p = last;\n        while\
    \ (p != -1 and !st[p].next[c]) {\n            st[p].next[c] = cur;\n         \
    \   p = st[p].slink;\n        }\n        if (p == -1) {\n            st[cur].slink\
    \ = 0;\n        } else {\n            int q = st[p].next[c];\n            if (st[p].len\
    \ + 1 == st[q].len) {\n                st[cur].slink = q;\n            } else\
    \ {\n                int clone = sz++;\n                st[clone].len = st[p].len\
    \ + 1;\n                st[clone].next = st[q].next;\n                st[clone].slink\
    \ = st[q].slink;\n                st[clone].cnt = 0;\n                st[clone].is_clone\
    \ = true;\n                stat.emplace_back(clone);\n                while (p\
    \ != -1 and st[p].next[c] == q) {\n                    st[p].next[c] = clone;\n\
    \                    p = st[p].slink;\n                }\n                st[q].slink\
    \ = st[cur].slink = clone;\n            }\n        }\n        last = cur;\n  \
    \  }\n\n    void topo_sort() {\n        topological.resize(sz);\n        vector<int>\
    \ in(sz);\n        for (int i = 0; i < sz; i++) {\n            for (auto [c, nex]\
    \ : st[i].next) {\n                in[nex]++;\n            }\n        }\n    \
    \    queue<int> que;\n        for (int i = 0; i < sz; i++) {\n            if (in[i]\
    \ == 0) {\n                que.push(i);\n            }\n        }\n        int\
    \ idx = 0;\n        while (!que.empty()) {\n            int cur = que.front();\n\
    \            que.pop();\n            topological[idx++] = cur;\n            for\
    \ (auto [c, nex] : st[cur].next) {\n                in[nex]--;\n             \
    \   if (in[nex] == 0) {\n                    que.push(nex);\n                }\n\
    \            }\n        }\n    }\n\n   public:\n    SuffixAutomaton() {\n    \
    \    st.resize(2);\n        init();\n    }\n\n    SuffixAutomaton(const string\
    \ &s) {\n        int n = int(s.size());\n        st.resize(n << 1);\n        init();\n\
    \        for (int i = 0; i < n; i++) {\n            extend(s[i]);\n        }\n\
    \        sort(stat.begin(), stat.end(), [&](int i, int j) { return st[i].len <\
    \ st[j].len; });\n        for (int i = sz - 1; i >= 0; i--) {\n            if\
    \ (st[stat[i]].slink != -1) {\n                st[st[stat[i]].slink].cnt += st[stat[i]].cnt;\n\
    \            }\n        }\n\n        topo_sort();\n    }\n\n    long long number_of_substrings()\
    \ {\n        long long res = 0;\n        for (int i = 1; i < sz; i++) {\n    \
    \        res += st[i].len - st[st[i].slink].len;\n        }\n        return res;\n\
    \    }\n\n    bool is_substring(const string &t) {\n        int m = int(t.size());\n\
    \        int cur = 0;\n        for (int i = 0; i < m; i++) {\n            if (!st[cur].next[t[i]])\
    \ {\n                return false;\n            }\n            cur = st[cur].next[t[i]];\n\
    \        }\n        return true;\n    }\n\n    int count_substring(const string\
    \ &t) {\n        int m = int(t.size());\n        int cur = 0;\n        for (int\
    \ i = 0; i < m; i++) {\n            if (!st[cur].next[t[i]]) {\n             \
    \   return 0;\n            }\n            cur = st[cur].next[t[i]];\n        }\n\
    \        return st[cur].cnt;\n    }\n\n    string kth_substring(int k) {\n   \
    \     vector<int> dp(sz);\n        dp[topological[0]] = 1;\n        for (int i\
    \ = sz - 1; i >= 0; i--) {\n            dp[topological[i]] = 1;\n            int\
    \ cur = topological[i];\n            for (auto [c, nex] : st[cur].next) {\n  \
    \              dp[cur] += dp[nex];\n            }\n        }\n        string res;\n\
    \        int cur = 0;\n        while (k > 0) {\n            for (auto [c, nex]\
    \ : st[cur].next) {\n                if (dp[nex] >= k) {\n                   \
    \ res.push_back(c);\n                    k--;\n                    cur = nex;\n\
    \                    break;\n                } else {\n                    k -=\
    \ dp[nex];\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n    string kth_substring(int k, const vector<char> &exclude) {\n   \
    \     set<char> ex;\n        for (char c : exclude) {\n            ex.insert(c);\n\
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
    \ \"\";\n        }\n        return res;\n    }\n};\n"
  code: "class SuffixAutomaton {\n   private:\n    struct state {\n        int len,\
    \ slink, cnt;\n        bool is_clone;\n        map<char, int> next;\n    };\n\n\
    \    // sz: \u72B6\u614B\u6570\n    int sz, last;\n    vector<state> st;\n   \
    \ vector<int> stat;\n    vector<int> topological;\n\n    void\n    init() {\n\
    \        st[0].len = 0;\n        st[0].slink = -1;\n        st[0].cnt = 0;\n \
    \       st[0].is_clone = false;\n        sz = 1;\n        last = 0;\n    }\n\n\
    \    void extend(char c) {\n        int cur = sz++;\n        st[cur].len = st[last].len\
    \ + 1;\n        st[cur].cnt = 1;\n        st[cur].is_clone = false;\n        stat.emplace_back(cur);\n\
    \        int p = last;\n        while (p != -1 and !st[p].next[c]) {\n       \
    \     st[p].next[c] = cur;\n            p = st[p].slink;\n        }\n        if\
    \ (p == -1) {\n            st[cur].slink = 0;\n        } else {\n            int\
    \ q = st[p].next[c];\n            if (st[p].len + 1 == st[q].len) {\n        \
    \        st[cur].slink = q;\n            } else {\n                int clone =\
    \ sz++;\n                st[clone].len = st[p].len + 1;\n                st[clone].next\
    \ = st[q].next;\n                st[clone].slink = st[q].slink;\n            \
    \    st[clone].cnt = 0;\n                st[clone].is_clone = true;\n        \
    \        stat.emplace_back(clone);\n                while (p != -1 and st[p].next[c]\
    \ == q) {\n                    st[p].next[c] = clone;\n                    p =\
    \ st[p].slink;\n                }\n                st[q].slink = st[cur].slink\
    \ = clone;\n            }\n        }\n        last = cur;\n    }\n\n    void topo_sort()\
    \ {\n        topological.resize(sz);\n        vector<int> in(sz);\n        for\
    \ (int i = 0; i < sz; i++) {\n            for (auto [c, nex] : st[i].next) {\n\
    \                in[nex]++;\n            }\n        }\n        queue<int> que;\n\
    \        for (int i = 0; i < sz; i++) {\n            if (in[i] == 0) {\n     \
    \           que.push(i);\n            }\n        }\n        int idx = 0;\n   \
    \     while (!que.empty()) {\n            int cur = que.front();\n           \
    \ que.pop();\n            topological[idx++] = cur;\n            for (auto [c,\
    \ nex] : st[cur].next) {\n                in[nex]--;\n                if (in[nex]\
    \ == 0) {\n                    que.push(nex);\n                }\n           \
    \ }\n        }\n    }\n\n   public:\n    SuffixAutomaton() {\n        st.resize(2);\n\
    \        init();\n    }\n\n    SuffixAutomaton(const string &s) {\n        int\
    \ n = int(s.size());\n        st.resize(n << 1);\n        init();\n        for\
    \ (int i = 0; i < n; i++) {\n            extend(s[i]);\n        }\n        sort(stat.begin(),\
    \ stat.end(), [&](int i, int j) { return st[i].len < st[j].len; });\n        for\
    \ (int i = sz - 1; i >= 0; i--) {\n            if (st[stat[i]].slink != -1) {\n\
    \                st[st[stat[i]].slink].cnt += st[stat[i]].cnt;\n            }\n\
    \        }\n\n        topo_sort();\n    }\n\n    long long number_of_substrings()\
    \ {\n        long long res = 0;\n        for (int i = 1; i < sz; i++) {\n    \
    \        res += st[i].len - st[st[i].slink].len;\n        }\n        return res;\n\
    \    }\n\n    bool is_substring(const string &t) {\n        int m = int(t.size());\n\
    \        int cur = 0;\n        for (int i = 0; i < m; i++) {\n            if (!st[cur].next[t[i]])\
    \ {\n                return false;\n            }\n            cur = st[cur].next[t[i]];\n\
    \        }\n        return true;\n    }\n\n    int count_substring(const string\
    \ &t) {\n        int m = int(t.size());\n        int cur = 0;\n        for (int\
    \ i = 0; i < m; i++) {\n            if (!st[cur].next[t[i]]) {\n             \
    \   return 0;\n            }\n            cur = st[cur].next[t[i]];\n        }\n\
    \        return st[cur].cnt;\n    }\n\n    string kth_substring(int k) {\n   \
    \     vector<int> dp(sz);\n        dp[topological[0]] = 1;\n        for (int i\
    \ = sz - 1; i >= 0; i--) {\n            dp[topological[i]] = 1;\n            int\
    \ cur = topological[i];\n            for (auto [c, nex] : st[cur].next) {\n  \
    \              dp[cur] += dp[nex];\n            }\n        }\n        string res;\n\
    \        int cur = 0;\n        while (k > 0) {\n            for (auto [c, nex]\
    \ : st[cur].next) {\n                if (dp[nex] >= k) {\n                   \
    \ res.push_back(c);\n                    k--;\n                    cur = nex;\n\
    \                    break;\n                } else {\n                    k -=\
    \ dp[nex];\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n    string kth_substring(int k, const vector<char> &exclude) {\n   \
    \     set<char> ex;\n        for (char c : exclude) {\n            ex.insert(c);\n\
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
    \ \"\";\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/SuffixAutomaton.hpp
  requiredBy: []
  timestamp: '2024-12-19 16:32:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/SuffixAutomaton.hpp
layout: document
title: Suffix Automaton (Directed Acyclic Word Graph)
---

## 概要

todo

## 計算量
todo