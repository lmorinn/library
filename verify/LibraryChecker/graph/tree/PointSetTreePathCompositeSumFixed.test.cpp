#include "../../../../atcoder/modint.hpp"
#include "../../../../template/template.hpp"
using namespace atcoder;
using mint = modint998244353;
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
#include "../../../../graph/tree/TreeDPPointSet.hpp"

vector<mint> A, eb, ec;

struct Path {
  mint a, b, g, d;
  Path(mint a = 1, mint b = 0, mint g = 0, mint d = 0) : a(a), b(b), g(g), d(d) {}
};

Path compress(const Path& p, const Path& c) {
  return Path(p.a * c.a, c.a * p.b + c.b, c.a * p.g + c.b * p.d + c.g, c.d + p.d);
}

struct Point {
  mint sum;
  mint cnt;
  Point(mint sum = 0, mint cnt = 0) : sum(sum), cnt(cnt) {}
};

Point point_e() {
  return {0, 0};
}

Path path_e() {
  return Path();
}

Point rake(const Point& a, const Point& b) {
  return Point(a.sum + b.sum, a.cnt + b.cnt);
}

Path add_v(int v, Point p) {
  mint B = eb[v];
  mint C = ec[v];
  return Path(B, C, B * (p.sum + A[v]) + C * (p.cnt + 1), p.cnt + 1);
}

Path vertex(int v) {
  mint B = eb[v];
  mint C = ec[v];
  return Path(B, C, B * A[v] + C, 1);
}

Point add_e(Path p) {
  return Point(p.g, p.d);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  in(n, q);
  A.assign(n, 0);
  eb.assign(n, 1);
  ec.assign(n, 0);

  rep(i, n) {
    lint x;
    in(x);
    A[i] = x;
  }

  hld<Path, compress, path_e, Point, rake, point_e, add_v, add_e, vertex> t(n);

  vector<int> U(n - 1), V(n - 1);
  vector<mint> B(n - 1), C(n - 1);

  vector<vector<pair<int, int>>> g(n);

  rep(e, n - 1) {
    int u, v;
    lint b, c;
    in(u, v, b, c);
    U[e] = u;
    V[e] = v;
    B[e] = mint(b);
    C[e] = mint(c);
    t.add_edge(u, v);
    g[u].push_back({v, e});
    g[v].push_back({u, e});
  }

  vector<int> par(n, -1);
  vector<int> par_e(n, -1);
  vector<int> chi_e(n - 1, -1);

  queue<int> que;
  par[0] = -2;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto [to, e] : g[v]) {
      if (par[to] != -1) continue;
      par[to] = v;
      par_e[to] = e;
      chi_e[e] = to;
      que.push(to);
    }
  }
  eb[0] = 1;
  ec[0] = 0;
  rep(i, 1, n) {
    int e = par_e[i];
    eb[i] = B[e];
    ec[i] = C[e];
  }

  t.build(0);

  rep(i, q) {
    int com;
    in(com);
    if (com == 0) {
      int w;
      lint x;
      in(w, x);
      A[w] = x;
      t.set(w);
    } else {
      int e;
      lint y, z;
      in(e, y, z);
      int ch = chi_e[e];
      eb[ch] = y;
      ec[ch] = z;
      t.set(ch);
    }
    out(add_e(t.tree_dp()).sum.val());
  }
}
