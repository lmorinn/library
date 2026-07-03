// add(c): 頂点 c の情報をテーブルに追加する
// query(c): 頂点 c の部分木全体の情報が載ったテーブルに対するクエリに答える
// reset(): テーブルをリセットする
template <auto add, auto query, auto reset>
struct dsu_on_tree {
 private:
  int n, root, edge;
  vector<vector<int>> g;
  int dfs(int cur, int prev) {
    int sub = 1;
    for (int& nex : g[cur]) {
      if (nex == prev) {
        swap(g[cur].back(), nex);
        g[cur].pop_back();
        break;
      }
    }
    int best = 0;
    int idx = -1;
    for (int i = 0; i < int(g[cur].size()); i++) {
      int cnt = dfs(g[cur][i], cur);
      sub += cnt;
      if (best < cnt) {
        best = cnt;
        idx = i;
      }
    }
    if (!g[cur].empty()) swap(g[cur][idx], g[cur].front());
    return sub;
  }

  void dfs2(int cur) {
    for (int nex : g[cur]) dfs2(nex);
    add(cur);
  }

  void build() {
    int id = 0;
    dfs(root, -1);
  }

 public:
  dsu_on_tree(int n, int root = 0) : n(n), root(root), edge(0), g(n) {}

  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    edge++;
    if (edge == n - 1) build();
  }

  void calc(int cur) {
    for (int i = 1; i < int(g[cur].size()); i++) {
      calc(g[cur][i]);
      reset();
    }
    if (!g[cur].empty()) calc(g[cur].front());
    for (int i = 1; i < int(g[cur].size()); i++) dfs2(g[cur][i]);
    add(cur);
    query(cur);
  }
};
