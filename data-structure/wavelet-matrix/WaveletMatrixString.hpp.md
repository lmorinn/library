---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/FMindex.hpp
    title: FM-index
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
    title: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixString.hpp\"\n\
    template <class T>\nclass BitVector {\n   private:\n    unsigned n, cur, p;\n\
    \    vector<unsigned> acc, bit;\n\n   public:\n    BitVector() {\n    }\n\n  \
    \  BitVector(vector<bool> &b) {\n        cur = 0;\n        n = b.size();\n   \
    \     acc.resize((n >> 5) + 2, 0);\n        bit.resize((n >> 5) + 2, 0);\n   \
    \     for (int i = 0; i < n; i++) {\n            if (!(i & 31)) {\n          \
    \      cur++;\n                acc[cur] = acc[cur - 1];\n            }\n     \
    \       if (b[i]) {\n                acc[cur] += int(b[i]);\n                bit[cur\
    \ - 1] |= (1U << (32 - (i & 31) - 1));\n            }\n        }\n    }\n\n  \
    \  inline unsigned rank(unsigned k) {\n        if (!(k & 31)) return acc[k >>\
    \ 5];\n        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k\
    \ & 31)));\n    }\n\n    inline bool access(unsigned k) {\n        return (rank(k\
    \ + 1) - rank(k)) == 1;\n    }\n};\n\nclass WaveletMatrix {\n   private:\n   \
    \ unsigned n;\n    unsigned bitsize;\n    vector<BitVector<unsigned char>> b;\n\
    \    vector<unsigned> zero;\n    vector<int> stInd;\n    unsigned char MI, MA;\n\
    \n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\
    \u8FD4\u3059\n    unsigned rank_less(unsigned l, unsigned r, unsigned char k)\
    \ {\n        unsigned less = 0;\n        for (unsigned i = 0; i < bitsize and\
    \ l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n        \
    \    const unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l\
    \ = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n        \
    \    if (k & (1U << (bitsize - i - 1))) {\n                less += (rank0_r -\
    \ rank0_l);\n                l = zero[i] + rank1_l;\n                r = zero[i]\
    \ + rank1_r;\n            } else {\n                l = rank0_l;\n           \
    \     r = rank0_r;\n            }\n        }\n        return less;\n    }\n\n\
    \   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix()\
    \ {}\n    WaveletMatrix(string v) {\n        MI = numeric_limits<unsigned char>::min();\n\
    \        MA = numeric_limits<unsigned char>::max();\n        n = v.size();\n\n\
    \        vector<unsigned> tmp(n);\n        stInd.resize(256, -1);\n        bitsize\
    \ = 8;\n        b.resize(bitsize);\n        zero.resize(bitsize, 0);\n       \
    \ vector<bool> bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            for (unsigned j = 0; j < n; j++) {\n                bit[j] = v[j]\
    \ & (1U << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n\
    \                tmp[j] = v[j];\n            }\n            b[i] = BitVector<unsigned\
    \ char>(bit);\n            int cur = 0;\n            for (unsigned j = 0; j <\
    \ n; j++) {\n                if (!bit[j]) {\n                    v[cur] = tmp[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        v[cur] = tmp[j];\n                    cur++;\n                }\n   \
    \         }\n        }\n\n        for (unsigned i = 0; i < n; i++) {\n       \
    \     if (stInd[v[i]] == -1) {\n                stInd[v[i]] = i;\n           \
    \ }\n        }\n    }\n\n    // get v[k]\n    unsigned char access(unsigned k)\
    \ {\n        unsigned char res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return res;\n    }\n\n    // v[0,k) \u4E2D\u3067\u306Ec\u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned k, unsigned\
    \ char c) {\n        unsigned cur = k;\n        if (stInd[c] == -1) {\n      \
    \      return 0;\n        }\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            if (c & (1U << (bitsize - i - 1))) {\n                cur = zero[i]\
    \ + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cur - stInd[c];\n    }\n\n    // v[l,r)\
    \ \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\
    \u8FD4\u3059\n    unsigned char kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned char res = 0;\n        for (unsigned i = 0; i < bitsize;\
    \ i++) {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n         \
    \   unsigned num0 = r - l - num1;\n            if (num0 < k) {\n             \
    \   res |= (1ULL << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n\
    \                r = zero[i] + b[i].rank(r);\n                k -= num0;\n   \
    \         } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return res;\n    }\n\n    // v[l,r) \u306E\u4E2D\
    \u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n\
    \    unsigned char kth_largest(unsigned l, unsigned r, unsigned k) {\n       \
    \ return kth_smallest(l, r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    unsigned range_freq(unsigned l, unsigned r, unsigned char mink, unsigned\
    \ char maxk) {\n        if (mink == 0) {\n            return rank_less(l, r, maxk);\n\
    \        }\n        return rank_less(l, r, maxk) - rank_less(l, r, mink);\n  \
    \  }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\
    \u5927\u306E\u5024\u3092\u8FD4\u3059\n    unsigned char prev_value(unsigned l,\
    \ unsigned r, unsigned char val) {\n        int num = range_freq(l, r, MI, val);\n\
    \        if (num == 0) {\n            return MA;\n        } else {\n         \
    \   return kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\
    \u3067val\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\
    \n    unsigned char next_value(unsigned l, unsigned r, unsigned char val) {\n\
    \        int num = range_freq(l, r, MI, val + 1);\n        if (num == r - l) {\n\
    \            return MI;\n        } else {\n            return kth_smallest(l,\
    \ r, num + 1);\n        }\n    }\n};\n"
  code: "template <class T>\nclass BitVector {\n   private:\n    unsigned n, cur,\
    \ p;\n    vector<unsigned> acc, bit;\n\n   public:\n    BitVector() {\n    }\n\
    \n    BitVector(vector<bool> &b) {\n        cur = 0;\n        n = b.size();\n\
    \        acc.resize((n >> 5) + 2, 0);\n        bit.resize((n >> 5) + 2, 0);\n\
    \        for (int i = 0; i < n; i++) {\n            if (!(i & 31)) {\n       \
    \         cur++;\n                acc[cur] = acc[cur - 1];\n            }\n  \
    \          if (b[i]) {\n                acc[cur] += int(b[i]);\n             \
    \   bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n            }\n        }\n \
    \   }\n\n    inline unsigned rank(unsigned k) {\n        if (!(k & 31)) return\
    \ acc[k >> 5];\n        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >>\
    \ (32 - (k & 31)));\n    }\n\n    inline bool access(unsigned k) {\n        return\
    \ (rank(k + 1) - rank(k)) == 1;\n    }\n};\n\nclass WaveletMatrix {\n   private:\n\
    \    unsigned n;\n    unsigned bitsize;\n    vector<BitVector<unsigned char>>\
    \ b;\n    vector<unsigned> zero;\n    vector<int> stInd;\n    unsigned char MI,\
    \ MA;\n\n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n    unsigned rank_less(unsigned l, unsigned r, unsigned\
    \ char k) {\n        unsigned less = 0;\n        for (unsigned i = 0; i < bitsize\
    \ and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n    \
    \        const unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l\
    \ = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n        \
    \    if (k & (1U << (bitsize - i - 1))) {\n                less += (rank0_r -\
    \ rank0_l);\n                l = zero[i] + rank1_l;\n                r = zero[i]\
    \ + rank1_r;\n            } else {\n                l = rank0_l;\n           \
    \     r = rank0_r;\n            }\n        }\n        return less;\n    }\n\n\
    \   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix()\
    \ {}\n    WaveletMatrix(string v) {\n        MI = numeric_limits<unsigned char>::min();\n\
    \        MA = numeric_limits<unsigned char>::max();\n        n = v.size();\n\n\
    \        vector<unsigned> tmp(n);\n        stInd.resize(256, -1);\n        bitsize\
    \ = 8;\n        b.resize(bitsize);\n        zero.resize(bitsize, 0);\n       \
    \ vector<bool> bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            for (unsigned j = 0; j < n; j++) {\n                bit[j] = v[j]\
    \ & (1U << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n\
    \                tmp[j] = v[j];\n            }\n            b[i] = BitVector<unsigned\
    \ char>(bit);\n            int cur = 0;\n            for (unsigned j = 0; j <\
    \ n; j++) {\n                if (!bit[j]) {\n                    v[cur] = tmp[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        v[cur] = tmp[j];\n                    cur++;\n                }\n   \
    \         }\n        }\n\n        for (unsigned i = 0; i < n; i++) {\n       \
    \     if (stInd[v[i]] == -1) {\n                stInd[v[i]] = i;\n           \
    \ }\n        }\n    }\n\n    // get v[k]\n    unsigned char access(unsigned k)\
    \ {\n        unsigned char res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return res;\n    }\n\n    // v[0,k) \u4E2D\u3067\u306Ec\u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned k, unsigned\
    \ char c) {\n        unsigned cur = k;\n        if (stInd[c] == -1) {\n      \
    \      return 0;\n        }\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            if (c & (1U << (bitsize - i - 1))) {\n                cur = zero[i]\
    \ + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cur - stInd[c];\n    }\n\n    // v[l,r)\
    \ \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\
    \u8FD4\u3059\n    unsigned char kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned char res = 0;\n        for (unsigned i = 0; i < bitsize;\
    \ i++) {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n         \
    \   unsigned num0 = r - l - num1;\n            if (num0 < k) {\n             \
    \   res |= (1ULL << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n\
    \                r = zero[i] + b[i].rank(r);\n                k -= num0;\n   \
    \         } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return res;\n    }\n\n    // v[l,r) \u306E\u4E2D\
    \u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n\
    \    unsigned char kth_largest(unsigned l, unsigned r, unsigned k) {\n       \
    \ return kth_smallest(l, r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    unsigned range_freq(unsigned l, unsigned r, unsigned char mink, unsigned\
    \ char maxk) {\n        if (mink == 0) {\n            return rank_less(l, r, maxk);\n\
    \        }\n        return rank_less(l, r, maxk) - rank_less(l, r, mink);\n  \
    \  }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\
    \u5927\u306E\u5024\u3092\u8FD4\u3059\n    unsigned char prev_value(unsigned l,\
    \ unsigned r, unsigned char val) {\n        int num = range_freq(l, r, MI, val);\n\
    \        if (num == 0) {\n            return MA;\n        } else {\n         \
    \   return kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\
    \u3067val\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\
    \n    unsigned char next_value(unsigned l, unsigned r, unsigned char val) {\n\
    \        int num = range_freq(l, r, MI, val + 1);\n        if (num == r - l) {\n\
    \            return MI;\n        } else {\n            return kth_smallest(l,\
    \ r, num + 1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixString.hpp
  requiredBy:
  - string/FMindex.hpp
  timestamp: '2024-09-26 13:24:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
documentation_of: data-structure/wavelet-matrix/WaveletMatrixString.hpp
layout: document
title: Wavelet Matrix (String)
---

## 概要

todo

## 計算量
todo