
// m/n
vector<pair<char, int>> encode_path(lint m, lint n) {
    vector<pair<char, int>> res;
    while (m != 1 or n != 1) {
        if (m < n) {
            int num = (n - 1) / m;
            res.emplace_back('L', num);
            n -= m * num;
        } else {
            int num = (m - 1) / n;
            res.emplace_back('R', num);
            m -= n * num;
        }
    }
    return res;
}

pair<long long, long long> decode_path(const vector<pair<char, int>>& path) {
    long long n = 1;
    long long m = 0;
    long long n_ = 0;
    long long m_ = 1;
    if (path.empty()) return {1, 1};
    for (const auto [c, num] : path) {
        if (c == 'L') {
            n_ += n * num;
            m_ += m * num;
        } else {
            n += n_ * num;
            m += m_ * num;
        }
    }

    return {m + m_, n + n_};
}

// a/b, c/d
pair<long long, long long> sbt_lca(long long a, long long b, long long c, long long d) {
    vector<pair<char, int>> p1 = encode_path(a, b);
    vector<pair<char, int>> p2 = encode_path(c, d);
    int siz = min(int(p1.size()), int(p2.size()));
    if (siz == 0) return {1, 1};
    long long n = 1;
    long long m = 0;
    long long n_ = 0;
    long long m_ = 1;
    for (int i = 0; i < siz; i++) {
        if (p1[i].first != p2[i].first) {
            break;
        } else {
            long long num = min(p1[i].second, p2[i].second);
            if (p1[i].first == 'L') {
                n_ += n * num;
                m_ += m * num;
            } else {
                n += n_ * num;
                m += m_ * num;
            }
            if (p1[i].second != p2[i].second) break;
        }
    }

    return {m + m_, n + n_};
}

// a/b
pair<long long, long long> sbt_ancestor(int k, long long a, long long b) {
    vector<pair<char, int>> path = encode_path(a, b);
    long long n = 1;
    long long m = 0;
    long long n_ = 0;
    long long m_ = 1;
    for (auto [c, num] : path) {
        long long len = min(k, num);
        if (c == 'L') {
            n_ += n * len;
            m_ += m * len;
        } else {
            n += n_ * len;
            m += m_ * len;
        }
        k -= len;
        if (k == 0) break;
    }
    if (k == 0) {
        return {m + m_, n + n_};
    } else {
        return {-1, 1};
    }
}

vector<pair<long long, long long>> sbt_range(long long a, long long b) {
    vector<pair<char, int>> path = encode_path(a, b);
    long long n = 1;
    long long m = 0;
    long long n_ = 0;
    long long m_ = 1;

    if (path.empty()) return {{0, 1}, {1, 0}};
    for (const auto [c, num] : path) {
        if (c == 'L') {
            n_ += n * num;
            m_ += m * num;
        } else {
            n += n_ * num;
            m += m_ * num;
        }
    }
    return {{m, n}, {m_, n_}};
}
