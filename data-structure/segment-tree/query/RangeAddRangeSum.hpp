#include "../LazySegmentTree.hpp"

class RangeAddRangeMax {
 private:
  struct S {
    long long value;
    int size;
  };
  using F = long long;

  S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
  S e() { return {0, 0}; }
  S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
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