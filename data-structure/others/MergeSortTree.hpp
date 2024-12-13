
class MergeSortTree {
 private:
  int n0;
  int n;
  int MA = 1e9 + 10;
  vector<int> px;

  vector<vector<int>> node;

  void _merge(vector<int> &par, vector<int> a, vector<int> b) {
    int siz_a = a.size();
    int siz_b = b.size();
    par.resize(siz_a + siz_b);
    int i = 0;
    int j = 0;
    for (int k = 0; k < siz_a + siz_b; k++) {
      if (i < siz_a and j < siz_b) {
        if (a[i] <= b[j]) {
          par[k] = a[i];
          i++;
        } else {
          par[k] = b[j];
          j++;
        }
      } else if (i < siz_a) {
        par[k] = a[i];
        i++;
      } else {
        par[k] = b[j];
        j++;
      }
    }
  }

  int less_count(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n0;
    if (r <= a or b <= l) return 0;
    if (a <= l and r <= b) return distance(node[k].begin(), lower_bound(node[k].begin(), node[k].end(), x));

    int cl = less_count(a, b, x, k * 2 + 1, l, (l + r) / 2);
    int cr = less_count(a, b, x, k * 2 + 2, (l + r) / 2, r);

    return cl + cr;
  }

 public:
  MergeSortTree() {}
  MergeSortTree(const vector<int> &v) {
    n = v.size();
    n0 = 1;
    while (n0 < n) n0 *= 2;
    node.resize(n0 * 2 - 1);
    for (int i = 0; i < n; i++) node[i + n0 - 1].emplace_back(v[i]);
    for (int i = n0 - 2; i >= 0; i--) _merge(node[i], node[i * 2 + 1], node[i * 2 + 2]);
  }

  MergeSortTree(vector<int> x, vector<int> y) {
    n = x.size();
    n0 = 1;
    while (n0 < n) n0 *= 2;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {x[i], y[i]};
    sort(v.begin(), v.end());
    px.resize(n);
    for (int i = 0; i < n; i++) {
      px[i] = v[i].first;
      y[i] = v[i].second;
    }

    node.resize(n0 * 2 - 1);
    for (int i = 0; i < n; i++) node[i + n0 - 1].emplace_back(y[i]);
    for (int i = n0 - 2; i >= 0; i--) _merge(node[i], node[i * 2 + 1], node[i * 2 + 2]);
  }

  int range_freq(int l, int r, int mink, int maxk) {
    return less_count(l, r, maxk) - less_count(l, r, mink);
  }

  int rectangle_freq(int lx, int rx, int ly, int ry) {
    int l = distance(px.begin(), lower_bound(px.begin(), px.end(), lx));
    int r = distance(px.begin(), lower_bound(px.begin(), px.end(), rx));
    return less_count(l, r, ry) - less_count(l, r, ly);
  }
};