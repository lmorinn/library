---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
    title: verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/others/BinaryTrie.hpp\"\ntemplate <typename\
    \ U = unsigned, int B = 32>\nclass lazy_binary_trie {\n    struct node {\n   \
    \     int cnt;\n        U lazy;\n        node *ch[2];\n        node() : cnt(0),\
    \ lazy(0), ch{nullptr, nullptr} {}\n    };\n    void push(node *t, int b) {\n\
    \        if ((t->lazy >> (U)b) & (U)1) swap(t->ch[0], t->ch[1]);\n        if (t->ch[0])\
    \ t->ch[0]->lazy ^= t->lazy;\n        if (t->ch[1]) t->ch[1]->lazy ^= t->lazy;\n\
    \        t->lazy = 0;\n    }\n    node *add(node *t, U val, int b = B - 1) {\n\
    \        if (!t) t = new node;\n        t->cnt += 1;\n        if (b < 0) return\
    \ t;\n        push(t, b);\n        bool f = (val >> (U)b) & (U)1;\n        t->ch[f]\
    \ = add(t->ch[f], val, b - 1);\n        return t;\n    }\n    node *sub(node *t,\
    \ U val, int b = B - 1) {\n        assert(t);\n        t->cnt -= 1;\n        if\
    \ (t->cnt == 0) return nullptr;\n        if (b < 0) return t;\n        push(t,\
    \ b);\n        bool f = (val >> (U)b) & (U)1;\n        t->ch[f] = sub(t->ch[f],\
    \ val, b - 1);\n        return t;\n    }\n    U get_min(node *t, U val, int b\
    \ = B - 1) {\n        assert(t);\n        if (b < 0) return 0;\n        push(t,\
    \ b);\n        bool f = (val >> (U)b) & (U)1;\n        f ^= !t->ch[f];\n     \
    \   return get_min(t->ch[f], val, b - 1) | ((U)f << (U)b);\n    }\n    U get(node\
    \ *t, int k, int b = B - 1) {\n        if (b < 0) return 0;\n        push(t, b);\n\
    \        int m = t->ch[0] ? t->ch[0]->cnt : 0;\n        return k < m ? get(t->ch[0],\
    \ k, b - 1) : get(t->ch[1], k - m, b - 1) | ((U)1 << (U)b);\n    }\n    int count_lower(node\
    \ *t, U val, int b = B - 1) {\n        if (!t || b < 0) return 0;\n        push(t,\
    \ b);\n        bool f = (val >> (U)b) & (U)1;\n        return (f && t->ch[0] ?\
    \ t->ch[0]->cnt : 0) + count_lower(t->ch[f], val, b - 1);\n    }\n    node *root;\n\
    \n   public:\n    lazy_binary_trie() : root(nullptr) {}\n    int size() const\
    \ {\n        return root ? root->cnt : 0;\n    }\n    bool empty() const {\n \
    \       return !root;\n    }\n\n    // \u5024val\u3092\u96C6\u5408\u306B1\u3064\
    \u8FFD\u52A0\u3059\u308B\n    void insert(U val) {\n        root = add(root, val);\n\
    \    }\n\n    // \u5024val\u3092\u96C6\u5408\u304B\u30891\u3064\u524A\u9664\u3059\
    \u308B\n    void erase(U val) {\n        root = sub(root, val);\n    }\n\n   \
    \ // \u3059\u3079\u3066\u306E\u8981\u7D20\u3092val\u3068XOR\u3092\u53D6\u3063\u305F\
    \u5024\u306B\u5909\u66F4\u3059\u308B\n    void xor_all(U val) {\n        if (root)\
    \ root->lazy ^= val;\n    }\n\n    // \u5024bias\u3068xor\u3092\u53D6\u3063\u305F\
    \u3068\u304D\u306B\u6700\u5927\u306B\u306A\u308B\u5024\u3092\u8FD4\u3059\n   \
    \ U max_element(U bias = 0) {\n        return get_min(root, ~bias);\n    }\n\n\
    \    // \u5024bias\u3068xor\u3092\u53D6\u3063\u305F\u3068\u304D\u306B\u6700\u5C0F\
    \u306B\u306A\u308B\u5024\u3092\u8FD4\u3059\n    U min_element(U bias = 0) {\n\
    \        return get_min(root, bias);\n    }\n\n    // val\u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u8981\u7D20\u304C\u5C0F\u3055\u3044\u65B9\u304B\u3089\u4F55\u756A\
    \u76EE\u304B\u3092\u8FD4\u3059\n    int lower_bound(U val) {\n        return count_lower(root,\
    \ val);\n    }\n\n    // val\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20\u304C\u5C0F\u3055\u3044\u65B9\u304B\u3089\u4F55\u756A\u76EE\u304B\u3092\
    \u8FD4\u3059\n    int upper_bound(U val) {\n        return count_lower(root, val\
    \ + 1);\n    }\n\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\
    \u3059\n    U operator[](int k) {\n        assert(0 <= k && k < size());\n   \
    \     return get(root, k);\n    }\n\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\
    \u5024\u3092\u8FD4\u3059\n    U kth_smallest(int k) {\n        assert(0 <= k &&\
    \ k < size());\n        return get(root, k);\n    }\n\n    // \u5024val\u304C\u96C6\
    \u5408\u306B\u3044\u304F\u3064\u542B\u307E\u308C\u308B\u304B\u3092\u8FD4\u3059\
    \n    int count(U val) {\n        if (!root) return 0;\n        node *t = root;\n\
    \        for (int i = B - 1; i >= 0; i--) {\n            push(t, i);\n       \
    \     t = t->ch[(val >> (U)i) & (U)1];\n            if (!t) return 0;\n      \
    \  }\n        return t->cnt;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename U = unsigned, int B = 32>\nclass lazy_binary_trie\
    \ {\n    struct node {\n        int cnt;\n        U lazy;\n        node *ch[2];\n\
    \        node() : cnt(0), lazy(0), ch{nullptr, nullptr} {}\n    };\n    void push(node\
    \ *t, int b) {\n        if ((t->lazy >> (U)b) & (U)1) swap(t->ch[0], t->ch[1]);\n\
    \        if (t->ch[0]) t->ch[0]->lazy ^= t->lazy;\n        if (t->ch[1]) t->ch[1]->lazy\
    \ ^= t->lazy;\n        t->lazy = 0;\n    }\n    node *add(node *t, U val, int\
    \ b = B - 1) {\n        if (!t) t = new node;\n        t->cnt += 1;\n        if\
    \ (b < 0) return t;\n        push(t, b);\n        bool f = (val >> (U)b) & (U)1;\n\
    \        t->ch[f] = add(t->ch[f], val, b - 1);\n        return t;\n    }\n   \
    \ node *sub(node *t, U val, int b = B - 1) {\n        assert(t);\n        t->cnt\
    \ -= 1;\n        if (t->cnt == 0) return nullptr;\n        if (b < 0) return t;\n\
    \        push(t, b);\n        bool f = (val >> (U)b) & (U)1;\n        t->ch[f]\
    \ = sub(t->ch[f], val, b - 1);\n        return t;\n    }\n    U get_min(node *t,\
    \ U val, int b = B - 1) {\n        assert(t);\n        if (b < 0) return 0;\n\
    \        push(t, b);\n        bool f = (val >> (U)b) & (U)1;\n        f ^= !t->ch[f];\n\
    \        return get_min(t->ch[f], val, b - 1) | ((U)f << (U)b);\n    }\n    U\
    \ get(node *t, int k, int b = B - 1) {\n        if (b < 0) return 0;\n       \
    \ push(t, b);\n        int m = t->ch[0] ? t->ch[0]->cnt : 0;\n        return k\
    \ < m ? get(t->ch[0], k, b - 1) : get(t->ch[1], k - m, b - 1) | ((U)1 << (U)b);\n\
    \    }\n    int count_lower(node *t, U val, int b = B - 1) {\n        if (!t ||\
    \ b < 0) return 0;\n        push(t, b);\n        bool f = (val >> (U)b) & (U)1;\n\
    \        return (f && t->ch[0] ? t->ch[0]->cnt : 0) + count_lower(t->ch[f], val,\
    \ b - 1);\n    }\n    node *root;\n\n   public:\n    lazy_binary_trie() : root(nullptr)\
    \ {}\n    int size() const {\n        return root ? root->cnt : 0;\n    }\n  \
    \  bool empty() const {\n        return !root;\n    }\n\n    // \u5024val\u3092\
    \u96C6\u5408\u306B1\u3064\u8FFD\u52A0\u3059\u308B\n    void insert(U val) {\n\
    \        root = add(root, val);\n    }\n\n    // \u5024val\u3092\u96C6\u5408\u304B\
    \u30891\u3064\u524A\u9664\u3059\u308B\n    void erase(U val) {\n        root =\
    \ sub(root, val);\n    }\n\n    // \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\
    val\u3068XOR\u3092\u53D6\u3063\u305F\u5024\u306B\u5909\u66F4\u3059\u308B\n   \
    \ void xor_all(U val) {\n        if (root) root->lazy ^= val;\n    }\n\n    //\
    \ \u5024bias\u3068xor\u3092\u53D6\u3063\u305F\u3068\u304D\u306B\u6700\u5927\u306B\
    \u306A\u308B\u5024\u3092\u8FD4\u3059\n    U max_element(U bias = 0) {\n      \
    \  return get_min(root, ~bias);\n    }\n\n    // \u5024bias\u3068xor\u3092\u53D6\
    \u3063\u305F\u3068\u304D\u306B\u6700\u5C0F\u306B\u306A\u308B\u5024\u3092\u8FD4\
    \u3059\n    U min_element(U bias = 0) {\n        return get_min(root, bias);\n\
    \    }\n\n    // val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\u304C\u5C0F\
    \u3055\u3044\u65B9\u304B\u3089\u4F55\u756A\u76EE\u304B\u3092\u8FD4\u3059\n   \
    \ int lower_bound(U val) {\n        return count_lower(root, val);\n    }\n\n\
    \    // val\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\u7D20\u304C\u5C0F\
    \u3055\u3044\u65B9\u304B\u3089\u4F55\u756A\u76EE\u304B\u3092\u8FD4\u3059\n   \
    \ int upper_bound(U val) {\n        return count_lower(root, val + 1);\n    }\n\
    \n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n    U\
    \ operator[](int k) {\n        assert(0 <= k && k < size());\n        return get(root,\
    \ k);\n    }\n\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\
    \u3059\n    U kth_smallest(int k) {\n        assert(0 <= k && k < size());\n \
    \       return get(root, k);\n    }\n\n    // \u5024val\u304C\u96C6\u5408\u306B\
    \u3044\u304F\u3064\u542B\u307E\u308C\u308B\u304B\u3092\u8FD4\u3059\n    int count(U\
    \ val) {\n        if (!root) return 0;\n        node *t = root;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            push(t, i);\n            t = t->ch[(val\
    \ >> (U)i) & (U)1];\n            if (!t) return 0;\n        }\n        return\
    \ t->cnt;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2024-08-24 16:53:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
documentation_of: data-structure/others/BinaryTrie.hpp
layout: document
title: Binary Trie
---

## 概要

todo

## 計算量
todo