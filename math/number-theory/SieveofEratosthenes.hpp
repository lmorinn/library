#pragma once
class Eratosthenes {
  vector<bool> table;
  vector<int> minfactor;
  Eratosthenes(int n) {
    table.resize(n + 1, true);
    minfactor.resize(n + 1, -1);
    table[1] = false;
    minfactor[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!table[i]) continue;
      minfactor[i] = i;
      for (int j = i * 2; j <= n; j += i) {
        table[j] = false;
        if (minfactor[j] == -1) minfactor[j] = i;
      }
    }
  }

  // 高速素因数分解
  vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    while (n > 1) {
      int p = minfactor[n];
      int exp = 0;
      while (minfactor[n] == p) {
        n /= p;
        exp++;
      }
      res.emplace_back(p, exp);
    }
    return res;
  }

  // 素因数の種類
  int primefactor_num(int n) {
    int res = 0;
    while (n > 1) {
      int p = minfactor[n];
      int exp = 0;
      while (minfactor[n] == p) {
        n /= p;
        exp++;
      }
      res++;
    }
    return res;
  }

  // 約数の個数
  long long divisor_num(int n) {
    long long res = 1;
    while (n > 1) {
      int p = minfactor[n];
      int exp = 0;
      while (minfactor[n] == p) {
        n /= p;
        ++exp;
      }
      res *= (exp + 1);
    }
    return res;
  }

  // 約数の総和
  long long divisor_sum(int n) {
    long long res = 1;
    while (n > 1) {
      int p = minfactor[n];
      int pw = 1;
      long long sum = 0;
      while (minfactor[n] == p) {
        n /= p;
        sum += pw;
        pw *= p;
      }
      res *= sum;
    }
    return res;
  }
};
