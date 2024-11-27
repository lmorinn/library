#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../../data-structure/square-root-decomposition/PointSetRangeSum.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n, 0);
    PointSetRangeSum<lint> w(a);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int p, x;
            in(p, x);
            p--;
            w.add(p, x);
        } else {
            int l, r;
            in(l, r);
            l--;
            out(w.range_sum(l, r));
        }
    }
}
