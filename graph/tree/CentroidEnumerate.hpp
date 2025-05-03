vector<int> Centroid(const vector<vector<int>> &g) {
    int n = int(g.size());

    vector<int> centroids;
    vector<int> subtree_size(n, 1);
    auto dfs = [&](int u, int prev) {
        bool is_centroid = true;

        for (auto v : g[u]) {
            if (v != prev) {
                dfs(v, u);
                subtree_size[u] += subtree_size[v];
                if (subtree_size[v] > n / 2) is_centroid = false;
            }
        }
        if (n - subtree_size[u] > n / 2) is_centroid = false;
        if (is_centroid) centroids.emplace_back(u);
    };

    dfs(0, -1);
    return centroids;
}