#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../../../../data-structure/segment-tree/DualSegmentTree.hpp"

#define MOD 998244353
using S = lint;

struct F {
    lint a;
    lint b;
};

S mapping(F f, S x) {
    return ((x * f.a) % MOD + f.b) % MOD;
}

F composition(F f, F g) {
    return {(f.a * g.a) % MOD, ((f.a * g.b) % MOD + f.b) % MOD};
}

F id() {
    return {1, 0};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<S> a(n);
    in(a);
    DualSegmentTree<S, F, mapping, composition, id> seg(a);
    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int l, r;
            lint b, c;
            in(l, r, b, c);
            seg.apply(l, r, {b, c});
        } else {
            int p;
            in(p);
            out(seg.get(p));
        }
    }
}
