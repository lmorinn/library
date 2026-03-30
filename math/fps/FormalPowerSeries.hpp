template <class S>
struct FPS;

template <class S>
struct SFPS : vector<pair<int, S>> {
  using vector<pair<int, S>>::vector;
  using vector<pair<int, S>>::operator=;

  FPS<S> log(int deg);
  FPS<S> exp(int deg);
  FPS<S> pow(long long m, int deg);
};

template <class S>
struct FPS : vector<S> {
  using vector<S>::vector;
  using vector<S>::operator=;

  FPS<S> inv() const {
    int n = int((*this).size());
    FPS<S> res = {(*this)[0].inv()};
    while (int(res.size()) < n) {
      int m = int(res.size());
      // f = f[0, 2m)
      FPS<S> f((*this).begin(), (*this).begin() + min(n, m << 1));
      FPS<S> inv_f(res);
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
      S m2i = S(m << 1).inv();
      m2i *= -m2i;
      for (int i = 0; i < m << 1; i++) f[i] *= m2i;
      res.insert(res.end(), f.begin(), f.begin() + m);
    }
    return {res.begin(), res.begin() + n};
  }

  FPS<S> exp() const {
    int n = int((*this).size());
    FPS<S> res = {1};
    assert((*this)[0] == 0);
    for (int siz = 1; siz < n; siz <<= 1) {
      FPS<S> f(siz << 1);
      f[0] = 1;
      res.resize(siz << 1);
      FPS<S> lg = res.log();
      for (int i = 0; i < siz << 1; i++) f[i] -= lg[i];
      for (int i = 0; i < min(siz << 1, n); i++) f[i] += (*this)[i];
      res *= f;
    }
    return {res.begin(), res.begin() + n};
  }

  FPS<S> log() const {
    FPS<S> res = *this;
    res.log_inplace();
    return res;
  }

  FPS<S> pow(__int128_t m) const {
    __int128_t n = int((*this).size());
    if (m == 0) {
      FPS<S> res(n);
      if (n) res[0] = 1;
      return res;
    }
    // 定数項を1にする
    for (__int128_t i = 0; i < n; i++) {
      if ((*this)[i] != 0) {
        S coef = (*this)[i];
        FPS<S> f((*this).begin() + i, (*this).end());
        if (coef != 1) {
          for (int j = 0; j < n - i; j++) f[j] /= coef;
        }
        f.log_inplace();
        for (int j = 0; j < n - i; j++) f[j] *= m;
        f.exp_inplace();
        coef = coef.pow(m);
        for (int j = 0; j < n - i; j++) f[j] *= coef;
        FPS<S> res(min(__int128_t(m) * i, n), 0);
        if (res.size() < n) res.insert(res.end(), f.begin(), f.begin() + min(__int128_t(n), n - res.size()));
        return res;
      }
      if (__int128_t(i + 1) * m >= n) return FPS<S>(n, 0);
    }
    return FPS<S>(n, 0);
  }

  FPS<S> differentiate() const {
    int n = int((*this).size());
    FPS<S> res(n);
    for (int i = 0; i < n - 1; i++) res[i] = (*this)[i + 1] * S(i + 1);
    res[n - 1] = 0;
    return res;
  }

  FPS<S> integrate() const {
    int n = int((*this).size());
    vector<S> iv(n);
    iv[1] = 1;
    for (int i = 2; i < n; i++) iv[i] = iv[S::mod() % i] * (-(S::mod() / i));
    FPS<S> res(n);
    res[0] = 0;
    for (int i = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];
    return res;
  }

  void integrate_inplace() {
    int n = int((*this).size());
    static vector<S> inv{0, 1};
    if (int(inv.size()) < n) {
      int old_siz = inv.size();
      inv.resize(n);
      int mod = S::mod();
      for (int i = old_siz; i < n; i++) inv[i] = -inv[mod % i] * (mod / i);
    }
    for (int i = n - 1; i > 0; i--) (*this)[i] = (*this)[i - 1] * inv[i];
    (*this)[0] = 0;
  }

