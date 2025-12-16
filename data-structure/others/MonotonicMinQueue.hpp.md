---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/LongestCommonSubstring.hpp
    title: Longest Common Substring
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/string/LongestCommonSubstring.test.cpp
    title: verify/LibraryChecker/string/LongestCommonSubstring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/MonotonicMinQueue.hpp\"\ntemplate\
    \ <class T>\nclass MonotonicMinQueue {\n private:\n  queue<T> que;\n  deque<T>\
    \ deq;\n\n public:\n  void push(const T& x) {\n    que.push(x);\n    while (deq.size()\
    \ > 0 and deq.back() > x) deq.pop_back();\n    deq.push_back(x);\n  }\n\n  void\
    \ pop() {\n    if (que.front() == deq.front()) deq.pop_front();\n    que.pop();\n\
    \  }\n\n  const T& front() const {\n    return que.front();\n  }\n\n  bool empty()\
    \ const {\n    return que.empty();\n  }\n\n  const T& minimum() const {\n    return\
    \ deq.front();\n  }\n};\n"
  code: "template <class T>\nclass MonotonicMinQueue {\n private:\n  queue<T> que;\n\
    \  deque<T> deq;\n\n public:\n  void push(const T& x) {\n    que.push(x);\n  \
    \  while (deq.size() > 0 and deq.back() > x) deq.pop_back();\n    deq.push_back(x);\n\
    \  }\n\n  void pop() {\n    if (que.front() == deq.front()) deq.pop_front();\n\
    \    que.pop();\n  }\n\n  const T& front() const {\n    return que.front();\n\
    \  }\n\n  bool empty() const {\n    return que.empty();\n  }\n\n  const T& minimum()\
    \ const {\n    return deq.front();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/MonotonicMinQueue.hpp
  requiredBy:
  - string/LongestCommonSubstring.hpp
  timestamp: '2025-12-17 00:38:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/string/LongestCommonSubstring.test.cpp
documentation_of: data-structure/others/MonotonicMinQueue.hpp
layout: document
title: Monotonic Queue (Min Queue)
---

## 概要

todo

## 計算量
todo