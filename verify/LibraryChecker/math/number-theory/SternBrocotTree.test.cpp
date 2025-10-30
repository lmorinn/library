#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"
#include "../../../../math/number-theory/SternBrocotTree.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    in(t);
    rep(i, t) {
        string q;
        in(q);
        if (q == "ENCODE_PATH") {
            int a, b;
            in(a, b);
            auto res = encode_path(a, b);
            if (res.empty()) {
                out(0);
            } else {
                cout << res.size() << " ";
                rep(j, res.size()) {
                    cout << res[j].first << " " << res[j].second;
                    if (j + 1 != res.size()) {
                        cout << " ";
                    } else {
                        cout << "\n";
                    }
                }
            }
        } else if (q == "DECODE_PATH") {
            int k;
            in(k);
            vector<pair<char, int>> path(k);
            rep(j, k) {
                in(path[j].first, path[j].second);
            }
            auto res = decode_path(path);
            out(res.first, res.second);
        } else if (q == "LCA") {
            int a, b, c, d;
            in(a, b, c, d);
            auto res = sbt_lca(a, b, c, d);
            out(res.first, res.second);
        } else if (q == "ANCESTOR") {
            int k, a, b;
            in(k, a, b);
            auto res = sbt_ancestor(k, a, b);
            if (res.first == -1) {
                out(-1);
            } else {
                out(res.first, res.second);
            }
        } else {
            int a, b;
            in(a, b);
            auto res = sbt_range(a, b);
            out(res[0].first, res[0].second, res[1].first, res[1].second);
        }
    }
}