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
  bundledCode: "#line 1 \"dp/RectangleAddPointGet.hpp\"\ntemplate <class T>\nclass\
    \ RectangleAddPointGet {\n   private:\n    vector<vector<T>> sum;\n    int max_x,\
    \ max_y;\n\n   public:\n    RectangleAddPointGet(int h, int w) {\n        sum.resize(h\
    \ + 5, vector<T>(w + 5));\n        max_y = h;\n        max_x = w;\n    }\n\n \
    \   // \u77E9\u5F62\u9818\u57DF[yl, yr) \u3001[xl, xr) \u306Bv\u3092\u52A0\u7B97\
    \u3059\u308B\n    void rectangle_add(int yl, int yr, int xl, int xr, T v) {\n\
    \        sum[yl + 1][xl + 1] += v;\n        sum[yl + 1][xr] -= v;\n        sum[yr][xl\
    \ + 1] -= v;\n        sum[yr][xr] += v;\n    }\n\n    // \u4E8C\u6B21\u5143\u7D2F\
    \u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\n    void build() {\n        for (int\
    \ i = 0; i < max_y + 3; i++) {\n            for (int j = 1; j < max_x + 3; j++)\
    \ {\n                sum[i][j] += sum[i][j - 1];\n            }\n        }\n\n\
    \        for (int j = 0; j < max_x + 3; j++) {\n            for (int i = 1; i\
    \ < max_y + 3; i++) {\n                sum[i][j] += sum[i - 1][j];\n         \
    \   }\n        }\n    }\n\n    // \u70B9(y, x)\u306E\u91CD\u307F\u3092\u8FD4\u3059\
    \n    T point_get(int y, int x) {\n        return sum[y][x];\n    }\n};\n"
  code: "template <class T>\nclass RectangleAddPointGet {\n   private:\n    vector<vector<T>>\
    \ sum;\n    int max_x, max_y;\n\n   public:\n    RectangleAddPointGet(int h, int\
    \ w) {\n        sum.resize(h + 5, vector<T>(w + 5));\n        max_y = h;\n   \
    \     max_x = w;\n    }\n\n    // \u77E9\u5F62\u9818\u57DF[yl, yr) \u3001[xl,\
    \ xr) \u306Bv\u3092\u52A0\u7B97\u3059\u308B\n    void rectangle_add(int yl, int\
    \ yr, int xl, int xr, T v) {\n        sum[yl + 1][xl + 1] += v;\n        sum[yl\
    \ + 1][xr] -= v;\n        sum[yr][xl + 1] -= v;\n        sum[yr][xr] += v;\n \
    \   }\n\n    // \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\
    \n    void build() {\n        for (int i = 0; i < max_y + 3; i++) {\n        \
    \    for (int j = 1; j < max_x + 3; j++) {\n                sum[i][j] += sum[i][j\
    \ - 1];\n            }\n        }\n\n        for (int j = 0; j < max_x + 3; j++)\
    \ {\n            for (int i = 1; i < max_y + 3; i++) {\n                sum[i][j]\
    \ += sum[i - 1][j];\n            }\n        }\n    }\n\n    // \u70B9(y, x)\u306E\
    \u91CD\u307F\u3092\u8FD4\u3059\n    T point_get(int y, int x) {\n        return\
    \ sum[y][x];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/RectangleAddPointGet.hpp
  requiredBy: []
  timestamp: '2024-12-07 15:59:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/RectangleAddPointGet.hpp
layout: document
title: Rectangle Add Point Get
---

## 概要

todo

## 計算量
todo