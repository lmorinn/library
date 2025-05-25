---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/number-theory/SumofMultiplicativeFunction.test.cpp
    title: verify/LibraryChecker/math/number-theory/SumofMultiplicativeFunction.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number-theory/SumofMultiplicativeFunction.hpp\"\nint\
    \ sum_of_multiplicative(long long n, long long a, long long b, int mod = 469762049)\
    \ {\n  modint::set_mod(mod);\n  if (n == 0) return 0;\n  long long sq = sqrtl(n);\n\
    \  vector<long long> d(sq * 2 + 1);\n  long long siz = d.size();\n  vector<modint>\
    \ dp(siz), dps(siz);\n  vector<long long> prime;\n  for (long long s = 1; s <=\
    \ sq; s++) d[s] = n / s;\n  for (long long s = 1; s <= sq; s++) d[siz - s] = s;\n\
    \  for (int i = 1; i < siz; i++) {\n    dp[i] = d[i] - 1;\n    dps[i] = (modint(d[i])\
    \ * (d[i] + 1)) / 2 - 1;\n  }\n\n  for (long long p = 2; p <= sq; p++) {\n   \
    \ long long p2 = p * p;\n    if (dp[siz - p + 1] == dp[siz - p]) continue;\n \
    \   prime.emplace_back(p);\n    for (int i = 1; i < siz; i++) {\n      if (d[i]\
    \ < p2) break;\n      long long prev = d[i] / p;\n      if (prev > sq) {\n   \
    \     dp[i] -= dp[n / prev] - dp[siz - p + 1];\n        dps[i] -= p * (dps[n /\
    \ prev] - dps[siz - p + 1]);\n      } else {\n        dp[i] -= dp[siz - prev]\
    \ - dp[siz - p + 1];\n        dps[i] -= p * (dps[siz - prev] - dps[siz - p + 1]);\n\
    \      }\n    }\n  }\n  for (int i = 0; i < siz; i++) {\n    dps[i] *= b;\n  \
    \  dps[i] += dp[i] * a + 1;\n  }\n  modint ans = dps[1];\n\n  auto dfs = [&](auto\
    \ &&self, long long p, long long cur, long long parent, modint bf, modint f, int\
    \ idx) -> void {\n    long long gpf = cur / parent;\n    if (cur * p <= n) {\n\
    \      long long id1 = n / cur;\n      ans += f * (dps[id1 > sq ? n / id1 : siz\
    \ - id1] - dps[(gpf > sq ? n / gpf : siz - gpf)]);\n      ans += f + a * bf;\n\
    \      self(self, p, cur * p, cur, bf, f + a * bf, idx);\n    }\n    for (int\
    \ j = idx + 1; j < prime.size() and __int128_t(cur) * prime[j] * prime[j] <= n;\
    \ j++) {\n      self(self, prime[j], cur * prime[j], cur, f, (prime[j] * b + a)\
    \ * f, j);\n    }\n  };\n  for (int i = 0; i < prime.size() and __int128_t(prime[i])\
    \ * prime[i] <= n; i++) {\n    dfs(dfs, prime[i], prime[i], 1, 1, prime[i] * b\
    \ + a, i);\n  }\n  return ans.val();\n}\n"
  code: "int sum_of_multiplicative(long long n, long long a, long long b, int mod\
    \ = 469762049) {\n  modint::set_mod(mod);\n  if (n == 0) return 0;\n  long long\
    \ sq = sqrtl(n);\n  vector<long long> d(sq * 2 + 1);\n  long long siz = d.size();\n\
    \  vector<modint> dp(siz), dps(siz);\n  vector<long long> prime;\n  for (long\
    \ long s = 1; s <= sq; s++) d[s] = n / s;\n  for (long long s = 1; s <= sq; s++)\
    \ d[siz - s] = s;\n  for (int i = 1; i < siz; i++) {\n    dp[i] = d[i] - 1;\n\
    \    dps[i] = (modint(d[i]) * (d[i] + 1)) / 2 - 1;\n  }\n\n  for (long long p\
    \ = 2; p <= sq; p++) {\n    long long p2 = p * p;\n    if (dp[siz - p + 1] ==\
    \ dp[siz - p]) continue;\n    prime.emplace_back(p);\n    for (int i = 1; i <\
    \ siz; i++) {\n      if (d[i] < p2) break;\n      long long prev = d[i] / p;\n\
    \      if (prev > sq) {\n        dp[i] -= dp[n / prev] - dp[siz - p + 1];\n  \
    \      dps[i] -= p * (dps[n / prev] - dps[siz - p + 1]);\n      } else {\n   \
    \     dp[i] -= dp[siz - prev] - dp[siz - p + 1];\n        dps[i] -= p * (dps[siz\
    \ - prev] - dps[siz - p + 1]);\n      }\n    }\n  }\n  for (int i = 0; i < siz;\
    \ i++) {\n    dps[i] *= b;\n    dps[i] += dp[i] * a + 1;\n  }\n  modint ans =\
    \ dps[1];\n\n  auto dfs = [&](auto &&self, long long p, long long cur, long long\
    \ parent, modint bf, modint f, int idx) -> void {\n    long long gpf = cur / parent;\n\
    \    if (cur * p <= n) {\n      long long id1 = n / cur;\n      ans += f * (dps[id1\
    \ > sq ? n / id1 : siz - id1] - dps[(gpf > sq ? n / gpf : siz - gpf)]);\n    \
    \  ans += f + a * bf;\n      self(self, p, cur * p, cur, bf, f + a * bf, idx);\n\
    \    }\n    for (int j = idx + 1; j < prime.size() and __int128_t(cur) * prime[j]\
    \ * prime[j] <= n; j++) {\n      self(self, prime[j], cur * prime[j], cur, f,\
    \ (prime[j] * b + a) * f, j);\n    }\n  };\n  for (int i = 0; i < prime.size()\
    \ and __int128_t(prime[i]) * prime[i] <= n; i++) {\n    dfs(dfs, prime[i], prime[i],\
    \ 1, 1, prime[i] * b + a, i);\n  }\n  return ans.val();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/SumofMultiplicativeFunction.hpp
  requiredBy: []
  timestamp: '2025-05-24 20:50:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/number-theory/SumofMultiplicativeFunction.test.cpp
documentation_of: math/number-theory/SumofMultiplicativeFunction.hpp
layout: document
title: Sum of Multiplicative Function
---

## 概要

todo

## 計算量
todo