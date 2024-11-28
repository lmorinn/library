
template <class T>
class RangeSetRangeMin {
   private:
    int n;
    vector<T> a, mi, lazy;
    int bsize;
    T ma;

    void push(int bidx) {
        if (lazy[bidx] != ma) {
            int start = bidx * bsize;
            int end = min(n, start + bsize);
            for (int i = start; i < end; i++) {
                a[i] = lazy[bidx];
            }
            lazy[bidx] = ma;
        }
    }

    void update(int bidx) {
        mi[bidx] = ma;
        int start = bidx * bsize;
        int end = min(n, start + bsize);
        for (int i = start; i < end; i++) {
            mi[bidx] = min(mi[bidx], a[i]);
        }
    }

   public:
    RangeSetRangeMin(const vector<T> &v) {
        ma = numeric_limits<T>::max();
        a = v;
        n = a.size();
        bsize = sqrt(n) + 1;
        lazy.resize(bsize, ma);
        mi.resize(bsize, ma);
        for (int i = 0; i < n; i++) mi[i / bsize] = min(mi[i / bsize], a[i]);
    }

    T range_min(int l, int r) {
        T res = ma;
        if (l / bsize == r / bsize) {
            push(l / bsize);
            for (int i = l; i < r; i++) res = min(res, a[i]);
        } else {
            push(l / bsize);
            for (int i = l; i < l / bsize * bsize + bsize; i++) res = min(res, a[i]);

            push(r / bsize);
            for (int i = r / bsize * bsize; i < r; i++) res = min(res, a[i]);

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    res = min(res, mi[i]);
                }
            }
        }
        return res;
    }

    void range_set(int l, int r, T x) {
        if (l / bsize == r / bsize) {
            push(l / bsize);
            for (int i = l; i < r; i++) a[i] = x;
            update(l / bsize);
        } else {
            push(l / bsize);
            for (int i = l; i < l / bsize * bsize + bsize; i++) a[i] = x;
            update(l / bsize);

            push(r / bsize);
            for (int i = r / bsize * bsize; i < r; i++) a[i] = x;
            update(r / bsize);

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    lazy[i] = x;
                    mi[i] = x;
                }
            }
        }
    }
};