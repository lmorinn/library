#include "../LazySegmentTree.hpp"
class RangeLinearAddRangeSum {
 private:
  static constexpr long long INF = 8e18;
  static constexpr int INFI = int(1e9) + 10;

  struct S {
    long long sum;
    int l, r;
  };
  struct F {
    long long a, b;
  };

  static S op(S a, S b) {
    return S{a.sum + b.sum, min(a.l, b.l), max(a.r, b.r)};
  }
  static S e() {
    return S{0, INFI, -INFI};
  }

  static S mapping(F f, S s) {
    return {s.sum + (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};
  }

  static F composition(F f, F g) {
    return {f.a + g.a, f.b + g.b};
  }

  static F id() {
    return F{0, 0};
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg;

 public:
  RangeLinearAddRangeSum(const vector<long long> &v) {
    int n = int(v.size());
    vector<S> tmp(n);
    for (int i = 0; i < n; i++) {
      tmp[i].l = i;
      tmp[i].r = i + 1;
      tmp[i].sum = v[i];
    }
    seg = lazy_segtree<S, op, e, F, mapping, composition, id>(tmp);
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
    seg.apply(l, r, F{f.a, f.b - f.a * get(l).l});
  }
  void apply(int i, F f) {
    seg.apply(i, F{f.a, f.b - f.a * get(i).l});
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