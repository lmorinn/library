template <class T>
class multi_dimensional_sum {
 private:
  vector<T> sum;
  vector<int> mx;
  vector<long long> prod;
  int n, siz;

  T idx(const vector<int>& id) {
    int ret = 0;
    for (int i = 0; i < n; i++) ret += prod[i] * id[i];
    return ret;
  }

 public:
  // [1, mx_0] x [1, mx_1] x ... x [1, mx_{n-1}]
  multi_dimensional_sum(const vector<int>& mx) : mx(mx) {
    n = int(mx.size());
    siz = 1;
    for (int i = 0; i < n; i++) siz *= mx[i];
    sum.assign(siz, 0);
    prod.resize(n);
    prod[n - 1] = 1;
    for (int i = n - 1; i > 0; i--) prod[i - 1] = prod[i] * mx[i];
  };

  void add(vector<int> id, T x) {
    assert(int(id.size()) == n);
    int i = idx(id);
    assert(i < siz);
    sum[i] += x;
  }

  void build() {
    for (int i = 0; i < n; i++) {
      int j = prod[i];
      for (int id = 0; id < siz; id++) {
        if ((id / j) % mx[i] > 0) sum[id] += sum[id - j];
      }
    }
  }

  // sum [l_0, r_0] x [l_1, r_1] x ... x [l_{n-1}, r_{n-1}]
  T calc(const vector<int>& l, const vector<int>& r) {
    assert(int(l.size()) == n and int(r.size()) == n);
    for (int i = 0; i < n; i++) {
      if (l[i] > r[i]) return 0;
    }

    T ret = 0;
    vector<int> id(n);
    for (unsigned int bit = 0; bit < (1u << n); bit++) {
      bool ok = true;

      for (int i = 0; i < n; i++) {
        if ((bit & (1 << i))) {
          id[i] = r[i] - 1;
        } else {
          id[i] = l[i] - 2;
        }

        if (id[i] < 0) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      int lcnt = n - popcount(bit);
      ret += (lcnt % 2 ? -sum[idx(id)] : sum[idx(id)]);
    }
    return ret;
  }
};