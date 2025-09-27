#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/7/ITP2_7_B"
#include "../../../../data-structure/balanced-binary-search-tree/RedBlackTree.hpp"
int main() {
    cin.tie(0)->sync_with_stdio(0);
    RedBlackTree t;
    int q;
    in(q);
    int siz = 0;
    rep(i, q) {
        int com, x;
        in(com, x);
        if (com == 0) {
            if (!t.contains(x)) {
                t.insert(x);
                siz++;
            }
            out(siz);
        } else if (com == 1) {
            out((t.contains(x) ? 1 : 0));
        } else {
            if (t.contains(x)) {
                t.erase(x);
                siz--;
            }
        }
    }
}