  void differentiate_inplace() {
    int n = int((*this).size());
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) {
      (*this)[i] = (*this)[i + 1] * S(i + 1);
    }
    (*this)[n - 1] = 0;
  }

  void inv_inplace() {
    *this = this->inv();
  }
  void exp_inplace() {
    *this = this->exp();
  }

  void log_inplace() {
    assert(!this->empty() and (*this)[0] == 1);
    FPS<S> inv_f = this->inv();
    this->differentiate_inplace();
    *this *= inv_f;
    this->integrate_inplace();
  }

  void pow_inplace(__int128_t m) {
    *this = this->pow(m);
  }

  FPS<S>& operator*=(const FPS<S>& g) {
    int n = int((*this).size());
    *this = convolution(*this, g);
    (*this).resize(n);
    return *this;
  }

  FPS<S>& operator/=(FPS<S>& g) {
    int n = int((*this).size());
    *this = convolution(*this, g.inv());
    (*this).resize(n);
    return *this;
  }

  FPS<S>& operator<<=(int k) {
    int n = int((*this).size());
    if (k >= n) {
      (*this).assign(n, 0);
      return *this;
    }
    for (int i = n - 1; i >= k; i--) (*this)[i] = (*this)[i - k];
    for (int i = 0; i < k; i++) (*this)[i] = 0;
    return *this;
  }

  FPS<S>& operator>>=(int k) {
    int n = int((*this).size());
    if (k >= n) {
      (*this).assign(n, 0);
      return *this;
    }
    for (int i = 0; i < n - k; i++) (*this)[i] = (*this)[i + k];
    for (int i = n - k; i < n; i++) (*this)[i] = 0;
    return *this;
  }

  FPS<S>& operator*=(const SFPS<S>& g) {
    int n = (*this).size();
    int k = int(g.size());
    auto [d, c] = g.front();
    int start = 0;
    if (d == 0) {
      start = 1;
    } else {
      c = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
      (*this)[i] *= c;
      for (int j = start; j < k; j++) {
        const auto& [d_, c_] = g[j];
        if (d_ > i) break;
        (*this)[i] += (*this)[i - d_] * c_;
      }
    }
    return *this;
  }

  FPS<S>& operator/=(const SFPS<S>& g) {
    int n = (*this).size();
    int k = int(g.size());
    auto [d, c] = g.front();
    assert(d == 0 and c != 0);
    S inv = c.inv();
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < k; j++) {
        const auto& [d, c] = g[j];
        if (d > i) break;
        (*this)[i] -= (*this)[i - d] * c;
      }
      (*this)[i] *= inv;
    }
    return *this;
  }

  FPS<S> operator<<(int k) const { return FPS<S>(*this) <<= k; }
  FPS<S> operator>>(int k) const { return FPS<S>(*this) >>= k; }
};

template <class S>
FPS<S> SFPS<S>::log(int deg) {
  FPS<S> f(deg);
  assert((*this)[0].first == 0 and (*this)[0].second == 1 and (*this).back().first < deg);
  int k = (*this).size();
  for (int i = 0; i < k; i++) {
    const auto& [d, c] = (*this)[i];
    f[d] = c;
  }
  f.differentiate_inplace();
  f /= (*this);
  f.integrate_inplace();
  return f;
}

template <class S>
FPS<S> SFPS<S>::exp(int deg) {
  SFPS df = (*this);
  int k = (*this).size();
  vector<S> inv(deg);
  inv[1] = 1;
  for (int i = 2; i < deg; i++) inv[i] = inv[S::mod() % i] * (-(S::mod() / i));

  // df = f'
  for (int i = 0; i < k; i++) {
    const auto& [d, c] = df[i];
    df[i] = {d - 1, d * c};
  }

  // F = exp(f)
  // F' = f'F
  FPS<S> F(deg);
  F[0] = 1;
  for (int i = 0; i < deg - 1; i++) {
    S conv_sum = 0;
    for (int j = 0; j < k; j++) {
      const auto& [d, c] = df[j];
      if (d > i) break;
      conv_sum += c * F[i - d];
    }
    F[i + 1] = conv_sum * inv[i + 1];
  }
  return F;
}

template <class S>
FPS<S> SFPS<S>::pow(long long m, int deg) {
  if (m == 0) {
    FPS<S> res(deg);
    if (deg) res[0] = 1;
    return res;
  }
  vector<S> inv(deg);
  inv[1] = 1;
  for (int i = 2; i < deg; i++) inv[i] = inv[S::mod() % i] * (-(S::mod() / i));

  int k = (*this).size();
  // F = f ^ m
  FPS<S> F(deg);
  // F' = m(f^(n-1))f'
  // fF' = mFf'

  // 定数項を1にする
  for (int i = 0; i < k; i++) {
    const auto& [d, c] = (*this)[i];
    if (c != 0) {
      SFPS f((*this).begin() + i, (*this).end());
      for (int j = 0; j < f.size(); j++) {
        f[j].first -= d;
        f[j].second /= c;
      }

      FPS<S> F(deg);
      F[0] = 1;
      for (int j = 0; j < deg - 1; j++) {
        S dF_j = 0;
        for (int l = 0; l < f.size(); l++) {
          const auto& [d_, c_] = f[l];
          if (d_ == 0) continue;
          if (d_ - 1 > j) break;
          dF_j += c_ * F[j - d_ + 1] * (S(m) * d_ - (j - d_ + 1));
        }
        F[j + 1] = dF_j * inv[j + 1];
      }
      S coef_pw = S(c).pow(m);
      for (int j = 0; j < deg; j++) F[j] *= coef_pw;

      FPS<S> res(min(__int128_t(m) * d, __int128_t(deg)), 0);
      if (res.size() < deg) res.insert(res.end(), F.begin(), F.begin() + min(deg, deg - int(res.size())));
      return res;
    }

    if (__int128_t(d + 1) * m >= deg) return FPS<S>(deg, 0);
  }

  return FPS<S>(deg, 0);
}