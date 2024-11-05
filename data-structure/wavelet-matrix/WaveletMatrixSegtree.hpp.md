---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp\"\
    \ntemplate <class T, auto op, auto e>\nclass BitVector {\n   private:\n    unsigned\
    \ n, cur, p;\n    vector<unsigned> acc, bit;\n    segtree<T, op, e> seg;\n\n \
    \  public:\n    BitVector() {\n    }\n\n    BitVector(vector<bool> &b) {\n   \
    \     cur = 0;\n        n = b.size();\n        acc.resize((n >> 5) + 2, 0);\n\
    \        bit.resize((n >> 5) + 2, 0);\n        for (int i = 0; i < n; i++) {\n\
    \            if (!(i & 31)) {\n                cur++;\n                acc[cur]\
    \ = acc[cur - 1];\n            }\n            if (b[i]) {\n                acc[cur]\
    \ += int(b[i]);\n                bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n\
    \            }\n        }\n    }\n\n    inline void seg_set(const vector<T> &v)\
    \ {\n        seg = segtree<T, op, e>(v);\n    }\n\n    inline unsigned rank(unsigned\
    \ k) {\n        if (!(k & 31)) return acc[k >> 5];\n        return acc[k >> 5]\
    \ + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));\n    }\n\n    inline unsigned\
    \ rank0(unsigned k) {\n        return k - rank(k);\n    }\n\n    inline T rank_prod(unsigned\
    \ l, unsigned r) {\n        return seg.prod(l, r);\n    }\n\n    inline bool access(unsigned\
    \ k) {\n        return (rank(k + 1) - rank(k)) == 1;\n    }\n};\n\ntemplate <class\
    \ T, auto op, auto e>\nclass WaveletMatrix {\n   private:\n    unsigned n;\n \
    \   unsigned bitsize, logn;\n    vector<BitVector<T, op, e>> b;\n    vector<unsigned>\
    \ zero;\n    vector<int> stInd;\n    vector<unsigned> compressed;\n    vector<T>\
    \ cmp;\n    vector<T> arr;\n    vector<T> prod_pw;\n    vector<long long> sum;\n\
    \    T MI, MA;\n\n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n    unsigned rank_less(unsigned l, unsigned r,\
    \ T k) {\n        unsigned less = 0;\n        for (unsigned i = 0; i < bitsize\
    \ and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n    \
    \        const unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l\
    \ = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n        \
    \    if (k & (1U << (bitsize - i - 1))) {\n                less += (rank0_r -\
    \ rank0_l);\n                l = zero[i] + rank1_l;\n                r = zero[i]\
    \ + rank1_r;\n            } else {\n                l = rank0_l;\n           \
    \     r = rank0_r;\n            }\n        }\n        return less;\n    }\n\n\
    \    inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n    inline unsigned index(const T &x)\
    \ {\n        return lower_bound(arr.begin(), arr.end(), x) - begin(arr);\n   \
    \ }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix()\
    \ {}\n    WaveletMatrix(vector<T> v) {\n        MI = numeric_limits<T>::min();\n\
    \        MA = numeric_limits<T>::max();\n        n = v.size();\n\n        logn\
    \ = bit_width(n);\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n \
    \       arr = cmp;\n        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n\
    \        compressed.resize(n);\n        sum.resize(n + 1);\n        prod_pw.resize(32);\n\
    \        vector<T> tmp(n);\n        vector<unsigned> tmpc(n);\n        unsigned\
    \ size_mx = v.size();\n        for (unsigned i = 0; i < n; i++) {\n          \
    \  compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));\n\
    \            sum[i + 1] = sum[i] + v[i];\n        }\n        stInd.resize(cmp.size()\
    \ + 1, -1);\n        bitsize = bit_width(cmp.size());\n        b.resize(bitsize\
    \ + 1);\n        zero.resize(bitsize, 0);\n        vector<bool> bit(n, 0);\n \
    \       for (unsigned i = 0; i < bitsize; i++) {\n            for (unsigned j\
    \ = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U << (bitsize\
    \ - i - 1));\n                zero[i] += unsigned(!bit[j]);\n                tmp[j]\
    \ = v[j];\n                tmpc[j] = compressed[j];\n            }\n         \
    \   b[i] = BitVector<T, op, e>(bit);\n            b[i].seg_set(v);\n         \
    \   int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n           \
    \     if (!bit[j]) {\n                    v[cur] = tmp[j];\n                 \
    \   compressed[cur] = tmpc[j];\n                    cur++;\n                }\n\
    \            }\n            for (unsigned j = 0; j < n; j++) {\n             \
    \   if (bit[j]) {\n                    v[cur] = tmp[j];\n                    compressed[cur]\
    \ = tmpc[j];\n                    cur++;\n                }\n            }\n \
    \           b[i + 1].seg_set(v);\n        }\n\n        for (unsigned i = 0; i\
    \ < n; i++) {\n            if (stInd[compressed[i]] == -1) {\n               \
    \ stInd[compressed[i]] = i;\n            }\n        }\n    }\n\n    // get v[k]\n\
    \    T access(unsigned k) {\n        unsigned res = 0;\n        unsigned cur =\
    \ k;\n        for (unsigned i = 0; i < bitsize; i++) {\n            if (b[i].access(cur))\
    \ {\n                res |= (1U << (bitsize - i - 1));\n                cur =\
    \ zero[i] + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[0,k) \u4E2D\
    \u3067\u306Ec\u306E\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned\
    \ k, T c) {\n        c = compress(c);\n        unsigned cur = k;\n        if (stInd[c]\
    \ == -1) {\n            return 0;\n        }\n        for (unsigned i = 0; i <\
    \ bitsize; i++) {\n            if (c & (1U << (bitsize - i - 1))) {\n        \
    \        cur = zero[i] + b[i].rank(cur);\n            } else {\n             \
    \   cur -= b[i].rank(cur);\n            }\n        }\n        return cur - stInd[c];\n\
    \    }\n\n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\
    \u3044\u5024\u3092\u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL\
    \ << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n      \
    \          r = zero[i] + b[i].rank(r);\n                k -= num0;\n         \
    \   } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r]\u3092\u6607\u9806\u30BD\u30FC\u30C8\
    \u3057\u305F\u6642\u306E\u5148\u982Dk\u500B\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\
    \n    T kth_ascending_prod(unsigned l, unsigned r, unsigned k) {\n        T res\
    \ = e();\n        unsigned val = 0;\n        for (unsigned i = 0; i < bitsize;\
    \ i++) {\n            const unsigned rank1_l = b[i].rank(l);\n            const\
    \ unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l = l - rank1_l;\n\
    \            const unsigned rank0_r = r - rank1_r;\n            const unsigned\
    \ num1 = rank1_r - rank1_l;\n            const unsigned num0 = rank0_r - rank0_l;\n\
    \            if (num0 < k) {\n                val |= (1ULL << (bitsize - i - 1));\n\
    \                res = op(res, b[i].rank_prod(rank0_l, rank0_r));\n          \
    \      l = zero[i] + rank1_l;\n                r = zero[i] + rank1_r;\n      \
    \          k -= num0;\n            } else {\n                l = rank0_l;\n  \
    \              r = rank0_r;\n            }\n        }\n        int bw = bit_width(k);\n\
    \        prod_pw[0] = cmp[val];\n        for (int i = 1; i < bw; i++) {\n    \
    \        prod_pw[i] = op(prod_pw[i - 1], prod_pw[i - 1]);\n        }\n       \
    \ for (int i = 0; i < bw; i++) {\n            if (k & (1 << i)) {\n          \
    \      res = op(res, prod_pw[i]);\n            }\n        }\n        return res;\n\
    \    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n    unsigned range_freq(unsigned l, unsigned r,\
    \ T mink, T maxk) {\n        mink = compress(mink);\n        maxk = compress(maxk);\n\
    \        if (mink == 0) {\n            return rank_less(l, r, maxk);\n       \
    \ }\n        return rank_less(l, r, maxk) - rank_less(l, r, mink);\n    }\n\n\
    \    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Cupper\u672A\u6E80\u306E\u7DCF\u7A4D\
    \u3092\u8FD4\u3059\n    T rank_less_prod(unsigned l, unsigned r, T upper) {\n\
    \        T ret = e();\n        unsigned k = compress(upper);\n        for (unsigned\
    \ i = 0; i < bitsize and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n\
    \            const unsigned rank1_r = b[i].rank(r);\n            const unsigned\
    \ rank0_l = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n\
    \            if (k & (1U << (bitsize - i - 1))) {\n                ret = op(ret,\
    \ b[i].rank_prod(rank0_l, rank0_r));\n                l = zero[i] + rank1_l;\n\
    \                r = zero[i] + rank1_r;\n            } else {\n              \
    \  l = rank0_l;\n                r = rank0_r;\n            }\n        }\n    \
    \    return ret;\n    }\n\n    // [L,R) x [y1,y2)\n\n    T range_prod(int L, int\
    \ R, T y1, T y2) {\n        int lo = compress(y1);\n        int hi = compress(y2);\n\
    \        T t = e();\n        auto dfs = [&](auto &dfs, int d, int L, int R, int\
    \ A, int B) -> void {\n            if (hi <= A || B <= lo) return;\n         \
    \   if (lo <= A && B <= hi) {\n                t = op(t, b[d].rank_prod(L, R));\n\
    \                return;\n            }\n            if (d == bitsize) {\n   \
    \             if (lo <= A && A < hi) {\n                    t = op(t, b[bitsize].rank_prod(L,\
    \ R));\n                }\n                return;\n            }\n          \
    \  int C = (A + B) / 2;\n            int l0 = L - b[d].rank(L);\n            int\
    \ r0 = R - b[d].rank(R);\n            int l1 = b[d].rank(L) + zero[d];\n     \
    \       int r1 = b[d].rank(R) + zero[d];\n\n            dfs(dfs, d + 1, l0, r0,\
    \ A, C);\n            dfs(dfs, d + 1, l1, r1, C, B);\n        };\n        dfs(dfs,\
    \ 0, L, R, 0, 1 << bitsize);\n        return t;\n    }\n\n    // v[l,r)\u306E\u4E2D\
    \u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\
    \n    T prev_value(unsigned l, unsigned r, T val) {\n        int num = range_freq(l,\
    \ r, MI, val);\n        if (num == 0) {\n            return MA;\n        } else\
    \ {\n            return kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\
    \u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n\
    \    T next_value(unsigned l, unsigned r, T val) {\n        int num = range_freq(l,\
    \ r, MI, val);\n        if (num == r - l) {\n            return MI;\n        }\
    \ else {\n            return kth_smallest(l, r, num + 1);\n        }\n    }\n\
    };\n"
  code: "template <class T, auto op, auto e>\nclass BitVector {\n   private:\n   \
    \ unsigned n, cur, p;\n    vector<unsigned> acc, bit;\n    segtree<T, op, e> seg;\n\
    \n   public:\n    BitVector() {\n    }\n\n    BitVector(vector<bool> &b) {\n \
    \       cur = 0;\n        n = b.size();\n        acc.resize((n >> 5) + 2, 0);\n\
    \        bit.resize((n >> 5) + 2, 0);\n        for (int i = 0; i < n; i++) {\n\
    \            if (!(i & 31)) {\n                cur++;\n                acc[cur]\
    \ = acc[cur - 1];\n            }\n            if (b[i]) {\n                acc[cur]\
    \ += int(b[i]);\n                bit[cur - 1] |= (1U << (32 - (i & 31) - 1));\n\
    \            }\n        }\n    }\n\n    inline void seg_set(const vector<T> &v)\
    \ {\n        seg = segtree<T, op, e>(v);\n    }\n\n    inline unsigned rank(unsigned\
    \ k) {\n        if (!(k & 31)) return acc[k >> 5];\n        return acc[k >> 5]\
    \ + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));\n    }\n\n    inline unsigned\
    \ rank0(unsigned k) {\n        return k - rank(k);\n    }\n\n    inline T rank_prod(unsigned\
    \ l, unsigned r) {\n        return seg.prod(l, r);\n    }\n\n    inline bool access(unsigned\
    \ k) {\n        return (rank(k + 1) - rank(k)) == 1;\n    }\n};\n\ntemplate <class\
    \ T, auto op, auto e>\nclass WaveletMatrix {\n   private:\n    unsigned n;\n \
    \   unsigned bitsize, logn;\n    vector<BitVector<T, op, e>> b;\n    vector<unsigned>\
    \ zero;\n    vector<int> stInd;\n    vector<unsigned> compressed;\n    vector<T>\
    \ cmp;\n    vector<T> arr;\n    vector<T> prod_pw;\n    vector<long long> sum;\n\
    \    T MI, MA;\n\n    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Ck\u672A\u6E80\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n    unsigned rank_less(unsigned l, unsigned r,\
    \ T k) {\n        unsigned less = 0;\n        for (unsigned i = 0; i < bitsize\
    \ and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n    \
    \        const unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l\
    \ = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n        \
    \    if (k & (1U << (bitsize - i - 1))) {\n                less += (rank0_r -\
    \ rank0_l);\n                l = zero[i] + rank1_l;\n                r = zero[i]\
    \ + rank1_r;\n            } else {\n                l = rank0_l;\n           \
    \     r = rank0_r;\n            }\n        }\n        return less;\n    }\n\n\
    \    inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n    inline unsigned index(const T &x)\
    \ {\n        return lower_bound(arr.begin(), arr.end(), x) - begin(arr);\n   \
    \ }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix()\
    \ {}\n    WaveletMatrix(vector<T> v) {\n        MI = numeric_limits<T>::min();\n\
    \        MA = numeric_limits<T>::max();\n        n = v.size();\n\n        logn\
    \ = bit_width(n);\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n \
    \       arr = cmp;\n        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n\
    \        compressed.resize(n);\n        sum.resize(n + 1);\n        prod_pw.resize(32);\n\
    \        vector<T> tmp(n);\n        vector<unsigned> tmpc(n);\n        unsigned\
    \ size_mx = v.size();\n        for (unsigned i = 0; i < n; i++) {\n          \
    \  compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), v[i]));\n\
    \            sum[i + 1] = sum[i] + v[i];\n        }\n        stInd.resize(cmp.size()\
    \ + 1, -1);\n        bitsize = bit_width(cmp.size());\n        b.resize(bitsize\
    \ + 1);\n        zero.resize(bitsize, 0);\n        vector<bool> bit(n, 0);\n \
    \       for (unsigned i = 0; i < bitsize; i++) {\n            for (unsigned j\
    \ = 0; j < n; j++) {\n                bit[j] = compressed[j] & (1U << (bitsize\
    \ - i - 1));\n                zero[i] += unsigned(!bit[j]);\n                tmp[j]\
    \ = v[j];\n                tmpc[j] = compressed[j];\n            }\n         \
    \   b[i] = BitVector<T, op, e>(bit);\n            b[i].seg_set(v);\n         \
    \   int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n           \
    \     if (!bit[j]) {\n                    v[cur] = tmp[j];\n                 \
    \   compressed[cur] = tmpc[j];\n                    cur++;\n                }\n\
    \            }\n            for (unsigned j = 0; j < n; j++) {\n             \
    \   if (bit[j]) {\n                    v[cur] = tmp[j];\n                    compressed[cur]\
    \ = tmpc[j];\n                    cur++;\n                }\n            }\n \
    \           b[i + 1].seg_set(v);\n        }\n\n        for (unsigned i = 0; i\
    \ < n; i++) {\n            if (stInd[compressed[i]] == -1) {\n               \
    \ stInd[compressed[i]] = i;\n            }\n        }\n    }\n\n    // get v[k]\n\
    \    T access(unsigned k) {\n        unsigned res = 0;\n        unsigned cur =\
    \ k;\n        for (unsigned i = 0; i < bitsize; i++) {\n            if (b[i].access(cur))\
    \ {\n                res |= (1U << (bitsize - i - 1));\n                cur =\
    \ zero[i] + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[0,k) \u4E2D\
    \u3067\u306Ec\u306E\u51FA\u73FE\u56DE\u6570\u3092\u8FD4\u3059\n    unsigned rank(unsigned\
    \ k, T c) {\n        c = compress(c);\n        unsigned cur = k;\n        if (stInd[c]\
    \ == -1) {\n            return 0;\n        }\n        for (unsigned i = 0; i <\
    \ bitsize; i++) {\n            if (c & (1U << (bitsize - i - 1))) {\n        \
    \        cur = zero[i] + b[i].rank(cur);\n            } else {\n             \
    \   cur -= b[i].rank(cur);\n            }\n        }\n        return cur - stInd[c];\n\
    \    }\n\n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\
    \u3044\u5024\u3092\u8FD4\u3059\n    T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n        unsigned res = 0;\n        for (unsigned i = 0; i < bitsize; i++)\
    \ {\n            unsigned num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned\
    \ num0 = r - l - num1;\n            if (num0 < k) {\n                res |= (1ULL\
    \ << (bitsize - i - 1));\n                l = zero[i] + b[i].rank(l);\n      \
    \          r = zero[i] + b[i].rank(r);\n                k -= num0;\n         \
    \   } else {\n                l -= b[i].rank(l);\n                r -= b[i].rank(r);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_largest(unsigned l, unsigned r, unsigned k) {\n        return kth_smallest(l,\
    \ r, r - l - k + 1);\n    }\n\n    // v[l,r]\u3092\u6607\u9806\u30BD\u30FC\u30C8\
    \u3057\u305F\u6642\u306E\u5148\u982Dk\u500B\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\
    \n    T kth_ascending_prod(unsigned l, unsigned r, unsigned k) {\n        T res\
    \ = e();\n        unsigned val = 0;\n        for (unsigned i = 0; i < bitsize;\
    \ i++) {\n            const unsigned rank1_l = b[i].rank(l);\n            const\
    \ unsigned rank1_r = b[i].rank(r);\n            const unsigned rank0_l = l - rank1_l;\n\
    \            const unsigned rank0_r = r - rank1_r;\n            const unsigned\
    \ num1 = rank1_r - rank1_l;\n            const unsigned num0 = rank0_r - rank0_l;\n\
    \            if (num0 < k) {\n                val |= (1ULL << (bitsize - i - 1));\n\
    \                res = op(res, b[i].rank_prod(rank0_l, rank0_r));\n          \
    \      l = zero[i] + rank1_l;\n                r = zero[i] + rank1_r;\n      \
    \          k -= num0;\n            } else {\n                l = rank0_l;\n  \
    \              r = rank0_r;\n            }\n        }\n        int bw = bit_width(k);\n\
    \        prod_pw[0] = cmp[val];\n        for (int i = 1; i < bw; i++) {\n    \
    \        prod_pw[i] = op(prod_pw[i - 1], prod_pw[i - 1]);\n        }\n       \
    \ for (int i = 0; i < bw; i++) {\n            if (k & (1 << i)) {\n          \
    \      res = op(res, prod_pw[i]);\n            }\n        }\n        return res;\n\
    \    }\n\n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n    unsigned range_freq(unsigned l, unsigned r,\
    \ T mink, T maxk) {\n        mink = compress(mink);\n        maxk = compress(maxk);\n\
    \        if (mink == 0) {\n            return rank_less(l, r, maxk);\n       \
    \ }\n        return rank_less(l, r, maxk) - rank_less(l, r, mink);\n    }\n\n\
    \    // v[l,r) \u306E\u4E2D\u3067\u5024\u304Cupper\u672A\u6E80\u306E\u7DCF\u7A4D\
    \u3092\u8FD4\u3059\n    T rank_less_prod(unsigned l, unsigned r, T upper) {\n\
    \        T ret = e();\n        unsigned k = compress(upper);\n        for (unsigned\
    \ i = 0; i < bitsize and l < r; i++) {\n            const unsigned rank1_l = b[i].rank(l);\n\
    \            const unsigned rank1_r = b[i].rank(r);\n            const unsigned\
    \ rank0_l = l - rank1_l;\n            const unsigned rank0_r = r - rank1_r;\n\
    \            if (k & (1U << (bitsize - i - 1))) {\n                ret = op(ret,\
    \ b[i].rank_prod(rank0_l, rank0_r));\n                l = zero[i] + rank1_l;\n\
    \                r = zero[i] + rank1_r;\n            } else {\n              \
    \  l = rank0_l;\n                r = rank0_r;\n            }\n        }\n    \
    \    return ret;\n    }\n\n    // [L,R) x [y1,y2)\n\n    T range_prod(int L, int\
    \ R, T y1, T y2) {\n        int lo = compress(y1);\n        int hi = compress(y2);\n\
    \        T t = e();\n        auto dfs = [&](auto &dfs, int d, int L, int R, int\
    \ A, int B) -> void {\n            if (hi <= A || B <= lo) return;\n         \
    \   if (lo <= A && B <= hi) {\n                t = op(t, b[d].rank_prod(L, R));\n\
    \                return;\n            }\n            if (d == bitsize) {\n   \
    \             if (lo <= A && A < hi) {\n                    t = op(t, b[bitsize].rank_prod(L,\
    \ R));\n                }\n                return;\n            }\n          \
    \  int C = (A + B) / 2;\n            int l0 = L - b[d].rank(L);\n            int\
    \ r0 = R - b[d].rank(R);\n            int l1 = b[d].rank(L) + zero[d];\n     \
    \       int r1 = b[d].rank(R) + zero[d];\n\n            dfs(dfs, d + 1, l0, r0,\
    \ A, C);\n            dfs(dfs, d + 1, l1, r1, C, B);\n        };\n        dfs(dfs,\
    \ 0, L, R, 0, 1 << bitsize);\n        return t;\n    }\n\n    // v[l,r)\u306E\u4E2D\
    \u3067val\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\
    \n    T prev_value(unsigned l, unsigned r, T val) {\n        int num = range_freq(l,\
    \ r, MI, val);\n        if (num == 0) {\n            return MA;\n        } else\
    \ {\n            return kth_smallest(l, r, num);\n        }\n    }\n\n    // v[l,r)\u306E\
    \u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3092\u8FD4\u3059\n\
    \    T next_value(unsigned l, unsigned r, T val) {\n        int num = range_freq(l,\
    \ r, MI, val);\n        if (num == r - l) {\n            return MI;\n        }\
    \ else {\n            return kth_smallest(l, r, num + 1);\n        }\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
  requiredBy: []
  timestamp: '2024-11-05 10:22:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixSegtree.hpp
layout: document
title: Wavelet Matrix (Segment Tree)
---

## 概要

todo

## 計算量
todo