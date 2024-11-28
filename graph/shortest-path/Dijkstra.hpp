template <class T>
class Dijkstra {
   private:
    vector<vector<pair<int, T>>> g;
    vector<T> dist;
    vector<int> prev;
    int n;

   public:
    Dijkstra(vector<vector<pair<int, T>>> _g, int start = 0) {
        g = _g;
        n = g.size();
        dist.assign(n, -1);
        prev.assign(n, -1);
        vector<bool> fin(n, false);
        priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T, int, int>>> q;
        dist[start] = 0;
        q.emplace(0, start, -1);
        while (!q.empty()) {
            int cur = get<1>(q.top());
            int pre = get<2>(q.top());
            q.pop();
            if (fin[cur]) continue;
            fin[cur] = true;
            prev[cur] = pre;
            for (auto p : g[cur]) {
                int nex = p.first;
                int weight = p.second;
                if (dist[nex] == -1 or dist[nex] > dist[cur] + weight) {
                    dist[nex] = dist[cur] + weight;
                    q.emplace(dist[nex], nex, cur);
                }
            }
        }
    }

    void rebuild(int start) {
        dist.assign(n, -1);
        prev.assign(n, -1);
        vector<bool> fin(n, false);
        priority_queue<tuple<T, int, int>, vector<tuple<T, int, int>>, greater<tuple<T, int, int>>> q;
        dist[start] = 0;
        q.emplace(0, start, -1);
        while (!q.empty()) {
            int cur = get<1>(q.top());
            int pre = get<2>(q.top());
            q.pop();
            if (fin[cur]) continue;
            fin[cur] = true;
            prev[cur] = pre;
            for (auto p : g[cur]) {
                int nex = p.first;
                int weight = p.second;
                if (dist[nex] == -1 or dist[nex] > dist[cur] + weight) {
                    dist[nex] = dist[cur] + weight;
                    q.emplace(dist[nex], nex, cur);
                }
            }
        }
    }

    vector<T> get_dist() {
        return dist;
    }

    T get_dist(int t) {
        return dist[t];
    }

    vector<int> get_route(int t) {
        vector<int> ret;
        if (dist[t] == -1) return ret;

        int cur = t;
        while (cur != -1) {
            ret.emplace_back(cur);
            cur = prev[cur];
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};