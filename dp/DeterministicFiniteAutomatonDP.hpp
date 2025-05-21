
enum class Ordering { Less,
                      Equal,
                      Greater };

namespace std {
template <>
struct hash<Ordering> {
  std::size_t operator()(const Ordering& o) const {
    return std::hash<int>()(static_cast<int>(o));
  }
};
template <typename T1, typename T2>
struct hash<pair<T1, T2>> {
  std::size_t operator()(const pair<T1, T2>& p) const {
    return std::hash<T1>()(p.first) * 31 + std::hash<T2>()(p.second);
  }
};

}  // namespace std

struct TupleHash {
  size_t operator()(const std::tuple<int, int, int>& t) const {
    auto [x, y, z] = t;
    return std::hash<int>()(x) ^ (std::hash<int>()(y) << 1) ^ (std::hash<int>()(z) << 2);
  }
};

template <typename X>
class Dfa {
 public:
  using Alphabet = typename X::Alphabet;
  using State = typename X::State;

  Dfa(const X& x) : x_(x) {}

  State init() const { return x_.init(); }

  State next(const State& s, const Alphabet& a, size_t i) const {
    return x_.next(s, a, i);
  }

  bool accept(const State& s) const {
    return x_.accept(s);
  }

  bool successful(const State& s) const {
    return x_.successful(s);
  }

  bool unsuccessful(const State& s) const {
    return x_.unsuccessful(s);
  }

 private:
  X x_;
};

template <typename X, typename Y>
class AndDfa {
 public:
  using Alphabet = typename X::Alphabet;
  using State = pair<typename X::State, typename Y::State>;

  AndDfa(const X& x, const Y& y) : x_(x), y_(y) {}

  State init() const { return make_pair(x_.init(), y_.init()); }

  State next(const State& s, const Alphabet& a, size_t i) const {
    return make_pair(x_.next(s.first, a, i), y_.next(s.second, a, i));
  }

  bool accept(const State& s) const {
    return x_.accept(s.first) and y_.accept(s.second);
  }

  bool successful(const State& s) const {
    return x_.successful(s.first) and y_.successful(s.second);
  }

  bool unsuccessful(const State& s) const {
    return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);
  }

 private:
  X x_;
  Y y_;
};

template <typename X, typename Y>
class OrDfa {
 public:
  using Alphabet = typename X::Alphabet;
  using State = pair<typename X::State, typename Y::State>;

  OrDfa(const X& x, const Y& y) : x_(x), y_(y) {}

  State init() const { return make_pair(x_.init(), y_.init()); }

  State next(const State& s, const Alphabet& a, size_t i) const {
    return make_pair(x_.next(s.first, a, i), y_.next(s.second, a, i));
  }

  bool accept(const State& s) const {
    return x_.accept(s.first) or y_.accept(s.second);
  }

  bool successful(const State& s) const {
    return x_.successful(s.first) or y_.successful(s.second);
  }

  bool unsuccessful(const State& s) const {
    return x_.unsuccessful(s.first) and y_.unsuccessful(s.second);
  }

 private:
  X x_;
  Y y_;
};

template <typename X>
class NotDfa {
 public:
  using Alphabet = typename X::Alphabet;
  using State = typename X::State;

  NotDfa(const X& x) : x_(x) {}

  State init() const { return x_.init(); }

  State next(const State& s, const Alphabet& a, size_t i) const {
    return x_.next(s, a, i);
  }

  bool accept(const State& s) const {
    return !x_.accept(s);
  }

  bool successful(const State& s) const {
    return !x_.successful(s);
  }

  bool unsuccessful(const State& s) const {
    return !x_.unsuccessful(s);
  }

 private:
  X x_;
};

template <typename X, typename Y>
class ProdDfa {
 public:
  using Alphabet = pair<typename X::Alphabet, typename Y::Alphabet>;
  using State = pair<typename X::State, typename Y::State>;

  ProdDfa(const X& x, const Y& y) : x_(x), y_(y) {}

  State init() const { return make_pair(x_.init(), y_.init()); }

  State next(const State& s, const Alphabet& a, size_t i) const {
    return make_pair(x_.next(s.first, a.first, i), y_.next(s.second, a.second, i));
  }

  bool accept(const State& s) const {
    return x_.accept(s.first) and y_.accept(s.second);
  }

  bool successful(const State& s) const {
    return x_.successful(s.first) and y_.successful(s.second);
  }

  bool unsuccessful(const State& s) const {
    return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);
  }

 private:
  X x_;
  Y y_;
};

// 0以上N以下の整数を受理するDFA
class Leq {
 public:
  using Alphabet = char;
  using State = Ordering;

  Leq(const string& n) : digits_(n.begin(), n.end()) {}

  State init() const {
    return State::Equal;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    if (s == State::Greater) {
      return State::Greater;
    }

    if (s == State::Less) {
      return State::Less;
    }

    if (a < digits_[i]) {
      return State::Less;
    }

    if (a == digits_[i]) {
      return State::Equal;
    }

    return State::Greater;
  }

  bool accept(State s) const {
    return s != State::Greater;
  }

  bool successful(State s) const {
    return s == State::Less;
  }

  bool unsuccessful(State s) const {
    return s == State::Greater;
  }

 private:
  vector<char> digits_;
};

// 0以上N未満の整数を受理するDFA
class Le {
 public:
  using Alphabet = char;
  using State = Ordering;

  Le(const string& n) : digits_(n.begin(), n.end()) {}

