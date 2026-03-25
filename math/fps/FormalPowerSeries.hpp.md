---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/fps/ExpofFormalPowerSeries.test.cpp
    title: verify/LibraryChecker/math/fps/ExpofFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/fps/InvofFormalPowerSeries.test.cpp
    title: verify/LibraryChecker/math/fps/InvofFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/fps/LogofFormalPowerSeries.test.cpp
    title: verify/LibraryChecker/math/fps/LogofFormalPowerSeries.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/math/fps/PowofFormalPowerSeries.test.cpp
    title: verify/LibraryChecker/math/fps/PowofFormalPowerSeries.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/fps/FormalPowerSeries.hpp\"\nstruct FPS : vector<mint>\
    \ {\n  using vector<mint>::vector;\n  using vector<mint>::operator=;\n\n  FPS\
    \ inv() {\n    int n = int((*this).size());\n    FPS res = {(*this)[0].inv()};\n\
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
    \ {\n    int n = int((*this).size());\n    FPS res = {1};\n    assert((*this)[0]\
    \ == 0);\n    for (int siz = 1; siz < n; siz <<= 1) {\n      FPS f(siz << 1);\n\
    \      f[0] = 1;\n      res.resize(siz << 1);\n      FPS lg = res.log();\n   \
    \   for (int i = 0; i < siz << 1; i++) f[i] -= lg[i];\n      for (int i = 0; i\
    \ < min(siz << 1, n); i++) f[i] += (*this)[i];\n      res *= f;\n    }\n    return\
    \ {res.begin(), res.begin() + n};\n  }\n\n  FPS log() {\n    FPS res = (*this).differentiate();\n\
    \    res /= (*this);\n    return res.integrate();\n  }\n\n  FPS pow(__int128_t\
    \ m) {\n    __int128_t n = int((*this).size());\n    if (m == 0) {\n      FPS\
    \ res(n);\n      if (n) res[0] = 1;\n      return res;\n    }\n    // \u5B9A\u6570\
    \u9805\u30921\u306B\u3059\u308B\n    for (__int128_t i = 0; i < n; i++) {\n  \
    \    if ((*this)[i] != 0) {\n        mint coef = (*this)[i];\n        FPS f((*this).begin()\
    \ + i, (*this).end());\n        if (coef != 1) {\n          for (int j = 0; j\
    \ < n - i; j++) f[j] /= coef;\n        }\n        f = f.log();\n        for (int\
    \ j = 0; j < n - i; j++) f[j] *= m;\n        f = f.exp();\n        coef = coef.pow(m);\n\
    \        for (int j = 0; j < n - i; j++) f[j] *= coef;\n        FPS res(min(__int128_t(m)\
    \ * i, n), 0);\n        if (res.size() < n) res.insert(res.end(), f.begin(), f.begin()\
    \ + min(__int128_t(n), n - res.size()));\n        return res;\n      }\n     \
    \ if (__int128_t(i + 1) * m >= n) return FPS(n, 0);\n    }\n    return FPS(n,\
    \ 0);\n  }\n\n  FPS differentiate() {\n    int n = int((*this).size());\n    FPS\
    \ res(n);\n    for (int i = 0; i < n - 1; i++) res[i] = (*this)[i + 1] * mint(i\
    \ + 1);\n    res[n - 1] = 0;\n    return res;\n  }\n\n  FPS integrate() {\n  \
    \  int n = int((*this).size());\n    vector<mint> iv(n);\n    iv[1] = 1;\n   \
    \ for (int i = 2; i < n; i++) iv[i] = iv[998244353 % i] * (-(998244353 / i));\n\
    \    FPS res(n);\n    res[0] = 0;\n    for (int i = 0; i < n - 1; i++) res[i +\
    \ 1] = (*this)[i] * iv[i + 1];\n    return res;\n  }\n\n  FPS& operator*=(const\
    \ FPS& g) {\n    int n = int((*this).size());\n    *this = convolution(*this,\
    \ g);\n    (*this).resize(n);\n    return *this;\n  }\n\n  FPS& operator/=(FPS&\
    \ g) {\n    int n = int((*this).size());\n    *this = convolution(*this, g.inv());\n\
    \    (*this).resize(n);\n    return *this;\n  }\n};\n"
  code: "struct FPS : vector<mint> {\n  using vector<mint>::vector;\n  using vector<mint>::operator=;\n\
    \n  FPS inv() {\n    int n = int((*this).size());\n    FPS res = {(*this)[0].inv()};\n\
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
    \ {\n    int n = int((*this).size());\n    FPS res = {1};\n    assert((*this)[0]\
    \ == 0);\n    for (int siz = 1; siz < n; siz <<= 1) {\n      FPS f(siz << 1);\n\
    \      f[0] = 1;\n      res.resize(siz << 1);\n      FPS lg = res.log();\n   \
    \   for (int i = 0; i < siz << 1; i++) f[i] -= lg[i];\n      for (int i = 0; i\
    \ < min(siz << 1, n); i++) f[i] += (*this)[i];\n      res *= f;\n    }\n    return\
    \ {res.begin(), res.begin() + n};\n  }\n\n  FPS log() {\n    FPS res = (*this).differentiate();\n\
    \    res /= (*this);\n    return res.integrate();\n  }\n\n  FPS pow(__int128_t\
    \ m) {\n    __int128_t n = int((*this).size());\n    if (m == 0) {\n      FPS\
    \ res(n);\n      if (n) res[0] = 1;\n      return res;\n    }\n    // \u5B9A\u6570\
    \u9805\u30921\u306B\u3059\u308B\n    for (__int128_t i = 0; i < n; i++) {\n  \
    \    if ((*this)[i] != 0) {\n        mint coef = (*this)[i];\n        FPS f((*this).begin()\
    \ + i, (*this).end());\n        if (coef != 1) {\n          for (int j = 0; j\
    \ < n - i; j++) f[j] /= coef;\n        }\n        f = f.log();\n        for (int\
    \ j = 0; j < n - i; j++) f[j] *= m;\n        f = f.exp();\n        coef = coef.pow(m);\n\
    \        for (int j = 0; j < n - i; j++) f[j] *= coef;\n        FPS res(min(__int128_t(m)\
    \ * i, n), 0);\n        if (res.size() < n) res.insert(res.end(), f.begin(), f.begin()\
    \ + min(__int128_t(n), n - res.size()));\n        return res;\n      }\n     \
    \ if (__int128_t(i + 1) * m >= n) return FPS(n, 0);\n    }\n    return FPS(n,\
    \ 0);\n  }\n\n  FPS differentiate() {\n    int n = int((*this).size());\n    FPS\
    \ res(n);\n    for (int i = 0; i < n - 1; i++) res[i] = (*this)[i + 1] * mint(i\
    \ + 1);\n    res[n - 1] = 0;\n    return res;\n  }\n\n  FPS integrate() {\n  \
    \  int n = int((*this).size());\n    vector<mint> iv(n);\n    iv[1] = 1;\n   \
    \ for (int i = 2; i < n; i++) iv[i] = iv[998244353 % i] * (-(998244353 / i));\n\
    \    FPS res(n);\n    res[0] = 0;\n    for (int i = 0; i < n - 1; i++) res[i +\
    \ 1] = (*this)[i] * iv[i + 1];\n    return res;\n  }\n\n  FPS& operator*=(const\
    \ FPS& g) {\n    int n = int((*this).size());\n    *this = convolution(*this,\
    \ g);\n    (*this).resize(n);\n    return *this;\n  }\n\n  FPS& operator/=(FPS&\
    \ g) {\n    int n = int((*this).size());\n    *this = convolution(*this, g.inv());\n\
    \    (*this).resize(n);\n    return *this;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2026-03-26 00:06:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/math/fps/LogofFormalPowerSeries.test.cpp
  - verify/LibraryChecker/math/fps/ExpofFormalPowerSeries.test.cpp
  - verify/LibraryChecker/math/fps/PowofFormalPowerSeries.test.cpp
  - verify/LibraryChecker/math/fps/InvofFormalPowerSeries.test.cpp
documentation_of: math/fps/FormalPowerSeries.hpp
layout: document
title: Formal Power Series
---

## 概要

工事中

## 計算量
todo