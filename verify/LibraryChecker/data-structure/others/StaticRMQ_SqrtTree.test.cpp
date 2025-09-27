#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../../data-structure/others/SqrtTree.hpp"

using S = int;
S op(S a, S b) {
    return min(a, b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<int> a(n);
    in(a);
    SqrtTree<S, op> t(a);

    rep(i, q) {
        int l, r;
        in(l, r);
        out(t.prod(l, r));
    }
}
