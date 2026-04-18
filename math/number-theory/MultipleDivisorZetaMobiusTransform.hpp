template <class T>
vector<T> divisor_zeta(vector<T> a) {
  int n = int(a.size()) - 1;
  vector<bool> prime(n + 1, true);
  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      for (long long k = 1; k * p <= n; k++) {
        prime[k * p] = false;
        a[k * p] += a[k];
      }
    }
  }
  return a;
}

template <class T>
vector<T> divisor_mobius(vector<T> a) {
  int n = int(a.size()) - 1;
  vector<bool> prime(n + 1, true);
  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      for (long long k = n / p; k > 0; k--) {
        prime[k * p] = false;
        a[k * p] -= a[k];
      }
    }
  }
  return a;
}

template <class T>
vector<T> multiple_zeta(vector<T> a) {
  int n = int(a.size()) - 1;
  vector<bool> prime(n + 1, true);
  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      for (long long k = n / p; k > 0; k--) {
        prime[k * p] = false;
        a[k] += a[k * p];
      }
    }
  }
  return a;
}

template <class T>
vector<T> multiple_mobius(vector<T> a) {
  int n = int(a.size()) - 1;
  vector<bool> prime(n + 1, true);
  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      for (long long k = 1; k * p <= n; k++) {
        prime[k * p] = false;
        a[k] -= a[k * p];
      }
    }
  }
  return a;
}