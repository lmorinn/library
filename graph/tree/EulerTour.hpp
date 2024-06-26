#pragma once
#include "../../data-structure/others/SparseTable.hpp"
#include "../../data-structure/segment-tree/SegmentTree.hpp"
struct SD {
  int depth;
  int ind;
};
auto f = [](const SD x, const SD y) { if (x.depth < y.depth) return x; else return y; };
template <class S, auto ops, auto es, auto invs, class T, auto opt, auto et, auto invt>
class EulerTour {
 private:
  int n;
  vector<int> start, finish, parent, depth, euler_tour;
  vector<SD> depth_v;
  vector<S> node_sum;
  vector<T> edge_sum;
  segtree<T, opt, et> seg_e, pseg_e;
  segtree<S, ops, es> seg_n, pseg_n;
  SparseTable<SD, f> sp_d;
  int time = 0;

  void rec(int cur, int p, int d, vector<vector<pair<int, S>>> &g) {
    start[cur] = time++;
    parent[cur] = p;
    depth[cur] = d;
    for (auto nex : g[cur]) {
      if (nex.first != p) {
        rec(nex.first, cur, d + 1, g);
      }
    }
    finish[cur] = time++;
  }

  T root_path_edge(int ind) {
    return pseg_e.prod(1, start[ind] + 1);
  }

  S root_path_node(int ind) {
    return pseg_n.prod(0, start[ind] + 1);
  }

 public:
  ///@param g g[from][j]={to,辺の重み}
  ///@param node_num 頂点の重み
  EulerTour(vector<vector<pair<int, S>>> &g, vector<S> node_num, int root = 0) {
    n = g.size();
    start.resize(n);
    finish.resize(n);
    parent.resize(n);
    euler_tour.resize(n * 2);
    depth.resize(n);
    node_sum.resize(n * 2, es());
    edge_sum.resize(n * 2, et());
    depth_v.resize(n * 2, {INT_MAX / 10, -1});
    rec(root, -1, 0, g);
    for (int i = 0; i < n; i++) {
      euler_tour[start[i]] = i;
      euler_tour[finish[i]] = -i;
      node_sum[start[i]] = node_num[i];
      depth_v[start[i]] = {depth[i], start[i]};
      if (i != root) {
        for (auto nex : g[i]) {
          if (nex.first == parent[i]) {
            edge_sum[start[i]] = nex.second;
            break;
          }
        }
      }
    }
    seg_e = segtree<T, opt, et>(edge_sum);
    seg_n = segtree<S, ops, es>(node_sum);

    for (int i = 0; i < n; i++) {
      node_sum[finish[i]] = invs(node_num[i]);
      if (i != root) {
        for (auto nex : g[i]) {
          if (nex.first == parent[i]) {
            edge_sum[finish[i]] = invt(nex.second);
            depth_v[finish[i]] = {depth[parent[-euler_tour[finish[i]]]], finish[i]};
            break;
          }
        }
      }
    }
    pseg_e = segtree<T, opt, et>(edge_sum);
    pseg_n = segtree<S, ops, es>(node_sum);
    sp_d = SparseTable<SD, f>(depth_v);
  }

  S get_node(int i) {
    return seg_n.get(start[i]);
  }

  T subtree_edge(int ind) {
    return seg_e.prod(start[ind] + 1, finish[ind]);
  }

  S subtree_node(int ind) {
    return seg_n.prod(start[ind], finish[ind]);
  }

  T path_edge(int i, int j) {
    int l = lca(i, j);
    return root_path_edge(i) + root_path_edge(j) - 2 * root_path_edge(l);
  }

  S path_node(int i, int j) {
    int l = lca(i, j);
    return root_path_node(i) + root_path_node(j) - 2 * root_path_node(l);
  }

  void update_weight_edge(int i, int j, T x) {
    if (i != parent[j]) swap(i, j);
    seg_e.set(start[j], x);
    pseg_e.set(start[j], x);
    pseg_e.set(finish[j], invt(x));
  }

  void update_weight_node(int i, T x) {
    seg_n.set(start[i], x);
    pseg_n.set(start[i], x);
    pseg_n.set(finish[i], invt(x));
  }

  int lca(int i, int j) {
    int res;
    if (start[i] > start[j]) swap(i, j);
    SD id = sp_d.query(start[i], start[j] + 1);
    if (euler_tour[id.ind] < 0) {
      res = parent[-euler_tour[id.ind]];
    } else {
      res = euler_tour[id.ind];
    }
    return res;
  }
};