#include "../../../../../template/template.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0489"
#include "../../../../../data-structure/wavelet-matrix/query/WaveletMatrixonHeavyLightDecomposition.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    in(n, m);
    vector<int> nodew(n);
    in(nodew);

    vector<vector<pair<int, int>>> g(n);
    rep(i, n - 1) {
        int s, t;
        in(s, t);
        s--;
        t--;
        g[s].emplace_back(t, 1);
        g[t].emplace_back(s, 1);
    }

    vector<vector<int>> q(m, vector<int>(4));
    rep(i, m) {
        int op, u, v, w, k;
        in(op);
        q[i][0] = op;

        if (op == 1) {
            in(u, w);
            u--;
            q[i][1] = u;
            q[i][2] = w;
            nodew.emplace_back(w);
            g.push_back(vector<pair<int, int>>());
            int newid = g.size() - 1;
            g[newid].emplace_back(u, 1);
            g[u].emplace_back(newid, 1);
        } else if (op == 2) {
            in(u, v, k);
            u--;
            v--;
            k--;
            q[i][1] = u;
            q[i][2] = v;
            q[i][3] = k;
        }
    }

    hld_wavelet<int> h(g, nodew);

    rep(i, m) {
        int op = q[i][0];
        if (op == 2) {
            int u = q[i][1];
            int v = q[i][2];
            int k = q[i][3];
            out(h.kth_path(u, v, k));
        }
    }
}