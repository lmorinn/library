#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450"
#include "../../../../graph/dynamic-tree/LinkCutTreeVertex.hpp"

struct S {
    lint val;
    lint siz;
    lint lmx;
    lint rmx;
    lint mx;
};

using T = lint;
using F = lint;
F ID = -1e17;

S op(S a, S b) {
    if (a.lmx == ID) return b;
    if (b.lmx == ID) return a;
    S ret;
    ret.val = a.val + b.val;
    ret.siz = a.siz + b.siz;
    ret.lmx = max(a.val + b.lmx, a.lmx);
    ret.rmx = max(b.val + a.rmx, b.rmx);
    ret.mx = max({a.mx, b.mx, a.rmx + b.lmx, ret.rmx, ret.lmx});
    return ret;
}

S e() {
    return {0, 0, ID, ID, ID};
}

S mapping(F f, S x) {
    if (f != ID) {
        x.val = f * x.siz;
        x.mx = x.lmx = x.rmx = max(f, f * x.siz);
    }
    return x;
}

F composition(F f, F g) {
    return (f == ID ? g : f);
}

F id() {
    return ID;
}

void reverseprod(S &node) {
    swap(node.lmx, node.rmx);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    in(n, q);
    vector<S> nodew(n);
    rep(i, n) {
        lint c;
        in(c);
        nodew[i] = {c, 1, c, c, c};
    }
    LinkCutTree<S, op, e, F, mapping, composition, id, reverseprod> t(nodew);

    rep(i, n - 1) {
        int u, v;
        in(u, v);
        u--;
        v--;
        t.add(u, v);
    }

    rep(i, q) {
        lint c;
        int com, u, v;
        in(com, u, v, c);
        u--;
        v--;
        if (com == 1) {
            t.apply(u, v, c);
        } else {
            out(t.prod(u, v).mx);
        }
    }
}
