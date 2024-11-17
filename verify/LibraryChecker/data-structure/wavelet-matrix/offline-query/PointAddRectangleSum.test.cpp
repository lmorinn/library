#include "../../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../../../../../data-structure/wavelet-matrix/offline-query/PointAddRectangleSum.hpp"

using S = lint;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    in(n, q);

    vector<S> x(n), y(n), w(n);
    rep(i, n) {
        in(x[i], y[i], w[i]);
    }
    PointAddRectangleSum<S> t(x, y, w, q);

    rep(i, q) {
        int com;
        lint a, b, c, d;
        in(com);
        if (com == 0) {
            in(a, b, c);
            t.add(a, b, c);
        } else {
            in(a, b, c, d);
            t.rectangle_sum(a, b, c, d);
        }
    }

    for (const S &res : t.build()) out(res);
}
