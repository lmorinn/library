#include "../LazySegmentTree.hpp"

class RangeLinearUpdate {
 private:
  static constexpr long long INF = 8e18;
  static constexpr int INFI = int(1e9) + 10;

  struct S {
    long long mi, mx, sum;
    int l, r;
  };
  struct F {
    long long a, b;
  };

  static S op(S a, S b) {
    return S{min(a.mi, b.mi), max(a.mx, b.mx), a.sum + b.sum, min(a.l, b.l), max(a.r, b.r)};
  }
  static S e() {
    return S{INF, -INF, 0, INFI, -INFI};
  }

  static S mapping(F f, S s) {
    if (f.a == INF) return s;
    if (f.a >= 0) {
      return S{f.a * s.l + f.b, f.a * (s.r - 1) + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};
    } else {
      return S{f.a * (s.r - 1) + f.b, f.a * s.l + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};
    }
  }

  static F composition(F f, F g) {
    return f.a == INF ? g : f;
  }

  static F id() {
    return F{INF, INF};
  }

  lazy_segtree<S, op, e, F, mapping, composition, id> seg;

 public:
  RangeLinearUpdate(const vector<long long> &v) {
    int n = int(v.size());
    vector<S> tmp(n);
    for (int i = 0; i < n; i++) {
      tmp[i].l = i;
      tmp[i].r = i + 1;
      tmp[i].mi = tmp[i].mx = tmp[i].sum = v[i];
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