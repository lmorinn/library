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
  bundledCode: "#line 1 \"data-structure/balanced-binary-search-tree/RedBlackTree.hpp\"\
    \nclass RedBlackTree {\n private:\n  const int RED = 0;\n  const int BLACK = 1;\n\
    \  struct Node {\n    Node *p, *left, *right;\n    int color, key;\n  };\n\n \
    \ Node *NIL;\n  Node *root;\n\n  void left_rotate(Node *x) {\n    assert(x->right);\n\
    \    Node *y = x->right;\n    x->right = y->left;\n    if (y->left != NIL) y->left->p\
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
    \ debug(cur->left);\n    debug(cur->right);\n  }\n};\n"
  code: "class RedBlackTree {\n private:\n  const int RED = 0;\n  const int BLACK\
    \ = 1;\n  struct Node {\n    Node *p, *left, *right;\n    int color, key;\n  };\n\
    \n  Node *NIL;\n  Node *root;\n\n  void left_rotate(Node *x) {\n    assert(x->right);\n\
    \    Node *y = x->right;\n    x->right = y->left;\n    if (y->left != NIL) y->left->p\
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
    \ debug(cur->left);\n    debug(cur->right);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/balanced-binary-search-tree/RedBlackTree.hpp
  requiredBy: []
  timestamp: '2025-06-22 12:57:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/balanced-binary-search-tree/RedBlackTree.hpp
layout: document
title: Red Black Tree
---

## 概要

todo

## 計算量
todo