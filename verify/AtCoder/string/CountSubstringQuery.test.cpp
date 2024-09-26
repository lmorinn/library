#include "../../../template/template.hpp"
#define PROBLEM "https://atcoder.jp/contests/abc362/tasks/abc362_g"
#include "../../../string/FMindex.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    in(s);
    FMindex f(s);
    int q;
    in(q);
    rep(i, q) {
        string t;
        in(t);
        out(f.substrCount(t));
    }
}
