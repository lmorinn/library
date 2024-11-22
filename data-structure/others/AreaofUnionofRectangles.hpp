#pragma once
#include "./../segment-tree/LazySegmentTree.hpp"
using Sa = pair<int, long long>;
using Fa = int;
Sa opa(Sa a, Sa b) {
  if (a.first < b.first) return a;
  if (a.first > b.first) return b;
  return {a.first, a.second + b.second};
}

Sa ea() {
  return {1e9 + 1e5, 0};
}

Sa mappinga(Fa f, Sa x) {
  return {x.first + f, x.second};
}

Fa compositiona(Fa f, Fa g) {
  return f + g;
}

Fa ida() {
  return 0;
}

class AreaofUnionofRectangles {
 private:
  vector<long long> x1, x2, y1, y2;
  int n;
  lint res = 0;

 public:
  AreaofUnionofRectangles(const vector<long long> &xl, const vector<long long> &xr, const vector<long long> &yl, const vector<long long> &yr) {
    x1 = xl;
    x2 = xr;
    y1 = yl;
    y2 = yr;
    n = x1.size();
    vector<int> cmp(n * 2);
    vector<tuple<long long, int, int, int>> q(n * 2);
    for (int i = 0; i < n; i++) {
      cmp[i * 2] = y1[i];
      cmp[i * 2 + 1] = y2[i];
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for (int i = 0; i < n; i++) {
      int idx1 = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y1[i]));
      int idx2 = distance(cmp.begin(), lower_bound(cmp.begin(), cmp.end(), y2[i]));
      q[i * 2] = {x1[i], 1, idx1, idx2};
      q[i * 2 + 1] = {x2[i], -1, idx1, idx2};
    }

    sort(q.begin(), q.end());
    int siz = cmp.size() - 1;
    vector<Sa> v(siz);
    for (int i = 0; i < siz; i++) {
      v[i] = {0, cmp[i + 1] - cmp[i]};
    }

    lazy_segtree<Sa, opa, ea, Fa, mappinga, compositiona, ida> seg(v);
    long long prev = get<0>(q[0]);
    for (int i = 0; i < n * 2; i++) {
      long long x = get<0>(q[i]);
      int f = get<1>(q[i]);
      long long l = get<2>(q[i]);
      long long r = get<3>(q[i]);
      long long h = x - prev;
      long long w = cmp[siz] - cmp[0];
      Sa pr = seg.all_prod();
      if (pr.first == 0) w -= pr.second;
      res += h * w;
      prev = x;
      seg.apply(l, r, f);
    }
  }

  lint ans() {
    return res;
  }
};