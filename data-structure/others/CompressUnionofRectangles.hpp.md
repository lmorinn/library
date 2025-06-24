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
  bundledCode: "#line 1 \"data-structure/others/CompressUnionofRectangles.hpp\"\n\
    class UnionofRectangles {\n private:\n  vector<lint> xl, yl, xr, yr, weight;\n\
    \  vector<lint> tx, ty;\n  vector<vector<lint>> g;\n  int n, h, w;\n\n public:\n\
    \n // \u5DE6\u4E0A\u306E\u5EA7\u6A19\u304C(xl,yl), \u53F3\u4E0B\u306E\u5EA7\u6A19\
    \u304C(xr,yr) \u3067\u91CD\u307Fw\u306E\u9577\u65B9\u5F62N\u500B\u3067\u521D\u671F\
    \u5316\n  UnionofRectangles(const vector<lint> &xl_, const vector<lint> &yl_,\
    \ const vector<lint> &xr_, const vector<lint> &yr_, const vector<lint> &w_)\n\
    \      : xl(xl_), yl(yl_), xr(xr_), yr(yr_), weight(w_) {\n    n = int(xl.size());\n\
    \    for (int i = 0; i < n; i++) {\n      tx.emplace_back(xl[i]);\n      tx.emplace_back(xr[i]);\n\
    \      tx.emplace_back(xl[i] + 1);\n      tx.emplace_back(xr[i] + 1);\n      ty.emplace_back(yl[i]);\n\
    \      ty.emplace_back(yr[i]);\n      ty.emplace_back(yl[i]) + 1;\n      ty.emplace_back(yr[i])\
    \ + 1;\n    }\n    sort(tx.begin(), tx.end());\n    sort(ty.begin(), ty.end());\n\
    \    tx.erase(unique(tx.begin(), tx.end()), tx.end());\n    ty.erase(unique(ty.begin(),\
    \ ty.end()), ty.end());\n    h = int(ty.size());\n    w = int(tx.size());\n  \
    \  g = vector<vector<lint>>(h, vector<lint>(w));\n    for (int i = 0; i < n; i++)\
    \ {\n      xl[i] = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), xl[i]));\n\
    \      xr[i] = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), xr[i]));\n\
    \      yl[i] = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), yl[i]));\n\
    \      yr[i] = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), yr[i]));\n\
    \      g[yl[i]][xl[i]] += weight[i];\n      g[yl[i]][xr[i]] -= weight[i];\n  \
    \    g[yr[i]][xl[i]] -= weight[i];\n      g[yr[i]][xr[i]] += weight[i];\n    }\n\
    \n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w - 1; j++) {\n\
    \        g[i][j + 1] += g[i][j];\n      }\n    }\n\n    for (int j = 0; j < w;\
    \ j++) {\n      for (int i = 0; i < h - 1; i++) {\n        g[i + 1][j] += g[i][j];\n\
    \      }\n    }\n  }\n\n\n  // [x1,x2) x [y1,y2) \u5185\u3067\u9577\u65B9\u5F62\
    \u306E\u91CD\u307F\u306E\u7DCF\u548C\u304CF\u3092\u6E80\u305F\u3059\u90E8\u5206\
    \u306E\u9762\u7A4D\u3092\u8FD4\u3059\n  template <auto F>\n  long long query(long\
    \ long x1, long long y1, long long x2, long long y2) {\n    long long ret = 0;\n\
    \    x1 = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), x1));\n    x2\
    \ = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), x2));\n    y1 = distance(ty.begin(),\
    \ lower_bound(ty.begin(), ty.end(), y1));\n    y2 = distance(ty.begin(), lower_bound(ty.begin(),\
    \ ty.end(), y2));\n    for (int i = y1; i < y2; i++) {\n      for (int j = x1;\
    \ j < x2; j++) {\n        if (F(g[i][j])) {\n          ret += (ty[i + 1] - ty[i])\
    \ * (tx[j + 1] - tx[j]);\n        }\n      }\n    }\n    return ret;\n  }\n};\n"
  code: "class UnionofRectangles {\n private:\n  vector<lint> xl, yl, xr, yr, weight;\n\
    \  vector<lint> tx, ty;\n  vector<vector<lint>> g;\n  int n, h, w;\n\n public:\n\
    \n // \u5DE6\u4E0A\u306E\u5EA7\u6A19\u304C(xl,yl), \u53F3\u4E0B\u306E\u5EA7\u6A19\
    \u304C(xr,yr) \u3067\u91CD\u307Fw\u306E\u9577\u65B9\u5F62N\u500B\u3067\u521D\u671F\
    \u5316\n  UnionofRectangles(const vector<lint> &xl_, const vector<lint> &yl_,\
    \ const vector<lint> &xr_, const vector<lint> &yr_, const vector<lint> &w_)\n\
    \      : xl(xl_), yl(yl_), xr(xr_), yr(yr_), weight(w_) {\n    n = int(xl.size());\n\
    \    for (int i = 0; i < n; i++) {\n      tx.emplace_back(xl[i]);\n      tx.emplace_back(xr[i]);\n\
    \      tx.emplace_back(xl[i] + 1);\n      tx.emplace_back(xr[i] + 1);\n      ty.emplace_back(yl[i]);\n\
    \      ty.emplace_back(yr[i]);\n      ty.emplace_back(yl[i]) + 1;\n      ty.emplace_back(yr[i])\
    \ + 1;\n    }\n    sort(tx.begin(), tx.end());\n    sort(ty.begin(), ty.end());\n\
    \    tx.erase(unique(tx.begin(), tx.end()), tx.end());\n    ty.erase(unique(ty.begin(),\
    \ ty.end()), ty.end());\n    h = int(ty.size());\n    w = int(tx.size());\n  \
    \  g = vector<vector<lint>>(h, vector<lint>(w));\n    for (int i = 0; i < n; i++)\
    \ {\n      xl[i] = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), xl[i]));\n\
    \      xr[i] = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), xr[i]));\n\
    \      yl[i] = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), yl[i]));\n\
    \      yr[i] = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), yr[i]));\n\
    \      g[yl[i]][xl[i]] += weight[i];\n      g[yl[i]][xr[i]] -= weight[i];\n  \
    \    g[yr[i]][xl[i]] -= weight[i];\n      g[yr[i]][xr[i]] += weight[i];\n    }\n\
    \n    for (int i = 0; i < h; i++) {\n      for (int j = 0; j < w - 1; j++) {\n\
    \        g[i][j + 1] += g[i][j];\n      }\n    }\n\n    for (int j = 0; j < w;\
    \ j++) {\n      for (int i = 0; i < h - 1; i++) {\n        g[i + 1][j] += g[i][j];\n\
    \      }\n    }\n  }\n\n\n  // [x1,x2) x [y1,y2) \u5185\u3067\u9577\u65B9\u5F62\
    \u306E\u91CD\u307F\u306E\u7DCF\u548C\u304CF\u3092\u6E80\u305F\u3059\u90E8\u5206\
    \u306E\u9762\u7A4D\u3092\u8FD4\u3059\n  template <auto F>\n  long long query(long\
    \ long x1, long long y1, long long x2, long long y2) {\n    long long ret = 0;\n\
    \    x1 = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), x1));\n    x2\
    \ = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), x2));\n    y1 = distance(ty.begin(),\
    \ lower_bound(ty.begin(), ty.end(), y1));\n    y2 = distance(ty.begin(), lower_bound(ty.begin(),\
    \ ty.end(), y2));\n    for (int i = y1; i < y2; i++) {\n      for (int j = x1;\
    \ j < x2; j++) {\n        if (F(g[i][j])) {\n          ret += (ty[i + 1] - ty[i])\
    \ * (tx[j + 1] - tx[j]);\n        }\n      }\n    }\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/CompressUnionofRectangles.hpp
  requiredBy: []
  timestamp: '2025-06-25 02:49:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/others/CompressUnionofRectangles.hpp
layout: document
title: Area of Union of Rectangles (Coordinate Compression)
---

## 概要

todo

## 計算量
todo