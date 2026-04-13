
template <class S>
struct BinomialCoefficient {
 private:
  inline static vector<S> fac, inv;

 public:
  BinomialCoefficient(int n) {
    int p = int(fac.size());
    if (p <= n) {
      fac.resize(n + 1);
      inv.resize(n + 1);
      if (p == 0) fac[0] = 1;
      for (int i = p; i < n + 1; i++) {
        if (i == 0) continue;
        fac[i] = fac[i - 1] * i;
      }
      inv[n] = fac[n].inv();
      for (int i = n; i > p; i--) {
        if (i == 0) continue;
        inv[i - 1] = inv[i] * i;
      }
    }
  }

  S nCr(int n, int r) {
    if (n < r) return S(0);
    assert(fac.size() > n and fac.size() > r);
    return fac[n] * inv[r] * inv[n - r];
  }
};