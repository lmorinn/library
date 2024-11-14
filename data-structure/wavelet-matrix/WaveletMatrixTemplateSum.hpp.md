---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AtCoder/data-structure/wavelet-matrix/SmallerSum.test.cpp
    title: verify/AtCoder/data-structure/wavelet-matrix/SmallerSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet-matrix/WaveletMatrixTemplateSum.hpp\"\
    \n\ntemplate <class T>\nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n\
    \  vector<unsigned long long> bit;\n  vector<unsigned> sum;\n  vector<T> srsum;\n\
    \n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 63) >> 6;\n    bit.assign(blocksize, 0ULL);\n    sum.assign(blocksize,\
    \ 0U);\n    srsum.assign(sz, 0);\n  }\n\n  inline void set(int k) { bit[k >> 6]\
    \ |= 1ULL << (k & 63ULL); }\n\n  inline void build() {\n    sum[0] = 0ULL;\n \
    \   for (int i = 1; i < blocksize; i++) {\n      sum[i] = sum[i - 1] + __builtin_popcountll(bit[i\
    \ - 1]);\n    }\n  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k\
    \ >> 6] >> (k & 63)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k\
    \ >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL << (k & 63)) - 1)));\n  }\n\
    \n  inline void srsum_set(vector<T> &v) {\n    for (int i = 0; i < sz - 1; i++)\
    \ {\n      srsum[i + 1] = srsum[i] + v[i];\n    }\n  }\n\n  inline T rank_srsum(int\
    \ l, int r) {\n    return srsum[r] - srsum[l];\n  }\n\n  inline T rank_srsum(int\
    \ r) {\n    return srsum[r];\n  }\n};\n\ntemplate <class T, class S>\nclass WaveletMatrix\
    \ {\n private:\n  unsigned n;\n  unsigned bitsize;\n  vector<BitVector<S>> b;\n\
    \  vector<unsigned> zero;\n  vector<T> cmp;\n  T MI, MA;\n\n  inline unsigned\
    \ compress(const T &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) -\
    \ begin(cmp);\n  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n  WaveletMatrix() {}\n  WaveletMatrix(vector<T> v) {\n    MI = numeric_limits<T>::min();\n\
    \    MA = numeric_limits<T>::max();\n    n = v.size();\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ vector<T> tmp(n);\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n  \
    \  for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize + 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector<T>(n + 1);\n\
    \      b[i].srsum_set(v);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          tmp[cur] = v[j];\n          cur++;\n        }\n      }\n      b[i].build();\n\
    \      for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = v[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ v);\n    }\n    b[bitsize] = BitVector<T>(n + 1);\n    b[bitsize].srsum_set(v);\n\
    \  }\n\n  WaveletMatrix(vector<T> v, vector<S> w) {\n    MI = numeric_limits<T>::min();\n\
    \    MA = numeric_limits<T>::max();\n    n = v.size();\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ vector<S> tmp(n);\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n  \
    \  for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize + 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector<S>(n + 1);\n\
    \      b[i].srsum_set(w);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          tmp[cur] = w[j];\n          cur++;\n        }\n      }\n      b[i].build();\n\
    \      for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = w[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ w);\n    }\n    b[bitsize] = BitVector<S>(n + 1);\n    b[bitsize].srsum_set(w);\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\
    \u3044\u5024\u3092\u8FD4\u3059\n  T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n    unsigned res = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n\
    \      unsigned num1 = b[i].rank(r) - b[i].rank(l);\n      unsigned num0 = r -\
    \ l - num1;\n      if (num0 < k) {\n        res |= (1ULL << (bitsize - i - 1));\n\
    \        l = zero[i] + b[i].rank(l);\n        r = zero[i] + b[i].rank(r);\n  \
    \      k -= num0;\n      } else {\n        l -= b[i].rank(l);\n        r -= b[i].rank(r);\n\
    \      }\n    }\n    return cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\
    \u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n  T kth_largest(unsigned\
    \ l, unsigned r, unsigned k) {\n    return kth_smallest(l, r, r - l - k + 1);\n\
    \  }\n\n  // v[l,r]\u3092\u6607\u9806\u30BD\u30FC\u30C8\u3057\u305F\u6642\u306E\
    \u5148\u982Dk\u500B\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  S kth_ascending_sum(unsigned\
    \ l, unsigned r, unsigned k) {\n    S res = 0;\n    unsigned val = 0;\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      const unsigned rank1_l = b[i].rank(l);\n\
    \      const unsigned rank1_r = b[i].rank(r);\n      const unsigned rank0_l =\
    \ l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n      const unsigned\
    \ num1 = rank1_r - rank1_l;\n      const unsigned num0 = rank0_r - rank0_l;\n\
    \      if (num0 < k) {\n        val |= (1ULL << (bitsize - i - 1));\n        res\
    \ += b[i + 1].rank_srsum(rank0_r) - b[i + 1].rank_srsum(rank0_l);\n        l =\
    \ zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n   \
    \   } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n   \
    \ res += int64_t(cmp[val]) * (k);\n    return res;\n  }\n\n  // v[l,r]\u3092\u964D\
    \u9806\u30BD\u30FC\u30C8\u3057\u305F\u6642\u306E\u5148\u982Dk\u500B\u306E\u7DCF\
    \u548C\u3092\u8FD4\u3059\n  S kth_descending_sum(unsigned l, unsigned r, unsigned\
    \ k) {\n    return range_sum(l, r, MI, MA) - kth_ascending_sum(l, r, r - l - k);\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n  unsigned range_freq(int vl, int vr, T mink,\
    \ T maxk) {\n    int D = compress(mink);\n    int U = compress(maxk);\n    unsigned\
    \ res = 0;\n    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) ->\
    \ void {\n      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n\
    \        res += (R - L);\n        return;\n      }\n      if (d == bitsize) {\n\
    \        if (D <= A and A < U) {\n          res += (R - L);\n        }\n     \
    \   return;\n      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n\
    \  S range_sum(int vl, int vr, T mink, T maxk) {\n    int D = compress(mink);\n\
    \    int U = compress(maxk);\n    S res = 0;\n    auto dfs = [&](auto &rec, int\
    \ d, int L, int R, int A, int B) -> void {\n      if (U <= A or B <= D) return;\n\
    \      if (D <= A and B <= U) {\n        res = res + b[d].rank_srsum(L, R);\n\
    \        return;\n      }\n      if (d == bitsize) {\n        if (D <= A and A\
    \ < U) {\n          res = res + b[d].rank_srsum(L, R);\n        }\n        return;\n\
    \      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067 \u2211|v[i]-d| \u3092\u8A08\u7B97\u3057\u3066\u8FD4\u3059\n  S range_abs(unsigned\
    \ l, unsigned r, T d) {\n    int dnum = range_freq(l, r, d, d + 1);\n    S dsum\
    \ = d * dnum;\n    S asum = range_sum(l, r, MI, MA);\n    int less = range_freq(l,\
    \ r, MI, d);\n    S less_sum = range_sum(l, r, MI, d);\n    int more = r - l -\
    \ dnum - less;\n    S more_sum = asum - dsum - less_sum;\n    return d * less\
    \ + more_sum - less_sum - (d * more);\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u3092\
    \u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n  T prev_value(unsigned\
    \ l, unsigned r, T val) {\n    int num = range_freq(l, r, MI, val);\n    if (num\
    \ == 0) {\n      return MA;\n    } else {\n      return kth_smallest(l, r, num);\n\
    \    }\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    \u5024\u3092\u8FD4\u3059\n  T next_value(unsigned l, unsigned r, T val) {\n  \
    \  int num = range_freq(l, r, MI, val);\n    if (num == r - l) {\n      return\
    \ MI;\n    } else {\n      return kth_smallest(l, r, num + 1);\n    }\n  }\n};\n"
  code: "\ntemplate <class T>\nstruct BitVector {\n  unsigned sz;\n  unsigned blocksize;\n\
    \  vector<unsigned long long> bit;\n  vector<unsigned> sum;\n  vector<T> srsum;\n\
    \n  BitVector() {}\n\n  BitVector(unsigned siz) {\n    sz = siz;\n    blocksize\
    \ = (sz + 63) >> 6;\n    bit.assign(blocksize, 0ULL);\n    sum.assign(blocksize,\
    \ 0U);\n    srsum.assign(sz, 0);\n  }\n\n  inline void set(int k) { bit[k >> 6]\
    \ |= 1ULL << (k & 63ULL); }\n\n  inline void build() {\n    sum[0] = 0ULL;\n \
    \   for (int i = 1; i < blocksize; i++) {\n      sum[i] = sum[i - 1] + __builtin_popcountll(bit[i\
    \ - 1]);\n    }\n  }\n\n  inline bool access(unsigned k) {\n    return (bool((bit[k\
    \ >> 6] >> (k & 63)) & 1));\n  }\n\n  inline int rank(int k) {\n    return (sum[k\
    \ >> 6] + __builtin_popcountll(bit[k >> 6] & ((1ULL << (k & 63)) - 1)));\n  }\n\
    \n  inline void srsum_set(vector<T> &v) {\n    for (int i = 0; i < sz - 1; i++)\
    \ {\n      srsum[i + 1] = srsum[i] + v[i];\n    }\n  }\n\n  inline T rank_srsum(int\
    \ l, int r) {\n    return srsum[r] - srsum[l];\n  }\n\n  inline T rank_srsum(int\
    \ r) {\n    return srsum[r];\n  }\n};\n\ntemplate <class T, class S>\nclass WaveletMatrix\
    \ {\n private:\n  unsigned n;\n  unsigned bitsize;\n  vector<BitVector<S>> b;\n\
    \  vector<unsigned> zero;\n  vector<T> cmp;\n  T MI, MA;\n\n  inline unsigned\
    \ compress(const T &x) {\n    return lower_bound(cmp.begin(), cmp.end(), x) -\
    \ begin(cmp);\n  }\n\n public:\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n  WaveletMatrix() {}\n  WaveletMatrix(vector<T> v) {\n    MI = numeric_limits<T>::min();\n\
    \    MA = numeric_limits<T>::max();\n    n = v.size();\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ vector<T> tmp(n);\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n  \
    \  for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize + 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector<T>(n + 1);\n\
    \      b[i].srsum_set(v);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          tmp[cur] = v[j];\n          cur++;\n        }\n      }\n      b[i].build();\n\
    \      for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = v[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ v);\n    }\n    b[bitsize] = BitVector<T>(n + 1);\n    b[bitsize].srsum_set(v);\n\
    \  }\n\n  WaveletMatrix(vector<T> v, vector<S> w) {\n    MI = numeric_limits<T>::min();\n\
    \    MA = numeric_limits<T>::max();\n    n = v.size();\n    cmp = v;\n    sort(cmp.begin(),\
    \ cmp.end());\n    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());\n   \
    \ vector<S> tmp(n);\n    vector<T> tmpc(n);\n    vector<T> compressed(n);\n  \
    \  for (unsigned i = 0; i < n; i++) {\n      compressed[i] = distance(cmp.begin(),\
    \ lower_bound(cmp.begin(), cmp.end(), v[i]));\n    }\n    bitsize = bit_width(cmp.size());\n\
    \    b.resize(bitsize + 1);\n    zero.resize(bitsize, 0);\n    int cur = 0;\n\
    \    for (unsigned i = 0; i < bitsize; i++) {\n      b[i] = BitVector<S>(n + 1);\n\
    \      b[i].srsum_set(w);\n      cur = 0;\n      for (unsigned j = 0; j < n; j++)\
    \ {\n        if (compressed[j] & (1U << (bitsize - i - 1))) {\n          b[i].set(j);\n\
    \        } else {\n          zero[i]++;\n          tmpc[cur] = compressed[j];\n\
    \          tmp[cur] = w[j];\n          cur++;\n        }\n      }\n      b[i].build();\n\
    \      for (int j = 0; j < n; j++) {\n        if (compressed[j] & (1U << (bitsize\
    \ - i - 1))) {\n          tmpc[cur] = compressed[j];\n          tmp[cur] = w[j];\n\
    \          cur++;\n        }\n      }\n      swap(tmpc, compressed);\n      swap(tmp,\
    \ w);\n    }\n    b[bitsize] = BitVector<S>(n + 1);\n    b[bitsize].srsum_set(w);\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\u76EE(1-origin)\u306B\u5C0F\u3055\
    \u3044\u5024\u3092\u8FD4\u3059\n  T kth_smallest(unsigned l, unsigned r, unsigned\
    \ k) {\n    unsigned res = 0;\n    for (unsigned i = 0; i < bitsize; i++) {\n\
    \      unsigned num1 = b[i].rank(r) - b[i].rank(l);\n      unsigned num0 = r -\
    \ l - num1;\n      if (num0 < k) {\n        res |= (1ULL << (bitsize - i - 1));\n\
    \        l = zero[i] + b[i].rank(l);\n        r = zero[i] + b[i].rank(r);\n  \
    \      k -= num0;\n      } else {\n        l -= b[i].rank(l);\n        r -= b[i].rank(r);\n\
    \      }\n    }\n    return cmp[res];\n  }\n\n  // v[l,r) \u306E\u4E2D\u3067k\u756A\
    \u76EE(1-origin)\u306B\u5927\u304D\u3044\u5024\u3092\u8FD4\u3059\n  T kth_largest(unsigned\
    \ l, unsigned r, unsigned k) {\n    return kth_smallest(l, r, r - l - k + 1);\n\
    \  }\n\n  // v[l,r]\u3092\u6607\u9806\u30BD\u30FC\u30C8\u3057\u305F\u6642\u306E\
    \u5148\u982Dk\u500B\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n  S kth_ascending_sum(unsigned\
    \ l, unsigned r, unsigned k) {\n    S res = 0;\n    unsigned val = 0;\n    for\
    \ (unsigned i = 0; i < bitsize; i++) {\n      const unsigned rank1_l = b[i].rank(l);\n\
    \      const unsigned rank1_r = b[i].rank(r);\n      const unsigned rank0_l =\
    \ l - rank1_l;\n      const unsigned rank0_r = r - rank1_r;\n      const unsigned\
    \ num1 = rank1_r - rank1_l;\n      const unsigned num0 = rank0_r - rank0_l;\n\
    \      if (num0 < k) {\n        val |= (1ULL << (bitsize - i - 1));\n        res\
    \ += b[i + 1].rank_srsum(rank0_r) - b[i + 1].rank_srsum(rank0_l);\n        l =\
    \ zero[i] + rank1_l;\n        r = zero[i] + rank1_r;\n        k -= num0;\n   \
    \   } else {\n        l = rank0_l;\n        r = rank0_r;\n      }\n    }\n   \
    \ res += int64_t(cmp[val]) * (k);\n    return res;\n  }\n\n  // v[l,r]\u3092\u964D\
    \u9806\u30BD\u30FC\u30C8\u3057\u305F\u6642\u306E\u5148\u982Dk\u500B\u306E\u7DCF\
    \u548C\u3092\u8FD4\u3059\n  S kth_descending_sum(unsigned l, unsigned r, unsigned\
    \ k) {\n    return range_sum(l, r, MI, MA) - kth_ascending_sum(l, r, r - l - k);\n\
    \  }\n\n  // v[l,r) \u306E\u4E2D\u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\
    \u500B\u6570\u3092\u8FD4\u3059\n  unsigned range_freq(int vl, int vr, T mink,\
    \ T maxk) {\n    int D = compress(mink);\n    int U = compress(maxk);\n    unsigned\
    \ res = 0;\n    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) ->\
    \ void {\n      if (U <= A or B <= D) return;\n      if (D <= A and B <= U) {\n\
    \        res += (R - L);\n        return;\n      }\n      if (d == bitsize) {\n\
    \        if (D <= A and A < U) {\n          res += (R - L);\n        }\n     \
    \   return;\n      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067[mink,maxk)\u306B\u5165\u308B\u5024\u306E\u7DCF\u548C\u3092\u8FD4\u3059\n\
    \  S range_sum(int vl, int vr, T mink, T maxk) {\n    int D = compress(mink);\n\
    \    int U = compress(maxk);\n    S res = 0;\n    auto dfs = [&](auto &rec, int\
    \ d, int L, int R, int A, int B) -> void {\n      if (U <= A or B <= D) return;\n\
    \      if (D <= A and B <= U) {\n        res = res + b[d].rank_srsum(L, R);\n\
    \        return;\n      }\n      if (d == bitsize) {\n        if (D <= A and A\
    \ < U) {\n          res = res + b[d].rank_srsum(L, R);\n        }\n        return;\n\
    \      }\n      int C = (A + B) / 2;\n      int rank0_l = L - b[d].rank(L);\n\
    \      int rank0_r = R - b[d].rank(R);\n      int rank1_l = b[d].rank(L) + zero[d];\n\
    \      int rank1_r = b[d].rank(R) + zero[d];\n      rec(rec, d + 1, rank0_l, rank0_r,\
    \ A, C);\n      rec(rec, d + 1, rank1_l, rank1_r, C, B);\n    };\n    dfs(dfs,\
    \ 0, vl, vr, 0, 1 << bitsize);\n    return res;\n  }\n\n  // v[l,r) \u306E\u4E2D\
    \u3067 \u2211|v[i]-d| \u3092\u8A08\u7B97\u3057\u3066\u8FD4\u3059\n  S range_abs(unsigned\
    \ l, unsigned r, T d) {\n    int dnum = range_freq(l, r, d, d + 1);\n    S dsum\
    \ = d * dnum;\n    S asum = range_sum(l, r, MI, MA);\n    int less = range_freq(l,\
    \ r, MI, d);\n    S less_sum = range_sum(l, r, MI, d);\n    int more = r - l -\
    \ dnum - less;\n    S more_sum = asum - dsum - less_sum;\n    return d * less\
    \ + more_sum - less_sum - (d * more);\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u3092\
    \u8D85\u3048\u306A\u3044\u6700\u5927\u306E\u5024\u3092\u8FD4\u3059\n  T prev_value(unsigned\
    \ l, unsigned r, T val) {\n    int num = range_freq(l, r, MI, val);\n    if (num\
    \ == 0) {\n      return MA;\n    } else {\n      return kth_smallest(l, r, num);\n\
    \    }\n  }\n\n  // v[l,r)\u306E\u4E2D\u3067val\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    \u5024\u3092\u8FD4\u3059\n  T next_value(unsigned l, unsigned r, T val) {\n  \
    \  int num = range_freq(l, r, MI, val);\n    if (num == r - l) {\n      return\
    \ MI;\n    } else {\n      return kth_smallest(l, r, num + 1);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/wavelet-matrix/WaveletMatrixTemplateSum.hpp
  requiredBy: []
  timestamp: '2024-11-14 18:13:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AtCoder/data-structure/wavelet-matrix/SmallerSum.test.cpp
documentation_of: data-structure/wavelet-matrix/WaveletMatrixTemplateSum.hpp
layout: document
title: Wavelet Matrix (Template Sum)
---

## 概要

todo

## 計算量
todo