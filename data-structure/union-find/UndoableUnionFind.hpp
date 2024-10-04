
template <class S, auto op, auto e>
class UndoableUnionFind {
 private:
  struct HistoryData {
    int u, datu;
    S accu;
    int v, datv;
    S accv;
    int comp_cnt;
  };

  vector<int> data;
  vector<S> acc;
  stack<HistoryData> history;
  int cnt;
  int snap;

 public:
  UndoableUnionFind() {}
  UndoableUnionFind(int sz) {
    data.assign(sz, -1);
    cnt = sz;
    acc.resize(sz, e());
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    history.emplace(u, data[u], acc[u], v, data[v], acc[v], cnt);
    if (u == v) return false;
    if (data[u] > data[v]) swap(u, v);
    data[u] += data[v];
    data[v] = u;
    acc[u] = op(acc[u], acc[v]);
    cnt--;
    return true;
  }

  int find(int k) {
    while (data[k] >= 0) {
      k = data[k];
    }
    return k;
  }

  void update(int a, S x) {
    a = find(a);
    history.push({a, data[a], acc[a], -1, -1, e(), -1});
    acc[a] = op(acc[a], x);
  }

  S prod_components(int a) {
    return acc[find(a)];
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int k) { return (-data[find(k)]); }

  void undo() {
    HistoryData h = history.top();
    history.pop();
    data[h.u] = h.datu;
    acc[h.u] = h.accu;
    if (h.v != -1) {
      data[h.v] = h.datv;
      acc[h.v] = h.accv;
      cnt = h.comp_cnt;
    }
  }

  int components() {
    return cnt;
  }
};