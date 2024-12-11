---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
    title: verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp\"\
    \ntemplate <class T>\nclass SegtreeBeats {\n   private:\n    T MA, MI;\n    int\
    \ n;\n    int n0;\n    vector<T> max_1_val, max_2_val, min_1_val, min_2_val, sum,\
    \ add;\n    vector<int> max_1_cnt, min_1_cnt, len;\n\n    void query_chmin(int\
    \ a, int b, int k, int l, int r, T x) {\n        if (b <= l or r <= a or max_1_val[k]\
    \ <= x) {\n            return;\n        }\n\n        if (a <= l and r <= b and\
    \ max_2_val[k] < x) {\n            update_node_max(k, x);\n            return;\n\
    \        }\n\n        push(k);\n\n        query_chmin(a, b, (k << 1) | 1, l, (l\
    \ + r) >> 1, x);\n        query_chmin(a, b, (k + 1) << 1, (l + r) >> 1, r, x);\n\
    \n        update(k);\n    }\n\n    void query_chmax(int a, int b, int k, int l,\
    \ int r, T x) {\n        if (b <= l or r <= a or x <= min_1_val[k]) {\n      \
    \      return;\n        }\n\n        if (a <= l and r <= b and x < min_2_val[k])\
    \ {\n            update_node_min(k, x);\n            return;\n        }\n\n  \
    \      push(k);\n\n        query_chmax(a, b, (k << 1) | 1, l, (l + r) >> 1, x);\n\
    \        query_chmax(a, b, (k + 1) << 1, (l + r) >> 1, r, x);\n\n        update(k);\n\
    \    }\n\n    T query_max(int a, int b, int k, int l, int r) {\n        if (b\
    \ <= l or r <= a) {\n            return MI;\n        }\n\n        if (a <= l and\
    \ r <= b) {\n            return max_1_val[k];\n        }\n\n        push(k);\n\
    \        T l_max = query_max(a, b, (k << 1) | 1, l, (l + r) >> 1);\n        T\
    \ r_max = query_max(a, b, (k + 1) << 1, (l + r) >> 1, r);\n        return max(l_max,\
    \ r_max);\n    }\n\n    T query_min(int a, int b, int k, int l, int r) {\n   \
    \     if (b <= l or r <= a) {\n            return MA;\n        }\n\n        if\
    \ (a <= l and r <= b) {\n            return min_1_val[k];\n        }\n\n     \
    \   push(k);\n        T l_max = query_min(a, b, (k << 1) | 1, l, (l + r) >> 1);\n\
    \        T r_max = query_min(a, b, (k + 1) << 1, (l + r) >> 1, r);\n        return\
    \ min(l_max, r_max);\n    }\n\n    T query_sum(int a, int b, int k, int l, int\
    \ r) {\n        if (b <= l or r <= a) {\n            return 0;\n        }\n\n\
    \        if (a <= l and r <= b) {\n            return sum[k];\n        }\n\n \
    \       push(k);\n        T l_sum = query_sum(a, b, (k << 1) | 1, l, (l + r) >>\
    \ 1);\n        T r_sum = query_sum(a, b, (k + 1) << 1, (l + r) >> 1, r);\n   \
    \     return l_sum + r_sum;\n    }\n\n    void query_add(int a, int b, int k,\
    \ int l, int r, T x) {\n        if (b <= l or r <= a) {\n            return;\n\
    \        }\n\n        if (a <= l and r <= b) {\n            add_node(k, x);\n\
    \            return;\n        }\n\n        push(k);\n        query_add(a, b, (k\
    \ << 1) | 1, l, (l + r) >> 1, x);\n        query_add(a, b, (k + 1) << 1, (l +\
    \ r) >> 1, r, x);\n        update(k);\n    }\n\n    void update_node_max(int k,\
    \ T x) {\n        sum[k] += (x - max_1_val[k]) * max_1_cnt[k];\n        if (max_1_val[k]\
    \ == min_1_val[k]) {\n            max_1_val[k] = x;\n            min_1_val[k]\
    \ = x;\n        } else if (max_1_val[k] == min_2_val[k]) {\n            max_1_val[k]\
    \ = x;\n            min_2_val[k] = x;\n        } else {\n            max_1_val[k]\
    \ = x;\n        }\n    }\n\n    void update_node_min(int k, T x) {\n        sum[k]\
    \ += (x - min_1_val[k]) * min_1_cnt[k];\n\n        if (max_1_val[k] == min_1_val[k])\
    \ {\n            max_1_val[k] = x;\n            min_1_val[k] = x;\n        } else\
    \ if (max_2_val[k] == min_1_val[k]) {\n            max_2_val[k] = x;\n       \
    \     min_1_val[k] = x;\n        } else {\n            min_1_val[k] = x;\n   \
    \     }\n    }\n\n    void add_node(int k, T x) {\n        max_1_val[k] += x;\n\
    \        if (max_2_val[k] != MI) {\n            max_2_val[k] += x;\n        }\n\
    \        min_1_val[k] += x;\n        if (min_2_val[k] != MA) {\n            min_2_val[k]\
    \ += x;\n        }\n\n        sum[k] += len[k] * x;\n        add[k] += x;\n  \
    \  }\n\n    void push(int k) {\n        if (add[k] != 0) {\n            add_node((k\
    \ << 1) | 1, add[k]);\n            add_node((k + 1) << 1, add[k]);\n         \
    \   add[k] = 0;\n        }\n\n        if (max_1_val[k] < max_1_val[(k << 1) |\
    \ 1]) {\n            update_node_max((k << 1) | 1, max_1_val[k]);\n        }\n\
    \n        if (max_1_val[k] < max_1_val[(k + 1) << 1]) {\n            update_node_max((k\
    \ + 1) << 1, max_1_val[k]);\n        }\n\n        if (min_1_val[k] > min_1_val[(k\
    \ << 1) | 1]) {\n            update_node_min((k << 1) | 1, min_1_val[k]);\n  \
    \      }\n\n        if (min_1_val[k] > min_1_val[(k + 1) << 1]) {\n          \
    \  update_node_min((k + 1) << 1, min_1_val[k]);\n        }\n    }\n\n    void\
    \ update(int k) {\n        sum[k] = sum[(k << 1) | 1] + sum[(k + 1) << 1];\n\n\
    \        if (max_1_val[(k << 1) | 1] < max_1_val[(k + 1) << 1]) {\n          \
    \  max_1_val[k] = max_1_val[(k + 1) << 1];\n            max_1_cnt[k] = max_1_cnt[(k\
    \ + 1) << 1];\n            max_2_val[k] = max(max_1_val[(k << 1) | 1], max_2_val[(k\
    \ + 1) << 1]);\n        } else if (max_1_val[(k << 1) | 1] > max_1_val[(k + 1)\
    \ << 1]) {\n            max_1_val[k] = max_1_val[(k << 1) | 1];\n            max_1_cnt[k]\
    \ = max_1_cnt[(k << 1) | 1];\n            max_2_val[k] = max(max_2_val[(k << 1)\
    \ | 1], max_1_val[(k + 1) << 1]);\n        } else {\n            max_1_val[k]\
    \ = max_1_val[(k << 1) | 1];\n            max_1_cnt[k] = max_1_cnt[(k << 1) |\
    \ 1] + max_1_cnt[(k + 1) << 1];\n            max_2_val[k] = max(max_2_val[(k <<\
    \ 1) | 1], max_2_val[(k + 1) << 1]);\n        }\n\n        if (min_1_val[(k <<\
    \ 1) | 1] < min_1_val[(k + 1) << 1]) {\n            min_1_val[k] = min_1_val[(k\
    \ << 1) | 1];\n            min_1_cnt[k] = min_1_cnt[(k << 1) | 1];\n         \
    \   min_2_val[k] = min(min_2_val[(k << 1) | 1], min_1_val[(k + 1) << 1]);\n  \
    \      } else if (min_1_val[(k << 1) | 1] > min_1_val[(k + 1) << 1]) {\n     \
    \       min_1_val[k] = min_1_val[(k + 1) << 1];\n            min_1_cnt[k] = min_1_cnt[(k\
    \ + 1) << 1];\n            min_2_val[k] = min(min_1_val[(k << 1) | 1], min_2_val[(k\
    \ + 1) << 1]);\n        } else {\n            min_1_val[k] = min_1_val[(k << 1)\
    \ | 1];\n            min_1_cnt[k] = min_1_cnt[(k << 1) | 1] + min_1_cnt[(k + 1)\
    \ << 1];\n            min_2_val[k] = min(min_2_val[(k << 1) | 1], min_2_val[(k\
    \ + 1) << 1]);\n        }\n    }\n\n   public:\n    SegtreeBeats(const vector<T>\
    \ &v) {\n        MA = numeric_limits<T>::max();\n        MI = numeric_limits<T>::min();\n\
    \        n = v.size();\n        n0 = 1;\n        while (n0 < n) {\n          \
    \  n0 <<= 1;\n        }\n        sum.assign((n0 << 1), 0);\n        add.assign((n0\
    \ << 1), 0);\n        len.assign((n0 << 1), 0);\n        max_1_val.assign((n0\
    \ << 1), MI);\n        max_2_val.assign((n0 << 1), MI);\n        min_1_val.assign((n0\
    \ << 1), MA);\n        min_2_val.assign((n0 << 1), MA);\n        max_1_cnt.assign((n0\
    \ << 1), 0);\n        min_1_cnt.assign((n0 << 1), 0);\n\n        for (int i =\
    \ 0; i < (n0 << 1); i++) {\n            add[i] = 0;\n        }\n        len[0]\
    \ = n0;\n        for (int i = 0; i < n0 - 1; i++) {\n            len[(i << 1)\
    \ | 1] = (len[i] >> 1);\n            len[(i + 1) << 1] = (len[i] >> 1);\n    \
    \    }\n\n        for (int i = 0; i < n; i++) {\n            max_1_val[n0 - 1\
    \ + i] = v[i];\n            min_1_val[n0 - 1 + i] = v[i];\n            sum[n0\
    \ - 1 + i] = v[i];\n            max_1_cnt[n0 - 1 + i] = 1;\n            min_1_cnt[n0\
    \ - 1 + i] = 1;\n        }\n\n        for (int i = n0 - 2; i >= 0; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void range_chmin(int l, int r,\
    \ T x) {\n        query_chmin(l, r, 0, 0, n0, x);\n    }\n\n    void range_chmax(int\
    \ l, int r, T x) {\n        query_chmax(l, r, 0, 0, n0, x);\n    }\n\n    void\
    \ range_add(int l, int r, T x) {\n        query_add(l, r, 0, 0, n0, x);\n    }\n\
    \n    void range_update(int l, int r, T x) {\n        query_chmax(l, r, MA);\n\
    \        query_chmin(l, r, x);\n    }\n\n    T range_max(int l, int r) {\n   \
    \     return query_max(l, r, 0, 0, n0);\n    }\n\n    T range_min(int l, int r)\
    \ {\n        return query_min(l, r, 0, 0, n0);\n    }\n\n    T range_sum(int l,\
    \ int r) {\n        return query_sum(l, r, 0, 0, n0);\n    }\n\n    T get(int\
    \ p) {\n        return range_sum(p, p + 1);\n    }\n\n    T set(int p, T x) {\n\
    \        range_update(p, p + 1, x);\n    }\n\n    void print() {\n        for\
    \ (int i = 0; i < n; i++) {\n            cout << get(i) << (i == n - 1) ? '\\\
    n' : \" \";\n        }\n    }\n};\n"
  code: "template <class T>\nclass SegtreeBeats {\n   private:\n    T MA, MI;\n  \
    \  int n;\n    int n0;\n    vector<T> max_1_val, max_2_val, min_1_val, min_2_val,\
    \ sum, add;\n    vector<int> max_1_cnt, min_1_cnt, len;\n\n    void query_chmin(int\
    \ a, int b, int k, int l, int r, T x) {\n        if (b <= l or r <= a or max_1_val[k]\
    \ <= x) {\n            return;\n        }\n\n        if (a <= l and r <= b and\
    \ max_2_val[k] < x) {\n            update_node_max(k, x);\n            return;\n\
    \        }\n\n        push(k);\n\n        query_chmin(a, b, (k << 1) | 1, l, (l\
    \ + r) >> 1, x);\n        query_chmin(a, b, (k + 1) << 1, (l + r) >> 1, r, x);\n\
    \n        update(k);\n    }\n\n    void query_chmax(int a, int b, int k, int l,\
    \ int r, T x) {\n        if (b <= l or r <= a or x <= min_1_val[k]) {\n      \
    \      return;\n        }\n\n        if (a <= l and r <= b and x < min_2_val[k])\
    \ {\n            update_node_min(k, x);\n            return;\n        }\n\n  \
    \      push(k);\n\n        query_chmax(a, b, (k << 1) | 1, l, (l + r) >> 1, x);\n\
    \        query_chmax(a, b, (k + 1) << 1, (l + r) >> 1, r, x);\n\n        update(k);\n\
    \    }\n\n    T query_max(int a, int b, int k, int l, int r) {\n        if (b\
    \ <= l or r <= a) {\n            return MI;\n        }\n\n        if (a <= l and\
    \ r <= b) {\n            return max_1_val[k];\n        }\n\n        push(k);\n\
    \        T l_max = query_max(a, b, (k << 1) | 1, l, (l + r) >> 1);\n        T\
    \ r_max = query_max(a, b, (k + 1) << 1, (l + r) >> 1, r);\n        return max(l_max,\
    \ r_max);\n    }\n\n    T query_min(int a, int b, int k, int l, int r) {\n   \
    \     if (b <= l or r <= a) {\n            return MA;\n        }\n\n        if\
    \ (a <= l and r <= b) {\n            return min_1_val[k];\n        }\n\n     \
    \   push(k);\n        T l_max = query_min(a, b, (k << 1) | 1, l, (l + r) >> 1);\n\
    \        T r_max = query_min(a, b, (k + 1) << 1, (l + r) >> 1, r);\n        return\
    \ min(l_max, r_max);\n    }\n\n    T query_sum(int a, int b, int k, int l, int\
    \ r) {\n        if (b <= l or r <= a) {\n            return 0;\n        }\n\n\
    \        if (a <= l and r <= b) {\n            return sum[k];\n        }\n\n \
    \       push(k);\n        T l_sum = query_sum(a, b, (k << 1) | 1, l, (l + r) >>\
    \ 1);\n        T r_sum = query_sum(a, b, (k + 1) << 1, (l + r) >> 1, r);\n   \
    \     return l_sum + r_sum;\n    }\n\n    void query_add(int a, int b, int k,\
    \ int l, int r, T x) {\n        if (b <= l or r <= a) {\n            return;\n\
    \        }\n\n        if (a <= l and r <= b) {\n            add_node(k, x);\n\
    \            return;\n        }\n\n        push(k);\n        query_add(a, b, (k\
    \ << 1) | 1, l, (l + r) >> 1, x);\n        query_add(a, b, (k + 1) << 1, (l +\
    \ r) >> 1, r, x);\n        update(k);\n    }\n\n    void update_node_max(int k,\
    \ T x) {\n        sum[k] += (x - max_1_val[k]) * max_1_cnt[k];\n        if (max_1_val[k]\
    \ == min_1_val[k]) {\n            max_1_val[k] = x;\n            min_1_val[k]\
    \ = x;\n        } else if (max_1_val[k] == min_2_val[k]) {\n            max_1_val[k]\
    \ = x;\n            min_2_val[k] = x;\n        } else {\n            max_1_val[k]\
    \ = x;\n        }\n    }\n\n    void update_node_min(int k, T x) {\n        sum[k]\
    \ += (x - min_1_val[k]) * min_1_cnt[k];\n\n        if (max_1_val[k] == min_1_val[k])\
    \ {\n            max_1_val[k] = x;\n            min_1_val[k] = x;\n        } else\
    \ if (max_2_val[k] == min_1_val[k]) {\n            max_2_val[k] = x;\n       \
    \     min_1_val[k] = x;\n        } else {\n            min_1_val[k] = x;\n   \
    \     }\n    }\n\n    void add_node(int k, T x) {\n        max_1_val[k] += x;\n\
    \        if (max_2_val[k] != MI) {\n            max_2_val[k] += x;\n        }\n\
    \        min_1_val[k] += x;\n        if (min_2_val[k] != MA) {\n            min_2_val[k]\
    \ += x;\n        }\n\n        sum[k] += len[k] * x;\n        add[k] += x;\n  \
    \  }\n\n    void push(int k) {\n        if (add[k] != 0) {\n            add_node((k\
    \ << 1) | 1, add[k]);\n            add_node((k + 1) << 1, add[k]);\n         \
    \   add[k] = 0;\n        }\n\n        if (max_1_val[k] < max_1_val[(k << 1) |\
    \ 1]) {\n            update_node_max((k << 1) | 1, max_1_val[k]);\n        }\n\
    \n        if (max_1_val[k] < max_1_val[(k + 1) << 1]) {\n            update_node_max((k\
    \ + 1) << 1, max_1_val[k]);\n        }\n\n        if (min_1_val[k] > min_1_val[(k\
    \ << 1) | 1]) {\n            update_node_min((k << 1) | 1, min_1_val[k]);\n  \
    \      }\n\n        if (min_1_val[k] > min_1_val[(k + 1) << 1]) {\n          \
    \  update_node_min((k + 1) << 1, min_1_val[k]);\n        }\n    }\n\n    void\
    \ update(int k) {\n        sum[k] = sum[(k << 1) | 1] + sum[(k + 1) << 1];\n\n\
    \        if (max_1_val[(k << 1) | 1] < max_1_val[(k + 1) << 1]) {\n          \
    \  max_1_val[k] = max_1_val[(k + 1) << 1];\n            max_1_cnt[k] = max_1_cnt[(k\
    \ + 1) << 1];\n            max_2_val[k] = max(max_1_val[(k << 1) | 1], max_2_val[(k\
    \ + 1) << 1]);\n        } else if (max_1_val[(k << 1) | 1] > max_1_val[(k + 1)\
    \ << 1]) {\n            max_1_val[k] = max_1_val[(k << 1) | 1];\n            max_1_cnt[k]\
    \ = max_1_cnt[(k << 1) | 1];\n            max_2_val[k] = max(max_2_val[(k << 1)\
    \ | 1], max_1_val[(k + 1) << 1]);\n        } else {\n            max_1_val[k]\
    \ = max_1_val[(k << 1) | 1];\n            max_1_cnt[k] = max_1_cnt[(k << 1) |\
    \ 1] + max_1_cnt[(k + 1) << 1];\n            max_2_val[k] = max(max_2_val[(k <<\
    \ 1) | 1], max_2_val[(k + 1) << 1]);\n        }\n\n        if (min_1_val[(k <<\
    \ 1) | 1] < min_1_val[(k + 1) << 1]) {\n            min_1_val[k] = min_1_val[(k\
    \ << 1) | 1];\n            min_1_cnt[k] = min_1_cnt[(k << 1) | 1];\n         \
    \   min_2_val[k] = min(min_2_val[(k << 1) | 1], min_1_val[(k + 1) << 1]);\n  \
    \      } else if (min_1_val[(k << 1) | 1] > min_1_val[(k + 1) << 1]) {\n     \
    \       min_1_val[k] = min_1_val[(k + 1) << 1];\n            min_1_cnt[k] = min_1_cnt[(k\
    \ + 1) << 1];\n            min_2_val[k] = min(min_1_val[(k << 1) | 1], min_2_val[(k\
    \ + 1) << 1]);\n        } else {\n            min_1_val[k] = min_1_val[(k << 1)\
    \ | 1];\n            min_1_cnt[k] = min_1_cnt[(k << 1) | 1] + min_1_cnt[(k + 1)\
    \ << 1];\n            min_2_val[k] = min(min_2_val[(k << 1) | 1], min_2_val[(k\
    \ + 1) << 1]);\n        }\n    }\n\n   public:\n    SegtreeBeats(const vector<T>\
    \ &v) {\n        MA = numeric_limits<T>::max();\n        MI = numeric_limits<T>::min();\n\
    \        n = v.size();\n        n0 = 1;\n        while (n0 < n) {\n          \
    \  n0 <<= 1;\n        }\n        sum.assign((n0 << 1), 0);\n        add.assign((n0\
    \ << 1), 0);\n        len.assign((n0 << 1), 0);\n        max_1_val.assign((n0\
    \ << 1), MI);\n        max_2_val.assign((n0 << 1), MI);\n        min_1_val.assign((n0\
    \ << 1), MA);\n        min_2_val.assign((n0 << 1), MA);\n        max_1_cnt.assign((n0\
    \ << 1), 0);\n        min_1_cnt.assign((n0 << 1), 0);\n\n        for (int i =\
    \ 0; i < (n0 << 1); i++) {\n            add[i] = 0;\n        }\n        len[0]\
    \ = n0;\n        for (int i = 0; i < n0 - 1; i++) {\n            len[(i << 1)\
    \ | 1] = (len[i] >> 1);\n            len[(i + 1) << 1] = (len[i] >> 1);\n    \
    \    }\n\n        for (int i = 0; i < n; i++) {\n            max_1_val[n0 - 1\
    \ + i] = v[i];\n            min_1_val[n0 - 1 + i] = v[i];\n            sum[n0\
    \ - 1 + i] = v[i];\n            max_1_cnt[n0 - 1 + i] = 1;\n            min_1_cnt[n0\
    \ - 1 + i] = 1;\n        }\n\n        for (int i = n0 - 2; i >= 0; i--) {\n  \
    \          update(i);\n        }\n    }\n\n    void range_chmin(int l, int r,\
    \ T x) {\n        query_chmin(l, r, 0, 0, n0, x);\n    }\n\n    void range_chmax(int\
    \ l, int r, T x) {\n        query_chmax(l, r, 0, 0, n0, x);\n    }\n\n    void\
    \ range_add(int l, int r, T x) {\n        query_add(l, r, 0, 0, n0, x);\n    }\n\
    \n    void range_update(int l, int r, T x) {\n        query_chmax(l, r, MA);\n\
    \        query_chmin(l, r, x);\n    }\n\n    T range_max(int l, int r) {\n   \
    \     return query_max(l, r, 0, 0, n0);\n    }\n\n    T range_min(int l, int r)\
    \ {\n        return query_min(l, r, 0, 0, n0);\n    }\n\n    T range_sum(int l,\
    \ int r) {\n        return query_sum(l, r, 0, 0, n0);\n    }\n\n    T get(int\
    \ p) {\n        return range_sum(p, p + 1);\n    }\n\n    T set(int p, T x) {\n\
    \        range_update(p, p + 1, x);\n    }\n\n    void print() {\n        for\
    \ (int i = 0; i < n; i++) {\n            cout << get(i) << (i == n - 1) ? '\\\
    n' : \" \";\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp
  requiredBy: []
  timestamp: '2024-12-12 00:16:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/data-structure/segment-tree/RangeChminChmaxAddRangeSum.test.cpp
documentation_of: data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp
layout: document
title: Segment Tree Beats
---

## 概要

todo

## 計算量
todo