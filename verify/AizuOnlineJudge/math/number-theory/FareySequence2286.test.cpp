#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2286"
#include "../../../../math/number-theory/EulersPhiFunctionTable.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    in(t);
    vector<int> table = Eulers_phi_function_table(1000001);
    vector<lint> sum(1000002, 0);
    sum[1] = 2;
    rep(i, 2, 1000001) {
        sum[i] = sum[i - 1] + table[i];
    }

    rep(i, t) {
        int n;
        in(n);
        out(sum[n]);
    }
}