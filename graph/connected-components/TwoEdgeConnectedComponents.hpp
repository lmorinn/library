#include "../others/LowLink.hpp"

class TwoEdgeConnectedComponents {
   private:
    int n;
    int m;
    int eid;
    vector<pair<int, int>> edges;
    LowLink l;

    void dfs(int v, int prev, int prev_eid, const vector<bool> &is_bridge, int cid) {
        cmp[v] = cid;
        for (auto &[nex, eid] : l.g[v]) {
            if (cmp[nex] == -1 and !is_bridge[eid]) {
                dfs(nex, v, eid, is_bridge, cid);
            }
        }
    }

   public:
    vector<int> cmp;
    vector<vector<int>> components;

    TwoEdgeConnectedComponents(int _n) : n(_n), l(_n), eid(0) {
        cmp.assign(n, -1);
    }

    void add_edge(int u, int v) {
        l.add_edge(u, v, eid);
        edges.emplace_back(u, v);
        eid++;
    }

    void build() {
        l.build();
        vector<bool> is_bridge(eid, false);
        for (int id : l.bridge) is_bridge[id] = true;

        int cid = 0;
        for (int i = 0; i < n; i++) {
            if (cmp[i] == -1) {
                dfs(i, -1, -1, is_bridge, cid++);
            }
        }
        components.resize(cid);
        for (int i = 0; i < n; i++) {
            components[cmp[i]].push_back(i);
        }
    }
};