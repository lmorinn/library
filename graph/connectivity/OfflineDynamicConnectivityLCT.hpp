#pragma once
#include "../dynamic-tree/LinkCutTreeEdge.hpp"

struct S {
  int val, u, v;
};

S op(S a, S b) {
  if (a.val < b.val) {
    return a;
  } else {
    return b;
  }
}

S e() {
  return {10000000, -1, -1};
}

using F = int;
S mapping(F x, S a) {
  return a;
}

F composition(F g, F f) {
  return f;
}

F id() {
  return 0;
}

void reverseprod(S a) {
}

template <class R>
class OfflineDynamicConnectivity {
 private:
  struct Query {
    int com;
    int u, v;
    int pos;
    int finish;
  };
  int Q_INF = 1e8;
  int n;
  LinkCutTree<S, op, e, F, mapping, composition, id, reverseprod> t;
  vector<map<int, int>> ed;
  vector<set<int>> msf;
  int qtime;
  vector<Query> q;

 public:
  OfflineDynamicConnectivity() {}

  OfflineDynamicConnectivity(int siz) {
    vector<S> nodew(siz, {int(1e8), -1, -1});
    t = LinkCutTree<S, op, e, F, mapping, composition, id, reverseprod>(nodew);
    ed.resize(siz);
    msf.resize(siz);
    qtime = 0;
  }

  void link(int u, int v) {
    q.push_back({0, u, v, qtime, Q_INF});
    ed[u][v] = qtime;
    ed[v][u] = qtime;
    qtime++;
  }

  void cut(int u, int v) {
    q.push_back({1, u, v, qtime, -1});
    int idx = ed[u][v];
    q[idx].finish = qtime;
    ed[u].erase(v);
    ed[v].erase(u);
    qtime++;
  }

  void same(int u, int v) {
    q.push_back({2, u, v, qtime, -1});
    qtime++;
  }

  vector<R> build() {
    int u, v, com;
    vector<R> res;
    for (int i = 0; i < qtime; i++) {
      com = q[i].com;
      int u = q[i].u;
      int v = q[i].v;
      int w = q[i].finish;
      if (com == 0) {
        if (!t.is_connected(u, v)) {
          t.add(u, v, w);
          msf[u].insert(v);
          msf[v].insert(u);
        } else {
          S path = t.prod(u, v);
          if (path.val < w and path.u != -1 and path.v != -1) {
            t.erase(path.u, path.v);
            t.add(u, v, w);
            msf[path.u].erase(path.v);
            msf[path.v].erase(path.u);
            msf[u].insert(v);
            msf[v].insert(u);
          }
        }
      } else if (com == 1) {
        if (msf[u].find(v) != msf[u].end()) {
          int p = t.prod(u, v).val;
          t.erase(u, v);
          msf[u].erase(v);
          msf[v].erase(u);
        }
      } else if (com == 2) {
        res.emplace_back(t.is_connected(u, v));
      }
    }
    return res;
  }
};