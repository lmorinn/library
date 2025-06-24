#include "../others/PersistentArray.hpp"

struct PersistentUnionfind {
 public:
  using Node = PersistentArray<int>::Node;
  PersistentUnionfind() : _n(0) {}
  explicit PersistentUnionfind(int n) : _n(n), parent_or_size(n, -1) {
    root = parent_or_size.get_root();
  }

  Node *get_root() {
    return root;
  }

  Node *merge(Node *p, int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(p, a), y = leader(p, b);
    if (x == y) return p;
    int px = parent_or_size.get(p, x);
    int py = parent_or_size.get(p, y);
    if (-px < -py) std::swap(x, y);
    // Node *ret = parent_or_size.set(p, x, px + py);
    return parent_or_size.set(parent_or_size.set(p, x, px + py), y, x);
  }

  bool same(Node *p, int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(p, a) == leader(p, b);
  }

  int leader(Node *p, int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size.get(p, a) < 0) return a;
    return leader(p, parent_or_size.get(p, a));
  }

  int size(Node *p, int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size.get(p, leader(p, a));
  }

  std::vector<std::vector<int>> groups(Node *p) {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(p, i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }

 private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent

  PersistentArray<int> parent_or_size;
  Node *root;
};