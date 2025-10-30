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
  bundledCode: "#line 1 \"math/number-theory/SternBrocotTree.hpp\"\n\n// m/n\nvector<pair<char,\
    \ int>> encode_path(lint m, lint n) {\n    vector<pair<char, int>> res;\n    while\
    \ (m != 1 or n != 1) {\n        if (m < n) {\n            int num = (n - 1) /\
    \ m;\n            res.emplace_back('L', num);\n            n -= m * num;\n   \
    \     } else {\n            int num = (m - 1) / n;\n            res.emplace_back('R',\
    \ num);\n            m -= n * num;\n        }\n    }\n    return res;\n}\n\npair<long\
    \ long, long long> decode_path(const vector<pair<char, int>>& path) {\n    long\
    \ long n = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ =\
    \ 1;\n    if (path.empty()) return {1, 1};\n    for (const auto [c, num] : path)\
    \ {\n        if (c == 'L') {\n            n_ += n * num;\n            m_ += m\
    \ * num;\n        } else {\n            n += n_ * num;\n            m += m_ *\
    \ num;\n        }\n    }\n\n    return {m + m_, n + n_};\n}\n\n// a/b, c/d\npair<long\
    \ long, long long> sbt_lca(long long a, long long b, long long c, long long d)\
    \ {\n    vector<pair<char, int>> p1 = encode_path(a, b);\n    vector<pair<char,\
    \ int>> p2 = encode_path(c, d);\n    int siz = min(int(p1.size()), int(p2.size()));\n\
    \    if (siz == 0) return {1, 1};\n    long long n = 1;\n    long long m = 0;\n\
    \    long long n_ = 0;\n    long long m_ = 1;\n    for (int i = 0; i < siz; i++)\
    \ {\n        if (p1[i].first != p2[i].first) {\n            break;\n        }\
    \ else {\n            long long num = min(p1[i].second, p2[i].second);\n     \
    \       if (p1[i].first == 'L') {\n                n_ += n * num;\n          \
    \      m_ += m * num;\n            } else {\n                n += n_ * num;\n\
    \                m += m_ * num;\n            }\n            if (p1[i].second !=\
    \ p2[i].second) break;\n        }\n    }\n\n    return {m + m_, n + n_};\n}\n\n\
    // a/b\npair<long long, long long> sbt_ancestor(int k, long long a, long long\
    \ b) {\n    vector<pair<char, int>> path = encode_path(a, b);\n    long long n\
    \ = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n \
    \   for (auto [c, num] : path) {\n        long long len = min(k, num);\n     \
    \   if (c == 'L') {\n            n_ += n * len;\n            m_ += m * len;\n\
    \        } else {\n            n += n_ * len;\n            m += m_ * len;\n  \
    \      }\n        k -= len;\n        if (k == 0) break;\n    }\n    if (k == 0)\
    \ {\n        return {m + m_, n + n_};\n    } else {\n        return {-1, 1};\n\
    \    }\n}\n\nvector<pair<long long, long long>> sbt_range(long long a, long long\
    \ b) {\n    vector<pair<char, int>> path = encode_path(a, b);\n    long long n\
    \ = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n\n\
    \    if (path.empty()) return {{0, 1}, {1, 0}};\n    for (const auto [c, num]\
    \ : path) {\n        if (c == 'L') {\n            n_ += n * num;\n           \
    \ m_ += m * num;\n        } else {\n            n += n_ * num;\n            m\
    \ += m_ * num;\n        }\n    }\n    return {{m, n}, {m_, n_}};\n}\n"
  code: "\n// m/n\nvector<pair<char, int>> encode_path(lint m, lint n) {\n    vector<pair<char,\
    \ int>> res;\n    while (m != 1 or n != 1) {\n        if (m < n) {\n         \
    \   int num = (n - 1) / m;\n            res.emplace_back('L', num);\n        \
    \    n -= m * num;\n        } else {\n            int num = (m - 1) / n;\n   \
    \         res.emplace_back('R', num);\n            m -= n * num;\n        }\n\
    \    }\n    return res;\n}\n\npair<long long, long long> decode_path(const vector<pair<char,\
    \ int>>& path) {\n    long long n = 1;\n    long long m = 0;\n    long long n_\
    \ = 0;\n    long long m_ = 1;\n    if (path.empty()) return {1, 1};\n    for (const\
    \ auto [c, num] : path) {\n        if (c == 'L') {\n            n_ += n * num;\n\
    \            m_ += m * num;\n        } else {\n            n += n_ * num;\n  \
    \          m += m_ * num;\n        }\n    }\n\n    return {m + m_, n + n_};\n\
    }\n\n// a/b, c/d\npair<long long, long long> sbt_lca(long long a, long long b,\
    \ long long c, long long d) {\n    vector<pair<char, int>> p1 = encode_path(a,\
    \ b);\n    vector<pair<char, int>> p2 = encode_path(c, d);\n    int siz = min(int(p1.size()),\
    \ int(p2.size()));\n    if (siz == 0) return {1, 1};\n    long long n = 1;\n \
    \   long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n    for (int\
    \ i = 0; i < siz; i++) {\n        if (p1[i].first != p2[i].first) {\n        \
    \    break;\n        } else {\n            long long num = min(p1[i].second, p2[i].second);\n\
    \            if (p1[i].first == 'L') {\n                n_ += n * num;\n     \
    \           m_ += m * num;\n            } else {\n                n += n_ * num;\n\
    \                m += m_ * num;\n            }\n            if (p1[i].second !=\
    \ p2[i].second) break;\n        }\n    }\n\n    return {m + m_, n + n_};\n}\n\n\
    // a/b\npair<long long, long long> sbt_ancestor(int k, long long a, long long\
    \ b) {\n    vector<pair<char, int>> path = encode_path(a, b);\n    long long n\
    \ = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n \
    \   for (auto [c, num] : path) {\n        long long len = min(k, num);\n     \
    \   if (c == 'L') {\n            n_ += n * len;\n            m_ += m * len;\n\
    \        } else {\n            n += n_ * len;\n            m += m_ * len;\n  \
    \      }\n        k -= len;\n        if (k == 0) break;\n    }\n    if (k == 0)\
    \ {\n        return {m + m_, n + n_};\n    } else {\n        return {-1, 1};\n\
    \    }\n}\n\nvector<pair<long long, long long>> sbt_range(long long a, long long\
    \ b) {\n    vector<pair<char, int>> path = encode_path(a, b);\n    long long n\
    \ = 1;\n    long long m = 0;\n    long long n_ = 0;\n    long long m_ = 1;\n\n\
    \    if (path.empty()) return {{0, 1}, {1, 0}};\n    for (const auto [c, num]\
    \ : path) {\n        if (c == 'L') {\n            n_ += n * num;\n           \
    \ m_ += m * num;\n        } else {\n            n += n_ * num;\n            m\
    \ += m_ * num;\n        }\n    }\n    return {{m, n}, {m_, n_}};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/SternBrocotTree.hpp
  requiredBy: []
  timestamp: '2025-10-30 19:44:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/SternBrocotTree.hpp
layout: document
title: "Stern\u2013Brocot Tree"
---

## 概要

todo

## 計算量
todo