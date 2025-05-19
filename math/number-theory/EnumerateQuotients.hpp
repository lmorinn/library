vector<long long> enumerate_quotients(long long n) {
  long long sq = sqrtl(n);
  vector<long long> d(sq);
  iota(d.begin(), d.end(), 1);
  long long siz = d.size();
  for (long long s = sq; s >= 1; s--) {
    if (n / s != s) d.emplace_back(n / s);
  }
  return d;
}