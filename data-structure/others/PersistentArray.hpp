
template <class T>
class PersistentArray {
 public:
  struct Node {
    Node *l, *r;
    T val;
    Node() : l(nullptr), r(nullptr) {
    }
  };
  PersistentArray() {}
  PersistentArray(int siz) {
    n = siz;
    vector<T> v(n);
    root = new Node();
    for (int i = 0; i < n; i++) {
      init_set(root, i, v[i], 0, n);
    }
  }

  PersistentArray(int siz, T x) {
    n = siz;
    root = new Node();
    for (int i = 0; i < n; i++) {
      init_set(root, i, x, 0, n);
    }
  }

  PersistentArray(const vector<T> &v) {
    n = int(v.size());
    root = new Node();
    for (int i = 0; i < n; i++) {
      init_set(root, i, v[i], 0, n);
    }
  }

  T get(Node *ptr, int p) {
    return get(ptr, p, 0, n)->val;
  }

  Node *get_root() {
    return root;
  }

  Node *set(Node *ptr, int p, T x) {
    Node *new_root = new Node();
    Node *cur = new_root;
    int l = 0;
    int r = n;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (l <= p and p < m) {
        if (!cur->l) cur->l = new Node();
        cur->r = ptr->r;
        cur = cur->l;
        ptr = ptr->l;
        r = m;
      } else {
        if (!cur->r) cur->r = new Node();
        cur->l = ptr->l;
        cur = cur->r;
        ptr = ptr->r;
        l = m;
      }
    }
    cur->val = x;
    return new_root;
  }

 private:
  int n;

  Node *root;

  void init_set(Node *cur, int p, T x, int l, int r) {
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (l <= p and p < m) {
        if (!cur->l) cur->l = new Node();
        cur = cur->l;
        r = m;
      } else {
        if (!cur->r) cur->r = new Node();
        cur = cur->r;
        l = m;
      }
    }
    cur->val = x;
  }

  Node *get(Node *cur, int p, int l, int r) {
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (l <= p and p < m) {
        cur = cur->l;
        r = m;
      } else {
        cur = cur->r;
        l = m;
      }
    }
    return cur;
  }
};