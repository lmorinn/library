#include "../../../atcoder/modint.hpp"
using namespace atcoder;
#include "../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2879"
#include "../../../dp/DeterministicFiniteAutomatonDP.hpp"

// ごちうさ数を受理するDFA
class Gochiusa {
   public:
    using Alphabet = char;
    using State = pair<int, int>;

    Gochiusa() {}

    State init() const {
        return {0, 0};
    }

    State next(State s, const Alphabet& a, size_t i) const {
        int d = a - '0';
        if (s.first == 4) return {4, 0};
        if (s.first == 2) return {3, d};

        if (s.first == 3) {
            if (d == 3) {
                return {4, 0};
            } else if (d == 5) {
                return {1, 5};
            } else if (s.second == 5 and d == 1) {
                return {2, 1};
            } else {
                return {0, d};
            }
        } else if (s.first == 1) {
            if (d == 1) {
                return {2, 1};
            } else if (d == 5) {
                return {1, 5};
            } else {
                return {0, d};
            }
        } else if (s.first == 0) {
            if (d == 5) {
                return {1, 5};
            } else {
                return {0, d};
            }
        }
        return {0, 0};
    }

    bool accept(State s) const {
        return s.first == 4;
    }

    bool successful(State s) const {
        return s.first == 4;
    }

    bool unsuccessful(State s) const {
        return 0;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<char> alphabet(10);
    iota(all(alphabet), '0');
    string s;
    in(s);
    out(count_dfa_ll(AndDfa(Leq(s), Gochiusa()), s.size(), alphabet));
}