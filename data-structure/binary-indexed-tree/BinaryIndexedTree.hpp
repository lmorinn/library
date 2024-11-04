
template <typename T>
struct BinaryIndexedTree {
    int N;
    vector<T> data;

    BinaryIndexedTree() = default;

    BinaryIndexedTree(int size) { init(size); }

    void init(int size) {
        N = size + 2;
        data.assign(N + 1, {});
    }

    T sum(int k) const {
        if (k < 0) return T{};
        T ret{};
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }
    inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }

    inline T operator[](int k) const { return sum(k) - sum(k - 1); }

    void add(int k, T x) {
        for (++k; k < N; k += k & -k) data[k] += x;
    }
};
