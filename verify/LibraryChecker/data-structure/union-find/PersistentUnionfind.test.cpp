#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../../../../data-structure/union-find/PersistentUnionFind.hpp"
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    PersistentUnionfind uf(n);
    vector<PersistentUnionfind::Node *> g(q + 1);
    g[0] = uf.get_root();

    rep(i, q) {
        int t, k, u, v;
        in(t, k, u, v);
        k++;
        if (t == 0) {
            g[i + 1] = uf.merge(g[k], u, v);
        } else {
            out(uf.same(g[k], u, v));
        }
    }
}
