#include "../../data-structure/binary-indexed-tree/DualBinaryIndexedTree.hpp"

static const unsigned long long seed = chrono::steady_clock::now().time_since_epoch().count();
static mt19937_64 eng(seed);

template <class S>
class CentroidDecomposition {
   private:
    vector<vector<int>> g;
    vector<bool> dead;
    vector<S> leaf;
    vector<int> ord;
    vector<int> dinfo;
    vector<int> parent;
    vector<vector<RangeAddPointGet<S>>> subtrees;
    vector<vector<int>> ds_size;
    vector<int> subtree_size;
    vector<vector<pair<int, int>>> info;

    int n;
    int node_idx;

    void reorder(int s) {
        ord.assign(n, -1);
        queue<int> q;
        q.push(s);
        int idx = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ord[cur] = idx++;
            for (int nex : g[cur])
                if (ord[nex] == -1) q.push(nex);
        }
    }

    void ds_add(RangeAddPointGet<S> &fen, int siz, int l, int r, S x) {
        l = max(0, l);
        r = min(r, siz);
        if (l < r) fen.range_add(l, r, x);
    }

   public:
    CentroidDecomposition(int siz) {
        n = siz;
        g.resize(n);

        node_idx = n;
    }
    CentroidDecomposition() {}

    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    void build(const vector<S> &a) {
        parent.assign(n << 1, -1);
        info.resize(n, vector<pair<int, int>>(30));
        subtrees.resize(n << 1, vector<RangeAddPointGet<S>>(2));
        ds_size.resize(n << 1, vector<int>(2));
        dead.resize(n, false);
        subtree_size.resize(n << 1);
        leaf.resize(n);
        dinfo.resize(n);
        reorder(uniform_int_distribution<int>(0, n - 1)(eng));
        vector<vector<int>> tmp(n);
        vector<int> par_cr(n << 1, -1);
        vector<int> head(n << 1);
        vector<int> tail(n << 1);
        vector<int> link(n << 1, -1);
        vector<S> d(n * 3);
        for (int i = 0; i < n; i++) {
            head[i] = tail[i] = i;
        }

        for (int u = 0; u < n; u++) {
            for (const int v : g[u]) {
                tmp[ord[u]].emplace_back(ord[v]);
            }
            leaf[ord[u]] = a[u];
        }
        g = tmp;

        function<int(int, int)> rec = [&](int start, int sz) -> int {
            int c = -1;
            const auto get_centroid = [&](auto &&self, int u, int p) -> void {
                subtree_size[u] = 1;
                for (const int v : g[u]) {
                    if (v == p || dead[v]) continue;

                    self(self, v, u);
                    if (v == c) {
                        subtree_size[u] = sz - subtree_size[c];
                        break;
                    }

                    subtree_size[u] += subtree_size[v];
                }

                if (c == -1 && subtree_size[u] * 2 > sz) c = u;
            };

            get_centroid(get_centroid, start, -1);
            dead[c] = true;
            for (const int u : g[c]) {
                if (dead[u]) continue;
                const int comp_sz = subtree_size[u];
                par_cr[u] = rec(u, comp_sz);
                subtree_size[u] = comp_sz;
            }

            const auto compare = [&](int i, int j) {
                return subtree_size[i] > subtree_size[j];
            };

            priority_queue<int, vector<int>, decltype(compare)> pq{compare};

            for (const int v : g[c]) {
                if (dead[v]) continue;
                link[v] = -1;
                pq.push(v);
            }

            const auto build_data_structure = [&](const int root_head, const int child_index) {
                queue<pair<int, int>> q;
                for (int root = root_head; root >= 0; root = link[root]) {
                    q.emplace(root, -1);
                }

                S x = 0;
                int idx = 0;
                int nxt = -1;
                while (!q.empty()) {
                    int cur = q.front().first;
                    int prev = q.front().second;
                    q.pop();
                    if (cur == nxt) {
                        d[idx++] = exchange(x, 0);
                        nxt = -1;
                    }

                    info[cur][dinfo[cur]++] = {child_index, idx};
                    x += leaf[cur];

                    for (const int v : g[cur]) {
                        if (v == prev or dead[v]) continue;
                        q.emplace(v, cur);
                        if (nxt == -1) nxt = v;
                    }
                }
                d[idx++] = x;
                return idx;
            };

            while (pq.size() >= 2) {
                const int p1 = pq.top();
                pq.pop();
                const int p2 = pq.top();
                pq.pop();
                if (pq.empty()) {
                    parent[par_cr[p1]] = parent[par_cr[p2]] = c;
                    ds_size[c][0] = build_data_structure(head[p1], 0);
                    subtrees[c][0] = RangeAddPointGet<S>(ds_size[c][0]);
                    ds_size[c][1] = build_data_structure(head[p2], 1);
                    subtrees[c][1] = RangeAddPointGet<S>(ds_size[c][1]);
                    break;
                }
                subtree_size[node_idx] = subtree_size[p1] + subtree_size[p2];
                par_cr[node_idx] = node_idx;
                parent[par_cr[p1]] = parent[par_cr[p2]] = node_idx;
                ds_size[node_idx][0] = build_data_structure(head[p1], 0);
                subtrees[node_idx][0] = RangeAddPointGet<S>(ds_size[node_idx][0]);
                ds_size[node_idx][1] = build_data_structure(head[p2], 1);
                subtrees[node_idx][1] = RangeAddPointGet<S>(ds_size[node_idx][1]);
                head[node_idx] = head[p1];
                tail[node_idx] = tail[p2];
                link[tail[p1]] = head[p2];
                pq.push(node_idx);
                node_idx++;
            }

            if (!pq.empty()) {
                int u = pq.top();
                pq.pop();
                parent[par_cr[u]] = c;
                ds_size[c][0] = build_data_structure(head[u], 0);
                subtrees[c][0] = RangeAddPointGet<S>(ds_size[c][0]);
            }
            dead[c] = false;
            return c;
        };

        rec(0, n);
        parent.resize(node_idx);
        parent.shrink_to_fit();
        subtrees.resize(node_idx);
        subtrees.shrink_to_fit();
    }

    S get(int p) {
        S ret = 0;
        p = ord[p];
        ret += leaf[p];
        int cur = parent[p];
        for (int i = 0; i < dinfo[p]; i++) {
            const auto &[b, dist] = info[p][i];
            ret += subtrees[exchange(cur, parent[cur])][b].point_get(dist);
        }
        return ret;
    }

    void add(int p, int lower, int upper, S x) {
        p = ord[p];
        if (lower <= 0 and 0 < upper) leaf[p] += x;
        ds_add(subtrees[p][0], ds_size[p][0], lower - 1, upper - 1, x);
        ds_add(subtrees[p][1], ds_size[p][1], lower - 1, upper - 1, x);
        int v = parent[p];
        for (int i = 0; i < dinfo[p]; i++) {
            const auto &[b, dist] = info[p][i];
            int ql = lower - dist - 1;
            int qr = upper - dist - 1;
            if (v < n and ql <= 0 and 0 < qr) leaf[v] += x;
            ds_add(subtrees[exchange(v, parent[v])][b ^ 1], ds_size[v][b ^ 1], ql - 1, qr - 1, x);
        }
    }
};