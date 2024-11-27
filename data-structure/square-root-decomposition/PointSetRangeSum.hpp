template <class T>
class PointSetRangeSum {
   private:
    int n;
    vector<T> a, sum;
    int bsize;

   public:
    PointSetRangeSum(const vector<T> &v) {
        a = v;
        n = a.size();
        bsize = sqrt(n) + 1;
        sum.resize(bsize);
        for (int i = 0; i < n; i++) {
            sum[i / bsize] += a[i];
        }
    }

    T get(int p) {
        return a[p];
    }

    void set(int p, T val) {
        sum[p / bsize] -= a[p];
        sum[p / bsize] += val;
        a[p] = val;
    }

    void add(int p, T val) {
        sum[p / bsize] += val;
        a[p] += val;
    }

    T range_sum(int l, int r) {
        if (l / bsize == r / bsize) {
            T s = 0;
            for (int i = l; i < r; i++) {
                s += a[i];
            }
            return s;
        } else {
            T l_sum = 0;
            for (int i = l; i < l / bsize * bsize + bsize; i++) {
                l_sum += a[i];
            }

            T r_sum = 0;
            for (int i = r / bsize * bsize; i < r; i++) {
                r_sum += a[i];
            }
            T mid_sum = 0;

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    mid_sum += sum[i];
                }
            }
            return l_sum + mid_sum + r_sum;
        }
    }
};