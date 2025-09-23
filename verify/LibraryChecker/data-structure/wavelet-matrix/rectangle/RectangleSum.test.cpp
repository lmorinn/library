#include "../../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../../../../../data-structure/wavelet-matrix/rectangle/RectangleSum.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<int> x(n), y(n);
    vector<lint> w(n);
    rep(i, n) {
        in(x[i], y[i], w[i]);
    }

    RectangleSum<int, lint> wm(x, y, w);

    rep(i, q) {
        int l, d, r, u;
        in(l, d, r, u);
        out(wm.rectangle_sum(l, r, d, u));
    }
}
