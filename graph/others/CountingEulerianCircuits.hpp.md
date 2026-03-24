---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/CountingSpanningTrees.hpp
    title: Counting Spanning Trees
  - icon: ':heavy_check_mark:'
    path: linear-algebra/Matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LibraryChecker/graph/others/CountingEulerianCircuits.test.cpp
    title: verify/LibraryChecker/graph/others/CountingEulerianCircuits.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linear-algebra/Matrix.hpp\"\ntemplate <class S>\nstruct\
    \ Matrix {\n private:\n public:\n  vector<vector<S>> A;\n  Matrix() {}\n  Matrix(int\
    \ n, int m) : A(n, vector<S>(m)) {}\n  Matrix(int n) : A(n, vector<S>(n)) {}\n\
    \n  inline int size() const { return A.size(); }\n  inline int height() const\
    \ { return A.size(); }\n  inline int width() const { return A[0].size(); }\n \
    \ inline const vector<S>& operator[](int h) const { return (A[h]); }\n  inline\
    \ vector<S>& operator[](int h) { return (A[h]); }\n\n  Matrix& operator+=(const\
    \ Matrix& B) {\n    int h = height();\n    int w = width();\n    for (int i =\
    \ 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n        (*this)[i][j]\
    \ += B[i][j];\n      }\n    }\n    return (*this);\n  }\n  Matrix& operator-=(const\
    \ Matrix& B) {\n    int h = height();\n    int w = width();\n    for (int i =\
    \ 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n        (*this)[i][j]\
    \ -= B[i][j];\n      }\n    }\n    return (*this);\n  }\n\n  Matrix& operator*=(const\
    \ Matrix& B) {\n    int h = height();\n    int w = B.width();\n    int c = width();\n\
    \    vector<vector<S>> C(h, vector<S>(w));\n    for (int i = 0; i < h; i++) {\n\
    \      for (int j = 0; j < w; j++) {\n        for (int k = 0; k < c; k++) {\n\
    \          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);\n        }\n      }\n\
    \    }\n    A = move(C);\n    return (*this);\n  }\n  Matrix operator+(const Matrix&\
    \ B) const { return (Matrix(*this) += B); }\n  Matrix operator-(const Matrix&\
    \ B) const { return (Matrix(*this) -= B); }\n  Matrix operator*(const Matrix&\
    \ B) const { return (Matrix(*this) *= B); }\n\n  int rank() {\n    Matrix B(*this);\n\
    \    if (B.height() == 0 or B.width() == 0) return 0;\n    int res = 0;\n    int\
    \ h = height();\n    int w = width();\n    int ch = 0;\n    int cw = 0;\n    while\
    \ (ch < h and cw < w) {\n      bool ok = false;\n      for (int j = cw; j < w;\
    \ j++) {\n        for (int i = ch; i < h; i++) {\n          if (B[i][j] != 0)\
    \ {\n            ok = true;\n            swap(B[ch], B[i]);\n            S d =\
    \ B[ch][j];\n            for (int j2 = j; j2 < w; j2++) {\n              B[ch][j2]\
    \ /= d;\n            }\n            for (int i2 = 0; i2 < h; i2++) {\n       \
    \       if (B[i2][j] != 0 and i2 != ch) {\n                S m = B[i2][j];\n \
    \               for (int j2 = j; j2 < w; j2++) {\n                  B[i2][j2]\
    \ -= B[ch][j2] * m;\n                }\n              }\n            }\n     \
    \       res++;\n            ch++;\n            cw = j + 1;\n            break;\n\
    \          }\n        }\n        if (ok) break;\n      }\n      if (!ok) break;\n\
    \    }\n    return res;\n  }\n\n  S determinant() {\n    Matrix B(*this);\n  \
    \  if (B.height() == 0 or B.width() == 0) return 0;\n    assert(B.height() ==\
    \ B.width());\n    int h = height();\n    int w = width();\n    int ch = 0;\n\
    \    int cw = 0;\n    S div = 1;\n    bool neg = false;\n    while (ch < h and\
    \ cw < w) {\n      bool ok = false;\n      for (int j = cw; j < w; j++) {\n  \
    \      for (int i = ch; i < h; i++) {\n          if (B[i][j] != 0) {\n       \
    \     ok = true;\n            if (ch != i) neg = !neg;\n            swap(B[ch],\
    \ B[i]);\n            S d = B[ch][j];\n            div /= d;\n            for\
    \ (int j2 = j; j2 < w; j2++) {\n              B[ch][j2] /= d;\n            }\n\
    \            for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) {\n                S m = B[i2][j];\n                for (int j2\
    \ = j; j2 < w; j2++) {\n                  B[i2][j2] -= B[ch][j2] * m;\n      \
    \          }\n              }\n            }\n            ch++;\n            cw\
    \ = j + 1;\n            break;\n          }\n        }\n        if (ok) {\n  \
    \        break;\n        } else {\n          return S(0);\n        }\n      }\n\
    \      if (!ok) break;\n    }\n    S res = (neg ? -B[0][0] : B[0][0]) / div;\n\
    \    for (int i = 1; i < h; i++) {\n      res = res * B[i][i];\n    }\n    return\
    \ res;\n  }\n\n  pair<bool, Matrix<S>> inverse() {\n    int h = height();\n  \
    \  int w = width();\n    assert(h == w);\n    Matrix<S> B(h, w * 2);\n    for\
    \ (int i = 0; i < h; i++) {\n      for (int j = 0; j < w; j++) {\n        B[i][j]\
    \ = (*this)[i][j];\n      }\n    }\n    for (int i = 0; i < h; i++) {\n      B[i][i\
    \ + w] = 1;\n    }\n    w *= 2;\n    int rnk = 0;\n\n    int ch = 0;\n    int\
    \ cw = 0;\n    while (ch < h and cw < h) {\n      bool ok = false;\n      for\
    \ (int j = cw; j < h; j++) {\n        for (int i = ch; i < h; i++) {\n       \
    \   if (B[i][j] != 0) {\n            ok = true;\n            swap(B[ch], B[i]);\n\
    \            S d = B[ch][j];\n            for (int j2 = j; j2 < w; j2++) {\n \
    \             B[ch][j2] /= d;\n            }\n            for (int i2 = 0; i2\
    \ < h; i2++) {\n              if (B[i2][j] != 0 and i2 != ch) {\n            \
    \    S m = B[i2][j];\n                for (int j2 = j; j2 < w; j2++) {\n     \
    \             B[i2][j2] -= B[ch][j2] * m;\n                }\n              }\n\
    \            }\n            rnk++;\n            ch++;\n            cw = j + 1;\n\
    \            break;\n          }\n        }\n        if (ok) break;\n      }\n\
    \      if (!ok) break;\n    }\n    Matrix<S> res(h);\n    if (rnk == h) {\n  \
    \    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < h; j++) {\n  \
    \        res[i][j] = B[i][j + h];\n        }\n      }\n      return {true, res};\n\
    \    } else {\n      return {false, res};\n    }\n  }\n\n  Matrix<S> linear_equation(vector<S>\
    \ b) {\n    Matrix A(*this);\n\n    int rnk = 0;\n    assert(A.height() == b.size());\n\
    \    int h = height();\n    int w = width();\n    int ch = 0;\n    int cw = 0;\n\
    \    vector<int> pivot_row(w, -1);\n    while (ch < h and cw < w) {\n      bool\
    \ ok = false;\n      for (int j = cw; j < w; j++) {\n        for (int i = ch;\
    \ i < h; i++) {\n          if (A[i][j] != 0) {\n            ok = true;\n     \
    \       swap(A[ch], A[i]);\n            swap(b[ch], b[i]);\n            S d =\
    \ A[ch][j];\n            for (int j2 = j; j2 < w; j2++) {\n              A[ch][j2]\
    \ /= d;\n            }\n            b[ch] /= d;\n            for (int i2 = 0;\
    \ i2 < h; i2++) {\n              S m = A[i2][j];\n              if (A[i2][j] !=\
    \ 0 and i2 != ch) {\n                for (int j2 = j; j2 < w; j2++) {\n      \
    \            A[i2][j2] -= A[ch][j2] * m;\n                }\n              }\n\
    \              if (i2 != ch) b[i2] -= b[ch] * m;\n            }\n            pivot_row[j]\
    \ = ch;\n            rnk++;\n            ch++;\n            cw = j + 1;\n    \
    \        break;\n          }\n        }\n        if (ok) break;\n      }\n   \
    \   if (!ok) break;\n    }\n\n    for (int i = rnk; i < h; i++) {\n      if (b[i]\
    \ != 0) return Matrix<S>(0);\n    }\n    Matrix<S> sol(w - rnk + 1, w);\n    int\
    \ idx = 1;\n    for (int j = 0; j < w; j++) {\n      if (pivot_row[j] != -1) {\n\
    \        sol[0][j] = b[pivot_row[j]];\n      } else {\n        sol[idx][j] = 1;\n\
    \        for (int i = 0; i < w; i++) {\n          if (pivot_row[i] != -1) {\n\
    \            sol[idx][i] = -A[pivot_row[i]][j];\n          }\n        }\n    \
    \    idx++;\n      }\n    }\n    return sol;\n  }\n};\n#line 2 \"graph/tree/CountingSpanningTrees.hpp\"\
    \n\ntemplate <class S>\nstruct CountingSpanningTrees {\n private:\n  Matrix<S>\
    \ laplacian;\n  int n, root;\n  bool is_undirected = true;\n\n  void internal_add_edge(int\
    \ from, int to, S w = 1) {\n    if (from != root and to != root) {\n      if (root\
    \ < from) from--;\n      if (root < to) to--;\n      laplacian[from][to] -= w;\n\
    \      laplacian[from][from] += w;\n    } else if (from != root) {\n      if (root\
    \ < from) from--;\n      laplacian[from][from] += w;\n    }\n  }\n\n public:\n\
    \  CountingSpanningTrees() {}\n  CountingSpanningTrees(int n, bool undirected\
    \ = true, int root = 0) : n(n), is_undirected(undirected), root(root), laplacian(n\
    \ - 1, n - 1) {}\n\n  // \u3059\u3079\u3066\u306E\u8FBA\u304C\u6839\u306E\u65B9\
    \u3092\u5411\u304F: u->v\n  // \u6839\u304B\u3089\u3059\u3079\u3066\u306E\u9802\
    \u70B9\u306B\u5230\u9054: v->u\n  void add_edge(int u, int v, S w = 1) {\n   \
    \ assert(0 <= u and u < n and 0 <= v and v < n);\n    internal_add_edge(u, v,\
    \ w);\n    if (is_undirected) internal_add_edge(v, u, w);\n  }\n\n  S count_spanning_trees()\
    \ {\n    if (n != 1) {\n      return laplacian.determinant();\n    } else {\n\
    \      return 1;\n    }\n  }\n};\n#line 2 \"graph/others/CountingEulerianCircuits.hpp\"\
    \n\ntemplate <class S>\nstruct CountingEulerianCircuits {\n private:\n  int n;\n\
    \  vector<vector<long long>> g;\n  vector<S> fac;\n  int out_mx = 1;\n\n public:\n\
    \  CountingEulerianCircuits(int n) : n(n), g(n, vector<long long>(n)), fac(1)\
    \ { fac[0] = 1; }\n  void add_edge(int u, int v, int w = 1) {\n    g[u][v] +=\
    \ w;\n  }\n\n  S count_eulerian_circuits() {\n    vector<long long> ods(n);\n\
    \    vector<int> ids;\n    for (int i = 0; i < n; i++) {\n      long long diff\
    \ = 0;\n      long long outdeg = 0;\n      for (int j = 0; j < n; j++) {\n   \
    \     diff += g[i][j] - g[j][i];\n        outdeg += g[i][j];\n      }\n      if\
    \ (diff != 0) return 0;\n      if (out_mx < outdeg) out_mx = outdeg;\n      ods[i]\
    \ = outdeg;\n    }\n\n    if (fac.size() < out_mx) {\n      int siz = fac.size();\n\
    \      fac.resize(out_mx);\n      for (int i = siz; i < out_mx; i++) {\n     \
    \   fac[i] = fac[i - 1] * i;\n      }\n    }\n    S res = 1;\n    for (int i =\
    \ 0; i < n; i++) {\n      if (ods[i]) {\n        ids.emplace_back(i);\n      \
    \  res *= fac[ods[i] - 1];\n      }\n    }\n\n    int siz = ids.size();\n    CountingSpanningTrees<S>\
    \ t(siz, false, 0);\n    for (int i = 0; i < siz; i++) {\n      for (int j = 0;\
    \ j < siz; j++) {\n        t.add_edge(i, j, g[ids[i]][ids[j]]);\n      }\n   \
    \ }\n    res *= t.count_spanning_trees();\n    return res;\n  }\n};\n"
  code: "#include \"../tree/CountingSpanningTrees.hpp\"\n\ntemplate <class S>\nstruct\
    \ CountingEulerianCircuits {\n private:\n  int n;\n  vector<vector<long long>>\
    \ g;\n  vector<S> fac;\n  int out_mx = 1;\n\n public:\n  CountingEulerianCircuits(int\
    \ n) : n(n), g(n, vector<long long>(n)), fac(1) { fac[0] = 1; }\n  void add_edge(int\
    \ u, int v, int w = 1) {\n    g[u][v] += w;\n  }\n\n  S count_eulerian_circuits()\
    \ {\n    vector<long long> ods(n);\n    vector<int> ids;\n    for (int i = 0;\
    \ i < n; i++) {\n      long long diff = 0;\n      long long outdeg = 0;\n    \
    \  for (int j = 0; j < n; j++) {\n        diff += g[i][j] - g[j][i];\n       \
    \ outdeg += g[i][j];\n      }\n      if (diff != 0) return 0;\n      if (out_mx\
    \ < outdeg) out_mx = outdeg;\n      ods[i] = outdeg;\n    }\n\n    if (fac.size()\
    \ < out_mx) {\n      int siz = fac.size();\n      fac.resize(out_mx);\n      for\
    \ (int i = siz; i < out_mx; i++) {\n        fac[i] = fac[i - 1] * i;\n      }\n\
    \    }\n    S res = 1;\n    for (int i = 0; i < n; i++) {\n      if (ods[i]) {\n\
    \        ids.emplace_back(i);\n        res *= fac[ods[i] - 1];\n      }\n    }\n\
    \n    int siz = ids.size();\n    CountingSpanningTrees<S> t(siz, false, 0);\n\
    \    for (int i = 0; i < siz; i++) {\n      for (int j = 0; j < siz; j++) {\n\
    \        t.add_edge(i, j, g[ids[i]][ids[j]]);\n      }\n    }\n    res *= t.count_spanning_trees();\n\
    \    return res;\n  }\n};"
  dependsOn:
  - graph/tree/CountingSpanningTrees.hpp
  - linear-algebra/Matrix.hpp
  isVerificationFile: false
  path: graph/others/CountingEulerianCircuits.hpp
  requiredBy: []
  timestamp: '2026-03-25 02:15:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LibraryChecker/graph/others/CountingEulerianCircuits.test.cpp
documentation_of: graph/others/CountingEulerianCircuits.hpp
layout: document
title: Counting Eulerian Circuits
---

## 概要

todo

## 計算量
todo