#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../../data-structure/square-root-decomposition/PointSetRangeMin.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n, (1ll << 31) - 1);
    PointSetRangeMin<lint> w(a);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int p, x;
            in(p, x);
            w.set(p, x);
        } else {
            int l, r;
            in(l, r);
            out(w.range_min(l, r + 1));
        }
    }
}
