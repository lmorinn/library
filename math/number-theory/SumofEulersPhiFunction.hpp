int sum_of_totient(long long n) {
  if (n == 0) return 0;
  long long sq = sqrtl(n);
  vector<long long> d(sq * 2 + 1);
  long long siz = d.size();
  vector<modint998244353> dp(siz), dps(siz);
  vector<long long> prime;
  for (long long s = 1; s <= sq; s++) d[s] = n / s;
  for (long long s = 1; s <= sq; s++) d[siz - s] = s;
  for (int i = 1; i < siz; i++) {
    dp[i] = d[i] - 1;
    dps[i] = (modint998244353(d[i]) * (d[i] + 1)) / 2 - 1;
  }

  for (long long p = 2; p <= sq; p++) {
    long long p2 = p * p;
    if (dp[siz - p + 1] == dp[siz - p]) continue;
    prime.emplace_back(p);
    for (int i = 1; i < siz; i++) {
      if (d[i] < p2) break;
      long long prev = d[i] / p;
      if (prev > sq) {
        dp[i] -= dp[n / prev] - dp[siz - p + 1];
        dps[i] -= p * (dps[n / prev] - dps[siz - p + 1]);
      } else {
        dp[i] -= dp[siz - prev] - dp[siz - p + 1];
        dps[i] -= p * (dps[siz - prev] - dps[siz - p + 1]);
      }
    }
  }

  modint998244353 ans = dps[1] - dp[1] + 1;
  for (int i = 0; i < siz; i++) dps[i] -= dp[i];

  auto dfs = [&](auto &&self, long long p, long long cur, long long parent, modint998244353 f, int idx) -> void {
    long long gpf = cur / parent;
    if (cur * p <= n) {
      long long id1 = n / cur;
      ans += f * (p + dps[id1 > sq ? n / id1 : siz - id1] - dps[(gpf > sq ? n / gpf : siz - gpf)]);
      self(self, p, cur * p, cur, f * p, idx);
    }
    for (int j = idx + 1; j < prime.size() and __int128_t(cur) * prime[j] * prime[j] <= n; j++) {
      self(self, prime[j], cur * prime[j], cur, f * (prime[j] - 1), j);
    }
  };
  for (int i = 0; i < prime.size() and __int128_t(prime[i]) * prime[i] <= n; i++) {
    dfs(dfs, prime[i], prime[i], 1, prime[i] - 1, i);
  }
  return ans.val();
}
