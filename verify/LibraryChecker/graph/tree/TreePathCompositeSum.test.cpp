#include "../../../../atcoder/modint.hpp"
#include "../../../../template/template.hpp"
using namespace atcoder;
#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include "../../../../graph/tree/Rerooting.hpp"

using mint = modint998244353;

struct S {
    mint val;
    int sub;
};

vector<int> a, b, c;

S op(S a, S b) {
    return {a.val + b.val, a.sub + b.sub};
}

S e() {
    return {0, 0};
}

S put_vertex(S x, int i) {
    return {x.val + a[i], x.sub + 1};
}

S put_edge(S x, int i) {
    return {x.val * b[i] + mint(x.sub) * c[i], x.sub};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    in(n);
    a.resize(n);
    b.resize(n - 1);
    c.resize(n - 1);
    in(a);

    Rerooting<S, op, e, put_vertex, put_edge> t(n);
    rep(i, n - 1) {
        int u, v;
        in(u, v, b[i], c[i]);
        t.add_edge(u, v, i, i);
    }

    vector<int> res;
    for (auto [v, s] : t.build()) {
        res.emplace_back(v.val());
    }
    out(res);
}
