#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"
#include "../../../../data-structure/segment-tree/DynamicSegmentTree.hpp"

using mint = modint998244353;
struct S {
    mint a, b;
};

S op(S x, S y) {
    return {x.a * y.a, x.b * y.a + y.b};
}

S e() { return {1, 0}; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    in(n, q);
    DynamicSegmentTree<S, op, e> seg(n);
    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int p, c, d;
            in(p, c, d);
            seg.set(p, {c, d});
        } else {
            int l, r, x;
            in(l, r, x);
            S ret = seg.prod(l, r);
            out((ret.a * x + ret.b).val());
        }
    }
}
