---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/EnumerateDivisors.hpp
    title: Enumerate Divisors
  - icon: ':heavy_check_mark:'
    path: math/number-theory/EulersPhiFunction.hpp
    title: Euler's Phi Function
  - icon: ':heavy_check_mark:'
    path: math/number-theory/Factorize.hpp
    title: Factorize
  - icon: ':heavy_check_mark:'
    path: math/number-theory/PrimitiveRoot.hpp
    title: Primitive Root
  - icon: ':heavy_check_mark:'
    path: math/number-theory/TetrationMod.hpp
    title: Tetration Mod
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/math/number-theory/EulersPhiFunction.test.cpp
    title: verify/AizuOnlineJudge/math/number-theory/EulersPhiFunction.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/math/number-theory/ITP1_3_D.test.cpp
    title: verify/AizuOnlineJudge/math/number-theory/ITP1_3_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/Factorize.test.cpp
    title: verify/LibraryChecker/math/number-theory/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/PrimalityTest.test.cpp
    title: verify/LibraryChecker/math/number-theory/PrimalityTest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/PrimitiveRoot.test.cpp
    title: verify/LibraryChecker/math/number-theory/PrimitiveRoot.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
    title: verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/PrimalityTest.hpp\"\n__int128_t mod_pow(__int128_t\
    \ a, long long n, long long m) {\n    __int128_t res = 1;\n    a %= m;\n    while\
    \ (n) {\n        if (n & 1) res = (res * a) % m;\n        a = (a * a) % m;\n \
    \       n >>= 1;\n    }\n    return res;\n}\n\nconstexpr long long MR[] = {2,\
    \ 7, 61};\nconstexpr long long MRl[] = {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022};\n\nbool Miller_Rabin(long long n) {\n    long long s = 0;\n   \
    \ long long d = n - 1;\n    while ((d & 1) == 0) {\n        s++;\n        d >>=\
    \ 1;\n    }\n    for (int i = 0; i < 3; i++) {\n        if (n <= MR[i]) return\
    \ true;\n        __int128_t x = mod_pow(MR[i], d, n);\n        if (x != 1) {\n\
    \            bool ok = false;\n            for (int t = 0; t < s; t++) {\n   \
    \             if (x == n - 1) {\n                    ok = true;\n            \
    \        break;\n                }\n                x = x * x % n;\n         \
    \   }\n            if (!ok) return false;\n        }\n    }\n    return true;\n\
    }\n\nbool Miller_Rabinl(long long n) {\n    long long s = 0;\n    long long d\
    \ = n - 1;\n    while ((d & 1) == 0) {\n        s++;\n        d >>= 1;\n    }\n\
    \    for (int i = 0; i < 7; i++) {\n        if (n <= MRl[i]) return true;\n  \
    \      __int128_t x = mod_pow(MRl[i], d, n);\n        if (x != 1) {\n        \
    \    bool ok = false;\n            for (int t = 0; t < s; t++) {\n           \
    \     if (x == n - 1) {\n                    ok = true;\n                    break;\n\
    \                }\n                x = x * x % n;\n            }\n          \
    \  if (!ok) return false;\n        }\n    }\n    return true;\n}\n\nbool brute_force(long\
    \ long n) {\n    for (int i = 2; i * i <= n; i++) {\n        if (n % i == 0) return\
    \ false;\n    }\n    return true;\n}\n\nbool is_prime(long long n) {\n    if (n\
    \ == 2) return true;\n    if ((n & 1) == 0 or n < 2) return false;\n    if (n\
    \ < 1000) return brute_force(n);\n    if (n < 4759123141LL) {\n        return\
    \ Miller_Rabin(n);\n    }\n    return Miller_Rabinl(n);\n}\n"
  code: "__int128_t mod_pow(__int128_t a, long long n, long long m) {\n    __int128_t\
    \ res = 1;\n    a %= m;\n    while (n) {\n        if (n & 1) res = (res * a) %\
    \ m;\n        a = (a * a) % m;\n        n >>= 1;\n    }\n    return res;\n}\n\n\
    constexpr long long MR[] = {2, 7, 61};\nconstexpr long long MRl[] = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\nbool Miller_Rabin(long long n) {\n \
    \   long long s = 0;\n    long long d = n - 1;\n    while ((d & 1) == 0) {\n \
    \       s++;\n        d >>= 1;\n    }\n    for (int i = 0; i < 3; i++) {\n   \
    \     if (n <= MR[i]) return true;\n        __int128_t x = mod_pow(MR[i], d, n);\n\
    \        if (x != 1) {\n            bool ok = false;\n            for (int t =\
    \ 0; t < s; t++) {\n                if (x == n - 1) {\n                    ok\
    \ = true;\n                    break;\n                }\n                x =\
    \ x * x % n;\n            }\n            if (!ok) return false;\n        }\n \
    \   }\n    return true;\n}\n\nbool Miller_Rabinl(long long n) {\n    long long\
    \ s = 0;\n    long long d = n - 1;\n    while ((d & 1) == 0) {\n        s++;\n\
    \        d >>= 1;\n    }\n    for (int i = 0; i < 7; i++) {\n        if (n <=\
    \ MRl[i]) return true;\n        __int128_t x = mod_pow(MRl[i], d, n);\n      \
    \  if (x != 1) {\n            bool ok = false;\n            for (int t = 0; t\
    \ < s; t++) {\n                if (x == n - 1) {\n                    ok = true;\n\
    \                    break;\n                }\n                x = x * x % n;\n\
    \            }\n            if (!ok) return false;\n        }\n    }\n    return\
    \ true;\n}\n\nbool brute_force(long long n) {\n    for (int i = 2; i * i <= n;\
    \ i++) {\n        if (n % i == 0) return false;\n    }\n    return true;\n}\n\n\
    bool is_prime(long long n) {\n    if (n == 2) return true;\n    if ((n & 1) ==\
    \ 0 or n < 2) return false;\n    if (n < 1000) return brute_force(n);\n    if\
    \ (n < 4759123141LL) {\n        return Miller_Rabin(n);\n    }\n    return Miller_Rabinl(n);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/PrimalityTest.hpp
  requiredBy:
  - math/number-theory/EnumerateDivisors.hpp
  - math/number-theory/TetrationMod.hpp
  - math/number-theory/EulersPhiFunction.hpp
  - math/number-theory/Factorize.hpp
  - math/number-theory/PrimitiveRoot.hpp
  timestamp: '2025-05-15 03:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/math/number-theory/ITP1_3_D.test.cpp
  - verify/AizuOnlineJudge/math/number-theory/EulersPhiFunction.test.cpp
  - verify/LibraryChecker/math/number-theory/PrimitiveRoot.test.cpp
  - verify/LibraryChecker/math/number-theory/PrimalityTest.test.cpp
  - verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
  - verify/LibraryChecker/math/number-theory/Factorize.test.cpp
documentation_of: math/number-theory/PrimalityTest.hpp
layout: document
title: Primality Test
---

## 概要

todo

## 計算量
todo