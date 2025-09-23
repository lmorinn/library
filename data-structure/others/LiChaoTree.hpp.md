---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
    title: verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/others/SegmentAddGetMin.test.cpp
    title: verify/LibraryChecker/data-structure/others/SegmentAddGetMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/LiChaoTree.hpp\"\n\nclass LiChaoTree\
    \ {\n   private:\n    struct Node {\n        long long a, b;\n        Node *left;\n\
    \        Node *right;\n        Node(long long a, long long b) : a(a), b(b), left(nullptr),\
    \ right(nullptr) {}\n    };\n    long long lower_x, upper_x;\n    Node *root =\
    \ nullptr;\n\n    inline long long f(long long a, long long b, long long x) {\n\
    \        return a * x + b;\n    }\n\n    void add_line(long long line_a, long\
    \ long line_b, Node *&t, long long l, long long r) {\n        if (!t) {\n    \
    \        t = new Node(line_a, line_b);\n            return;\n        }\n\n   \
    \     if (r - l == 1) {\n            if (f(line_a, line_b, l) < f(t->a, t->b,\
    \ l)) {\n                t->a = line_a;\n                t->b = line_b;\n    \
    \        }\n            return;\n        }\n        long long m = (l + r) >> 1ll;\n\
    \n        bool left_min = f(line_a, line_b, l) < f(t->a, t->b, l);\n        bool\
    \ mid_min = f(line_a, line_b, m) < f(t->a, t->b, m);\n        bool right_min =\
    \ f(line_a, line_b, r) < f(t->a, t->b, r);\n\n        if (left_min and right_min)\
    \ {\n            t->a = line_a;\n            t->b = line_b;\n            return;\n\
    \        }\n        if (!left_min and !right_min) {\n            return;\n   \
    \     }\n\n        if (mid_min) {\n            swap(t->a, line_a);\n         \
    \   swap(t->b, line_b);\n        }\n        if (left_min != mid_min) {\n     \
    \       add_line(line_a, line_b, t->left, l, m);\n        } else {\n         \
    \   add_line(line_a, line_b, t->right, m, r);\n        }\n    }\n\n    void add_segment(long\
    \ long line_a, long long line_b, Node *&t, long long a, long long b, long long\
    \ l, long long r) {\n        if (r <= a or b <= l) return;\n        if (!t) t\
    \ = new Node(0, LLONG_MAX);\n\n        long long m = (l + r) >> 1ll;\n       \
    \ if (!(a <= l and r <= b)) {\n            add_segment(line_a, line_b, t->left,\
    \ a, b, l, m);\n            add_segment(line_a, line_b, t->right, a, b, m, r);\n\
    \            return;\n        }\n        if (t->a == 0 and t->b == LLONG_MAX)\
    \ {\n            t->a = line_a;\n            t->b = line_b;\n        } else {\n\
    \            add_line(line_a, line_b, t, l, r);\n        }\n    }\n\n    long\
    \ long get_min(long long x, Node *t, long long l, long long r) {\n        if (!t)\
    \ return LLONG_MAX;\n        long long y = f(t->a, t->b, x);\n        if (r -\
    \ l == 1) return y;\n        long long m = (l + r) >> 1ll;\n        if (x < m)\
    \ {\n            return min(y, get_min(x, t->left, l, m));\n        } else {\n\
    \            return min(y, get_min(x, t->right, m, r));\n        }\n    }\n\n\
    \   public:\n    LiChaoTree() {}\n    LiChaoTree(long long lower_x, long long\
    \ upper_x) : lower_x(lower_x), upper_x(upper_x) {\n    }\n\n    void add_line(long\
    \ long a, long long b) {\n        add_line(a, b, root, lower_x, upper_x);\n  \
    \  }\n\n    void add_segment(long long l, long long r, long long a, long long\
    \ b) {\n        add_segment(a, b, root, l, r, lower_x, upper_x);\n    }\n\n  \
    \  long long get_min(long long x) {\n        return get_min(x, root, lower_x,\
    \ upper_x);\n    }\n};\n"
  code: "\nclass LiChaoTree {\n   private:\n    struct Node {\n        long long a,\
    \ b;\n        Node *left;\n        Node *right;\n        Node(long long a, long\
    \ long b) : a(a), b(b), left(nullptr), right(nullptr) {}\n    };\n    long long\
    \ lower_x, upper_x;\n    Node *root = nullptr;\n\n    inline long long f(long\
    \ long a, long long b, long long x) {\n        return a * x + b;\n    }\n\n  \
    \  void add_line(long long line_a, long long line_b, Node *&t, long long l, long\
    \ long r) {\n        if (!t) {\n            t = new Node(line_a, line_b);\n  \
    \          return;\n        }\n\n        if (r - l == 1) {\n            if (f(line_a,\
    \ line_b, l) < f(t->a, t->b, l)) {\n                t->a = line_a;\n         \
    \       t->b = line_b;\n            }\n            return;\n        }\n      \
    \  long long m = (l + r) >> 1ll;\n\n        bool left_min = f(line_a, line_b,\
    \ l) < f(t->a, t->b, l);\n        bool mid_min = f(line_a, line_b, m) < f(t->a,\
    \ t->b, m);\n        bool right_min = f(line_a, line_b, r) < f(t->a, t->b, r);\n\
    \n        if (left_min and right_min) {\n            t->a = line_a;\n        \
    \    t->b = line_b;\n            return;\n        }\n        if (!left_min and\
    \ !right_min) {\n            return;\n        }\n\n        if (mid_min) {\n  \
    \          swap(t->a, line_a);\n            swap(t->b, line_b);\n        }\n \
    \       if (left_min != mid_min) {\n            add_line(line_a, line_b, t->left,\
    \ l, m);\n        } else {\n            add_line(line_a, line_b, t->right, m,\
    \ r);\n        }\n    }\n\n    void add_segment(long long line_a, long long line_b,\
    \ Node *&t, long long a, long long b, long long l, long long r) {\n        if\
    \ (r <= a or b <= l) return;\n        if (!t) t = new Node(0, LLONG_MAX);\n\n\
    \        long long m = (l + r) >> 1ll;\n        if (!(a <= l and r <= b)) {\n\
    \            add_segment(line_a, line_b, t->left, a, b, l, m);\n            add_segment(line_a,\
    \ line_b, t->right, a, b, m, r);\n            return;\n        }\n        if (t->a\
    \ == 0 and t->b == LLONG_MAX) {\n            t->a = line_a;\n            t->b\
    \ = line_b;\n        } else {\n            add_line(line_a, line_b, t, l, r);\n\
    \        }\n    }\n\n    long long get_min(long long x, Node *t, long long l,\
    \ long long r) {\n        if (!t) return LLONG_MAX;\n        long long y = f(t->a,\
    \ t->b, x);\n        if (r - l == 1) return y;\n        long long m = (l + r)\
    \ >> 1ll;\n        if (x < m) {\n            return min(y, get_min(x, t->left,\
    \ l, m));\n        } else {\n            return min(y, get_min(x, t->right, m,\
    \ r));\n        }\n    }\n\n   public:\n    LiChaoTree() {}\n    LiChaoTree(long\
    \ long lower_x, long long upper_x) : lower_x(lower_x), upper_x(upper_x) {\n  \
    \  }\n\n    void add_line(long long a, long long b) {\n        add_line(a, b,\
    \ root, lower_x, upper_x);\n    }\n\n    void add_segment(long long l, long long\
    \ r, long long a, long long b) {\n        add_segment(a, b, root, l, r, lower_x,\
    \ upper_x);\n    }\n\n    long long get_min(long long x) {\n        return get_min(x,\
    \ root, lower_x, upper_x);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2025-09-23 18:49:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/others/SegmentAddGetMin.test.cpp
  - verify/LibraryChecker/data-structure/others/LineAddGetMin.test.cpp
documentation_of: data-structure/others/LiChaoTree.hpp
layout: document
title: Li Chao Tree
---

## 概要

todo

## 計算量
todo