int sum_of_multiplicative(long long n, long long a, long long b, int mod = 469762049) {
  modint::set_mod(mod);
  if (n == 0) return 0;
  long long sq = sqrtl(n);
  vector<long long> d(sq * 2 + 1);
  long long siz = d.size();
  vector<modint> dp(siz), dps(siz);
  vector<long long> prime;
  for (long long s = 1; s <= sq; s++) d[s] = n / s;
  for (long long s = 1; s <= sq; s++) d[siz - s] = s;
  for (int i = 1; i < siz; i++) {
    dp[i] = d[i] - 1;
    dps[i] = (modint(d[i]) * (d[i] + 1)) / 2 - 1;
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
  for (int i = 0; i < siz; i++) {
    dps[i] *= b;
    dps[i] += dp[i] * a + 1;
  }
  modint ans = dps[1];

  auto dfs = [&](auto &&self, long long p, long long cur, long long parent, modint bf, modint f, int idx) -> void {
    long long gpf = cur / parent;
    if (cur * p <= n) {
      long long id1 = n / cur;
      ans += f * (dps[id1 > sq ? n / id1 : siz - id1] - dps[(gpf > sq ? n / gpf : siz - gpf)]);
      ans += f + a * bf;
      self(self, p, cur * p, cur, bf, f + a * bf, idx);
    }
    for (int j = idx + 1; j < prime.size() and __int128_t(cur) * prime[j] * prime[j] <= n; j++) {
      self(self, prime[j], cur * prime[j], cur, f, (prime[j] * b + a) * f, j);
    }
  };
  for (int i = 0; i < prime.size() and __int128_t(prime[i]) * prime[i] <= n; i++) {
    dfs(dfs, prime[i], prime[i], 1, 1, prime[i] * b + a, i);
  }
  return ans.val();
}
