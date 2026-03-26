#include "../../atcoder/convolution.hpp"
#include "../../atcoder/modint.hpp"

template <class S>
vector<S> product_of_polynomial_sequence(const vector<vector<S>>& poly) {
  int n = int(poly.size());
  auto compare = [](const vector<S>& a, const vector<S>& b) {
    return (int(a.size()) > int(b.size()));
  };
  priority_queue<vector<S>, vector<vector<S>>, decltype(compare)> q{compare};
  q.emplace(vector<S>(1, 1));
  for (int i = 0; i < n; i++) q.emplace(poly[i]);
  while (q.size() > 1) {
    vector<S> a = q.top();
    q.pop();
    vector<S> b = q.top();
    q.pop();
    q.emplace(atcoder::convolution(a, b));
  }
  return q.top();
}