#pragma once
#include "../data-structure/segment-tree/SegmentTree.hpp"
template <typename T>
int lis(vector<T> a) {
  using S = int;
  auto op = [](S x, S y) { return max(x, y); };
  auto e = []() { return 0; };
  int n = a.size();
  int ret = 0;
  vector<T> b(n);
  b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; i++) a[i] = distance(b.begin(), lower_bound(b.begin(), b.end(), a[i]));
  int siz = b.size();
  segtree<S, op, e> dp(siz);
  for (int i = 0; i < n; i++) {
    int cur = max(1, dp.prod(0, a[i]) + 1);
    dp.set(a[i], cur);
    ret = max(ret, cur);
  }
  return ret;
}
