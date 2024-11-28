
template <class T>
class RangeAddRangeSum {
   private:
    int n;
    vector<T> a, add, sum;
    int bsize;

   public:
    RangeAddRangeSum(const vector<T> &v) {
        a = v;
        n = a.size();
        bsize = sqrt(n) + 1;
        add.resize(bsize, 0);
        sum.resize(bsize, 0);
        for (int i = 0; i < n; i++) {
            sum[i / bsize] += v[i];
        }
    }

    T get(int p) {
        return add[p / bsize] + a[p];
    }

    T range_sum(int l, int r) {
        T res = 0;
        if (l / bsize == r / bsize) {
            for (int i = l; i < r; i++) {
                res += a[i] + add[i / bsize];
            }
        } else {
            for (int i = l; i < l / bsize * bsize + bsize; i++) {
                res += a[i] + add[i / bsize];
            }

            for (int i = r / bsize * bsize; i < r; i++) {
                res += a[i] + add[i / bsize];
            }

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    res += sum[i] + add[i] * bsize;
                }
            }
        }
        return res;
    }

    void range_add(int l, int r, T x) {
        if (l / bsize == r / bsize) {
            for (int i = l; i < r; i++) {
                a[i] += x;
                sum[i / bsize] += x;
            }
        } else {
            for (int i = l; i < l / bsize * bsize + bsize; i++) {
                a[i] += x;
                sum[i / bsize] += x;
            }

            for (int i = r / bsize * bsize; i < r; i++) {
                a[i] += x;
                sum[i / bsize] += x;
            }

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    add[i] += x;
                }
            }
        }
    }
};