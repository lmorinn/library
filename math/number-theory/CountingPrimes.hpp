long long count_prime(long long n) {
  long long sq = sqrtl(n);
  vector<long long> d(sq * 2 + 1);
  long long siz = d.size();
  vector<long long> dp(siz);
  for (long long s = 1; s <= sq; s++) d[s] = n / s;
  for (long long s = 1; s <= sq; s++) d[siz - s] = s;
  for (int i = 1; i < siz; i++) dp[i] = d[i] - 1;

  for (long long p = 2; p <= sq; p++) {
    long long p2 = p * p;
    if (dp[siz - p + 1] == dp[siz - p]) continue;
    for (int i = 1; i < siz; i++) {
      if (d[i] < p2) break;
      long long prev = d[i] / p;
      if (prev > sq) {
        dp[i] -= dp[n / prev] - dp[siz - p + 1];
      } else {
        dp[i] -= dp[siz - prev] - dp[siz - p + 1];
      }
    }
  }
  return dp[1];
}