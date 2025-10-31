template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id, auto filled>
class DynamicLazySegmentTree {
   private:
    struct Node {
        S value;
        F lazy;
        Node* left;
        Node* right;
        Node(S value) : value(value), left(nullptr), right(nullptr), lazy(id()) {}
    };
    long long n;
    Node* root = nullptr;
    vector<S> identity;

    void set(S x, Node*& t, long long a, long long b, int d, long long l = 0, long long r = -1) {
        if (r < 0) r = n;
        if (!t) t = new Node(identity[d]);
        eval(t, l, r, d);
        if (r <= a or b <= l) return;

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

    void apply(Node*& t, F x, long long a, long long b, int d, long long l = 0, long long r = -1) {
        if (r < 0) r = n;
        if (!t) t = new Node(identity[d]);
        eval(t, l, r, d);
        if (r <= a or b <= l) return;
        if (a <= l and r <= b) {
            t->lazy = composition(x, t->lazy);
            eval(t, l, r, d);
        } else {
            long long m = (l + r) >> 1;
            apply(t->left, x, a, b, d + 1, l, m);
            apply(t->right, x, a, b, d + 1, m, r);
            t->value = op(t->left->value, t->right->value);
        }
    }

    S prod(Node*& t, long long a, long long b, int d, long long l = 0, long long r = -1) {
        if (r < 0) r = n;
        if (r <= a or b <= l) return e();
        if (!t) t = new Node(identity[d]);
        eval(t, l, r, d);
        if (a <= l and r <= b) {
            return t->value;
        }
        long long m = (l + r) >> 1ll;
        return op(prod(t->left, a, b, d + 1, l, m), prod(t->right, a, b, d + 1, m, r));
    }

    void eval(Node* t, long long l, long long r, int d) {
        if (!t) return;
        t->value = mapping(t->lazy, t->value);
        if (r - l > 1) {
            if (!t->left) t->left = new Node(identity[d + 1]);
            if (!t->right) t->right = new Node(identity[d + 1]);
            t->left->lazy = composition(t->lazy, t->left->lazy);
            t->right->lazy = composition(t->lazy, t->right->lazy);
        }
        t->lazy = id();
    }

   public:
    DynamicLazySegmentTree() {}
    DynamicLazySegmentTree(long long n_) {
        n = bit_ceil(uint64_t(n_));
        int log = bit_width(uint64_t(n));
        identity.resize(log);
        identity[log - 1] = filled();
        for (int i = log - 2; i >= 0; i--) {
            identity[i] = op(identity[i + 1], identity[i + 1]);
        }
    }
    void set(long long p, S x) {
        set(x, root, p, p + 1, 0);
    }

    S get(long long p) {
        return prod(root, p, p + 1, 0);
    }

    S prod(long long l, long long r) {
        return prod(root, l, r, 0);
    }

    void apply(long long l, long long r, F x) {
        apply(root, x, l, r, 0);
    }
};
