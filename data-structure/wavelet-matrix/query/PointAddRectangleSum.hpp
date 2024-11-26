#include "../WaveletMatrixBinaryIndexedTree.hpp"
template <class S>
class PointAddRectangleSum {
   private:
    const int RESERVE = 700000;
    const int QSIZE = 700000;
    WaveletMatrix<S> wm;
    vector<S> x, y, w;
    vector<vector<S>> q;
    int add_query = 0;
    int output_query = 0;
    int setidx;

   public:
    PointAddRectangleSum() {
        x.reserve(RESERVE);
        y.reserve(RESERVE);
        w.reserve(RESERVE);
        q.resize(QSIZE);
        for (int i = 0; i < QSIZE; i++) {
            q[i].assign(5, 0);
        }
        setidx = 0;
    }

    PointAddRectangleSum(int query) {
        q = vector<vector<S>>(query, vector<S>(5));
        setidx = 0;
    }

    PointAddRectangleSum(const vector<S> &vx, const vector<S> &vy, const vector<S> &vw, int query) {
        q = vector<vector<S>>(query, vector<S>(5));
        x = vx;
        y = vy;
        w = vw;
        setidx = x.size();
    }

    void add(S px, S py, S weight) {
        int cur = add_query + output_query;
        q[cur][0] = 0;
        q[cur][1] = px;
        q[cur][2] = py;
        q[cur][3] = weight;
        q[cur][4] = setidx++;
        x.emplace_back(px);
        y.emplace_back(py);
        w.emplace_back(0);
        add_query++;
    }

    void rectangle_sum(S x1, S y1, S x2, S y2) {
        int cur = add_query + output_query;
        q[cur][0] = 1;
        q[cur][1] = x1;
        q[cur][2] = y1;
        q[cur][3] = x2;
        q[cur][4] = y2;
        output_query++;
    }

    vector<S> build() {
        wm = WaveletMatrix<S>(x, y, w);
        vector<S> ret(output_query);
        int idx = 0;
        for (int i = 0; i < output_query + add_query; i++) {
            S com = q[i][0];
            if (com == 0) {
                wm.set(q[i][4], q[i][3]);
            } else {
                ret[idx] = (wm.rectangle_sum(q[i][1], q[i][3], q[i][2], q[i][4]));
                idx++;
            }
        }
        return ret;
    }
};