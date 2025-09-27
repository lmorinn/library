#include "../../../../atcoder/modint.hpp"
#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../../../../data-structure/balanced-binary-search-tree/ReversibleLazySplayTree.hpp"

using namespace atcoder;
using mint = modint998244353;
struct S {
    mint val;
    int siz;
};

S op(S a, S b) {
    return S{a.val + b.val, a.siz + b.siz};
}

S e() {
    return {0, 0};
}

struct F {
    mint b, c;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    SplayTree<S, op, e, F, mapping, composition, id> t;

    int n, q;
    in(n, q);
    rep(i, n) {
        S a;
        a.siz = 1;
        int x;
        in(x);
        a.val = x;
        t.insert_at(i, a);
    }
    int len = n;

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int p, x;
            in(p, x);
            t.insert_at(p, {x, 1});
        } else if (com == 1) {
            int p;
            in(p);
            t.erase_at(p);
        } else if (com == 2) {
            int l, r;
            in(l, r);
            t.reverse(l, r);
        } else if (com == 3) {
            int l, r, b, c;
            in(l, r, b, c);
            t.apply(l, r, {b, c});
        } else if (com == 4) {
            int l, r;
            in(l, r);
            out(t.prod(l, r).val.val());
        }
    }
}