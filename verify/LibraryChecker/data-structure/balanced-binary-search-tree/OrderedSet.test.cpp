#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "../../../../data-structure/balanced-binary-search-tree/AVLTree.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    AVLTree avl;
    int n, q;
    in(n, q);
    rep(i, n) {
        int a;
        in(a);
        avl.insert(a);
    }

    rep(i, q) {
        int t, x;
        in(t, x);
        if (t == 0) {
            avl.insert(x);
        } else if (t == 1) {
            avl.erase(x);
        } else if (t == 2) {
            out(avl.kth_element(x - 1));
        } else if (t == 3) {
            out(avl.less_count(x + 1));
        } else if (t == 4) {
            out(avl.upper_bound(x));
        } else if (t == 5) {
            out(avl.lower_bound(x));
        }
    }
}
