template <class S, auto op>
class SqrtTree {
   private:
    int n, lg, indexSz;
    vector<S> v;
    vector<int> clz, layers, onLayer;
    vector<vector<S>> prefix, suffix, between;

    void build(int layer, int lBound, int rBound, int betweenOffs) {
        if (layer >= (int)layers.size()) {
            return;
        }
        int bSz = 1 << ((layers[layer] + 1) >> 1);
        for (int l = lBound; l < rBound; l += bSz) {
            int r = min(l + bSz, rBound);
            prefix[layer][l] = v[l];
            for (int i = l + 1; i < r; i++) {
                prefix[layer][i] = op(prefix[layer][i - 1], v[i]);
            }
            suffix[layer][r - 1] = v[r - 1];
            for (int i = r - 2; i >= l; i--) {
                suffix[layer][i] = op(v[i], suffix[layer][i + 1]);
            }
            build(layer + 1, l, r, betweenOffs);
        }
        if (layer == 0) {
            int bSzLog = (lg + 1) >> 1;
            for (int i = 0; i < indexSz; i++) {
                v[n + i] = suffix[0][i << bSzLog];
            }
            build(1, n, n + indexSz, (1 << lg) - n);
        } else {
            int bSzLog = (layers[layer] + 1) >> 1;
            int bCntLog = layers[layer] >> 1;
            int bSz = 1 << bSzLog;
            int bCnt = (rBound - lBound + bSz - 1) >> bSzLog;
            for (int i = 0; i < bCnt; i++) {
                S ans;
                for (int j = i; j < bCnt; j++) {
                    S add = suffix[layer][lBound + (j << bSzLog)];
                    ans = (i == j) ? add : op(ans, add);
                    between[layer - 1][betweenOffs + lBound + (i << bCntLog) + j] = ans;
                }
            }
        }
    }

    inline S query(int l, int r, int betweenOffs, int base) {
        if (l == r) {
            return v[l];
        }
        if (l + 1 == r) {
            return op(v[l], v[r]);
        }
        int layer = onLayer[clz[(l - base) ^ (r - base)]];
        int bSzLog = (layers[layer] + 1) >> 1;
        int bCntLog = layers[layer] >> 1;
        int lBound = (((l - base) >> layers[layer]) << layers[layer]) + base;
        int lBlock = ((l - lBound) >> bSzLog) + 1;
        int rBlock = ((r - lBound) >> bSzLog) - 1;
        S ans = suffix[layer][l];
        if (lBlock <= rBlock) {
            S add = (layer == 0) ? (
                                       query(n + lBlock, n + rBlock, (1 << lg) - n, n))
                                 : (
                                       between[layer - 1][betweenOffs + lBound + (lBlock << bCntLog) + rBlock]);
            ans = op(ans, add);
        }
        ans = op(ans, prefix[layer][r]);
        return ans;
    }

   public:
    inline S prod(int l, int r) {
        return query(l, r - 1, 0, 0);
    }
    SqrtTree() {}

    SqrtTree(const vector<S> a)
        : n((int)a.size()), v(a) {
        lg = 0;
        while ((1 << lg) < n) lg++;
        clz.assign(1 << lg, 0);
        onLayer.assign(lg + 1, 0);
        clz[0] = 0;
        for (int i = 1; i < (int)clz.size(); i++) {
            clz[i] = clz[i >> 1] + 1;
        }
        int tlg = lg;
        while (tlg > 1) {
            onLayer[tlg] = (int)layers.size();
            layers.push_back(tlg);
            tlg = (tlg + 1) >> 1;
        }
        for (int i = lg - 1; i >= 0; i--) {
            onLayer[i] = max(onLayer[i], onLayer[i + 1]);
        }
        int betweenLayers = max(0, (int)layers.size() - 1);
        int bSzLog = (lg + 1) >> 1;
        int bSz = 1 << bSzLog;
        indexSz = (n + bSz - 1) >> bSzLog;
        v.resize(n + indexSz);
        prefix.assign(layers.size(), vector<S>(n + indexSz));
        suffix.assign(layers.size(), vector<S>(n + indexSz));
        between.assign(betweenLayers, vector<S>((1 << lg) + bSz));
        build(0, 0, n, 0);
    }
};