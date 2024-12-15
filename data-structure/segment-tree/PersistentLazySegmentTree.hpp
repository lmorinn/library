
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
class persistent_lazy_segtree {
   private:
    vector<S> node;
    vector<F> lazy;

    vector<int> l_id, r_id;
    int idx = 0;
    int n, root;
    int NODE_SIZE = 45000000;

    inline int newleaf(S x) {
        int pos = idx++;
        node[pos] = x;
        return pos;
    }

    inline int newparent(int l, int r) {
        int pos = idx++;
        l_id[pos] = l;
        r_id[pos] = r;
        node[pos] = op(node[l], node[r]);
        return pos;
    }

    inline int newlazy(int node_id, F f, int l, int r) {
        int pos = idx++;
        l_id[pos] = l_id[node_id];
        r_id[pos] = r_id[node_id];
        lazy[pos] = composition(f, lazy[node_id]);
        node[pos] = mapping(f, node[node_id]);

        return pos;
    }

    inline void push(int root_id, int l, int r) {
        if (l + 1 < r and lazy[root_id] != id()) {
            l_id[root_id] = newlazy(l_id[root_id], lazy[root_id], l, (l + r) >> 1);
            r_id[root_id] = newlazy(r_id[root_id], lazy[root_id], (l + r) >> 1, r);
            lazy[root_id] = id();
        }
    }

    int build(const vector<S> &v, int l, int r) {
        if (r - l == 1) {
            return newleaf(v[l]);
        } else {
            return newparent(build(v, l, (l + r) >> 1), build(v, (l + r) >> 1, r));
        }
    }

    int set_query(int i, S x, int root_id, int l, int r) {
        if (r - l == 1) {
            return newleaf(x);
        }
        int mid = (l + r) >> 1;
        if (i < mid) {
            return newparent(set_query(i, x, l_id[root_id], l, mid), r_id[root_id]);
        } else {
            return newparent(l_id[root_id], set_query(i, x, r_id[root_id], mid, r));
        }
    }

    int apply_query(int a, int b, F f, int root_id, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= a or b <= l) return root_id;
        if (a <= l and r <= b) return newlazy(root_id, f, l, r);
        push(root_id, l, r);
        int mid = (l + r) >> 1;
        return newparent(apply_query(a, b, f, l_id[root_id], l, mid), apply_query(a, b, f, r_id[root_id], mid, r));
    }

    S prod_query(int a, int b, int root_id, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= a or b <= l) return e();
        if (a <= l and r <= b) return node[root_id];
        push(root_id, l, r);
        int mid = (l + r) >> 1;
        return op(prod_query(a, b, l_id[root_id], l, mid), prod_query(a, b, r_id[root_id], mid, r));
    }

    S get_query(int i, int root_id, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r - l == 1) return node[root_id];
        push(root_id, l, r);

        int mid = (l + r) >> 1;
        if (i < mid) {
            return get_query(i, l_id[root_id], l, mid);
        } else {
            return get_query(i, r_id[root_id], mid, r);
        }
    }

    int rollback_query(int a, int b, int root, int old_root, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= a or b <= l) return root;
        if (a <= l and r <= b) return old_root;
        push(root, l, r);
        push(old_root, l, r);
        return newparent(rollback_query(a, b, l_id[root], l_id[old_root], l, (l + r) >> 1), rollback_query(a, b, r_id[root], r_id[old_root], (l + r) >> 1, r));
    }

   public:
    persistent_lazy_segtree() {}
    persistent_lazy_segtree(const vector<S> &v) {
        node.resize(NODE_SIZE);
        lazy.resize(NODE_SIZE, id());
        l_id.resize(NODE_SIZE);
        r_id.resize(NODE_SIZE);
        n = v.size();
        root = build(v, 0, n);
    }

    int get_root() {
        return root;
    }

    int set(int p, S x, int root_id) {
        return set_query(p, x, root_id, 0, n);
    }

    int apply(int l, int r, F f, int root_id) {
        return apply_query(l, r, f, root_id, 0, n);
    }

    S prod(int l, int r, int root_id) {
        return prod_query(l, r, root_id);
    }

    S get(int p, int root_id) {
        return get_query(p, root_id);
    }

    int rollback(int a, int b, int root_id, int old_root) {
        return rollback_query(a, b, root_id, old_root, 0, n);
    }

    vector<S> status(int root_id) {
        vector<S> res(n);

        for (int i = 0; i < n; i++) {
            res[i] = get(i, root_id);
        }
        return res;
    }
};