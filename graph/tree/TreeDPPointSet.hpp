#include "../../data-structure/segment-tree/SegmentTree.hpp"

template <class Path, auto compress, auto Path_e, class Point, auto rake, auto Point_e, auto add_v, auto add_e, auto vertex>
struct hld {
 private:
  int n, root;
  vector<vector<int>> g;
  vector<int> heavy_p, heavy_l, light_p, idx, idx_c;
  segtree<Path, compress, Path_e> seg;
  segtree<Point, rake, Point_e> seg2;

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
    for (int i = 1; i < int(g[cur].size()); i++) light_p[g[cur][i]] = cur;
    return sub;
  }

  void dfs2(int cur, int top, int& id, int& id2) {
    heavy_p[cur] = top;
    idx[cur] = --id;
    if (!g[cur].empty()) {
      dfs2(g[cur].front(), top, id, id2);
      heavy_l[cur] = heavy_l[g[cur].front()];
    } else {
      heavy_l[cur] = cur;
    }
    for (int i = 1; i < int(g[cur].size()); i++) dfs2(g[cur][i], g[cur][i], id, id2);
    for (int i = 1; i < int(g[cur].size()); i++) idx_c[g[cur][i]] = id2++;
  }

  Point init_segtree(int top, vector<Path>& init_path, vector<Point>& init_point) {
    vector<int> heavy_path;
    int v = top;
    while (1) {
      heavy_path.emplace_back(v);
      if (g[v].empty()) break;
      v = g[v].front();
    }
    for (int v : heavy_path) {
      Point light = Point_e();
      for (int i = 1; i < int(g[v].size()); i++) {
        int ch = g[v][i];
        Point child_point = init_segtree(ch, init_path, init_point);
        init_point[idx_c[ch]] = child_point;
        light = rake(light, child_point);
      }
      if (g[v].size() > 1) {
        init_path[idx[v]] = add_v(v, light);
      } else {
        init_path[idx[v]] = vertex(v);
      }
    }
    Path path = Path_e();
    for (int i = int(heavy_path.size()) - 1; i >= 0; i--) {
      int v = heavy_path[i];
      path = compress(path, init_path[idx[v]]);
    }
    return add_e(path);
  }

 public:
  hld(int n, int root = 0) : n(n), root(root), g(n), heavy_p(n, -1), heavy_l(n, -1), light_p(n, -1), idx(n), idx_c(n) {}

  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  void build(int root = 0) {
    int id = n;
    int id2 = 0;
    dfs(root, -1);
    dfs2(root, root, id, id2);
    vector<Path> init_path(n, Path_e());
    vector<Point> init_point(n, Point_e());
    init_segtree(root, init_path, init_point);
    seg = segtree<Path, compress, Path_e>(init_path);
    seg2 = segtree<Point, rake, Point_e>(init_point);
  }

  Path tree_dp() {
    return seg.prod(idx[heavy_l[root]], idx[root] + 1);
  }

  void set(int i) {
    while (1) {
      if (g[i].size() > 1) {
        int ch_num = int(g[i].size()) - 1;
        if (ch_num == 1) {
          seg.set(idx[i], add_v(i, seg2.get(idx_c[g[i][1]])));
        } else {
          seg.set(idx[i], add_v(i, seg2.prod(idx_c[g[i][1]], idx_c[g[i][1]] + ch_num)));
        }
      } else {
        seg.set(idx[i], vertex(i));
      }
      int nex = light_p[heavy_p[i]];
      if (nex == -1) break;
      int l = idx[heavy_l[heavy_p[i]]];
      int r = idx[heavy_p[i]] + 1;
      if (r - l == 1) {
        seg2.set(idx_c[heavy_p[i]], add_e(seg.get(l)));
      } else {
        seg2.set(idx_c[heavy_p[i]], add_e(seg.prod(l, r)));
      }
      i = nex;
    }
  }
};