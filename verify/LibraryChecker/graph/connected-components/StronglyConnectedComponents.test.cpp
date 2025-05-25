#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../../../graph/connected-components/StronglyConnectedComponents.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    in(n, m);
    SCC g(n);

    rep(i, m) {
        int a, b;
        in(a, b);
        g.add_edge(a, b);
    }

    auto res = g.decompose();
    out(res.size());
    for (auto v : res) {
        out(v.size(), v);
    }
}
