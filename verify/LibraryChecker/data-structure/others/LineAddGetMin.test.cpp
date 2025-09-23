#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../../data-structure/others/LiChaoTree.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    LiChaoTree t(-1e9, 1e9 + 1);
    int n, q;
    in(n, q);
    rep(i, n) {
        lint a, b;
        in(a, b);
        t.add_line(a, b);
    }

    rep(i, q) {
        int com;
        in(com);
        if (com == 0) {
            lint a, b;
            in(a, b);
            t.add_line(a, b);
        } else {
            lint p;
            in(p);
            out(t.get_min(p));
        }
    }
}
