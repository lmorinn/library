#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#include "../../../../data-structure/square-root-decomposition/RangeAddRangeSum.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n);
    RangeAddRangeSum<lint> w(a);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int l, r, x;
            in(l, r, x);
            l--;
            w.range_add(l, r, x);
        } else {
            int l, r;
            in(l, r);
            l--;
            out(w.range_sum(l, r));
        }
    }
}
