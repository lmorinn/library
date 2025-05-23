#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include "../../../../data-structure/square-root-decomposition/RangeSetRangeMin.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n, (1LL << 31) - 1);
    RangeSetRangeMin<lint> w(a);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int l, r, x;
            in(l, r, x);
            w.range_set(l, r + 1, x);
        } else {
            int l, r;
            in(l, r);
            out(w.range_min(l, r + 1));
        }
    }
}
