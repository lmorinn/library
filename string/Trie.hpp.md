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
    \       node_id = next_id;\n        }\n        return (prefix) ? true : tree[node_id].fin.size()\
    \ > 0;\n    }\n\n    // \u6307\u5B9A\u3057\u305Fprefix\u3092\u3082\u3064\u6587\
    \u5B57\u5217\u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\
    \u3059\n    bool start_with(const string &s) {\n        return search(s, 1);\n\
    \    }\n\n    // \u633F\u5165\u3057\u305F\u6587\u5B57\u5217\u306E\u7DCF\u6570\u3092\
    \u8FD4\u3059\n    int count() {\n        return tree[0].cnt;\n    }\n};\n"
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
    \       node_id = next_id;\n        }\n        return (prefix) ? true : tree[node_id].fin.size()\
    \ > 0;\n    }\n\n    // \u6307\u5B9A\u3057\u305Fprefix\u3092\u3082\u3064\u6587\
    \u5B57\u5217\u304C\u5B58\u5728\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\
    \u3059\n    bool start_with(const string &s) {\n        return search(s, 1);\n\
    \    }\n\n    // \u633F\u5165\u3057\u305F\u6587\u5B57\u5217\u306E\u7DCF\u6570\u3092\
    \u8FD4\u3059\n    int count() {\n        return tree[0].cnt;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy: []
  timestamp: '2026-04-14 16:41:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Trie.hpp
layout: document
title: Trie
---

## 概要

文字列集合に対して、文字列の挿入と検索を扱うデータ構造。

## コンストラクタ

```cpp
Trie<char_size, base>()
```

空の trie を構築する。

### 制約
- テンプレート引数 `char_size` : 扱う文字種数
- テンプレート引数 `base` : 最小の文字

### 計算量
- $O(1)$

## insert

```cpp
void trie.insert(const string& s)
```

文字列 `s` を trie に挿入する。

### 制約
- `s` の各文字 `c` について $0 \leq c - \mathrm{base} < \mathrm{charsize}$

### 計算量
- $O(|s|)$

## search

```cpp
bool trie.search(const string& s, bool prefix = false)
```

- `prefix = false` のとき、文字列 `s` が挿入されていれば `true` を返す。
- `prefix = true` のとき、`s` を prefix に持つ文字列が存在すれば `true` を返す。

### 制約
- `s` の各文字 `c` について $0 \leq c - \mathrm{base} < \mathrm{charsize}$

### 計算量
- $O(|s|)$

## start_with

```cpp
bool trie.start_with(const string& s)
```

`search(s, true)` を行う。`s` を prefix に持つ文字列が存在すれば `true` を返す。

### 制約
- `s` の各文字 `c` について $0 \leq c - \mathrm{base} < \mathrm{charsize}$

### 計算量
- $O(|s|)$

## count

```cpp
int trie.count()
```

挿入された文字列の総数を返す。同じ文字列を複数回挿入した場合も、その回数だけ数える。

### 計算量
- $O(1)$
