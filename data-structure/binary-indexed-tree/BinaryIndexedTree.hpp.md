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
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree/BinaryIndexedTree.hpp\"\
    \n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ data;\n\n    BinaryIndexedTree() = default;\n\n    BinaryIndexedTree(int size)\
    \ { init(size); }\n\n    void init(int size) {\n        N = size + 2;\n      \
    \  data.assign(N + 1, {});\n    }\n\n    T sum(int k) const {\n        if (k <\
    \ 0) return T{};\n        T ret{};\n        for (++k; k > 0; k -= k & -k) ret\
    \ += data[k];\n        return ret;\n    }\n    inline T sum(int l, int r) const\
    \ { return sum(r) - sum(l - 1); }\n\n    inline T operator[](int k) const { return\
    \ sum(k) - sum(k - 1); }\n\n    void add(int k, T x) {\n        for (++k; k <\
    \ N; k += k & -k) data[k] += x;\n    }\n};\n"
  code: "\ntemplate <typename T>\nstruct BinaryIndexedTree {\n    int N;\n    vector<T>\
    \ data;\n\n    BinaryIndexedTree() = default;\n\n    BinaryIndexedTree(int size)\
    \ { init(size); }\n\n    void init(int size) {\n        N = size + 2;\n      \
    \  data.assign(N + 1, {});\n    }\n\n    T sum(int k) const {\n        if (k <\
    \ 0) return T{};\n        T ret{};\n        for (++k; k > 0; k -= k & -k) ret\
    \ += data[k];\n        return ret;\n    }\n    inline T sum(int l, int r) const\
    \ { return sum(r) - sum(l - 1); }\n\n    inline T operator[](int k) const { return\
    \ sum(k) - sum(k - 1); }\n\n    void add(int k, T x) {\n        for (++k; k <\
    \ N; k += k & -k) data[k] += x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2024-11-04 22:20:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
- /library/data-structure/binary-indexed-tree/BinaryIndexedTree.hpp.html
title: data-structure/binary-indexed-tree/BinaryIndexedTree.hpp
---
