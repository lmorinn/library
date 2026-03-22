#include "../../atcoder/modint.hpp"
#include "../../linear-algebra/Matrix.hpp"
#include "../../other/Xorshift.hpp"

class MaximumMatchingsize {
 private:
  int n;
  const int MOD = 998244353;
  Matrix<atcoder::modint998244353> m;
  unordered_map<int, int> seen;

 public:
  MaximumMatchingsize() {}
  MaximumMatchingsize(int n) : n(n), m(n) {}

  void add_edge(int u, int v) {
    int x = rand_gen(MOD);
    while (seen.contains(x)) x = rand_gen(MOD);
    m[u][v] = x;
    m[v][u] = -x;
    seen[x] = 1;
  }

  int maximum_matching() {
    return m.rank() / 2;
  }
};
