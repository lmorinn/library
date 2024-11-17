---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix/WaveletMatrixString.hpp
    title: Wavelet Matrix (String)
  - icon: ':heavy_check_mark:'
    path: string/FMindex.hpp
    title: FM-index
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.hpp
    title: Suffix Array
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D\"\
    \n#line 1 \"data-structure/wavelet-matrix/WaveletMatrixString.hpp\"\ntemplate\
    \ <class T>\nclass BitVector {\n   private:\n    unsigned n, cur, p;\n    vector<unsigned>\
    \ acc, bit;\n\n   public:\n    BitVector() {\n    }\n\n    BitVector(vector<bool>\
    \ &b) {\n        cur = 0;\n        n = b.size();\n        acc.resize((n >> 5)\
    \ + 2, 0);\n        bit.resize((n >> 5) + 2, 0);\n        for (int i = 0; i <\
    \ n; i++) {\n            if (!(i & 31)) {\n                cur++;\n          \
    \      acc[cur] = acc[cur - 1];\n            }\n            if (b[i]) {\n    \
    \            acc[cur] += int(b[i]);\n                bit[cur - 1] |= (1U << (32\
    \ - (i & 31) - 1));\n            }\n        }\n    }\n\n    inline unsigned rank(unsigned\
    \ k) {\n        if (!(k & 31)) return acc[k >> 5];\n        return acc[k >> 5]\
    \ + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));\n    }\n\n    inline bool\
    \ access(unsigned k) {\n        return (rank(k + 1) - rank(k)) == 1;\n    }\n\
    };\n\nclass WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned bitsize;\n\
    \    vector<BitVector<unsigned char>> b;\n    vector<unsigned> zero;\n    vector<int>\
    \ stInd;\n    unsigned char MI, MA;\n\n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304C\
    k\u672A\u6E80\u306E\u500B\u6570\u3092\u8FD4\u3059\n    unsigned rank_less(unsigned\
    \ l, unsigned r, unsigned char k) {\n        unsigned less = 0;\n        for (unsigned\
    \ i = 0; i < bitsize and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n\
    \            const unsigned rank1_r = b[i].rank(r);\n            const unsigned\
    \ rank0_l = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n\
    \            if (k & (1U << (bitsize - i - 1))) {\n                less += (rank0_r\
    \ - rank0_l);\n                l = zero[i] + rank1_l;\n                r = zero[i]\
    \ + rank1_r;\n            } else {\n                l = rank0_l;\n           \
    \     r = rank0_r;\n            }\n        }\n        return less;\n    }\n\n\
    \   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix()\
    \ {}\n    WaveletMatrix(string v) {\n        MI = numeric_limits<unsigned char>::min();\n\
    \        MA = numeric_limits<unsigned char>::max();\n        n = v.size();\n\n\
    \        vector<unsigned> tmp(n);\n        stInd.resize(256, -1);\n        bitsize\
    \ = 8;\n        b.resize(bitsize);\n        zero.resize(bitsize, 0);\n       \
    \ vector<bool> bit(n, 0);\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            for (unsigned j = 0; j < n; j++) {\n                bit[j] = v[j]\
    \ & (1U << (bitsize - i - 1));\n                zero[i] += unsigned(!bit[j]);\n\
    \                tmp[j] = v[j];\n            }\n            b[i] = BitVector<unsigned\
    \ char>(bit);\n            int cur = 0;\n            for (unsigned j = 0; j <\
    \ n; j++) {\n                if (!bit[j]) {\n                    v[cur] = tmp[j];\n\
    \                    cur++;\n                }\n            }\n            for\
    \ (unsigned j = 0; j < n; j++) {\n                if (bit[j]) {\n            \
    \        v[cur] = tmp[j];\n                    cur++;\n                }\n   \
    \         }\n        }\n\n        for (unsigned i = 0; i < n; i++) {\n       \
    \     if (stInd[v[i]] == -1) {\n                stInd[v[i]] = i;\n           \
    \ }\n        }\n    }\n\n    // get v[k]\n    unsigned char access(unsigned k)\
    \ {\n        unsigned char res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return res;\n    }\n\n    // v[0,k) \u4E2D\u3067\u306Ec\u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned k, unsigned\
    \ char c) {\n        unsigned cur = k;\n        if (stInd[c] == -1) {\n      \
    \      return 0;\n        }\n        for (unsigned i = 0; i < bitsize; i++) {\n\
    \            if (c & (1U << (bitsize - i - 1))) {\n                cur = zero[i]\
    \ + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cur - stInd[c];\n    }\n\n    // v[l,r)\
    \ \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\
    \u8FD4\u3059\n    unsigned char kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned char res = 0;\n        for (unsigned i = 0; i < bitsize;\
    \ i++) {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n         \
    \   unsigned num0 = r - l - num1;\n            if (num0 < k) {\n             \
    \   res |= (1ULL << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n\
    \                r = zero[i] + b[i].rank(r);\n                k -= num0;\n   \
    \         } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return res;\n    }\n\n    // v[l,r) \u306E\u4E2D\
    \u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n\
    \    unsigned char kth_largest(unsigned l, unsigned r, unsigned k) {\n       \
    \ return kth_smallest(l, r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u500B\u6570\u3092\u8FD4\u3059\n\
    \    unsigned range_freq(unsigned l, unsigned r, unsigned char mink, unsigned\
    \ char maxk) {\n        if (mink == 0) {\n            return rank_less(l, r, maxk);\n\
    \        }\n        return rank_less(l, r, maxk) - rank_less(l, r, mink);\n  \
    \  }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\
    \u5927\u306E\u5024\u3092\u8FD4\u3059\n    unsigned char prev_value(unsigned l,\
    \ unsigned r, unsigned char val) {\n        int num = range_freq(l, r, MI, val);\n\
    \        if (num == 0) {\n            return MA;\n        } else {\n         \
    \   return kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\
    \u3067val\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\
    \n    unsigned char next_value(unsigned l, unsigned r, unsigned char val) {\n\
    \        int num = range_freq(l, r, MI, val + 1);\n        if (num == r - l) {\n\
    \            return MI;\n        } else {\n            return kth_smallest(l,\
    \ r, num + 1);\n        }\n    }\n};\n#line 2 \"string/SuffixArray.hpp\"\n\n#define\
    \ tget(i) (((t)[(i) >> 3] >> (7 - ((i) & 7))) & 1)\n\n#define tset(i, b)     \
    \                               \\\n    do {                                 \
    \             \\\n        if (b)                                        \\\n \
    \           (t)[(i) >> 3] |= (1 << (7 - ((i) & 7)));  \\\n        else       \
    \                                   \\\n            (t)[(i) >> 3] &= ~(1 << (7\
    \ - ((i) & 7))); \\\n    } while (0)\n\n#define chr(i) (cs == sizeof(int) ? ((int\
    \ *)s)[i] : ((unsigned char *)s)[i])\n#define isLMS(i) (i > 0 and tget(i) and\
    \ !tget(i - 1))\n\nvoid getBuckets(unsigned char *s, int *bkt, int n, int K, int\
    \ cs, bool end) {\n    int sum = 0;\n    for (int i = 0; i <= K; i++) {\n    \
    \    bkt[i] = 0;\n    }\n    for (int i = 0; i < n; i++) {\n        bkt[chr(i)]++;\n\
    \    }\n    for (int i = 0; i <= K; i++) {\n        sum += bkt[i];\n        bkt[i]\
    \ = end ? sum : sum - bkt[i];\n    }\n}\n\nvoid induceSAl(unsigned char *t, int\
    \ *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {\n    getBuckets(s,\
    \ bkt, n, K, cs, end);\n    for (int i = 0; i < n; i++) {\n        int j = SA[i]\
    \ - 1;\n        if (j >= 0 and !tget(j)) {\n            SA[bkt[chr(j)]++] = j;\n\
    \        }\n    }\n}\n\nvoid induceSAs(unsigned char *t, int *SA, unsigned char\
    \ *s, int *bkt, int n, int K, int cs, bool end) {\n    getBuckets(s, bkt, n, K,\
    \ cs, end);\n    for (int i = n - 1; i >= 0; i--) {\n        int j = SA[i] - 1;\n\
    \        if (j >= 0 and tget(j)) {\n            SA[--bkt[chr(j)]] = j;\n     \
    \   }\n    }\n}\n\nvoid SA_IS(unsigned char *s, int *SA, int n, int K, int cs)\
    \ {\n    unsigned char *t = (unsigned char *)malloc(n / 8 + 1);\n    tset(n -\
    \ 2, 0);\n    tset(n - 1, 1);\n    for (int i = n - 3; i >= 0; i--) {\n      \
    \  tset(i, (chr(i) < chr(i + 1) or (chr(i) == chr(i + 1) and tget(i + 1) == 1))\
    \ ? 1 : 0);\n    }\n\n    int *bkt = (int *)malloc(sizeof(int) * (K + 1));\n \
    \   getBuckets(s, bkt, n, K, cs, true);\n    for (int i = 0; i < n; i++) {\n \
    \       SA[i] = -1;\n    }\n    for (int i = 1; i < n; i++) {\n        if (isLMS(i))\
    \ {\n            SA[--bkt[chr(i)]] = i;\n        }\n    }\n    induceSAl(t, SA,\
    \ s, bkt, n, K, cs, false);\n    induceSAs(t, SA, s, bkt, n, K, cs, true);\n \
    \   free(bkt);\n\n    int n1 = 0;\n    for (int i = 0; i < n; i++) {\n       \
    \ if (isLMS(SA[i])) {\n            SA[n1++] = SA[i];\n        }\n    }\n\n   \
    \ for (int i = n1; i < n; i++) {\n        SA[i] = -1;\n    }\n    int name = 0;\n\
    \    int prev = -1;\n    for (int i = 0; i < n1; i++) {\n        int pos = SA[i];\n\
    \        bool diff = false;\n        for (int d = 0; d < n; d++) {\n         \
    \   if (prev == -1 or chr(pos + d) != chr(prev + d) or tget(pos + d) != tget(prev\
    \ + d)) {\n                diff = true;\n                break;\n            }\
    \ else if (d > 0 and (isLMS(pos + d) or isLMS(prev + d))) {\n                break;\n\
    \            }\n        }\n        if (diff) {\n            name++;\n        \
    \    prev = pos;\n        }\n        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1)\
    \ / 2;\n        SA[n1 + pos] = name - 1;\n    }\n    for (int i = n - 1, j = n\
    \ - 1; i >= n1; i--) {\n        if (SA[i] >= 0) {\n            SA[j--] = SA[i];\n\
    \        }\n    }\n\n    int *SA1 = SA;\n    int *s1 = SA + n - n1;\n    if (name\
    \ < n1) {\n        SA_IS((unsigned char *)s1, SA1, n1, name - 1, sizeof(int));\n\
    \    } else {\n        for (int i = 0; i < n1; i++) {\n            SA1[s1[i]]\
    \ = i;\n        }\n    }\n    bkt = (int *)malloc(sizeof(int) * (K + 1));\n  \
    \  getBuckets(s, bkt, n, K, cs, true);\n    for (int i = 1, j = 0; i < n; i++)\
    \ {\n        if (isLMS(i)) {\n            s1[j++] = i;\n        }\n    }\n   \
    \ for (int i = 0; i < n1; i++) {\n        SA1[i] = s1[SA1[i]];\n    }\n    for\
    \ (int i = n1; i < n; i++) {\n        SA[i] = -1;\n    }\n    for (int i = n1\
    \ - 1; i >= 0; i--) {\n        int j = SA[i];\n        SA[i] = -1;\n        SA[--bkt[chr(j)]]\
    \ = j;\n    }\n    induceSAl(t, SA, s, bkt, n, K, cs, false);\n    induceSAs(t,\
    \ SA, s, bkt, n, K, cs, true);\n    free(bkt);\n    free(t);\n}\n\nvector<int>\
    \ suffixArray(string &str) {\n    int n = str.size() + 1;\n    int *sa = (int\
    \ *)malloc(sizeof(int) * n);\n    unsigned char *s = (unsigned char *)malloc(sizeof(unsigned\
    \ char) * (n + 2));\n    int k = 256;\n    int cs = sizeof(unsigned char);\n \
    \   for (int i = 0; i < str.size(); i++) {\n        s[i] = str[i];\n    }\n  \
    \  s[int(str.size())] = 0;\n    SA_IS((unsigned char *)(s), sa, n, k, cs);\n \
    \   vector<int> res(n - 1);\n    for (int i = 0; i < n - 1; i++) {\n        res[i]\
    \ = sa[i + 1];\n    }\n    free(sa);\n    free(s);\n    return res;\n}\n#line\
    \ 4 \"string/FMindex.hpp\"\n\nclass FMindex {\n   private:\n    int n;\n    WaveletMatrix\
    \ w;\n    vector<int> less;\n\n   public:\n    FMindex(string &s) {\n        n\
    \ = s.size();\n        less.resize(256);\n        vector<int> cnt(256);\n    \
    \    string bwt(n + 1, '$');\n        vector<int> sa = suffixArray(s);\n     \
    \   reverse(sa.begin(), sa.end());\n        sa.emplace_back(s.size());\n     \
    \   reverse(sa.begin(), sa.end());\n\n        for (int i = 0; i < s.size() + 1;\
    \ i++) {\n            if (sa[i] > 0) {\n                bwt[i] = s[sa[i] - 1];\n\
    \            }\n            cnt[s[i]]++;\n        }\n\n        for (int i = 1;\
    \ i < 256; i++) {\n            less[i] = less[i - 1] + cnt[i - 1];\n        }\n\
    \        w = WaveletMatrix(bwt);\n    }\n\n    int substrCount(string &t) {\n\
    \        int m = t.size();\n        int l = 0;\n        int r = n + 1;\n     \
    \   for (int i = 0; i < m; i++) {\n            unsigned char c = t[m - 1 - i];\n\
    \            l = less[c] + w.rank(l, c);\n            r = less[c] + w.rank(r,\
    \ c);\n            if (l >= r) {\n                l = 0;\n                r =\
    \ 0;\n                break;\n            }\n        }\n        return r - l;\n\
    \    }\n};\n#line 4 \"verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp\"\n\n\
    int main() {\n    cin.tie(0)->sync_with_stdio(0);\n    string t;\n    in(t);\n\
    \    FMindex f(t);\n    int q;\n    in(q);\n    rep(i, q) {\n        string p;\n\
    \        in(p);\n        out(f.substrCount(p) != 0);\n    }\n}\n"
  code: "#include \"../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D\"\
    \n#include \"../../../string/FMindex.hpp\"\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    string t;\n    in(t);\n    FMindex f(t);\n    int q;\n    in(q);\n    rep(i,\
    \ q) {\n        string p;\n        in(p);\n        out(f.substrCount(p) != 0);\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - string/FMindex.hpp
  - data-structure/wavelet-matrix/WaveletMatrixString.hpp
  - string/SuffixArray.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
  requiredBy: []
  timestamp: '2024-09-26 13:24:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
- /verify/verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp.html
title: verify/AizuOnlineJudge/string/ALDS1_14_D.test.cpp
---