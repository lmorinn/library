---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \  }\n};\n#line 2 \"data-structure/segment-tree/query/RangeLinearUpdateRangeMinMaxSum.hpp\"\
    \n\nclass RangeLinearUpdate {\n private:\n  static constexpr long long INF = 8e18;\n\
    \  static constexpr int INFI = int(1e9) + 10;\n\n  struct S {\n    long long mi,\
    \ mx, sum;\n    int l, r;\n  };\n  struct F {\n    long long a, b;\n  };\n\n \
    \ static S op(S a, S b) {\n    return S{min(a.mi, b.mi), max(a.mx, b.mx), a.sum\
    \ + b.sum, min(a.l, b.l), max(a.r, b.r)};\n  }\n  static S e() {\n    return S{INF,\
    \ -INF, 0, INFI, -INFI};\n  }\n\n  static S mapping(F f, S s) {\n    if (f.a ==\
    \ INF) return s;\n    if (f.a >= 0) {\n      return S{f.a * s.l + f.b, f.a * (s.r\
    \ - 1) + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n\
    \    } else {\n      return S{f.a * (s.r - 1) + f.b, f.a * s.l + f.b, (f.a * (s.l\
    \ + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n    }\n  }\n\n  static\
    \ F composition(F f, F g) {\n    return f.a == INF ? g : f;\n  }\n\n  static F\
    \ id() {\n    return F{INF, INF};\n  }\n\n  lazy_segtree<S, op, e, F, mapping,\
    \ composition, id> seg;\n\n public:\n  RangeLinearUpdate(const vector<long long>\
    \ &v) {\n    int n = int(v.size());\n    vector<S> tmp(n);\n    for (int i = 0;\
    \ i < n; i++) {\n      tmp[i].l = i;\n      tmp[i].r = i + 1;\n      tmp[i].mi\
    \ = tmp[i].mx = tmp[i].sum = v[i];\n    }\n    seg = lazy_segtree<S, op, e, F,\
    \ mapping, composition, id>(tmp);\n  }\n\n  void set(int i, S x) {\n    seg.set(i,\
    \ x);\n  }\n  S get(int i) {\n    return seg.get(i);\n  }\n  S all_prod() {\n\
    \    return seg.all_prod();\n  }\n  S prod(int l, int r) {\n    return seg.prod(l,\
    \ r);\n  }\n  void apply(int l, int r, F f) {\n    seg.apply(l, r, F{f.a, f.b\
    \ - f.a * get(l).l});\n  }\n  void apply(int i, F f) {\n    seg.apply(i, F{f.a,\
    \ f.b - f.a * get(i).l});\n  }\n\n  template <bool (*g)(S)>\n  int max_right(int\
    \ l) {\n    return seg.max_right(l, [](S x) { return g(x); });\n  }\n  template\
    \ <bool (*g)(S)>\n  int min_left(int r) {\n    return seg.min_left(r, [](S x)\
    \ { return g(x); });\n  }\n};\n"
  code: "#include \"../LazySegmentTree.hpp\"\n\nclass RangeLinearUpdate {\n private:\n\
    \  static constexpr long long INF = 8e18;\n  static constexpr int INFI = int(1e9)\
    \ + 10;\n\n  struct S {\n    long long mi, mx, sum;\n    int l, r;\n  };\n  struct\
    \ F {\n    long long a, b;\n  };\n\n  static S op(S a, S b) {\n    return S{min(a.mi,\
    \ b.mi), max(a.mx, b.mx), a.sum + b.sum, min(a.l, b.l), max(a.r, b.r)};\n  }\n\
    \  static S e() {\n    return S{INF, -INF, 0, INFI, -INFI};\n  }\n\n  static S\
    \ mapping(F f, S s) {\n    if (f.a == INF) return s;\n    if (f.a >= 0) {\n  \
    \    return S{f.a * s.l + f.b, f.a * (s.r - 1) + f.b, (f.a * (s.l + s.r - 1) +\
    \ f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n    } else {\n      return S{f.a * (s.r\
    \ - 1) + f.b, f.a * s.l + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l)\
    \ / 2, s.l, s.r};\n    }\n  }\n\n  static F composition(F f, F g) {\n    return\
    \ f.a == INF ? g : f;\n  }\n\n  static F id() {\n    return F{INF, INF};\n  }\n\
    \n  lazy_segtree<S, op, e, F, mapping, composition, id> seg;\n\n public:\n  RangeLinearUpdate(const\
    \ vector<long long> &v) {\n    int n = int(v.size());\n    vector<S> tmp(n);\n\
    \    for (int i = 0; i < n; i++) {\n      tmp[i].l = i;\n      tmp[i].r = i +\
    \ 1;\n      tmp[i].mi = tmp[i].mx = tmp[i].sum = v[i];\n    }\n    seg = lazy_segtree<S,\
    \ op, e, F, mapping, composition, id>(tmp);\n  }\n\n  void set(int i, S x) {\n\
    \    seg.set(i, x);\n  }\n  S get(int i) {\n    return seg.get(i);\n  }\n  S all_prod()\
    \ {\n    return seg.all_prod();\n  }\n  S prod(int l, int r) {\n    return seg.prod(l,\
    \ r);\n  }\n  void apply(int l, int r, F f) {\n    seg.apply(l, r, F{f.a, f.b\
    \ - f.a * get(l).l});\n  }\n  void apply(int i, F f) {\n    seg.apply(i, F{f.a,\
    \ f.b - f.a * get(i).l});\n  }\n\n  template <bool (*g)(S)>\n  int max_right(int\
    \ l) {\n    return seg.max_right(l, [](S x) { return g(x); });\n  }\n  template\
    \ <bool (*g)(S)>\n  int min_left(int r) {\n    return seg.min_left(r, [](S x)\
    \ { return g(x); });\n  }\n};"
  dependsOn:
  - data-structure/segment-tree/LazySegmentTree.hpp
  isVerificationFile: false
  path: data-structure/segment-tree/query/RangeLinearUpdateRangeMinMaxSum.hpp
  requiredBy: []
  timestamp: '2025-06-25 02:49:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segment-tree/query/RangeLinearUpdateRangeMinMaxSum.hpp
layout: document
title: Range Linear Update Range Min Max Sum
---

## 概要

todo

## 計算量
todo