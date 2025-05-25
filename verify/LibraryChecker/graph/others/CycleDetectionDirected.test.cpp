#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "../../../../graph/others/CycleDetection.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    in(n, m);
    CycleDetection<int> g(n, true);
    rep(i, m) {
        int u, v;
        in(u, v);
        g.add_edge(u, v, i);
    }

    auto res = g.cycle();
    int len = res.size();
    if (len == 0) {
        out(-1);
    } else {
        out(len);
        rep(i, len) {
            out(res[i].val);
        }
    }
}
