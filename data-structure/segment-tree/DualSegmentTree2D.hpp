#include <./DualSegmentTree.hpp>
#pragma once

template <class S, class F, auto mapping, auto composition, auto id>
class DualSegmentTree2D {
   private:
    int n;
    vector<DualSegmentTree<S, F, mapping, composition, id>> node;
    vector<vector<S>> ar;

    void Apply(int x1, int y1, int x2, int y2, F x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= y1 || y2 <= l) return;
        if (y1 <= l && r <= y2) {
            node[k].apply(x1, x2, x);
            return;
        }
        Apply(x1, y1, x2, y2, x, 2 * k + 1, l, (l + r) / 2);
        Apply(x1, y1, x2, y2, x, 2 * k + 2, (l + r) / 2, r);
    }

   public:
    DualSegmentTree2D(vector<vector<S>> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        ar.resize(sz);
        vector<S> idv(v[0].size(), id());
        node.resize(n * 2 - 1);
        for (int i = 0; i < sz; i++) {
            ar[i].resize(ar[i].size());
            ar[i] = v[i];
        }
        for (int i = 0; i < n * 2 - 1; i++) {
            node[i] = DualSegmentTree<S, F, mapping, composition, id>(idv);
        }
    }

    void apply(int x1, int y1, int x2, int y2, F x) {
        Apply(x1, y1, x2, y2, x);
    }

    S get2d(int x, int y) {
        S ret = ar[y][x];
        y += (n - 1);
        F f = node[y].getf(x);
        while (y > 0) {
            y = (y - 1) / 2;
            f = composition(node[y].getf(x), f);
        }
        return mapping(f, ret);
    }

    void print() {
        for (int i = 0; i < ar.size(); i++) {
            for (int j = 0; j < ar[i].size(); j++) {
                cout << get2d(j, i);
                if (j + 1 == ar[i].size()) {
                    cout << "\n";
                } else {
                    cout << " ";
                }
            }
        }
    }
};
