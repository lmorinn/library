template <class S, auto op, auto e>
class persistent_segtree {
   private:
    vector<S> node;
    vector<int> l_id, r_id;
    int id = 0;
    int n, root;
    int NODE_SIZE = 20000000;

    inline int newleaf(S x) {
        int pos = id++;
        node[pos] = x;
        return pos;
    }

    inline int newparent(int l, int r) {
        int pos = id++;
        l_id[pos] = l;
        r_id[pos] = r;
        node[pos] = op(node[l], node[r]);
        return pos;
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

    S prod_query(int a, int b, int root_id, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= a or b <= l) return e();
        if (a <= l and r <= b) return node[root_id];
        int mid = (l + r) >> 1;
        return op(prod_query(a, b, l_id[root_id], l, mid), prod_query(a, b, r_id[root_id], mid, r));
    }

    int rollback_query(int a, int b, int root, int old_root, int l = 0, int r = -1) {
        if (r == -1) r = n;
        if (r <= a or b <= l) return root;
        if (a <= l and r <= b) return old_root;
        return newparent(rollback_query(a, b, l_id[root], l_id[old_root], l, (l + r) >> 1), rollback_query(a, b, r_id[root], r_id[old_root], (l + r) >> 1, r));
    }

   public:
    persistent_segtree() {}
    persistent_segtree(const vector<S> &v) {
        node.resize(NODE_SIZE);
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

    S prod(int l, int r, int root_id) {
        return prod_query(l, r, root_id);
    }

    S get(int p, int root_id) {
        return prod(p, p + 1, root_id);
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
