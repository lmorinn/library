---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/SuffixArray.hpp
    title: Suffix Array
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/LongestCommonSubstring.hpp
    title: Longest Common Substring
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LibraryChecker/string/LongestCommonSubstring.test.cpp
    title: verify/LibraryChecker/string/LongestCommonSubstring.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
    title: verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/SuffixArray.hpp\"\n\n#define tget(i) (((t)[(i) >>\
    \ 3] >> (7 - ((i) & 7))) & 1)\n\n#define tset(i, b)                          \
    \          \\\n    do {                                              \\\n    \
    \    if (b)                                        \\\n            (t)[(i) >>\
    \ 3] |= (1 << (7 - ((i) & 7)));  \\\n        else                            \
    \              \\\n            (t)[(i) >> 3] &= ~(1 << (7 - ((i) & 7))); \\\n\
    \    } while (0)\n\n#define chr(i) (cs == sizeof(int) ? ((int *)s)[i] : ((unsigned\
    \ char *)s)[i])\n#define isLMS(i) (i > 0 and tget(i) and !tget(i - 1))\n\nvoid\
    \ getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {\n \
    \   int sum = 0;\n    for (int i = 0; i <= K; i++) {\n        bkt[i] = 0;\n  \
    \  }\n    for (int i = 0; i < n; i++) {\n        bkt[chr(i)]++;\n    }\n    for\
    \ (int i = 0; i <= K; i++) {\n        sum += bkt[i];\n        bkt[i] = end ? sum\
    \ : sum - bkt[i];\n    }\n}\n\nvoid induceSAl(unsigned char *t, int *SA, unsigned\
    \ char *s, int *bkt, int n, int K, int cs, bool end) {\n    getBuckets(s, bkt,\
    \ n, K, cs, end);\n    for (int i = 0; i < n; i++) {\n        int j = SA[i] -\
    \ 1;\n        if (j >= 0 and !tget(j)) {\n            SA[bkt[chr(j)]++] = j;\n\
    \        }\n    }\n}\n\nvoid induceSAs(unsigned char *t, int *SA, unsigned char\
    \ *s, int *bkt, int n, int K, int cs, bool end) {\n    getBuckets(s, bkt, n, K,\
    \ cs, end);\n    for (int i = n - 1; i >= 0; i--) {\n        int j = SA[i] - 1;\n\
    \        if (j >= 0 and tget(j)) {\n            SA[--bkt[chr(j)]] = j;\n     \
    \   }\n    }\n}\n\nvoid SA_IS(unsigned char *s, int *SA, int n, int K, int cs)\
    \ {\n    unsigned char *t = (unsigned char *)malloc(n / 8 + 1);\n    tset(n -\
    \ 2, 0);\n    tset(n - 1, 1);\n    for (int i = n - 3; i >= 0; i--) {\n      \
    \  tset(i, (chr(i) < chr(i + 1) or (chr(i) == chr(i + 1) and tget(i + 1) == 1))\
    \ ? 1 : 0);\n    }\n\n    int *bkt = (int *)malloc(sizeof(int) * (K + 1));\n \
    \   getBuckets(s, bkt, n, K, cs, true);\n    for (int i = 0; i < n; i++) {\n \
    \       SA[i] = -1;\n    }\n    for (int i = 1; i < n; i++) {\n        if (isLMS(i))\
    \ {\n            SA[--bkt[chr(i)]] = i;\n        }\n    }\n    induceSAl(t, SA,\
    \ s, bkt, n, K, cs, false);\n    induceSAs(t, SA, s, bkt, n, K, cs, true);\n \
    \   free(bkt);\n\n    int n1 = 0;\n    for (int i = 0; i < n; i++) {\n       \
    \ if (isLMS(SA[i])) {\n            SA[n1++] = SA[i];\n        }\n    }\n\n   \
    \ for (int i = n1; i < n; i++) {\n        SA[i] = -1;\n    }\n    int name = 0;\n\
    \    int prev = -1;\n    for (int i = 0; i < n1; i++) {\n        int pos = SA[i];\n\
    \        bool diff = false;\n        for (int d = 0; d < n; d++) {\n         \
    \   if (prev == -1 or chr(pos + d) != chr(prev + d) or tget(pos + d) != tget(prev\
    \ + d)) {\n                diff = true;\n                break;\n            }\
    \ else if (d > 0 and (isLMS(pos + d) or isLMS(prev + d))) {\n                break;\n\
    \            }\n        }\n        if (diff) {\n            name++;\n        \
    \    prev = pos;\n        }\n        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1)\
    \ / 2;\n        SA[n1 + pos] = name - 1;\n    }\n    for (int i = n - 1, j = n\
    \ - 1; i >= n1; i--) {\n        if (SA[i] >= 0) {\n            SA[j--] = SA[i];\n\
    \        }\n    }\n\n    int *SA1 = SA;\n    int *s1 = SA + n - n1;\n    if (name\
    \ < n1) {\n        SA_IS((unsigned char *)s1, SA1, n1, name - 1, sizeof(int));\n\
    \    } else {\n        for (int i = 0; i < n1; i++) {\n            SA1[s1[i]]\
    \ = i;\n        }\n    }\n    bkt = (int *)malloc(sizeof(int) * (K + 1));\n  \
    \  getBuckets(s, bkt, n, K, cs, true);\n    for (int i = 1, j = 0; i < n; i++)\
    \ {\n        if (isLMS(i)) {\n            s1[j++] = i;\n        }\n    }\n   \
    \ for (int i = 0; i < n1; i++) {\n        SA1[i] = s1[SA1[i]];\n    }\n    for\
    \ (int i = n1; i < n; i++) {\n        SA[i] = -1;\n    }\n    for (int i = n1\
    \ - 1; i >= 0; i--) {\n        int j = SA[i];\n        SA[i] = -1;\n        SA[--bkt[chr(j)]]\
    \ = j;\n    }\n    induceSAl(t, SA, s, bkt, n, K, cs, false);\n    induceSAs(t,\
    \ SA, s, bkt, n, K, cs, true);\n    free(bkt);\n    free(t);\n}\n\nvector<int>\
    \ suffixArray(string &str) {\n    int n = str.size() + 1;\n    int *sa = (int\
    \ *)malloc(sizeof(int) * n);\n    unsigned char *s = (unsigned char *)malloc(sizeof(unsigned\
    \ char) * (n + 2));\n    int k = 256;\n    int cs = sizeof(unsigned char);\n \
    \   for (int i = 0; i < str.size(); i++) {\n        s[i] = str[i];\n    }\n  \
    \  s[int(str.size())] = 0;\n    SA_IS((unsigned char *)(s), sa, n, k, cs);\n \
    \   vector<int> res(n - 1);\n    for (int i = 0; i < n - 1; i++) {\n        res[i]\
    \ = sa[i + 1];\n    }\n    free(sa);\n    free(s);\n    return res;\n}\n#line\
    \ 2 \"string/LCPArray.hpp\"\nvector<int> LCPArray(const string& s, const vector<int>&\
    \ sa) {\n  int n = int(s.size());\n  vector<int> rank(n);\n  for (int i = 0; i\
    \ < n; i++) rank[sa[i]] = i;\n  vector<int> lcp(n - 1);\n  int h = 0;\n  for (int\
    \ i = 0; i < n; i++) {\n    if (h > 0) h--;\n    if (rank[i] == 0) continue;\n\
    \    int j = sa[rank[i] - 1];\n    for (; j + h < n and i + h < n; h++) {\n  \
    \    if (s[j + h] != s[i + h]) break;\n    }\n    lcp[rank[i] - 1] = h;\n  }\n\
    \  return lcp;\n}\n"
  code: "#include \"SuffixArray.hpp\"\nvector<int> LCPArray(const string& s, const\
    \ vector<int>& sa) {\n  int n = int(s.size());\n  vector<int> rank(n);\n  for\
    \ (int i = 0; i < n; i++) rank[sa[i]] = i;\n  vector<int> lcp(n - 1);\n  int h\
    \ = 0;\n  for (int i = 0; i < n; i++) {\n    if (h > 0) h--;\n    if (rank[i]\
    \ == 0) continue;\n    int j = sa[rank[i] - 1];\n    for (; j + h < n and i +\
    \ h < n; h++) {\n      if (s[j + h] != s[i + h]) break;\n    }\n    lcp[rank[i]\
    \ - 1] = h;\n  }\n  return lcp;\n}"
  dependsOn:
  - string/SuffixArray.hpp
  isVerificationFile: false
  path: string/LCPArray.hpp
  requiredBy:
  - string/LongestCommonSubstring.hpp
  timestamp: '2025-12-14 23:58:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/LibraryChecker/string/NumberofSubstrings2.test.cpp
  - verify/LibraryChecker/string/LongestCommonSubstring.test.cpp
documentation_of: string/LCPArray.hpp
layout: document
title: LCP Array
---

## 概要

todo

## 計算量
todo