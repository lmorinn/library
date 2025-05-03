template <class T>
struct RangeAddPointGet {
   private:
    fenwick_tree<T> ft;

   public:
    RangeAddPointGet() {}
    RangeAddPointGet(int siz) : ft(siz + 1) {}

    void range_add(int l, int r, T x) {
        ft.add(l, x);
        ft.add(r, -x);
    }

    void add(int p, T x) {
        ft.add(p, x);
        ft.add(p + 1, -x);
    }

    T point_get(int p) {
        return ft.sum(0, p + 1);
    }
};