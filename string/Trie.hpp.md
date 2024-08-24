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
  bundledCode: "#line 2 \"string/Trie.hpp\"\ntemplate <int char_size = 26, char base\
    \ = 'a'>\nclass Trie {\n    struct Node {\n        vector<int> child;\n      \
    \  vector<int> fin;\n        int dist;\n        int cnt;\n        Node(int c_)\
    \ : dist(c_), cnt(0) {\n            child.resize(char_size, -1);\n        }\n\
    \    };\n\n   private:\n    vector<Node> tree;\n    int root;\n\n    void insert(const\
    \ string &s, int word_id) {\n        int node_id = 0;\n        rep(i, s.size())\
    \ {\n            int c = s[i] - base;\n            int &next_id = tree[node_id].child[c];\n\
    \            if (next_id == -1) {\n                next_id = tree.size();\n  \
    \              tree.emplace_back(Node(c));\n            }\n            tree[node_id].cnt++;\n\
    \            node_id = next_id;\n        }\n        tree[node_id].cnt++;\n   \
    \     tree[node_id].fin.push_back(word_id);\n    }\n\n   public:\n    Trie() :\
    \ root(0) {\n        tree.push_back(Node(root));\n    }\n\n    // \u6587\u5B57\
    \u5217\u3092\u633F\u5165\u3059\u308B\n    void insert(const string &s) {\n   \
    \     insert(s, tree[0].cnt);\n    }\n\n    // \u6307\u5B9A\u3057\u305F\u6587\u5B57\
    \u5217\u304C\u5B58\u5728\u3059\u308B\u304B or \u6307\u5B9A\u3057\u305Fprefix\u3092\
    \u3082\u3064\u6587\u5B57\u5217\u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\
    \u304B\u3092\u8FD4\u3059\n    bool search(const string &s, bool prefix = false)\
    \ {\n        int node_id = 0;\n        rep(i, s.size()) {\n            int c =\
    \ s[i] - base;\n            int &next_id = tree[node_id].child[c];\n         \
    \   if (next_id == -1) {\n                return false;\n            }\n     \
    \       node_id = next_id;\n            out(\"cnt\", tree[node_id].cnt);\n   \
    \     }\n        return (prefix) ? true : tree[node_id].fin.size() > 0;\n    }\n\
    \n    // \u6307\u5B9A\u3057\u305Fprefix\u3092\u3082\u3064\u6587\u5B57\u5217\u304C\
    \u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n    bool start_with(const\
    \ string &s) {\n        return search(s, 1);\n    }\n\n    // \u633F\u5165\u3057\
    \u305F\u6587\u5B57\u5217\u306E\u7DCF\u6570\u3092\u8FD4\u3059\n    int count()\
    \ {\n        return tree[0].cnt;\n    }\n};\n"
  code: "#pragma once\ntemplate <int char_size = 26, char base = 'a'>\nclass Trie\
    \ {\n    struct Node {\n        vector<int> child;\n        vector<int> fin;\n\
    \        int dist;\n        int cnt;\n        Node(int c_) : dist(c_), cnt(0)\
    \ {\n            child.resize(char_size, -1);\n        }\n    };\n\n   private:\n\
    \    vector<Node> tree;\n    int root;\n\n    void insert(const string &s, int\
    \ word_id) {\n        int node_id = 0;\n        rep(i, s.size()) {\n         \
    \   int c = s[i] - base;\n            int &next_id = tree[node_id].child[c];\n\
    \            if (next_id == -1) {\n                next_id = tree.size();\n  \
    \              tree.emplace_back(Node(c));\n            }\n            tree[node_id].cnt++;\n\
    \            node_id = next_id;\n        }\n        tree[node_id].cnt++;\n   \
    \     tree[node_id].fin.push_back(word_id);\n    }\n\n   public:\n    Trie() :\
    \ root(0) {\n        tree.push_back(Node(root));\n    }\n\n    // \u6587\u5B57\
    \u5217\u3092\u633F\u5165\u3059\u308B\n    void insert(const string &s) {\n   \
    \     insert(s, tree[0].cnt);\n    }\n\n    // \u6307\u5B9A\u3057\u305F\u6587\u5B57\
    \u5217\u304C\u5B58\u5728\u3059\u308B\u304B or \u6307\u5B9A\u3057\u305Fprefix\u3092\
    \u3082\u3064\u6587\u5B57\u5217\u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\
    \u304B\u3092\u8FD4\u3059\n    bool search(const string &s, bool prefix = false)\
    \ {\n        int node_id = 0;\n        rep(i, s.size()) {\n            int c =\
    \ s[i] - base;\n            int &next_id = tree[node_id].child[c];\n         \
    \   if (next_id == -1) {\n                return false;\n            }\n     \
    \       node_id = next_id;\n            out(\"cnt\", tree[node_id].cnt);\n   \
    \     }\n        return (prefix) ? true : tree[node_id].fin.size() > 0;\n    }\n\
    \n    // \u6307\u5B9A\u3057\u305Fprefix\u3092\u3082\u3064\u6587\u5B57\u5217\u304C\
    \u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n    bool start_with(const\
    \ string &s) {\n        return search(s, 1);\n    }\n\n    // \u633F\u5165\u3057\
    \u305F\u6587\u5B57\u5217\u306E\u7DCF\u6570\u3092\u8FD4\u3059\n    int count()\
    \ {\n        return tree[0].cnt;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy: []
  timestamp: '2024-08-24 16:53:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Trie.hpp
layout: document
title: Trie
---

## 概要

todo

## 計算量
todo