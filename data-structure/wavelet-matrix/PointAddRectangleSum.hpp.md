---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp
    title: Wavelet Matrix (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp\"\
    \n\ntemplate <class T>\nclass BitVector {\n   private:\n    unsigned n, cur, p;\n\
    \    vector<unsigned> acc, bit;\n    fenwick_tree<T> seg;\n    vector<bool> wnonzero;\n\
    \n   public:\n    BitVector() {\n    }\n\n    BitVector(vector<bool> &b) {\n \
    \       cur = 0;\n        n = b.size();\n        acc.resize((n >> 5) + 2, 0);\n\
    \        bit.resize((n >> 5) + 2, 0);\n        for (int i = 0; i < n; i++) {\n\
    \            if (!(i & 31)) {\n                cur++;\n                acc[cur]\
    \ = acc[cur - 1];\n            }\n            if (b[i]) {\n                acc[cur]\
    \ += int(b[i]);\n                bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n\
    \            }\n        }\n    }\n\n    inline void ft_set(const vector<T> &v)\
    \ {\n        seg = fenwick_tree<T>(v.size());\n        wnonzero.assign(v.size(),\
    \ 0);\n        for (int i = 0; i < v.size(); i++) {\n            if (v[i] != 0)\
    \ {\n                seg.add(i, v[i]);\n                wnonzero[i] = 1;\n   \
    \         }\n        }\n    }\n\n    inline void val_set(unsigned pos, T x) {\n\
    \        if (wnonzero[pos]) {\n            seg.add(pos, x - val_get(pos));\n \
    \       } else {\n            seg.add(pos, x);\n            wnonzero[pos] = 1;\n\
    \        }\n    }\n\n    inline T val_get(unsigned pos) {\n        return seg.sum(pos,\
    \ pos + 1);\n    }\n\n    inline unsigned rank(unsigned k) {\n        if (!(k\
    \ & 31)) return acc[k >> 5];\n        return acc[k >> 5] + __builtin_popcount(bit[k\
    \ >> 5] >> (32 - (k & 31)));\n    }\n\n    inline unsigned rank0(unsigned k) {\n\
    \        return k - rank(k);\n    }\n\n    inline T rank_sum(unsigned l, unsigned\
    \ r) {\n        return seg.sum(l, r);\n    }\n\n    inline bool access(unsigned\
    \ k) {\n        return (rank(k + 1) - rank(k)) == 1;\n    }\n};\n\ntemplate <class\
    \ T>\nclass WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned bitsize,\
    \ logn;\n    vector<BitVector<T>> b;\n    vector<unsigned> zero;\n    vector<unsigned>\
    \ index;\n    vector<T> cmp;\n    vector<T> px;\n    T MI, MA;\n\n    inline unsigned\
    \ compress(const T &x) {\n        return lower_bound(cmp.begin(), cmp.end(), x)\
    \ - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n    WaveletMatrix() {}\n    WaveletMatrix(vector<T> v) {\n        MI =\
    \ numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n        n\
    \ = v.size();\n        index.resize(n);\n        iota(index.begin(), index.end(),\
    \ 0);\n        logn = bit_width(n);\n        cmp = v;\n        sort(cmp.begin(),\
    \ cmp.end());\n        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n\
    \        vector<unsigned> compressed(n);\n        vector<T> tmp(n);\n        vector<unsigned>\
    \ tmpc(n);\n        unsigned size_mx = v.size();\n        for (unsigned i = 0;\
    \ i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        vector<bool>\
    \ bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U\
    \ << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n    \
    \            tmp[j] = v[j];\n                tmpc[j] = compressed[j];\n      \
    \      }\n            b[i] = BitVector<T>(bit);\n            b[i].ft_set(v);\n\
    \            int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n  \
    \              if (!bit[j]) {\n                    v[cur] = tmp[j];\n        \
    \            compressed[cur] = tmpc[j];\n                    cur++;\n        \
    \        }\n            }\n            for (unsigned j = 0; j < n; j++) {\n  \
    \              if (bit[j]) {\n                    v[cur] = tmp[j];\n         \
    \           compressed[cur] = tmpc[j];\n                    cur++;\n         \
    \       }\n            }\n        }\n\n        b[bitsize].ft_set(v);\n    }\n\n\
    \    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {\n        n = x.size();\n\
    \        px.resize(n);\n        index.resize(n);\n        vector<tuple<T, T, T,\
    \ int>> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i] = {x[i],\
    \ y[i], w[i], i};\n        }\n        sort(v.begin(), v.end());\n        for (int\
    \ i = 0; i < n; i++) {\n            px[i] = std::get<0>(v[i]);\n            y[i]\
    \ = std::get<1>(v[i]);\n            w[i] = std::get<2>(v[i]);\n            index[std::get<3>(v[i])]\
    \ = i;\n        }\n        vector<unsigned> compressed(n);\n        cmp.resize(y.size());\n\
    \        cmp = y;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        vector<unsigned> tmpc(n);\n        vector<T>\
    \ tmp(n);\n        unsigned size_mx = y.size();\n        for (unsigned i = 0;\
    \ i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        vector<bool>\
    \ bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U\
    \ << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n    \
    \            tmp[j] = w[j];\n                tmpc[j] = compressed[j];\n      \
    \      }\n            b[i] = BitVector<T>(bit);\n            b[i].ft_set(w);\n\
    \            int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n  \
    \              if (!bit[j]) {\n                    w[cur] = tmp[j];\n        \
    \            compressed[cur] = tmpc[j];\n                    cur++;\n        \
    \        }\n            }\n            for (unsigned j = 0; j < n; j++) {\n  \
    \              if (bit[j]) {\n                    w[cur] = tmp[j];\n         \
    \           compressed[cur] = tmpc[j];\n                    cur++;\n         \
    \       }\n            }\n        }\n\n        b[bitsize].ft_set(w);\n    }\n\n\
    \    // get v[k]\n    T access(unsigned k) {\n        unsigned res = 0;\n    \
    \    unsigned cur = k;\n        for (unsigned i = 0; i < bitsize; i++) {\n   \
    \         if (b[i].access(cur)) {\n                res |= (1U << (bitsize - i\
    \ - 1));\n                cur = zero[i] + b[i].rank(cur);\n            } else\
    \ {\n                cur -= b[i].rank(cur);\n            }\n        }\n      \
    \  return cmp[res];\n    }\n\n    void set(int p, T x) {\n        unsigned cur\
    \ = index[p];\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i].val_set(cur,\
    \ x);\n            if (b[i].access(cur)) {\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        b[bitsize].val_set(cur, x);\n    }\n\n    T get(int p) {\n\
    \        unsigned cur = index[p];\n        return b[0];\n    }\n\n    // v[l,r)\
    \ \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\
    \u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned k) {\n     \
    \   unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n    \
    \        unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned num0\
    \ = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL <<\
    \ (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n         \
    \       r = zero[i] + b[i].rank(r);\n                k -= num0;\n            }\
    \ else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\
    \u5165\u308B\u5024\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n    T range_sum(int vl,\
    \ int vr, T mink, T maxk) {\n        int D = compress(mink);\n        int U =\
    \ compress(maxk);\n        T res = 0;\n        auto dfs = [&](auto &rec, int d,\
    \ int L, int R, int A, int B) -> void {\n            if (U <= A or B <= D) return;\n\
    \            if (D <= A and B <= U) {\n                res += b[d].rank_sum(L,\
    \ R);\n                return;\n            }\n            if (d == bitsize) {\n\
    \                if (D <= A and A < U) {\n                    res += b[bitsize].rank_sum(L,\
    \ R);\n                }\n                return;\n            }\n           \
    \ int C = (A + B) / 2;\n            int rank0_l = L - b[d].rank(L);\n        \
    \    int rank0_r = R - b[d].rank(R);\n            int rank1_l = b[d].rank(L) +\
    \ zero[d];\n            int rank1_r = b[d].rank(R) + zero[d];\n\n            rec(rec,\
    \ d + 1, rank0_l, rank0_r, A, C);\n            rec(rec, d + 1, rank1_l, rank1_r,\
    \ C, B);\n        };\n        dfs(dfs, 0, vl, vr, 0, 1 << bitsize);\n        return\
    \ res;\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\
    \u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n    T prev_value(unsigned l, unsigned\
    \ r, T val) {\n        int num = range_freq(l, r, MI, val);\n        if (num ==\
    \ 0) {\n            return MA;\n        } else {\n            return kth_smallest(l,\
    \ r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u4EE5\u4E0A\
    \u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n    T next_value(unsigned l,\
    \ unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n       \
    \ if (num == r - l) {\n            return MI;\n        } else {\n            return\
    \ kth_smallest(l, r, num + 1);\n        }\n    }\n\n    // x\u5EA7\u6A19\u304C\
    [l,r) \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\u7DCF\
    \u7A4D\u3092\u8FD4\u3059\n    T rectangle_sum(T l, T r, T d, T u) {\n        unsigned\
    \ cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));\n        unsigned\
    \ cr = distance(px.begin(), lower_bound(px.begin(), px.end(), r));\n        return\
    \ range_sum(cl, cr, d, u);\n    }\n};\n#line 2 \"data-structure/wavelet-matrix/PointAddRectangleSum.hpp\"\
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
  code: "#include \"WaveletMatrixBinaryIndexedTree.hpp\"\ntemplate <class S>\nclass\
    \ PointAddRectangleSum {\n   private:\n    const int RESERVE = 700000;\n    const\
    \ int QSIZE = 700000;\n    WaveletMatrix<S> wm;\n    vector<S> x, y, w;\n    vector<vector<S>>\
    \ q;\n    int add_query = 0;\n    int output_query = 0;\n    int setidx;\n\n \
    \  public:\n    PointAddRectangleSum() {\n        x.reserve(RESERVE);\n      \
    \  y.reserve(RESERVE);\n        w.reserve(RESERVE);\n        q.resize(QSIZE);\n\
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
  path: data-structure/wavelet-matrix/PointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2024-11-16 20:46:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/PointAddRectangleSum.hpp
layout: document
title: Point Add Rectangle Sum
---

## 概要

todo

## 計算量
todo