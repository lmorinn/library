class GraphReachability {
   private:
    vector<vector<int>> r;
    queue<pair<int, int>> q;
    vector<int> compress_id;
    SCC s;
    int n;

   public:
    GraphReachability(const vector<vector<int>> &v) {
        int siz = v.size();
        s = SCC(siz);
        compress_id.resize(siz);
        for (int i = 0; i < siz; i++) {
            for (auto j : v[i]) {
                s.add_edge(i, j);
            }
        }

        vector<vector<int>> components = s.decompose();
        for (int i = 0; i < components.size(); i++) {
            for (int idx : components[i]) {
                compress_id[idx] = i;
            }
        }

        n = components.size();
        r.resize(n);

        for (int i = 0; i < siz; i++) {
            for (auto j : v[i]) {
                if (compress_id[i] != compress_id[j]) {
                    r[compress_id[j]].emplace_back(compress_id[i]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            sort(r[i].begin(), r[i].end());
            r[i].erase(unique(r[i].begin(), r[i].end()), r[i].end());
        }
    }

    void is_reachable(int from, int to) {
        q.emplace(from, to);
    }

    vector<bool> build() {
        vector<bool> res(int(q.size()));
        int res_idx = 0;
        int cnt = 0;
        vector<unsigned long long> dp(n);
        vector<int> goal(64);

        while (!q.empty()) {
            int a = compress_id[q.front().first];
            int b = compress_id[q.front().second];
            q.pop();
            dp[a] |= (1ULL << cnt);
            goal[cnt] = b;
            cnt++;
            if (cnt == 64 or q.empty()) {
                for (int i = 0; i < n; i++) {
                    for (int prev : r[i]) {
                        dp[i] |= dp[prev];
                    }
                }
                for (int i = 0; i < cnt; i++) {
                    if (dp[goal[i]] & (1ULL << i)) {
                        res[res_idx] = true;
                    } else {
                        res[res_idx] = false;
                    }
                    res_idx++;
                }

                for (int i = 0; i < n; i++) {
                    dp[i] = 0;
                }
                cnt = 0;
            }
        }

        return res;
    }
};