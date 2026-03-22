---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':question:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':question:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: dp/DeterministicFiniteAutomatonDP.hpp
    title: Deterministic Finite Automaton DP
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2879
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2879
  bundledCode: "#line 1 \"atcoder/modint.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <numeric>\n#include <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\n#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n\
    #ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long\
    \ safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\n// Fast modular multiplication by barrett reduction\n// Reference:\
    \ https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider after Ice\
    \ Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n\
    \    // @param m `1 <= m`\n    explicit barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n\n    // @return m\n    unsigned int umod() const\
    \ { return _m; }\n\n    // @param a `0 <= a < m`\n    // @param b `0 <= b < m`\n\
    \    // @return `a * b % m`\n    unsigned int mul(unsigned int a, unsigned int\
    \ b) const {\n        // [1] m = 1\n        // a = b = im = 0, so okay\n\n   \
    \     // [2] m >= 2\n        // im = ceil(2^64 / m)\n        // -> im * m = 2^64\
    \ + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <= c, d < m)\n       \
    \ // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im\n     \
    \   // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) <\
    \ 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n        unsigned long\
    \ long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned long long x;\n\
    \        _umul128(z, im, &x);\n#else\n        unsigned long long x =\n       \
    \     (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n#endif\n     \
    \   unsigned long long y = x * _m;\n        return (unsigned int)(z - y + (z <\
    \ y ? _m : 0));\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1 <= m`\n// @return\
    \ `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long long x, long long\
    \ n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n\
    \    unsigned long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n \
    \   while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n\
    \        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n// M. Forisek and\
    \ J. Jancina,\n// Fast Primality Testing for Integers That Fit into a Machine\
    \ Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int n) {\n   \
    \ if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return true;\n\
    \    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while (d % 2\
    \ == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for (long\
    \ long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 2 \"verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp\"\
    \nusing namespace atcoder;\n#line 2 \"template/template.hpp\"\n#pragma region\
    \ Macros\n#include <bits/stdc++.h>\nusing namespace std;\nusing lint = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n\
    #define all(x) (x).begin(), (x).end()\n#define uniqv(v) v.erase(unique(all(v)),\
    \ v.end())\n#define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP1(i,\
    \ n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))\n#define REP2(i,\
    \ l, r) for (auto i = (l); (i) != (r); ++(i))\n#define rep(...) OVERLOAD_REP(__VA_ARGS__,\
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 4 \"verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2879\"\n#line 1\
    \ \"dp/DeterministicFiniteAutomatonDP.hpp\"\n\nenum class Ordering { Less,\n \
    \                     Equal,\n                      Greater };\n\nnamespace std\
    \ {\ntemplate <>\nstruct hash<Ordering> {\n    std::size_t operator()(const Ordering&\
    \ o) const {\n        return std::hash<int>()(static_cast<int>(o));\n    }\n};\n\
    template <typename T1, typename T2>\nstruct hash<pair<T1, T2>> {\n    std::size_t\
    \ operator()(const pair<T1, T2>& p) const {\n        return std::hash<T1>()(p.first)\
    \ * 31 + std::hash<T2>()(p.second);\n    }\n};\n\n}  // namespace std\n\nstruct\
    \ TupleHash {\n    size_t operator()(const std::tuple<int, int, int>& t) const\
    \ {\n        auto [x, y, z] = t;\n        return std::hash<int>()(x) ^ (std::hash<int>()(y)\
    \ << 1) ^ (std::hash<int>()(z) << 2);\n    }\n};\n\ntemplate <typename X>\nclass\
    \ Dfa {\n   public:\n    using Alphabet = typename X::Alphabet;\n    using State\
    \ = typename X::State;\n\n    Dfa(const X& x) : x_(x) {}\n\n    State init() const\
    \ { return x_.init(); }\n\n    State next(const State& s, const Alphabet& a, size_t\
    \ i) const {\n        return x_.next(s, a, i);\n    }\n\n    bool accept(const\
    \ State& s) const {\n        return x_.accept(s);\n    }\n\n    bool successful(const\
    \ State& s) const {\n        return x_.successful(s);\n    }\n\n    bool unsuccessful(const\
    \ State& s) const {\n        return x_.unsuccessful(s);\n    }\n\n   private:\n\
    \    X x_;\n};\n\ntemplate <typename X, typename Y>\nclass AndDfa {\n   public:\n\
    \    using Alphabet = typename X::Alphabet;\n    using State = pair<typename X::State,\
    \ typename Y::State>;\n\n    AndDfa(const X& x, const Y& y) : x_(x), y_(y) {}\n\
    \n    State init() const { return make_pair(x_.init(), y_.init()); }\n\n    State\
    \ next(const State& s, const Alphabet& a, size_t i) const {\n        return make_pair(x_.next(s.first,\
    \ a, i), y_.next(s.second, a, i));\n    }\n\n    bool accept(const State& s) const\
    \ {\n        return x_.accept(s.first) and y_.accept(s.second);\n    }\n\n   \
    \ bool successful(const State& s) const {\n        return x_.successful(s.first)\
    \ and y_.successful(s.second);\n    }\n\n    bool unsuccessful(const State& s)\
    \ const {\n        return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);\n\
    \    }\n\n   private:\n    X x_;\n    Y y_;\n};\n\ntemplate <typename X, typename\
    \ Y>\nclass OrDfa {\n   public:\n    using Alphabet = typename X::Alphabet;\n\
    \    using State = pair<typename X::State, typename Y::State>;\n\n    OrDfa(const\
    \ X& x, const Y& y) : x_(x), y_(y) {}\n\n    State init() const { return make_pair(x_.init(),\
    \ y_.init()); }\n\n    State next(const State& s, const Alphabet& a, size_t i)\
    \ const {\n        return make_pair(x_.next(s.first, a, i), y_.next(s.second,\
    \ a, i));\n    }\n\n    bool accept(const State& s) const {\n        return x_.accept(s.first)\
    \ or y_.accept(s.second);\n    }\n\n    bool successful(const State& s) const\
    \ {\n        return x_.successful(s.first) or y_.successful(s.second);\n    }\n\
    \n    bool unsuccessful(const State& s) const {\n        return x_.unsuccessful(s.first)\
    \ and y_.unsuccessful(s.second);\n    }\n\n   private:\n    X x_;\n    Y y_;\n\
    };\n\ntemplate <typename X>\nclass NotDfa {\n   public:\n    using Alphabet =\
    \ typename X::Alphabet;\n    using State = typename X::State;\n\n    NotDfa(const\
    \ X& x) : x_(x) {}\n\n    State init() const { return x_.init(); }\n\n    State\
    \ next(const State& s, const Alphabet& a, size_t i) const {\n        return x_.next(s,\
    \ a, i);\n    }\n\n    bool accept(const State& s) const {\n        return !x_.accept(s);\n\
    \    }\n\n    bool successful(const State& s) const {\n        return !x_.successful(s);\n\
    \    }\n\n    bool unsuccessful(const State& s) const {\n        return !x_.unsuccessful(s);\n\
    \    }\n\n   private:\n    X x_;\n};\n\ntemplate <typename X, typename Y>\nclass\
    \ ProdDfa {\n   public:\n    using Alphabet = pair<typename X::Alphabet, typename\
    \ Y::Alphabet>;\n    using State = pair<typename X::State, typename Y::State>;\n\
    \n    ProdDfa(const X& x, const Y& y) : x_(x), y_(y) {}\n\n    State init() const\
    \ { return make_pair(x_.init(), y_.init()); }\n\n    State next(const State& s,\
    \ const Alphabet& a, size_t i) const {\n        return make_pair(x_.next(s.first,\
    \ a.first, i), y_.next(s.second, a.second, i));\n    }\n\n    bool accept(const\
    \ State& s) const {\n        return x_.accept(s.first) and y_.accept(s.second);\n\
    \    }\n\n    bool successful(const State& s) const {\n        return x_.successful(s.first)\
    \ and y_.successful(s.second);\n    }\n\n    bool unsuccessful(const State& s)\
    \ const {\n        return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);\n\
    \    }\n\n   private:\n    X x_;\n    Y y_;\n};\n\n// 0\u4EE5\u4E0AN\u4EE5\u4E0B\
    \u306E\u6574\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass Leq {\n   public:\n\
    \    using Alphabet = char;\n    using State = Ordering;\n\n    Leq(const string&\
    \ n) : digits_(n.begin(), n.end()) {}\n\n    State init() const {\n        return\
    \ State::Equal;\n    }\n\n    State next(State s, const Alphabet& a, size_t i)\
    \ const {\n        if (s == State::Greater) {\n            return State::Greater;\n\
    \        }\n\n        if (s == State::Less) {\n            return State::Less;\n\
    \        }\n\n        if (a < digits_[i]) {\n            return State::Less;\n\
    \        }\n\n        if (a == digits_[i]) {\n            return State::Equal;\n\
    \        }\n\n        return State::Greater;\n    }\n\n    bool accept(State s)\
    \ const {\n        return s != State::Greater;\n    }\n\n    bool successful(State\
    \ s) const {\n        return s == State::Less;\n    }\n\n    bool unsuccessful(State\
    \ s) const {\n        return s == State::Greater;\n    }\n\n   private:\n    vector<char>\
    \ digits_;\n};\n\n// 0\u4EE5\u4E0AN\u672A\u6E80\u306E\u6574\u6570\u3092\u53D7\u7406\
    \u3059\u308BDFA\nclass Le {\n   public:\n    using Alphabet = char;\n    using\
    \ State = Ordering;\n\n    Le(const string& n) : digits_(n.begin(), n.end()) {}\n\
    \n    State init() const {\n        return State::Equal;\n    }\n\n    State next(State\
    \ s, const Alphabet& a, size_t i) const {\n        if (s == State::Greater) {\n\
    \            return State::Greater;\n        }\n\n        if (s == State::Less)\
    \ {\n            return State::Less;\n        }\n\n        if (a < digits_[i])\
    \ {\n            return State::Less;\n        }\n\n        if (a == digits_[i])\
    \ {\n            return State::Equal;\n        }\n\n        return State::Greater;\n\
    \    }\n\n    bool accept(State s) const {\n        return s == State::Less;\n\
    \    }\n\n    bool successful(State s) const {\n        return s == State::Less;\n\
    \    }\n\n    bool unsuccessful(State s) const {\n        return s == State::Greater;\n\
    \    }\n\n   private:\n    vector<char> digits_;\n};\n\n// M\u306E\u500D\u6570\
    \u3092\u53D7\u7406\u3059\u308BDFA\nclass MultipleOf {\n   public:\n    using Alphabet\
    \ = char;\n    using State = int;\n\n    MultipleOf(int m, int base = 10) : m_(m),\
    \ base_(base) {}\n\n    State init() const {\n        return 0;\n    }\n\n   \
    \ State next(State s, const Alphabet& a, size_t i) const {\n        return (s\
    \ * base_ + (a - '0')) % m_;\n    }\n\n    bool accept(State s) const {\n    \
    \    return s == 0;\n    }\n\n    bool successful(State s) const {\n        return\
    \ 0;\n    }\n\n    bool unsuccessful(State s) const {\n        return 0;\n   \
    \ }\n\n   private:\n    int base_;\n    int m_;\n};\n\n// popcount\u304C\u3061\
    \u3087\u3046\u3069K\u306E\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass PopcountOf\
    \ {\n   public:\n    using Alphabet = char;\n    using State = int;\n\n    PopcountOf(int\
    \ k) : k_(k) {}\n\n    State init() const {\n        return 0;\n    }\n\n    State\
    \ next(State s, const Alphabet& a, size_t i) const {\n        return s + (a -\
    \ '0');\n    }\n\n    bool accept(State s) const {\n        return s == k_;\n\
    \    }\n\n    bool successful(State s) const {\n        return 0;\n    }\n\n \
    \   bool unsuccessful(State s) const {\n        return s > k_;\n    }\n\n   private:\n\
    \    int k_;\n};\n\n// \u6841\u548C\u304CM\u306E\u500D\u6570\u3068\u306A\u308B\
    \u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass DigitSumMultipleOf {\n   public:\n\
    \    using Alphabet = char;\n    using State = int;\n\n    DigitSumMultipleOf(int\
    \ m) : m_(m) {}\n\n    State init() const {\n        return 0;\n    }\n\n    State\
    \ next(State s, const Alphabet& a, size_t i) const {\n        return (s + (a -\
    \ '0')) % m_;\n    }\n\n    bool accept(State s) const {\n        return s ==\
    \ 0;\n    }\n\n    bool successful(State s) const {\n        return 0;\n    }\n\
    \n    bool unsuccessful(State s) const {\n        return 0;\n    }\n\n   private:\n\
    \    int m_;\n};\n\n// \u6841\u540C\u58EB\u306E\u7A4D\u304CM\u306E\u500D\u6570\
    \u3068\u306A\u308B\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass DigitProdMultipleOf\
    \ {\n   public:\n    using Alphabet = char;\n    using State = int;\n\n    DigitProdMultipleOf(int\
    \ m) : m_(m) {}\n\n    State init() const {\n        return -1;\n    }\n\n   \
    \ State next(State s, const Alphabet& a, size_t i) const {\n        if (s == -1\
    \ and a == '0') {\n            return -1;\n        }\n        if (s == -1 and\
    \ a != '0') {\n            return a - '0';\n        }\n        return (s * (a\
    \ - '0')) % m_;\n    }\n\n    bool accept(State s) const {\n        return s ==\
    \ 0;\n    }\n\n    bool successful(State s) const {\n        return s == 0;\n\
    \    }\n\n    bool unsuccessful(State s) const {\n        return 0;\n    }\n\n\
    \   private:\n    int m_;\n};\n\nclass LeadingZero {\n   public:\n    using Alphabet\
    \ = char;\n    using State = bool;\n\n    LeadingZero() {}\n\n    State init()\
    \ const {\n        return true;\n    }\n\n    State next(State s, const Alphabet&\
    \ a, size_t i) const {\n        return s and a == '0';\n    }\n\n    bool accept(State\
    \ s) const {\n        return !s;\n    }\n\n    bool successful(State s) const\
    \ {\n        return !s;\n    }\n\n    bool unsuccessful(State s) const {\n   \
    \     return 0;\n    }\n};\n\ntemplate <typename DFA>\nlong long count_dfa(const\
    \ DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {\n    using\
    \ State = typename DFA::State;\n\n    unordered_map<State, modint998244353> dp;\n\
    \    unordered_map<State, modint998244353> dp_next;\n\n    dp.emplace(dfa.init(),\
    \ 1);\n\n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n    \
    \    for (const auto& [state, count] : dp) {\n            for (const auto& a :\
    \ alphabet) {\n                State s1 = dfa.next(state, a, i);\n           \
    \     if (dfa.unsuccessful(s1)) continue;\n                dp_next[s1] = dp_next[s1]\
    \ + count;\n            }\n        }\n        dp.swap(dp_next);\n    }\n\n   \
    \ modint998244353 ans = 0;\n    for (const auto& [state, count] : dp) {\n    \
    \    if (dfa.accept(state)) {\n            ans += count;\n        }\n    }\n \
    \   return ans.val();\n}\n\ntemplate <typename DFA>\nlong long count_dfa_ll(const\
    \ DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {\n    using\
    \ State = typename DFA::State;\n\n    unordered_map<State, long long> dp;\n  \
    \  unordered_map<State, long long> dp_next;\n\n    dp.emplace(dfa.init(), 1);\n\
    \n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n        for\
    \ (const auto& [state, count] : dp) {\n            for (const auto& a : alphabet)\
    \ {\n                State s1 = dfa.next(state, a, i);\n                if (dfa.unsuccessful(s1))\
    \ continue;\n                dp_next[s1] = dp_next[s1] + count;\n            }\n\
    \        }\n        dp.swap(dp_next);\n    }\n\n    long long ans = 0;\n    for\
    \ (const auto& [state, count] : dp) {\n        if (dfa.accept(state)) {\n    \
    \        ans += count;\n        }\n    }\n    return ans;\n}\n\nstruct DPRes {\n\
    \    modint998244353 num, sum;\n};\n\ntemplate <typename DFA>\npair<long long,\
    \ long long> count_sum_dfa(const DFA& dfa, size_t n, const vector<typename DFA::Alphabet>&\
    \ alphabet, int base = 10) {\n    using State = typename DFA::State;\n\n    unordered_map<State,\
    \ DPRes> dp;\n    unordered_map<State, DPRes> dp_next;\n\n    dp.emplace(dfa.init(),\
    \ 1);\n\n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n    \
    \    for (const auto& [state, res] : dp) {\n            for (const auto& a : alphabet)\
    \ {\n                State s1 = dfa.next(state, a, i);\n                if (dfa.unsuccessful(s1))\
    \ continue;\n                dp_next[s1].num = dp_next[s1].num + res.num;\n  \
    \              dp_next[s1].sum = dp_next[s1].sum + res.sum * base + (a - '0')\
    \ * res.num;\n            }\n        }\n        dp.swap(dp_next);\n    }\n   \
    \ modint998244353 cnt = 0;\n    modint998244353 sum = 0;\n    for (const auto&\
    \ [state, res] : dp) {\n        if (dfa.accept(state)) {\n            cnt += res.num;\n\
    \            sum += res.sum;\n        }\n    }\n    return {cnt.val(), sum.val()};\n\
    }\n\nstring decimalToBinary(const string& decimalStr) {\n    if (decimalStr.empty())\
    \ return \"0\";\n    string num = decimalStr;\n    string binaryStr = \"\";\n\
    \    while (num != \"0\") {\n        int remainder = 0;\n        string quotient\
    \ = \"\";\n        for (char ch : num) {\n            int current = remainder\
    \ * 10 + (ch - '0');\n            if (!quotient.empty() || current / 2 != 0) {\n\
    \                quotient += (current / 2) + '0';\n            }\n           \
    \ remainder = current % 2;\n        }\n        binaryStr += (remainder ? '1' :\
    \ '0');\n        num = quotient.empty() ? \"0\" : quotient;\n    }\n    reverse(binaryStr.begin(),\
    \ binaryStr.end());\n    return binaryStr.empty() ? \"0\" : binaryStr;\n}\n#line\
    \ 6 \"verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp\"\n\n// \u3054\u3061\u3046\
    \u3055\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass Gochiusa {\n   public:\n\
    \    using Alphabet = char;\n    using State = pair<int, int>;\n\n    Gochiusa()\
    \ {}\n\n    State init() const {\n        return {0, 0};\n    }\n\n    State next(State\
    \ s, const Alphabet& a, size_t i) const {\n        int d = a - '0';\n        if\
    \ (s.first == 4) return {4, 0};\n        if (s.first == 2) return {3, d};\n\n\
    \        if (s.first == 3) {\n            if (d == 3) {\n                return\
    \ {4, 0};\n            } else if (d == 5) {\n                return {1, 5};\n\
    \            } else if (s.second == 5 and d == 1) {\n                return {2,\
    \ 1};\n            } else {\n                return {0, d};\n            }\n \
    \       } else if (s.first == 1) {\n            if (d == 1) {\n              \
    \  return {2, 1};\n            } else if (d == 5) {\n                return {1,\
    \ 5};\n            } else {\n                return {0, d};\n            }\n \
    \       } else if (s.first == 0) {\n            if (d == 5) {\n              \
    \  return {1, 5};\n            } else {\n                return {0, d};\n    \
    \        }\n        }\n        return {0, 0};\n    }\n\n    bool accept(State\
    \ s) const {\n        return s.first == 4;\n    }\n\n    bool successful(State\
    \ s) const {\n        return s.first == 4;\n    }\n\n    bool unsuccessful(State\
    \ s) const {\n        return 0;\n    }\n};\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    vector<char> alphabet(10);\n    iota(all(alphabet), '0');\n    string s;\n\
    \    in(s);\n    out(count_dfa_ll(AndDfa(Leq(s), Gochiusa()), s.size(), alphabet));\n\
    }\n"
  code: "#include \"../../../atcoder/modint.hpp\"\nusing namespace atcoder;\n#include\
    \ \"../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2879\"\
    \n#include \"../../../dp/DeterministicFiniteAutomatonDP.hpp\"\n\n// \u3054\u3061\
    \u3046\u3055\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass Gochiusa {\n   public:\n\
    \    using Alphabet = char;\n    using State = pair<int, int>;\n\n    Gochiusa()\
    \ {}\n\n    State init() const {\n        return {0, 0};\n    }\n\n    State next(State\
    \ s, const Alphabet& a, size_t i) const {\n        int d = a - '0';\n        if\
    \ (s.first == 4) return {4, 0};\n        if (s.first == 2) return {3, d};\n\n\
    \        if (s.first == 3) {\n            if (d == 3) {\n                return\
    \ {4, 0};\n            } else if (d == 5) {\n                return {1, 5};\n\
    \            } else if (s.second == 5 and d == 1) {\n                return {2,\
    \ 1};\n            } else {\n                return {0, d};\n            }\n \
    \       } else if (s.first == 1) {\n            if (d == 1) {\n              \
    \  return {2, 1};\n            } else if (d == 5) {\n                return {1,\
    \ 5};\n            } else {\n                return {0, d};\n            }\n \
    \       } else if (s.first == 0) {\n            if (d == 5) {\n              \
    \  return {1, 5};\n            } else {\n                return {0, d};\n    \
    \        }\n        }\n        return {0, 0};\n    }\n\n    bool accept(State\
    \ s) const {\n        return s.first == 4;\n    }\n\n    bool successful(State\
    \ s) const {\n        return s.first == 4;\n    }\n\n    bool unsuccessful(State\
    \ s) const {\n        return 0;\n    }\n};\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    vector<char> alphabet(10);\n    iota(all(alphabet), '0');\n    string s;\n\
    \    in(s);\n    out(count_dfa_ll(AndDfa(Leq(s), Gochiusa()), s.size(), alphabet));\n\
    }"
  dependsOn:
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - template/template.hpp
  - dp/DeterministicFiniteAutomatonDP.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
  requiredBy: []
  timestamp: '2025-05-26 06:29:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
- /verify/verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp.html
title: verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
---
