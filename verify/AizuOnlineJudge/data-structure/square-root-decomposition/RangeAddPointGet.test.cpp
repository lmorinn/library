#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../../data-structure/square-root-decomposition/RangeAddPointGet.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n);
    RangeAddPointGet<lint> w(a);

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            int l, r, x;
            in(l, r, x);
            l--;
            w.range_add(l, r, x);
        } else {
            int p;
            in(p);
            p--;
            out(w.get(p));
        }
    }
}
