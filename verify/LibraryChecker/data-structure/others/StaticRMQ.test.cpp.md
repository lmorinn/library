---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/others/SparseTable.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 1 \"data-structure/others/SparseTable.hpp\"\ntemplate\
    \ <class T, auto f>\nclass SparseTable {\n private:\n  vector<vector<T>> st;\n\
    \  vector<int> lookup;\n\n public:\n  SparseTable() {}\n\n  SparseTable(const\
    \ vector<T> &v) {\n    const int n = (int)v.size();\n    const int b = 32 - __builtin_clz(n);\n\
    \    st.assign(b, vector<T>(n));\n    for (int i = 0; i < v.size(); i++) {\n \
    \     st[0][i] = v[i];\n    }\n    \n    for (int i = 1; i < b; i++) {\n     \
    \ for (int j = 0; j + (1 << i) <= n; j++) {\n        st[i][j] = f(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n    lookup.resize(v.size()\
    \ + 1);\n    for (int i = 2; i < lookup.size(); i++) {\n      lookup[i] = lookup[i\
    \ >> 1] + 1;\n    }\n  }\n\n  inline T query(int l, int r) const {\n    int b\
    \ = lookup[r - l];\n    return f(st[b][l], st[b][r - (1 << b)]);\n  }\n};\n#line\
    \ 5 \"verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp\"\nint main()\
    \ {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  cin >> n >> q;\n  auto\
    \ f = [=](const int &x, const int &y) { return min(x, y); };\n  vector<int> a(n);\n\
    \  for (int i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  SparseTable<int, f>\
    \ s(a);\n\n  for (int i = 0; i < q; i++) {\n    int l, r;\n    cin >> l >> r;\n\
    \    cout << s.query(l, r) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#include \"../../../../data-structure/others/SparseTable.hpp\"\
    \nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  cin >> n >>\
    \ q;\n  auto f = [=](const int &x, const int &y) { return min(x, y); };\n  vector<int>\
    \ a(n);\n  for (int i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  SparseTable<int,\
    \ f> s(a);\n\n  for (int i = 0; i < q; i++) {\n    int l, r;\n    cin >> l >>\
    \ r;\n    cout << s.query(l, r) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - data-structure/others/SparseTable.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 21:07:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
- /verify/verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp.html
title: verify/LibraryChecker/data-structure/others/StaticRMQ.test.cpp
---
