template <class T>
class PointAddRectangleSum {
   private:
    vector<vector<T>> sum;
    int max_x, max_y;

   public:
    PointAddRectangleSum(int h, int w) {
        sum.resize(h + 5, vector<T>(w + 5));
        max_y = h;
        max_x = w;
    }

    // (y, x) にvを加算する
    void point_add(int y, int x, T v) {
        sum[y][x] += v;
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

    T rectangle_sum(int yl, int yr, int xl, int xr) {
        yl = max(0, yl - 1);
        xl = max(0, xl - 1);
        yr = min(max_y + 1, yr);
        xr = min(max_x + 1, xr);
        return sum[yr - 1][xr - 1] + sum[yl][xl] - sum[yl][xr - 1] - sum[yr - 1][xl];
    }

    T point_get(int y, int x) {
        return rectangle_sum(y, y + 1, x, x + 1);
    }
};
