---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
    title: Wavelet Matrix (Template)
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc379/tasks/abc379_f
    links:
    - https://atcoder.jp/contests/abc379/tasks/abc379_f
  bundledCode: "#line 1 \"verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp\"\
    \n\n#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing lint = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing int128 = __int128_t;\n#define all(x) (x).begin(),\
    \ (x).end()\n#define uniqv(v) v.erase(unique(all(v)), v.end())\n#define OVERLOAD_REP(_1,\
    \ _2, _3, name, ...) name\n#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{};\
    \ (i) != (n); ++(i))\n#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))\n\
    #define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define logfixed(x)\
    \ cout << fixed << setprecision(10) << x << endl;\n\nostream &operator<<(ostream\
    \ &dest, __int128_t value) {\n  ostream::sentry s(dest);\n  if (s) {\n    __uint128_t\
    \ tmp = value < 0 ? -value : value;\n    char buffer[128];\n    char *d = end(buffer);\n\
    \    do {\n      --d;\n      *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n\
    \    } while (tmp != 0);\n    if (value < 0) {\n      --d;\n      *d = '-';\n\
    \    }\n    int len = end(buffer) - d;\n    if (dest.rdbuf()->sputn(d, len) !=\
    \ len) {\n      dest.setstate(ios_base::badbit);\n    }\n  }\n  return dest;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T> &v)\
    \ {\n  for (int i = 0; i < (int)v.size(); i++) {\n    os << v[i] << (i + 1 !=\
    \ (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, const set<T> &set_var) {\n  for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr !=\
    \ set_var.end()) os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &set_var) {\n  for\
    \ (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os << *itr;\n\
    \    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n  }\n  return\
    \ os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const map<T, U> &map_var) {\n  for (auto itr = map_var.begin(); itr != map_var.end();\
    \ itr++) {\n    os << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n\
    \  return os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const unordered_map<T, U> &map_var) {\n  for (auto itr = map_var.begin();\
    \ itr != map_var.end(); itr++) {\n    os << itr->first << \" -> \" << itr->second\
    \ << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &pair_var) {\n  os << pair_var.first\
    \ << \" \" << pair_var.second;\n  return os;\n}\n\nvoid out() { cout << '\\n';\
    \ }\ntemplate <class T, class... Ts>\nvoid out(const T &a, const Ts &...b) {\n\
    \  cout << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\nvoid\
    \ outf() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid outf(const\
    \ T &a, const Ts &...b) {\n  cout << fixed << setprecision(14) << a;\n  (cout\
    \ << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\ntemplate <typename T>\n\
    istream &operator>>(istream &is, vector<T> &v) {\n  for (T &in : v) is >> in;\n\
    \  return is;\n}\n\ninline void in(void) { return; }\ntemplate <typename First,\
    \ typename... Rest>\nvoid in(First &first, Rest &...rest) {\n  cin >> first;\n\
    \  in(rest...);\n  return;\n}\n\ntemplate <typename T>\nbool chmax(T &a, const\
    \ T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n\
    }\ntemplate <typename T>\nbool chmin(T &a, const T &b) {\n  if (a > b) {\n   \
    \ a = b;\n    return true;\n  }\n  return false;\n}\n\nvector<lint> dx8 = {1,\
    \ 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    vector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0, 1, 0, -1};\n\n#pragma\
    \ endregion\n#line 3 \"verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc379/tasks/abc379_f\"\n#line\
    \ 1 \"data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp\"\nstruct BitVector\
    \ {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned> bit, sum;\n\n \
    \ BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class T>\nclass WaveletMatrix {\n private:\n  unsigned n;\n  unsigned bitsize;\n\
    \  vector<BitVector> b;\n  vector<unsigned> zero;\n  vector<T> cmp;\n  T MI, MA;\n\
    \n  inline unsigned compress(const T &x) {\n    return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n  WaveletMatrix() {}\n  WaveletMatrix(const vector<T> &v) {\n  \
    \  MI = numeric_limits<T>::min();\n    MA = numeric_limits<T>::max();\n    n =\
    \ v.size();\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n    vector<unsigned> compressed(n);\n    vector<unsigned>\
    \ tmpc(n);\n    unsigned size_mx = v.size();\n    for (unsigned i = 0; i < n;\
    \ i++) {\n      compressed[i] = compress(v[i]);\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize);\n    zero.assign(bitsize, 0);\n    int cur = 0;\n\n  \
    \  for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector(n + 1);\n\
    \      cur = 0;\n      for (unsigned j = 0; j < n; j++) {\n        if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n        } else {\n \
    \         zero[i]++;\n          tmpc[cur] = compressed[j];\n          cur++;\n\
    \        }\n      }\n      b[i].build();\n\n      for (unsigned j = 0; j < n;\
    \ j++) {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n         \
    \ tmpc[cur] = compressed[j];\n          cur++;\n        }\n      }\n      swap(tmpc,\
    \ compressed);\n    }\n  }\n\n  // get v[k]\n  T access(unsigned k) {\n    unsigned\
    \ res = 0;\n    unsigned cur = k;\n    for (unsigned i = 0; i < bitsize; i++)\
    \ {\n      if (b[i].access(cur)) {\n        res |= (1U << (bitsize - i - 1));\n\
    \        cur = zero[i] + b[i].rank(cur);\n      } else {\n        cur -= b[i].rank(cur);\n\
    \      }\n    }\n    return cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\
    \u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\n  T kth_smallest(unsigned\
    \ l, unsigned r, unsigned k) {\n    unsigned res = 0;\n    unsigned rank1_l, rank1_r,\
    \ num0;\n    for (unsigned i = 0; i < bitsize; i++) {\n      rank1_l = b[i].rank(l);\n\
    \      rank1_r = b[i].rank(r);\n      num0 = r - l - (rank1_r - rank1_l);\n  \
    \    if (num0 < k) {\n        res |= (1U << (bitsize - i - 1));\n        l = zero[i]\
    \ + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n      } else\
    \ {\n        l -= rank1_l;\n        r -= rank1_r;\n      }\n    }\n    return\
    \ cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\
    \u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n  T kth_largest(unsigned l, unsigned\
    \ r, unsigned k) {\n    return kth_smallest(l, r, r - l - k + 1);\n  }\n\n  //\
    \ v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\n  unsigned range_freq(int vl, int vr, T mink, T maxk) {\n\
    \    int D = compress(mink);\n    int U = compress(maxk);\n    unsigned res =\
    \ 0;\n    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void\
    \ {\n      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n   \
    \     res += (R - L);\n        return;\n      }\n      if (d == bitsize) {\n \
    \       if (D <= A and A < U) {\n          res += (R - L);\n        }\n      \
    \  return;\n      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r)\u306E\u4E2D\
    \u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\
    \n  T prev_value(unsigned l, unsigned r, T val) {\n    int num = range_freq(l,\
    \ r, MI, val);\n    if (num == 0) {\n      return MA;\n    } else {\n      return\
    \ kth_smallest(l, r, num);\n    }\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n  T next_value(unsigned\
    \ l, unsigned r, T val) {\n    int num = range_freq(l, r, MI, val);\n    if (num\
    \ == r - l) {\n      return MI;\n    } else {\n      return kth_smallest(l, r,\
    \ num + 1);\n    }\n  }\n};\n#line 5 \"verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n, q);\n\
    \  vector<int> h(n);\n  vector<int> a(n, -1e9);\n  in(h);\n  stack<pair<int, int>>\
    \ s;\n  for (int i = n - 1; i >= 0; i--) {\n    while (!s.empty() and s.top().first\
    \ < h[i]) {\n      a[s.top().second] = i - 1;\n      s.pop();\n    }\n    s.push({h[i],\
    \ i});\n  }\n\n  WaveletMatrix<int> w(a);\n  rep(i, q) {\n    int l, r;\n    in(l,\
    \ r);\n    out(w.range_freq(r, n, INT_MIN, l - 1));\n  }\n}\n"
  code: "\n#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc379/tasks/abc379_f\"\
    \n#include \"../../../../data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  in(n, q);\n\
    \  vector<int> h(n);\n  vector<int> a(n, -1e9);\n  in(h);\n  stack<pair<int, int>>\
    \ s;\n  for (int i = n - 1; i >= 0; i--) {\n    while (!s.empty() and s.top().first\
    \ < h[i]) {\n      a[s.top().second] = i - 1;\n      s.pop();\n    }\n    s.push({h[i],\
    \ i});\n  }\n\n  WaveletMatrix<int> w(a);\n  rep(i, q) {\n    int l, r;\n    in(l,\
    \ r);\n    out(w.range_freq(r, n, INT_MIN, l - 1));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/wavelet-matrix/WaveletMatrixTemplate.hpp
  isVerificationFile: true
  path: verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp
  requiredBy: []
  timestamp: '2024-11-14 22:32:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp
layout: document
redirect_from:
- /verify/verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp
- /verify/verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp.html
title: verify/AtCoder/data-structure/wavelet-matrix/Buildings2.test.cpp
---
