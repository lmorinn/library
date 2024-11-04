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
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp\"\
    \n\ntemplate <class T>\nclass BitVector {\n   private:\n    unsigned n, cur, p;\n\
    \    vector<unsigned> acc, bit;\n\n   public:\n    BitVector() {\n    }\n\n  \
    \  BitVector(vector<bool> &b) {\n        cur = 0;\n        n = b.size();\n   \
    \     acc.resize((n >> 5) + 2, 0);\n        bit.resize((n >> 5) + 2, 0);\n   \
    \     for (int i = 0; i < n; i++) {\n            if (!(i & 31)) {\n          \
    \      cur++;\n                acc[cur] = acc[cur - 1];\n            }\n     \
    \       if (b[i]) {\n                acc[cur] += int(b[i]);\n                bit[cur\
    \ - 1] |= (1U << (32 - (i & 31) - 1));\n            }\n        }\n    }\n\n  \
    \  inline unsigned rank(unsigned k) {\n        if (!(k & 31)) return acc[k >>\
    \ 5];\n        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k\
    \ & 31)));\n    }\n    inline bool access(unsigned k) {\n        return (rank(k\
    \ + 1) - rank(k)) == 1;\n    }\n};\n\ntemplate <class T>\nclass WaveletMatrix\
    \ {\n   private:\n    unsigned n;\n    unsigned bitsize;\n    vector<BitVector<T>>\
    \ b;\n    vector<unsigned> zero;\n    vector<int> stInd;\n    vector<unsigned>\
    \ compressed;\n    vector<T> cmp;\n    T MI, MA;\n\n    // v[l,r) \u306E\u4E2D\
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\n    unsigned\
    \ rank_less(unsigned l, unsigned r, T k) {\n        unsigned less = 0;\n     \
    \   for (unsigned i = 0; i < bitsize and l < r; i++) {\n            const unsigned\
    \ rank1_l = b[i].rank(l);\n            const unsigned rank1_r = b[i].rank(r);\n\
    \            const unsigned rank0_l = l - rank1_l;\n            const unsigned\
    \ rank0_r = r - rank1_r;\n            if (k & (1U << (bitsize - i - 1))) {\n \
    \               less += (rank0_r - rank0_l);\n                l = zero[i] + rank1_l;\n\
    \                r = zero[i] + rank1_r;\n            } else {\n              \
    \  l = rank0_l;\n                r = rank0_r;\n            }\n        }\n    \
    \    return less;\n    }\n\n    inline unsigned compress(const T &x) {\n     \
    \   return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n    }\n\n   public:\n\
    \    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix() {}\n \
    \   WaveletMatrix(vector<T> v) {\n        MI = numeric_limits<T>::min();\n   \
    \     MA = numeric_limits<T>::max();\n        n = v.size();\n        cmp = v;\n\
    \        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        compressed.resize(n);\n        vector<unsigned>\
    \ tmpc(n);\n        unsigned size_mx = v.size();\n        for (unsigned i = 0;\
    \ i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n            sum[i + 1] = sum[i] + v[i];\n        }\n   \
    \     stInd.resize(cmp.size() + 1, -1);\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize);\n        zero.resize(bitsize, 0);\n        vector<bool>\
    \ bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U\
    \ << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n    \
    \            tmpc[j] = compressed[j];\n            }\n            b[i] = BitVector<T>(bit);\n\
    \            int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n  \
    \              if (!bit[j]) {\n                    compressed[cur] = tmpc[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        compressed[cur] = tmpc[j];\n                    cur++;\n            \
    \    }\n            }\n        }\n\n        for (unsigned i = 0; i < n; i++) {\n\
    \            if (stInd[compressed[i]] == -1) {\n                stInd[compressed[i]]\
    \ = i;\n            }\n        }\n    }\n\n    // get v[k]\n    T access(unsigned\
    \ k) {\n        unsigned res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return cmp[res];\n    }\n\n    // v[0,k) \u4E2D\u3067\u306E\
    c\u306E\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned\
    \ k, T c) {\n        c = compress(c);\n        unsigned cur = k;\n        if (stInd[c]\
    \ == -1) {\n            return 0;\n        }\n        for (unsigned i = 0; i <\
    \ bitsize; i++) {\n            if (c & (1U << (bitsize - i - 1))) {\n        \
    \        cur = zero[i] + b[i].rank(cur);\n            } else {\n             \
    \   cur -= b[i].rank(cur);\n            }\n        }\n        return cur - stInd[c];\n\
    \    }\n\n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\
    \u3044\u5024\u3092\u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL\
    \ << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n      \
    \          r = zero[i] + b[i].rank(r);\n                k -= num0;\n         \
    \   } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\
    \u5165\u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n    unsigned range_freq(unsigned\
    \ l, unsigned r, T mink, T maxk) {\n        mink = compress(mink);\n        maxk\
    \ = compress(maxk);\n        if (mink == 0) {\n            return rank_less(l,\
    \ r, maxk);\n        }\n        return rank_less(l, r, maxk) - rank_less(l, r,\
    \ mink);\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\
    \u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n    T prev_value(unsigned l, unsigned\
    \ r, T val) {\n        int num = range_freq(l, r, MI, val);\n        if (num ==\
    \ 0) {\n            return MA;\n        } else {\n            return kth_smallest(l,\
    \ r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u4EE5\u4E0A\
    \u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n    T next_value(unsigned l,\
    \ unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n       \
    \ if (num == r - l) {\n            return MI;\n        } else {\n            return\
    \ kth_smallest(l, r, num + 1);\n        }\n    }\n};\n"
  code: "\ntemplate <class T>\nclass BitVector {\n   private:\n    unsigned n, cur,\
    \ p;\n    vector<unsigned> acc, bit;\n\n   public:\n    BitVector() {\n    }\n\
    \n    BitVector(vector<bool> &b) {\n        cur = 0;\n        n = b.size();\n\
    \        acc.resize((n >> 5) + 2, 0);\n        bit.resize((n >> 5) + 2, 0);\n\
    \        for (int i = 0; i < n; i++) {\n            if (!(i & 31)) {\n       \
    \         cur++;\n                acc[cur] = acc[cur - 1];\n            }\n  \
    \          if (b[i]) {\n                acc[cur] += int(b[i]);\n             \
    \   bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n            }\n        }\n \
    \   }\n\n    inline unsigned rank(unsigned k) {\n        if (!(k & 31)) return\
    \ acc[k >> 5];\n        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >>\
    \ (32 - (k & 31)));\n    }\n    inline bool access(unsigned k) {\n        return\
    \ (rank(k + 1) - rank(k)) == 1;\n    }\n};\n\ntemplate <class T>\nclass WaveletMatrix\
    \ {\n   private:\n    unsigned n;\n    unsigned bitsize;\n    vector<BitVector<T>>\
    \ b;\n    vector<unsigned> zero;\n    vector<int> stInd;\n    vector<unsigned>\
    \ compressed;\n    vector<T> cmp;\n    T MI, MA;\n\n    // v[l,r) \u306E\u4E2D\
    \u3067\u5024\u304Ck\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\n    unsigned\
    \ rank_less(unsigned l, unsigned r, T k) {\n        unsigned less = 0;\n     \
    \   for (unsigned i = 0; i < bitsize and l < r; i++) {\n            const unsigned\
    \ rank1_l = b[i].rank(l);\n            const unsigned rank1_r = b[i].rank(r);\n\
    \            const unsigned rank0_l = l - rank1_l;\n            const unsigned\
    \ rank0_r = r - rank1_r;\n            if (k & (1U << (bitsize - i - 1))) {\n \
    \               less += (rank0_r - rank0_l);\n                l = zero[i] + rank1_l;\n\
    \                r = zero[i] + rank1_r;\n            } else {\n              \
    \  l = rank0_l;\n                r = rank0_r;\n            }\n        }\n    \
    \    return less;\n    }\n\n    inline unsigned compress(const T &x) {\n     \
    \   return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n    }\n\n   public:\n\
    \    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix() {}\n \
    \   WaveletMatrix(vector<T> v) {\n        MI = numeric_limits<T>::min();\n   \
    \     MA = numeric_limits<T>::max();\n        n = v.size();\n        cmp = v;\n\
    \        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        compressed.resize(n);\n        vector<unsigned>\
    \ tmpc(n);\n        unsigned size_mx = v.size();\n        for (unsigned i = 0;\
    \ i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n            sum[i + 1] = sum[i] + v[i];\n        }\n   \
    \     stInd.resize(cmp.size() + 1, -1);\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize);\n        zero.resize(bitsize, 0);\n        vector<bool>\
    \ bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U\
    \ << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n    \
    \            tmpc[j] = compressed[j];\n            }\n            b[i] = BitVector<T>(bit);\n\
    \            int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n  \
    \              if (!bit[j]) {\n                    compressed[cur] = tmpc[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        compressed[cur] = tmpc[j];\n                    cur++;\n            \
    \    }\n            }\n        }\n\n        for (unsigned i = 0; i < n; i++) {\n\
    \            if (stInd[compressed[i]] == -1) {\n                stInd[compressed[i]]\
    \ = i;\n            }\n        }\n    }\n\n    // get v[k]\n    T access(unsigned\
    \ k) {\n        unsigned res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return cmp[res];\n    }\n\n    // v[0,k) \u4E2D\u3067\u306E\
    c\u306E\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned\
    \ k, T c) {\n        c = compress(c);\n        unsigned cur = k;\n        if (stInd[c]\
    \ == -1) {\n            return 0;\n        }\n        for (unsigned i = 0; i <\
    \ bitsize; i++) {\n            if (c & (1U << (bitsize - i - 1))) {\n        \
    \        cur = zero[i] + b[i].rank(cur);\n            } else {\n             \
    \   cur -= b[i].rank(cur);\n            }\n        }\n        return cur - stInd[c];\n\
    \    }\n\n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\
    \u3044\u5024\u3092\u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL\
    \ << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n      \
    \          r = zero[i] + b[i].rank(r);\n                k -= num0;\n         \
    \   } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\
    \u5165\u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n    unsigned range_freq(unsigned\
    \ l, unsigned r, T mink, T maxk) {\n        mink = compress(mink);\n        maxk\
    \ = compress(maxk);\n        if (mink == 0) {\n            return rank_less(l,\
    \ r, maxk);\n        }\n        return rank_less(l, r, maxk) - rank_less(l, r,\
    \ mink);\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\
    \u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n    T prev_value(unsigned l, unsigned\
    \ r, T val) {\n        int num = range_freq(l, r, MI, val);\n        if (num ==\
    \ 0) {\n            return MA;\n        } else {\n            return kth_smallest(l,\
    \ r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u4EE5\u4E0A\
    \u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n    T next_value(unsigned l,\
    \ unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n       \
    \ if (num == r - l) {\n            return MI;\n        } else {\n            return\
    \ kth_smallest(l, r, num + 1);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
  requiredBy: []
  timestamp: '2024-11-04 22:20:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
layout: document
title: Wavelet Matrix (Template)
---

## 概要

todo

## 計算量
todo