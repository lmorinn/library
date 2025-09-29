#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C"
#include "../../../dp/KnapsackProblemNoLimit.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, W;
    in(n, W);
    vector<int> v(n), w(n);
    rep(i, n) in(v[i], w[i]);
    vector<int> res = knapsack<int>(w, v, W);
    int ans = 0;
    for (auto x : res) chmax(ans, x);
    out(ans);
}