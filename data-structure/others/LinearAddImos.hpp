template <class T>
class linearimos {
 private:
  int n;

 public:
  vector<T> imos;
  linearimos(int n) : n(n) {
    imos.assign(n + 2, 0);
  }

  void add_line(int l, int r, T a, T d) {
    assert(l <= r and 0 <= l and r <= n);
    imos[l] += a;
    imos[l + 1] += d - a;
    imos[r] -= (d * T(r - l) + a);
    imos[r + 1] += d * T(r - l - 1) + a;
  }

  void build() {
    int siz = imos.size();
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < siz - 1; i++) {
        imos[i + 1] += imos[i];
      }
    }
  }
};