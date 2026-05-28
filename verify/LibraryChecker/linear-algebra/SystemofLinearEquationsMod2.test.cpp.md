---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linear-algebra/BitMatrix.hpp
    title: Matrix (Mod 2)
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\n#include <tr2/dynamic_bitset>\n\nusing namespace std;\nusing\
    \ namespace tr2;\nusing lint = long long;\nusing ull = unsigned long long;\nusing\
    \ ld = long double;\nusing int128 = __int128_t;\n#define all(x) (x).begin(), (x).end()\n\
    #define uniqv(v) v.erase(unique(all(v)), v.end())\n#define OVERLOAD_REP(_1, _2,\
    \ _3, name, ...) name\n#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{};\
    \ (i) != (n); ++(i))\n#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))\n\
    #define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)\n#define logfixed(x)\
    \ cout << fixed << setprecision(10) << x << endl;\n\nostream &operator<<(ostream\
    \ &dest, __int128_t value) {\n  ostream::sentry s(dest);\n  if (s) {\n    __uint128_t\
    \ tmp = value < 0 ? -value : value;\n    char buffer[128];\n    char *d = end(buffer);\n\
    \    do {\n      --d;\n      *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n\
    \    } while (tmp != 0);\n    if (value < 0) {\n      --d;\n      *d = '-';\n\
    \    }\n    int len = end(buffer) - d;\n    if (dest.rdbuf()->sputn(d, len) !=\
    \ len) {\n      dest.setstate(ios_base::badbit);\n    }\n  }\n  return dest;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const vector<T> &v)\
    \ {\n  for (int i = 0; i < (int)v.size(); i++) {\n    os << v[i] << (i + 1 !=\
    \ (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, const set<T> &set_var) {\n  for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr !=\
    \ set_var.end()) os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &set_var) {\n  for\
    \ (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os << *itr;\n\
    \    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n  }\n  return\
    \ os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const map<T, U> &map_var) {\n  for (auto itr = map_var.begin(); itr != map_var.end();\
    \ itr++) {\n    os << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n\
    \  return os;\n}\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const unordered_map<T, U> &map_var) {\n  for (auto itr = map_var.begin();\
    \ itr != map_var.end(); itr++) {\n    os << itr->first << \" -> \" << itr->second\
    \ << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename T, typename U>\nostream\
    \ &operator<<(ostream &os, const pair<T, U> &pair_var) {\n  os << pair_var.first\
    \ << \" \" << pair_var.second;\n  return os;\n}\n\nvoid out() { cout << '\\n';\
    \ }\ntemplate <class T, class... Ts>\nvoid out(const T &a, const Ts &...b) {\n\
    \  cout << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\nvoid\
    \ outf() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid outf(const\
    \ T &a, const Ts &...b) {\n  cout << fixed << setprecision(14) << a;\n  (cout\
    \ << ... << (cout << ' ', b));\n  cout << '\\n';\n}\n\ntemplate <typename T>\n\
    istream &operator>>(istream &is, vector<T> &v) {\n  for (T &in : v) is >> in;\n\
    \  return is;\n}\n\ninline void in(void) { return; }\ntemplate <typename First,\
    \ typename... Rest>\nvoid in(First &first, Rest &...rest) {\n  cin >> first;\n\
    \  in(rest...);\n  return;\n}\n\ntemplate <typename T>\nbool chmax(T &a, const\
    \ T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n\
    }\ntemplate <typename T>\nbool chmin(T &a, const T &b) {\n  if (a > b) {\n   \
    \ a = b;\n    return true;\n  }\n  return false;\n}\n\nvector<lint> dx8 = {1,\
    \ 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};\n\
    vector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0, 1, 0, -1};\n\n#pragma\
    \ endregion\n#line 2 \"verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp\"\
    \n\n#line 1 \"linear-algebra/BitMatrix.hpp\"\n\n\nstruct BitMatrix {\n private:\n\
    \ public:\n  vector<dynamic_bitset<>> A;\n  BitMatrix() {}\n  BitMatrix(int n,\
    \ int m) : A(n, dynamic_bitset<>(m)) {}\n  BitMatrix(int n) : A(n, dynamic_bitset<>(n))\
    \ {}\n\n  inline int size() const { return A.size(); }\n  inline int height()\
    \ const { return A.size(); }\n  inline int width() const { return A[0].size();\
    \ }\n  inline const dynamic_bitset<>& operator[](int h) const { return (A[h]);\
    \ }\n  inline dynamic_bitset<>& operator[](int h) { return (A[h]); }\n\n  BitMatrix&\
    \ operator+=(const BitMatrix& B) {\n    int h = height();\n    for (int i = 0;\
    \ i < h; i++) (*this)[i] ^= B[i];\n    return (*this);\n  }\n  BitMatrix& operator-=(const\
    \ BitMatrix& B) {\n    int h = height();\n    for (int i = 0; i < h; i++) (*this)[i]\
    \ ^= B[i];\n    return (*this);\n  }\n\n  BitMatrix& operator*=(const BitMatrix&\
    \ B) {\n    int h = height();\n    int w = B.width();\n    int c = width();\n\
    \    vector<dynamic_bitset<>> C(h, dynamic_bitset<>(w));\n    for (int i = 0;\
    \ i < h; i++) {\n      for (int j = 0; j < c; j++) {\n        if ((*this)[i][j])\
    \ C[i] ^= B[j];\n      }\n    }\n    A = move(C);\n    return (*this);\n  }\n\n\
    \  BitMatrix operator+(const BitMatrix& B) const { return (BitMatrix(*this) +=\
    \ B); }\n  BitMatrix operator-(const BitMatrix& B) const { return (BitMatrix(*this)\
    \ -= B); }\n  BitMatrix operator*(const BitMatrix& B) const { return (BitMatrix(*this)\
    \ *= B); }\n\n  int rank() {\n    BitMatrix B(*this);\n    if (B.height() == 0\
    \ or B.width() == 0) return 0;\n    int res = 0;\n    int h = height();\n    int\
    \ w = width();\n    int ch = 0;\n    int cw = 0;\n    while (ch < h and cw < w)\
    \ {\n      bool ok = false;\n      for (int j = cw; j < w; j++) {\n        for\
    \ (int i = ch; i < h; i++) {\n          if (B[i][j]) {\n            ok = true;\n\
    \            swap(B[ch], B[i]);\n            for (int i2 = 0; i2 < h; i2++) {\n\
    \              if (B[i2][j] != 0 and i2 != ch) B[i2] ^= B[ch];\n            }\n\
    \            res++;\n            ch++;\n            cw = j + 1;\n            break;\n\
    \          }\n        }\n        if (ok) break;\n      }\n      if (!ok) break;\n\
    \    }\n    return res;\n  }\n\n  int determinant() {\n    BitMatrix B(*this);\n\
    \    if (B.height() == 0 or B.width() == 0) return 0;\n    assert(B.height() ==\
    \ B.width());\n    int h = height();\n    int w = width();\n    int ch = 0;\n\
    \    int cw = 0;\n    while (ch < h and cw < w) {\n      bool ok = false;\n  \
    \    for (int j = cw; j < w; j++) {\n        for (int i = ch; i < h; i++) {\n\
    \          if (B[i][j]) {\n            ok = true;\n            swap(B[ch], B[i]);\n\
    \            for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) B[i2] ^= B[ch];\n            }\n            ch++;\n          \
    \  cw = j + 1;\n            break;\n          }\n        }\n        if (ok) {\n\
    \          break;\n        } else {\n          return 0;\n        }\n      }\n\
    \      if (!ok) break;\n    }\n    return 1;\n  }\n\n  pair<bool, BitMatrix> inverse()\
    \ {\n    int h = height();\n    int w = width();\n    assert(h == w);\n    BitMatrix\
    \ B(h, w * 2);\n    for (int i = 0; i < h; i++) {\n      dynamic_bitset<> tmp\
    \ = (*this)[i];\n      tmp.resize(w * 2);\n      tmp[i + w] = 1;\n      B[i] ^=\
    \ tmp;\n    }\n\n    w *= 2;\n    int rnk = 0;\n\n    int ch = 0;\n    int cw\
    \ = 0;\n    while (ch < h and cw < h) {\n      bool ok = false;\n      for (int\
    \ j = cw; j < h; j++) {\n        for (int i = ch; i < h; i++) {\n          if\
    \ (B[i][j] != 0) {\n            ok = true;\n            swap(B[ch], B[i]);\n \
    \           for (int i2 = 0; i2 < h; i2++) {\n              if (B[i2][j] != 0\
    \ and i2 != ch) B[i2] ^= B[ch];\n            }\n            rnk++;\n         \
    \   ch++;\n            cw = j + 1;\n            break;\n          }\n        }\n\
    \        if (ok) break;\n      }\n      if (!ok) break;\n    }\n    BitMatrix\
    \ res(h);\n    if (rnk == h) {\n      for (int i = 0; i < h; i++) {\n        B[i]\
    \ >>= h;\n        B[i].resize(h);\n        res[i] ^= B[i];\n      }\n      return\
    \ {true, res};\n    } else {\n      return {false, res};\n    }\n  }\n\n  BitMatrix\
    \ linear_equation(dynamic_bitset<> b) {\n    BitMatrix A(*this);\n    int rnk\
    \ = 0;\n    assert(A.height() == b.size());\n    int h = height();\n    int w\
    \ = width();\n    int ch = 0;\n    int cw = 0;\n    vector<int> pivot_row(w, -1);\n\
    \    while (ch < h and cw < w) {\n      bool ok = false;\n      for (int j = cw;\
    \ j < w; j++) {\n        for (int i = ch; i < h; i++) {\n          if (A[i][j]\
    \ != 0) {\n            ok = true;\n            swap(A[ch], A[i]);\n          \
    \  bool tmp = b[ch];\n            b[ch] = b[i];\n            b[i] = tmp;\n   \
    \         for (int i2 = 0; i2 < h; i2++) {\n              if (A[i2][j] != 0 and\
    \ i2 != ch) {\n                A[i2] ^= A[ch];\n                b[i2] = b[i2]\
    \ ^ b[ch];\n              }\n            }\n            pivot_row[j] = ch;\n \
    \           rnk++;\n            ch++;\n            cw = j + 1;\n            break;\n\
    \          }\n        }\n        if (ok) break;\n      }\n      if (!ok) break;\n\
    \    }\n\n    for (int i = rnk; i < h; i++) {\n      if (b[i] != 0) return BitMatrix(0);\n\
    \    }\n    BitMatrix sol(w - rnk + 1, w);\n    int idx = 1;\n    for (int j =\
    \ 0; j < w; j++) {\n      if (pivot_row[j] != -1) {\n        sol[0][j] = b[pivot_row[j]];\n\
    \      } else {\n        sol[idx][j] = 1;\n        for (int i = 0; i < w; i++)\
    \ {\n          if (pivot_row[i] != -1) {\n            sol[idx][i] = A[pivot_row[i]][j];\n\
    \          }\n        }\n        idx++;\n      }\n    }\n    return sol;\n  }\n\
    };\n#line 4 \"verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp\"\
    \n\n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, m;\n  in(n, m);\n\
    \  BitMatrix a(n, m);\n  rep(i, n) {\n    string s;\n    in(s);\n    rep(j, m)\
    \ {\n      if (s[j] == '1') a[i][j] = 1;\n    }\n  }\n\n  dynamic_bitset<> b(n);\n\
    \  string s;\n  in(s);\n  rep(i, n) {\n    if (s[i] == '1') b[i] = 1;\n  }\n \
    \ BitMatrix sol = a.linear_equation(b);\n  if (sol.size() == 0) {\n    out(-1);\n\
    \  } else {\n    out(sol.size() - 1);\n    rep(i, sol.size()) {\n      s = sol[i].to_string();\n\
    \      reverse(all(s));\n      out(s);\n    }\n  }\n}\n"
  code: "#include \"../../../template/template.hpp\"\n\n#include \"../../../linear-algebra/BitMatrix.hpp\"\
    \n\n#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int n, m;\n  in(n, m);\n\
    \  BitMatrix a(n, m);\n  rep(i, n) {\n    string s;\n    in(s);\n    rep(j, m)\
    \ {\n      if (s[j] == '1') a[i][j] = 1;\n    }\n  }\n\n  dynamic_bitset<> b(n);\n\
    \  string s;\n  in(s);\n  rep(i, n) {\n    if (s[i] == '1') b[i] = 1;\n  }\n \
    \ BitMatrix sol = a.linear_equation(b);\n  if (sol.size() == 0) {\n    out(-1);\n\
    \  } else {\n    out(sol.size() - 1);\n    rep(i, sol.size()) {\n      s = sol[i].to_string();\n\
    \      reverse(all(s));\n      out(s);\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - linear-algebra/BitMatrix.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
  requiredBy: []
  timestamp: '2026-03-24 21:06:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
- /verify/verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp.html
title: verify/LibraryChecker/linear-algebra/SystemofLinearEquationsMod2.test.cpp
---
