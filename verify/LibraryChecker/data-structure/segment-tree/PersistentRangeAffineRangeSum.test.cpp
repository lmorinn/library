#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_range_affine_range_sum"
#include "../../../../data-structure/segment-tree/PersistentLazySegmentTree.hpp"

struct S {
    modint998244353 val;
    int siz;
};

S op(S a, S b) {
    return {a.val + b.val, a.siz + b.siz};
}

S e() {
    return {0, 0};
}

struct F {
    modint998244353 b, c;
};

S mapping(F f, S x) {
    return {f.b * x.val + f.c * x.siz, x.siz};
}

F composition(F g, F f) {
    return {g.b * f.b, g.b * f.c + g.c};
}

F id() {
    return {1, 0};
}

bool operator!=(F a, F b) {
    if (a.b != b.b or a.c != b.c) return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<S> v(n);
    rep(i, n) {
        int a;
        in(a);
        v[i] = {a, 1};
    }

    unordered_map<int, int> idx;
    persistent_lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    idx[-1] = seg.get_root();

    rep(i, q) {
        int com, k, l, r, b, c, s;
        in(com, k);
        if (com == 0) {
            in(l, r, b, c);
            idx[i] = seg.apply(l, r, {b, c}, idx[k]);
        } else if (com == 1) {
            in(s, l, r);
            idx[i] = seg.rollback(l, r, idx[k], idx[s]);
        } else if (com == 2) {
            in(l, r);
            out(seg.prod(l, r, idx[k]).val.val());
        }
    }
}
