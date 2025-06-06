#include "../WaveletMatrixBinaryIndexedTree.hpp"

template <class T, class S>
class RectangleSumPointAdd {
 private:
  WaveletMatrix<T, S> wm;
  vector<T> px;
  vector<int> ord;

 public:
  RectangleSumPointAdd() {}
  RectangleSumPointAdd(vector<T> x, vector<T> y, vector<S> w) {
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
    wm = WaveletMatrix<T, S>(y, w);
  }

  S rectangle_sum(T xl, T xr, T yl, T yr) {
    int l = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));
    int r = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));
    return wm.range_sum(l, r, yl, yr);
  }

  void add(int p, S x) {
    wm.add(ord[p], x);
  }

  void set(int p, S x) {
    wm.set(ord[p], x);
  }
};