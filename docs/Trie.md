---
title: Trie
documentation_of: //string/Trie.hpp
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
- `s` の各文字 `c` について $0 \leq c - \mathrm{base} < \mathrm{char\_size}$

### 計算量
- $O(|s|)$

## search

```cpp
bool trie.search(const string& s, bool prefix = false)
```

- `prefix = false` のとき、文字列 `s` が挿入されていれば `true` を返す。
- `prefix = true` のとき、`s` を prefix に持つ文字列が存在すれば `true` を返す。

### 制約
- `s` の各文字 `c` について $0 \leq c - \mathrm{base} < \mathrm{char\_size}$

### 計算量
- $O(|s|)$

## start_with

```cpp
bool trie.start_with(const string& s)
```

`search(s, true)` を行う。`s` を prefix に持つ文字列が存在すれば `true` を返す。

### 制約
- `s` の各文字 `c` について $0 \leq c - \mathrm{base} < \mathrm{char\_size}$

### 計算量
- $O(|s|)$

## count

```cpp
int trie.count()
```

挿入された文字列の総数を返す。同じ文字列を複数回挿入した場合も、その回数だけ数える。

### 計算量
- $O(1)$
