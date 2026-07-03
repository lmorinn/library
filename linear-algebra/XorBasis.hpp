template <class T>
vector<T> xor_basis(vector<T> a) {
  vector<T> basis;
  for (T e : a) {
    for (T b : basis) {
      chmin(e, e ^ b);
    }
    if (e) basis.emplace_back(e);
  }
  return basis;
}