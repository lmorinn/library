#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"
#include "../../../string/RollingHash.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string t, p;
    in(t, p);
    int n = t.size();
    int m = p.size();

    if (n < m) return 0;

    RollingHash tmp(p);
    int64_t h = tmp.range_hash(0, m);

    RollingHash rh(t);

    rep(i, n - m + 1) {
        if (rh.range_hash(i, i + m) == h) {
            out(i);
        }
    }
}
