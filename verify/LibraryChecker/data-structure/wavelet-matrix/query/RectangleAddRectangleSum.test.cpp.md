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
    path: data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp
    title: Rectangle Add Rectangle Sum
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
    PROBLEM: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n#line 1 \"atcoder/modint.hpp\"\n\n\n\n#line 6 \"atcoder/modint.hpp\"\n#include\
    \ <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"\
    atcoder/internal_math.hpp\"\n\n\n\n#line 5 \"atcoder/internal_math.hpp\"\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\n// Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned long long y = x * _m;\n        return (unsigned int)(z\
    \ - y + (z < y ? _m : 0));\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1\
    \ <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
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
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 4 \"verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp\"\
    \nusing mint = atcoder::modint998244353;\n#line 1 \"data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp\"\
    \n\nusing S = tuple<mint, mint, mint, mint>;\n\nS op(const S &a, const S &b) {\n\
    \  auto &[a1, a2, a3, a4] = a;\n  auto &[b1, b2, b3, b4] = b;\n  return {a1 +\
    \ b1, a2 + b2, a3 + b3, a4 + b4};\n}\n\nvoid print(const S &a) {\n  auto &[a1,\
    \ a2, a3, a4] = a;\n  out(a1.val(), a2.val(), a3.val(), a4.val());\n}\n\nS e()\
    \ {\n  return {0, 0, 0, 0};\n}\n\nS operator+(const S &a, const S &b) {\n  return\
    \ op(a, b);\n}\n\nS operator-(const S &a, const S &b) {\n  auto &[a1, a2, a3,\
    \ a4] = a;\n  auto &[b1, b2, b3, b4] = b;\n  return {a1 - b1, a2 - b2, a3 - b3,\
    \ a4 - b4};\n}\n\nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n\
    \  vector<unsigned long long> bit;\n  vector<unsigned> sum;\n  vector<S> srsum;\n\
    \n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 63) >> 6;\n    bit.assign(blocksize, 0ULL);\n    sum.assign(blocksize,\
    \ 0U);\n    srsum.resize(sz);\n  }\n\n  inline void set(int k) { bit[k >> 6] |=\
    \ 1ULL << (k & 63ULL); }\n\n  inline void build() {\n    sum[0] = 0ULL;\n    for\
    \ (int i = 1; i < blocksize; i++) {\n      sum[i] = sum[i - 1] + __builtin_popcountll(bit[i\
    \ - 1]);\n    }\n  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k\
    \ >> 6] >> (k & 63)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k\
    \ >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL << (k & 63)) - 1)));\n  }\n\
    \n  inline void srsum_set(vector<S> &v) {\n    for (int i = 0; i < sz - 1; i++)\
    \ {\n      srsum[i + 1] = srsum[i] + v[i];\n    }\n  }\n\n  inline S rank_srsum(int\
    \ l, int r) {\n    return srsum[r] - srsum[l];\n  }\n\n  inline S rank_srsum(int\
    \ r) {\n    return srsum[r];\n  }\n};\n\nclass WaveletMatrix {\n private:\n  unsigned\
    \ n;\n  unsigned bitsize, logn;\n  vector<BitVector> b;\n  vector<unsigned> zero;\n\
    \  vector<int> cmp;\n  vector<int> px;\n  int MI, MA;\n\n  inline unsigned compress(const\
    \ int &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n\
    \  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n\n  WaveletMatrix(vector<int> x, vector<int> y, vector<S> w) {\n    n =\
    \ x.size();\n    px.resize(n);\n    vector<tuple<int, int, S>> v(n);\n    for\
    \ (int i = 0; i < n; i++) {\n      v[i] = {x[i], y[i], w[i]};\n    }\n    sort(v.begin(),\
    \ v.end(), [](const tuple<int, int, S> &l, const tuple<int, int, S> &r) {\n  \
    \    return std::get<0>(l) < std::get<0>(r);\n    });\n    for (int i = 0; i <\
    \ n; i++) {\n      px[i] = std::get<0>(v[i]);\n      y[i] = std::get<1>(v[i]);\n\
    \      w[i] = std::get<2>(v[i]);\n    }\n    vector<unsigned> compressed(n);\n\
    \    cmp.resize(y.size());\n    cmp = y;\n    sort(cmp.begin(), cmp.end());\n\
    \    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n    vector<unsigned>\
    \ tmpc(n);\n    vector<S> tmp(n);\n    unsigned size_mx = y.size();\n    for (unsigned\
    \ i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), y[i]));\n    }\n    bitsize = bit_width(cmp.size());\n    b.resize(bitsize\
    \ + 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n    for (unsigned i =\
    \ 0; i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n      b[i].srsum_set(w);\n\
    \      cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n        } else {\n \
    \         zero[i]++;\n          tmpc[cur] = compressed[j];\n          tmp[cur]\
    \ = w[j];\n          cur++;\n        }\n      }\n\n      b[i].build();\n     \
    \ for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = w[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ w);\n    }\n\n    b[bitsize] = BitVector(n + 1);\n    b[bitsize].srsum_set(w);\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\
    \u7DCF\u548C\u3092\u8FD4\u3059\n  S range_sum(int vl, int vr, int mink, int maxk)\
    \ {\n    int D = mink;\n    int U = compress(maxk);\n    S res = e();\n    auto\
    \ dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {\n      if\
    \ (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n        res = op(res,\
    \ b[d].rank_srsum(L, R));\n        return;\n      }\n      if (d == bitsize) {\n\
    \        if (D <= A and A < U) {\n          res = op(res, b[bitsize].rank_srsum(L,\
    \ R));\n        }\n        return;\n      }\n      int C = (A + B) >> 1;\n   \
    \   int rank0_l = L - b[d].rank(L);\n      int rank0_r = R - b[d].rank(R);\n \
    \     int rank1_l = b[d].rank(L) + zero[d];\n      int rank1_r = b[d].rank(R)\
    \ + zero[d];\n\n      rec(rec, d + 1, rank0_l, rank0_r, A, C);\n      rec(rec,\
    \ d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs, 0, vl, vr, 0, 1 << bitsize);\n\
    \    return res;\n  }\n\n  // x\u5EA7\u6A19\u304C[l,r) \u304B\u3064y\u5EA7\u6A19\
    \u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n  S\
    \ rectangle_sum(int l, int r, int d, int u) {\n    unsigned cr = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), r));\n    return range_sum(l, cr, d, u);\n\
    \  }\n};\n\nclass RectangleAddRectangleSum {\n private:\n  vector<int> x, y;\n\
    \  vector<S> z;\n  WaveletMatrix wm;\n\n public:\n  RectangleAddRectangleSum(const\
    \ vector<int> &x1, const vector<int> &y1, const vector<int> &x2, const vector<int>\
    \ &y2, const vector<int> &weight) {\n    int n = x1.size();\n    x.resize(n *\
    \ 4);\n    y.resize(n * 4);\n    z.resize(n * 4);\n\n    for (int i = 0; i < n;\
    \ i++) {\n      int xl = x1[i];\n      int yl = y1[i];\n      int xr = x2[i];\n\
    \      int yr = y2[i];\n      mint w = weight[i];\n      x[i * 4] = xl;\n    \
    \  y[i * 4] = yl;\n      z[i * 4] = {w, w * -yl, w * -xl, w * +xl * yl};\n\n \
    \     x[i * 4 + 1] = xl;\n      y[i * 4 + 1] = yr;\n      z[i * 4 + 1] = {-w,\
    \ w * +yr, w * xl, w * -xl * yr};\n\n      x[i * 4 + 2] = xr;\n      y[i * 4 +\
    \ 2] = yl;\n      z[i * 4 + 2] = {-w, w * yl, w * xr, w * -xr * yl};\n\n     \
    \ x[i * 4 + 3] = xr;\n      y[i * 4 + 3] = yr;\n      z[i * 4 + 3] = {w, w * -yr,\
    \ w * -xr, w * xr * yr};\n    }\n\n    wm = WaveletMatrix(x, y, z);\n  }\n\n \
    \ mint rectangle_sum(int xl, int yl, int xr, int yr) {\n    mint resp = 0;\n \
    \   mint resn = 0;\n    {\n      auto [a, b, c, d] = wm.rectangle_sum(0, xl, 0,\
    \ yl);\n      resp += a * xl * yl;\n      resp += b * xl;\n      resp += c * yl;\n\
    \      resp += d;\n    }\n    {\n      auto [a, b, c, d] = wm.rectangle_sum(0,\
    \ xl, 0, yr);\n      resn += a * xl * yr;\n      resn += b * xl;\n      resn +=\
    \ c * yr;\n      resn += d;\n    }\n    {\n      auto [a, b, c, d] = wm.rectangle_sum(0,\
    \ xr, 0, yl);\n      resn += a * xr * yl;\n      resn += b * xr;\n      resn +=\
    \ c * yl;\n      resn += d;\n    }\n    {\n      auto [a, b, c, d] = wm.rectangle_sum(0,\
    \ xr, 0, yr);\n      resp += a * xr * yr;\n      resp += b * xr;\n      resp +=\
    \ c * yr;\n      resp += d;\n    }\n    return resp - resn;\n  }\n};\n#line 6\
    \ \"verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp\"\
    \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<int> x1(n), y1(n), x2(n), y2(n), w(n);\n    rep(i, n) {\n  \
    \      in(x1[i], y1[i], x2[i], y2[i], w[i]);\n    }\n\n    RectangleAddRectangleSum\
    \ wm(x1, y1, x2, y2, w);\n\n    rep(i, q) {\n        int l, d, r, u;\n       \
    \ in(l, d, r, u);\n        out(wm.rectangle_sum(l, d, r, u).val());\n    }\n}\n"
  code: "#include \"../../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n#include \"../../../../../atcoder/modint.hpp\"\nusing mint = atcoder::modint998244353;\n\
    #include \"../../../../../data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp\"\
    \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n,\
    \ q);\n    vector<int> x1(n), y1(n), x2(n), y2(n), w(n);\n    rep(i, n) {\n  \
    \      in(x1[i], y1[i], x2[i], y2[i], w[i]);\n    }\n\n    RectangleAddRectangleSum\
    \ wm(x1, y1, x2, y2, w);\n\n    rep(i, q) {\n        int l, d, r, u;\n       \
    \ in(l, d, r, u);\n        out(wm.rectangle_sum(l, d, r, u).val());\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - atcoder/modint.hpp
  - atcoder/internal_math.hpp
  - atcoder/internal_type_traits.hpp
  - data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 04:01:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp
- /verify/verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp.html
title: verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddRectangleSum.test.cpp
---
