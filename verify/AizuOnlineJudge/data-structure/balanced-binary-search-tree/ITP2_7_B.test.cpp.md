---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/balanced-binary-search-tree/RedBlackTree.hpp
    title: Red Black Tree
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/7/ITP2_7_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/7/ITP2_7_B
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing lint = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n#define\
    \ all(x) (x).begin(), (x).end()\n#define uniqv(v) v.erase(unique(all(v)), v.end())\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP1(i, n) for (auto\
    \ i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))\n#define REP2(i, l, r) for\
    \ (auto i = (l); (i) != (r); ++(i))\n#define rep(...) OVERLOAD_REP(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define logfixed(x) cout << fixed << setprecision(10)\
    \ << x << endl;\n\nostream &operator<<(ostream &dest, __int128_t value) {\n  ostream::sentry\
    \ s(dest);\n  if (s) {\n    __uint128_t tmp = value < 0 ? -value : value;\n  \
    \  char buffer[128];\n    char *d = end(buffer);\n    do {\n      --d;\n     \
    \ *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n    } while (tmp != 0);\n\
    \    if (value < 0) {\n      --d;\n      *d = '-';\n    }\n    int len = end(buffer)\
    \ - d;\n    if (dest.rdbuf()->sputn(d, len) != len) {\n      dest.setstate(ios_base::badbit);\n\
    \    }\n  }\n  return dest;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n  for (int i = 0; i < (int)v.size(); i++) {\n  \
    \  os << v[i] << (i + 1 != (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\n  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os\
    \ << *itr;\n    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n\
    \  }\n  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const unordered_set<T> &set_var) {\n  for (auto itr = set_var.begin(); itr !=\
    \ set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr != set_var.end())\
    \ os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const map<T, U> &map_var) {\n  for (auto\
    \ itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os << itr->first\
    \ << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const unordered_map<T, U> &map_var)\
    \ {\n  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os\
    \ << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\
    \ntemplate <typename T, typename U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &pair_var) {\n  os << pair_var.first << \" \" << pair_var.second;\n  return\
    \ os;\n}\n\nvoid out() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid\
    \ out(const T &a, const Ts &...b) {\n  cout << a;\n  (cout << ... << (cout <<\
    \ ' ', b));\n  cout << '\\n';\n}\n\nvoid outf() { cout << '\\n'; }\ntemplate <class\
    \ T, class... Ts>\nvoid outf(const T &a, const Ts &...b) {\n  cout << fixed <<\
    \ setprecision(14) << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\\
    n';\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v)\
    \ {\n  for (T &in : v) is >> in;\n  return is;\n}\n\ninline void in(void) { return;\
    \ }\ntemplate <typename First, typename... Rest>\nvoid in(First &first, Rest &...rest)\
    \ {\n  cin >> first;\n  in(rest...);\n  return;\n}\n\ntemplate <typename T>\n\
    bool chmax(T &a, const T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <typename T>\nbool chmin(T &a, const T &b)\
    \ {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\n\
    vector<lint> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1,\
    \ 1, 0, -1, -1, -1};\nvector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0,\
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/7/ITP2_7_B\"\
    \n#line 1 \"data-structure/balanced-binary-search-tree/RedBlackTree.hpp\"\nclass\
    \ RedBlackTree {\n private:\n  const int RED = 0;\n  const int BLACK = 1;\n  struct\
    \ Node {\n    Node *p, *left, *right;\n    int color, key;\n  };\n\n  Node *NIL;\n\
    \  Node *root;\n\n  void left_rotate(Node *x) {\n    assert(x->right);\n    Node\
    \ *y = x->right;\n    x->right = y->left;\n    if (y->left != NIL) y->left->p\
    \ = x;\n    y->p = x->p;\n    if (x->p == NIL) {\n      root = y;\n    } else\
    \ if (x == x->p->left) {\n      x->p->left = y;\n    } else {\n      x->p->right\
    \ = y;\n    }\n    y->left = x;\n    x->p = y;\n  }\n\n  void right_rotate(Node\
    \ *y) {\n    assert(y->left);\n    Node *x = y->left;\n    y->left = x->right;\n\
    \    if (x->right != NIL) x->right->p = y;\n    x->p = y->p;\n    if (y->p ==\
    \ NIL) {\n      root = x;\n    } else if (y == y->p->left) {\n      y->p->left\
    \ = x;\n    } else {\n      y->p->right = x;\n    }\n    x->right = y;\n    y->p\
    \ = x;\n  }\n\n  void insert(Node *z) {\n    Node *y = NIL;\n    Node *x = root;\n\
    \    while (x != NIL) {\n      y = x;\n      if (z->key < x->key) {\n        x\
    \ = x->left;\n      } else {\n        x = x->right;\n      }\n    }\n    z->p\
    \ = y;\n    if (y == NIL) {\n      root = z;\n    } else if (z->key < y->key)\
    \ {\n      y->left = z;\n    } else {\n      y->right = z;\n    }\n    z->left\
    \ = NIL;\n    z->right = NIL;\n    z->color = RED;\n    insert_fixup(z);\n  }\n\
    \n  void insert_fixup(Node *z) {\n    while (z->p->color == RED) {\n      if (z->p\
    \ == z->p->p->left) {\n        Node *y = z->p->p->right;\n        if (y->color\
    \ == RED) {\n          z->p->color = BLACK;\n          y->color = BLACK;\n   \
    \       z->p->p->color = RED;\n          z = z->p->p;\n        } else if (z ==\
    \ z->p->right) {\n          z = z->p;\n          left_rotate(z);\n        } else\
    \ if (z == z->p->left) {\n          z->p->color = BLACK;\n          z->p->p->color\
    \ = RED;\n          right_rotate(z->p->p);\n        }\n      } else if (z->p ==\
    \ z->p->p->right) {\n        Node *y = z->p->p->left;\n        if (y->color ==\
    \ RED) {\n          z->p->color = BLACK;\n          y->color = BLACK;\n      \
    \    z->p->p->color = RED;\n          z = z->p->p;\n        } else if (z == z->p->left)\
    \ {\n          z = z->p;\n          right_rotate(z);\n        } else if (z ==\
    \ z->p->right) {\n          z->p->color = BLACK;\n          z->p->p->color = RED;\n\
    \          left_rotate(z->p->p);\n        }\n      }\n    }\n    root->color =\
    \ BLACK;\n  }\n\n  void transplant(Node *u, Node *v) {\n    if (u->p == NIL) {\n\
    \      root = v;\n    } else if (u == u->p->left) {\n      u->p->left = v;\n \
    \   } else {\n      u->p->right = v;\n    }\n    v->p = u->p;\n  }\n\n  void erase(Node\
    \ *z) {\n    Node *x;\n    Node *y = z;\n    int y_original_color = y->color;\n\
    \    if (z->left == NIL) {\n      x = z->right;\n      transplant(z, z->right);\n\
    \    } else if (z->right == NIL) {\n      x = z->left;\n      transplant(z, z->left);\n\
    \    } else {\n      y = min_element(z->right);\n      y_original_color = y->color;\n\
    \      x = y->right;\n      if (y->p == z) {\n        x->p = y;\n      } else\
    \ {\n        transplant(y, y->right);\n        y->right = z->right;\n        y->right->p\
    \ = y;\n      }\n      transplant(z, y);\n      y->left = z->left;\n      y->left->p\
    \ = y;\n      y->color = z->color;\n    }\n\n    if (y_original_color == BLACK)\
    \ {\n      erase_fixup(x);\n    }\n    delete z;\n  }\n\n  void erase_fixup(Node\
    \ *x) {\n    while (x != root and x->color == BLACK) {\n      if (x == x->p->left)\
    \ {\n        Node *w = x->p->right;\n        if (w->color == RED) {\n        \
    \  w->color = BLACK;\n          x->p->color = RED;\n          left_rotate(x->p);\n\
    \          w = w->p->right;\n        } else if (w->left->color == BLACK and w->right->color\
    \ == BLACK) {\n          w->color = RED;\n          x = x->p;\n        } else\
    \ if (w->right->color == BLACK) {\n          w->left->color = BLACK;\n       \
    \   w->color = RED;\n          right_rotate(w);\n          w = x->p->right;\n\
    \        } else {\n          w->color = x->p->color;\n          x->p->color =\
    \ BLACK;\n          w->right->color = BLACK;\n          left_rotate(x->p);\n \
    \         x = root;\n        }\n      } else {\n        Node *w = x->p->left;\n\
    \        if (w->color == RED) {\n          w->color = BLACK;\n          x->p->color\
    \ = RED;\n          right_rotate(x->p);\n          w = w->p->left;\n        }\
    \ else if (w->left->color == BLACK and w->right->color == BLACK) {\n         \
    \ w->color = RED;\n          x = x->p;\n        } else if (w->left->color == BLACK)\
    \ {\n          w->right->color = BLACK;\n          w->color = RED;\n         \
    \ left_rotate(w);\n          w = x->p->left;\n        } else {\n          w->color\
    \ = x->p->color;\n          x->p->color = BLACK;\n          w->left->color = BLACK;\n\
    \          right_rotate(x->p);\n          x = root;\n        }\n      }\n    }\n\
    \    x->color = BLACK;\n  }\n\n  Node *min_element(Node *cur) {\n    while (cur->left\
    \ != NIL) cur = cur->left;\n    return cur;\n  }\n\n  Node *max_element(Node *cur)\
    \ {\n    while (cur->right != NIL) cur = cur->right;\n    return cur;\n  }\n\n\
    \  Node *contains(Node *cur, int key) {\n    while (cur != NIL and cur->key !=\
    \ key) {\n      if (key < cur->key) {\n        cur = cur->left;\n      } else\
    \ {\n        cur = cur->right;\n      }\n    }\n    return cur;\n  }\n\n  Node\
    \ *lower_bound(Node *cur, int key) {\n    Node *res = NIL;\n    while (cur !=\
    \ NIL) {\n      if (cur->key >= key) {\n        res = cur;\n        cur = cur->left;\n\
    \      } else {\n        cur = cur->right;\n      }\n    }\n    return res;\n\
    \  }\n\n public:\n  RedBlackTree() {\n    NIL = new Node();\n    NIL->color =\
    \ BLACK;\n    NIL->key = 0;\n    NIL->p = NIL->left = NIL->right = NIL;\n    root\
    \ = NIL;\n  }\n\n  void insert(int value) {\n    Node *z = new Node();\n    z->color\
    \ = RED;\n    z->key = value;\n    insert(z);\n  }\n\n  void erase(int value)\
    \ {\n    Node *z = contains(root, value);\n    if (z != NIL) erase(z);\n  }\n\n\
    \  bool contains(int value) {\n    Node *z = contains(root, value);\n    return\
    \ z != NIL;\n  }\n\n  int min_element() {\n    Node *z = min_element(root);\n\
    \    return z->key;\n  }\n\n  int max_element() {\n    Node *z = max_element(root);\n\
    \    return z->key;\n  }\n\n  int lower_bound(int value) {\n    Node *z = lower_bound(root,\
    \ value);\n    if (z == NIL) return -1;\n    return z->key;\n  }\n\n  void debug(Node\
    \ *cur = nullptr) {\n    if (cur == nullptr) cur = root;\n    if (cur == NIL)\
    \ return;\n    cout << \"key: \" << cur->key << \", color: \" << cur->color <<\
    \ \", P:\" << (cur->p == NIL ? \"NIL\" : to_string(cur->p->key)) << \", L:\" <<\
    \ (cur->left == NIL ? \"NIL\" : to_string(cur->left->key)) << ' ' << \", R:\"\
    \ << (cur->right == NIL ? \"NIL\" : to_string(cur->right->key)) << endl;\n   \
    \ debug(cur->left);\n    debug(cur->right);\n  }\n};\n#line 4 \"verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp\"\
    \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    RedBlackTree t;\n   \
    \ int q;\n    in(q);\n    int siz = 0;\n    rep(i, q) {\n        int com, x;\n\
    \        in(com, x);\n        if (com == 0) {\n            if (!t.contains(x))\
    \ {\n                t.insert(x);\n                siz++;\n            }\n   \
    \         out(siz);\n        } else if (com == 1) {\n            out((t.contains(x)\
    \ ? 1 : 0));\n        } else {\n            if (t.contains(x)) {\n           \
    \     t.erase(x);\n                siz--;\n            }\n        }\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/7/ITP2_7_B\"\
    \n#include \"../../../../data-structure/balanced-binary-search-tree/RedBlackTree.hpp\"\
    \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    RedBlackTree t;\n   \
    \ int q;\n    in(q);\n    int siz = 0;\n    rep(i, q) {\n        int com, x;\n\
    \        in(com, x);\n        if (com == 0) {\n            if (!t.contains(x))\
    \ {\n                t.insert(x);\n                siz++;\n            }\n   \
    \         out(siz);\n        } else if (com == 1) {\n            out((t.contains(x)\
    \ ? 1 : 0));\n        } else {\n            if (t.contains(x)) {\n           \
    \     t.erase(x);\n                siz--;\n            }\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/balanced-binary-search-tree/RedBlackTree.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp
  requiredBy: []
  timestamp: '2025-09-28 01:25:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp
- /verify/verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp.html
title: verify/AizuOnlineJudge/data-structure/balanced-binary-search-tree/ITP2_7_B.test.cpp
---
