template <class T, auto compare = std::less()>
class CartesianTree {
 public:
  int root;
  vector<int> parent, left, right;

  CartesianTree() : root(0) {}
  CartesianTree(const vector<T>& v) : root(0), parent(int(v.size()), -1), left(int(v.size()), -1), right(int(v.size()), -1) {
    stack<pair<lint, int>> st;
    int n = int(v.size());
    for (int i = 0; i < n; i++) {
      if (!st.empty()) {
        int pop_idx = -1;
        while (!st.empty() and compare(v[i], st.top().first)) {
          pop_idx = st.top().second;
          st.pop();
        }
        if (pop_idx != -1) {
          left[i] = pop_idx;
          parent[pop_idx] = i;
        }
        if (!st.empty()) {
          int idx = st.top().second;
          parent[i] = idx;
          right[idx] = i;
        }
      }
      st.emplace(v[i], i);
    }

    for (int i = 0; i < n; i++) {
      if (parent[i] == -1) {
        root = i;
        parent[i] = i;
        break;
      }
    }
  }
};