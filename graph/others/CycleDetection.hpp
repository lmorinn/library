template <class T>
class CycleDetection {
   private:
    struct Edge {
        int from = -1, to = -1;
        T val;
        Edge() {}
        Edge(int f, int t, T v) {
            from = f;
            to = t;
            val = v;
        }
    };

    vector<vector<Edge>> g;
    vector<unordered_map<int, int>> undirected_id;
    int n;
    bool is_directed;
    bool ud_two_edge_cycle = false;
    stack<Edge> history;
    pair<int, int> two_v;
    T two_e;
    vector<bool> seen, finished;

    int dfs(int cur, Edge cur_e, bool is_prohibit_reverse) {
        seen[cur] = true;
        history.emplace(cur_e);
        for (const Edge &nex : g[cur]) {
            if (is_prohibit_reverse and cur_e.from == nex.to) continue;
            if (finished[nex.to]) continue;
            if (seen[nex.to] and !finished[nex.to]) {
                history.emplace(nex);
                return nex.to;
            }
            int pos = dfs(nex.to, nex, is_prohibit_reverse);
            if (pos != -1) return pos;
        }
        finished[cur] = true;
        history.pop();
        return -1;
    }

    vector<Edge> reconstruct(int pos) {
        vector<Edge> cycle;
        while (!history.empty()) {
            const Edge &e = history.top();
            history.pop();
            cycle.emplace_back(e);
            if (e.from == pos) break;
        }
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }

    vector<Edge> detect(bool is_prohibit_reverse = true) {
        seen.assign(n, false);
        finished.assign(n, false);
        int pos = -1;
        for (int cur = 0; cur < n and pos == -1; cur++) {
            if (seen[cur]) continue;
            while (!history.empty()) history.pop();
            pos = dfs(cur, Edge(), is_prohibit_reverse);
            if (pos != -1) return reconstruct(pos);
        }
        return vector<Edge>();
    }

   public:
    CycleDetection(int siz, bool is_directed_graph) {
        n = siz;
        is_directed = is_directed_graph;
        g.resize(n);
        if (!is_directed) undirected_id.resize(n);
    }

    void add_edge(int u, int v, T w) {
        if (is_directed) {
            g[u].emplace_back(Edge(u, v, w));
        } else {
            if (u > v) swap(u, v);
            if (undirected_id[u].contains(v)) {
                ud_two_edge_cycle = true;
                two_v = {u, v};
                two_e = w;
            } else {
                undirected_id[u][v] = w;
            }
            g[u].emplace_back(Edge(u, v, w));
            g[v].emplace_back(Edge(v, u, w));
        }
    }

    vector<Edge> cycle() {
        if (is_directed) {
            return detect(false);
        } else if (ud_two_edge_cycle) {
            int u = two_v.first;
            int v = two_v.second;
            vector<Edge> res = {Edge(u, v, undirected_id[u][v]), Edge(v, u, two_e)};
            return res;
        } else {
            return detect(true);
        }
    }
};
