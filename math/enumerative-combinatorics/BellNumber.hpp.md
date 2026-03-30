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
  bundledCode: "#line 1 \"math/fps/FormalPowerSeries.hpp\"\ntemplate <class S>\nstruct\
    \ FPS;\n\ntemplate <class S>\nstruct SFPS : vector<pair<int, S>> {\n  using vector<pair<int,\
    \ S>>::vector;\n  using vector<pair<int, S>>::operator=;\n\n  FPS<S> log(int deg);\n\
    \  FPS<S> exp(int deg);\n  FPS<S> pow(long long m, int deg);\n};\n\ntemplate <class\
    \ S>\nstruct FPS : vector<S> {\n  using vector<S>::vector;\n  using vector<S>::operator=;\n\
    \n  FPS<S> inv() const {\n    int n = int((*this).size());\n    FPS<S> res = {(*this)[0].inv()};\n\
    \    while (int(res.size()) < n) {\n      int m = int(res.size());\n      // f\
    \ = f[0, 2m)\n      FPS<S> f((*this).begin(), (*this).begin() + min(n, m << 1));\n\
    \      FPS<S> inv_f(res);\n      f.resize(m << 1);\n      internal::butterfly(f);\n\
    \      inv_f.resize(m << 1);\n      internal::butterfly(inv_f);\n      // f =\
    \ f*g\n      for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];\n      internal::butterfly_inv(f);\n\
    \n      // f = f[m, 2m)\n      f.erase(f.begin(), f.begin() + m);\n      f.resize(m\
    \ << 1);\n      // f = f*g\n      internal::butterfly(f);\n      for (int i =\
    \ 0; i < m << 1; i++) f[i] *= inv_f[i];\n      internal::butterfly_inv(f);\n \
    \     S m2i = S(m << 1).inv();\n      m2i *= -m2i;\n      for (int i = 0; i <\
    \ m << 1; i++) f[i] *= m2i;\n      res.insert(res.end(), f.begin(), f.begin()\
    \ + m);\n    }\n    return {res.begin(), res.begin() + n};\n  }\n\n  FPS<S> exp()\
    \ const {\n    int n = int((*this).size());\n    FPS<S> res = {1};\n    assert((*this)[0]\
    \ == 0);\n    for (int siz = 1; siz < n; siz <<= 1) {\n      FPS<S> f(siz << 1);\n\
    \      f[0] = 1;\n      res.resize(siz << 1);\n      FPS<S> lg = res.log();\n\
    \      for (int i = 0; i < siz << 1; i++) f[i] -= lg[i];\n      for (int i = 0;\
    \ i < min(siz << 1, n); i++) f[i] += (*this)[i];\n      res *= f;\n    }\n   \
    \ return {res.begin(), res.begin() + n};\n  }\n\n  FPS<S> log() const {\n    FPS<S>\
    \ res = *this;\n    res.log_inplace();\n    return res;\n  }\n\n  FPS<S> pow(__int128_t\
    \ m) const {\n    __int128_t n = int((*this).size());\n    if (m == 0) {\n   \
    \   FPS<S> res(n);\n      if (n) res[0] = 1;\n      return res;\n    }\n    //\
    \ \u5B9A\u6570\u9805\u30921\u306B\u3059\u308B\n    for (__int128_t i = 0; i <\
    \ n; i++) {\n      if ((*this)[i] != 0) {\n        S coef = (*this)[i];\n    \
    \    FPS<S> f((*this).begin() + i, (*this).end());\n        if (coef != 1) {\n\
    \          for (int j = 0; j < n - i; j++) f[j] /= coef;\n        }\n        f.log_inplace();\n\
    \        for (int j = 0; j < n - i; j++) f[j] *= m;\n        f.exp_inplace();\n\
    \        coef = coef.pow(m);\n        for (int j = 0; j < n - i; j++) f[j] *=\
    \ coef;\n        FPS<S> res(min(__int128_t(m) * i, n), 0);\n        if (res.size()\
    \ < n) res.insert(res.end(), f.begin(), f.begin() + min(__int128_t(n), n - res.size()));\n\
    \        return res;\n      }\n      if (__int128_t(i + 1) * m >= n) return FPS<S>(n,\
    \ 0);\n    }\n    return FPS<S>(n, 0);\n  }\n\n  FPS<S> differentiate() const\
    \ {\n    int n = int((*this).size());\n    FPS<S> res(n);\n    for (int i = 0;\
    \ i < n - 1; i++) res[i] = (*this)[i + 1] * S(i + 1);\n    res[n - 1] = 0;\n \
    \   return res;\n  }\n\n  FPS<S> integrate() const {\n    int n = int((*this).size());\n\
    \    vector<S> iv(n);\n    iv[1] = 1;\n    for (int i = 2; i < n; i++) iv[i] =\
    \ iv[S::mod() % i] * (-(S::mod() / i));\n    FPS<S> res(n);\n    res[0] = 0;\n\
    \    for (int i = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];\n  \
    \  return res;\n  }\n\n  void integrate_inplace() {\n    int n = int((*this).size());\n\
    \    static vector<S> inv{0, 1};\n    if (int(inv.size()) < n) {\n      int old_siz\
    \ = inv.size();\n      inv.resize(n);\n      int mod = S::mod();\n      for (int\
    \ i = old_siz; i < n; i++) inv[i] = -inv[mod % i] * (mod / i);\n    }\n    for\
    \ (int i = n - 1; i > 0; i--) (*this)[i] = (*this)[i - 1] * inv[i];\n    (*this)[0]\
    \ = 0;\n  }\n\n  void differentiate_inplace() {\n    int n = int((*this).size());\n\
    \    if (n == 0) return;\n    for (int i = 0; i < n - 1; i++) {\n      (*this)[i]\
    \ = (*this)[i + 1] * S(i + 1);\n    }\n    (*this)[n - 1] = 0;\n  }\n\n  void\
    \ inv_inplace() {\n    *this = this->inv();\n  }\n  void exp_inplace() {\n   \
    \ *this = this->exp();\n  }\n\n  void log_inplace() {\n    assert(!this->empty()\
    \ and (*this)[0] == 1);\n    FPS<S> inv_f = this->inv();\n    this->differentiate_inplace();\n\
    \    *this *= inv_f;\n    this->integrate_inplace();\n  }\n\n  void pow_inplace(__int128_t\
    \ m) {\n    *this = this->pow(m);\n  }\n\n  FPS<S>& operator*=(const FPS<S>& g)\
    \ {\n    int n = int((*this).size());\n    *this = convolution(*this, g);\n  \
    \  (*this).resize(n);\n    return *this;\n  }\n\n  FPS<S>& operator/=(FPS<S>&\
    \ g) {\n    int n = int((*this).size());\n    *this = convolution(*this, g.inv());\n\
    \    (*this).resize(n);\n    return *this;\n  }\n\n  FPS<S>& operator<<=(int k)\
    \ {\n    int n = int((*this).size());\n    if (k >= n) {\n      (*this).assign(n,\
    \ 0);\n      return *this;\n    }\n    for (int i = n - 1; i >= k; i--) (*this)[i]\
    \ = (*this)[i - k];\n    for (int i = 0; i < k; i++) (*this)[i] = 0;\n    return\
    \ *this;\n  }\n\n  FPS<S>& operator>>=(int k) {\n    int n = int((*this).size());\n\
    \    if (k >= n) {\n      (*this).assign(n, 0);\n      return *this;\n    }\n\
    \    for (int i = 0; i < n - k; i++) (*this)[i] = (*this)[i + k];\n    for (int\
    \ i = n - k; i < n; i++) (*this)[i] = 0;\n    return *this;\n  }\n\n  FPS<S>&\
    \ operator*=(const SFPS<S>& g) {\n    int n = (*this).size();\n    int k = int(g.size());\n\
    \    auto [d, c] = g.front();\n    int start = 0;\n    if (d == 0) {\n      start\
    \ = 1;\n    } else {\n      c = 0;\n    }\n    for (int i = n - 1; i >= 0; i--)\
    \ {\n      (*this)[i] *= c;\n      for (int j = start; j < k; j++) {\n       \
    \ const auto& [d_, c_] = g[j];\n        if (d_ > i) break;\n        (*this)[i]\
    \ += (*this)[i - d_] * c_;\n      }\n    }\n    return *this;\n  }\n\n  FPS<S>&\
    \ operator/=(const SFPS<S>& g) {\n    int n = (*this).size();\n    int k = int(g.size());\n\
    \    auto [d, c] = g.front();\n    assert(d == 0 and c != 0);\n    S inv = c.inv();\n\
    \    for (int i = 0; i < n; i++) {\n      for (int j = 1; j < k; j++) {\n    \
    \    const auto& [d, c] = g[j];\n        if (d > i) break;\n        (*this)[i]\
    \ -= (*this)[i - d] * c;\n      }\n      (*this)[i] *= inv;\n    }\n    return\
    \ *this;\n  }\n\n  FPS<S> operator<<(int k) const { return FPS<S>(*this) <<= k;\
    \ }\n  FPS<S> operator>>(int k) const { return FPS<S>(*this) >>= k; }\n};\n\n\
    template <class S>\nFPS<S> SFPS<S>::log(int deg) {\n  FPS<S> f(deg);\n  assert((*this)[0].first\
    \ == 0 and (*this)[0].second == 1 and (*this).back().first < deg);\n  int k =\
    \ (*this).size();\n  for (int i = 0; i < k; i++) {\n    const auto& [d, c] = (*this)[i];\n\
    \    f[d] = c;\n  }\n  f.differentiate_inplace();\n  f /= (*this);\n  f.integrate_inplace();\n\
    \  return f;\n}\n\ntemplate <class S>\nFPS<S> SFPS<S>::exp(int deg) {\n  SFPS\
    \ df = (*this);\n  int k = (*this).size();\n  vector<S> inv(deg);\n  inv[1] =\
    \ 1;\n  for (int i = 2; i < deg; i++) inv[i] = inv[S::mod() % i] * (-(S::mod()\
    \ / i));\n\n  // df = f'\n  for (int i = 0; i < k; i++) {\n    const auto& [d,\
    \ c] = df[i];\n    df[i] = {d - 1, d * c};\n  }\n\n  // F = exp(f)\n  // F' =\
    \ f'F\n  FPS<S> F(deg);\n  F[0] = 1;\n  for (int i = 0; i < deg - 1; i++) {\n\
    \    S conv_sum = 0;\n    for (int j = 0; j < k; j++) {\n      const auto& [d,\
    \ c] = df[j];\n      if (d > i) break;\n      conv_sum += c * F[i - d];\n    }\n\
    \    F[i + 1] = conv_sum * inv[i + 1];\n  }\n  return F;\n}\n\ntemplate <class\
    \ S>\nFPS<S> SFPS<S>::pow(long long m, int deg) {\n  if (m == 0) {\n    FPS<S>\
    \ res(deg);\n    if (deg) res[0] = 1;\n    return res;\n  }\n  vector<S> inv(deg);\n\
    \  inv[1] = 1;\n  for (int i = 2; i < deg; i++) inv[i] = inv[S::mod() % i] * (-(S::mod()\
    \ / i));\n\n  int k = (*this).size();\n  // F = f ^ m\n  FPS<S> F(deg);\n  //\
    \ F' = m(f^(n-1))f'\n  // fF' = mFf'\n\n  // \u5B9A\u6570\u9805\u30921\u306B\u3059\
    \u308B\n  for (int i = 0; i < k; i++) {\n    const auto& [d, c] = (*this)[i];\n\
    \    if (c != 0) {\n      SFPS f((*this).begin() + i, (*this).end());\n      for\
    \ (int j = 0; j < f.size(); j++) {\n        f[j].first -= d;\n        f[j].second\
    \ /= c;\n      }\n\n      FPS<S> F(deg);\n      F[0] = 1;\n      for (int j =\
    \ 0; j < deg - 1; j++) {\n        S dF_j = 0;\n        for (int l = 0; l < f.size();\
    \ l++) {\n          const auto& [d_, c_] = f[l];\n          if (d_ == 0) continue;\n\
    \          if (d_ - 1 > j) break;\n          dF_j += c_ * F[j - d_ + 1] * (S(m)\
    \ * d_ - (j - d_ + 1));\n        }\n        F[j + 1] = dF_j * inv[j + 1];\n  \
    \    }\n      S coef_pw = S(c).pow(m);\n      for (int j = 0; j < deg; j++) F[j]\
    \ *= coef_pw;\n\n      FPS<S> res(min(__int128_t(m) * d, __int128_t(deg)), 0);\n\
    \      if (res.size() < deg) res.insert(res.end(), F.begin(), F.begin() + min(deg,\
    \ deg - int(res.size())));\n      return res;\n    }\n\n    if (__int128_t(d +\
    \ 1) * m >= deg) return FPS<S>(deg, 0);\n  }\n\n  return FPS<S>(deg, 0);\n}\n\
    #line 2 \"math/enumerative-combinatorics/BellNumber.hpp\"\n\ntemplate <class S>\n\
    FPS<S> Bell_number(int n) {\n  vector<S> fac(n + 1);\n  fac[0] = 1;\n  for (int\
    \ i = 1; i < n + 1; i++) fac[i] = fac[i - 1] * i;\n  FPS<S> f(n + 1);\n  f[1]\
    \ = 1;\n  f.exp_inplace();\n  f[0]--;\n  f.exp_inplace();\n  for (int i = 0; i\
    \ < n + 1; i++) f[i] *= fac[i];\n  return f;\n}\n"
  code: "#include \"../fps/FormalPowerSeries.hpp\"\n\ntemplate <class S>\nFPS<S> Bell_number(int\
    \ n) {\n  vector<S> fac(n + 1);\n  fac[0] = 1;\n  for (int i = 1; i < n + 1; i++)\
    \ fac[i] = fac[i - 1] * i;\n  FPS<S> f(n + 1);\n  f[1] = 1;\n  f.exp_inplace();\n\
    \  f[0]--;\n  f.exp_inplace();\n  for (int i = 0; i < n + 1; i++) f[i] *= fac[i];\n\
    \  return f;\n}"
  dependsOn:
  - math/fps/FormalPowerSeries.hpp
  isVerificationFile: false
  path: math/enumerative-combinatorics/BellNumber.hpp
  requiredBy: []
  timestamp: '2026-03-31 05:32:13+09:00'
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