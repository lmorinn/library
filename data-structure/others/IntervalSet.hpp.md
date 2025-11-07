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
  bundledCode: "#line 1 \"data-structure/others/IntervalSet.hpp\"\n// [l, r]\ntemplate\
    \ <class T>\nclass IntervalSet {\n   private:\n    set<pair<T, T>> s;\n\n   public:\n\
    \    IntervalSet() {\n        T mi = numeric_limits<T>::min();\n        T mx =\
    \ numeric_limits<T>::max();\n        s.emplace(mi, mi);\n        s.emplace(mx,\
    \ mx);\n    }\n\n    bool contains(T x) {\n        auto itr = s.lower_bound({x\
    \ + 1, x + 1});\n        itr--;\n        return ((*itr).first <= x and x <= (*itr).second);\n\
    \    }\n\n    int insert(T x) {\n        // assert(!(*this).contains(x));\n  \
    \      auto nex = s.lower_bound({x, x});\n        auto prev = nex;\n        prev--;\n\
    \        if ((*prev).second + 1 == x and x == (*nex).first - 1) {\n          \
    \  int nl = (*prev).first;\n            int nr = (*nex).second;\n            s.erase(prev);\n\
    \            s.erase(nex);\n            s.emplace(nl, nr);\n            return\
    \ -1;\n        } else if ((*prev).second + 1 == x) {\n            int nl = (*prev).first;\n\
    \            int nr = (*prev).second + 1;\n            s.erase(prev);\n      \
    \      s.emplace(nl, nr);\n            return 0;\n        } else if (x == (*nex).first\
    \ - 1) {\n            int nl = (*nex).first - 1;\n            int nr = (*nex).second;\n\
    \            s.erase(nex);\n            s.emplace(nl, nr);\n            return\
    \ 0;\n        } else {\n            s.emplace(x, x);\n            return 1;\n\
    \        }\n    }\n\n    int erase(T x) {\n        auto itr = s.lower_bound({x\
    \ + 1, x + 1});\n        itr--;\n        int l = (*itr).first;\n        int r\
    \ = (*itr).second;\n        if (!(l <= x and x <= r)) return 0;\n\n        s.erase(itr);\n\
    \        if (l == r) {\n            return -1;\n        } else if (l == x) {\n\
    \            s.emplace(l + 1, r);\n            return 0;\n        } else if (r\
    \ == x) {\n            s.emplace(l, r - 1);\n            return 0;\n        }\
    \ else {\n            s.emplace(l, x - 1);\n            s.emplace(x + 1, r);\n\
    \            return 1;\n        }\n    }\n\n    T mex(T x) {\n        auto itr\
    \ = s.lower_bound({x + 1, x + 1});\n        itr--;\n        if ((*itr).first <=\
    \ x and x <= (*itr).second) {\n            return (*itr).second + 1;\n       \
    \ } else {\n            return x;\n        }\n    }\n\n    void print() {\n  \
    \      for (auto p : s) {\n            cout << \"[\" << p.first << \", \" << p.second\
    \ << \"] \";\n        }\n        cout << \"\\n\";\n    }\n};\n"
  code: "// [l, r]\ntemplate <class T>\nclass IntervalSet {\n   private:\n    set<pair<T,\
    \ T>> s;\n\n   public:\n    IntervalSet() {\n        T mi = numeric_limits<T>::min();\n\
    \        T mx = numeric_limits<T>::max();\n        s.emplace(mi, mi);\n      \
    \  s.emplace(mx, mx);\n    }\n\n    bool contains(T x) {\n        auto itr = s.lower_bound({x\
    \ + 1, x + 1});\n        itr--;\n        return ((*itr).first <= x and x <= (*itr).second);\n\
    \    }\n\n    int insert(T x) {\n        // assert(!(*this).contains(x));\n  \
    \      auto nex = s.lower_bound({x, x});\n        auto prev = nex;\n        prev--;\n\
    \        if ((*prev).second + 1 == x and x == (*nex).first - 1) {\n          \
    \  int nl = (*prev).first;\n            int nr = (*nex).second;\n            s.erase(prev);\n\
    \            s.erase(nex);\n            s.emplace(nl, nr);\n            return\
    \ -1;\n        } else if ((*prev).second + 1 == x) {\n            int nl = (*prev).first;\n\
    \            int nr = (*prev).second + 1;\n            s.erase(prev);\n      \
    \      s.emplace(nl, nr);\n            return 0;\n        } else if (x == (*nex).first\
    \ - 1) {\n            int nl = (*nex).first - 1;\n            int nr = (*nex).second;\n\
    \            s.erase(nex);\n            s.emplace(nl, nr);\n            return\
    \ 0;\n        } else {\n            s.emplace(x, x);\n            return 1;\n\
    \        }\n    }\n\n    int erase(T x) {\n        auto itr = s.lower_bound({x\
    \ + 1, x + 1});\n        itr--;\n        int l = (*itr).first;\n        int r\
    \ = (*itr).second;\n        if (!(l <= x and x <= r)) return 0;\n\n        s.erase(itr);\n\
    \        if (l == r) {\n            return -1;\n        } else if (l == x) {\n\
    \            s.emplace(l + 1, r);\n            return 0;\n        } else if (r\
    \ == x) {\n            s.emplace(l, r - 1);\n            return 0;\n        }\
    \ else {\n            s.emplace(l, x - 1);\n            s.emplace(x + 1, r);\n\
    \            return 1;\n        }\n    }\n\n    T mex(T x) {\n        auto itr\
    \ = s.lower_bound({x + 1, x + 1});\n        itr--;\n        if ((*itr).first <=\
    \ x and x <= (*itr).second) {\n            return (*itr).second + 1;\n       \
    \ } else {\n            return x;\n        }\n    }\n\n    void print() {\n  \
    \      for (auto p : s) {\n            cout << \"[\" << p.first << \", \" << p.second\
    \ << \"] \";\n        }\n        cout << \"\\n\";\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/others/IntervalSet.hpp
  requiredBy: []
  timestamp: '2025-11-07 13:51:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/others/IntervalSet.hpp
layout: document
title: Interval Set
---

## 概要

区間をSetで管理するテク
工事中

## 計算量
todo