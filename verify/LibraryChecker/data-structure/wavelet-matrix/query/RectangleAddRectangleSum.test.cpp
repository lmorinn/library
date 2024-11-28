#include "../../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "../../../../../atcoder/modint.hpp"
using mint = atcoder::modint998244353;
#include "../../../../../data-structure/wavelet-matrix/query/RectangleAddRectangleSum.hpp"
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<int> x1(n), y1(n), x2(n), y2(n), w(n);
    rep(i, n) {
        in(x1[i], y1[i], x2[i], y2[i], w[i]);
    }

    RectangleAddRectangleSum wm(x1, y1, x2, y2, w);

    rep(i, q) {
        int l, d, r, u;
        in(l, d, r, u);
        out(wm.rectangle_sum(l, d, r, u).val());
    }
}
