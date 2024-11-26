
#include "./../WaveletMatrixSegtree"
using S = int;
S op(S a, S b) {
  return min(a, b);
}

S e() {
  return INT_MAX;
}
class RangeMex {
 private:
  int n;
  WaveletMatrix<S, op, e> wm;

 public:
  RangeMex(const vector<int> &v) {
    n = v.size();
    vector<int> x, y, z;
    vector<int> last(n + 1, -1);
    x.reserve(n * 2);
    y.reserve(n * 2);
    z.reserve(n * 2);

    for (int i = 0; i < n; i++) {
      if (v[i] > n) continue;
      x.emplace_back(last[v[i]]);
      y.emplace_back(i);
      z.emplace_back(v[i]);
      last[v[i]] = i;
    }

    for (int i = 0; i < n + 1; i++) {
      x.emplace_back(last[i]);
      y.emplace_back(n);
      z.emplace_back(i);
    }

    wm = WaveletMatrix<S, op, e>(x, y, z);
  }

  int range_mex(int l, int r) {
    return wm.rectangle_prod(-1, l, r, n + 1);
  }
};