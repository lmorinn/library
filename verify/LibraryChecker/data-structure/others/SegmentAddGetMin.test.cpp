#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../../../data-structure/others/LiChaoTree.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    LiChaoTree t(-1e9, 1e9 + 1);
    int n, q;
    in(n, q);
    rep(i, n) {
        lint l, r, a, b;
        in(l, r, a, b);
        t.add_segment(l, r, a, b);
    }

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            lint l, r, a, b;
            in(l, r, a, b);
            t.add_segment(l, r, a, b);
        } else {
            lint p;
            in(p);
            lint res = t.get_min(p);
            if (res == LLONG_MAX) {
                out("INFINITY");
            } else {
                out(res);
            }
        }
    }
}
