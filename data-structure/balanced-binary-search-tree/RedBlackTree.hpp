class RedBlackTree {
 private:
  const int RED = 0;
  const int BLACK = 1;
  struct Node {
    Node *p, *left, *right;
    int color, key;
  };

  Node *NIL;
  Node *root;

  void left_rotate(Node *x) {
    assert(x->right);
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NIL) y->left->p = x;
    y->p = x->p;
    if (x->p == NIL) {
      root = y;
    } else if (x == x->p->left) {
      x->p->left = y;
    } else {
      x->p->right = y;
    }
    y->left = x;
    x->p = y;
  }

  void right_rotate(Node *y) {
    assert(y->left);
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NIL) x->right->p = y;
    x->p = y->p;
    if (y->p == NIL) {
      root = x;
    } else if (y == y->p->left) {
      y->p->left = x;
    } else {
      y->p->right = x;
    }
    x->right = y;
    y->p = x;
  }

  void insert(Node *z) {
    Node *y = NIL;
    Node *x = root;
    while (x != NIL) {
      y = x;
      if (z->key < x->key) {
        x = x->left;
      } else {
        x = x->right;
      }
    }
    z->p = y;
    if (y == NIL) {
      root = z;
    } else if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
    z->left = NIL;
    z->right = NIL;
    z->color = RED;
    insert_fixup(z);
  }

  void insert_fixup(Node *z) {
    while (z->p->color == RED) {
      if (z->p == z->p->p->left) {
        Node *y = z->p->p->right;
        if (y->color == RED) {
          z->p->color = BLACK;
          y->color = BLACK;
          z->p->p->color = RED;
          z = z->p->p;
        } else if (z == z->p->right) {
          z = z->p;
          left_rotate(z);
        } else if (z == z->p->left) {
          z->p->color = BLACK;
          z->p->p->color = RED;
          right_rotate(z->p->p);
        }
      } else if (z->p == z->p->p->right) {
        Node *y = z->p->p->left;
        if (y->color == RED) {
          z->p->color = BLACK;
          y->color = BLACK;
          z->p->p->color = RED;
          z = z->p->p;
        } else if (z == z->p->left) {
          z = z->p;
          right_rotate(z);
        } else if (z == z->p->right) {
          z->p->color = BLACK;
          z->p->p->color = RED;
          left_rotate(z->p->p);
        }
      }
    }
    root->color = BLACK;
  }

  void transplant(Node *u, Node *v) {
    if (u->p == NIL) {
      root = v;
    } else if (u == u->p->left) {
      u->p->left = v;
    } else {
      u->p->right = v;
    }
    v->p = u->p;
  }

  void erase(Node *z) {
    Node *x;
    Node *y = z;
    int y_original_color = y->color;
    if (z->left == NIL) {
      x = z->right;
      transplant(z, z->right);
    } else if (z->right == NIL) {
      x = z->left;
      transplant(z, z->left);
    } else {
      y = min_element(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->p == z) {
        x->p = y;
      } else {
        transplant(y, y->right);
        y->right = z->right;
        y->right->p = y;
      }
      transplant(z, y);
      y->left = z->left;
      y->left->p = y;
      y->color = z->color;
    }

    if (y_original_color == BLACK) {
      erase_fixup(x);
    }
    delete z;
  }

  void erase_fixup(Node *x) {
    while (x != root and x->color == BLACK) {
      if (x == x->p->left) {
        Node *w = x->p->right;
        if (w->color == RED) {
          w->color = BLACK;
          x->p->color = RED;
          left_rotate(x->p);
          w = w->p->right;
        } else if (w->left->color == BLACK and w->right->color == BLACK) {
          w->color = RED;
          x = x->p;
        } else if (w->right->color == BLACK) {
          w->left->color = BLACK;
          w->color = RED;
          right_rotate(w);
          w = x->p->right;
        } else {
          w->color = x->p->color;
          x->p->color = BLACK;
          w->right->color = BLACK;
          left_rotate(x->p);
          x = root;
        }
      } else {
        Node *w = x->p->left;
        if (w->color == RED) {
          w->color = BLACK;
          x->p->color = RED;
          right_rotate(x->p);
          w = w->p->left;
        } else if (w->left->color == BLACK and w->right->color == BLACK) {
          w->color = RED;
          x = x->p;
        } else if (w->left->color == BLACK) {
          w->right->color = BLACK;
          w->color = RED;
          left_rotate(w);
          w = x->p->left;
        } else {
          w->color = x->p->color;
          x->p->color = BLACK;
          w->left->color = BLACK;
          right_rotate(x->p);
          x = root;
        }
      }
    }
    x->color = BLACK;
  }

  Node *min_element(Node *cur) {
    while (cur->left != NIL) cur = cur->left;
    return cur;
  }

  Node *max_element(Node *cur) {
    while (cur->right != NIL) cur = cur->right;
    return cur;
  }

  Node *contains(Node *cur, int key) {
    while (cur != NIL and cur->key != key) {
      if (key < cur->key) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return cur;
  }

  Node *lower_bound(Node *cur, int key) {
    Node *res = NIL;
    while (cur != NIL) {
      if (cur->key >= key) {
        res = cur;
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return res;
  }

 public:
  RedBlackTree() {
    NIL = new Node();
    NIL->color = BLACK;
    NIL->key = 0;
    NIL->p = NIL->left = NIL->right = NIL;
    root = NIL;
  }

  void insert(int value) {
    Node *z = new Node();
    z->color = RED;
    z->key = value;
    insert(z);
  }

  void erase(int value) {
    Node *z = contains(root, value);
    if (z != NIL) erase(z);
  }

  bool contains(int value) {
    Node *z = contains(root, value);
    return z != NIL;
  }

  int min_element() {
    Node *z = min_element(root);
    return z->key;
  }

  int max_element() {
    Node *z = max_element(root);
    return z->key;
  }

  int lower_bound(int value) {
    Node *z = lower_bound(root, value);
    if (z == NIL) return -1;
    return z->key;
  }

  void debug(Node *cur = nullptr) {
    if (cur == nullptr) cur = root;
    if (cur == NIL) return;
    cout << "key: " << cur->key << ", color: " << cur->color << ", P:" << (cur->p == NIL ? "NIL" : to_string(cur->p->key)) << ", L:" << (cur->left == NIL ? "NIL" : to_string(cur->left->key)) << ' ' << ", R:" << (cur->right == NIL ? "NIL" : to_string(cur->right->key)) << endl;
    debug(cur->left);
    debug(cur->right);
  }
};
