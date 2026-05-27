---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/modint.hpp
    title: atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: graph/tree/TreeDPPointSet.hpp
    title: Tree DP Point Set
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 2 \"template/template.hpp\"\
    \n#pragma region Macros\n#include <bits/stdc++.h>\n#include <tr2/dynamic_bitset>\n\
    \nusing namespace std;\nusing namespace tr2;\nusing lint = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n\
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 3 \"verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp\"\
    \nusing namespace atcoder;\nusing mint = modint998244353;\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#line 2 \"data-structure/segment-tree/SegmentTree.hpp\"\ntemplate <class S,\
    \ auto op, auto e>\nstruct segtree {\n private:\n  unsigned int seg_bit_ceil(unsigned\
    \ int n) {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n\
    \    return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  segtree()\
    \ : segtree(0) {}\n  explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    size\
    \ = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n  \
    \    update(i);\n    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p &&\
    \ p < _n);\n    p += size;\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) const {\n    assert(0 <= p && p < _n);\n\
    \    return d[p + size];\n  }\n\n  S prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= _n);\n    S sml = e(), smr = e();\n    l += size;\n \
    \   r += size;\n\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n\
    \  template <bool (*f)(S)>\n  int max_right(int l) const {\n    return max_right(l,\
    \ [](S x) { return f(x); });\n  }\n  template <class F>\n  int max_right(int l,\
    \ F f) const {\n    assert(0 <= l && l <= _n);\n    assert(f(e()));\n    if (l\
    \ == _n) return _n;\n    l += size;\n    S sm = e();\n    do {\n      while (l\
    \ % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < size)\
    \ {\n          l = (2 * l);\n          if (f(op(sm, d[l]))) {\n            sm\
    \ = op(sm, d[l]);\n            l++;\n          }\n        }\n        return l\
    \ - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l)\
    \ != l);\n    return _n;\n  }\n\n  template <bool (*f)(S)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n    S sm = e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r],\
    \ sm))) {\n        while (r < size) {\n          r = (2 * r + 1);\n          if\
    \ (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = op(d[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n,\
    \ size, log;\n  std::vector<S> d;\n\n  void update(int k) { d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n};\n#line 2 \"graph/tree/TreeDPPointSet.hpp\"\n\ntemplate\
    \ <class Path, auto compress, auto Path_e, class Point, auto rake, auto Point_e,\
    \ auto add_v, auto add_e, auto vertex>\nstruct hld {\n private:\n  int n, root;\n\
    \  vector<vector<int>> g;\n  vector<int> heavy_p, heavy_l, light_p, idx, idx_c;\n\
    \  segtree<Path, compress, Path_e> seg;\n  segtree<Point, rake, Point_e> seg2;\n\
    \n  int dfs(int cur, int prev) {\n    int sub = 1;\n    for (int& nex : g[cur])\
    \ {\n      if (nex == prev) {\n        swap(g[cur].back(), nex);\n        g[cur].pop_back();\n\
    \        break;\n      }\n    }\n    int best = 0;\n    int idx = -1;\n    for\
    \ (int i = 0; i < int(g[cur].size()); i++) {\n      int cnt = dfs(g[cur][i], cur);\n\
    \      sub += cnt;\n      if (best < cnt) {\n        best = cnt;\n        idx\
    \ = i;\n      }\n    }\n    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());\n\
    \    for (int i = 1; i < int(g[cur].size()); i++) light_p[g[cur][i]] = cur;\n\
    \    return sub;\n  }\n\n  void dfs2(int cur, int top, int& id, int& id2) {\n\
    \    heavy_p[cur] = top;\n    idx[cur] = --id;\n    if (!g[cur].empty()) {\n \
    \     dfs2(g[cur].front(), top, id, id2);\n      heavy_l[cur] = heavy_l[g[cur].front()];\n\
    \    } else {\n      heavy_l[cur] = cur;\n    }\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) dfs2(g[cur][i], g[cur][i], id, id2);\n    for (int i = 1; i < int(g[cur].size());\
    \ i++) idx_c[g[cur][i]] = id2++;\n  }\n\n  Point init_segtree(int top, vector<Path>&\
    \ init_path, vector<Point>& init_point) {\n    vector<int> heavy_path;\n    int\
    \ v = top;\n    while (1) {\n      heavy_path.emplace_back(v);\n      if (g[v].empty())\
    \ break;\n      v = g[v].front();\n    }\n    for (int v : heavy_path) {\n   \
    \   Point light = Point_e();\n      for (int i = 1; i < int(g[v].size()); i++)\
    \ {\n        int ch = g[v][i];\n        Point child_point = init_segtree(ch, init_path,\
    \ init_point);\n        init_point[idx_c[ch]] = child_point;\n        light =\
    \ rake(light, child_point);\n      }\n      if (g[v].size() > 1) {\n        init_path[idx[v]]\
    \ = add_v(v, light);\n      } else {\n        init_path[idx[v]] = vertex(v);\n\
    \      }\n    }\n    Path path = Path_e();\n    for (int i = int(heavy_path.size())\
    \ - 1; i >= 0; i--) {\n      int v = heavy_path[i];\n      path = compress(path,\
    \ init_path[idx[v]]);\n    }\n    return add_e(path);\n  }\n\n public:\n  hld(int\
    \ n, int root = 0) : n(n), root(root), g(n), heavy_p(n, -1), heavy_l(n, -1), light_p(n,\
    \ -1), idx(n), idx_c(n) {}\n\n  void add_edge(int u, int v) {\n    g[u].emplace_back(v);\n\
    \    g[v].emplace_back(u);\n  }\n\n  void build(int root = 0) {\n    int id =\
    \ n;\n    int id2 = 0;\n    dfs(root, -1);\n    dfs2(root, root, id, id2);\n \
    \   vector<Path> init_path(n, Path_e());\n    vector<Point> init_point(n, Point_e());\n\
    \    init_segtree(root, init_path, init_point);\n    seg = segtree<Path, compress,\
    \ Path_e>(init_path);\n    seg2 = segtree<Point, rake, Point_e>(init_point);\n\
    \  }\n\n  Path tree_dp() {\n    return seg.prod(idx[heavy_l[root]], idx[root]\
    \ + 1);\n  }\n\n  void set(int i) {\n    while (1) {\n      if (g[i].size() >\
    \ 1) {\n        int ch_num = int(g[i].size()) - 1;\n        if (ch_num == 1) {\n\
    \          seg.set(idx[i], add_v(i, seg2.get(idx_c[g[i][1]])));\n        } else\
    \ {\n          seg.set(idx[i], add_v(i, seg2.prod(idx_c[g[i][1]], idx_c[g[i][1]]\
    \ + ch_num)));\n        }\n      } else {\n        seg.set(idx[i], vertex(i));\n\
    \      }\n      int nex = light_p[heavy_p[i]];\n      if (nex == -1) break;\n\
    \      int l = idx[heavy_l[heavy_p[i]]];\n      int r = idx[heavy_p[i]] + 1;\n\
    \      if (r - l == 1) {\n        seg2.set(idx_c[heavy_p[i]], add_e(seg.get(l)));\n\
    \      } else {\n        seg2.set(idx_c[heavy_p[i]], add_e(seg.prod(l, r)));\n\
    \      }\n      i = nex;\n    }\n  }\n};\n#line 7 \"verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp\"\
    \n\nvector<mint> A, eb, ec;\n\nstruct Path {\n  mint a, b, g, d;\n  Path(mint\
    \ a = 1, mint b = 0, mint g = 0, mint d = 0) : a(a), b(b), g(g), d(d) {}\n};\n\
    \nPath compress(const Path& p, const Path& c) {\n  return Path(p.a * c.a, c.a\
    \ * p.b + c.b, c.a * p.g + c.b * p.d + c.g, c.d + p.d);\n}\n\nstruct Point {\n\
    \  mint sum;\n  mint cnt;\n  Point(mint sum = 0, mint cnt = 0) : sum(sum), cnt(cnt)\
    \ {}\n};\n\nPoint point_e() {\n  return {0, 0};\n}\n\nPath path_e() {\n  return\
    \ Path();\n}\n\nPoint rake(const Point& a, const Point& b) {\n  return Point(a.sum\
    \ + b.sum, a.cnt + b.cnt);\n}\n\nPath add_v(int v, Point p) {\n  mint B = eb[v];\n\
    \  mint C = ec[v];\n  return Path(B, C, B * (p.sum + A[v]) + C * (p.cnt + 1),\
    \ p.cnt + 1);\n}\n\nPath vertex(int v) {\n  mint B = eb[v];\n  mint C = ec[v];\n\
    \  return Path(B, C, B * A[v] + C, 1);\n}\n\nPoint add_e(Path p) {\n  return Point(p.g,\
    \ p.d);\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n \
    \ in(n, q);\n  A.assign(n, 0);\n  eb.assign(n, 1);\n  ec.assign(n, 0);\n\n  rep(i,\
    \ n) {\n    lint x;\n    in(x);\n    A[i] = x;\n  }\n\n  hld<Path, compress, path_e,\
    \ Point, rake, point_e, add_v, add_e, vertex> t(n);\n\n  vector<int> U(n - 1),\
    \ V(n - 1);\n  vector<mint> B(n - 1), C(n - 1);\n\n  vector<vector<pair<int, int>>>\
    \ g(n);\n\n  rep(e, n - 1) {\n    int u, v;\n    lint b, c;\n    in(u, v, b, c);\n\
    \    U[e] = u;\n    V[e] = v;\n    B[e] = mint(b);\n    C[e] = mint(c);\n    t.add_edge(u,\
    \ v);\n    g[u].push_back({v, e});\n    g[v].push_back({u, e});\n  }\n\n  vector<int>\
    \ par(n, -1);\n  vector<int> par_e(n, -1);\n  vector<int> chi_e(n - 1, -1);\n\n\
    \  queue<int> que;\n  par[0] = -2;\n  que.push(0);\n  while (!que.empty()) {\n\
    \    int v = que.front();\n    que.pop();\n    for (auto [to, e] : g[v]) {\n \
    \     if (par[to] != -1) continue;\n      par[to] = v;\n      par_e[to] = e;\n\
    \      chi_e[e] = to;\n      que.push(to);\n    }\n  }\n  eb[0] = 1;\n  ec[0]\
    \ = 0;\n  rep(i, 1, n) {\n    int e = par_e[i];\n    eb[i] = B[e];\n    ec[i]\
    \ = C[e];\n  }\n\n  t.build(0);\n\n  rep(i, q) {\n    int com;\n    in(com);\n\
    \    if (com == 0) {\n      int w;\n      lint x;\n      in(w, x);\n      A[w]\
    \ = x;\n      t.set(w);\n    } else {\n      int e;\n      lint y, z;\n      in(e,\
    \ y, z);\n      int ch = chi_e[e];\n      eb[ch] = y;\n      ec[ch] = z;\n   \
    \   t.set(ch);\n    }\n    out(add_e(t.tree_dp()).sum.val());\n  }\n}\n"
  code: "#include \"../../../../atcoder/modint.hpp\"\n#include \"../../../../template/template.hpp\"\
    \nusing namespace atcoder;\nusing mint = modint998244353;\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#include \"../../../../graph/tree/TreeDPPointSet.hpp\"\n\nvector<mint> A, eb,\
    \ ec;\n\nstruct Path {\n  mint a, b, g, d;\n  Path(mint a = 1, mint b = 0, mint\
    \ g = 0, mint d = 0) : a(a), b(b), g(g), d(d) {}\n};\n\nPath compress(const Path&\
    \ p, const Path& c) {\n  return Path(p.a * c.a, c.a * p.b + c.b, c.a * p.g + c.b\
    \ * p.d + c.g, c.d + p.d);\n}\n\nstruct Point {\n  mint sum;\n  mint cnt;\n  Point(mint\
    \ sum = 0, mint cnt = 0) : sum(sum), cnt(cnt) {}\n};\n\nPoint point_e() {\n  return\
    \ {0, 0};\n}\n\nPath path_e() {\n  return Path();\n}\n\nPoint rake(const Point&\
    \ a, const Point& b) {\n  return Point(a.sum + b.sum, a.cnt + b.cnt);\n}\n\nPath\
    \ add_v(int v, Point p) {\n  mint B = eb[v];\n  mint C = ec[v];\n  return Path(B,\
    \ C, B * (p.sum + A[v]) + C * (p.cnt + 1), p.cnt + 1);\n}\n\nPath vertex(int v)\
    \ {\n  mint B = eb[v];\n  mint C = ec[v];\n  return Path(B, C, B * A[v] + C, 1);\n\
    }\n\nPoint add_e(Path p) {\n  return Point(p.g, p.d);\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int n, q;\n  in(n, q);\n  A.assign(n, 0);\n  eb.assign(n, 1);\n  ec.assign(n,\
    \ 0);\n\n  rep(i, n) {\n    lint x;\n    in(x);\n    A[i] = x;\n  }\n\n  hld<Path,\
    \ compress, path_e, Point, rake, point_e, add_v, add_e, vertex> t(n);\n\n  vector<int>\
    \ U(n - 1), V(n - 1);\n  vector<mint> B(n - 1), C(n - 1);\n\n  vector<vector<pair<int,\
    \ int>>> g(n);\n\n  rep(e, n - 1) {\n    int u, v;\n    lint b, c;\n    in(u,\
    \ v, b, c);\n    U[e] = u;\n    V[e] = v;\n    B[e] = mint(b);\n    C[e] = mint(c);\n\
    \    t.add_edge(u, v);\n    g[u].push_back({v, e});\n    g[v].push_back({u, e});\n\
    \  }\n\n  vector<int> par(n, -1);\n  vector<int> par_e(n, -1);\n  vector<int>\
    \ chi_e(n - 1, -1);\n\n  queue<int> que;\n  par[0] = -2;\n  que.push(0);\n  while\
    \ (!que.empty()) {\n    int v = que.front();\n    que.pop();\n    for (auto [to,\
    \ e] : g[v]) {\n      if (par[to] != -1) continue;\n      par[to] = v;\n     \
    \ par_e[to] = e;\n      chi_e[e] = to;\n      que.push(to);\n    }\n  }\n  eb[0]\
    \ = 1;\n  ec[0] = 0;\n  rep(i, 1, n) {\n    int e = par_e[i];\n    eb[i] = B[e];\n\
    \    ec[i] = C[e];\n  }\n\n  t.build(0);\n\n  rep(i, q) {\n    int com;\n    in(com);\n\
    \    if (com == 0) {\n      int w;\n      lint x;\n      in(w, x);\n      A[w]\
    \ = x;\n      t.set(w);\n    } else {\n      int e;\n      lint y, z;\n      in(e,\
    \ y, z);\n      int ch = chi_e[e];\n      eb[ch] = y;\n      ec[ch] = z;\n   \
    \   t.set(ch);\n    }\n    out(add_e(t.tree_dp()).sum.val());\n  }\n}\n"
  dependsOn:
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - template/template.hpp
  - graph/tree/TreeDPPointSet.hpp
  - data-structure/segment-tree/SegmentTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
  requiredBy: []
  timestamp: '2026-05-27 15:27:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
- /verify/verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp.html
title: verify/LibraryChecker/graph/tree/PointSetTreePathCompositeSumFixed.test.cpp
---
