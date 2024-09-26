#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_D"
#include "../../../string/FMindex.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string t;
    in(t);
    FMindex f(t);
    int q;
    in(q);
    rep(i, q) {
        string p;
        in(p);
        out(f.substrCount(p) != 0);
    }
}
