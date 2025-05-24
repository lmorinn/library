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
  bundledCode: "#line 1 \"math/number-theory/SumofEulersPhiFunction.hpp\"\nint sum_of_totient(long\
    \ long n) {\n  if (n == 0) return 0;\n  long long sq = sqrtl(n);\n  vector<long\
    \ long> d(sq * 2 + 1);\n  long long siz = d.size();\n  vector<modint998244353>\
    \ dp(siz), dps(siz);\n  vector<long long> prime;\n  for (long long s = 1; s <=\
    \ sq; s++) d[s] = n / s;\n  for (long long s = 1; s <= sq; s++) d[siz - s] = s;\n\
    \  for (int i = 1; i < siz; i++) {\n    dp[i] = d[i] - 1;\n    dps[i] = (modint998244353(d[i])\
    \ * (d[i] + 1)) / 2 - 1;\n  }\n\n  for (long long p = 2; p <= sq; p++) {\n   \
    \ long long p2 = p * p;\n    if (dp[siz - p + 1] == dp[siz - p]) continue;\n \
    \   prime.emplace_back(p);\n    for (int i = 1; i < siz; i++) {\n      if (d[i]\
    \ < p2) break;\n      long long prev = d[i] / p;\n      if (prev > sq) {\n   \
    \     dp[i] -= dp[n / prev] - dp[siz - p + 1];\n        dps[i] -= p * (dps[n /\
    \ prev] - dps[siz - p + 1]);\n      } else {\n        dp[i] -= dp[siz - prev]\
    \ - dp[siz - p + 1];\n        dps[i] -= p * (dps[siz - prev] - dps[siz - p + 1]);\n\
    \      }\n    }\n  }\n\n  modint998244353 ans = dps[1] - dp[1] + 1;\n  for (int\
    \ i = 0; i < siz; i++) dps[i] -= dp[i];\n\n  auto dfs = [&](auto &&self, long\
    \ long p, long long cur, long long parent, modint998244353 f, int idx) -> void\
    \ {\n    long long gpf = cur / parent;\n    if (cur * p <= n) {\n      long long\
    \ id1 = n / cur;\n      ans += f * (p + dps[id1 > sq ? n / id1 : siz - id1] -\
    \ dps[(gpf > sq ? n / gpf : siz - gpf)]);\n      self(self, p, cur * p, cur, f\
    \ * p, idx);\n    }\n    for (int j = idx + 1; j < prime.size() and __int128_t(cur)\
    \ * prime[j] * prime[j] <= n; j++) {\n      self(self, prime[j], cur * prime[j],\
    \ cur, f * (prime[j] - 1), j);\n    }\n  };\n  for (int i = 0; i < prime.size()\
    \ and __int128_t(prime[i]) * prime[i] <= n; i++) {\n    dfs(dfs, prime[i], prime[i],\
    \ 1, prime[i] - 1, i);\n  }\n  return ans.val();\n}\n"
  code: "int sum_of_totient(long long n) {\n  if (n == 0) return 0;\n  long long sq\
    \ = sqrtl(n);\n  vector<long long> d(sq * 2 + 1);\n  long long siz = d.size();\n\
    \  vector<modint998244353> dp(siz), dps(siz);\n  vector<long long> prime;\n  for\
    \ (long long s = 1; s <= sq; s++) d[s] = n / s;\n  for (long long s = 1; s <=\
    \ sq; s++) d[siz - s] = s;\n  for (int i = 1; i < siz; i++) {\n    dp[i] = d[i]\
    \ - 1;\n    dps[i] = (modint998244353(d[i]) * (d[i] + 1)) / 2 - 1;\n  }\n\n  for\
    \ (long long p = 2; p <= sq; p++) {\n    long long p2 = p * p;\n    if (dp[siz\
    \ - p + 1] == dp[siz - p]) continue;\n    prime.emplace_back(p);\n    for (int\
    \ i = 1; i < siz; i++) {\n      if (d[i] < p2) break;\n      long long prev =\
    \ d[i] / p;\n      if (prev > sq) {\n        dp[i] -= dp[n / prev] - dp[siz -\
    \ p + 1];\n        dps[i] -= p * (dps[n / prev] - dps[siz - p + 1]);\n      }\
    \ else {\n        dp[i] -= dp[siz - prev] - dp[siz - p + 1];\n        dps[i] -=\
    \ p * (dps[siz - prev] - dps[siz - p + 1]);\n      }\n    }\n  }\n\n  modint998244353\
    \ ans = dps[1] - dp[1] + 1;\n  for (int i = 0; i < siz; i++) dps[i] -= dp[i];\n\
    \n  auto dfs = [&](auto &&self, long long p, long long cur, long long parent,\
    \ modint998244353 f, int idx) -> void {\n    long long gpf = cur / parent;\n \
    \   if (cur * p <= n) {\n      long long id1 = n / cur;\n      ans += f * (p +\
    \ dps[id1 > sq ? n / id1 : siz - id1] - dps[(gpf > sq ? n / gpf : siz - gpf)]);\n\
    \      self(self, p, cur * p, cur, f * p, idx);\n    }\n    for (int j = idx +\
    \ 1; j < prime.size() and __int128_t(cur) * prime[j] * prime[j] <= n; j++) {\n\
    \      self(self, prime[j], cur * prime[j], cur, f * (prime[j] - 1), j);\n   \
    \ }\n  };\n  for (int i = 0; i < prime.size() and __int128_t(prime[i]) * prime[i]\
    \ <= n; i++) {\n    dfs(dfs, prime[i], prime[i], 1, prime[i] - 1, i);\n  }\n \
    \ return ans.val();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/SumofEulersPhiFunction.hpp
  requiredBy: []
  timestamp: '2025-05-24 20:50:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/SumofEulersPhiFunction.hpp
layout: document
title: Sum of Eulers Phi Function
---

## 概要

todo

## 計算量
todo