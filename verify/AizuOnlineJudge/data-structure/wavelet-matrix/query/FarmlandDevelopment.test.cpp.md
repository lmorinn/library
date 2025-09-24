---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix/query/WaveletMatrixonHeavyLightDecomposition.hpp
    title: Wavelet Matrix on Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0489
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0489
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0489\"\
    \n#line 1 \"data-structure/wavelet-matrix/query/WaveletMatrixonHeavyLightDecomposition.hpp\"\
    \n\nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n  vector<unsigned>\
    \ bit, sum;\n\n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n\
    \    blocksize = (sz + 31) >> 5;\n    bit.assign(blocksize, 0U);\n    sum.assign(blocksize,\
    \ 0U);\n  }\n\n  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n\n\
    \  inline void build() {\n    sum[0] = 0U;\n    for (int i = 1; i < blocksize;\
    \ i++) {\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n\
    \  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k >> 5] +\
    \ __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n  }\n};\n\ntemplate\
    \ <class T>\nclass WaveletMatrix {\n private:\n public:\n  // \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n  WaveletMatrix() {}\n  WaveletMatrix(const vector<T>\
    \ &v) {\n    MI = numeric_limits<T>::min();\n    MA = numeric_limits<T>::max();\n\
    \    n = v.size();\n    cmp = v;\n    sort(cmp.begin(), cmp.end());\n    cmp.erase(unique(cmp.begin(),\
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
    \ num + 1);\n    }\n  }\n  vector<T> cmp;\n  unsigned n;\n  unsigned bitsize;\n\
    \  vector<BitVector> b;\n  vector<unsigned> zero;\n  T MI, MA;\n\n  inline unsigned\
    \ compress(const T &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) -\
    \ begin(cmp);\n  }\n};\n\ntemplate <typename T>\nclass hld_wavelet {\n private:\n\
    \  vector<int> subtree, depth, ind, parent, top;\n  vector<bool> seen;\n  vector<int>\
    \ hl;\n  int n;\n  WaveletMatrix<T> wm;\n\n  int rec_sub(vector<vector<pair<int,\
    \ int>>> &g, int cur, int d) {\n    int sub = 0;\n    for (auto nex : g[cur])\
    \ {\n      if (seen[nex.first]) continue;\n      seen[nex.first] = 1;\n      parent[nex.first]\
    \ = cur;\n      sub += rec_sub(g, nex.first, d + 1);\n    }\n    subtree[cur]\
    \ = sub + 1;\n    depth[cur] = d;\n    return subtree[cur];\n  }\n\n  void rec_hld(vector<vector<pair<int,\
    \ int>>> &g, int cur) {\n    ind[cur] = int(hl.size());\n    seen[cur] = 1;\n\
    \    hl.push_back(cur);\n    int sub = 0;\n    int idx = -1;\n    for (auto nex\
    \ : g[cur]) {\n      if (subtree[nex.first] > sub and !seen[nex.first]) {\n  \
    \      sub = subtree[nex.first];\n        idx = nex.first;\n      }\n    }\n \
    \   if (idx != -1) {\n      top[idx] = top[cur];\n      rec_hld(g, idx);\n   \
    \   for (auto nex : g[cur]) {\n        if (nex.first != idx and !seen[nex.first])\
    \ {\n          top[nex.first] = nex.first;\n          rec_hld(g, nex.first);\n\
    \        }\n      }\n    }\n  }\n\n  vector<pair<int, int>> decompose(int u, int\
    \ v) {\n    vector<pair<int, int>> res;\n    while (top[u] != top[v]) {\n    \
    \  if (depth[top[u]] < depth[top[v]]) swap(u, v);\n      res.emplace_back(ind[top[u]],\
    \ ind[u]);\n      u = parent[top[u]];\n    }\n    if (depth[u] > depth[v]) swap(u,\
    \ v);\n    res.emplace_back(ind[u], ind[v]);\n    return res;\n  }\n\n public:\n\
    \  hld_wavelet(vector<vector<pair<int, int>>> &g, const vector<T> &node_values,\
    \ int root = 0) {\n    n = g.size();\n    seen.resize(n, 0);\n    subtree.resize(n,\
    \ 0);\n    ind.resize(n, 0);\n    depth.resize(n, 0);\n    top.resize(n, 0);\n\
    \    parent.resize(n, -1);\n    seen[root] = 1;\n    rec_sub(g, root, 0);\n  \
    \  for (int i = 0; i < n; i++) seen[i] = 0;\n    seen[root] = 1;\n    top[root]\
    \ = root;\n    rec_hld(g, root);\n    for (int i = 1; i < n; i++) {\n      int\
    \ prev = hl[i - 1];\n      int cur = hl[i];\n      if (top[prev] != top[cur])\
    \ continue;\n    }\n\n    vector<T> reordered_values(n);\n    for (int i = 0;\
    \ i < n; ++i) {\n      reordered_values[i] = node_values[hl[i]];\n    }\n    wm\
    \ = WaveletMatrix<T>(reordered_values);\n  }\n\n  T kth_path(int u, int v, int\
    \ k) {\n    vector<pair<int, int>> segments;\n    for (const auto &[s, t] : decompose(u,\
    \ v)) {\n      if (s > t) {\n        segments.emplace_back(t, s + 1);\n      }\
    \ else {\n        segments.emplace_back(s, t + 1);\n      }\n    }\n    int cnt\
    \ = 0;\n    int p = 0;\n    for (int i = 0; i < wm.bitsize; i++) {\n      int\
    \ c = 0;\n      for (auto &[l, r] : segments) {\n        int l0 = l - wm.b[i].rank(l);\n\
    \        int r0 = r - wm.b[i].rank(r);\n        c += r0 - l0;\n      }\n\n   \
    \   if (cnt + c > k) {\n        for (auto &&[l, r] : segments) {\n          int\
    \ l0 = l - wm.b[i].rank(l);\n          int r0 = r - wm.b[i].rank(r);\n       \
    \   l = l0;\n          r = r0;\n        }\n      } else {\n        cnt += c;\n\
    \        p |= (1 << (wm.bitsize - i - 1));\n\n        for (auto &&[l, r] : segments)\
    \ {\n          int l0 = l - wm.b[i].rank(l);\n          int r0 = r - wm.b[i].rank(r);\n\
    \          l += wm.zero[i] - l0;\n          r += wm.zero[i] - r0;\n        }\n\
    \      }\n    }\n    return wm.cmp[p];\n  }\n};\n#line 4 \"verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\n    int n, m;\n    in(n,\
    \ m);\n    vector<int> nodew(n);\n    in(nodew);\n\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    rep(i, n - 1) {\n        int s, t;\n        in(s, t);\n  \
    \      s--;\n        t--;\n        g[s].emplace_back(t, 1);\n        g[t].emplace_back(s,\
    \ 1);\n    }\n\n    vector<vector<int>> q(m, vector<int>(4));\n    rep(i, m) {\n\
    \        int op, u, v, w, k;\n        in(op);\n        q[i][0] = op;\n\n     \
    \   if (op == 1) {\n            in(u, w);\n            u--;\n            q[i][1]\
    \ = u;\n            q[i][2] = w;\n            nodew.emplace_back(w);\n       \
    \     g.push_back(vector<pair<int, int>>());\n            int newid = g.size()\
    \ - 1;\n            g[newid].emplace_back(u, 1);\n            g[u].emplace_back(newid,\
    \ 1);\n        } else if (op == 2) {\n            in(u, v, k);\n            u--;\n\
    \            v--;\n            k--;\n            q[i][1] = u;\n            q[i][2]\
    \ = v;\n            q[i][3] = k;\n        }\n    }\n\n    hld_wavelet<int> h(g,\
    \ nodew);\n\n    rep(i, m) {\n        int op = q[i][0];\n        if (op == 2)\
    \ {\n            int u = q[i][1];\n            int v = q[i][2];\n            int\
    \ k = q[i][3];\n            out(h.kth_path(u, v, k));\n        }\n    }\n}\n"
  code: "#include \"../../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0489\"\
    \n#include \"../../../../../data-structure/wavelet-matrix/query/WaveletMatrixonHeavyLightDecomposition.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\n    int n, m;\n    in(n,\
    \ m);\n    vector<int> nodew(n);\n    in(nodew);\n\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    rep(i, n - 1) {\n        int s, t;\n        in(s, t);\n  \
    \      s--;\n        t--;\n        g[s].emplace_back(t, 1);\n        g[t].emplace_back(s,\
    \ 1);\n    }\n\n    vector<vector<int>> q(m, vector<int>(4));\n    rep(i, m) {\n\
    \        int op, u, v, w, k;\n        in(op);\n        q[i][0] = op;\n\n     \
    \   if (op == 1) {\n            in(u, w);\n            u--;\n            q[i][1]\
    \ = u;\n            q[i][2] = w;\n            nodew.emplace_back(w);\n       \
    \     g.push_back(vector<pair<int, int>>());\n            int newid = g.size()\
    \ - 1;\n            g[newid].emplace_back(u, 1);\n            g[u].emplace_back(newid,\
    \ 1);\n        } else if (op == 2) {\n            in(u, v, k);\n            u--;\n\
    \            v--;\n            k--;\n            q[i][1] = u;\n            q[i][2]\
    \ = v;\n            q[i][3] = k;\n        }\n    }\n\n    hld_wavelet<int> h(g,\
    \ nodew);\n\n    rep(i, m) {\n        int op = q[i][0];\n        if (op == 2)\
    \ {\n            int u = q[i][1];\n            int v = q[i][2];\n            int\
    \ k = q[i][3];\n            out(h.kth_path(u, v, k));\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/wavelet-matrix/query/WaveletMatrixonHeavyLightDecomposition.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 04:01:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp
- /verify/verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp.html
title: verify/AizuOnlineJudge/data-structure/wavelet-matrix/query/FarmlandDevelopment.test.cpp
---
