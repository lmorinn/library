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
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp\"\
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
    \ c * yr;\n      resp += d;\n    }\n    return resp - resn;\n  }\n};\n"
  code: "\nusing S = tuple<mint, mint, mint, mint>;\n\nS op(const S &a, const S &b)\
    \ {\n  auto &[a1, a2, a3, a4] = a;\n  auto &[b1, b2, b3, b4] = b;\n  return {a1\
    \ + b1, a2 + b2, a3 + b3, a4 + b4};\n}\n\nvoid print(const S &a) {\n  auto &[a1,\
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
    \ c * yr;\n      resp += d;\n    }\n    return resp - resn;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2024-11-26 19:17:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp
layout: document
title: Rectangle Add Rectangle Sum
---

## 概要

todo

## 計算量
todo