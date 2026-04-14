---
title: Suffix Array
documentation_of: //string/SuffixArray.hpp
---

## 概要

文字列の suffix array を構築する。

## 関数

```cpp
vector<int> suffixArray(string& str)
```

文字列 `str` の suffix array を返す。返り値の `i` 番目は、辞書順で `i` 番目に小さい suffix の開始位置を表す。空文字に対応する suffix は含まれない。

### 制約
- `str` は `unsigned char` として扱える文字列

### 計算量
- $O(n)$
