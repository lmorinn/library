template <class T>
class SegtreeBeats {
   private:
    T MA, MI;
    int n;
    int n0;
    vector<T> max_1_val, max_2_val, min_1_val, min_2_val, sum, add;
    vector<int> max_1_cnt, min_1_cnt, len;

    void query_chmin(int a, int b, int k, int l, int r, T x) {
        if (b <= l or r <= a or max_1_val[k] <= x) {
            return;
        }

        if (a <= l and r <= b and max_2_val[k] < x) {
            update_node_max(k, x);
            return;
        }

        push(k);

        query_chmin(a, b, (k << 1) | 1, l, (l + r) >> 1, x);
        query_chmin(a, b, (k + 1) << 1, (l + r) >> 1, r, x);

        update(k);
    }

    void query_chmax(int a, int b, int k, int l, int r, T x) {
        if (b <= l or r <= a or x <= min_1_val[k]) {
            return;
        }

        if (a <= l and r <= b and x < min_2_val[k]) {
            update_node_min(k, x);
            return;
        }

        push(k);

        query_chmax(a, b, (k << 1) | 1, l, (l + r) >> 1, x);
        query_chmax(a, b, (k + 1) << 1, (l + r) >> 1, r, x);

        update(k);
    }

    T query_max(int a, int b, int k, int l, int r) {
        if (b <= l or r <= a) {
            return MI;
        }

        if (a <= l and r <= b) {
            return max_1_val[k];
        }

        push(k);
        T l_max = query_max(a, b, (k << 1) | 1, l, (l + r) >> 1);
        T r_max = query_max(a, b, (k + 1) << 1, (l + r) >> 1, r);
        return max(l_max, r_max);
    }

    T query_min(int a, int b, int k, int l, int r) {
        if (b <= l or r <= a) {
            return MA;
        }

        if (a <= l and r <= b) {
            return min_1_val[k];
        }

        push(k);
        T l_max = query_min(a, b, (k << 1) | 1, l, (l + r) >> 1);
        T r_max = query_min(a, b, (k + 1) << 1, (l + r) >> 1, r);
        return min(l_max, r_max);
    }

    T query_sum(int a, int b, int k, int l, int r) {
        if (b <= l or r <= a) {
            return 0;
        }

        if (a <= l and r <= b) {
            return sum[k];
        }

        push(k);
        T l_sum = query_sum(a, b, (k << 1) | 1, l, (l + r) >> 1);
        T r_sum = query_sum(a, b, (k + 1) << 1, (l + r) >> 1, r);
        return l_sum + r_sum;
    }

    void query_add(int a, int b, int k, int l, int r, T x) {
        if (b <= l or r <= a) {
            return;
        }

        if (a <= l and r <= b) {
            add_node(k, x);
            return;
        }

        push(k);
        query_add(a, b, (k << 1) | 1, l, (l + r) >> 1, x);
        query_add(a, b, (k + 1) << 1, (l + r) >> 1, r, x);
        update(k);
    }

    void update_node_max(int k, T x) {
        sum[k] += (x - max_1_val[k]) * max_1_cnt[k];
        if (max_1_val[k] == min_1_val[k]) {
            max_1_val[k] = x;
            min_1_val[k] = x;
        } else if (max_1_val[k] == min_2_val[k]) {
            max_1_val[k] = x;
            min_2_val[k] = x;
        } else {
            max_1_val[k] = x;
        }
    }

    void update_node_min(int k, T x) {
        sum[k] += (x - min_1_val[k]) * min_1_cnt[k];

        if (max_1_val[k] == min_1_val[k]) {
            max_1_val[k] = x;
            min_1_val[k] = x;
        } else if (max_2_val[k] == min_1_val[k]) {
            max_2_val[k] = x;
            min_1_val[k] = x;
        } else {
            min_1_val[k] = x;
        }
    }

    void add_node(int k, T x) {
        max_1_val[k] += x;
        if (max_2_val[k] != MI) {
            max_2_val[k] += x;
        }
        min_1_val[k] += x;
        if (min_2_val[k] != MA) {
            min_2_val[k] += x;
        }

        sum[k] += len[k] * x;
        add[k] += x;
    }

    void push(int k) {
        if (add[k] != 0) {
            add_node((k << 1) | 1, add[k]);
            add_node((k + 1) << 1, add[k]);
            add[k] = 0;
        }

        if (max_1_val[k] < max_1_val[(k << 1) | 1]) {
            update_node_max((k << 1) | 1, max_1_val[k]);
        }

        if (max_1_val[k] < max_1_val[(k + 1) << 1]) {
            update_node_max((k + 1) << 1, max_1_val[k]);
        }

        if (min_1_val[k] > min_1_val[(k << 1) | 1]) {
            update_node_min((k << 1) | 1, min_1_val[k]);
        }

        if (min_1_val[k] > min_1_val[(k + 1) << 1]) {
            update_node_min((k + 1) << 1, min_1_val[k]);
        }
    }

