
template <class T>
vector<T> subset_zeta(int n, vector<T> a) {
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < (1 << n); t++) {
      if (t & (1 << i)) a[t] += a[t ^ (1 << i)];
    }
  }
  return a;
}

template <class T>
vector<T> subset_mobius(int n, vector<T> a) {
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < (1 << n); t++) {
      if (t & (1 << i)) a[t] -= a[t ^ (1 << i)];
    }
  }
  return a;
}

template <class T>
vector<T> superset_zeta(int n, vector<T> a) {
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < (1 << n); t++) {
      if (!(t & (1 << i))) a[t] += a[t | (1 << i)];
    }
  }
  return a;
}

template <class T>
vector<T> superset_mobius(int n, vector<T> a) {
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < (1 << n); t++) {
      if (!(t & (1 << i))) a[t] -= a[t | (1 << i)];
    }
  }
  return a;
}