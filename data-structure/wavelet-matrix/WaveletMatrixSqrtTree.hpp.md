---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/others/SqrtTree.hpp
    title: Sqrt Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/others/SqrtTree.hpp\"\n\ntemplate <class\
    \ S, auto op>\nclass SqrtTree {\n   private:\n    vector<vector<S>> prefix, suffix,\
    \ between;\n    vector<S> v;\n    vector<int> layerlg, layerv;\n\n   public:\n\
    \    SqrtTree() = default;\n    SqrtTree(vector<S> &a) {\n        v = a;\n   \
    \     int n = v.size();\n        int lg = 0;\n        lg = bit_width(ull(n));\n\
    \        int n_layer = 0;\n        layerv.resize(lg + 1);\n        for (int i\
    \ = lg; i > 1; i = (i + 1) >> 1) {\n            layerv[i] = n_layer++;\n     \
    \       layerlg.push_back(i);\n        }\n        for (int i = lg - 1; i >= 0;\
    \ --i) layerv[i] = max(layerv[i], layerv[i + 1]);\n        prefix.resize(n_layer,\
    \ vector<S>(n));\n        suffix.resize(n_layer, vector<S>(n));\n        between.resize(n_layer,\
    \ vector<S>(1 << lg));\n\n        for (int layer = 0; layer < n_layer; ++layer)\
    \ {\n            int current_lg = layerlg[layer];\n            int prev_b_sz =\
    \ 1 << current_lg;\n            int b_sz_shift = (current_lg + 1) >> 1;\n    \
    \        int b_cnt_shift = current_lg >> 1;\n            int b_sz = 1 << b_sz_shift;\n\
    \            int b_cnt = 1 << b_cnt_shift;\n            for (int l = 0; l < n;\
    \ l += prev_b_sz) {\n                int r = min(l + prev_b_sz, n);\n        \
    \        for (int a = l; a < r; a += b_sz) {\n                    int b = min(a\
    \ + b_sz, r);\n                    prefix[layer][a] = v[a];\n                \
    \    for (int i = a + 1; i < b; ++i) {\n                        prefix[layer][i]\
    \ = op(prefix[layer][i - 1], v[i]);\n                    }\n                 \
    \   suffix[layer][b - 1] = v[b - 1];\n                    for (int i = b - 2;\
    \ i >= a; --i) {\n                        suffix[layer][i] = op(v[i], suffix[layer][i\
    \ + 1]);\n                    }\n                }\n                for (int i\
    \ = 0; i < b_cnt; ++i) {\n                    int idx = l + (i << b_sz_shift);\n\
    \                    S val = suffix[layer][idx];\n                    between[layer][(i\
    \ << b_cnt_shift) + i] = val;\n                    for (int j = i + 1; j < b_cnt;\
    \ ++j) {\n                        int suffix_idx = l + (j << b_sz_shift);\n  \
    \                      val = op(val, suffix[layer][suffix_idx]);\n           \
    \             between[layer][(i << b_cnt_shift) + j] = val;\n                \
    \    }\n                }\n            }\n        }\n    }\n\n    S prod(int l,\
    \ int r) const {\n        --r;\n        if (l == r) return v[l];\n        if (l\
    \ + 1 == r) return op(v[l], v[r]);\n        int xor_val = l ^ r;\n        int\
    \ highest_bit = 32 - __builtin_clz(xor_val);\n        int layer = layerv[highest_bit];\n\
    \        int current_lg = layerlg[layer];\n        int b_sz_shift = (current_lg\
    \ + 1) >> 1;\n        int b_cnt_shift = current_lg >> 1;\n        int b_sz = 1\
    \ << b_sz_shift;\n        int b_cnt = 1 << b_cnt_shift;\n        int a = l & (~((1\
    \ << current_lg) - 1));\n        int lblock = ((l - a) >> b_sz_shift) + 1;\n \
    \       int rblock = ((r - a) >> b_sz_shift) - 1;\n        S val = suffix[layer][l];\n\
    \        if (lblock <= rblock) val = op(val, between[layer][a + (lblock << b_cnt_shift)\
    \ + rblock]);\n        val = op(val, prefix[layer][r]);\n        return val;\n\
    \    }\n};\n#line 2 \"data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp\"\
    \ntemplate <class T, auto op>\nstruct BitVector {\n    unsigned sz;\n    unsigned\
    \ blocksize;\n    vector<unsigned long long> bit;\n    vector<unsigned> sum;\n\
    \    SqrtTree<T, op> t;\n\n    BitVector() {}\n\n    BitVector(unsigned siz) {\n\
    \        sz = siz;\n        blocksize = (sz + 63) >> 6;\n        bit.assign(blocksize,\
    \ 0ULL);\n        sum.assign(blocksize, 0U);\n    }\n\n    inline void set(int\
    \ k) { bit[k >> 6] |= 1ULL << (k & 63ULL); }\n\n    inline void build() {\n  \
    \      sum[0] = 0ULL;\n        for (int i = 1; i < blocksize; i++) {\n       \
    \     sum[i] = sum[i - 1] + __builtin_popcountll(bit[i - 1]);\n        }\n   \
    \ }\n\n    inline bool access(unsigned k) {\n        return (bool((bit[k >> 6]\
    \ >> (k & 63)) & 1));\n    }\n\n    inline int rank(int k) {\n        return (sum[k\
    \ >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL << (k & 63)) - 1)));\n   \
    \ }\n\n    inline void sqrt_set(vector<T> &v) {\n        t = SqrtTree<T, op>(v);\n\
    \    }\n\n    inline T rank_prod(int l, int r) {\n        return t.prod(l, r);\n\
    \    }\n};\n\ntemplate <class T, auto op, class S>\nclass WaveletMatrix {\n  \
    \ private:\n    unsigned n;\n    unsigned bitsize, logn;\n    vector<BitVector<T,\
    \ op>> b;\n    vector<unsigned> zero;\n    vector<unsigned> index;\n    vector<T>\
    \ cmp;\n    vector<T> px;\n    T MI, MA;\n\n    inline unsigned compress(const\
    \ T &x) {\n        return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);\n\
    \    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    WaveletMatrix()\
    \ {}\n    WaveletMatrix(vector<T> v) {\n        MI = numeric_limits<T>::min();\n\
    \        MA = numeric_limits<T>::max();\n        n = v.size();\n        cmp =\
    \ v;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        vector<T> tmp(n);\n        vector<T> tmpc(n);\n\
    \        vector<T> compressed(n);\n        for (unsigned i = 0; i < n; i++) {\n\
    \            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(),\
    \ v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n        b.resize(bitsize\
    \ + 1);\n        zero.resize(bitsize, 0);\n        int cur = 0;\n        for (unsigned\
    \ i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T, op>(n + 1);\n  \
    \          b[i].sqrt_set(v);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = v[j];\n                    cur++;\n          \
    \      }\n            }\n            b[i].build();\n            for (int j = 0;\
    \ j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i - 1)))\
    \ {\n                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = v[j];\n                    cur++;\n                }\n            }\n    \
    \        swap(tmpc, compressed);\n            swap(tmp, v);\n        }\n\n   \
    \     b[bitsize].sqrt_set(v);\n    }\n\n    WaveletMatrix(vector<T> v, vector<S>\
    \ w) {\n        MI = numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n\
    \        n = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n\
    \        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<S>\
    \ tmp(n);\n        vector<T> tmpc(n);\n        vector<T> compressed(n);\n    \
    \    for (unsigned i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int\
    \ cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i]\
    \ = BitVector<S>(n + 1);\n            b[i].sqrt_set(w);\n            cur = 0;\n\
    \            for (unsigned j = 0; j < n; j++) {\n                if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n                    b[i].set(j);\n         \
    \       } else {\n                    zero[i]++;\n                    tmpc[cur]\
    \ = compressed[j];\n                    tmp[cur] = w[j];\n                   \
    \ cur++;\n                }\n            }\n            b[i].build();\n      \
    \      for (int j = 0; j < n; j++) {\n                if (compressed[j] & (1U\
    \ << (bitsize - i - 1))) {\n                    tmpc[cur] = compressed[j];\n \
    \                   tmp[cur] = w[j];\n                    cur++;\n           \
    \     }\n            }\n            swap(tmpc, compressed);\n            swap(tmp,\
    \ w);\n        }\n        b[bitsize] = BitVector<S>(n + 1);\n        b[bitsize].sqrt_set(w);\n\
    \    }\n\n    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {\n       \
    \ n = x.size();\n        px.resize(n);\n        vector<tuple<T, T, T>> v(n);\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] = {x[i], y[i], w[i]};\n\
    \        }\n        sort(v.begin(), v.end());\n        for (int i = 0; i < n;\
    \ i++) {\n            px[i] = std::get<0>(v[i]);\n            y[i] = std::get<1>(v[i]);\n\
    \            w[i] = std::get<2>(v[i]);\n        }\n\n        cmp.resize(y.size());\n\
    \        cmp = y;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        vector<T> tmpc(n);\n        vector<T> tmp(n);\n\
    \        vector<T> compressed(n);\n        for (unsigned i = 0; i < n; i++) {\n\
    \            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(),\
    \ y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n        b.resize(bitsize\
    \ + 1);\n        zero.resize(bitsize, 0);\n        vector<bool> bit(n, 0);\n \
    \       int cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n     \
    \       b[i] = BitVector<T, op>(bit);\n            b[i].sqrt_set(w);\n       \
    \     int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n         \
    \       if (compressed[j] & (1U << (bitsize - i - 1))) {\n                   \
    \ b[i].set(j);\n                } else {\n                    zero[i]++;\n   \
    \                 tmpc[cur] = compressed[j];\n                    tmp[cur] = w[j];\n\
    \                    cur++;\n                }\n            }\n            b[i].build();\n\
    \            for (unsigned j = 0; j < n; j++) {\n                if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = w[j];\n                    cur++;\n          \
    \      }\n            }\n\n            swap(tmpc, compressed);\n            swap(tmp,\
    \ w);\n        }\n        b[bitsize].sqrt_set(w);\n    }\n\n    // get v[k]\n\
    \    T access(unsigned k) {\n        unsigned res = 0;\n        unsigned cur =\
    \ k;\n        for (unsigned i = 0; i < bitsize; i++) {\n            if (b[i].access(cur))\
    \ {\n                res |= (1U << (bitsize - i - 1));\n                cur =\
    \ zero[i] + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_smallest(unsigned l, unsigned r, unsigned k) {\n        unsigned res\
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            unsigned\
    \ num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned num0 = r - l - num1;\n\
    \            if (num0 < k) {\n                res |= (1ULL << (bitsize - i - 1));\n\
    \                l = zero[i] + b[i].rank(l);\n                r = zero[i] + b[i].rank(r);\n\
    \                k -= num0;\n            } else {\n                l -= b[i].rank(l);\n\
    \                r -= b[i].rank(r);\n            }\n        }\n        return\
    \ cmp[res];\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\
    \u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n    T kth_largest(unsigned l, unsigned\
    \ r, unsigned k) {\n        return kth_smallest(l, r, r - l - k + 1);\n    }\n\
    \n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\
    \u7A4D\u3092\u8FD4\u3059\n    T range_prod(int vl, int vr, T mink, T maxk) {\n\
    \        int D = compress(mink);\n        int U = compress(maxk);\n        T res\
    \ = e();\n        auto dfs = [&](auto &rec, int d, int L, int R, int A, int B)\
    \ -> void {\n            if (U <= A or B <= D) return;\n            if (D <= A\
    \ and B <= U) {\n                res = op(res, b[d].rank_prod(L, R));\n      \
    \          return;\n            }\n            if (d == bitsize) {\n         \
    \       if (D <= A and A < U) {\n                    res = op(res, b[bitsize].rank_prod(L,\
    \ R));\n                }\n                return;\n            }\n          \
    \  int C = (A + B) / 2;\n            int rank0_l = L - b[d].rank(L);\n       \
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
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n    T rectangle_prod(T l, T r, T d, T u) {\n \
    \       unsigned cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));\n\
    \        unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n        return range_prod(cl, cr, d, u);\n    }\n\n    template <typename\
    \ F>\n    T max_y(T xl, T xr, F check) {\n        unsigned L = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xl));\n        unsigned R = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xr));\n        int cnt = 0;\n        T prod\
    \ = e();\n        unsigned yidx = 0;\n        if (check(R - L, b[0].rank_prod(L,\
    \ R))) {\n            return cmp.back();\n        }\n        for (int i = 0; i\
    \ < bitsize; i++) {\n            int l0 = L - b[i].rank(L);\n            int r0\
    \ = R - b[i].rank(R);\n            int l1 = L + zero[i] - l0;\n            int\
    \ r1 = R + zero[i] - r0;\n            int cnt1 = cnt + r0 - l0;\n            T\
    \ tmp = op(prod, b[i + 1].rank_prod(l0, r0));\n            if (check(cnt1, tmp))\
    \ {\n                cnt = cnt1;\n                prod = tmp;\n              \
    \  L = l1;\n                R = r1;\n                yidx |= 1U << (bitsize -\
    \ i - 1);\n            } else {\n                L = l0;\n                R =\
    \ r0;\n            }\n        }\n        return cmp[yidx];\n    }\n};\n"
  code: "#include \"../others/SqrtTree.hpp\"\ntemplate <class T, auto op>\nstruct\
    \ BitVector {\n    unsigned sz;\n    unsigned blocksize;\n    vector<unsigned\
    \ long long> bit;\n    vector<unsigned> sum;\n    SqrtTree<T, op> t;\n\n    BitVector()\
    \ {}\n\n    BitVector(unsigned siz) {\n        sz = siz;\n        blocksize =\
    \ (sz + 63) >> 6;\n        bit.assign(blocksize, 0ULL);\n        sum.assign(blocksize,\
    \ 0U);\n    }\n\n    inline void set(int k) { bit[k >> 6] |= 1ULL << (k & 63ULL);\
    \ }\n\n    inline void build() {\n        sum[0] = 0ULL;\n        for (int i =\
    \ 1; i < blocksize; i++) {\n            sum[i] = sum[i - 1] + __builtin_popcountll(bit[i\
    \ - 1]);\n        }\n    }\n\n    inline bool access(unsigned k) {\n        return\
    \ (bool((bit[k >> 6] >> (k & 63)) & 1));\n    }\n\n    inline int rank(int k)\
    \ {\n        return (sum[k >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL <<\
    \ (k & 63)) - 1)));\n    }\n\n    inline void sqrt_set(vector<T> &v) {\n     \
    \   t = SqrtTree<T, op>(v);\n    }\n\n    inline T rank_prod(int l, int r) {\n\
    \        return t.prod(l, r);\n    }\n};\n\ntemplate <class T, auto op, class\
    \ S>\nclass WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned bitsize,\
    \ logn;\n    vector<BitVector<T, op>> b;\n    vector<unsigned> zero;\n    vector<unsigned>\
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
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T,\
    \ op>(n + 1);\n            b[i].sqrt_set(v);\n            cur = 0;\n         \
    \   for (unsigned j = 0; j < n; j++) {\n                if (compressed[j] & (1U\
    \ << (bitsize - i - 1))) {\n                    b[i].set(j);\n               \
    \ } else {\n                    zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = v[j];\n                    cur++;\n          \
    \      }\n            }\n            b[i].build();\n            for (int j = 0;\
    \ j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i - 1)))\
    \ {\n                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = v[j];\n                    cur++;\n                }\n            }\n    \
    \        swap(tmpc, compressed);\n            swap(tmp, v);\n        }\n\n   \
    \     b[bitsize].sqrt_set(v);\n    }\n\n    WaveletMatrix(vector<T> v, vector<S>\
    \ w) {\n        MI = numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n\
    \        n = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n\
    \        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<S>\
    \ tmp(n);\n        vector<T> tmpc(n);\n        vector<T> compressed(n);\n    \
    \    for (unsigned i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int\
    \ cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i]\
    \ = BitVector<S>(n + 1);\n            b[i].sqrt_set(w);\n            cur = 0;\n\
    \            for (unsigned j = 0; j < n; j++) {\n                if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n                    b[i].set(j);\n         \
    \       } else {\n                    zero[i]++;\n                    tmpc[cur]\
    \ = compressed[j];\n                    tmp[cur] = w[j];\n                   \
    \ cur++;\n                }\n            }\n            b[i].build();\n      \
    \      for (int j = 0; j < n; j++) {\n                if (compressed[j] & (1U\
    \ << (bitsize - i - 1))) {\n                    tmpc[cur] = compressed[j];\n \
    \                   tmp[cur] = w[j];\n                    cur++;\n           \
    \     }\n            }\n            swap(tmpc, compressed);\n            swap(tmp,\
    \ w);\n        }\n        b[bitsize] = BitVector<S>(n + 1);\n        b[bitsize].sqrt_set(w);\n\
    \    }\n\n    WaveletMatrix(vector<T> x, vector<T> y, vector<T> w) {\n       \
    \ n = x.size();\n        px.resize(n);\n        vector<tuple<T, T, T>> v(n);\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] = {x[i], y[i], w[i]};\n\
    \        }\n        sort(v.begin(), v.end());\n        for (int i = 0; i < n;\
    \ i++) {\n            px[i] = std::get<0>(v[i]);\n            y[i] = std::get<1>(v[i]);\n\
    \            w[i] = std::get<2>(v[i]);\n        }\n\n        cmp.resize(y.size());\n\
    \        cmp = y;\n        sort(cmp.begin(), cmp.end());\n        cmp.erase(unique(cmp.begin(),\
    \ cmp.end()), cmp.end());\n        vector<T> tmpc(n);\n        vector<T> tmp(n);\n\
    \        vector<T> compressed(n);\n        for (unsigned i = 0; i < n; i++) {\n\
    \            compressed[i] = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(),\
    \ y[i]));\n        }\n        bitsize = bit_width(cmp.size());\n        b.resize(bitsize\
    \ + 1);\n        zero.resize(bitsize, 0);\n        vector<bool> bit(n, 0);\n \
    \       int cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n     \
    \       b[i] = BitVector<T, op>(bit);\n            b[i].sqrt_set(w);\n       \
    \     int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n         \
    \       if (compressed[j] & (1U << (bitsize - i - 1))) {\n                   \
    \ b[i].set(j);\n                } else {\n                    zero[i]++;\n   \
    \                 tmpc[cur] = compressed[j];\n                    tmp[cur] = w[j];\n\
    \                    cur++;\n                }\n            }\n            b[i].build();\n\
    \            for (unsigned j = 0; j < n; j++) {\n                if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = w[j];\n                    cur++;\n          \
    \      }\n            }\n\n            swap(tmpc, compressed);\n            swap(tmp,\
    \ w);\n        }\n        b[bitsize].sqrt_set(w);\n    }\n\n    // get v[k]\n\
    \    T access(unsigned k) {\n        unsigned res = 0;\n        unsigned cur =\
    \ k;\n        for (unsigned i = 0; i < bitsize; i++) {\n            if (b[i].access(cur))\
    \ {\n                res |= (1U << (bitsize - i - 1));\n                cur =\
    \ zero[i] + b[i].rank(cur);\n            } else {\n                cur -= b[i].rank(cur);\n\
    \            }\n        }\n        return cmp[res];\n    }\n\n    // v[l,r) \u306E\
    \u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\u3044\u5024\u3092\u8FD4\u3059\
    \n    T kth_smallest(unsigned l, unsigned r, unsigned k) {\n        unsigned res\
    \ = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            unsigned\
    \ num1 = b[i].rank(r) - b[i].rank(l);\n            unsigned num0 = r - l - num1;\n\
    \            if (num0 < k) {\n                res |= (1ULL << (bitsize - i - 1));\n\
    \                l = zero[i] + b[i].rank(l);\n                r = zero[i] + b[i].rank(r);\n\
    \                k -= num0;\n            } else {\n                l -= b[i].rank(l);\n\
    \                r -= b[i].rank(r);\n            }\n        }\n        return\
    \ cmp[res];\n    }\n\n    // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\
    \u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n    T kth_largest(unsigned l, unsigned\
    \ r, unsigned k) {\n        return kth_smallest(l, r, r - l - k + 1);\n    }\n\
    \n    // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\
    \u7A4D\u3092\u8FD4\u3059\n    T range_prod(int vl, int vr, T mink, T maxk) {\n\
    \        int D = compress(mink);\n        int U = compress(maxk);\n        T res\
    \ = e();\n        auto dfs = [&](auto &rec, int d, int L, int R, int A, int B)\
    \ -> void {\n            if (U <= A or B <= D) return;\n            if (D <= A\
    \ and B <= U) {\n                res = op(res, b[d].rank_prod(L, R));\n      \
    \          return;\n            }\n            if (d == bitsize) {\n         \
    \       if (D <= A and A < U) {\n                    res = op(res, b[bitsize].rank_prod(L,\
    \ R));\n                }\n                return;\n            }\n          \
    \  int C = (A + B) / 2;\n            int rank0_l = L - b[d].rank(L);\n       \
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
    \u7DCF\u7A4D\u3092\u8FD4\u3059\n    T rectangle_prod(T l, T r, T d, T u) {\n \
    \       unsigned cl = distance(px.begin(), lower_bound(px.begin(), px.end(), l));\n\
    \        unsigned cr = distance(px.begin(), lower_bound(px.begin(), px.end(),\
    \ r));\n        return range_prod(cl, cr, d, u);\n    }\n\n    template <typename\
    \ F>\n    T max_y(T xl, T xr, F check) {\n        unsigned L = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xl));\n        unsigned R = distance(px.begin(),\
    \ lower_bound(px.begin(), px.end(), xr));\n        int cnt = 0;\n        T prod\
    \ = e();\n        unsigned yidx = 0;\n        if (check(R - L, b[0].rank_prod(L,\
    \ R))) {\n            return cmp.back();\n        }\n        for (int i = 0; i\
    \ < bitsize; i++) {\n            int l0 = L - b[i].rank(L);\n            int r0\
    \ = R - b[i].rank(R);\n            int l1 = L + zero[i] - l0;\n            int\
    \ r1 = R + zero[i] - r0;\n            int cnt1 = cnt + r0 - l0;\n            T\
    \ tmp = op(prod, b[i + 1].rank_prod(l0, r0));\n            if (check(cnt1, tmp))\
    \ {\n                cnt = cnt1;\n                prod = tmp;\n              \
    \  L = l1;\n                R = r1;\n                yidx |= 1U << (bitsize -\
    \ i - 1);\n            } else {\n                L = l0;\n                R =\
    \ r0;\n            }\n        }\n        return cmp[yidx];\n    }\n};\n"
  dependsOn:
  - data-structure/others/SqrtTree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp
  requiredBy: []
  timestamp: '2024-11-15 00:33:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp
layout: document
title: Wavelet Matrix (Sqrt Tree)
---

## 概要

todo

## 計算量
todo