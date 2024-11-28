
template <class T>
class RangeChminChmaxAddRangeSum {
   private:
    int n;
    vector<T> a, sum, offset;
    vector<int> divi;
    vector<bool> modulo;

    vector<deque<pair<T, int>>> deq;
    int bsize, bnum;

    inline void build(int bidx) {
        sum[bidx] = 0;
        offset[bidx] = 0;
        map<T, int> cnt;
        int l = bidx * bsize;
        int r = min(n, l + bsize);
        for (int i = l; i < r; i++) {
            cnt[a[i]]++;
            sum[bidx] += a[i];
        }
        deq[bidx].assign(begin(cnt), end(cnt));
    }

    inline void push(int bidx) {
        sum[bidx] += offset[bidx] * (min((bidx + 1) * bsize, n) - bidx * bsize);
        T lower = offset[bidx] + deq[bidx].front().first;
        T upper = offset[bidx] + deq[bidx].back().first;
        for (int i = bidx * bsize; i < min((bidx + 1) * bsize, n); i++) {
            a[i] = min(max(a[i] + offset[bidx], lower), upper);
        }
    }

   public:
    RangeChminChmaxAddRangeSum(const vector<T> &v) {
        a = v;
        n = a.size();
        divi.resize(n + 1);
        modulo.assign(n + 1, false);
        bsize = 250;
        bnum = (n + bsize - 1) / bsize;
        deq.resize(bnum);
        sum.assign(bnum, 0);
        offset.assign(bnum, 0);
        for (int i = 0; i < n + 1; i++) {
            divi[i] = i / bsize;
            modulo[i] = ((i % bsize) != 0);
        }

        for (int i = 0; i < bnum; i++) {
            build(i);
        }
    }

    void range_chmin(int l, int r, T x) {
        // 左端
        if (modulo[l]) {
            push(divi[l]);
            while (l < r and modulo[l]) {
                a[l] = min(a[l], x);
                l++;
            }
            build(divi[l - 1]);
        }

        // 右端
        if (modulo[r]) {
            push(divi[r]);
            while (l < r and modulo[r]) {
                r--;
                a[r] = min(a[r], x);
            }
            build(divi[r]);
        }

        // バケット全体
        while (l < r) {
            int i = divi[l];
            while (offset[i] + deq[i].back().first > x) {
                auto p = deq[i].back();
                deq[i].pop_back();
                if (deq[i].empty() or offset[i] + deq[i].back().first < x) {
                    deq[i].emplace_back(x - offset[i], 0);
                }
                sum[i] -= (p.first - deq[i].back().first) * p.second;
                deq[i].back().second += p.second;
            }
            l += bsize;
        }
    }

    void range_chmax(int l, int r, T x) {
        // 左端
        if (modulo[l]) {
            push(divi[l]);
            while (l < r and modulo[l]) {
                a[l] = max(a[l], x);
                l++;
            }
            build(divi[l - 1]);
        }

        // 右端
        if (modulo[r]) {
            push(divi[r]);
            while (l < r and modulo[r]) {
                r--;
                a[r] = max(a[r], x);
            }
            build(divi[r]);
        }

        // バケット全体
        while (l < r) {
            int i = divi[l];
            while (offset[i] + deq[i].front().first < x) {
                auto p = deq[i].front();
                deq[i].pop_front();
                if (deq[i].empty() or offset[i] + deq[i].front().first > x) {
                    deq[i].emplace_front(x - offset[i], 0);
                }
                sum[i] += (deq[i].front().first - p.first) * p.second;
                deq[i].front().second += p.second;
            }
            l += bsize;
        }
    }

    void range_add(int l, int r, T x) {
        // 左端
        if (modulo[l]) {
            push(divi[l]);
            while (l < r and modulo[l]) {
                a[l] += x;
                l++;
            }
            build(divi[l - 1]);
        }

        // 右端
        if (modulo[r]) {
            push(divi[r]);
            while (l < r and modulo[r]) {
                r--;
                a[r] += x;
            }
            build(divi[r]);
        }

        // バケット全体
        while (l < r) {
            int i = divi[l];
            offset[i] += x;
            l += bsize;
        }
    }

    T range_sum(int l, int r) {
        T res = 0;
        // 左端
        if (modulo[l]) {
            push(divi[l]);
            while (l < r and modulo[l]) {
                res += a[l];
                l++;
            }
            build(divi[l - 1]);
        }

        // 右端
        if (modulo[r]) {
            push(divi[r]);
            while (l < r and modulo[r]) {
                r--;
                res += a[r];
            }
            build(divi[r]);
        }

        // バケット全体
        while (l < r) {
            int i = divi[l];
            res += offset[i] * (min((i + 1) * bsize, n) - i * bsize) + sum[i];
            l += bsize;
        }
        return res;
    }
};