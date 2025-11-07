
class LiChaoTree {
   private:
    struct Node {
        long long a, b;
        Node* left;
        Node* right;
        Node(long long a, long long b) : a(a), b(b), left(nullptr), right(nullptr) {}
    };
    long long lower_x, upper_x;
    Node* root = nullptr;

    inline long long f(long long a, long long b, long long x) {
        return a * x + b;
    }

    void add_line(long long line_a, long long line_b, Node*& t, long long l, long long r) {
        if (!t) {
            t = new Node(line_a, line_b);
            return;
        }

        if (r - l == 1) {
            if (f(line_a, line_b, l) > f(t->a, t->b, l)) {
                t->a = line_a;
                t->b = line_b;
            }
            return;
        }
        long long m = (l + r) >> 1ll;

        bool left_max = f(line_a, line_b, l) > f(t->a, t->b, l);
        bool mid_max = f(line_a, line_b, m) > f(t->a, t->b, m);
        bool right_max = f(line_a, line_b, r) > f(t->a, t->b, r);

        if (left_max and right_max) {
            t->a = line_a;
            t->b = line_b;
            return;
        }
        if (!left_max and !right_max) {
            return;
        }

        if (mid_max) {
            swap(t->a, line_a);
            swap(t->b, line_b);
        }
        if (left_max != mid_max) {
            add_line(line_a, line_b, t->left, l, m);
        } else {
            add_line(line_a, line_b, t->right, m, r);
        }
    }

    void add_segment(long long line_a, long long line_b, Node*& t, long long a, long long b, long long l, long long r) {
        if (r <= a or b <= l) return;
        if (!t) t = new Node(0, LLONG_MIN);

        long long m = (l + r) >> 1ll;
        if (!(a <= l and r <= b)) {
            add_segment(line_a, line_b, t->left, a, b, l, m);
            add_segment(line_a, line_b, t->right, a, b, m, r);
            return;
        }
        if (t->a == 0 and t->b == LLONG_MIN) {
            t->a = line_a;
            t->b = line_b;
        } else {
            add_line(line_a, line_b, t, l, r);
        }
    }

    long long get_max(long long x, Node* t, long long l, long long r) {
        if (!t) return LLONG_MIN;
        long long y = f(t->a, t->b, x);
        if (r - l == 1) return y;
        long long m = (l + r) >> 1ll;
        if (x < m) {
            return max(y, get_max(x, t->left, l, m));
        } else {
            return max(y, get_max(x, t->right, m, r));
        }
    }

   public:
    LiChaoTree() {}
    LiChaoTree(long long lower_x, long long upper_x) : lower_x(lower_x), upper_x(upper_x) {
    }

    void add_line(long long a, long long b) {
        add_line(a, b, root, lower_x, upper_x);
    }

    void add_segment(long long l, long long r, long long a, long long b) {
        add_segment(a, b, root, l, r, lower_x, upper_x);
    }

    long long get_max(long long x) {
        return get_max(x, root, lower_x, upper_x);
    }
};