    void update(int k) {
        sum[k] = sum[(k << 1) | 1] + sum[(k + 1) << 1];

        if (max_1_val[(k << 1) | 1] < max_1_val[(k + 1) << 1]) {
            max_1_val[k] = max_1_val[(k + 1) << 1];
            max_1_cnt[k] = max_1_cnt[(k + 1) << 1];
            max_2_val[k] = max(max_1_val[(k << 1) | 1], max_2_val[(k + 1) << 1]);
        } else if (max_1_val[(k << 1) | 1] > max_1_val[(k + 1) << 1]) {
            max_1_val[k] = max_1_val[(k << 1) | 1];
            max_1_cnt[k] = max_1_cnt[(k << 1) | 1];
            max_2_val[k] = max(max_2_val[(k << 1) | 1], max_1_val[(k + 1) << 1]);
        } else {
            max_1_val[k] = max_1_val[(k << 1) | 1];
            max_1_cnt[k] = max_1_cnt[(k << 1) | 1] + max_1_cnt[(k + 1) << 1];
            max_2_val[k] = max(max_2_val[(k << 1) | 1], max_2_val[(k + 1) << 1]);
        }

        if (min_1_val[(k << 1) | 1] < min_1_val[(k + 1) << 1]) {
            min_1_val[k] = min_1_val[(k << 1) | 1];
            min_1_cnt[k] = min_1_cnt[(k << 1) | 1];
            min_2_val[k] = min(min_2_val[(k << 1) | 1], min_1_val[(k + 1) << 1]);
        } else if (min_1_val[(k << 1) | 1] > min_1_val[(k + 1) << 1]) {
            min_1_val[k] = min_1_val[(k + 1) << 1];
            min_1_cnt[k] = min_1_cnt[(k + 1) << 1];
            min_2_val[k] = min(min_1_val[(k << 1) | 1], min_2_val[(k + 1) << 1]);
        } else {
            min_1_val[k] = min_1_val[(k << 1) | 1];
            min_1_cnt[k] = min_1_cnt[(k << 1) | 1] + min_1_cnt[(k + 1) << 1];
            min_2_val[k] = min(min_2_val[(k << 1) | 1], min_2_val[(k + 1) << 1]);
        }
    }

   public:
    SegtreeBeats(const vector<T> &v) {
        MA = numeric_limits<T>::max();
        MI = numeric_limits<T>::min();
        n = v.size();
        n0 = 1;
        while (n0 < n) {
            n0 <<= 1;
        }
        sum.assign((n0 << 1), 0);
        add.assign((n0 << 1), 0);
        len.assign((n0 << 1), 0);
        max_1_val.assign((n0 << 1), MI);
        max_2_val.assign((n0 << 1), MI);
        min_1_val.assign((n0 << 1), MA);
        min_2_val.assign((n0 << 1), MA);
        max_1_cnt.assign((n0 << 1), 0);
        min_1_cnt.assign((n0 << 1), 0);

        for (int i = 0; i < (n0 << 1); i++) {
            add[i] = 0;
        }
        len[0] = n0;
        for (int i = 0; i < n0 - 1; i++) {
            len[(i << 1) | 1] = (len[i] >> 1);
            len[(i + 1) << 1] = (len[i] >> 1);
        }

        for (int i = 0; i < n; i++) {
            max_1_val[n0 - 1 + i] = v[i];
            min_1_val[n0 - 1 + i] = v[i];
            sum[n0 - 1 + i] = v[i];
            max_1_cnt[n0 - 1 + i] = 1;
            min_1_cnt[n0 - 1 + i] = 1;
        }

        for (int i = n0 - 2; i >= 0; i--) {
            update(i);
        }
    }

    void range_chmin(int l, int r, T x) {
        query_chmin(l, r, 0, 0, n0, x);
    }

    void range_chmax(int l, int r, T x) {
        query_chmax(l, r, 0, 0, n0, x);
    }

    void range_add(int l, int r, T x) {
        query_add(l, r, 0, 0, n0, x);
    }

    void range_update(int l, int r, T x) {
        query_chmax(l, r, MA);
        query_chmin(l, r, x);
    }

    T range_max(int l, int r) {
        return query_max(l, r, 0, 0, n0);
    }

    T range_min(int l, int r) {
        return query_min(l, r, 0, 0, n0);
    }

    T range_sum(int l, int r) {
        return query_sum(l, r, 0, 0, n0);
    }

    T get(int p) {
        return range_sum(p, p + 1);
    }

    T set(int p, T x) {
        range_update(p, p + 1, x);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << get(i) << (i == n - 1) ? '\n' : " ";
        }
    }
};