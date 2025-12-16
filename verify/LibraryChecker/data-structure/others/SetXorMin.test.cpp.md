---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/BinaryTrie.hpp
    title: Binary Trie
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 2 \"\
    data-structure/others/BinaryTrie.hpp\"\ntemplate <typename U = unsigned, int B\
    \ = 32>\nclass lazy_binary_trie {\n    struct node {\n        int cnt;\n     \
    \   U lazy;\n        node *ch[2];\n        node() : cnt(0), lazy(0), ch{nullptr,\
    \ nullptr} {}\n    };\n    void push(node *t, int b) {\n        if ((t->lazy >>\
    \ (U)b) & (U)1) swap(t->ch[0], t->ch[1]);\n        if (t->ch[0]) t->ch[0]->lazy\
    \ ^= t->lazy;\n        if (t->ch[1]) t->ch[1]->lazy ^= t->lazy;\n        t->lazy\
    \ = 0;\n    }\n    node *add(node *t, U val, int b = B - 1) {\n        if (!t)\
    \ t = new node;\n        t->cnt += 1;\n        if (b < 0) return t;\n        push(t,\
    \ b);\n        bool f = (val >> (U)b) & (U)1;\n        t->ch[f] = add(t->ch[f],\
    \ val, b - 1);\n        return t;\n    }\n    node *sub(node *t, U val, int b\
    \ = B - 1) {\n        assert(t);\n        t->cnt -= 1;\n        if (t->cnt ==\
    \ 0) return nullptr;\n        if (b < 0) return t;\n        push(t, b);\n    \
    \    bool f = (val >> (U)b) & (U)1;\n        t->ch[f] = sub(t->ch[f], val, b -\
    \ 1);\n        return t;\n    }\n    U get_min(node *t, U val, int b = B - 1)\
    \ {\n        assert(t);\n        if (b < 0) return 0;\n        push(t, b);\n \
    \       bool f = (val >> (U)b) & (U)1;\n        f ^= !t->ch[f];\n        return\
    \ get_min(t->ch[f], val, b - 1) | ((U)f << (U)b);\n    }\n    U get(node *t, int\
    \ k, int b = B - 1) {\n        if (b < 0) return 0;\n        push(t, b);\n   \
    \     int m = t->ch[0] ? t->ch[0]->cnt : 0;\n        return k < m ? get(t->ch[0],\
    \ k, b - 1) : get(t->ch[1], k - m, b - 1) | ((U)1 << (U)b);\n    }\n    int count_lower(node\
    \ *t, U val, int b = B - 1) {\n        if (!t || b < 0) return 0;\n        push(t,\
    \ b);\n        bool f = (val >> (U)b) & (U)1;\n        return (f && t->ch[0] ?\
    \ t->ch[0]->cnt : 0) + count_lower(t->ch[f], val, b - 1);\n    }\n    node *root;\n\
    \n   public:\n    lazy_binary_trie() : root(nullptr) {}\n    int size() const\
    \ {\n        return root ? root->cnt : 0;\n    }\n    bool empty() const {\n \
    \       return !root;\n    }\n\n    // \u5024val\u3092\u96C6\u5408\u306B1\u3064\
    \u8FFD\u52A0\u3059\u308B\n    void insert(U val) {\n        root = add(root, val);\n\
    \    }\n\n    // \u5024val\u3092\u96C6\u5408\u304B\u30891\u3064\u524A\u9664\u3059\
    \u308B\n    void erase(U val) {\n        root = sub(root, val);\n    }\n\n   \
    \ // \u3059\u3079\u3066\u306E\u8981\u7D20\u3092val\u3068XOR\u3092\u53D6\u3063\u305F\
    \u5024\u306B\u5909\u66F4\u3059\u308B\n    void xor_all(U val) {\n        if (root)\
    \ root->lazy ^= val;\n    }\n\n    // \u5024bias\u3068xor\u3092\u53D6\u3063\u305F\
    \u3068\u304D\u306B\u6700\u5927\u306B\u306A\u308B\u5024\u3092\u8FD4\u3059\n   \
    \ U max_element(U bias = 0) {\n        return get_min(root, ~bias);\n    }\n\n\
    \    // \u5024bias\u3068xor\u3092\u53D6\u3063\u305F\u3068\u304D\u306B\u6700\u5C0F\
    \u306B\u306A\u308B\u5024\u3092\u8FD4\u3059\n    U min_element(U bias = 0) {\n\
    \        return get_min(root, bias);\n    }\n\n    // val\u4EE5\u4E0A\u306E\u6700\
    \u5C0F\u306E\u8981\u7D20\u304C\u5C0F\u3055\u3044\u65B9\u304B\u3089\u4F55\u756A\
    \u76EE\u304B\u3092\u8FD4\u3059\n    int lower_bound(U val) {\n        return count_lower(root,\
    \ val);\n    }\n\n    // val\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20\u304C\u5C0F\u3055\u3044\u65B9\u304B\u3089\u4F55\u756A\u76EE\u304B\u3092\
    \u8FD4\u3059\n    int upper_bound(U val) {\n        return count_lower(root, val\
    \ + 1);\n    }\n\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\
    \u3059\n    U operator[](int k) {\n        assert(0 <= k && k < size());\n   \
    \     return get(root, k);\n    }\n\n    // k\u756A\u76EE\u306B\u5C0F\u3055\u3044\
    \u5024\u3092\u8FD4\u3059\n    U kth_smallest(int k) {\n        assert(0 <= k &&\
    \ k < size());\n        return get(root, k);\n    }\n\n    // \u5024val\u304C\u96C6\
    \u5408\u306B\u3044\u304F\u3064\u542B\u307E\u308C\u308B\u304B\u3092\u8FD4\u3059\
    \n    int count(U val) {\n        if (!root) return 0;\n        node *t = root;\n\
    \        for (int i = B - 1; i >= 0; i--) {\n            push(t, i);\n       \
    \     t = t->ch[(val >> (U)i) & (U)1];\n            if (!t) return 0;\n      \
    \  }\n        return t->cnt;\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    int q;\n    in(q);\n\
    \    lazy_binary_trie<int> trie;\n    rep(i, q) {\n        int com, x;\n     \
    \   in(com, x);\n        if (com == 0 and trie.count(x) == 0) {\n            trie.insert(x);\n\
    \        } else if (com == 1 and trie.count(x) > 0) {\n            trie.erase(x);\n\
    \        } else if (com == 2) {\n            out(trie.min_element(x) ^ x);\n \
    \       }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n#include \"../../../../data-structure/others/BinaryTrie.hpp\"\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    int q;\n    in(q);\n    lazy_binary_trie<int>\
    \ trie;\n    rep(i, q) {\n        int com, x;\n        in(com, x);\n        if\
    \ (com == 0 and trie.count(x) == 0) {\n            trie.insert(x);\n        }\
    \ else if (com == 1 and trie.count(x) > 0) {\n            trie.erase(x);\n   \
    \     } else if (com == 2) {\n            out(trie.min_element(x) ^ x);\n    \
    \    }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/others/BinaryTrie.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
  requiredBy: []
  timestamp: '2025-09-23 21:10:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
- /verify/verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp.html
title: verify/LibraryChecker/data-structure/others/SetXorMin.test.cpp
---
