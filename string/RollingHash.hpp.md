---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
    title: verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/RollingHash.hpp\"\nclass RollingHash {\n   private:\n\
    \    int64_t n;\n    int64_t mod = (1LL << 61) - 1;\n    int64_t base = 58347;\n\
    \    vector<int64_t> invb;\n    vector<int64_t> sum;\n\n    __int128_t mod_pow(__int128_t\
    \ a, int64_t p) {\n        __int128_t res = 1;\n        while (p) {\n        \
    \    if (p & 1) res = (res * a) % mod;\n            a = (a * a) % mod;\n     \
    \       p >>= 1;\n        }\n        return res;\n    }\n\n   public:\n    RollingHash(const\
    \ string &s) {\n        __int128_t b_p = 1;\n        n = int64_t(s.size());\n\
    \        invb.resize(n + 1);\n        sum.resize(n + 1);\n\n        for (int i\
    \ = 0; i < n; i++) {\n            int64_t h_i = (b_p * int(s[i])) % mod;\n   \
    \         sum[i + 1] = (sum[i] + h_i) % mod;\n            b_p = (b_p * base) %\
    \ mod;\n        }\n        invb[n] = mod_pow(b_p, mod - 2);\n        for (int\
    \ i = n - 1; i >= 0; i--) {\n            invb[i] = (__int128_t(invb[i + 1]) *\
    \ base) % mod;\n        }\n    }\n\n    int64_t range_hash(int l, int r) {\n \
    \       return (__int128_t(sum[r] - sum[l] + mod) * invb[l]) % mod;\n    }\n};\n"
  code: "class RollingHash {\n   private:\n    int64_t n;\n    int64_t mod = (1LL\
    \ << 61) - 1;\n    int64_t base = 58347;\n    vector<int64_t> invb;\n    vector<int64_t>\
    \ sum;\n\n    __int128_t mod_pow(__int128_t a, int64_t p) {\n        __int128_t\
    \ res = 1;\n        while (p) {\n            if (p & 1) res = (res * a) % mod;\n\
    \            a = (a * a) % mod;\n            p >>= 1;\n        }\n        return\
    \ res;\n    }\n\n   public:\n    RollingHash(const string &s) {\n        __int128_t\
    \ b_p = 1;\n        n = int64_t(s.size());\n        invb.resize(n + 1);\n    \
    \    sum.resize(n + 1);\n\n        for (int i = 0; i < n; i++) {\n           \
    \ int64_t h_i = (b_p * int(s[i])) % mod;\n            sum[i + 1] = (sum[i] + h_i)\
    \ % mod;\n            b_p = (b_p * base) % mod;\n        }\n        invb[n] =\
    \ mod_pow(b_p, mod - 2);\n        for (int i = n - 1; i >= 0; i--) {\n       \
    \     invb[i] = (__int128_t(invb[i + 1]) * base) % mod;\n        }\n    }\n\n\
    \    int64_t range_hash(int l, int r) {\n        return (__int128_t(sum[r] - sum[l]\
    \ + mod) * invb[l]) % mod;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2025-09-24 16:29:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/string/ALDS1_14_B.test.cpp
documentation_of: string/RollingHash.hpp
layout: document
title: Rolling Hash
---

## 概要

todo

## 計算量
todo