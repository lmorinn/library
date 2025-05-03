---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp
    title: Point Add Rectangle Sum
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix/query/RectangleAddPointGet.hpp
    title: Rectangle Add Point Get
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/wavelet-matrix/query/PointAddRectangleSum.test.cpp
    title: verify/LibraryChecker/data-structure/wavelet-matrix/query/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddPointGet.test.cpp
    title: verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddPointGet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree/BinaryIndexedTree.hpp\"\
    \n\ntemplate <class T>\nstruct fenwick_tree {\n   public:\n    fenwick_tree()\
    \ : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n) {}\n\n    void\
    \ add(int p, T x) {\n        p++;\n        while (p <= _n) {\n            data[p\
    \ - 1] += x;\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int\
    \ r) {\n        return sum(r) - sum(l);\n    }\n\n   private:\n    int _n;\n \
    \   vector<T> data;\n\n    T sum(int r) {\n        T s = 0;\n        while (r\
    \ > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n\
    \        return s;\n    }\n};\n#line 2 \"data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp\"\
    \ntemplate <class T>\nstruct BitVector {\n    unsigned sz;\n    unsigned blocksize;\n\
    \    vector<unsigned long long> bit;\n    vector<unsigned> sum;\n    fenwick_tree<T>\
    \ seg;\n\n    BitVector() {}\n\n    BitVector(unsigned siz) {\n        sz = siz;\n\
    \        blocksize = (sz + 63) >> 6;\n        bit.assign(blocksize, 0ULL);\n \
    \       sum.assign(blocksize, 0U);\n    }\n\n    inline void set(int k) { bit[k\
    \ >> 6] |= 1ULL << (k & 63ULL); }\n\n    inline void build() {\n        sum[0]\
    \ = 0ULL;\n        for (int i = 1; i < blocksize; i++) {\n            sum[i] =\
    \ sum[i - 1] + __builtin_popcountll(bit[i - 1]);\n        }\n    }\n\n    inline\
    \ bool access(unsigned k) {\n        return (bool((bit[k >> 6] >> (k & 63)) &\
    \ 1));\n    }\n\n    inline int rank(int k) {\n        return (sum[k >> 6] + __builtin_popcountll(bit[k\
    \ >> 6] & ((1ULL << (k & 63)) - 1)));\n    }\n\n    inline void ft_set(const vector<T>\
    \ &v) {\n        seg = fenwick_tree<T>(v.size());\n        for (int i = 0; i <\
    \ v.size(); i++) {\n            if (v[i] != 0) {\n                seg.add(i, v[i]);\n\
    \            }\n        }\n    }\n\n    inline void val_add(unsigned pos, T x)\
    \ {\n        seg.add(pos, x);\n    }\n\n    inline T val_get(unsigned pos) {\n\
    \        return seg.sum(pos, pos + 1);\n    }\n\n    inline T rank_sum(unsigned\
    \ l, unsigned r) {\n        return seg.sum(l, r);\n    }\n};\n\ntemplate <class\
    \ T>\nclass WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned bitsize,\
    \ logn;\n    vector<BitVector<T>> b;\n    vector<unsigned> zero;\n    vector<unsigned>\
    \ index;\n    vector<T> cmp;\n    vector<T> px;\n    T MI, MA;\n\n    inline unsigned\
    \ compress(const T &x) {\n        return lower_bound(cmp.begin(), cmp.end(), x)\
    \ - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n    WaveletMatrix() {}\n    WaveletMatrix(vector<T> v) {\n        MI =\
    \ numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n        n\
    \ = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n     \
    \   cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<T> tmp(n);\n\
    \        vector<T> tmpc(n);\n        vector<T> compressed(n);\n        for (unsigned\
    \ i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int cur\
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T>(n\
    \ + 1);\n            b[i].ft_set(v);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = v[j];\n                    cur++;\n          \
    \      }\n            }\n            b[i].build();\n            for (int j = 0;\
    \ j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i - 1)))\
    \ {\n                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = v[j];\n                    cur++;\n                }\n            }\n    \
    \        swap(tmpc, compressed);\n            swap(tmp, v);\n        }\n     \
    \   b[bitsize] = BitVector<T>(n + 1);\n        b[bitsize].ft_set(v);\n    }\n\n\
    \    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {\n        n = x.size();\n\
    \        px.resize(n);\n        index.resize(n);\n        vector<tuple<T, T, T,\
    \ int>> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i] = {x[i],\
    \ y[i], w[i], i};\n        }\n        sort(v.begin(), v.end(), [](const tuple<T,\
    \ T, T, int> &l, const tuple<T, T, T, int> &r) {\n            return std::get<0>(l)\
    \ < std::get<0>(r);\n        });\n        for (int i = 0; i < n; i++) {\n    \
    \        px[i] = std::get<0>(v[i]);\n            y[i] = std::get<1>(v[i]);\n \
    \           w[i] = std::get<2>(v[i]);\n            index[std::get<3>(v[i])] =\
    \ i;\n        }\n        vector<unsigned> compressed(n);\n        cmp.resize(y.size());\n\
    \        cmp = y;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        vector<unsigned> tmpc(n);\n        vector<T>\
    \ tmp(n);\n        unsigned size_mx = y.size();\n        for (unsigned i = 0;\
    \ i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int cur\
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T>(n\
    \ + 1);\n            b[i].ft_set(w);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = w[j];\n                    cur++;\n          \
    \      }\n            }\n\n            b[i].build();\n            for (int j =\
    \ 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i -\
    \ 1))) {\n                    tmpc[cur] = compressed[j];\n                   \
    \ tmp[cur] = w[j];\n                    cur++;\n                }\n          \
    \  }\n            swap(tmpc, compressed);\n            swap(tmp, w);\n       \
    \ }\n\n        b[bitsize].ft_set(w);\n    }\n\n    // get v[k]\n    T access(unsigned\
    \ k) {\n        unsigned res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return cmp[res];\n    }\n\n    void set(int p, T x) {\n  \
    \      unsigned cur = index[p];\n        T before = b[0].val_get(cur);\n     \
    \   for (unsigned i = 0; i < bitsize; i++) {\n            b[i].val_add(cur, x\
    \ - before);\n            if (b[i].access(cur)) {\n                cur = zero[i]\
    \ + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        b[bitsize].val_add(cur, x - before);\n    }\n\
    \n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\
    \u5024\u3092\u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL\
    \ << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n      \
    \          r = zero[i] + b[i].rank(r);\n                k -= num0;\n         \
    \   } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\
    \u5165\u308B\u5024\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n    T range_sum(int vl,\
    \ int vr, T mink, T maxk) {\n        int D = compress(mink);\n        int U =\
    \ compress(maxk);\n        T res = 0;\n        auto dfs = [&](auto &rec, int d,\
    \ int L, int R, int A, int B) -> void {\n            if (U <= A or B <= D) return;\n\
    \            if (D <= A and B <= U) {\n                res += b[d].rank_sum(L,\
    \ R);\n                return;\n            }\n            if (d == bitsize) {\n\
    \                if (D <= A and A < U) {\n                    res += b[bitsize].rank_sum(L,\
    \ R);\n                }\n                return;\n            }\n           \
    \ int C = (A + B) >> 1;\n            int rank0_l = L - b[d].rank(L);\n       \
    \     int rank0_r = R - b[d].rank(R);\n            int rank1_l = b[d].rank(L)\
    \ + zero[d];\n            int rank1_r = b[d].rank(R) + zero[d];\n\n          \
    \  rec(rec, d + 1, rank0_l, rank0_r, A, C);\n            rec(rec, d + 1, rank1_l,\
    \ rank1_r, C, B);\n        };\n        dfs(dfs, 0, vl, vr, 0, 1 << bitsize);\n\
    \        return res;\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\
    \u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n    T prev_value(unsigned\
    \ l, unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n    \
    \    if (num == 0) {\n            return MA;\n        } else {\n            return\
    \ kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067\
    val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n    T next_value(unsigned\
    \ l, unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n    \
    \    if (num == r - l) {\n            return MI;\n        } else {\n         \
    \   return kth_smallest(l, r, num + 1);\n        }\n    }\n\n    // x\u5EA7\u6A19\
    \u304C[l,r) \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n    T rectangle_sum(T l, T r, T d, T u) {\n  \
    \      unsigned cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));\n\
    \        unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n        return range_sum(cl, cr, d, u);\n    }\n};\n"
  code: "#include \"../binary-indexed-tree/BinaryIndexedTree.hpp\"\ntemplate <class\
    \ T>\nstruct BitVector {\n    unsigned sz;\n    unsigned blocksize;\n    vector<unsigned\
    \ long long> bit;\n    vector<unsigned> sum;\n    fenwick_tree<T> seg;\n\n   \
    \ BitVector() {}\n\n    BitVector(unsigned siz) {\n        sz = siz;\n       \
    \ blocksize = (sz + 63) >> 6;\n        bit.assign(blocksize, 0ULL);\n        sum.assign(blocksize,\
    \ 0U);\n    }\n\n    inline void set(int k) { bit[k >> 6] |= 1ULL << (k & 63ULL);\
    \ }\n\n    inline void build() {\n        sum[0] = 0ULL;\n        for (int i =\
    \ 1; i < blocksize; i++) {\n            sum[i] = sum[i - 1] + __builtin_popcountll(bit[i\
    \ - 1]);\n        }\n    }\n\n    inline bool access(unsigned k) {\n        return\
    \ (bool((bit[k >> 6] >> (k & 63)) & 1));\n    }\n\n    inline int rank(int k)\
    \ {\n        return (sum[k >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL <<\
    \ (k & 63)) - 1)));\n    }\n\n    inline void ft_set(const vector<T> &v) {\n \
    \       seg = fenwick_tree<T>(v.size());\n        for (int i = 0; i < v.size();\
    \ i++) {\n            if (v[i] != 0) {\n                seg.add(i, v[i]);\n  \
    \          }\n        }\n    }\n\n    inline void val_add(unsigned pos, T x) {\n\
    \        seg.add(pos, x);\n    }\n\n    inline T val_get(unsigned pos) {\n   \
    \     return seg.sum(pos, pos + 1);\n    }\n\n    inline T rank_sum(unsigned l,\
    \ unsigned r) {\n        return seg.sum(l, r);\n    }\n};\n\ntemplate <class T>\n\
    class WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned bitsize, logn;\n\
    \    vector<BitVector<T>> b;\n    vector<unsigned> zero;\n    vector<unsigned>\
    \ index;\n    vector<T> cmp;\n    vector<T> px;\n    T MI, MA;\n\n    inline unsigned\
    \ compress(const T &x) {\n        return lower_bound(cmp.begin(), cmp.end(), x)\
    \ - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n    WaveletMatrix() {}\n    WaveletMatrix(vector<T> v) {\n        MI =\
    \ numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n        n\
    \ = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n     \
    \   cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<T> tmp(n);\n\
    \        vector<T> tmpc(n);\n        vector<T> compressed(n);\n        for (unsigned\
    \ i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int cur\
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T>(n\
    \ + 1);\n            b[i].ft_set(v);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = v[j];\n                    cur++;\n          \
    \      }\n            }\n            b[i].build();\n            for (int j = 0;\
    \ j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i - 1)))\
    \ {\n                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = v[j];\n                    cur++;\n                }\n            }\n    \
    \        swap(tmpc, compressed);\n            swap(tmp, v);\n        }\n     \
    \   b[bitsize] = BitVector<T>(n + 1);\n        b[bitsize].ft_set(v);\n    }\n\n\
    \    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {\n        n = x.size();\n\
    \        px.resize(n);\n        index.resize(n);\n        vector<tuple<T, T, T,\
    \ int>> v(n);\n        for (int i = 0; i < n; i++) {\n            v[i] = {x[i],\
    \ y[i], w[i], i};\n        }\n        sort(v.begin(), v.end(), [](const tuple<T,\
    \ T, T, int> &l, const tuple<T, T, T, int> &r) {\n            return std::get<0>(l)\
    \ < std::get<0>(r);\n        });\n        for (int i = 0; i < n; i++) {\n    \
    \        px[i] = std::get<0>(v[i]);\n            y[i] = std::get<1>(v[i]);\n \
    \           w[i] = std::get<2>(v[i]);\n            index[std::get<3>(v[i])] =\
    \ i;\n        }\n        vector<unsigned> compressed(n);\n        cmp.resize(y.size());\n\
    \        cmp = y;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        vector<unsigned> tmpc(n);\n        vector<T>\
    \ tmp(n);\n        unsigned size_mx = y.size();\n        for (unsigned i = 0;\
    \ i < n; i++) {\n            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(),\
    \ cmp.end(), y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n  \
    \      b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int cur\
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T>(n\
    \ + 1);\n            b[i].ft_set(w);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = w[j];\n                    cur++;\n          \
    \      }\n            }\n\n            b[i].build();\n            for (int j =\
    \ 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i -\
    \ 1))) {\n                    tmpc[cur] = compressed[j];\n                   \
    \ tmp[cur] = w[j];\n                    cur++;\n                }\n          \
    \  }\n            swap(tmpc, compressed);\n            swap(tmp, w);\n       \
    \ }\n\n        b[bitsize].ft_set(w);\n    }\n\n    // get v[k]\n    T access(unsigned\
    \ k) {\n        unsigned res = 0;\n        unsigned cur = k;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            if (b[i].access(cur)) {\n          \
    \      res |= (1U << (bitsize - i - 1));\n                cur = zero[i] + b[i].rank(cur);\n\
    \            } else {\n                cur -= b[i].rank(cur);\n            }\n\
    \        }\n        return cmp[res];\n    }\n\n    void set(int p, T x) {\n  \
    \      unsigned cur = index[p];\n        T before = b[0].val_get(cur);\n     \
    \   for (unsigned i = 0; i < bitsize; i++) {\n            b[i].val_add(cur, x\
    \ - before);\n            if (b[i].access(cur)) {\n                cur = zero[i]\
    \ + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        b[bitsize].val_add(cur, x - before);\n    }\n\
    \n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\
    \u5024\u3092\u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL\
    \ << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n      \
    \          r = zero[i] + b[i].rank(r);\n                k -= num0;\n         \
    \   } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\
    \u5165\u308B\u5024\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\n    T range_sum(int vl,\
    \ int vr, T mink, T maxk) {\n        int D = compress(mink);\n        int U =\
    \ compress(maxk);\n        T res = 0;\n        auto dfs = [&](auto &rec, int d,\
    \ int L, int R, int A, int B) -> void {\n            if (U <= A or B <= D) return;\n\
    \            if (D <= A and B <= U) {\n                res += b[d].rank_sum(L,\
    \ R);\n                return;\n            }\n            if (d == bitsize) {\n\
    \                if (D <= A and A < U) {\n                    res += b[bitsize].rank_sum(L,\
    \ R);\n                }\n                return;\n            }\n           \
    \ int C = (A + B) >> 1;\n            int rank0_l = L - b[d].rank(L);\n       \
    \     int rank0_r = R - b[d].rank(R);\n            int rank1_l = b[d].rank(L)\
    \ + zero[d];\n            int rank1_r = b[d].rank(R) + zero[d];\n\n          \
    \  rec(rec, d + 1, rank0_l, rank0_r, A, C);\n            rec(rec, d + 1, rank1_l,\
    \ rank1_r, C, B);\n        };\n        dfs(dfs, 0, vl, vr, 0, 1 << bitsize);\n\
    \        return res;\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067val\u3092\u8D85\u3048\
    \u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n    T prev_value(unsigned\
    \ l, unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n    \
    \    if (num == 0) {\n            return MA;\n        } else {\n            return\
    \ kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\u4E2D\u3067\
    val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n    T next_value(unsigned\
    \ l, unsigned r, T val) {\n        int num = range_freq(l, r, MI, val);\n    \
    \    if (num == r - l) {\n            return MI;\n        } else {\n         \
    \   return kth_smallest(l, r, num + 1);\n        }\n    }\n\n    // x\u5EA7\u6A19\
    \u304C[l,r) \u304B\u3064y\u5EA7\u6A19\u304C[d,u) \u306B\u5165\u308B\u70B9\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n    T rectangle_sum(T l, T r, T d, T u) {\n  \
    \      unsigned cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));\n\
    \        unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n        return range_sum(cl, cr, d, u);\n    }\n};"
  dependsOn:
  - data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp
  requiredBy:
  - data-structure/wavelet-matrix/query/RectangleAddPointGet.hpp
  - data-structure/wavelet-matrix/query/PointAddRectangleSum.hpp
  timestamp: '2024-11-18 02:13:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/wavelet-matrix/query/PointAddRectangleSum.test.cpp
  - verify/LibraryChecker/data-structure/wavelet-matrix/query/RectangleAddPointGet.test.cpp
documentation_of: data-structure/wavelet-matrix/WaveletMatrixBinaryIndexedTree.hpp
layout: document
title: Wavelet Matrix (Binary Indexed Tree)
---

## 概要

todo

## 計算量
todo