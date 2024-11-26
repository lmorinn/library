
struct BitVector {
  unsigned sz;
  unsigned blocksize;
  vector<unsigned> bit, sum;

  BitVector() {}

  BitVector(unsigned siz) {
    sz = siz;
    blocksize = (sz + 31) >> 5;
    bit.assign(blocksize, 0U);
    sum.assign(blocksize, 0U);
  }

  inline void set(int k) { bit[k >> 5] |= 1U << (k & 31); }

  inline void build() {
    sum[0] = 0U;
    for (int i = 1; i < blocksize; i++) {
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
    }
  }

  inline bool access(unsigned k) {
    return (bool((bit[k >> 5] >> (k & 31)) & 1));
  }

  inline int rank(int k) {
    return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
  }
};

template <class T>
class WaveletMatrix {
 private:
 public:
  // コンストラクタ
  WaveletMatrix() {}
  WaveletMatrix(const vector<T> &v) {
    MI = numeric_limits<T>::min();
    MA = numeric_limits<T>::max();
    n = v.size();
    cmp = v;
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    vector<unsigned> compressed(n);
    vector<unsigned> tmpc(n);
    unsigned size_mx = v.size();
    for (unsigned i = 0; i < n; i++) {
      compressed[i] = compress(v[i]);
    }
    bitsize = bit_width(cmp.size());
    b.resize(bitsize);
    zero.assign(bitsize, 0);
    int cur = 0;

    for (unsigned i = 0; i < bitsize; i++) {
      b[i] = BitVector(n + 1);
      cur = 0;
      for (unsigned j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          b[i].set(j);
        } else {
          zero[i]++;
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      b[i].build();

      for (unsigned j = 0; j < n; j++) {
        if (compressed[j] & (1U << (bitsize - i - 1))) {
          tmpc[cur] = compressed[j];
          cur++;
        }
      }
      swap(tmpc, compressed);
    }
  }

  // get v[k]
  T access(unsigned k) {
    unsigned res = 0;
    unsigned cur = k;
    for (unsigned i = 0; i < bitsize; i++) {
      if (b[i].access(cur)) {
        res |= (1U << (bitsize - i - 1));
        cur = zero[i] + b[i].rank(cur);
      } else {
        cur -= b[i].rank(cur);
      }
    }
    return cmp[res];
  }

  // v[l,r) の中でk番目(1-origin)に小さい値を返す
  T kth_smallest(unsigned l, unsigned r, unsigned k) {
    unsigned res = 0;
    unsigned rank1_l, rank1_r, num0;
    for (unsigned i = 0; i < bitsize; i++) {
      rank1_l = b[i].rank(l);
      rank1_r = b[i].rank(r);
      num0 = r - l - (rank1_r - rank1_l);
      if (num0 < k) {
        res |= (1U << (bitsize - i - 1));
        l = zero[i] + rank1_l;
        r = zero[i] + rank1_r;
        k -= num0;
      } else {
        l -= rank1_l;
        r -= rank1_r;
      }
    }
    return cmp[res];
  }

  // v[l,r) の中でk番目(1-origin)に大きい値を返す
  T kth_largest(unsigned l, unsigned r, unsigned k) {
    return kth_smallest(l, r, r - l - k + 1);
  }

  // v[l,r) の中で[mink,maxk)に入る値の個数を返す
  unsigned range_freq(int vl, int vr, T mink, T maxk) {
    int D = compress(mink);
    int U = compress(maxk);
    unsigned res = 0;
    auto dfs = [&](auto &rec, int d, int L, int R, int A, int B) -> void {
      if (U <= A or B <= D) return;
      if (D <= A and B <= U) {
        res += (R - L);
        return;
      }
      if (d == bitsize) {
        if (D <= A and A < U) {
          res += (R - L);
        }
        return;
      }
      int C = (A + B) / 2;
      int rank0_l = L - b[d].rank(L);
      int rank0_r = R - b[d].rank(R);
      int rank1_l = b[d].rank(L) + zero[d];
      int rank1_r = b[d].rank(R) + zero[d];
      rec(rec, d + 1, rank0_l, rank0_r, A, C);
      rec(rec, d + 1, rank1_l, rank1_r, C, B);
    };
    dfs(dfs, 0, vl, vr, 0, 1 << bitsize);
    return res;
  }

  // v[l,r)の中でvalを超えない最大の値を返す
  T prev_value(unsigned l, unsigned r, T val) {
    int num = range_freq(l, r, MI, val);
    if (num == 0) {
      return MA;
    } else {
      return kth_smallest(l, r, num);
    }
  }

  // v[l,r)の中でval以上の最小の値を返す
  T next_value(unsigned l, unsigned r, T val) {
    int num = range_freq(l, r, MI, val);
    if (num == r - l) {
      return MI;
    } else {
      return kth_smallest(l, r, num + 1);
    }
  }
  vector<T> cmp;
  unsigned n;
  unsigned bitsize;
  vector<BitVector> b;
  vector<unsigned> zero;
  T MI, MA;

  inline unsigned compress(const T &x) {
    return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
  }
};

template <typename T>
class hld_wavelet {
 private:
  vector<int> subtree, depth, ind, parent, top;
  vector<bool> seen;
  vector<int> hl;
  int n;
  WaveletMatrix<T> wm;

