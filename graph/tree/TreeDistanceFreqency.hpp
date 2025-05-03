
class TreeDistFreq {
   private:
    vector<vector<int>> g;
    vector<bool> dead;
    int n;

    int find_centroid(int root) {
        static vector<int> subtree_size(g.size());
        function<void(int, int)> subtree_size_dp = [&](int u, int prev) {
            subtree_size[u] = 1;
            for (int v : g[u]) {
                if (v != prev and !dead[v]) {
                    subtree_size_dp(v, u);
                    subtree_size[u] += subtree_size[v];
                }
            }
        };
        subtree_size_dp(root, -1);
        int n = subtree_size[root];
        function<int(int, int)> dfs = [&](int u, int prev) {
            for (int v : g[u]) {
                if (v != prev and !dead[v]) {
                    if (subtree_size[v] > n / 2) {
                        return dfs(v, u);
                    }
                }
            }
            return u;
        };

        return dfs(root, -1);
    }

    vector<long long> centroid_decomposition(int start) {
        vector<long long> ans(g.size());
        function<void(int)> rec = [&](int start) {
            int c = find_centroid(start);
            dead[c] = true;
            for (int u : g[c]) {
                if (!dead[u]) rec(u);
            }
            vector<vector<long long>> subtree_dist;

            int alive_sub = 0;
            for (int u : g[c]) {
                if (!dead[u]) {
                    subtree_dist.emplace_back();
                    calc_freq(c, u, subtree_dist[alive_sub]);
                    for (int i = 0; i < int(subtree_dist[alive_sub].size()); i++) {
                        ans[i] += subtree_dist[alive_sub][i];
                    }
                    alive_sub++;
                }
            }

            sort(subtree_dist.begin(), subtree_dist.end(), [](const vector<long long> &a, const vector<long long> &b) {
                return int(a.size()) < int(b.size());
            });

            if (alive_sub >= 2) {
                vector<long long> l = subtree_dist[0];
                for (int i = 0; i < alive_sub - 1; i++) {
                    int idx = 0;
                    for (long long x : convolution_ll(l, subtree_dist[i + 1])) {
                        ans[idx] += x;
                        idx++;
                        if (idx == n) break;
                    }
                    int nex_size = subtree_dist[i + 1].size();
                    l.resize(nex_size);
                    for (int j = 0; j < nex_size; j++) {
                        l[j] += subtree_dist[i + 1][j];
                    }
                }
            }
            dead[c] = false;
        };
        rec(0);
        return ans;
    }

    void calc_freq(int c, int u, vector<long long> &freq) {
        freq.resize(2);
        freq[1] = 1;
        auto dfs = [&](auto &&self, int v, int prev, int dist) -> void {
            for (int nex : g[v]) {
                if (nex != prev and !dead[nex]) {
                    if (int(freq.size()) <= dist + 1) {
                        freq.emplace_back(1);
                    } else {
                        freq[dist + 1]++;
                    }
                    self(self, nex, v, dist + 1);
                }
            }
        };
        dfs(dfs, u, c, 1);
    }

   public:
    TreeDistFreq(int siz) {
        n = siz;
        g.resize(n);
        dead.resize(n, false);
    }
    TreeDistFreq() {}

    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<long long> get_table() {
        return centroid_decomposition(0);
    }
};