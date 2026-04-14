---
title: LCP Array
documentation_of: //string/LCPArray.hpp
---

## 概要

文字列 `s` とその suffix array から LCP array を構築する。

## 関数

```cpp
vector<int> LCPArray(const string& s, const vector<int>& sa)
```

文字列 `s` の suffix array `sa` に対する LCP array を返す。返り値の `i` 番目は、`sa[i]` と `sa[i + 1]` を開始位置とする 2 つの suffix の最長共通接頭辞長を表す。

### 制約
- `sa` は `s` の suffix array
- `sa.size() = s.size()`

### 計算量
- $O(n)$
