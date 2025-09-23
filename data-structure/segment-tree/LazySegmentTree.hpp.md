---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/AreaofUnionofRectangles.hpp
    title: Area of Union of Rectangles
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeAddRangeMax.hpp
    title: Range Add Range Max
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeAddRangeMin.hpp
    title: Range Add Range Min
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeAddRangeSum.hpp
    title: Range Add Range Sum
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeLinearAddRangeSum.hpp
    title: Range Linear Add Range Sum
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeLinearUpdateRangeMinMaxSum.hpp
    title: Range Linear Update Range Min Max Sum
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeUpdateRangeMax.hpp
    title: Range Update Range Max
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeUpdateRangeMin.hpp
    title: Range Update Range Min
  - icon: ':warning:'
    path: data-structure/segment-tree/query/RangeUpdateRangeSum.hpp
    title: Range Update Range Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_F.test.cpp
    title: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
    title: verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
    title: verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree/LazySegmentTree.hpp\"\n\ntemplate\
    \ <class S,\n          auto op,\n          auto e,\n          class F,\n     \
    \     auto mapping,\n          auto composition,\n          auto id>\nstruct lazy_segtree\
    \ {\n private:\n  unsigned int seg_bit_ceil(unsigned int n) {\n    unsigned int\
    \ x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n    return x;\n  }\n\n public:\n\
    \  static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,\n\
    \                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  static_assert(\n\
    \      std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,\n   \
    \   \"mapping must work as F(F, S)\");\n  static_assert(\n      std::is_convertible_v<decltype(composition),\
    \ std::function<F(F, F)>>,\n      \"compostiion must work as F(F, F)\");\n  static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                \"id must work as F()\");\n  lazy_segtree()\
    \ : lazy_segtree(0) {}\n  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n    size = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    lz = std::vector<F>(size,\
    \ id());\n    for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    for (int i\
    \ = size - 1; i >= 1; i--) {\n      update(i);\n    }\n  }\n\n  void set(int p,\
    \ S x) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) {\n    assert(0 <= p && p < _n);\n  \
    \  p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n\
    \  }\n\n  S prod(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n \
    \   if (l == r) return e();\n\n    l += size;\n    r += size;\n\n    for (int\
    \ i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n   \
    \   if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    S sml = e(), smr\
    \ = e();\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n     \
    \ if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n    }\n\n\
    \    return op(sml, smr);\n  }\n\n  S all_prod() { return d[1]; }\n\n  void apply(int\
    \ p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = mapping(f, d[p]);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n  void apply(int l, int r, F f) {\n   \
    \ assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\n    l += size;\n\
    \    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if\
    \ (l & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r, f);\n        l\
    \ >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n \
    \   for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l\
    \ >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n\
    \  template <bool (*g)(S)>\n  int max_right(int l) {\n    return max_right(l,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int max_right(int l,\
    \ G g) {\n    assert(0 <= l && l <= _n);\n    assert(g(e()));\n    if (l == _n)\
    \ return _n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    S sm = e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n  \
    \          l++;\n          }\n        }\n        return l - size;\n      }\n \
    \     sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l) != l);\n    return\
    \ _n;\n  }\n\n  template <bool (*g)(S)>\n  int min_left(int r) {\n    return min_left(r,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int min_left(int r,\
    \ G g) {\n    assert(0 <= r && r <= _n);\n    assert(g(e()));\n    if (r == 0)\
    \ return 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >>\
    \ i);\n    S sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r\
    \ >>= 1;\n      if (!g(op(d[r], sm))) {\n        while (r < size) {\n        \
    \  push(r);\n          r = (2 * r + 1);\n          if (g(op(d[r], sm))) {\n  \
    \          sm = op(d[r], sm);\n            r--;\n          }\n        }\n    \
    \    return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n, size, log;\n  std::vector<S>\
    \ d;\n  std::vector<F> lz;\n\n  void update(int k) { d[k] = op(d[2 * k], d[2 *\
    \ k + 1]); }\n  void all_apply(int k, F f) {\n    d[k] = mapping(f, d[k]);\n \
    \   if (k < size) lz[k] = composition(f, lz[k]);\n  }\n  void push(int k) {\n\
    \    all_apply(2 * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n    lz[k] = id();\n\
    \  }\n};\n"
  code: "\ntemplate <class S,\n          auto op,\n          auto e,\n          class\
    \ F,\n          auto mapping,\n          auto composition,\n          auto id>\n\
    struct lazy_segtree {\n private:\n  unsigned int seg_bit_ceil(unsigned int n)\
    \ {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n    return\
    \ x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  static_assert(\n\
    \      std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,\n   \
    \   \"mapping must work as F(F, S)\");\n  static_assert(\n      std::is_convertible_v<decltype(composition),\
    \ std::function<F(F, F)>>,\n      \"compostiion must work as F(F, F)\");\n  static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                \"id must work as F()\");\n  lazy_segtree()\
    \ : lazy_segtree(0) {}\n  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n    size = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    lz = std::vector<F>(size,\
    \ id());\n    for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    for (int i\
    \ = size - 1; i >= 1; i--) {\n      update(i);\n    }\n  }\n\n  void set(int p,\
    \ S x) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) {\n    assert(0 <= p && p < _n);\n  \
    \  p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n\
    \  }\n\n  S prod(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n \
    \   if (l == r) return e();\n\n    l += size;\n    r += size;\n\n    for (int\
    \ i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n   \
    \   if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    S sml = e(), smr\
    \ = e();\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n     \
    \ if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n    }\n\n\
    \    return op(sml, smr);\n  }\n\n  S all_prod() { return d[1]; }\n\n  void apply(int\
    \ p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = mapping(f, d[p]);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n  void apply(int l, int r, F f) {\n   \
    \ assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\n    l += size;\n\
    \    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if\
    \ (l & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r, f);\n        l\
    \ >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n \
    \   for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l\
    \ >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n\
    \  template <bool (*g)(S)>\n  int max_right(int l) {\n    return max_right(l,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int max_right(int l,\
    \ G g) {\n    assert(0 <= l && l <= _n);\n    assert(g(e()));\n    if (l == _n)\
    \ return _n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    S sm = e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(op(sm, d[l]))) {\n            sm = op(sm, d[l]);\n  \
    \          l++;\n          }\n        }\n        return l - size;\n      }\n \
    \     sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l) != l);\n    return\
    \ _n;\n  }\n\n  template <bool (*g)(S)>\n  int min_left(int r) {\n    return min_left(r,\
    \ [](S x) { return g(x); });\n  }\n  template <class G>\n  int min_left(int r,\
    \ G g) {\n    assert(0 <= r && r <= _n);\n    assert(g(e()));\n    if (r == 0)\
    \ return 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >>\
    \ i);\n    S sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r\
    \ >>= 1;\n      if (!g(op(d[r], sm))) {\n        while (r < size) {\n        \
    \  push(r);\n          r = (2 * r + 1);\n          if (g(op(d[r], sm))) {\n  \
    \          sm = op(d[r], sm);\n            r--;\n          }\n        }\n    \
    \    return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n, size, log;\n  std::vector<S>\
    \ d;\n  std::vector<F> lz;\n\n  void update(int k) { d[k] = op(d[2 * k], d[2 *\
    \ k + 1]); }\n  void all_apply(int k, F f) {\n    d[k] = mapping(f, d[k]);\n \
    \   if (k < size) lz[k] = composition(f, lz[k]);\n  }\n  void push(int k) {\n\
    \    all_apply(2 * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n    lz[k] = id();\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/LazySegmentTree.hpp
  requiredBy:
  - data-structure/segment-tree/query/RangeUpdateRangeMin.hpp
  - data-structure/segment-tree/query/RangeUpdateRangeMax.hpp
  - data-structure/segment-tree/query/RangeAddRangeSum.hpp
  - data-structure/segment-tree/query/RangeAddRangeMin.hpp
  - data-structure/segment-tree/query/RangeLinearUpdateRangeMinMaxSum.hpp
  - data-structure/segment-tree/query/RangeUpdateRangeSum.hpp
  - data-structure/segment-tree/query/RangeLinearAddRangeSum.hpp
  - data-structure/segment-tree/query/RangeAddRangeMax.hpp
  - data-structure/others/AreaofUnionofRectangles.hpp
  timestamp: '2024-06-26 17:49:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
  - verify/AizuOnlineJudge/graph/tree/GRL_5_E.test.cpp
  - verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_F.test.cpp
documentation_of: data-structure/segment-tree/LazySegmentTree.hpp
layout: document
title: Lazy Segment Tree
---

## 概要

todo

## 計算量
todo