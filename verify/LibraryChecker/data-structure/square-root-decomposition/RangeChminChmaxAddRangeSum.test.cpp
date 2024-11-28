#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../../../data-structure/square-root-decomposition/RangeChminChmaxAddRangeSum.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n);
    in(a);
    RangeChminChmaxAddRangeSum<lint> rc(a);
    while (q--) {
        int tp, l, r;
        in(tp, l, r);
        if (tp == 0) {
            lint x;
            in(x);
            rc.range_chmin(l, r, x);
        } else if (tp == 1) {
            lint x;
            in(x);
            rc.range_chmax(l, r, x);
        } else if (tp == 2) {
            lint x;
            in(x);
            rc.range_add(l, r, x);
        } else {
            out(rc.range_sum(l, r));
        }
    }
}
