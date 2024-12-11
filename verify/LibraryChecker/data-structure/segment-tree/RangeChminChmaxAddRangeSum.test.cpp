#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../../../data-structure/segment-tree/SegmentTreeBeatsChminChmax.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<lint> a(n);
    in(a);
    SegtreeBeats<lint> seg(a);

    rep(i, q) {
        int com, l, r;
        lint x;
        in(com, l, r);
        if (com == 0) {
            in(x);
            seg.range_chmin(l, r, x);
        } else if (com == 1) {
            in(x);
            seg.range_chmax(l, r, x);
        } else if (com == 2) {
            in(x);
            seg.range_add(l, r, x);
        } else if (com == 3) {
            out(seg.range_sum(l, r));
        }
    }
}
