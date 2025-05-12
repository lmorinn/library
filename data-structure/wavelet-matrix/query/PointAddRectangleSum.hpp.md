---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp
    title: Wavelet Matrix (Binary Indexed Tree)
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/query/RectangleAddPointGet.hpp
    title: data-structure/wavelet-matrix/query/RectangleAddPointGet.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp\"\
    \nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned>\
    \ bit, sum;\n\n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n\
    \    blocksize = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class S, class T>\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned\
    \ bitsize;\n  vector<BitVector> b;\n  vector<fenwick_tree<S>> fen;\n  vector<unsigned>\
    \ zero;\n  vector<T> cmp;\n  T MI, MA;\n\n  inline unsigned compress(const T &x)\
    \ {\n    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n  }\n\n\
    \ public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix()\
    \ {}\n  WaveletMatrix(vector<T> v) {\n    MI = numeric_limits<T>::min();\n   \
    \ MA = numeric_limits<T>::max();\n    n = v.size();\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ vector<T> tmp(n);\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n  \
    \  for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize + 1);\n    fen.resize(bitsize + 1);\n    zero.resize(bitsize,\
    \ 0);\n    int cur = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      b[i]\
    \ = BitVector(n + 1);\n      fen[i] = fenwick_tree<T>(n);\n      cur = 0;\n  \
    \    for (unsigned j = 0; j < n; j++) {\n        fen[i].add(j, v[j]);\n      \
    \  if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          tmp[cur] = v[j];\n          cur++;\n        }\n      }\n      b[i].build();\n\
    \      for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = v[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ v);\n    }\n    b[bitsize] = BitVector(n + 1);\n    fen[bitsize] = fenwick_tree<T>(n);\n\
    \    for (unsigned i = 0; i < n; i++) {\n      fen[bitsize].add(i, v[i]);\n  \
    \  }\n  }\n\n  WaveletMatrix(vector<T> v, vector<S> w) {\n    MI = numeric_limits<T>::min();\n\
    \    MA = numeric_limits<T>::max();\n    n = v.size();\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ vector<S> tmp(n);\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n  \
    \  for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize + 1);\n    fen.resize(bitsize + 1);\n    zero.resize(bitsize,\
    \ 0);\n    int cur = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      b[i]\
    \ = BitVector(n + 1);\n      fen[i] = fenwick_tree<S>(n);\n      cur = 0;\n  \
    \    for (unsigned j = 0; j < n; j++) {\n        fen[i].add(j, w[j]);\n      \
    \  if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          tmp[cur] = w[j];\n          cur++;\n        }\n      }\n      b[i].build();\n\
    \      for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = w[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ w);\n    }\n    b[bitsize] = BitVector(n + 1);\n    fen[bitsize] = fenwick_tree<S>(n);\n\
    \    for (unsigned i = 0; i < n; i++) {\n      fen[bitsize].add(i, w[i]);\n  \
    \  }\n  }\n\n  void set(int p, S x) {\n    unsigned cur = p;\n    S before = fen[0].get(p);\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      fen[i].add(cur, x - before);\n\
    \      if (b[i].access(cur)) {\n        cur = zero[i] + b[i].rank(cur);\n    \
    \  } else {\n        cur -= b[i].rank(cur);\n      }\n    }\n    fen[bitsize].add(cur,\
    \ x - before);\n  }\n\n  void add(int p, S x) {\n    unsigned cur = p;\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      fen[i].add(cur, x);\n      if (b[i].access(cur))\
    \ {\n        cur = zero[i] + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n\
    \      }\n    }\n    fen[bitsize].add(cur, x);\n  }\n\n  S get(int p) {\n    return\
    \ fen[0].get(p);\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\
    \u308B\u5024\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  S range_sum(int vl, int vr,\
    \ T mink, T maxk) {\n    int D = compress(mink);\n    int U = compress(maxk);\n\
    \    S res = 0;\n    auto dfs = [&](auto &rec, int d, int L, int R, int A, int\
    \ B) -> void {\n      if (U <= A or B <= D) return;\n      if (D <= A and B <=\
    \ U) {\n        res += fen[d].sum(L, R);\n        return;\n      }\n      if (d\
    \ == bitsize) {\n        if (D <= A and A < U) {\n          res += fen[bitsize].sum(L,\
    \ R);\n        }\n        return;\n      }\n      int C = (A + B) >> 1;\n    \
    \  int rank0_l = L - b[d].rank(L);\n      int rank0_r = R - b[d].rank(R);\n  \
    \    int rank1_l = b[d].rank(L) + zero[d];\n      int rank1_r = b[d].rank(R) +\
    \ zero[d];\n\n      rec(rec, d + 1, rank0_l, rank0_r, A, C);\n      rec(rec, d\
    \ + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs, 0, vl, vr, 0, 1 << bitsize);\n\
    \    return res;\n  }\n};\n#line 2 \"data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp\"\
    \ntemplate <class S>\nclass PointAddRectangleSum {\n   private:\n    const int\
    \ RESERVE = 700000;\n    const int QSIZE = 700000;\n    WaveletMatrix<S> wm;\n\
    \    vector<S> x, y, w;\n    vector<vector<S>> q;\n    int add_query = 0;\n  \
    \  int output_query = 0;\n    int setidx;\n\n   public:\n    PointAddRectangleSum()\
    \ {\n        x.reserve(RESERVE);\n        y.reserve(RESERVE);\n        w.reserve(RESERVE);\n\
    \        q.resize(QSIZE);\n        for (int i = 0; i < QSIZE; i++) {\n       \
    \     q[i].assign(5, 0);\n        }\n        setidx = 0;\n    }\n\n    PointAddRectangleSum(int\
    \ query) {\n        q = vector<vector<S>>(query, vector<S>(5));\n        setidx\
    \ = 0;\n    }\n\n    PointAddRectangleSum(const vector<S> &vx, const vector<S>\
    \ &vy, const vector<S> &vw, int query) {\n        q = vector<vector<S>>(query,\
    \ vector<S>(5));\n        x = vx;\n        y = vy;\n        w = vw;\n        setidx\
    \ = x.size();\n    }\n\n    void add(S px, S py, S weight) {\n        int cur\
    \ = add_query + output_query;\n        q[cur][0] = 0;\n        q[cur][1] = px;\n\
    \        q[cur][2] = py;\n        q[cur][3] = weight;\n        q[cur][4] = setidx++;\n\
    \        x.emplace_back(px);\n        y.emplace_back(py);\n        w.emplace_back(0);\n\
    \        add_query++;\n    }\n\n    void rectangle_sum(S x1, S y1, S x2, S y2)\
    \ {\n        int cur = add_query + output_query;\n        q[cur][0] = 1;\n   \
    \     q[cur][1] = x1;\n        q[cur][2] = y1;\n        q[cur][3] = x2;\n    \
    \    q[cur][4] = y2;\n        output_query++;\n    }\n\n    vector<S> build()\
    \ {\n        wm = WaveletMatrix<S>(x, y, w);\n        vector<S> ret(output_query);\n\
    \        int idx = 0;\n        for (int i = 0; i < output_query + add_query; i++)\
    \ {\n            S com = q[i][0];\n            if (com == 0) {\n             \
    \   wm.set(q[i][4], q[i][3]);\n            } else {\n                ret[idx]\
    \ = (wm.rectangle_sum(q[i][1], q[i][3], q[i][2], q[i][4]));\n                idx++;\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "#include \"../WaveletMatrixBinaryIndexedTree.hpp\"\ntemplate <class S>\n\
    class PointAddRectangleSum {\n   private:\n    const int RESERVE = 700000;\n \
    \   const int QSIZE = 700000;\n    WaveletMatrix<S> wm;\n    vector<S> x, y, w;\n\
    \    vector<vector<S>> q;\n    int add_query = 0;\n    int output_query = 0;\n\
    \    int setidx;\n\n   public:\n    PointAddRectangleSum() {\n        x.reserve(RESERVE);\n\
    \        y.reserve(RESERVE);\n        w.reserve(RESERVE);\n        q.resize(QSIZE);\n\
    \        for (int i = 0; i < QSIZE; i++) {\n            q[i].assign(5, 0);\n \
    \       }\n        setidx = 0;\n    }\n\n    PointAddRectangleSum(int query) {\n\
    \        q = vector<vector<S>>(query, vector<S>(5));\n        setidx = 0;\n  \
    \  }\n\n    PointAddRectangleSum(const vector<S> &vx, const vector<S> &vy, const\
    \ vector<S> &vw, int query) {\n        q = vector<vector<S>>(query, vector<S>(5));\n\
    \        x = vx;\n        y = vy;\n        w = vw;\n        setidx = x.size();\n\
    \    }\n\n    void add(S px, S py, S weight) {\n        int cur = add_query +\
    \ output_query;\n        q[cur][0] = 0;\n        q[cur][1] = px;\n        q[cur][2]\
    \ = py;\n        q[cur][3] = weight;\n        q[cur][4] = setidx++;\n        x.emplace_back(px);\n\
    \        y.emplace_back(py);\n        w.emplace_back(0);\n        add_query++;\n\
    \    }\n\n    void rectangle_sum(S x1, S y1, S x2, S y2) {\n        int cur =\
    \ add_query + output_query;\n        q[cur][0] = 1;\n        q[cur][1] = x1;\n\
    \        q[cur][2] = y1;\n        q[cur][3] = x2;\n        q[cur][4] = y2;\n \
    \       output_query++;\n    }\n\n    vector<S> build() {\n        wm = WaveletMatrix<S>(x,\
    \ y, w);\n        vector<S> ret(output_query);\n        int idx = 0;\n       \
    \ for (int i = 0; i < output_query + add_query; i++) {\n            S com = q[i][0];\n\
    \            if (com == 0) {\n                wm.set(q[i][4], q[i][3]);\n    \
    \        } else {\n                ret[idx] = (wm.rectangle_sum(q[i][1], q[i][3],\
    \ q[i][2], q[i][4]));\n                idx++;\n            }\n        }\n    \
    \    return ret;\n    }\n};"
  dependsOn:
  - data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp
  requiredBy:
  - data-structure/wavelet-matrix/query/RectangleAddPointGet.hpp
  timestamp: '2025-05-12 11:31:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp
layout: document
redirect_from:
- /library/data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp
- /library/data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp.html
title: data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp
---
