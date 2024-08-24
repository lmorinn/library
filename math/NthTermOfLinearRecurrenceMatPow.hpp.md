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
  bundledCode: "#line 2 \"math/NthTermOfLinearRecurrenceMatPow.hpp\"\ntemplate <class\
    \ T>\nvector<vector<T>> multiply_matrix(vector<vector<T>> &a, vector<vector<T>>\
    \ &b) {\n    int n = a.size();\n    int m = b[0].size();\n    vector<vector<T>>\
    \ ret(n, vector<T>(m));\n    for (int i = 0; i < n; i++) {\n        for (int j\
    \ = 0; j < m; j++) {\n            for (int k = 0; k < b.size(); k++) {\n     \
    \           ret[i][j] += (a[i][k] * b[k][j]);\n            }\n        }\n    }\n\
    \n    return ret;\n}\n\ntemplate <class T>\nvector<vector<T>> pow_matrix(vector<vector<T>>\
    \ a, long long n) {\n    vector<vector<T>> ret(a.size(), vector<T>(a[0].size()));\n\
    \    for (int i = 0; i < ret.size(); i++) {\n        ret[i][i] = 1;\n    }\n\n\
    \    while (n > 0) {\n        if (n & 1) ret = multiply_matrix(ret, a);\n    \
    \    a = multiply_matrix(a, a);\n        n >>= 1;\n    }\n\n    return ret;\n\
    }\n\ntemplate <class T>\nT nth_sequence_recurrence(vector<T> coefficient, T constant,\
    \ vector<T> init, long long n) {\n    int m = coefficient.size();\n    vector<vector<T>>\
    \ mat(m + 1, vector<T>(m + 1));\n    vector<vector<T>> initv(m + 1, vector<T>(1));\n\
    \    reverse(init.begin(), init.end());\n    for (int i = 0; i < m; i++) {\n \
    \       initv[i][0] = init[i];\n    }\n    initv[m][0] = 1;\n    for (int i =\
    \ 0; i < m; i++) {\n        mat[0][i] = coefficient[m - 1 - i];\n    }\n    for\
    \ (int i = 1; i < m; i++) {\n        mat[i][i - 1] = 1;\n    }\n    mat[0][m]\
    \ = constant;\n    mat[m][m] = 1;\n    mat = pow_matrix(mat, n - m + 1);\n   \
    \ return multiply_matrix(mat, initv)[0][0];\n\n    // nth_sequence_recurrence\n\
    \    // 0-indexed\n    // a_n+k = b_0*a_0 + b_1*a_1 + ... + b_m-1*a_n+m-1\n  \
    \  // coefficient = {b_0, b_1, ... , b_m-1}\n    // init = {a_0, a_1, ... , a_m-1}\n\
    \n    // vector<lint> coefficient = {1, 1};\n    // vector<lint> init = {1, 1};\n\
    \    // lint constant = 0;\n    // lint n;\n    // in(n);\n    // if (n < init.size())\
    \ {\n    //     out(init[n]);\n    //     return 0;\n    // }\n    // out(nth_sequence_recurrence(coefficient,\
    \ constant, init, n));\n}\n"
  code: "#pragma once\ntemplate <class T>\nvector<vector<T>> multiply_matrix(vector<vector<T>>\
    \ &a, vector<vector<T>> &b) {\n    int n = a.size();\n    int m = b[0].size();\n\
    \    vector<vector<T>> ret(n, vector<T>(m));\n    for (int i = 0; i < n; i++)\
    \ {\n        for (int j = 0; j < m; j++) {\n            for (int k = 0; k < b.size();\
    \ k++) {\n                ret[i][j] += (a[i][k] * b[k][j]);\n            }\n \
    \       }\n    }\n\n    return ret;\n}\n\ntemplate <class T>\nvector<vector<T>>\
    \ pow_matrix(vector<vector<T>> a, long long n) {\n    vector<vector<T>> ret(a.size(),\
    \ vector<T>(a[0].size()));\n    for (int i = 0; i < ret.size(); i++) {\n     \
    \   ret[i][i] = 1;\n    }\n\n    while (n > 0) {\n        if (n & 1) ret = multiply_matrix(ret,\
    \ a);\n        a = multiply_matrix(a, a);\n        n >>= 1;\n    }\n\n    return\
    \ ret;\n}\n\ntemplate <class T>\nT nth_sequence_recurrence(vector<T> coefficient,\
    \ T constant, vector<T> init, long long n) {\n    int m = coefficient.size();\n\
    \    vector<vector<T>> mat(m + 1, vector<T>(m + 1));\n    vector<vector<T>> initv(m\
    \ + 1, vector<T>(1));\n    reverse(init.begin(), init.end());\n    for (int i\
    \ = 0; i < m; i++) {\n        initv[i][0] = init[i];\n    }\n    initv[m][0] =\
    \ 1;\n    for (int i = 0; i < m; i++) {\n        mat[0][i] = coefficient[m - 1\
    \ - i];\n    }\n    for (int i = 1; i < m; i++) {\n        mat[i][i - 1] = 1;\n\
    \    }\n    mat[0][m] = constant;\n    mat[m][m] = 1;\n    mat = pow_matrix(mat,\
    \ n - m + 1);\n    return multiply_matrix(mat, initv)[0][0];\n\n    // nth_sequence_recurrence\n\
    \    // 0-indexed\n    // a_n+k = b_0*a_0 + b_1*a_1 + ... + b_m-1*a_n+m-1\n  \
    \  // coefficient = {b_0, b_1, ... , b_m-1}\n    // init = {a_0, a_1, ... , a_m-1}\n\
    \n    // vector<lint> coefficient = {1, 1};\n    // vector<lint> init = {1, 1};\n\
    \    // lint constant = 0;\n    // lint n;\n    // in(n);\n    // if (n < init.size())\
    \ {\n    //     out(init[n]);\n    //     return 0;\n    // }\n    // out(nth_sequence_recurrence(coefficient,\
    \ constant, init, n));\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/NthTermOfLinearRecurrenceMatPow.hpp
  requiredBy: []
  timestamp: '2024-08-24 16:53:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/NthTermOfLinearRecurrenceMatPow.hpp
layout: document
title: Nth term of linear recurrence (Matrix Power)
---

## 概要

todo

## 計算量

