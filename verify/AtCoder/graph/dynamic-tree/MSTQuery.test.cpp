#include "../../../../template/template.hpp"
#define PROBLEM "https://atcoder.jp/contests/abc355/tasks/abc355_f"
#include "../../../../graph/dynamic-tree/LinkCutTreeEdge.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    ull sum = 0;
    vector<S> nodew(n, {0, -1, -1});
    LinkCutTree l(nodew);
    rep(i, n - 1) {
        ull a, b, c;
        in(a, b, c);
        a--;
        b--;
        l.add(a, b, c);
        sum += c;
    }
    rep(i, q) {
        ull u, v, w;
        in(u, v, w);
        u--;
        v--;
        S path = l.prod(u, v);
        if (path.val > w) {
            l.erase(path.u, path.v);
            l.add(u, v, w);
            sum -= path.val;
            sum += w;
        }
        out(sum);
    }
}
