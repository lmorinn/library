#include "../WaveletMatrixTemplate.hpp"

template <class S>
class PointSetRangeFreq {
   private:
    unordered_map<S, vector<unsigned>> m;
    unordered_map<S, unsigned> cnt;
    vector<vector<S>> q;
    unordered_map<S, bool> printq;
    unsigned n;

    unsigned set_query;
    unsigned output_query;
    vector<S> prev;

   public:
    PointSetRangeFreq(const vector<S> &v, unsigned query) {
        n = v.size();
        prev.resize(n);

        for (unsigned i = 0; i < n; i++) {
            m[v[i]].emplace_back(i);
            cnt[v[i]]++;
            prev[i] = v[i];
        }
        set_query = 0;
        output_query = 0;

        q = vector<vector<S>>(query, vector<S>(4));
    }

    void set(unsigned pos, S val) {
        unsigned idx = set_query + output_query;
        q[idx][0] = 0;
        q[idx][1] = pos;
        q[idx][2] = prev[pos];
        q[idx][3] = val;

        m[prev[pos]].emplace_back(pos + n);
        m[val].emplace_back(pos);
        set_query++;
        prev[pos] = val;
    }

    void range_freq(unsigned l, unsigned r, S val) {
        unsigned idx = set_query + output_query;
        q[idx][0] = 1;
        q[idx][1] = l;
        q[idx][2] = r;
        q[idx][3] = val;
        printq[val] = true;
        output_query++;
    }

    vector<unsigned> build() {
        for (int i = 0; i < set_query + output_query; i++) {
            if (q[i][0] == 0 and printq.contains(q[i][3])) {
                m[q[i][3]].emplace_back(q[i][1]);
                if (printq.contains(q[i][2])) {
                    m[q[i][2]].emplace_back(unsigned(q[i][1]) + n);
                }
            }
        }
        unordered_map<S, WaveletMatrix<unsigned>> wm;
        for (const pair<S, vector<unsigned>> &p : m) {
            if (!printq.contains(p.first)) continue;
            wm.emplace(make_pair(p.first, WaveletMatrix<unsigned>(p.second)));
        }
        vector<unsigned> ret(output_query);
        int idx = 0;
        for (int i = 0; i < set_query + output_query; i++) {
            S com = q[i][0];
            if (com == 0) {
                cnt[q[i][2]]++;
                cnt[q[i][3]]++;
            } else {
                ret[idx] = wm[q[i][3]].range_freq(0, cnt[q[i][3]], q[i][1], q[i][2]);
                ret[idx] -= wm[q[i][3]].range_freq(0, cnt[q[i][3]], n + q[i][1], n + q[i][2]);
                idx++;
            }
        }
        return ret;
    }
};