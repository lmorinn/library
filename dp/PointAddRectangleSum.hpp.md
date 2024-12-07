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
  bundledCode: "#line 1 \"dp/PointAddRectangleSum.hpp\"\ntemplate <class T>\nclass\
    \ PointAddRectangleSum {\n   private:\n    vector<vector<T>> sum;\n    int max_x,\
    \ max_y;\n\n   public:\n    PointAddRectangleSum(int h, int w) {\n        sum.resize(h\
    \ + 5, vector<T>(w + 5));\n        max_y = h;\n        max_x = w;\n    }\n\n \
    \   // (y, x) \u306Bv\u3092\u52A0\u7B97\u3059\u308B\n    void point_add(int y,\
    \ int x, T v) {\n        sum[y][x] += v;\n    }\n\n    // \u4E8C\u6B21\u5143\u7D2F\
    \u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\n    void build() {\n        for (int\
    \ i = 0; i < max_y + 3; i++) {\n            for (int j = 1; j < max_x + 3; j++)\
    \ {\n                sum[i][j] += sum[i][j - 1];\n            }\n        }\n\n\
    \        for (int j = 0; j < max_x + 3; j++) {\n            for (int i = 1; i\
    \ < max_y + 3; i++) {\n                sum[i][j] += sum[i - 1][j];\n         \
    \   }\n        }\n    }\n\n    T rectangle_sum(int yl, int yr, int xl, int xr)\
    \ {\n        yl = max(0, yl - 1);\n        xl = max(0, xl - 1);\n        yr =\
    \ min(max_y + 1, yr);\n        xr = min(max_x + 1, xr);\n        return sum[yr\
    \ - 1][xr - 1] + sum[yl][xl] - sum[yl][xr - 1] - sum[yr - 1][xl];\n    }\n\n \
    \   T point_get(int y, int x) {\n        return rectangle_sum(y, y + 1, x, x +\
    \ 1);\n    }\n};\n"
  code: "template <class T>\nclass PointAddRectangleSum {\n   private:\n    vector<vector<T>>\
    \ sum;\n    int max_x, max_y;\n\n   public:\n    PointAddRectangleSum(int h, int\
    \ w) {\n        sum.resize(h + 5, vector<T>(w + 5));\n        max_y = h;\n   \
    \     max_x = w;\n    }\n\n    // (y, x) \u306Bv\u3092\u52A0\u7B97\u3059\u308B\
    \n    void point_add(int y, int x, T v) {\n        sum[y][x] += v;\n    }\n\n\
    \    // \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\u3092\u69CB\u7BC9\u3059\u308B\n \
    \   void build() {\n        for (int i = 0; i < max_y + 3; i++) {\n          \
    \  for (int j = 1; j < max_x + 3; j++) {\n                sum[i][j] += sum[i][j\
    \ - 1];\n            }\n        }\n\n        for (int j = 0; j < max_x + 3; j++)\
    \ {\n            for (int i = 1; i < max_y + 3; i++) {\n                sum[i][j]\
    \ += sum[i - 1][j];\n            }\n        }\n    }\n\n    T rectangle_sum(int\
    \ yl, int yr, int xl, int xr) {\n        yl = max(0, yl - 1);\n        xl = max(0,\
    \ xl - 1);\n        yr = min(max_y + 1, yr);\n        xr = min(max_x + 1, xr);\n\
    \        return sum[yr - 1][xr - 1] + sum[yl][xl] - sum[yl][xr - 1] - sum[yr -\
    \ 1][xl];\n    }\n\n    T point_get(int y, int x) {\n        return rectangle_sum(y,\
    \ y + 1, x, x + 1);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/PointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2024-12-07 15:59:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/PointAddRectangleSum.hpp
layout: document
title: Point Add Rectantgle Sum
---

## 概要

todo

## 計算量
todo