  State init() const {
    return State::Equal;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    if (s == State::Greater) {
      return State::Greater;
    }

    if (s == State::Less) {
      return State::Less;
    }

    if (a < digits_[i]) {
      return State::Less;
    }

    if (a == digits_[i]) {
      return State::Equal;
    }

    return State::Greater;
  }

  bool accept(State s) const {
    return s == State::Less;
  }

  bool successful(State s) const {
    return s == State::Less;
  }

  bool unsuccessful(State s) const {
    return s == State::Greater;
  }

 private:
  vector<char> digits_;
};

// Mの倍数を受理するDFA
class MultipleOf {
 public:
  using Alphabet = char;
  using State = int;

  MultipleOf(int m, int base = 10) : m_(m), base_(base) {}

  State init() const {
    return 0;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    return (s * base_ + (a - '0')) % m_;
  }

  bool accept(State s) const {
    return s == 0;
  }

  bool successful(State s) const {
    return 0;
  }

  bool unsuccessful(State s) const {
    return 0;
  }

 private:
  int base_;
  int m_;
};

// popcountがちょうどKの数を受理するDFA
class PopcountOf {
 public:
  using Alphabet = char;
  using State = int;

  PopcountOf(int k) : k_(k) {}

  State init() const {
    return 0;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    return s + (a - '0');
  }

  bool accept(State s) const {
    return s == k_;
  }

  bool successful(State s) const {
    return 0;
  }

  bool unsuccessful(State s) const {
    return s > k_;
  }

 private:
  int k_;
};

// 桁和がMの倍数となる数を受理するDFA
class DigitSumMultipleOf {
 public:
  using Alphabet = char;
  using State = int;

  DigitSumMultipleOf(int m) : m_(m) {}

  State init() const {
    return 0;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    return (s + (a - '0')) % m_;
  }

  bool accept(State s) const {
    return s == 0;
  }

  bool successful(State s) const {
    return 0;
  }

  bool unsuccessful(State s) const {
    return 0;
  }

 private:
  int m_;
};

// 桁同士の積がMの倍数となる数を受理するDFA
class DigitProdMultipleOf {
 public:
  using Alphabet = char;
  using State = int;

  DigitProdMultipleOf(int m) : m_(m) {}

  State init() const {
    return -1;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    if (s == -1 and a == '0') {
      return -1;
    }
    if (s == -1 and a != '0') {
      return a - '0';
    }
    return (s * (a - '0')) % m_;
  }

  bool accept(State s) const {
    return s == 0;
  }

  bool successful(State s) const {
    return s == 0;
  }

  bool unsuccessful(State s) const {
    return 0;
  }

 private:
  int m_;
};

class LeadingZero {
 public:
  using Alphabet = char;
  using State = bool;

  LeadingZero() {}

  State init() const {
    return true;
  }

  State next(State s, const Alphabet& a, size_t i) const {
    return s and a == '0';
  }

  bool accept(State s) const {
    return !s;
  }

  bool successful(State s) const {
    return !s;
  }

  bool unsuccessful(State s) const {
    return 0;
  }
};

template <typename DFA>
long long count_dfa(const DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {
  using State = typename DFA::State;

  unordered_map<State, modint998244353> dp;
  unordered_map<State, modint998244353> dp_next;

  dp.emplace(dfa.init(), 1);

  for (size_t i = 0; i < n; ++i) {
    dp_next.clear();
    for (const auto& [state, count] : dp) {
      for (const auto& a : alphabet) {
        State s1 = dfa.next(state, a, i);
        if (dfa.unsuccessful(s1)) continue;
        dp_next[s1] = dp_next[s1] + count;
      }
    }
    dp.swap(dp_next);
  }

  modint998244353 ans = 0;
  for (const auto& [state, count] : dp) {
    if (dfa.accept(state)) {
      ans += count;
    }
  }
  return ans.val();
}

struct DPRes {
  modint998244353 num, sum;
};

template <typename DFA>
pair<long long, long long> count_sum_dfa(const DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet, int base = 10) {
  using State = typename DFA::State;

  unordered_map<State, DPRes> dp;
  unordered_map<State, DPRes> dp_next;

  dp.emplace(dfa.init(), 1);

  for (size_t i = 0; i < n; ++i) {
    dp_next.clear();
    for (const auto& [state, res] : dp) {
      for (const auto& a : alphabet) {
        State s1 = dfa.next(state, a, i);
        if (dfa.unsuccessful(s1)) continue;
        dp_next[s1].num = dp_next[s1].num + res.num;
        dp_next[s1].sum = dp_next[s1].sum + res.sum * base + (a - '0') * res.num;
      }
    }
    dp.swap(dp_next);
  }
  modint998244353 cnt = 0;
  modint998244353 sum = 0;
  for (const auto& [state, res] : dp) {
    if (dfa.accept(state)) {
      cnt += res.num;
      sum += res.sum;
    }
  }
  return {cnt.val(), sum.val()};
}

string decimalToBinary(const string& decimalStr) {
  if (decimalStr.empty()) return "0";
  string num = decimalStr;
  string binaryStr = "";
  while (num != "0") {
    int remainder = 0;
    string quotient = "";
    for (char ch : num) {
      int current = remainder * 10 + (ch - '0');
      if (!quotient.empty() || current / 2 != 0) {
        quotient += (current / 2) + '0';
      }
      remainder = current % 2;
    }
    binaryStr += (remainder ? '1' : '0');
    num = quotient.empty() ? "0" : quotient;
  }
  reverse(binaryStr.begin(), binaryStr.end());
  return binaryStr.empty() ? "0" : binaryStr;
}