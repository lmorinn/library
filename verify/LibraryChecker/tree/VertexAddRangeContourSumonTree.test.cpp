#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"
#include "../../../atcoder/fenwicktree.hpp"
using namespace atcoder;
#include "../../../graph/tree/CentroidDecompositionContourSum.hpp"

using S = lint;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    in(n, q);
    vector<S> a(n);
    in(a);
    CentroidDecomposition<S> t(n);

    rep(i, n - 1) {
        int u, v;
        in(u, v);
        t.add_edge(u, v);
    }

    t.build(a);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int p;
            S x;
            in(p, x);
            t.add(p, x);
        } else {
            int p, l, r;
            in(p, l, r);
            out(t.prod(p, l, r));
        }
    }
}
