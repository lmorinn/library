#include "../../../../atcoder/convolution.hpp"
#include "../../../../template/template.hpp"
using namespace atcoder;
#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../../../graph/tree/TreeDistanceFreqency.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    in(n);
    TreeDistFreq t(n);
    rep(i, n - 1) {
        int a, b;
        in(a, b);
        t.add_edge(a, b);
    }

    vector<long long> res = t.get_table();
    rep(i, 1, n) {
        cout << res[i] << ((i != n - 1) ? " " : "\n");
    }
}
