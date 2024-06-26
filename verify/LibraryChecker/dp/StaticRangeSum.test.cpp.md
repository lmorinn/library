---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/CumulativeSum.hpp
    title: Cumulative Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/LibraryChecker/dp/StaticRangeSum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"dp/CumulativeSum.hpp\"\ntemplate <class T>\nclass\
    \ CumulativeSum {\n private:\n  int siz;\n  vector<T> s;\n\n public:\n  CumulativeSum()\
    \ {}\n  CumulativeSum(vector<T> &a) {\n    siz = a.size();\n    s.resize(siz +\
    \ 1, 0);\n    for (int i = 0; i < siz; i++) {\n      s[i + 1] = s[i] + a[i];\n\
    \    }\n  }\n\n  T sum(int r) {\n    return s[r];\n  }\n\n  T sum(int l, int r)\
    \ {\n    return s[r] - s[l];\n  }\n};\n#line 5 \"verify/LibraryChecker/dp/StaticRangeSum.test.cpp\"\
    \nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<long long> a(n);\n  for (int i = 0; i < n; i++) {\n    cin >> a[i];\n\
    \  }\n  CumulativeSum s(a);\n  for (int i = 0; i < q; i++) {\n    int l, r;\n\
    \    cin >> l >> r;\n    cout << s.sum(l, r) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#include \"../../../dp/CumulativeSum.hpp\"\
    \nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<long long> a(n);\n  for (int i = 0; i < n; i++) {\n    cin >> a[i];\n\
    \  }\n  CumulativeSum s(a);\n  for (int i = 0; i < q; i++) {\n    int l, r;\n\
    \    cin >> l >> r;\n    cout << s.sum(l, r) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - dp/CumulativeSum.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/dp/StaticRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 20:58:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/dp/StaticRangeSum.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/dp/StaticRangeSum.test.cpp
- /verify/verify/LibraryChecker/dp/StaticRangeSum.test.cpp.html
title: verify/LibraryChecker/dp/StaticRangeSum.test.cpp
---
