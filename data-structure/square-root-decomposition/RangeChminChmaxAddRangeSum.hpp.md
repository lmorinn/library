---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
    title: verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp\"\
    \n\ntemplate <class T>\nclass RangeChminChmaxAddRangeSum {\n   private:\n    int\
    \ n;\n    vector<T> a, sum, offset;\n    vector<int> divi;\n    vector<bool> modulo;\n\
    \n    vector<deque<pair<T, int>>> deq;\n    int bsize, bnum;\n\n    inline void\
    \ build(int bidx) {\n        sum[bidx] = 0;\n        offset[bidx] = 0;\n     \
    \   map<T, int> cnt;\n        int l = bidx * bsize;\n        int r = min(n, l\
    \ + bsize);\n        for (int i = l; i < r; i++) {\n            cnt[a[i]]++;\n\
    \            sum[bidx] += a[i];\n        }\n        deq[bidx].assign(begin(cnt),\
    \ end(cnt));\n    }\n\n    inline void push(int bidx) {\n        sum[bidx] +=\
    \ offset[bidx] * (min((bidx + 1) * bsize, n) - bidx * bsize);\n        T lower\
    \ = offset[bidx] + deq[bidx].front().first;\n        T upper = offset[bidx] +\
    \ deq[bidx].back().first;\n        for (int i = bidx * bsize; i < min((bidx +\
    \ 1) * bsize, n); i++) {\n            a[i] = min(max(a[i] + offset[bidx], lower),\
    \ upper);\n        }\n    }\n\n   public:\n    RangeChminChmaxAddRangeSum(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        divi.resize(n\
    \ + 1);\n        modulo.assign(n + 1, false);\n        bsize = 250;\n        bnum\
    \ = (n + bsize - 1) / bsize;\n        deq.resize(bnum);\n        sum.assign(bnum,\
    \ 0);\n        offset.assign(bnum, 0);\n        for (int i = 0; i < n + 1; i++)\
    \ {\n            divi[i] = i / bsize;\n            modulo[i] = ((i % bsize) !=\
    \ 0);\n        }\n\n        for (int i = 0; i < bnum; i++) {\n            build(i);\n\
    \        }\n    }\n\n    void range_chmin(int l, int r, T x) {\n        // \u5DE6\
    \u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n            while\
    \ (l < r and modulo[l]) {\n                a[l] = min(a[l], x);\n            \
    \    l++;\n            }\n            build(divi[l - 1]);\n        }\n\n     \
    \   // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n  \
    \          while (l < r and modulo[r]) {\n                r--;\n             \
    \   a[r] = min(a[r], x);\n            }\n            build(divi[r]);\n       \
    \ }\n\n        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r)\
    \ {\n            int i = divi[l];\n            while (offset[i] + deq[i].back().first\
    \ > x) {\n                auto p = deq[i].back();\n                deq[i].pop_back();\n\
    \                if (deq[i].empty() or offset[i] + deq[i].back().first < x) {\n\
    \                    deq[i].emplace_back(x - offset[i], 0);\n                }\n\
    \                sum[i] -= (p.first - deq[i].back().first) * p.second;\n     \
    \           deq[i].back().second += p.second;\n            }\n            l +=\
    \ bsize;\n        }\n    }\n\n    void range_chmax(int l, int r, T x) {\n    \
    \    // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n \
    \           while (l < r and modulo[l]) {\n                a[l] = max(a[l], x);\n\
    \                l++;\n            }\n            build(divi[l - 1]);\n      \
    \  }\n\n        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     a[r] = max(a[r], x);\n            }\n            build(divi[r]);\n     \
    \   }\n\n        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r)\
    \ {\n            int i = divi[l];\n            while (offset[i] + deq[i].front().first\
    \ < x) {\n                auto p = deq[i].front();\n                deq[i].pop_front();\n\
    \                if (deq[i].empty() or offset[i] + deq[i].front().first > x) {\n\
    \                    deq[i].emplace_front(x - offset[i], 0);\n               \
    \ }\n                sum[i] += (deq[i].front().first - p.first) * p.second;\n\
    \                deq[i].front().second += p.second;\n            }\n         \
    \   l += bsize;\n        }\n    }\n\n    void range_add(int l, int r, T x) {\n\
    \        // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n\
    \            while (l < r and modulo[l]) {\n                a[l] += x;\n     \
    \           l++;\n            }\n            build(divi[l - 1]);\n        }\n\n\
    \        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     a[r] += x;\n            }\n            build(divi[r]);\n        }\n\n  \
    \      // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r) {\n    \
    \        int i = divi[l];\n            offset[i] += x;\n            l += bsize;\n\
    \        }\n    }\n\n    T range_sum(int l, int r) {\n        T res = 0;\n   \
    \     // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n\
    \            while (l < r and modulo[l]) {\n                res += a[l];\n   \
    \             l++;\n            }\n            build(divi[l - 1]);\n        }\n\
    \n        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     res += a[r];\n            }\n            build(divi[r]);\n        }\n\n\
    \        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r) {\n  \
    \          int i = divi[l];\n            res += offset[i] * (min((i + 1) * bsize,\
    \ n) - i * bsize) + sum[i];\n            l += bsize;\n        }\n        return\
    \ res;\n    }\n};\n"
  code: "\ntemplate <class T>\nclass RangeChminChmaxAddRangeSum {\n   private:\n \
    \   int n;\n    vector<T> a, sum, offset;\n    vector<int> divi;\n    vector<bool>\
    \ modulo;\n\n    vector<deque<pair<T, int>>> deq;\n    int bsize, bnum;\n\n  \
    \  inline void build(int bidx) {\n        sum[bidx] = 0;\n        offset[bidx]\
    \ = 0;\n        map<T, int> cnt;\n        int l = bidx * bsize;\n        int r\
    \ = min(n, l + bsize);\n        for (int i = l; i < r; i++) {\n            cnt[a[i]]++;\n\
    \            sum[bidx] += a[i];\n        }\n        deq[bidx].assign(begin(cnt),\
    \ end(cnt));\n    }\n\n    inline void push(int bidx) {\n        sum[bidx] +=\
    \ offset[bidx] * (min((bidx + 1) * bsize, n) - bidx * bsize);\n        T lower\
    \ = offset[bidx] + deq[bidx].front().first;\n        T upper = offset[bidx] +\
    \ deq[bidx].back().first;\n        for (int i = bidx * bsize; i < min((bidx +\
    \ 1) * bsize, n); i++) {\n            a[i] = min(max(a[i] + offset[bidx], lower),\
    \ upper);\n        }\n    }\n\n   public:\n    RangeChminChmaxAddRangeSum(const\
    \ vector<T> &v) {\n        a = v;\n        n = a.size();\n        divi.resize(n\
    \ + 1);\n        modulo.assign(n + 1, false);\n        bsize = 250;\n        bnum\
    \ = (n + bsize - 1) / bsize;\n        deq.resize(bnum);\n        sum.assign(bnum,\
    \ 0);\n        offset.assign(bnum, 0);\n        for (int i = 0; i < n + 1; i++)\
    \ {\n            divi[i] = i / bsize;\n            modulo[i] = ((i % bsize) !=\
    \ 0);\n        }\n\n        for (int i = 0; i < bnum; i++) {\n            build(i);\n\
    \        }\n    }\n\n    void range_chmin(int l, int r, T x) {\n        // \u5DE6\
    \u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n            while\
    \ (l < r and modulo[l]) {\n                a[l] = min(a[l], x);\n            \
    \    l++;\n            }\n            build(divi[l - 1]);\n        }\n\n     \
    \   // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n  \
    \          while (l < r and modulo[r]) {\n                r--;\n             \
    \   a[r] = min(a[r], x);\n            }\n            build(divi[r]);\n       \
    \ }\n\n        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r)\
    \ {\n            int i = divi[l];\n            while (offset[i] + deq[i].back().first\
    \ > x) {\n                auto p = deq[i].back();\n                deq[i].pop_back();\n\
    \                if (deq[i].empty() or offset[i] + deq[i].back().first < x) {\n\
    \                    deq[i].emplace_back(x - offset[i], 0);\n                }\n\
    \                sum[i] -= (p.first - deq[i].back().first) * p.second;\n     \
    \           deq[i].back().second += p.second;\n            }\n            l +=\
    \ bsize;\n        }\n    }\n\n    void range_chmax(int l, int r, T x) {\n    \
    \    // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n \
    \           while (l < r and modulo[l]) {\n                a[l] = max(a[l], x);\n\
    \                l++;\n            }\n            build(divi[l - 1]);\n      \
    \  }\n\n        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     a[r] = max(a[r], x);\n            }\n            build(divi[r]);\n     \
    \   }\n\n        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r)\
    \ {\n            int i = divi[l];\n            while (offset[i] + deq[i].front().first\
    \ < x) {\n                auto p = deq[i].front();\n                deq[i].pop_front();\n\
    \                if (deq[i].empty() or offset[i] + deq[i].front().first > x) {\n\
    \                    deq[i].emplace_front(x - offset[i], 0);\n               \
    \ }\n                sum[i] += (deq[i].front().first - p.first) * p.second;\n\
    \                deq[i].front().second += p.second;\n            }\n         \
    \   l += bsize;\n        }\n    }\n\n    void range_add(int l, int r, T x) {\n\
    \        // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n\
    \            while (l < r and modulo[l]) {\n                a[l] += x;\n     \
    \           l++;\n            }\n            build(divi[l - 1]);\n        }\n\n\
    \        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     a[r] += x;\n            }\n            build(divi[r]);\n        }\n\n  \
    \      // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r) {\n    \
    \        int i = divi[l];\n            offset[i] += x;\n            l += bsize;\n\
    \        }\n    }\n\n    T range_sum(int l, int r) {\n        T res = 0;\n   \
    \     // \u5DE6\u7AEF\n        if (modulo[l]) {\n            push(divi[l]);\n\
    \            while (l < r and modulo[l]) {\n                res += a[l];\n   \
    \             l++;\n            }\n            build(divi[l - 1]);\n        }\n\
    \n        // \u53F3\u7AEF\n        if (modulo[r]) {\n            push(divi[r]);\n\
    \            while (l < r and modulo[r]) {\n                r--;\n           \
    \     res += a[r];\n            }\n            build(divi[r]);\n        }\n\n\
    \        // \u30D0\u30B1\u30C3\u30C8\u5168\u4F53\n        while (l < r) {\n  \
    \          int i = divi[l];\n            res += offset[i] * (min((i + 1) * bsize,\
    \ n) - i * bsize) + sum[i];\n            l += bsize;\n        }\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp
  requiredBy: []
  timestamp: '2024-11-28 20:50:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.test.cpp
documentation_of: data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp
layout: document
title: Range Chmin Chmax Add Range Sum
---

## 概要

todo

## 計算量
todo