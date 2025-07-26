---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/balanced-binary-search-tree/AVLTree.hpp
    title: AVL Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
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
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\"\n#line 1 \"\
    data-structure/balanced-binary-search-tree/AVLTree.hpp\"\nclass AVLTree {\n  \
    \ private:\n    struct Node {\n        Node *p, *left, *right;\n        int key,\
    \ height;\n        int subtree_size;\n\n        // Balance Factor\n        int\
    \ bf() {\n            return left->height - right->height;\n        }\n    };\n\
    \    int siz;\n    Node *NIL;\n    Node *root;\n\n    // \u5DE6\u56DE\u8EE2\n\
    \    void rotate_left(Node *x) {\n        Node *y = x->right;\n        x->right\
    \ = y->left;\n        if (y->left != NIL) y->left->p = x;\n        y->p = x->p;\n\
    \        if (x->p == NIL) {\n            root = y;\n        } else if (x == x->p->left)\
    \ {\n            x->p->left = y;\n        } else {\n            x->p->right =\
    \ y;\n        }\n        y->left = x;\n        x->p = y;\n        update(x);\n\
    \        update(y);\n    }\n\n    // \u53F3\u56DE\u8EE2\n    void rotate_right(Node\
    \ *y) {\n        Node *x = y->left;\n        y->left = x->right;\n        if (x->right\
    \ != NIL) x->right->p = y;\n        x->p = y->p;\n        if (y->p == NIL) {\n\
    \            root = x;\n        } else if (y == y->p->left) {\n            y->p->left\
    \ = x;\n        } else {\n            y->p->right = x;\n        }\n        x->right\
    \ = y;\n        y->p = x;\n        update(y);\n        update(x);\n    }\n\n \
    \   // \u53F3\u56DE\u8EE2\u2192\u5DE6\u56DE\u8EE2\n    void rotate_RL(Node *x)\
    \ {\n        rotate_right(x->right);\n        rotate_left(x);\n    }\n\n    //\
    \ \u5DE6\u56DE\u8EE2\u2192\u53F3\u56DE\u8EE2\n    void rotate_LR(Node *z) {\n\
    \        rotate_left(z->left);\n        rotate_right(z);\n    }\n\n    // \u90E8\
    \u5206\u6728cur\u306E\u60C5\u5831\u3092\u66F4\u65B0\u3059\u308B\uFF08\u5DE6\u53F3\
    \u306E\u5B50\u306E\u60C5\u5831\u304C\u6700\u65B0\u3067\u306A\u3044\u3068\u3044\
    \u3051\u306A\u3044\uFF09\n    void update(Node *cur) {\n        cur->height =\
    \ max(cur->left->height, cur->right->height) + 1;\n        cur->subtree_size =\
    \ cur->left->subtree_size + cur->right->subtree_size + 1;\n    }\n\n    // \u30CE\
    \u30FC\u30C9\u30DD\u30A4\u30F3\u30BFz\u3092AVL\u6728\u306B\u633F\u5165\u3059\u308B\
    \u3002\u633F\u5165\u3067\u304D\u305F\u5834\u5408true\u3001z\u306Ekey\u304C\u3059\
    \u3067\u306B\u542B\u307E\u308C\u3066\u3044\u305F\u5834\u5408false\u3092\u8FD4\u3059\
    \n    bool insert(Node *z) {\n        Node *y = NIL;\n        Node *x = root;\n\
    \        while (x != NIL) {\n            y = x;\n            if (z->key == x->key)\
    \ {\n                delete z;\n                return false;\n            }\n\
    \            if (z->key < x->key) {\n                x = x->left;\n          \
    \  } else {\n                x = x->right;\n            }\n        }\n       \
    \ z->p = y;\n        if (y == NIL) {\n            root = z;\n        } else if\
    \ (z->key < y->key) {\n            y->left = z;\n        } else {\n          \
    \  y->right = z;\n        }\n        siz++;\n        insert_fixup(z);\n      \
    \  return true;\n    }\n\n    // \u633F\u5165\u64CD\u4F5C\u6642\u306EAVL\u6728\
    \u4FEE\u5FA9\u51E6\u7406\n    void insert_fixup(Node *z) {\n        bool active\
    \ = true;\n        while (z->p != NIL) {\n            Node *u = z->p;\n      \
    \      update(u);\n            if (!active) {\n                z = u;\n      \
    \          continue;\n            }\n            int bf_u = u->bf();\n       \
    \     if (u->left == z) {\n                if (bf_u == 0) {\n                \
    \    active = false;\n                } else if (bf_u == 2) {\n              \
    \      Node *v = u->left;\n                    if (v->bf() == 1) {\n         \
    \               rotate_right(u);\n                        active = false;\n  \
    \                  } else {\n                        rotate_LR(u);\n         \
    \               active = false;\n                    }\n                }\n  \
    \          } else {\n                if (bf_u == 0) {\n                    active\
    \ = false;\n                } else if (bf_u == -2) {\n                    Node\
    \ *v = u->right;\n                    if (v->bf() == -1) {\n                 \
    \       rotate_left(u);\n                        active = false;\n           \
    \         } else {\n                        rotate_RL(u);\n                  \
    \      active = false;\n                    }\n                }\n           \
    \ }\n            z = u;\n        }\n    }\n\n    // cur\u306E\u90E8\u5206\u6728\
    \u5185\u3067\u6700\u5C0F\u306E\u30AD\u30FC\u3092\u6301\u3064\u30CE\u30FC\u30C9\
    \u30DD\u30A4\u30F3\u30BF\u3092\u8FD4\u3059\n    Node *min_element(Node *cur) {\n\
    \        while (cur->left != NIL) {\n            cur = cur->left;\n        }\n\
    \        return cur;\n    }\n\n    // \u90E8\u5206\u6728u\u306E\u5834\u6240\u306B\
    \u90E8\u5206\u6728v\u3092\u690D\u3048\u66FF\u3048\u308B(u\u306E\u89AA\u306E\u5B50\
    \u3092v\u306B\u3059\u308B)\n    void transplant(Node *u, Node *v) {\n        if\
    \ (u->p == NIL) {\n            root = v;\n        } else if (u == u->p->left)\
    \ {\n            u->p->left = v;\n        } else {\n            u->p->right =\
    \ v;\n        }\n        v->p = u->p;\n        if (u->p != NIL) update(u->p);\n\
    \    }\n\n    // \u30CE\u30FC\u30C9\u30DD\u30A4\u30F3\u30BFz\u3092AVL\u6728\u304B\
    \u3089\u524A\u9664\u3059\u308B\u3002\n    void erase(Node *z) {\n        Node\
    \ *x;\n        Node *y = z;\n        if (z->left == NIL) {\n            x = z->right;\n\
    \            transplant(z, z->right);\n        } else if (z->right == NIL) {\n\
    \            x = z->left;\n            transplant(z, z->left);\n        } else\
    \ {\n            y = min_element(z->right);\n            x = y->right;\n     \
    \       if (y->p == z) {\n                x->p = y;\n            } else {\n  \
    \              transplant(y, y->right);\n                y->right = z->right;\n\
    \                y->right->p = y;\n            }\n            transplant(z, y);\n\
    \            y->left = z->left;\n            y->left->p = y;\n        }\n    \
    \    erase_fixup(x);\n        siz--;\n        delete z;\n    }\n\n    // \u524A\
    \u9664\u64CD\u4F5C\u6642\u306EAVL\u6728\u4FEE\u5FA9\u51E6\u7406\n    void erase_fixup(Node\
    \ *z) {\n        bool active = true;\n        while (z->p != NIL) {\n        \
    \    Node *u = z->p;\n            update(u);\n            if (!active) {\n   \
    \             z = u;\n                continue;\n            }\n            int\
    \ bf_u = u->bf();\n            if (u->right == z) {\n                if (bf_u\
    \ == 1) {\n                    active = false;\n                } else if (bf_u\
    \ == 2) {\n                    Node *v = u->left;\n                    if (v->bf()\
    \ == 1) {\n                        rotate_right(u);\n                    } else\
    \ if (v->bf() == 0) {\n                        rotate_right(u);\n            \
    \            active = false;\n                    } else if (v->bf() == -1) {\n\
    \                        rotate_LR(u);\n                    }\n              \
    \  }\n            } else {\n                if (bf_u == -1) {\n              \
    \      active = false;\n                } else if (bf_u == -2) {\n           \
    \         Node *v = u->right;\n                    if (v->bf() == -1) {\n    \
    \                    rotate_left(u);\n                    } else if (v->bf() ==\
    \ 0) {\n                        rotate_left(u);\n                        active\
    \ = false;\n                    } else if (v->bf() == 1) {\n                 \
    \       rotate_RL(u);\n                    }\n                }\n            }\n\
    \            z = u;\n        }\n    }\n\n    // key\u306E\u30CE\u30FC\u30C9\u30DD\
    \u30A4\u30F3\u30BF\u3092\u8FD4\u3059\u3002key\u304C\u5B58\u5728\u3057\u306A\u3051\
    \u308C\u3070NIL\u3092\u8FD4\u3059\u3002\n    Node *contains(Node *cur, int key)\
    \ {\n        while (cur != NIL and cur->key != key) {\n            if (key < cur->key)\
    \ {\n                cur = cur->left;\n            } else {\n                cur\
    \ = cur->right;\n            }\n        }\n        return cur;\n    }\n\n    int\
    \ less_count(Node *cur, int key) {\n        int res = 0;\n        while (cur !=\
    \ NIL) {\n            if (cur->key < key) {\n                res += cur->left->subtree_size\
    \ + 1;\n                cur = cur->right;\n            } else {\n            \
    \    cur = cur->left;\n            }\n        }\n        return res;\n    }\n\n\
    \    Node *kth_element(Node *cur, int k) {\n        while (cur != NIL and k >\
    \ 0) {\n            if (cur->left->subtree_size < k) {\n                k -= cur->left->subtree_size;\n\
    \                if (k == 1) return cur;\n                k--;\n             \
    \   cur = cur->right;\n            } else {\n                cur = cur->left;\n\
    \            }\n        }\n        return cur;\n    }\n\n    Node *lower_bound(Node\
    \ *cur, int key) {\n        Node *res = NIL;\n        while (cur != NIL) {\n \
    \           if (key <= cur->key) {\n                res = cur;\n             \
    \   cur = cur->left;\n            } else {\n                cur = cur->right;\n\
    \            }\n        }\n        return res;\n    }\n\n    Node *upper_bound(Node\
    \ *cur, int key) {\n        Node *res = NIL;\n        while (cur != NIL) {\n \
    \           if (key >= cur->key) {\n                res = cur;\n             \
    \   cur = cur->right;\n            } else {\n                cur = cur->left;\n\
    \            }\n        }\n        return res;\n    }\n\n   public:\n    // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    AVLTree() {\n        NIL = new Node();\n\
    \        NIL->key = 0;\n        NIL->p = NIL->left = NIL->right = NIL;\n     \
    \   NIL->height = 0;\n        NIL->subtree_size = 0;\n        root = NIL;\n  \
    \      siz = 0;\n    }\n\n    // AVL\u6728\u306Bkey\u3092\u633F\u5165\u3059\u308B\
    \u3002\u633F\u5165\u3055\u308C\u305F\u3089true\u3001key\u304C\u3059\u3067\u306B\
    \u5B58\u5728\u3057\u305F\u3089false\u3092\u8FD4\u3059(\u4F55\u3082\u3057\u306A\
    \u3044)\n    bool insert(int key) {\n        Node *z = new Node();\n        z->key\
    \ = key;\n        z->left = NIL;\n        z->right = NIL;\n        z->height =\
    \ 1;\n        z->subtree_size = 1;\n        return insert(z);\n    }\n\n    //\
    \ AVL\u6728\u304B\u3089key\u3092\u524A\u9664\u3059\u308B\u3002\u524A\u9664\u3055\
    \u308C\u305F\u3089true\u3001key\u304C\u5B58\u5728\u3057\u306A\u304B\u3063\u305F\
    \u3089false\u3092\u8FD4\u3059\uFF08\u4F55\u3082\u3057\u306A\u3044\uFF09\n    bool\
    \ erase(int key) {\n        Node *z = contains(root, key);\n        if (z != NIL)\
    \ {\n            erase(z);\n            return true;\n        } else {\n     \
    \       return false;\n        }\n    }\n\n    // AVL\u6728\u306Bkey\u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u306A\u3089true\u3001\u305D\u3046\u3067\u306A\u3051\
    \u308C\u3070false\u3092\u8FD4\u3059\n    bool contains(int key) {\n        Node\
    \ *z = contains(root, key);\n        return z != NIL;\n    }\n\n    // \u73FE\u5728\
    \u306EAVL\u6728\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\n    int size() {\n\
    \        return siz;\n    }\n\n    // key\u672A\u6E80\u306E\u8981\u7D20\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\n    int less_count(int key) {\n        return less_count(root,\
    \ key);\n    }\n\n    // 0-indexed\u3067\u6607\u9806idx\u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1\u3092\
    \u8FD4\u3059\n    int kth_element(int idx) {\n        Node *z = kth_element(root,\
    \ idx + 1);\n        if (z != NIL) {\n            return z->key;\n        } else\
    \ {\n            return -1;\n        }\n    }\n\n    // key\u4EE5\u4E0A\u306E\u8981\
    \u7D20\u306E\u3046\u3061\u6700\u5C0F\u306E\u3082\u306E\u3092\u8FD4\u3059\u3002\
    \u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1\u3092\u8FD4\u3059\n    int lower_bound(int\
    \ key) {\n        Node *z = lower_bound(root, key);\n        if (z == NIL) return\
    \ -1;\n        return z->key;\n    }\n\n    // key\u4EE5\u4E0B\u306E\u8981\u7D20\
    \u306E\u3046\u3061\u6700\u5927\u306E\u3082\u306E\u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089-1\u3092\u8FD4\u3059\n    int upper_bound(int\
    \ key) {\n        Node *z = upper_bound(root, key);\n        if (z == NIL) return\
    \ -1;\n        return z->key;\n    }\n};\n#line 4 \"verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    AVLTree avl;\n    int\
    \ n, q;\n    in(n, q);\n    rep(i, n) {\n        int a;\n        in(a);\n    \
    \    avl.insert(a);\n    }\n\n    rep(i, q) {\n        int t, x;\n        in(t,\
    \ x);\n        if (t == 0) {\n            avl.insert(x);\n        } else if (t\
    \ == 1) {\n            avl.erase(x);\n        } else if (t == 2) {\n         \
    \   out(avl.kth_element(x - 1));\n        } else if (t == 3) {\n            out(avl.less_count(x\
    \ + 1));\n        } else if (t == 4) {\n            out(avl.upper_bound(x));\n\
    \        } else if (t == 5) {\n            out(avl.lower_bound(x));\n        }\n\
    \    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\"\
    \n#include \"../../../../data-structure/balanced-binary-search-tree/AVLTree.hpp\"\
    \n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    AVLTree avl;\n    int\
    \ n, q;\n    in(n, q);\n    rep(i, n) {\n        int a;\n        in(a);\n    \
    \    avl.insert(a);\n    }\n\n    rep(i, q) {\n        int t, x;\n        in(t,\
    \ x);\n        if (t == 0) {\n            avl.insert(x);\n        } else if (t\
    \ == 1) {\n            avl.erase(x);\n        } else if (t == 2) {\n         \
    \   out(avl.kth_element(x - 1));\n        } else if (t == 3) {\n            out(avl.less_count(x\
    \ + 1));\n        } else if (t == 4) {\n            out(avl.upper_bound(x));\n\
    \        } else if (t == 5) {\n            out(avl.lower_bound(x));\n        }\n\
    \    }\n}\n"
  dependsOn:
  - template/template.hpp
  - data-structure/balanced-binary-search-tree/AVLTree.hpp
  isVerificationFile: true
  path: verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp
  requiredBy: []
  timestamp: '2025-07-27 00:14:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp
layout: document
redirect_from:
- /verify/verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp
- /verify/verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp.html
title: verify/LibraryChecker/data-structure/balanced-binary-search-tree/OrderedSet.test.cpp
---
