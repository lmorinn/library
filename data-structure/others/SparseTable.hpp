template <class T, auto f>
class SparseTable {
 private:
  vector<vector<T>> st;
  vector<int> lookup;

 public:
  SparseTable() {}

  SparseTable(const vector<T> &v) {
    const int n = (int)v.size();
    const int b = 32 - __builtin_clz(n);
    st.assign(b, vector<T>(n));
    for (int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for (int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T query(int l, int r) const {
    int b = lookup[r - l];
    return f(st[b][l], st[b][r - (1 << b)]);
  }
};
