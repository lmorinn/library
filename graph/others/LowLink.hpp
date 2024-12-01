class LowLink {
   public:
    int n, time;
    vector<vector<pair<int, int>>> g;
    vector<bool> seen;
    vector<int> order, low;
    vector<int> articulation;
    vector<int> bridge;

    LowLink(int _n) : n(_n), time(0) {
        g.resize(n);
        seen.assign(n, false);
        order.assign(n, -1);
        low.assign(n, 0);
    }

    void add_edge(int u, int v, int eid) {
        g[u].emplace_back(v, eid);
        g[v].emplace_back(u, eid);
    }

    void dfs(int cur, int prev, int prev_eid) {
        seen[cur] = true;
        order[cur] = low[cur] = time++;
        int child = 0;
        bool is_articulation = false;
        for (auto &[nex, eid] : g[cur]) {
            if (!seen[nex]) {
                child++;
                dfs(nex, cur, eid);
                low[cur] = min(low[cur], low[nex]);
                if (prev != -1 and order[cur] <= low[nex]) is_articulation = true;
                if (order[cur] < low[nex]) bridge.push_back(eid);
            } else if (eid != prev_eid) {
                low[cur] = min(low[cur], order[nex]);
            }
        }
        if (prev == -1 and child > 1) is_articulation = true;
        if (is_articulation) articulation.push_back(cur);
    }

    void build() {
        for (int i = 0; i < n; i++) {
            if (!seen[i]) dfs(i, -1, -1);
        }
    }
};