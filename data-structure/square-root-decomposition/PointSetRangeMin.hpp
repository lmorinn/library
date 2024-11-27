template <class T>
class PointSetRangeMin {
   private:
    int n;
    vector<T> a, mi;
    T ma;
    int bsize;

   public:
    PointSetRangeMin(const vector<T> &v) {
        ma = numeric_limits<T>::max();
        a = v;
        n = a.size();
        bsize = sqrt(n) + 1;
        mi.resize(bsize, ma);
        for (int i = 0; i < n; i++) {
            mi[i / bsize] = min(mi[i / bsize], a[i]);
        }
    }

    T get(int p) {
        return a[p];
    }

    void set(int p, T val) {
        a[p] = val;
        int bidx = p / bsize;
        mi[bidx] = ma;
        int start = bidx * bsize;
        int end = min(n, start + bsize);
        for (int i = start; i < end; i++) {
            mi[bidx] = min(mi[bidx], a[i]);
        }
    }

    void add(int p, T val) {
        a[p] += val;
        int bidx = p / bsize;
        mi[bidx] = ma;
        int start = bidx * bsize;
        int end = min(n, start + bsize);
        for (int i = start; i < end; i++) {
            mi[bidx] = min(mi[bidx], a[i]);
        }
    }

    T range_min(int l, int r) {
        T res = ma;
        if (l / bsize == r / bsize) {
            for (int i = l; i < r; i++) {
                if (res > a[i]) {
                    res = a[i];
                }
            }
            return res;
        } else {
            for (int i = l; i < l / bsize * bsize + bsize; i++) {
                if (res > a[i]) {
                    res = a[i];
                }
            }

            for (int i = r / bsize * bsize; i < r; i++) {
                if (res > a[i]) {
                    res = a[i];
                }
            }

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    if (res > mi[i]) {
                        res = mi[i];
                    }
                }
            }
            return res;
        }
    }
};