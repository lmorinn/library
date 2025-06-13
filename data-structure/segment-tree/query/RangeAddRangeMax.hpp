#include "../LazySegmentTree.hpp"

class RangeAddRangeMax {
 private:
  using S = long long;
  using F = long long;
  const S INF = 8e18;
  S op(S a, S b) { return std::max(a, b); }
  S e() { return -INF; }
  S mapping(F f, S x) { return f + x; }
  F composition(F f, F g) { return f + g; }
  F id() { return 0; }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg;

 public:
  RangeAddRangeMax(vector<S> v) : seg(v) {
  }
  void set(int i, S x) {
    seg.set(i, x);
  }
  S get(int i) {
    return seg.get(i);
  }
  S all_prod() {
    return seg.all_prod();
  }
  S prod(int l, int r) {
    return seg.prod(l, r);
  }
  void apply(int l, int r, F f) {
    seg.apply(l, r, f);
  }
  void apply(int i, F f) {
    seg.apply(i, f);
  }

  S prod(int l, int r) {
    return seg.prod(l, r);
  }

  template <bool (*g)(S)>
  int max_right(int l) {
    return seg.max_right(l, [](S x) { return g(x); });
  }
  template <bool (*g)(S)>
  int min_left(int r) {
    return seg.min_left(r, [](S x) { return g(x); });
  }
};