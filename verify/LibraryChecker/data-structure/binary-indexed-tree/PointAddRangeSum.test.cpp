#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../../../data-structure/binary-indexed-tree/BinaryIndexedTree.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    fenwick_tree<lint> f(n);

    rep(i, n) {
        lint a;
        in(a);
        f.add(i, a);
    }

    rep(i, q) {
        int com, p, l, r;
        lint x;
        in(com);
        if (com == 0) {
            in(p, x);
            f.add(p, x);
        } else {
            in(l, r);
            out(f.sum(l, r));
        }
    }
}
