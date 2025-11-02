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
  bundledCode: "#line 1 \"math/fps/FormalPowerSeries.hpp\"\n\nstruct FPS : vector<mint>\
    \ {\n    using vector<mint>::vector;\n    using vector<mint>::operator=;\n\n \
    \   FPS inv() {\n        int n = int((*this).size());\n        FPS res = {(*this)[0].inv()};\n\
    \        while (int(res.size()) < n) {\n            int m = int(res.size());\n\
    \            FPS f((*this).begin(), (*this).begin() + min(n, m << 1));\n     \
    \       FPS inv_f(res);\n            f.resize(m << 1);\n            internal::butterfly(f);\n\
    \            inv_f.resize(m << 1);\n            internal::butterfly(inv_f);\n\
    \            for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];\n            internal::butterfly_inv(f);\n\
    \            f.erase(f.begin(), f.begin() + m);\n            f.resize(m << 1);\n\
    \            internal::butterfly(f);\n            for (int i = 0; i < m << 1;\
    \ i++) f[i] *= inv_f[i];\n            internal::butterfly_inv(f);\n          \
    \  mint m2i = mint(m << 1).inv();\n            m2i *= -m2i;\n            for (int\
    \ i = 0; i < m << 1; i++) f[i] *= m2i;\n            res.insert(res.end(), f.begin(),\
    \ f.begin() + m);\n        }\n        return {res.begin(), res.begin() + n};\n\
    \    }\n\n    FPS log() {\n        int n = int((*this).size());\n        FPS res\
    \ = (*this).differentiate();\n        res /= (*this);\n        return res.integrate();\n\
    \    }\n\n    FPS differentiate() {\n        int n = int((*this).size());\n  \
    \      FPS res(n);\n        for (int i = 0; i < n - 1; i++) res[i] = (*this)[i\
    \ + 1] * mint(i + 1);\n        res[n - 1] = 0;\n        return res;\n    }\n\n\
    \    FPS integrate() {\n        int n = int((*this).size());\n        vector<mint>\
    \ iv(n);\n        iv[1] = 1;\n        for (int i = 2; i < n; i++) iv[i] = iv[998244353\
    \ % i] * (-(998244353 / i));\n        FPS res(n);\n        res[0] = 0;\n     \
    \   for (int i = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];\n   \
    \     return res;\n    }\n\n    FPS& operator*=(const FPS& g) {\n        int n\
    \ = int((*this).size());\n        *this = convolution(*this, g);\n        (*this).resize(n);\n\
    \        return *this;\n    }\n\n    FPS& operator/=(FPS& g) {\n        int n\
    \ = int((*this).size());\n        *this = convolution(*this, g.inv());\n     \
    \   (*this).resize(n);\n        return *this;\n    }\n};\n"
  code: "\nstruct FPS : vector<mint> {\n    using vector<mint>::vector;\n    using\
    \ vector<mint>::operator=;\n\n    FPS inv() {\n        int n = int((*this).size());\n\
    \        FPS res = {(*this)[0].inv()};\n        while (int(res.size()) < n) {\n\
    \            int m = int(res.size());\n            FPS f((*this).begin(), (*this).begin()\
    \ + min(n, m << 1));\n            FPS inv_f(res);\n            f.resize(m << 1);\n\
    \            internal::butterfly(f);\n            inv_f.resize(m << 1);\n    \
    \        internal::butterfly(inv_f);\n            for (int i = 0; i < m << 1;\
    \ i++) f[i] *= inv_f[i];\n            internal::butterfly_inv(f);\n          \
    \  f.erase(f.begin(), f.begin() + m);\n            f.resize(m << 1);\n       \
    \     internal::butterfly(f);\n            for (int i = 0; i < m << 1; i++) f[i]\
    \ *= inv_f[i];\n            internal::butterfly_inv(f);\n            mint m2i\
    \ = mint(m << 1).inv();\n            m2i *= -m2i;\n            for (int i = 0;\
    \ i < m << 1; i++) f[i] *= m2i;\n            res.insert(res.end(), f.begin(),\
    \ f.begin() + m);\n        }\n        return {res.begin(), res.begin() + n};\n\
    \    }\n\n    FPS log() {\n        int n = int((*this).size());\n        FPS res\
    \ = (*this).differentiate();\n        res /= (*this);\n        return res.integrate();\n\
    \    }\n\n    FPS differentiate() {\n        int n = int((*this).size());\n  \
    \      FPS res(n);\n        for (int i = 0; i < n - 1; i++) res[i] = (*this)[i\
    \ + 1] * mint(i + 1);\n        res[n - 1] = 0;\n        return res;\n    }\n\n\
    \    FPS integrate() {\n        int n = int((*this).size());\n        vector<mint>\
    \ iv(n);\n        iv[1] = 1;\n        for (int i = 2; i < n; i++) iv[i] = iv[998244353\
    \ % i] * (-(998244353 / i));\n        FPS res(n);\n        res[0] = 0;\n     \
    \   for (int i = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];\n   \
    \     return res;\n    }\n\n    FPS& operator*=(const FPS& g) {\n        int n\
    \ = int((*this).size());\n        *this = convolution(*this, g);\n        (*this).resize(n);\n\
    \        return *this;\n    }\n\n    FPS& operator/=(FPS& g) {\n        int n\
    \ = int((*this).size());\n        *this = convolution(*this, g.inv());\n     \
    \   (*this).resize(n);\n        return *this;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2025-11-03 02:42:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/FormalPowerSeries.hpp
layout: document
title: Formal Power Series
---

## 概要

工事中

## 計算量
todo