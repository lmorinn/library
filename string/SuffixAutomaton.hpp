class SuffixAutomaton {
   private:
    struct state {
        int len, slink, cnt;
        bool is_clone;
        map<char, int> next;
    };

    // sz: 状態数
    int sz, last;
    vector<state> st;
    vector<int> stat;
    vector<int> topological;

    void
    init() {
        st[0].len = 0;
        st[0].slink = -1;
        st[0].cnt = 0;
        st[0].is_clone = false;
        sz = 1;
        last = 0;
    }

    void extend(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].cnt = 1;
        st[cur].is_clone = false;
        stat.emplace_back(cur);
        int p = last;
        while (p != -1 and !st[p].next[c]) {
            st[p].next[c] = cur;
            p = st[p].slink;
        }
        if (p == -1) {
            st[cur].slink = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].slink = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].slink = st[q].slink;
                st[clone].cnt = 0;
                st[clone].is_clone = true;
                stat.emplace_back(clone);
                while (p != -1 and st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].slink;
                }
                st[q].slink = st[cur].slink = clone;
            }
        }
        last = cur;
    }

    void topo_sort() {
        topological.resize(sz);
        vector<int> in(sz);
        for (int i = 0; i < sz; i++) {
            for (auto [c, nex] : st[i].next) {
                in[nex]++;
            }
        }
        queue<int> que;
        for (int i = 0; i < sz; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }
        int idx = 0;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            topological[idx++] = cur;
            for (auto [c, nex] : st[cur].next) {
                in[nex]--;
                if (in[nex] == 0) {
                    que.push(nex);
                }
            }
        }
    }

   public:
    SuffixAutomaton() {
        st.resize(2);
        init();
    }

    SuffixAutomaton(const string &s) {
        int n = int(s.size());
        st.resize(n << 1);
        init();
        for (int i = 0; i < n; i++) {
            extend(s[i]);
        }
        sort(stat.begin(), stat.end(), [&](int i, int j) { return st[i].len < st[j].len; });
        for (int i = sz - 1; i >= 0; i--) {
            if (st[stat[i]].slink != -1) {
                st[st[stat[i]].slink].cnt += st[stat[i]].cnt;
            }
        }

        topo_sort();
    }

    long long number_of_substrings() {
        long long res = 0;
        for (int i = 1; i < sz; i++) {
            res += st[i].len - st[st[i].slink].len;
        }
        return res;
    }

    bool is_substring(const string &t) {
        int m = int(t.size());
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (!st[cur].next[t[i]]) {
                return false;
            }
            cur = st[cur].next[t[i]];
        }
        return true;
    }

    int count_substring(const string &t) {
        int m = int(t.size());
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (!st[cur].next[t[i]]) {
                return 0;
            }
            cur = st[cur].next[t[i]];
        }
        return st[cur].cnt;
    }

    string kth_substring(int k) {
        vector<int> dp(sz);
        dp[topological[0]] = 1;
        for (int i = sz - 1; i >= 0; i--) {
            dp[topological[i]] = 1;
            int cur = topological[i];
            for (auto [c, nex] : st[cur].next) {
                dp[cur] += dp[nex];
            }
        }
        string res;
        int cur = 0;
        while (k > 0) {
            for (auto [c, nex] : st[cur].next) {
                if (dp[nex] >= k) {
                    res.push_back(c);
                    k--;
                    cur = nex;
                    break;
                } else {
                    k -= dp[nex];
                }
            }
        }
        return res;
    }

    string kth_substring(int k, const vector<char> &exclude) {
        set<char> ex;
        for (char c : exclude) {
            ex.insert(c);
        }
        vector<int> dp(sz);
        dp[topological[0]] = 1;
        for (int i = sz - 1; i >= 0; i--) {
            dp[topological[i]] = 1;
            int cur = topological[i];
            for (auto [c, nex] : st[cur].next) {
                if (!ex.contains(c)) {
                    dp[cur] += dp[nex];
                }
            }
        }

        string res;
        int cur = 0;
        while (k > 0) {
            bool nex_exist = false;
            for (auto [c, nex] : st[cur].next) {
                if (!ex.contains(c)) {
                    if (dp[nex] >= k) {
                        nex_exist = true;
                        res.push_back(c);
                        k--;
                        cur = nex;
                        break;
                    } else {
                        k -= dp[nex];
                    }
                } else {
                    continue;
                }
            }

            if (!nex_exist) {
                break;
            }
        }

        if (k > 0) {
            return "";
        }
        return res;
    }
};