#include "./PointAddRectangleSum.hpp"

template <class S>
class RectangleAddPointGet {
   private:
    vector<S> x1, y1, x2, y2, w;
    vector<vector<S>> q;
    int add_query = 0;
    int output_query = 0;
    int dft;

   public:
    RectangleAddPointGet() {}

    RectangleAddPointGet(int query) {
        q = vector<vector<S>>(query, vector<S>(3));
    }

    RectangleAddPointGet(const vector<S> &lx, const vector<S> &ly, const vector<S> &rx, const vector<S> &ry, const vector<S> &vw, int query) {
        q = vector<vector<S>>(query, vector<S>(3));
        int n = lx.size();
        dft = n;
        x1.assign(n * 4, 0);
        y1.assign(n * 4, 0);
        w.assign(n * 4, 0);
        for (int i = 0; i < n; i++) {
            x1[i * 4] = lx[i];
            y1[i * 4] = ly[i];

            x1[i * 4 + 1] = rx[i];
            y1[i * 4 + 1] = ly[i];

            x1[i * 4 + 2] = lx[i];
            y1[i * 4 + 2] = ry[i];

            x1[i * 4 + 3] = rx[i];
            y1[i * 4 + 3] = ry[i];

            w[i * 4] = vw[i];
            w[i * 4 + 1] = -vw[i];
            w[i * 4 + 2] = -vw[i];
            w[i * 4 + 3] = vw[i];
        }
    }

    void rectangle_add(S lx, S ly, S rx, S ry, S weight) {
        int cur = add_query + output_query;
        q[cur][0] = 0;
        q[cur][1] = weight;
        x1.emplace_back(lx);
        y1.emplace_back(ly);
        x1.emplace_back(rx);
        y1.emplace_back(ly);
        x1.emplace_back(lx);
        y1.emplace_back(ry);
        x1.emplace_back(rx);
        y1.emplace_back(ry);
        for (int i = 0; i < 4; i++) {
            w.emplace_back(0);
        }
        add_query++;
    }

    void get(S x, S y) {
        int cur = add_query + output_query;
        q[cur][0] = 1;
        q[cur][1] = x + 1;
        q[cur][2] = y + 1;
        output_query++;
    }

    vector<S> build() {
        PointAddRectangleSum<S> wm(x1, y1, w, add_query * 4 + output_query);
        int cnt = dft * 4;
        for (int i = 0; i < output_query + add_query; i++) {
            S com = q[i][0];
            if (com == 0) {
                wm.add(x1[cnt], y1[cnt], q[i][1]);
                wm.add(x1[cnt + 1], y1[cnt + 1], -q[i][1]);
                wm.add(x1[cnt + 2], y1[cnt + 2], -q[i][1]);
                wm.add(x1[cnt + 3], y1[cnt + 3], q[i][1]);
                cnt += 4;
            } else {
                wm.rectangle_sum(0, 0, q[i][1], q[i][2]);
            }
        }
        return wm.build();
    }
};