template <class T>
vector<T> sliding_window_minimum(const vector<T> &a, int k) {
    int n = int(a.size());
    if (n < k) return {};
    deque<int> q;
    vector<T> res(n - k + 1);
    rep(i, k) {
        while (!q.empty() and a[q.back()] >= a[i]) {
            q.pop_back();
        }
        q.emplace_back(i);
    }

    rep(i, n - k + 1) {
        res[i] = a[q.front()];
        if (i == q.front()) q.pop_front();
        while (!q.empty() and a[q.back()] >= a[i + k]) {
            q.pop_back();
        }
        q.emplace_back(i + k);
    }

    return res;
}