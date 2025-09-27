---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/Factorize.hpp
    title: Factorize
  - icon: ':heavy_check_mark:'
    path: math/number-theory/PrimalityTest.hpp
    title: Primality Test
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/math/number-theory/ITP1_3_D.test.cpp
    title: verify/AizuOnlineJudge/math/number-theory/ITP1_3_D.test.cpp
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
    \ Miller_Rabin(n);\n    }\n    return Miller_Rabinl(n);\n}\n#line 2 \"math/number-theory/Factorize.hpp\"\
    \n\nlong long find_prime_factor(long long n) {\n  if ((n & 1) == 0) return 2;\n\
    \  long long m = int64_t(powl(n, 0.125)) + 1;\n  for (int i = 1; i < n; i++) {\n\
    \    long long y = 0;\n    long long g = 1;\n    long long q = 1;\n    long long\
    \ r = 1;\n    long long k = 0;\n    long long ys = 0;\n    long long x = 0;\n\
    \    while (g == 1) {\n      x = y;\n      while (k < 3ll * r / 4) {\n       \
    \ y = (__int128_t(y) * y + i) % n;\n        k++;\n      }\n      while (k < r\
    \ and g == 1) {\n        ys = y;\n        for (int j = 0; j < min(m, r - k); j++)\
    \ {\n          y = (__int128_t(y) * y + i) % n;\n          q = (__int128_t(q)\
    \ * abs(x - y)) % n;\n        }\n        g = gcd(q, n);\n        k += m;\n   \
    \   }\n      k = r;\n      r <<= 1;\n    }\n    if (g == n) {\n      g = 1;\n\
    \      y = ys;\n      while (g == 1) {\n        y = (__int128_t(y) * y + i) %\
    \ n;\n        g = gcd(abs(x - y), n);\n      }\n    }\n    if (g == n) continue;\n\
    \    if (is_prime(g)) return g;\n    if (is_prime(n / g)) return n / g;\n    return\
    \ find_prime_factor(g);\n  }\n  return -1;\n}\n\nvector<long long> factorize(long\
    \ long n, bool set = false) {\n  vector<long long> res;\n  while (!is_prime(n)\
    \ and n > 1) {\n    long long p = find_prime_factor(n);\n    if (set) res.emplace_back(p);\n\
    \    while (n % p == 0) {\n      n /= p;\n      if (!set) res.emplace_back(p);\n\
    \    }\n  }\n  if (n > 1) {\n    res.emplace_back(n);\n  }\n  sort(res.begin(),\
    \ res.end());\n  return res;\n}\n#line 2 \"math/number-theory/EnumerateDivisors.hpp\"\
    \n\nvector<long long> enumerate_divisors(long long n, bool sorted_result = false)\
    \ {\n  vector<long long> res = {1};\n  long long before = -1;\n  long long mul;\n\
    \  int siz_before = 1;\n  for (const long long p : factorize(n)) {\n    mul =\
    \ (p == before ? mul * p : p);\n    int siz = (p == before ? siz_before : int(res.size()));\n\
    \    for (int i = 0; i < siz; i++) {\n      res.emplace_back(res[i] * mul);\n\
    \    }\n    before = p;\n    siz_before = siz;\n  }\n  if (sorted_result) sort(res.begin(),\
    \ res.end());\n  return res;\n}\n"
  code: "#include \"Factorize.hpp\"\n\nvector<long long> enumerate_divisors(long long\
    \ n, bool sorted_result = false) {\n  vector<long long> res = {1};\n  long long\
    \ before = -1;\n  long long mul;\n  int siz_before = 1;\n  for (const long long\
    \ p : factorize(n)) {\n    mul = (p == before ? mul * p : p);\n    int siz = (p\
    \ == before ? siz_before : int(res.size()));\n    for (int i = 0; i < siz; i++)\
    \ {\n      res.emplace_back(res[i] * mul);\n    }\n    before = p;\n    siz_before\
    \ = siz;\n  }\n  if (sorted_result) sort(res.begin(), res.end());\n  return res;\n\
    }"
  dependsOn:
  - math/number-theory/Factorize.hpp
  - math/number-theory/PrimalityTest.hpp
  isVerificationFile: false
  path: math/number-theory/EnumerateDivisors.hpp
  requiredBy: []
  timestamp: '2025-05-20 03:07:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/math/number-theory/ITP1_3_D.test.cpp
documentation_of: math/number-theory/EnumerateDivisors.hpp
layout: document
title: Enumerate Divisors
---

## 概要

todo

## 計算量
todo