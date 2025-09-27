template <class S, auto op, auto e, auto put_vertex, auto put_edge>
class Rerooting {
   private:
    int n;
    vector<vector<int>> idx;
    vector<vector<int>> g, e_id, rev_id;
    vector<vector<S>> dp, acc_r;
    vector<S> ans;

    S postorder_dfs(int u, int prev = -1) {
        S res = e();
        int deg = int(g[u].size());
        dp[u].resize(deg, e());
        for (int i = 0; i < deg; i++) {
            int v = g[u][i];
            if (v == prev) continue;
            dp[u][i] = put_edge(postorder_dfs(v, u), e_id[u][i]);
            res = op(res, dp[u][i]);
        }
        return put_vertex(res, u);
    }

    void preorder_dfs(int u, int prev = -1) {
        int deg = int(g[u].size());
        acc_r[u].resize(deg + 1, e());
        S acc_l = e();
        for (int i = deg - 1; i >= 0; i--) {
            acc_r[u][i] = op(acc_r[u][i + 1], dp[u][i]);
        }
        ans[u] = put_vertex(acc_r[u][0], u);

        for (int i = 0; i < deg; i++) {
            int v = g[u][i];
            if (v != prev) {
                dp[v][idx[u][i]] = put_edge(put_vertex(op(acc_l, acc_r[u][i + 1]), u), e_id[v][idx[u][i]]);
                preorder_dfs(v, u);
            }
            acc_l = op(acc_l, dp[u][i]);
        }
    }

   public:
    Rerooting(int n) : n(n) {
        g.resize(n);
        idx.resize(n);
        dp.resize(n);
        acc_r.resize(n);
        ans.resize(n);
        e_id.resize(n);
        rev_id.resize(n);
    }

    void add_edge(int u, int v, int u_v_id, int v_u_id) {
        idx[u].emplace_back(int(g[v].size()));
        idx[v].emplace_back(int(g[u].size()));
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        e_id[u].emplace_back(u_v_id);
        e_id[v].emplace_back(v_u_id);
    }

    vector<S> build() {
        postorder_dfs(0);
        preorder_dfs(0);
        return ans;
    }
};