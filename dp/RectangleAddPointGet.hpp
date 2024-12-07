template <class T>
class RectangleAddPointGet {
   private:
    vector<vector<T>> sum;
    int max_x, max_y;

   public:
    RectangleAddPointGet(int h, int w) {
        sum.resize(h + 5, vector<T>(w + 5));
        max_y = h;
        max_x = w;
    }

    // 矩形領域[yl, yr) 、[xl, xr) にvを加算する
    void rectangle_add(int yl, int yr, int xl, int xr, T v) {
        sum[yl + 1][xl + 1] += v;
        sum[yl + 1][xr] -= v;
        sum[yr][xl + 1] -= v;
        sum[yr][xr] += v;
    }

    // 二次元累積和を構築する
    void build() {
        for (int i = 0; i < max_y + 3; i++) {
            for (int j = 1; j < max_x + 3; j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }

        for (int j = 0; j < max_x + 3; j++) {
            for (int i = 1; i < max_y + 3; i++) {
                sum[i][j] += sum[i - 1][j];
            }
        }
    }

    // 点(y, x)の重みを返す
    T point_get(int y, int x) {
        return sum[y][x];
    }
};