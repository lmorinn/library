struct FPS : vector<mint> {
  using vector<mint>::vector;
  using vector<mint>::operator=;

  FPS inv() {
    int n = int((*this).size());
    FPS res = {(*this)[0].inv()};
    while (int(res.size()) < n) {
      int m = int(res.size());
      // f = f[0, 2m)
      FPS f((*this).begin(), (*this).begin() + min(n, m << 1));
      FPS inv_f(res);
      f.resize(m << 1);
      internal::butterfly(f);
      inv_f.resize(m << 1);
      internal::butterfly(inv_f);
      // f = f*g
      for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];
      internal::butterfly_inv(f);

      // f = f[m, 2m)
      f.erase(f.begin(), f.begin() + m);
      f.resize(m << 1);
      // f = f*g
      internal::butterfly(f);
      for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];
      internal::butterfly_inv(f);
      mint m2i = mint(m << 1).inv();
      m2i *= -m2i;
      for (int i = 0; i < m << 1; i++) f[i] *= m2i;
      res.insert(res.end(), f.begin(), f.begin() + m);
    }
    return {res.begin(), res.begin() + n};
  }

  FPS exp() {
    int n = int((*this).size());
    FPS res = {1};
    assert((*this)[0] == 0);
    for (int siz = 1; siz < n; siz <<= 1) {
      FPS f(siz << 1);
      f[0] = 1;
      res.resize(siz << 1);
      FPS lg = res.log();
      for (int i = 0; i < siz << 1; i++) f[i] -= lg[i];
      for (int i = 0; i < min(siz << 1, n); i++) f[i] += (*this)[i];
      res *= f;
    }
    return {res.begin(), res.begin() + n};
  }

  FPS log() {
    FPS res = (*this).differentiate();
    res /= (*this);
    return res.integrate();
  }

  FPS pow(__int128_t m) {
    __int128_t n = int((*this).size());
    if (m == 0) {
      FPS res(n);
      if (n) res[0] = 1;
      return res;
    }
    // 定数項を1にする
    for (__int128_t i = 0; i < n; i++) {
      if ((*this)[i] != 0) {
        mint coef = (*this)[i];
        FPS f((*this).begin() + i, (*this).end());
        if (coef != 1) {
          for (int j = 0; j < n - i; j++) f[j] /= coef;
        }
        f = f.log();
        for (int j = 0; j < n - i; j++) f[j] *= m;
        f = f.exp();
        coef = coef.pow(m);
        for (int j = 0; j < n - i; j++) f[j] *= coef;
        FPS res(min(__int128_t(m) * i, n), 0);
        if (res.size() < n) res.insert(res.end(), f.begin(), f.begin() + min(__int128_t(n), n - res.size()));
        return res;
      }
      if (__int128_t(i + 1) * m >= n) return FPS(n, 0);
    }
    return FPS(n, 0);
  }

  FPS differentiate() {
    int n = int((*this).size());
    FPS res(n);
    for (int i = 0; i < n - 1; i++) res[i] = (*this)[i + 1] * mint(i + 1);
    res[n - 1] = 0;
    return res;
  }

  FPS integrate() {
    int n = int((*this).size());
    vector<mint> iv(n);
    iv[1] = 1;
    for (int i = 2; i < n; i++) iv[i] = iv[998244353 % i] * (-(998244353 / i));
    FPS res(n);
    res[0] = 0;
    for (int i = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];
    return res;
  }

  FPS& operator*=(const FPS& g) {
    int n = int((*this).size());
    *this = convolution(*this, g);
    (*this).resize(n);
    return *this;
  }

  FPS& operator/=(FPS& g) {
    int n = int((*this).size());
    *this = convolution(*this, g.inv());
    (*this).resize(n);
    return *this;
  }
};