#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../../../../graph/connected-components/TwoEdgeConnectedComponents.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    in(n, m);
    TwoEdgeConnectedComponents g(n);

    rep(i, m) {
        int u, v;
        in(u, v);
        g.add_edge(u, v);
    }
    g.build();

    out(g.components.size());
    for (auto &v : g.components) {
        out(v.size(), v);
    }
}
