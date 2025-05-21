---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/EulersPhiFunction.hpp
    title: Euler's Phi Function
  - icon: ':heavy_check_mark:'
    path: math/number-theory/Factorize.hpp
    title: Factorize
  - icon: ':heavy_check_mark:'
    path: math/number-theory/PrimalityTest.hpp
    title: Primality Test
  - icon: ':heavy_check_mark:'
    path: math/number-theory/TetrationMod.hpp
    title: Tetration Mod
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
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
    links:
    - https://judge.yosupo.jp/problem/tetration_mod
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n#line 1 \"\
    math/number-theory/PrimalityTest.hpp\"\n__int128_t mod_pow(__int128_t a, long\
    \ long n, long long m) {\n    __int128_t res = 1;\n    a %= m;\n    while (n)\
    \ {\n        if (n & 1) res = (res * a) % m;\n        a = (a * a) % m;\n     \
    \   n >>= 1;\n    }\n    return res;\n}\n\nconstexpr long long MR[] = {2, 7, 61};\n\
    constexpr long long MRl[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \nbool Miller_Rabin(long long n) {\n    long long s = 0;\n    long long d = n\
    \ - 1;\n    while ((d & 1) == 0) {\n        s++;\n        d >>= 1;\n    }\n  \
    \  for (int i = 0; i < 3; i++) {\n        if (n <= MR[i]) return true;\n     \
    \   __int128_t x = mod_pow(MR[i], d, n);\n        if (x != 1) {\n            bool\
    \ ok = false;\n            for (int t = 0; t < s; t++) {\n                if (x\
    \ == n - 1) {\n                    ok = true;\n                    break;\n  \
    \              }\n                x = x * x % n;\n            }\n            if\
    \ (!ok) return false;\n        }\n    }\n    return true;\n}\n\nbool Miller_Rabinl(long\
    \ long n) {\n    long long s = 0;\n    long long d = n - 1;\n    while ((d & 1)\
    \ == 0) {\n        s++;\n        d >>= 1;\n    }\n    for (int i = 0; i < 7; i++)\
    \ {\n        if (n <= MRl[i]) return true;\n        __int128_t x = mod_pow(MRl[i],\
    \ d, n);\n        if (x != 1) {\n            bool ok = false;\n            for\
    \ (int t = 0; t < s; t++) {\n                if (x == n - 1) {\n             \
    \       ok = true;\n                    break;\n                }\n          \
    \      x = x * x % n;\n            }\n            if (!ok) return false;\n   \
    \     }\n    }\n    return true;\n}\n\nbool brute_force(long long n) {\n    for\
    \ (int i = 2; i * i <= n; i++) {\n        if (n % i == 0) return false;\n    }\n\
    \    return true;\n}\n\nbool is_prime(long long n) {\n    if (n == 2) return true;\n\
    \    if ((n & 1) == 0 or n < 2) return false;\n    if (n < 1000) return brute_force(n);\n\
    \    if (n < 4759123141LL) {\n        return Miller_Rabin(n);\n    }\n    return\
    \ Miller_Rabinl(n);\n}\n#line 2 \"math/number-theory/Factorize.hpp\"\n\nlong long\
    \ find_prime_factor(long long n) {\n  if ((n & 1) == 0) return 2;\n  long long\
    \ m = int64_t(powl(n, 0.125)) + 1;\n  for (int i = 1; i < n; i++) {\n    long\
    \ long y = 0;\n    long long g = 1;\n    long long q = 1;\n    long long r = 1;\n\
    \    long long k = 0;\n    long long ys = 0;\n    long long x = 0;\n    while\
    \ (g == 1) {\n      x = y;\n      while (k < 3ll * r / 4) {\n        y = (__int128_t(y)\
    \ * y + i) % n;\n        k++;\n      }\n      while (k < r and g == 1) {\n   \
    \     ys = y;\n        for (int j = 0; j < min(m, r - k); j++) {\n          y\
    \ = (__int128_t(y) * y + i) % n;\n          q = (__int128_t(q) * abs(x - y)) %\
    \ n;\n        }\n        g = gcd(q, n);\n        k += m;\n      }\n      k = r;\n\
    \      r <<= 1;\n    }\n    if (g == n) {\n      g = 1;\n      y = ys;\n     \
    \ while (g == 1) {\n        y = (__int128_t(y) * y + i) % n;\n        g = gcd(abs(x\
    \ - y), n);\n      }\n    }\n    if (g == n) continue;\n    if (is_prime(g)) return\
    \ g;\n    if (is_prime(n / g)) return n / g;\n    return find_prime_factor(g);\n\
    \  }\n  return -1;\n}\n\nvector<long long> factorize(long long n, bool set = false)\
    \ {\n  vector<long long> res;\n  while (!is_prime(n) and n > 1) {\n    long long\
    \ p = find_prime_factor(n);\n    if (set) res.emplace_back(p);\n    while (n %\
    \ p == 0) {\n      n /= p;\n      if (!set) res.emplace_back(p);\n    }\n  }\n\
    \  if (n > 1) {\n    res.emplace_back(n);\n  }\n  sort(res.begin(), res.end());\n\
    \  return res;\n}\n#line 2 \"math/number-theory/EulersPhiFunction.hpp\"\n\nlong\
    \ long Eulers_phi_function(long long n) {\n  __uint128_t upper = n;\n  __uint128_t\
    \ lower = 1;\n  for (const long long p : factorize(n, true)) {\n    upper *= (p\
    \ - 1);\n    lower *= p;\n  }\n  return upper / lower;\n}\n#line 2 \"math/number-theory/TetrationMod.hpp\"\
    \n\nlong long tetration_mod(long long a, long long b, long long m) {\n  if (m\
    \ == 1) return 0;\n  if (a == 0) return ((b & 1) == 0);\n  if (b == 0) return\
    \ 1;\n  if (b == 1) return a % m;\n  if (b == 2) return mod_pow(a, a, m);\n  long\
    \ long phi = Eulers_phi_function(m);\n  long long power = tetration_mod(a, b -\
    \ 1, phi);\n  return mod_pow(a, (power == 0 ? phi : power), m);\n}\n#line 4 \"\
    verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp\"\n\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  int t;\n  in(t);\n  rep(i, t) {\n  \
    \  long long a, b, m;\n    in(a, b, m);\n    out(tetration_mod(a, b, m));\n  }\n\
    }\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\
    \n#include \"../../../../math/number-theory/TetrationMod.hpp\"\n\nint main() {\n\
    \  cin.tie(0)->sync_with_stdio(0);\n  int t;\n  in(t);\n  rep(i, t) {\n    long\
    \ long a, b, m;\n    in(a, b, m);\n    out(tetration_mod(a, b, m));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - math/number-theory/TetrationMod.hpp
  - math/number-theory/EulersPhiFunction.hpp
  - math/number-theory/Factorize.hpp
  - math/number-theory/PrimalityTest.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
  requiredBy: []
  timestamp: '2025-05-21 17:36:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
- /verify/verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp.html
title: verify/LibraryChecker/math/number-theory/TetrationMod.test.cpp
---
