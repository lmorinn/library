---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/AreaofUnionofRectangles.hpp
    title: Area of Union of Rectangles
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing lint = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n#define\
    \ all(x) (x).begin(), (x).end()\n#define uniqv(v) v.erase(unique(all(v)), v.end())\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP1(i, n) for (auto\
    \ i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))\n#define REP2(i, l, r) for\
    \ (auto i = (l); (i) != (r); ++(i))\n#define rep(...) OVERLOAD_REP(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define logfixed(x) cout << fixed << setprecision(10)\
    \ << x << endl;\n\nostream &operator<<(ostream &dest, __int128_t value) {\n  ostream::sentry\
    \ s(dest);\n  if (s) {\n    __uint128_t tmp = value < 0 ? -value : value;\n  \
    \  char buffer[128];\n    char *d = end(buffer);\n    do {\n      --d;\n     \
    \ *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n    } while (tmp != 0);\n\
    \    if (value < 0) {\n      --d;\n      *d = '-';\n    }\n    int len = end(buffer)\
    \ - d;\n    if (dest.rdbuf()->sputn(d, len) != len) {\n      dest.setstate(ios_base::badbit);\n\
    \    }\n  }\n  return dest;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n  for (int i = 0; i < (int)v.size(); i++) {\n  \
    \  os << v[i] << (i + 1 != (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\n  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os\
    \ << *itr;\n    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n\
    \  }\n  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const unordered_set<T> &set_var) {\n  for (auto itr = set_var.begin(); itr !=\
    \ set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr != set_var.end())\
    \ os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const map<T, U> &map_var) {\n  for (auto\
    \ itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os << itr->first\
    \ << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const unordered_map<T, U> &map_var)\
    \ {\n  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os\
    \ << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\
    \ntemplate <typename T, typename U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &pair_var) {\n  os << pair_var.first << \" \" << pair_var.second;\n  return\
    \ os;\n}\n\nvoid out() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid\
    \ out(const T &a, const Ts &...b) {\n  cout << a;\n  (cout << ... << (cout <<\
    \ ' ', b));\n  cout << '\\n';\n}\n\nvoid outf() { cout << '\\n'; }\ntemplate <class\
    \ T, class... Ts>\nvoid outf(const T &a, const Ts &...b) {\n  cout << fixed <<\
    \ setprecision(14) << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\\
    n';\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v)\
    \ {\n  for (T &in : v) is >> in;\n  return is;\n}\n\ninline void in(void) { return;\
    \ }\ntemplate <typename First, typename... Rest>\nvoid in(First &first, Rest &...rest)\
    \ {\n  cin >> first;\n  in(rest...);\n  return;\n}\n\ntemplate <typename T>\n\
    bool chmax(T &a, const T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <typename T>\nbool chmin(T &a, const T &b)\
    \ {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\n\
    vector<lint> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1,\
    \ 1, 0, -1, -1, -1};\nvector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0,\
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#line 1 \"data-structure/segment-tree/LazySegmentTree.hpp\"\n\ntemplate <class\
    \ S,\n          auto op,\n          auto e,\n          class F,\n          auto\
    \ mapping,\n          auto composition,\n          auto id>\nstruct lazy_segtree\
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
    \  }\n};\n#line 3 \"data-structure/others/AreaofUnionofRectangles.hpp\"\nusing\
    \ Sa = pair<int, long long>;\nusing Fa = int;\nSa opa(Sa a, Sa b) {\n  if (a.first\
    \ < b.first) return a;\n  if (a.first > b.first) return b;\n  return {a.first,\
    \ a.second + b.second};\n}\n\nSa ea() {\n  return {1e9 + 1e5, 0};\n}\n\nSa mappinga(Fa\
    \ f, Sa x) {\n  return {x.first + f, x.second};\n}\n\nFa compositiona(Fa f, Fa\
    \ g) {\n  return f + g;\n}\n\nFa ida() {\n  return 0;\n}\n\nclass AreaofUnionofRectangles\
    \ {\n private:\n  vector<long long> x1, x2, y1, y2;\n  int n;\n  lint res = 0;\n\
    \n public:\n  AreaofUnionofRectangles(const vector<long long> &xl, const vector<long\
    \ long> &xr, const vector<long long> &yl, const vector<long long> &yr) {\n   \
    \ x1 = xl;\n    x2 = xr;\n    y1 = yl;\n    y2 = yr;\n    n = x1.size();\n   \
    \ vector<int> cmp(n * 2);\n    vector<tuple<long long, int, int, int>> q(n * 2);\n\
    \    for (int i = 0; i < n; i++) {\n      cmp[i * 2] = y1[i];\n      cmp[i * 2\
    \ + 1] = y2[i];\n    }\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    for (int i = 0; i < n; i++) {\n      int idx1 =\
    \ distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y1[i]));\n      int\
    \ idx2 = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y2[i]));\n\
    \      q[i * 2] = {x1[i], 1, idx1, idx2};\n      q[i * 2 + 1] = {x2[i], -1, idx1,\
    \ idx2};\n    }\n\n    sort(q.begin(), q.end());\n    int siz = cmp.size() - 1;\n\
    \    vector<Sa> v(siz);\n    for (int i = 0; i < siz; i++) {\n      v[i] = {0,\
    \ cmp[i + 1] - cmp[i]};\n    }\n\n    lazy_segtree<Sa, opa, ea, Fa, mappinga,\
    \ compositiona, ida> seg(v);\n    long long prev = get<0>(q[0]);\n    for (int\
    \ i = 0; i < n * 2; i++) {\n      long long x = get<0>(q[i]);\n      int f = get<1>(q[i]);\n\
    \      long long l = get<2>(q[i]);\n      long long r = get<3>(q[i]);\n      long\
    \ long h = x - prev;\n      long long w = cmp[siz] - cmp[0];\n      Sa pr = seg.all_prod();\n\
    \      if (pr.first == 0) w -= pr.second;\n      res += h * w;\n      prev = x;\n\
    \      seg.apply(l, r, f);\n    }\n  }\n\n  lint ans() {\n    return res;\n  }\n\
    };\n#line 4 \"verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp\"\
    \n\nusing S = lint;\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n;\n\
    \  in(n);\n  vector<lint> x1(n), x2(n), y1(n), y2(n);\n  rep(i, n) {\n    in(x1[i],\
    \ y1[i], x2[i], y2[i]);\n  }\n  AreaofUnionofRectangles t(x1, x2, y1, y2);\n \
    \ out(t.ans());\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#include \"../../../../data-structure/others/AreaofUnionofRectangles.hpp\"\n\
    \nusing S = lint;\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n;\n\
    \  in(n);\n  vector<lint> x1(n), x2(n), y1(n), y2(n);\n  rep(i, n) {\n    in(x1[i],\
    \ y1[i], x2[i], y2[i]);\n  }\n  AreaofUnionofRectangles t(x1, x2, y1, y2);\n \
    \ out(t.ans());\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/others/AreaofUnionofRectangles.hpp
  - data-structure/segment-tree/LazySegmentTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
  requiredBy: []
  timestamp: '2024-11-22 13:46:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
- /verify/verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp.html
title: verify/LibraryChecker/data-structure/others/AreaofUnionofRectangles.test.cpp
---
