#pragma once
template <class S, auto ops, auto es, class F, auto mappings, auto compositionf, auto idf, class T, auto opt, auto et, class G, auto mappingt, auto compositiong, auto idg>
class hld {
 private:
  int n;
  vector<int> subtree, depth, hl, ind, parent, top;
  vector<bool> seen;
  vector<T> dist_top_p;
  lazy_segtree<S, ops, es, F, mappings, compositionf, idf> nodeseg, noderseg;
  lazy_segtree<T, opt, et, G, mappingt, compositiong, idg> pathseg, pathrseg;

  int indr(int x) {
    return abs(ind[x] - (n - 1)) - 1;
  }

  int indrn(int x) {
    return abs(ind[x] - (n - 1));
  }

  int rec_sub(vector<vector<pair<int, T>>> &g, int cur, int d) {
    int sub = 0;
    for (auto nex : g[cur]) {
      if (seen[nex.first]) continue;
      seen[nex.first] = 1;
      parent[nex.first] = cur;
      sub += rec_sub(g, nex.first, d + 1);
    }
    subtree[cur] = sub + 1;
    depth[cur] = d;
    return subtree[cur];
  }

  void rec_hld(vector<vector<pair<int, T>>> &g, int cur) {
    ind[cur] = int(hl.size());
    seen[cur] = 1;
    hl.push_back(cur);
    int sub = 0;
    int ind = -1;
    for (auto nex : g[cur]) {
      if (subtree[nex.first] > sub and !seen[nex.first]) {
        sub = subtree[nex.first];
        ind = nex.first;
      }
    }
    if (ind != -1) {
      top[ind] = top[cur];
      rec_hld(g, ind);
      for (auto nex : g[cur]) {
        if (nex.first != ind and !seen[nex.first]) {
          top[nex.first] = nex.first;
          dist_top_p[nex.first] = nex.second;
          rec_hld(g, nex.first);
        }
      }
    }
  }

 public:
  hld(vector<vector<pair<int, T>>> &g, vector<S> nodew, int root = 0) {
    n = g.size();
    seen.resize(n, 0);
    subtree.resize(n, 0);
    ind.resize(n, 0);
    depth.resize(n, 0);
    top.resize(n, 0);
    dist_top_p.resize(n, et());
    parent.resize(n, -1);
    seen[root] = 1;
    rec_sub(g, root, 0);
    for (int i = 0; i < n; i++) seen[i] = 0;
    seen[root] = 1;
    top[root] = root;
    rec_hld(g, root);
    vector<S> v(n, es());
    vector<T> z(n, et());
    for (int i = 0; i < n; i++) v[i] = nodew[hl[i]];
    nodeseg = lazy_segtree<S, ops, es, F, mappings, compositionf, idf>(v);
    reverse(v.begin(), v.end());
    noderseg = lazy_segtree<S, ops, es, F, mappings, compositionf, idf>(v);
    for (int i = 1; i < n; i++) {
      int prev = hl[i - 1];
      int cur = hl[i];
      if (top[prev] != top[cur]) continue;
      for (auto p : g[prev]) {
        if (p.first == cur) {
          z[i] = p.second;
        }
      }
    }
    pathseg = lazy_segtree<T, opt, et, G, mappingt, compositiong, idg>(z);
    reverse(z.begin(), z.end());
    pathrseg = lazy_segtree<T, opt, et, G, mappingt, compositiong, idg>(z);
  }

  // path i -> j
  S prod_node(int i, int j) {
    S prodsl = es();
    S prodsr = es();
    while (1) {
      if (top[i] == top[j]) {
        if (depth[i] > depth[j]) {
          prodsl = ops(prodsl, noderseg.prod(indrn(i), indrn(j) + 1));
        } else {
          prodsr = ops(nodeseg.prod(ind[i], ind[j] + 1), prodsr);
        }
        break;
      }

      if (depth[top[i]] > depth[top[j]]) {
        prodsl = ops(prodsl, noderseg.prod(indrn(i), indrn(top[i]) + 1));
        i = parent[top[i]];
      } else {
        prodsr = ops(nodeseg.prod(ind[top[j]], ind[j] + 1), prodsr);
        j = parent[top[j]];
      }
    }
    return ops(prodsl, prodsr);
  }

  // path i -> j
  T prod_edge(int i, int j) {
    T prodl = et();
    T prodr = et();
    while (1) {
      if (top[i] == top[j]) {
        if (depth[i] > depth[j]) {
          prodl = opt(prodl, pathrseg.prod(indr(i) + 1, indr(j) + 1));
        } else {
          prodr = opt(pathseg.prod(ind[i] + 1, ind[j] + 1), prodr);
        }
        break;
      }

      if (depth[top[i]] > depth[top[j]]) {
        prodl = opt(prodl, pathrseg.prod(indr(i) + 1, indr(top[i]) + 1));
        prodl = opt(prodl, dist_top_p[top[i]]);
        i = parent[top[i]];
      } else {
        prodr = opt(pathseg.prod(ind[top[j]] + 1, ind[j] + 1), prodr);
        prodr = opt(dist_top_p[top[j]], prodr);
        j = parent[top[j]];
      }
    }
    return opt(prodl, prodr);
  }

  void set_edge(int u, int v, T w) {
    if (top[u] == top[v]) {
      if (depth[u] > depth[v]) {
        pathrseg.set(indr(v), w);
        pathseg.set(ind[u], w);
      } else {
        pathseg.set(ind[v], w);
        pathrseg.set(indr(u), w);
      }
    } else {
      if (parent[v] == u) {
        dist_top_p[v] = w;
      } else {
        dist_top_p[u] = w;
      }
    }
  }

  void set_node(int u, S x) {
    nodeseg.set(ind[u], nodeseg.get(ind[u]) + x);
    noderseg.set(indrn(u), noderseg.get(indrn(u)) + x);
  }

  // path i -> j
  void apply_edge(int i, int j, G x) {
    while (1) {
      if (top[i] == top[j]) {
        if (depth[i] > depth[j]) {
          pathrseg.apply(indr(i) + 1, indr(j) + 1, x);
        } else {
          pathseg.apply(ind[i] + 1, ind[j] + 1, x);
        }
        break;
      }

      if (depth[top[i]] > depth[top[j]]) {
        pathrseg.apply(indr(i) + 1, indr(top[i]) + 1, x);
        dist_top_p[top[i]] = mappingt(x, dist_top_p[top[i]]);
        i = parent[top[i]];
      } else {
        pathseg.apply(ind[top[j]] + 1, ind[j] + 1, x);
        dist_top_p[top[j]] = mappingt(x, dist_top_p[top[j]]);
        j = parent[top[j]];
      }
    }
  }

  // path i -> j
  void apply_node(int i, int j, F x) {
    while (1) {
      if (top[i] == top[j]) {
        if (depth[i] > depth[j]) {
          noderseg.apply(indrn(i), indrn(j) + 1, x);
        } else {
          nodeseg.apply(ind[i], ind[j] + 1, x);
        }
        break;
      }

      if (depth[top[i]] > depth[top[j]]) {
        noderseg.apply(indrn(i), indrn(top[i]) + 1, x);
        i = parent[top[i]];
      } else {
        nodeseg.apply(ind[top[j]], ind[j] + 1, x);
        j = parent[top[j]];
      }
    }
  }
};