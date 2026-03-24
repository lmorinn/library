#include "../../linear-algebra/Matrix.hpp"

template <class S>
struct CountingSpanningTrees {
 private:
  Matrix<S> laplacian;
  int n, root;
  bool is_undirected = true;

  void internal_add_edge(int from, int to) {
    if (from != root and to != root) {
      if (root < from) from--;
      if (root < to) to--;
      laplacian[from][to]--;
      laplacian[from][from]++;
    } else if (from != root) {
      if (root < from) from--;
      laplacian[from][from]++;
    }
  }

 public:
  CountingSpanningTrees() {}
  CountingSpanningTrees(int n, bool undirected = true, int root = 0) : n(n), is_undirected(undirected), root(root), laplacian(n - 1, n - 1) {}

  // すべての辺が根の方を向く: u->v
  // 根からすべての頂点に到達: v->u
  void add_edge(int u, int v) {
    assert(0 <= u and u < n and 0 <= v and v < n);
    internal_add_edge(u, v);
    if (is_undirected) internal_add_edge(v, u);
  }

  S count_spanning_trees() {
    if (n != 1) {
      return laplacian.determinant();
    } else {
      return 1;
    }
  }
};