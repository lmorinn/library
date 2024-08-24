#pragma once
template <class S, class F, auto mapping, auto composition, auto id>
struct DualSegmentTree {
   private:
    int n;
    vector<F> node;
    vector<S> ar;
    F ID;
    void Apply(int a, int b, F x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            node[k] = composition(x, node[k]);
            eval(k, l, r);
            return;
        }
        Apply(a, b, x, 2 * k + 1, l, (l + r) / 2);
        Apply(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }

    void eval(int k, int l, int r) {
        if (r - l > 1) {
            node[k * 2 + 1] = composition(node[k], node[k * 2 + 1]);
            node[k * 2 + 2] = composition(node[k], node[k * 2 + 2]);
        } else {
            ar[k - n + 1] = mapping(node[k], ar[k - n + 1]);
        }
        node[k] = ID;
    }

   public:
    DualSegmentTree() {}
    DualSegmentTree(vector<S> &v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, id());
        ar.resize(sz);
        for (int i = 0; i < sz; i++) {
            ar[i] = v[i];
        }
        ID = id();
    }

    void apply(int l, int r, F x) {
        Apply(l, r, x);
    }

    S get(int p) {
        S ret = ar[p];
        int l = p;
        int r = p + 1;
        p += (n - 1);
        F f = node[p];
        while (p > 0) {
            p = (p - 1) / 2;
            f = composition(node[p], f);
        }
        return mapping(f, ret);
    }

    F getf(int p) {
        p += (n - 1);
        F f = node[p];
        while (p > 0) {
            p = (p - 1) / 2;
            f = composition(node[p], f);
        }
        return f;
    }
};