#include "../WaveletMatrixDualSegtree.hpp"

template <class S, class F, auto mapping, auto composition, auto id, class T>
class RectangleApplyPointGet {
 private:
  WaveletMatrix<S, F, mapping, composition, id, T> wm;
  vector<T> px;
  vector<int> ord;

 public:
  RectangleApplyPointGet() {}
  RectangleApplyPointGet(vector<T> x, vector<T> y, vector<S> w) {
    int n = int(x.size());
    ord.resize(n);
    vector<tuple<T, T, S, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {x[i], y[i], w[i], i};
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
      return get<0>(a) < get<0>(b);
    });
    px.resize(n);
    for (int i = 0; i < n; i++) {
      px[i] = get<0>(v[i]);
      y[i] = get<1>(v[i]);
      w[i] = get<2>(v[i]);
      ord[i] = get<3>(v[i]);
    }
    wm = WaveletMatrix<S, F, mapping, composition, id, T>(y, w);
  }

  void rectangle_apply(T xl, T xr, T yl, T yr, F x) {
    int l = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));
    int r = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));
    wm.range_apply(l, r, yl, yr, x);
  }

  S get(int p) {
    return wm.get(ord[p]);
  }
};