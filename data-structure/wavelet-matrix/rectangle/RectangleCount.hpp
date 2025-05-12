#include "../WaveletMatrixTemplate.hpp"

template <class T>
class RectangleCount {
 private:
  WaveletMatrix<T> wm;
  vector<T> px;

 public:
  RectangleCount() {}
  RectangleCount(vector<T> x, vector<T> y) {
    int n = int(x.size());
    vector<pair<T, T>> v(n);
    for (int i = 0; i < n; i++) v[i] = {x[i], y[i]};
    sort(v.begin(), v.end());
    px.resize(n);
    for (int i = 0; i < n; i++) {
      px[i] = v[i].first;
      y[i] = v[i].second;
    }
    wm = WaveletMatrix<T>(y);
  }

  int rectangle_count(T xl, T xr, T yl, T yr) {
    int l = distance(px.begin(), lower_bound(px.begin(), px.end(), xl));
    int r = distance(px.begin(), lower_bound(px.begin(), px.end(), xr));
    return wm.range_freq(l, r, yl, yr);
  }
};
