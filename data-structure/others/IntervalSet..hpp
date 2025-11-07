// [l, r]
template <class T>
class IntervalSet {
   private:
    set<pair<T, T>> s;

   public:
    IntervalSet() {
        T mi = numeric_limits<T>::min();
        T mx = numeric_limits<T>::max();
        s.emplace(mi, mi);
        s.emplace(mx, mx);
    }

    bool contains(T x) {
        auto itr = s.lower_bound({x + 1, x + 1});
        itr--;
        return ((*itr).first <= x and x <= (*itr).second);
    }

    int insert(T x) {
        // assert(!(*this).contains(x));
        auto nex = s.lower_bound({x, x});
        auto prev = nex;
        prev--;
        if ((*prev).second + 1 == x and x == (*nex).first - 1) {
            int nl = (*prev).first;
            int nr = (*nex).second;
            s.erase(prev);
            s.erase(nex);
            s.emplace(nl, nr);
            return -1;
        } else if ((*prev).second + 1 == x) {
            int nl = (*prev).first;
            int nr = (*prev).second + 1;
            s.erase(prev);
            s.emplace(nl, nr);
            return 0;
        } else if (x == (*nex).first - 1) {
            int nl = (*nex).first - 1;
            int nr = (*nex).second;
            s.erase(nex);
            s.emplace(nl, nr);
            return 0;
        } else {
            s.emplace(x, x);
            return 1;
        }
    }

    int erase(T x) {
        auto itr = s.lower_bound({x + 1, x + 1});
        itr--;
        int l = (*itr).first;
        int r = (*itr).second;
        if (!(l <= x and x <= r)) return 0;

        s.erase(itr);
        if (l == r) {
            return -1;
        } else if (l == x) {
            s.emplace(l + 1, r);
            return 0;
        } else if (r == x) {
            s.emplace(l, r - 1);
            return 0;
        } else {
            s.emplace(l, x - 1);
            s.emplace(x + 1, r);
            return 1;
        }
    }

    T mex(T x) {
        auto itr = s.lower_bound({x + 1, x + 1});
        itr--;
        if ((*itr).first <= x and x <= (*itr).second) {
            return (*itr).second + 1;
        } else {
            return x;
        }
    }

    void print() {
        for (auto p : s) {
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout << "\n";
    }
};