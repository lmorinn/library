#include "Factorize.hpp"

vector<long long> enumerate_divisors(long long n, bool sorted_result = false) {
  vector<long long> res = {1};
  long long before = -1;
  long long mul;
  int siz_before = 1;
  for (const long long p : factorize(n)) {
    mul = (p == before ? mul * p : p);
    int siz = (p == before ? siz_before : int(res.size()));
    for (int i = 0; i < siz; i++) {
      res.emplace_back(res[i] * mul);
    }
    before = p;
    siz_before = siz;
  }
  if (sorted_result) sort(res.begin(), res.end());
  return res;
}