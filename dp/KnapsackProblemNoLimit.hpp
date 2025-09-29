template <class T>
vector<T> knapsack(const vector<int> &w, const vector<T> &v, const int W) {
    int n = int(v.size());
    T ng = numeric_limits<T>::min();
    vector<vector<T>> dp(n + 1, vector(W + 2, ng));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (dp[i][j] != ng) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (dp[i + 1][j] != ng) dp[i + 1][min(j + w[i], W + 1)] = max(dp[i + 1][min(j + w[i], W + 1)], dp[i + 1][j] + v[i]);
        }
    }
    return {dp[n].begin(), dp[n].end() - 1};
}