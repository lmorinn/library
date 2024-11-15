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
  bundledCode: "#line 1 \"data-structure/others/SqrtTree.hpp\"\ntemplate <class S,\
    \ auto op>\nclass SqrtTree {\n   private:\n    int n, lg, indexSz;\n    vector<S>\
    \ v;\n    vector<int> clz, layers, onLayer;\n    vector<vector<S>> prefix, suffix,\
    \ between;\n\n    void build(int layer, int lBound, int rBound, int betweenOffs)\
    \ {\n        if (layer >= (int)layers.size()) {\n            return;\n       \
    \ }\n        int bSz = 1 << ((layers[layer] + 1) >> 1);\n        for (int l =\
    \ lBound; l < rBound; l += bSz) {\n            int r = min(l + bSz, rBound);\n\
    \            prefix[layer][l] = v[l];\n            for (int i = l + 1; i < r;\
    \ i++) {\n                prefix[layer][i] = op(prefix[layer][i - 1], v[i]);\n\
    \            }\n            suffix[layer][r - 1] = v[r - 1];\n            for\
    \ (int i = r - 2; i >= l; i--) {\n                suffix[layer][i] = op(v[i],\
    \ suffix[layer][i + 1]);\n            }\n            build(layer + 1, l, r, betweenOffs);\n\
    \        }\n        if (layer == 0) {\n            int bSzLog = (lg + 1) >> 1;\n\
    \            for (int i = 0; i < indexSz; i++) {\n                v[n + i] = suffix[0][i\
    \ << bSzLog];\n            }\n            build(1, n, n + indexSz, (1 << lg) -\
    \ n);\n        } else {\n            int bSzLog = (layers[layer] + 1) >> 1;\n\
    \            int bCntLog = layers[layer] >> 1;\n            int bSz = 1 << bSzLog;\n\
    \            int bCnt = (rBound - lBound + bSz - 1) >> bSzLog;\n            for\
    \ (int i = 0; i < bCnt; i++) {\n                S ans;\n                for (int\
    \ j = i; j < bCnt; j++) {\n                    S add = suffix[layer][lBound +\
    \ (j << bSzLog)];\n                    ans = (i == j) ? add : op(ans, add);\n\
    \                    between[layer - 1][betweenOffs + lBound + (i << bCntLog)\
    \ + j] = ans;\n                }\n            }\n        }\n    }\n\n    inline\
    \ S query(int l, int r, int betweenOffs, int base) {\n        if (l == r) {\n\
    \            return v[l];\n        }\n        if (l + 1 == r) {\n            return\
    \ op(v[l], v[r]);\n        }\n        int layer = onLayer[clz[(l - base) ^ (r\
    \ - base)]];\n        int bSzLog = (layers[layer] + 1) >> 1;\n        int bCntLog\
    \ = layers[layer] >> 1;\n        int lBound = (((l - base) >> layers[layer]) <<\
    \ layers[layer]) + base;\n        int lBlock = ((l - lBound) >> bSzLog) + 1;\n\
    \        int rBlock = ((r - lBound) >> bSzLog) - 1;\n        S ans = suffix[layer][l];\n\
    \        if (lBlock <= rBlock) {\n            S add = (layer == 0) ? (\n     \
    \                                  query(n + lBlock, n + rBlock, (1 << lg) - n,\
    \ n))\n                                 : (\n                                \
    \       between[layer - 1][betweenOffs + lBound + (lBlock << bCntLog) + rBlock]);\n\
    \            ans = op(ans, add);\n        }\n        ans = op(ans, prefix[layer][r]);\n\
    \        return ans;\n    }\n\n   public:\n    inline S prod(int l, int r) {\n\
    \        return query(l, r - 1, 0, 0);\n    }\n    SqrtTree() {}\n\n    SqrtTree(const\
    \ vector<S> a)\n        : n((int)a.size()), v(a) {\n        lg = 0;\n        while\
    \ ((1 << lg) < n) lg++;\n        clz.assign(1 << lg, 0);\n        onLayer.assign(lg\
    \ + 1, 0);\n        clz[0] = 0;\n        for (int i = 1; i < (int)clz.size();\
    \ i++) {\n            clz[i] = clz[i >> 1] + 1;\n        }\n        int tlg =\
    \ lg;\n        while (tlg > 1) {\n            onLayer[tlg] = (int)layers.size();\n\
    \            layers.push_back(tlg);\n            tlg = (tlg + 1) >> 1;\n     \
    \   }\n        for (int i = lg - 1; i >= 0; i--) {\n            onLayer[i] = max(onLayer[i],\
    \ onLayer[i + 1]);\n        }\n        int betweenLayers = max(0, (int)layers.size()\
    \ - 1);\n        int bSzLog = (lg + 1) >> 1;\n        int bSz = 1 << bSzLog;\n\
    \        indexSz = (n + bSz - 1) >> bSzLog;\n        v.resize(n + indexSz);\n\
    \        prefix.assign(layers.size(), vector<S>(n + indexSz));\n        suffix.assign(layers.size(),\
    \ vector<S>(n + indexSz));\n        between.assign(betweenLayers, vector<S>((1\
    \ << lg) + bSz));\n        build(0, 0, n, 0);\n    }\n};\n#line 2 \"data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp\"\
    \n\ntemplate <class T, auto op, auto e>\nclass WaveletMatrix {\n   private:\n\
    \    unsigned n;\n    unsigned bitsize;\n    vector<BitVector<T, op, e>> b;\n\
    \    vector<unsigned> zero;\n    vector<T> cmp;\n    vector<T> px;\n    T MI,\
    \ MA;\n\n    inline unsigned compress(const T &x) {\n        return lower_bound(cmp.begin(),\
    \ cmp.end(), x) - begin(cmp);\n    }\n\n   public:\n    // \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n    WaveletMatrix() {}\n    WaveletMatrix(vector<T> v) {\n\
    \        MI = numeric_limits<T>::min();\n        MA = numeric_limits<T>::max();\n\
    \        n = v.size();\n        cmp = v;\n        sort(cmp.begin(), cmp.end());\n\
    \        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n        vector<T>\
    \ tmp(n);\n        vector<T> tmpc(n);\n        vector<T> compressed(n);\n    \
    \    for (unsigned i = 0; i < n; i++) {\n            compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n        }\n        bitsize = bit_width(cmp.size());\n\
    \        b.resize(bitsize + 1);\n        zero.resize(bitsize, 0);\n        int\
    \ cur = 0;\n        for (unsigned i = 0; i < bitsize; i++) {\n            b[i]\
    \ = BitVector<T, op, e>(n + 1);\n            b[i].sqrt_set(v);\n            cur\
    \ = 0;\n            for (unsigned j = 0; j < n; j++) {\n                if (compressed[j]\
    \ & (1U << (bitsize - i - 1))) {\n                    b[i].set(j);\n         \
    \       } else {\n                    zero[i]++;\n                    tmpc[cur]\
    \ = compressed[j];\n                    tmp[cur] = v[j];\n                   \
    \ cur++;\n                }\n            }\n            b[i].build();\n      \
    \      for (int j = 0; j < n; j++) {\n                if (compressed[j] & (1U\
    \ << (bitsize - i - 1))) {\n                    tmpc[cur] = compressed[j];\n \
    \                   tmp[cur] = v[j];\n                    cur++;\n           \
    \     }\n            }\n            swap(tmpc, compressed);\n            swap(tmp,\
    \ v);\n        }\n        b[bitsize] = BitVector<T, op, e>(n + 1);\n        b[bitsize].sqrt_set(v);\n\
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
    \       b[i] = BitVector<T, op, e>(bit);\n            b[i].sqrt_set(w);\n    \
    \        int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n      \
    \          if (compressed[j] & (1U << (bitsize - i - 1))) {\n                \
    \    b[i].set(j);\n                } else {\n                    zero[i]++;\n\
    \                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = w[j];\n                    cur++;\n                }\n            }\n    \
    \        b[i].build();\n            for (unsigned j = 0; j < n; j++) {\n     \
    \           if (compressed[j] & (1U << (bitsize - i - 1))) {\n               \
    \     tmpc[cur] = compressed[j];\n                    tmp[cur] = w[j];\n     \
    \               cur++;\n                }\n            }\n\n            swap(tmpc,\
    \ compressed);\n            swap(tmp, w);\n        }\n        b[bitsize] = BitVector<T,\
    \ op, e>(n + 1);\n        b[bitsize].sqrt_set(w);\n    }\n\n    // get v[k]\n\
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
  code: "#include \"../others/SqrtTree.hpp\"\n\ntemplate <class T, auto op, auto e>\n\
    class WaveletMatrix {\n   private:\n    unsigned n;\n    unsigned bitsize;\n \
    \   vector<BitVector<T, op, e>> b;\n    vector<unsigned> zero;\n    vector<T>\
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
    \ i = 0; i < bitsize; i++) {\n            b[i] = BitVector<T, op, e>(n + 1);\n\
    \            b[i].sqrt_set(v);\n            cur = 0;\n            for (unsigned\
    \ j = 0; j < n; j++) {\n                if (compressed[j] & (1U << (bitsize -\
    \ i - 1))) {\n                    b[i].set(j);\n                } else {\n   \
    \                 zero[i]++;\n                    tmpc[cur] = compressed[j];\n\
    \                    tmp[cur] = v[j];\n                    cur++;\n          \
    \      }\n            }\n            b[i].build();\n            for (int j = 0;\
    \ j < n; j++) {\n                if (compressed[j] & (1U << (bitsize - i - 1)))\
    \ {\n                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = v[j];\n                    cur++;\n                }\n            }\n    \
    \        swap(tmpc, compressed);\n            swap(tmp, v);\n        }\n     \
    \   b[bitsize] = BitVector<T, op, e>(n + 1);\n        b[bitsize].sqrt_set(v);\n\
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
    \       b[i] = BitVector<T, op, e>(bit);\n            b[i].sqrt_set(w);\n    \
    \        int cur = 0;\n            for (unsigned j = 0; j < n; j++) {\n      \
    \          if (compressed[j] & (1U << (bitsize - i - 1))) {\n                \
    \    b[i].set(j);\n                } else {\n                    zero[i]++;\n\
    \                    tmpc[cur] = compressed[j];\n                    tmp[cur]\
    \ = w[j];\n                    cur++;\n                }\n            }\n    \
    \        b[i].build();\n            for (unsigned j = 0; j < n; j++) {\n     \
    \           if (compressed[j] & (1U << (bitsize - i - 1))) {\n               \
    \     tmpc[cur] = compressed[j];\n                    tmp[cur] = w[j];\n     \
    \               cur++;\n                }\n            }\n\n            swap(tmpc,\
    \ compressed);\n            swap(tmp, w);\n        }\n        b[bitsize] = BitVector<T,\
    \ op, e>(n + 1);\n        b[bitsize].sqrt_set(w);\n    }\n\n    // get v[k]\n\
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
    \ r0;\n            }\n        }\n        return cmp[yidx];\n    }\n};"
  dependsOn:
  - data-structure/others/SqrtTree.hpp
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixSqrtTree.hpp
  requiredBy: []
  timestamp: '2024-11-15 13:36:04+09:00'
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