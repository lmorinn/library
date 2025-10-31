#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"
#include "../../../../data-structure/segment-tree/DynamicLazySegmentTree.hpp"

using mint = modint998244353;
struct S {
    mint value;
    int size;
};

struct F {
    mint b;
    mint c;
};

const F ID = {mint(1), mint(0)};

S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }

S e() { return {mint(0), 0}; }

S mapping(F f, S x) {
    x.value = x.value * f.b + f.c * x.size;
    return x;
}

F composition(F g, F f) {
    return {f.b * g.b, g.b * f.c + g.c};
}

F id() { return ID; }

S filled() {
    return {mint(0), 1};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    DynamicLazySegmentTree<S, op, e, F, mapping, composition, id, filled> seg(n);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int l, r, b, c;
            in(l, r, b, c);
            seg.apply(l, r, {b, c});
        } else {
            int l, r;
            in(l, r);
            out(seg.prod(l, r).value.val());
        }
    }
}
