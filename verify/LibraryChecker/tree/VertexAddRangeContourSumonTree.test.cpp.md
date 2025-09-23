---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/fenwicktree.hpp
    title: atcoder/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/CentroidDecompositionContourSum.hpp
    title: Centroid Decomposition (Contour Sum)
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#line 6 \"atcoder/fenwicktree.hpp\"\
    \n\n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#line 6 \"atcoder/internal_type_traits.hpp\"\
    \n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace internal {\n\n#ifndef\
    \ _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 4 \"verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp\"\
    \nusing namespace atcoder;\n#line 1 \"graph/tree/CentroidDecompositionContourSum.hpp\"\
    \nstatic const unsigned long long seed = chrono::steady_clock::now().time_since_epoch().count();\n\
    static mt19937_64 eng(seed);\n\ntemplate <class S>\nclass CentroidDecomposition\
    \ {\n   private:\n    vector<vector<int>> g;\n    vector<bool> dead;\n    vector<S>\
    \ leaf;\n    vector<int> ord;\n    vector<int> dinfo;\n    vector<int> parent;\n\
    \    vector<vector<fenwick_tree<S>>> subtrees;\n    vector<vector<int>> ds_size;\n\
    \    vector<int> subtree_size;\n    vector<vector<pair<int, int>>> info;\n\n \
    \   int n;\n    int node_idx;\n\n    void reorder(int s) {\n        ord.assign(n,\
    \ -1);\n        queue<int> q;\n        q.push(s);\n        int idx = 0;\n    \
    \    while (!q.empty()) {\n            int cur = q.front();\n            q.pop();\n\
    \            ord[cur] = idx++;\n            for (int nex : g[cur])\n         \
    \       if (ord[nex] == -1) q.push(nex);\n        }\n    }\n\n    S ds_prod(fenwick_tree<S>\
    \ &fen, int siz, int l, int r) {\n        l = max(0, l);\n        r = min(r, siz);\n\
    \        if (l < r) {\n            return fen.sum(l, r);\n        }\n        return\
    \ 0;\n    }\n\n   public:\n    CentroidDecomposition(int siz) {\n        n = siz;\n\
    \        g.resize(n);\n\n        node_idx = n;\n    }\n    CentroidDecomposition()\
    \ {}\n\n    void add_edge(int u, int v) {\n        g[u].emplace_back(v);\n   \
    \     g[v].emplace_back(u);\n    }\n\n    void build(const vector<S> &a) {\n \
    \       parent.assign(n << 1, -1);\n        info.resize(n, vector<pair<int, int>>(30));\n\
    \        subtrees.resize(n << 1, vector<fenwick_tree<S>>(2));\n        ds_size.resize(n\
    \ << 1, vector<int>(2));\n        dead.resize(n, false);\n        subtree_size.resize(n\
    \ << 1);\n        leaf.resize(n);\n        dinfo.resize(n);\n        reorder(uniform_int_distribution<int>(0,\
    \ n - 1)(eng));\n        vector<vector<int>> tmp(n);\n        vector<int> par_cr(n\
    \ << 1, -1);\n        vector<int> head(n << 1);\n        vector<int> tail(n <<\
    \ 1);\n        vector<int> link(n << 1, -1);\n        vector<S> d(n * 3);\n  \
    \      for (int i = 0; i < n; i++) {\n            head[i] = tail[i] = i;\n   \
    \     }\n\n        for (int u = 0; u < n; u++) {\n            for (const int v\
    \ : g[u]) {\n                tmp[ord[u]].emplace_back(ord[v]);\n            }\n\
    \            leaf[ord[u]] = a[u];\n        }\n        g = tmp;\n\n        function<int(int,\
    \ int)> rec = [&](int start, int sz) -> int {\n            int c = -1;\n     \
    \       const auto get_centroid = [&](auto &&self, int u, int p) -> void {\n \
    \               subtree_size[u] = 1;\n                for (const int v : g[u])\
    \ {\n                    if (v == p || dead[v]) continue;\n\n                \
    \    self(self, v, u);\n                    if (v == c) {\n                  \
    \      subtree_size[u] = sz - subtree_size[c];\n                        break;\n\
    \                    }\n\n                    subtree_size[u] += subtree_size[v];\n\
    \                }\n\n                if (c == -1 && subtree_size[u] * 2 > sz)\
    \ c = u;\n            };\n\n            get_centroid(get_centroid, start, -1);\n\
    \            dead[c] = true;\n            for (const int u : g[c]) {\n       \
    \         if (dead[u]) continue;\n                const int comp_sz = subtree_size[u];\n\
    \                par_cr[u] = rec(u, comp_sz);\n                subtree_size[u]\
    \ = comp_sz;\n            }\n\n            const auto compare = [&](int i, int\
    \ j) {\n                return subtree_size[i] > subtree_size[j];\n          \
    \  };\n\n            priority_queue<int, vector<int>, decltype(compare)> pq{compare};\n\
    \n            for (const int v : g[c]) {\n                if (dead[v]) continue;\n\
    \                link[v] = -1;\n                pq.push(v);\n            }\n\n\
    \            const auto build_data_structure = [&](const int root_head, const\
    \ int child_index) {\n                queue<pair<int, int>> q;\n             \
    \   for (int root = root_head; root >= 0; root = link[root]) {\n             \
    \       q.emplace(root, -1);\n                }\n\n                S x = 0;\n\
    \                int idx = 0;\n                int nxt = -1;\n               \
    \ while (!q.empty()) {\n                    int cur = q.front().first;\n     \
    \               int prev = q.front().second;\n                    q.pop();\n \
    \                   if (cur == nxt) {\n                        d[idx++] = exchange(x,\
    \ 0);\n                        nxt = -1;\n                    }\n\n          \
    \          info[cur][dinfo[cur]++] = {child_index, idx};\n                   \
    \ x += leaf[cur];\n\n                    for (const int v : g[cur]) {\n      \
    \                  if (v == prev or dead[v]) continue;\n                     \
    \   q.emplace(v, cur);\n                        if (nxt == -1) nxt = v;\n    \
    \                }\n                }\n                d[idx++] = x;\n       \
    \         return idx;\n            };\n\n            while (pq.size() >= 2) {\n\
    \                const int p1 = pq.top();\n                pq.pop();\n       \
    \         const int p2 = pq.top();\n                pq.pop();\n\n            \
    \    if (pq.empty()) {\n                    parent[par_cr[p1]] = parent[par_cr[p2]]\
    \ = c;\n                    ds_size[c][0] = build_data_structure(head[p1], 0);\n\
    \                    subtrees[c][0] = fenwick_tree<S>(ds_size[c][0]);\n      \
    \              for (int i = 0; i < ds_size[c][0]; i++) {\n                   \
    \     subtrees[c][0].add(i, d[i]);\n                    }\n\n                \
    \    ds_size[c][1] = build_data_structure(head[p2], 1);\n                    subtrees[c][1]\
    \ = fenwick_tree<S>(ds_size[c][1]);\n                    for (int i = 0; i < ds_size[c][1];\
    \ i++) {\n                        subtrees[c][1].add(i, d[i]);\n             \
    \       }\n                    break;\n                }\n\n                subtree_size[node_idx]\
    \ = subtree_size[p1] + subtree_size[p2];\n                par_cr[node_idx] = node_idx;\n\
    \n                parent[par_cr[p1]] = parent[par_cr[p2]] = node_idx;\n      \
    \          ds_size[node_idx][0] = build_data_structure(head[p1], 0);\n       \
    \         subtrees[node_idx][0] = fenwick_tree<S>(ds_size[node_idx][0]);\n   \
    \             for (int i = 0; i < ds_size[node_idx][0]; i++) {\n             \
    \       subtrees[node_idx][0].add(i, d[i]);\n                }\n             \
    \   ds_size[node_idx][1] = build_data_structure(head[p2], 1);\n              \
    \  subtrees[node_idx][1] = fenwick_tree<S>(ds_size[node_idx][1]);\n\n        \
    \        for (int i = 0; i < ds_size[node_idx][1]; i++) {\n                  \
    \  subtrees[node_idx][1].add(i, d[i]);\n                }\n\n                head[node_idx]\
    \ = head[p1];\n                tail[node_idx] = tail[p2];\n                link[tail[p1]]\
    \ = head[p2];\n                pq.push(node_idx);\n                node_idx++;\n\
    \            }\n\n            if (!pq.empty()) {\n                int u = pq.top();\n\
    \                pq.pop();\n                parent[par_cr[u]] = c;\n         \
    \       ds_size[c][0] = build_data_structure(head[u], 0);\n                subtrees[c][0]\
    \ = fenwick_tree<S>(ds_size[c][0]);\n                for (int i = 0; i < ds_size[c][0];\
    \ i++) {\n                    subtrees[c][0].add(i, d[i]);\n                }\n\
    \            }\n\n            dead[c] = false;\n            return c;\n      \
    \  };\n\n        rec(0, n);\n        parent.resize(node_idx);\n        parent.shrink_to_fit();\n\
    \        subtrees.resize(node_idx);\n        subtrees.shrink_to_fit();\n    }\n\
    \n    void add(int p, S x) {\n        p = ord[p];\n        leaf[p] += x;\n   \
    \     int cur = parent[p];\n        for (int i = 0; i < dinfo[p]; i++) {\n   \
    \         const auto &[b, dist] = info[p][i];\n            subtrees[exchange(cur,\
    \ parent[cur])][b].add(dist, x);\n        }\n    }\n\n    S get(int p) {\n   \
    \     return leaf[ord[p]];\n    }\n\n    S prod(int p, int lower, int upper) {\n\
    \        p = ord[p];\n        S ret = 0;\n        if (lower <= 0 and 0 < upper)\
    \ {\n            assert(0 <= p and p < n);\n            ret = leaf[p];\n     \
    \   }\n        ret += ds_prod(subtrees[p][0], ds_size[p][0], lower - 1, upper\
    \ - 1);\n        ret += ds_prod(subtrees[p][1], ds_size[p][1], lower - 1, upper\
    \ - 1);\n        int v = parent[p];\n        for (int i = 0; i < dinfo[p]; i++)\
    \ {\n            const auto &[b, dist] = info[p][i];\n            int ql = lower\
    \ - dist - 1;\n            int qr = upper - dist - 1;\n            if (v < n and\
    \ ql <= 0 and 0 < qr) ret += leaf[v];\n            ret += ds_prod(subtrees[exchange(v,\
    \ parent[v])][b ^ 1], ds_size[v][b ^ 1], ql - 1, qr - 1);\n        }\n       \
    \ return ret;\n    }\n};\n#line 6 \"verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp\"\
    \n\nusing S = lint;\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int n, q;\n    in(n, q);\n    vector<S> a(n);\n    in(a);\n    CentroidDecomposition<S>\
    \ t(n);\n\n    rep(i, n - 1) {\n        int u, v;\n        in(u, v);\n       \
    \ t.add_edge(u, v);\n    }\n\n    t.build(a);\n\n    rep(i, q) {\n        int\
    \ com;\n        in(com);\n        if (com == 0) {\n            int p;\n      \
    \      S x;\n            in(p, x);\n            t.add(p, x);\n        } else {\n\
    \            int p, l, r;\n            in(p, l, r);\n            out(t.prod(p,\
    \ l, r));\n        }\n    }\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n#include \"../../../atcoder/fenwicktree.hpp\"\nusing namespace atcoder;\n#include\
    \ \"../../../graph/tree/CentroidDecompositionContourSum.hpp\"\n\nusing S = lint;\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ n, q;\n    in(n, q);\n    vector<S> a(n);\n    in(a);\n    CentroidDecomposition<S>\
    \ t(n);\n\n    rep(i, n - 1) {\n        int u, v;\n        in(u, v);\n       \
    \ t.add_edge(u, v);\n    }\n\n    t.build(a);\n\n    rep(i, q) {\n        int\
    \ com;\n        in(com);\n        if (com == 0) {\n            int p;\n      \
    \      S x;\n            in(p, x);\n            t.add(p, x);\n        } else {\n\
    \            int p, l, r;\n            in(p, l, r);\n            out(t.prod(p,\
    \ l, r));\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - atcoder/fenwicktree.hpp
  - atcoder/internal_type_traits.hpp
  - graph/tree/CentroidDecompositionContourSum.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp
  requiredBy: []
  timestamp: '2025-05-03 18:57:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp
- /verify/verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp.html
title: verify/LibraryChecker/tree/VertexAddRangeContourSumonTree.test.cpp
---
