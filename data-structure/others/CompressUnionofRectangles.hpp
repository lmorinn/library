class UnionofRectangles {
 private:
  vector<lint> xl, yl, xr, yr, weight;
  vector<lint> tx, ty;
  vector<vector<lint>> g;
  int n, h, w;

 public:

 // 左上の座標が(xl,yl), 右下の座標が(xr,yr) で重みwの長方形N個で初期化
  UnionofRectangles(const vector<lint> &xl_, const vector<lint> &yl_, const vector<lint> &xr_, const vector<lint> &yr_, const vector<lint> &w_)
      : xl(xl_), yl(yl_), xr(xr_), yr(yr_), weight(w_) {
    n = int(xl.size());
    for (int i = 0; i < n; i++) {
      tx.emplace_back(xl[i]);
      tx.emplace_back(xr[i]);
      tx.emplace_back(xl[i] + 1);
      tx.emplace_back(xr[i] + 1);
      ty.emplace_back(yl[i]);
      ty.emplace_back(yr[i]);
      ty.emplace_back(yl[i]) + 1;
      ty.emplace_back(yr[i]) + 1;
    }
    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    tx.erase(unique(tx.begin(), tx.end()), tx.end());
    ty.erase(unique(ty.begin(), ty.end()), ty.end());
    h = int(ty.size());
    w = int(tx.size());
    g = vector<vector<lint>>(h, vector<lint>(w));
    for (int i = 0; i < n; i++) {
      xl[i] = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), xl[i]));
      xr[i] = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), xr[i]));
      yl[i] = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), yl[i]));
      yr[i] = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), yr[i]));
      g[yl[i]][xl[i]] += weight[i];
      g[yl[i]][xr[i]] -= weight[i];
      g[yr[i]][xl[i]] -= weight[i];
      g[yr[i]][xr[i]] += weight[i];
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w - 1; j++) {
        g[i][j + 1] += g[i][j];
      }
    }

    for (int j = 0; j < w; j++) {
      for (int i = 0; i < h - 1; i++) {
        g[i + 1][j] += g[i][j];
      }
    }
  }


  // [x1,x2) x [y1,y2) 内で長方形の重みの総和がFを満たす部分の面積を返す
  template <auto F>
  long long query(long long x1, long long y1, long long x2, long long y2) {
    long long ret = 0;
    x1 = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), x1));
    x2 = distance(tx.begin(), lower_bound(tx.begin(), tx.end(), x2));
    y1 = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), y1));
    y2 = distance(ty.begin(), lower_bound(ty.begin(), ty.end(), y2));
    for (int i = y1; i < y2; i++) {
      for (int j = x1; j < x2; j++) {
        if (F(g[i][j])) {
          ret += (ty[i + 1] - ty[i]) * (tx[j + 1] - tx[j]);
        }
      }
    }
    return ret;
  }
};