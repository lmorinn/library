#pragma once
#include "../../data-structure/union-find/UndoableUnionFind.hpp"


template <class S, auto op, auto e>
struct OfflineDynamicConnectivity {
 private:
  struct Edge {
    int from, to;
  };

  struct Query {
    int com;
    int u, v;
    int start;
    int finish;
    lint val;
  };
  vector<Query> q;
  vector<S> res;
  int outq = 0;
  int n;
  vector<unordered_map<int, int>> ed;
  vector<vector<Edge>> node;
  vector<vector<pair<int, S>>> updates;
  vector<int> val_idx;
  UndoableUnionFind<S, op, e> d;
  int vertex_siz;
  int qtime;
  int Q_INF = 1e8;
  int idx = 0;

  vector<vector<Query>> outputQuery;

  void add(int a, int b, Edge &ed, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      node[k].emplace_back(ed);
      return;
    }
    add(a, b, ed, 2 * k + 1, l, (l + r) / 2);
    add(a, b, ed, 2 * k + 2, (l + r) / 2, r);
  }

  void add_update(int a, int b, pair<int, S> x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      updates[k].emplace_back(x);
      return;
    }
    add_update(a, b, x, 2 * k + 1, l, (l + r) / 2);
    add_update(a, b, x, 2 * k + 2, (l + r) / 2, r);
  }

  void execute(int k = 0) {
    if (outq == 0) return;
    for (auto &ed : node[k]) {
      d.unite(ed.from, ed.to);
    }

    for (auto &p : updates[k]) {
      d.update(p.first, p.second);
    }

    if (k < n - 1) {
      execute(2 * k + 1);
      execute(2 * k + 2);
    } else if (k - (n - 1) < qtime) {
      int qidx = k - (n - 1);
      for (auto cur : outputQuery[qidx]) {
        int com = cur.com;
        int u = cur.u;
        int v = cur.v;
        if (com == 2) {
          res.emplace_back(d.same(u, v));
        } else if (com == 3) {
          res.emplace_back(d.components());
        } else if (com == 4) {
          res.emplace_back(d.size(u));
        } else if (com == 6) {
          res.emplace_back(d.prod_components(u));
        }
      }
    }
    for (int i = 0; i < int(node[k].size() + updates[k].size()); i++) {
      d.undo();
    }
  }

 public:
  OfflineDynamicConnectivity(int siz) {
    d = UndoableUnionFind<S, op, e>(siz);
    vertex_siz = siz;
    ed.resize(siz);
    val_idx.resize(siz, -1);
  }

  void link(int u, int v) {
    if (u > v) swap(u, v);
    if (ed[u].find(v) != ed[u].end()) return;
    qtime++;
    q.push_back({0, u, v, qtime, Q_INF, 0});
    ed[u][v] = idx;
    idx++;
  }

  void cut(int u, int v) {
    if (u > v) swap(u, v);
    qtime++;
    q.push_back({1, u, v, qtime, -1, 0});
    int pos = ed[u][v];
    q[pos].finish = qtime;
    ed[u].erase(v);
    idx++;
  }

  void update(int u, lint x) {
    qtime++;
    q.push_back({5, u, -1, qtime, Q_INF, x});
    idx++;
  }

  void is_connected(int u, int v) {
    if (u > v) swap(u, v);
    q.push_back({2, u, v, qtime, -1, 0});
    idx++;
    outq++;
  }

  void components() {
    q.push_back({3, -1, -1, qtime, -1, 0});
    idx++;
    outq++;
  }

  void size(int u) {
    q.push_back({4, u, -1, qtime, -1, 0});
    idx++;
    outq++;
  }

  void prod(int u) {
    q.push_back({6, u, -1, qtime, -1, 0});
    idx++;
    outq++;
  }

  vector<S> build() {
    qtime++;

    int sz = qtime;
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1);
    updates.resize(2 * n - 1);
    outputQuery.resize(qtime);
    for (int i = 0; i < q.size(); i++) {
      if (q[i].com == 0) {
        Edge ed = {q[i].u, q[i].v};
        add(q[i].start, min(q[i].finish, qtime), ed);
      } else if (q[i].com == 5) {
        add_update(q[i].start, q[i].finish, {q[i].u, q[i].val});
      } else if (q[i].com != 1) {
        outputQuery[q[i].start].emplace_back(q[i]);
      }
    }
    execute();
    return res;
  }
};


