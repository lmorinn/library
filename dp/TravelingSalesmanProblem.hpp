#pragma once
template <class T>
vector<vector<T>> tsp(vector<vector<T>> &w, int n) {
    T INF = numeric_limits<T>::max();
    vector<vector<T>> dp(n, vector<T>((1 << (n + 1)), INF));
    dp[0][0] = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        for (int cur = 0; cur < n; cur++) {
            if (dp[cur][bit] == INF) continue;
            for (int nex = 0; nex < n; nex++) {
                if ((bit / (1 << nex)) % 2 == 1) continue;
                dp[nex][bit | (1 << nex)] = min(dp[nex][bit | (1 << nex)], dp[cur][bit] + w[cur][nex]);
            }
        }
    }
    return dp;
}
