---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/segment-tree/ACLSegmentTreeBeatsChminChmax.hpp
    title: Segment Tree Beats (ACL-based)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree/ACLSegmentTreeBeatsChminChmax.hpp\"\
    \n\ntemplate <class S,\n          auto op,\n          auto e,\n          class\
    \ F,\n          auto mapping,\n          auto composition,\n          auto id>\n\
    struct segtree_beats {\n   private:\n    unsigned int seg_bit_ceil(unsigned int\
    \ n) {\n        unsigned int x = 1;\n        while (x < (unsigned int)(n)) x *=\
    \ 2;\n        return x;\n    }\n\n   public:\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                  \"op must work as S(S, S)\");\n\
    \    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,\n \
    \                 \"e must work as S()\");\n    static_assert(\n        std::is_convertible_v<decltype(mapping),\
    \ std::function<S(F, S)>>,\n        \"mapping must work as F(F, S)\");\n    static_assert(\n\
    \        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,\n\
    \        \"compostiion must work as F(F, F)\");\n    static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                  \"id must work as F()\");\n    segtree_beats()\
    \ : segtree_beats(0) {}\n    explicit segtree_beats(int n) : segtree_beats(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree_beats(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = (int)seg_bit_ceil((unsigned int)(_n));\n        log = __builtin_ctz((unsigned\
    \ int)size);\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n\
    \        assert(0 <= p && p < _n);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool\
    \ (*g)(S)>\n    int max_right(int l) {\n        return max_right(l, [](S x) {\
    \ return g(x); });\n    }\n    template <class G>\n    int max_right(int l, G\
    \ g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n        if\
    \ (l == _n) return _n;\n        l += size;\n        for (int i = log; i >= 1;\
    \ i--) push(l >> i);\n        S sm = e();\n        do {\n            while (l\
    \ % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    push(l);\n                    l = (2 * l);\n\
    \                    if (g(op(sm, d[l]))) {\n                        sm = op(sm,\
    \ d[l]);\n                        l++;\n                    }\n              \
    \  }\n                return l - size;\n            }\n            sm = op(sm,\
    \ d[l]);\n            l++;\n        } while ((l & -l) != l);\n        return _n;\n\
    \    }\n\n    template <bool (*g)(S)>\n    int min_left(int r) {\n        return\
    \ min_left(r, [](S x) { return g(x); });\n    }\n    template <class G>\n    int\
    \ min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n\
    \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
    \ i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    push(r);\n\
    \                    r = (2 * r + 1);\n                    if (g(op(d[r], sm)))\
    \ {\n                        sm = op(d[r], sm);\n                        r--;\n\
    \                    }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n   private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) {\n            lz[k] = composition(f, lz[k]);\n       \
    \     if (d[k].fail) push(k), update(k);\n        }\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n#line 2 \"data-structure/segment-tree/query/RangeBitwiseORBitwiseAND.hpp\"\
    \n\nstruct S {\n    int mxpopcnt;\n    int mxnum;\n    uint64_t range_or, range_and;\n\
    \    bool fail;\n    S(uint64_t x = 0) : mxpopcnt(__builtin_popcountll(x)), mxnum(1),\
    \ range_or(x), range_and(x), fail(false) {}\n};\n\nS e() {\n    S ret(0ull);\n\
    \    ret.range_and = ~0ull;\n    ret.mxnum = 0;\n    return ret;\n}\nS op(S a,\
    \ S b) {\n    a.range_or |= b.range_or;\n    a.range_and &= b.range_and;\n   \
    \ if (a.mxpopcnt < b.mxpopcnt) {\n        a.mxpopcnt = b.mxpopcnt;\n        a.mxnum\
    \ = b.mxnum;\n    } else if (a.mxpopcnt == b.mxpopcnt) {\n        a.mxnum += b.mxnum;\n\
    \    }\n    a.fail = false;\n    return a;\n}\n\nstruct F {\n    uint64_t bit_or,\
    \ bit_and;\n    F() : bit_or(0ull), bit_and(~0ull) {}\n    F(uint64_t o, uint64_t\
    \ a) : bit_or(o), bit_and(a) {}\n};\n\nS mapping(F f, S x) {\n    if ((x.range_and\
    \ ^ x.range_or) & (~f.bit_and | f.bit_or)) {\n        x.fail = true;\n       \
    \ return x;\n    }\n    x.mxpopcnt -= __builtin_popcountll(x.range_and & ~f.bit_and);\n\
    \    x.range_and &= f.bit_and;\n    x.range_or &= f.bit_and;\n    x.mxpopcnt +=\
    \ __builtin_popcountll(~x.range_or & f.bit_or);\n    x.range_and |= f.bit_or;\n\
    \    x.range_or |= f.bit_or;\n    return x;\n}\n\nF composition(F g, F f) {\n\
    \    return {g.bit_or | (g.bit_and & f.bit_or), g.bit_and & f.bit_and};\n}\n\n\
    F id() { return F(); }\n\nclass Rangebitwise {\n   private:\n    segtree_beats<S,\
    \ op, e, F, mapping, composition, id> seg;\n\n   public:\n    Rangebitwise() {}\n\
    \    Rangebitwise(const vector<uint64_t>& a) {\n        int n = int(a.size());\n\
    \        vector<S> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i].range_and\
    \ = v[i].range_or = a[i];\n            v[i].mxpopcnt = __builtin_popcountll(a[i]);\n\
    \            v[i].mxnum = 1;\n            v[i].fail = false;\n        }\n    \
    \    seg = segtree_beats<S, op, e, F, mapping, composition, id>(v);\n    }\n\n\
    \    void apply_bitwise_or(int l, int r, uint64_t x) {\n        seg.apply(l, r,\
    \ {x, ULLONG_MAX});\n    }\n\n    void apply_bitwise_and(int l, int r, uint64_t\
    \ x) {\n        seg.apply(l, r, {0ull, x});\n    }\n\n    pair<int, int> max_popcount(int\
    \ l, int r) {\n        S res = seg.prod(l, r);\n        return {res.mxpopcnt,\
    \ res.mxnum};\n    }\n};\n"
  code: "#include \"../ACLSegmentTreeBeatsChminChmax.hpp\"\n\nstruct S {\n    int\
    \ mxpopcnt;\n    int mxnum;\n    uint64_t range_or, range_and;\n    bool fail;\n\
    \    S(uint64_t x = 0) : mxpopcnt(__builtin_popcountll(x)), mxnum(1), range_or(x),\
    \ range_and(x), fail(false) {}\n};\n\nS e() {\n    S ret(0ull);\n    ret.range_and\
    \ = ~0ull;\n    ret.mxnum = 0;\n    return ret;\n}\nS op(S a, S b) {\n    a.range_or\
    \ |= b.range_or;\n    a.range_and &= b.range_and;\n    if (a.mxpopcnt < b.mxpopcnt)\
    \ {\n        a.mxpopcnt = b.mxpopcnt;\n        a.mxnum = b.mxnum;\n    } else\
    \ if (a.mxpopcnt == b.mxpopcnt) {\n        a.mxnum += b.mxnum;\n    }\n    a.fail\
    \ = false;\n    return a;\n}\n\nstruct F {\n    uint64_t bit_or, bit_and;\n  \
    \  F() : bit_or(0ull), bit_and(~0ull) {}\n    F(uint64_t o, uint64_t a) : bit_or(o),\
    \ bit_and(a) {}\n};\n\nS mapping(F f, S x) {\n    if ((x.range_and ^ x.range_or)\
    \ & (~f.bit_and | f.bit_or)) {\n        x.fail = true;\n        return x;\n  \
    \  }\n    x.mxpopcnt -= __builtin_popcountll(x.range_and & ~f.bit_and);\n    x.range_and\
    \ &= f.bit_and;\n    x.range_or &= f.bit_and;\n    x.mxpopcnt += __builtin_popcountll(~x.range_or\
    \ & f.bit_or);\n    x.range_and |= f.bit_or;\n    x.range_or |= f.bit_or;\n  \
    \  return x;\n}\n\nF composition(F g, F f) {\n    return {g.bit_or | (g.bit_and\
    \ & f.bit_or), g.bit_and & f.bit_and};\n}\n\nF id() { return F(); }\n\nclass Rangebitwise\
    \ {\n   private:\n    segtree_beats<S, op, e, F, mapping, composition, id> seg;\n\
    \n   public:\n    Rangebitwise() {}\n    Rangebitwise(const vector<uint64_t>&\
    \ a) {\n        int n = int(a.size());\n        vector<S> v(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            v[i].range_and = v[i].range_or = a[i];\n \
    \           v[i].mxpopcnt = __builtin_popcountll(a[i]);\n            v[i].mxnum\
    \ = 1;\n            v[i].fail = false;\n        }\n        seg = segtree_beats<S,\
    \ op, e, F, mapping, composition, id>(v);\n    }\n\n    void apply_bitwise_or(int\
    \ l, int r, uint64_t x) {\n        seg.apply(l, r, {x, ULLONG_MAX});\n    }\n\n\
    \    void apply_bitwise_and(int l, int r, uint64_t x) {\n        seg.apply(l,\
    \ r, {0ull, x});\n    }\n\n    pair<int, int> max_popcount(int l, int r) {\n \
    \       S res = seg.prod(l, r);\n        return {res.mxpopcnt, res.mxnum};\n \
    \   }\n};"
  dependsOn:
  - data-structure/segment-tree/ACLSegmentTreeBeatsChminChmax.hpp
  isVerificationFile: false
  path: data-structure/segment-tree/query/RangeBitwiseORBitwiseAND.hpp
  requiredBy: []
  timestamp: '2025-11-07 13:33:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segment-tree/query/RangeBitwiseORBitwiseAND.hpp
layout: document
title: Range Bitwise OR Bitwise AND
---

## 概要

todo

## 計算量
todo