  int rec_sub(vector<vector<pair<int, int>>> &g, int cur, int d) {
    int sub = 0;
    for (auto nex : g[cur]) {
      if (seen[nex.first]) continue;
      seen[nex.first] = 1;
      parent[nex.first] = cur;
      sub += rec_sub(g, nex.first, d + 1);
    }
    subtree[cur] = sub + 1;
    depth[cur] = d;
    return subtree[cur];
  }

  void rec_hld(vector<vector<pair<int, int>>> &g, int cur) {
    ind[cur] = int(hl.size());
    seen[cur] = 1;
    hl.push_back(cur);
    int sub = 0;
    int idx = -1;
    for (auto nex : g[cur]) {
      if (subtree[nex.first] > sub and !seen[nex.first]) {
        sub = subtree[nex.first];
        idx = nex.first;
      }
    }
    if (idx != -1) {
      top[idx] = top[cur];
      rec_hld(g, idx);
      for (auto nex : g[cur]) {
        if (nex.first != idx and !seen[nex.first]) {
          top[nex.first] = nex.first;
          rec_hld(g, nex.first);
        }
      }
    }
  }

  vector<pair<int, int>> decompose(int u, int v) {
    vector<pair<int, int>> res;
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      res.emplace_back(ind[top[u]], ind[u]);
      u = parent[top[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    res.emplace_back(ind[u], ind[v]);
    return res;
  }

 public:
  hld_wavelet(vector<vector<pair<int, int>>> &g, const vector<T> &node_values, int root = 0) {
    n = g.size();
    seen.resize(n, 0);
    subtree.resize(n, 0);
    ind.resize(n, 0);
    depth.resize(n, 0);
    top.resize(n, 0);
    parent.resize(n, -1);
    seen[root] = 1;
    rec_sub(g, root, 0);
    for (int i = 0; i < n; i++) seen[i] = 0;
    seen[root] = 1;
    top[root] = root;
    rec_hld(g, root);
    for (int i = 1; i < n; i++) {
      int prev = hl[i - 1];
      int cur = hl[i];
      if (top[prev] != top[cur]) continue;
    }

    vector<T> reordered_values(n);
    for (int i = 0; i < n; ++i) {
      reordered_values[i] = node_values[hl[i]];
    }
    wm = WaveletMatrix<T>(reordered_values);
  }

  T kth_path(int u, int v, int k) {
    vector<pair<int, int>> segments;
    for (const auto &[s, t] : decompose(u, v)) {
      if (s > t) {
        segments.emplace_back(t, s + 1);
      } else {
        segments.emplace_back(s, t + 1);
      }
    }
    int cnt = 0;
    int p = 0;
    for (int i = 0; i < wm.bitsize; i++) {
      int c = 0;
      for (auto &[l, r] : segments) {
        int l0 = l - wm.b[i].rank(l);
        int r0 = r - wm.b[i].rank(r);
        c += r0 - l0;
      }

      if (cnt + c > k) {
        for (auto &&[l, r] : segments) {
          int l0 = l - wm.b[i].rank(l);
          int r0 = r - wm.b[i].rank(r);
          l = l0;
          r = r0;
        }
      } else {
        cnt += c;
        p |= (1 << (wm.bitsize - i - 1));

        for (auto &&[l, r] : segments) {
          int l0 = l - wm.b[i].rank(l);
          int r0 = r - wm.b[i].rank(r);
          l += wm.zero[i] - l0;
          r += wm.zero[i] - r0;
        }
      }
    }
    return wm.cmp[p];
  }
};