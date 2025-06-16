template <class S, auto op, auto e>
class DynamicSegmentTree {
 private:
  struct Node {
    S value;
    Node *left;
    Node *right;
    Node(S value) : value(value), left(nullptr), right(nullptr) {}
  };
  long long n;
  Node *root = nullptr;

  void set(S x, Node *&t, long long a, long long b, long long l = 0, long long r = -1) {
    if (r < 0) r = n;
    if (r <= a or b <= l) return;
    if (!t) t = new Node(e());
    if (r - l == 1) {
      t->value = x;
      return;
    }
    long long m = (l + r) >> 1ll;
    set(x, t->left, a, b, l, m);
    set(x, t->right, a, b, m, r);
    if (t->left and t->right) {
      t->value = op(t->left->value, t->right->value);
    } else if (t->left) {
      t->value = t->left->value;
    } else if (t->right) {
      t->value = t->right->value;
    }
  }

  S prod(Node *&t, long long a, long long b, long long l = 0, long long r = -1) {
    if (r < 0) r = n;
    if (!t or r <= a or b <= l) return e();
    if (a <= l and r <= b) {
      return t->value;
    }
    long long m = (l + r) >> 1ll;
    return op(prod(t->left, a, b, l, m), prod(t->right, a, b, m, r));
  }

  template <auto f>
  long long max_right(bool &fin, S &p, Node *&t, long long a, long long l = 0, long long r = -1) {
    if (r < 0) r = n;
    if (l >= r) {
      fin = true;
      return r;
    }
    if (fin or r <= a) return l;
    if (!t) {
      S val = op(p, e());
      if (f(val)) {
        p = val;
        return r;
      } else {
        fin = true;
        return l;
      }
    }
    if (a <= l) {
      S val = op(p, t->value);
      if (f(val)) {
        p = val;
        return r;
      }
    }
    long long m = (l + r) >> 1ll;
    long long res = max_right<f>(fin, p, t->left, a, l, m);
    if (fin) return res;
    return max_right<f>(fin, p, t->right, a, m, r);
  }

 public:
  DynamicSegmentTree() {}
  DynamicSegmentTree(long long n_) {
    n = bit_ceil(uint64_t(n_));
  }
  void set(long long p, S x) {
    set(x, root, p, p + 1);
  }

  S get(long long p) {
    return prod(root, p, p + 1);
  }

  S prod(long long l, long long r) {
    return prod(root, l, r);
  }

  template <auto g>
  long long max_right(long long l) {
    S p = e();
    bool fin = false;
    return max_right<g>(fin, p, root, l);
  }
};