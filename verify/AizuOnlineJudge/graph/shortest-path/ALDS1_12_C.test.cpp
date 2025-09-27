#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_C"

#include "../../../../graph/shortest-path/Dijkstra.hpp"


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    in(n);
    vector<vector<pair<int, lint>>> g(n);
    rep(i, n) {
        int u, k;
        in(u, k);
        rep(j, k) {
            int v, c;
            in(v, c);
            g[u].emplace_back(v, c);
        }
    }

    Dijkstra<lint> d(g);
    rep(i, n) {
        out(i, d.get_dist(i));
    }
}