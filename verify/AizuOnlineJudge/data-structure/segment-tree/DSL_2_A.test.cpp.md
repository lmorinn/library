---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/SegmentTree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n#line 2 \"data-structure/segment-tree/SegmentTree.hpp\"\
    \ntemplate <class S, auto op, auto e>\nstruct segtree {\n private:\n  unsigned\
    \ int seg_bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x <\
    \ (unsigned int)(n)) x *= 2;\n    return x;\n  }\n\n public:\n  static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                \"op must work as S(S, S)\");\n  static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\n                \"e must work as S()\");\n  segtree()\
    \ : segtree(0) {}\n  explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n    size\
    \ = (int)seg_bit_ceil((unsigned int)(_n));\n    log = __builtin_ctz((unsigned\
    \ int)size);\n    d = std::vector<S>(2 * size, e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i >= 1; i--) {\n  \
    \    update(i);\n    }\n  }\n\n  void set(int p, S x) {\n    assert(0 <= p &&\
    \ p < _n);\n    p += size;\n    d[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  S get(int p) const {\n    assert(0 <= p && p < _n);\n\
    \    return d[p + size];\n  }\n\n  S prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= _n);\n    S sml = e(), smr = e();\n    l += size;\n \
    \   r += size;\n\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1;\n      r >>= 1;\n   \
    \ }\n    return op(sml, smr);\n  }\n\n  S all_prod() const { return d[1]; }\n\n\
    \  template <bool (*f)(S)>\n  int max_right(int l) const {\n    return max_right(l,\
    \ [](S x) { return f(x); });\n  }\n  template <class F>\n  int max_right(int l,\
    \ F f) const {\n    assert(0 <= l && l <= _n);\n    assert(f(e()));\n    if (l\
    \ == _n) return _n;\n    l += size;\n    S sm = e();\n    do {\n      while (l\
    \ % 2 == 0) l >>= 1;\n      if (!f(op(sm, d[l]))) {\n        while (l < size)\
    \ {\n          l = (2 * l);\n          if (f(op(sm, d[l]))) {\n            sm\
    \ = op(sm, d[l]);\n            l++;\n          }\n        }\n        return l\
    \ - size;\n      }\n      sm = op(sm, d[l]);\n      l++;\n    } while ((l & -l)\
    \ != l);\n    return _n;\n  }\n\n  template <bool (*f)(S)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](S x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n    S sm = e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r],\
    \ sm))) {\n        while (r < size) {\n          r = (2 * r + 1);\n          if\
    \ (f(op(d[r], sm))) {\n            sm = op(d[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = op(d[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n private:\n  int _n,\
    \ size, log;\n  std::vector<S> d;\n\n  void update(int k) { d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n};\n#line 6 \"verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp\"\
    \n\nusing S = int;\nS op(S a, S b) {\n  return min(a, b);\n}\n\nS e() {\n  return\
    \ (1LL << 31) - 1;\n}\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<S> v(n, e());\n  segtree<S, op, e> seg(v);\n\
    \n  for (int i = 0; i < q; i++) {\n    int com, x, y;\n    cin >> com >> x >>\
    \ y;\n    if (com == 0) {\n      seg.set(x, y);\n    } else if (com == 1) {\n\
    \      cout << seg.prod(x, y + 1) << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n#include \"../../../../data-structure/segment-tree/SegmentTree.hpp\"\
    \n\nusing S = int;\nS op(S a, S b) {\n  return min(a, b);\n}\n\nS e() {\n  return\
    \ (1LL << 31) - 1;\n}\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<S> v(n, e());\n  segtree<S, op, e> seg(v);\n\
    \n  for (int i = 0; i < q; i++) {\n    int com, x, y;\n    cin >> com >> x >>\
    \ y;\n    if (com == 0) {\n      seg.set(x, y);\n    } else if (com == 1) {\n\
    \      cout << seg.prod(x, y + 1) << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - data-structure/segment-tree/SegmentTree.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 17:49:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
- /verify/verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp.html
title: verify/AizuOnlineJudge/data-structure/segment-tree/DSL_2_A.test.cpp
---
