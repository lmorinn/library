
class SCC {
   private:
    vector<vector<int>> g, r;
    int time;
    int n;
    vector<bool> seen, seen2;
    vector<int> idx;
    int component_id;
    vector<vector<int>> components;

    void dfs(int cur) {
        seen[cur] = true;
        for (auto nex : g[cur]) {
            if (seen[nex] == false) {
                dfs(nex);
            }
        }
        idx[time] = cur;
        time++;
    }

    void dfs2(int cur) {
        seen2[cur] = true;
        components[component_id].emplace_back(cur);
        for (auto nex : r[cur]) {
            if (seen2[nex] == false) {
                dfs2(nex);
            }
        }
    }

   public:
    SCC() {}
    SCC(int siz) {
        n = siz;
        g.resize(n);
        r.resize(n);
        time = 0;
        component_id = 0;
        idx.assign(n, -1);
        seen.assign(n, false);
        seen2.assign(n, false);
    }

    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        r[v].emplace_back(u);
    }

    vector<vector<int>> decompose() {
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                dfs(i);
            }
        }

        for (int i = time - 1; i >= 0; i--) {
            if (!seen2[idx[i]]) {
                components.emplace_back(vector<int>());
                dfs2(idx[i]);
                component_id++;
            }
        }

        return components;
    }
};