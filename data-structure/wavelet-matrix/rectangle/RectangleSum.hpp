#include "../WaveletMatrixTemplateSum.hpp"

template <class T, class S>
class RectangleSum {
 private:
  WaveletMatrix<T, S> wm;
  vector<T> px;

 public:
  RectangleSum() {}
  RectangleSum(vector<T> x, vector<T> y, vector<S> w) {
    int n = int(x.size());
    vector<tuple<T, T, S>> v(n);
    for (int i = 0; i < n; i++) v[i] = {x[i], y[i], w[i]};
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
      return get<0>(a) < get<0>(b);
    });
    px.resize(n);
    for (int i = 0; i < n; i++) {
      px[i] = get<0>(v[i]);
      y[i] = get<1>(v[i]);
      w[i] = get<2>(v[i]);
    }
    wm = WaveletMatrix<T, S>(y, w);
  }

  S rectangle_sum(T xl, T xr, T yl, T yr) {
    int l = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));
    int r = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));
    return wm.range_sum(l, r, yl, yr);
  }
};