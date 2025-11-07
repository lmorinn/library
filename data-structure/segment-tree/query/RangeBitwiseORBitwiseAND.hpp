#include "../ACLSegmentTreeBeatsChminChmax.hpp"

struct S {
    int mxpopcnt;
    int mxnum;
    uint64_t range_or, range_and;
    bool fail;
    S(uint64_t x = 0) : mxpopcnt(__builtin_popcountll(x)), mxnum(1), range_or(x), range_and(x), fail(false) {}
};

S e() {
    S ret(0ull);
    ret.range_and = ~0ull;
    ret.mxnum = 0;
    return ret;
}
S op(S a, S b) {
    a.range_or |= b.range_or;
    a.range_and &= b.range_and;
    if (a.mxpopcnt < b.mxpopcnt) {
        a.mxpopcnt = b.mxpopcnt;
        a.mxnum = b.mxnum;
    } else if (a.mxpopcnt == b.mxpopcnt) {
        a.mxnum += b.mxnum;
    }
    a.fail = false;
    return a;
}

struct F {
    uint64_t bit_or, bit_and;
    F() : bit_or(0ull), bit_and(~0ull) {}
    F(uint64_t o, uint64_t a) : bit_or(o), bit_and(a) {}
};

S mapping(F f, S x) {
    if ((x.range_and ^ x.range_or) & (~f.bit_and | f.bit_or)) {
        x.fail = true;
        return x;
    }
    x.mxpopcnt -= __builtin_popcountll(x.range_and & ~f.bit_and);
    x.range_and &= f.bit_and;
    x.range_or &= f.bit_and;
    x.mxpopcnt += __builtin_popcountll(~x.range_or & f.bit_or);
    x.range_and |= f.bit_or;
    x.range_or |= f.bit_or;
    return x;
}

F composition(F g, F f) {
    return {g.bit_or | (g.bit_and & f.bit_or), g.bit_and & f.bit_and};
}

F id() { return F(); }

class Rangebitwise {
   private:
    segtree_beats<S, op, e, F, mapping, composition, id> seg;

   public:
    Rangebitwise() {}
    Rangebitwise(const vector<uint64_t>& a) {
        int n = int(a.size());
        vector<S> v(n);
        for (int i = 0; i < n; i++) {
            v[i].range_and = v[i].range_or = a[i];
            v[i].mxpopcnt = __builtin_popcountll(a[i]);
            v[i].mxnum = 1;
            v[i].fail = false;
        }
        seg = segtree_beats<S, op, e, F, mapping, composition, id>(v);
    }

    void apply_bitwise_or(int l, int r, uint64_t x) {
        seg.apply(l, r, {x, ULLONG_MAX});
    }

    void apply_bitwise_and(int l, int r, uint64_t x) {
        seg.apply(l, r, {0ull, x});
    }

    pair<int, int> max_popcount(int l, int r) {
        S res = seg.prod(l, r);
        return {res.mxpopcnt, res.mxnum};
    }
};