#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D"
#include "../../../dp/SlidingWindowMinimum.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, l;
    in(n, l);
    vector<int> a(n);
    in(a);
    out(sliding_window_minimum(a, l));
}