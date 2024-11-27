template <class T>
class RangeAddPointGet {
   private:
    int n;
    vector<T> a, add;
    int bsize;

   public:
    RangeAddPointGet(const vector<T> &v) {
        a = v;
        n = a.size();
        bsize = sqrt(n) + 1;
        add.resize(bsize, 0);
    }

    T get(int p) {
        return add[p / bsize] + a[p];
    }

    void set(int p, T val) {
        int bidx = p / bsize;
        if (add[bidx] != 0) {
            int start = bidx * bsize;
            int end = min(n, start + bsize);
            for (int i = start; i < end; i++) {
                a[i] += add[bidx];
            }
            add[bidx] = 0;
        }
        a[p] = val;
    }

    void range_add(int l, int r, T x) {
        if (l / bsize == r / bsize) {
            for (int i = l; i < r; i++) {
                a[i] += x;
            }
        } else {
            for (int i = l; i < l / bsize * bsize + bsize; i++) {
                a[i] += x;
            }

            for (int i = r / bsize * bsize; i < r; i++) {
                a[i] += x;
            }

            for (int i = 0; i < bsize; i++) {
                if (l < i * bsize and (i + 1) * bsize <= r) {
                    add[i] += x;
                }
            }
        }
    }
};