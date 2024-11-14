
template <class S, auto op>
class SqrtTree {
   private:
    vector<vector<S>> prefix, suffix, between;
    vector<S> v;
    vector<int> layerlg, layerv;

   public:
    SqrtTree() = default;
    SqrtTree(vector<S> &a) {
        v = a;
        int n = v.size();
        int lg = 0;
        lg = bit_width(ull(n));
        int n_layer = 0;
        layerv.resize(lg + 1);
        for (int i = lg; i > 1; i = (i + 1) >> 1) {
            layerv[i] = n_layer++;
            layerlg.push_back(i);
        }
        for (int i = lg - 1; i >= 0; --i) layerv[i] = max(layerv[i], layerv[i + 1]);
        prefix.resize(n_layer, vector<S>(n));
        suffix.resize(n_layer, vector<S>(n));
        between.resize(n_layer, vector<S>(1 << lg));

        for (int layer = 0; layer < n_layer; ++layer) {
            int current_lg = layerlg[layer];
            int prev_b_sz = 1 << current_lg;
            int b_sz_shift = (current_lg + 1) >> 1;
            int b_cnt_shift = current_lg >> 1;
            int b_sz = 1 << b_sz_shift;
            int b_cnt = 1 << b_cnt_shift;
            for (int l = 0; l < n; l += prev_b_sz) {
                int r = min(l + prev_b_sz, n);
                for (int a = l; a < r; a += b_sz) {
                    int b = min(a + b_sz, r);
                    prefix[layer][a] = v[a];
                    for (int i = a + 1; i < b; ++i) {
                        prefix[layer][i] = op(prefix[layer][i - 1], v[i]);
                    }
                    suffix[layer][b - 1] = v[b - 1];
                    for (int i = b - 2; i >= a; --i) {
                        suffix[layer][i] = op(v[i], suffix[layer][i + 1]);
                    }
                }
                for (int i = 0; i < b_cnt; ++i) {
                    int idx = l + (i << b_sz_shift);
                    S val = suffix[layer][idx];
                    between[layer][(i << b_cnt_shift) + i] = val;
                    for (int j = i + 1; j < b_cnt; ++j) {
                        int suffix_idx = l + (j << b_sz_shift);
                        val = op(val, suffix[layer][suffix_idx]);
                        between[layer][(i << b_cnt_shift) + j] = val;
                    }
                }
            }
        }
    }

    S prod(int l, int r) const {
        --r;
        if (l == r) return v[l];
        if (l + 1 == r) return op(v[l], v[r]);
        int xor_val = l ^ r;
        int highest_bit = 32 - __builtin_clz(xor_val);
        int layer = layerv[highest_bit];
        int current_lg = layerlg[layer];
        int b_sz_shift = (current_lg + 1) >> 1;
        int b_cnt_shift = current_lg >> 1;
        int b_sz = 1 << b_sz_shift;
        int b_cnt = 1 << b_cnt_shift;
        int a = l & (~((1 << current_lg) - 1));
        int lblock = ((l - a) >> b_sz_shift) + 1;
        int rblock = ((r - a) >> b_sz_shift) - 1;
        S val = suffix[layer][l];
        if (lblock <= rblock) val = op(val, between[layer][a + (lblock << b_cnt_shift) + rblock]);
        val = op(val, prefix[layer][r]);
        return val;
    }
};