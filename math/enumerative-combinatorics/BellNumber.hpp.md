---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fps/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/enumerative-combinatorics/BellNumber.test.cpp
    title: verify/LibraryChecker/math/enumerative-combinatorics/BellNumber.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/fps/FormalPowerSeries.hpp\"\nstruct FPS : vector<mint>\
    \ {\n  using vector<mint>::vector;\n  using vector<mint>::operator=;\n\n  FPS\
    \ inv() const {\n    int n = int((*this).size());\n    FPS res = {(*this)[0].inv()};\n\
    \    while (int(res.size()) < n) {\n      int m = int(res.size());\n      // f\
    \ = f[0, 2m)\n      FPS f((*this).begin(), (*this).begin() + min(n, m << 1));\n\
    \      FPS inv_f(res);\n      f.resize(m << 1);\n      internal::butterfly(f);\n\
    \      inv_f.resize(m << 1);\n      internal::butterfly(inv_f);\n      // f =\
    \ f*g\n      for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];\n      internal::butterfly_inv(f);\n\
    \n      // f = f[m, 2m)\n      f.erase(f.begin(), f.begin() + m);\n      f.resize(m\
    \ << 1);\n      // f = f*g\n      internal::butterfly(f);\n      for (int i =\
    \ 0; i < m << 1; i++) f[i] *= inv_f[i];\n      internal::butterfly_inv(f);\n \
    \     mint m2i = mint(m << 1).inv();\n      m2i *= -m2i;\n      for (int i = 0;\
    \ i < m << 1; i++) f[i] *= m2i;\n      res.insert(res.end(), f.begin(), f.begin()\
    \ + m);\n    }\n    return {res.begin(), res.begin() + n};\n  }\n\n  FPS exp()\
    \ const {\n    int n = int((*this).size());\n    FPS res = {1};\n    assert((*this)[0]\
    \ == 0);\n    for (int siz = 1; siz < n; siz <<= 1) {\n      FPS f(siz << 1);\n\
    \      f[0] = 1;\n      res.resize(siz << 1);\n      FPS lg = res.log();\n   \
    \   for (int i = 0; i < siz << 1; i++) f[i] -= lg[i];\n      for (int i = 0; i\
    \ < min(siz << 1, n); i++) f[i] += (*this)[i];\n      res *= f;\n    }\n    return\
    \ {res.begin(), res.begin() + n};\n  }\n\n  FPS log() const {\n    FPS res = *this;\n\
    \    res.log_inplace();\n    return res;\n  }\n\n  FPS pow(__int128_t m) const\
    \ {\n    __int128_t n = int((*this).size());\n    if (m == 0) {\n      FPS res(n);\n\
    \      if (n) res[0] = 1;\n      return res;\n    }\n    // \u5B9A\u6570\u9805\
    \u30921\u306B\u3059\u308B\n    for (__int128_t i = 0; i < n; i++) {\n      if\
    \ ((*this)[i] != 0) {\n        mint coef = (*this)[i];\n        FPS f((*this).begin()\
    \ + i, (*this).end());\n        if (coef != 1) {\n          for (int j = 0; j\
    \ < n - i; j++) f[j] /= coef;\n        }\n        f.log_inplace();\n        for\
    \ (int j = 0; j < n - i; j++) f[j] *= m;\n        f.exp_inplace();\n        coef\
    \ = coef.pow(m);\n        for (int j = 0; j < n - i; j++) f[j] *= coef;\n    \
    \    FPS res(min(__int128_t(m) * i, n), 0);\n        if (res.size() < n) res.insert(res.end(),\
    \ f.begin(), f.begin() + min(__int128_t(n), n - res.size()));\n        return\
    \ res;\n      }\n      if (__int128_t(i + 1) * m >= n) return FPS(n, 0);\n   \
    \ }\n    return FPS(n, 0);\n  }\n\n  FPS differentiate() const {\n    int n =\
    \ int((*this).size());\n    FPS res(n);\n    for (int i = 0; i < n - 1; i++) res[i]\
    \ = (*this)[i + 1] * mint(i + 1);\n    res[n - 1] = 0;\n    return res;\n  }\n\
    \n  FPS integrate() const {\n    int n = int((*this).size());\n    vector<mint>\
    \ iv(n);\n    iv[1] = 1;\n    for (int i = 2; i < n; i++) iv[i] = iv[998244353\
    \ % i] * (-(998244353 / i));\n    FPS res(n);\n    res[0] = 0;\n    for (int i\
    \ = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];\n    return res;\n\
    \  }\n\n  void integrate_inplace() {\n    int n = int((*this).size());\n    static\
    \ vector<mint> inv{0, 1};\n    if (int(inv.size()) < n) {\n      int old_siz =\
    \ inv.size();\n      inv.resize(n);\n      int mod = mint::mod();\n      for (int\
    \ i = old_siz; i < n; i++) inv[i] = -inv[mod % i] * (mod / i);\n    }\n    for\
    \ (int i = n - 1; i > 0; i--) (*this)[i] = (*this)[i - 1] * inv[i];\n    (*this)[0]\
    \ = 0;\n  }\n\n  void differentiate_inplace() {\n    int n = int((*this).size());\n\
    \    if (n == 0) return;\n    for (int i = 0; i < n - 1; i++) {\n      (*this)[i]\
    \ = (*this)[i + 1] * mint(i + 1);\n    }\n    (*this)[n - 1] = 0;\n  }\n\n  void\
    \ inv_inplace() {\n    *this = this->inv();\n  }\n  void exp_inplace() {\n   \
    \ *this = this->exp();\n  }\n\n  void log_inplace() {\n    assert(!empty() and\
    \ (*this)[0] == 1);\n    FPS inv_f = this->inv();\n    this->differentiate_inplace();\n\
    \    *this *= inv_f;\n    this->integrate_inplace();\n  }\n\n  void pow_inplace(__int128_t\
    \ m) {\n    *this = this->pow(m);\n  }\n\n  FPS& operator*=(const FPS& g) {\n\
    \    int n = int((*this).size());\n    *this = convolution(*this, g);\n    (*this).resize(n);\n\
    \    return *this;\n  }\n\n  FPS& operator/=(FPS& g) {\n    int n = int((*this).size());\n\
    \    *this = convolution(*this, g.inv());\n    (*this).resize(n);\n    return\
    \ *this;\n  }\n\n  FPS& operator<<=(int k) {\n    int n = int(size());\n    if\
    \ (k >= n) {\n      assign(n, 0);\n      return *this;\n    }\n    for (int i\
    \ = n - 1; i >= k; i--) (*this)[i] = (*this)[i - k];\n    for (int i = 0; i <\
    \ k; i++) (*this)[i] = 0;\n    return *this;\n  }\n\n  FPS& operator>>=(int k)\
    \ {\n    int n = int(size());\n    if (k >= n) {\n      assign(n, 0);\n      return\
    \ *this;\n    }\n    for (int i = 0; i < n - k; i++) (*this)[i] = (*this)[i +\
    \ k];\n    for (int i = n - k; i < n; i++) (*this)[i] = 0;\n    return *this;\n\
    \  }\n\n  FPS operator<<(int k) const { return FPS(*this) <<= k; }\n  FPS operator>>(int\
    \ k) const { return FPS(*this) >>= k; }\n};\n#line 2 \"math/enumerative-combinatorics/BellNumber.hpp\"\
    \n\nFPS Bell_number(int n) {\n  vector<atcoder::modint998244353> fac(n + 1);\n\
    \  fac[0] = 1;\n  for (int i = 1; i < n + 1; i++) fac[i] = fac[i - 1] * i;\n \
    \ FPS f(n + 1);\n  f[1] = 1;\n  f.exp_inplace();\n  f[0]--;\n  f.exp_inplace();\n\
    \  for (int i = 0; i < n + 1; i++) f[i] *= fac[i];\n  return f;\n}\n"
  code: "#include \"../fps/FormalPowerSeries.hpp\"\n\nFPS Bell_number(int n) {\n \
    \ vector<atcoder::modint998244353> fac(n + 1);\n  fac[0] = 1;\n  for (int i =\
    \ 1; i < n + 1; i++) fac[i] = fac[i - 1] * i;\n  FPS f(n + 1);\n  f[1] = 1;\n\
    \  f.exp_inplace();\n  f[0]--;\n  f.exp_inplace();\n  for (int i = 0; i < n +\
    \ 1; i++) f[i] *= fac[i];\n  return f;\n}"
  dependsOn:
  - math/fps/FormalPowerSeries.hpp
  isVerificationFile: false
  path: math/enumerative-combinatorics/BellNumber.hpp
  requiredBy: []
  timestamp: '2026-03-26 18:24:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/enumerative-combinatorics/BellNumber.test.cpp
documentation_of: math/enumerative-combinatorics/BellNumber.hpp
layout: document
title: Bell Number
---

## 概要

todo

## 計算量
todo