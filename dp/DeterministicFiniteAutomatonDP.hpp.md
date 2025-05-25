---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
    title: verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/DeterministicFiniteAutomatonDP.hpp\"\n\nenum class Ordering\
    \ { Less,\n                      Equal,\n                      Greater };\n\n\
    namespace std {\ntemplate <>\nstruct hash<Ordering> {\n    std::size_t operator()(const\
    \ Ordering& o) const {\n        return std::hash<int>()(static_cast<int>(o));\n\
    \    }\n};\ntemplate <typename T1, typename T2>\nstruct hash<pair<T1, T2>> {\n\
    \    std::size_t operator()(const pair<T1, T2>& p) const {\n        return std::hash<T1>()(p.first)\
    \ * 31 + std::hash<T2>()(p.second);\n    }\n};\n\n}  // namespace std\n\nstruct\
    \ TupleHash {\n    size_t operator()(const std::tuple<int, int, int>& t) const\
    \ {\n        auto [x, y, z] = t;\n        return std::hash<int>()(x) ^ (std::hash<int>()(y)\
    \ << 1) ^ (std::hash<int>()(z) << 2);\n    }\n};\n\ntemplate <typename X>\nclass\
    \ Dfa {\n   public:\n    using Alphabet = typename X::Alphabet;\n    using State\
    \ = typename X::State;\n\n    Dfa(const X& x) : x_(x) {}\n\n    State init() const\
    \ { return x_.init(); }\n\n    State next(const State& s, const Alphabet& a, size_t\
    \ i) const {\n        return x_.next(s, a, i);\n    }\n\n    bool accept(const\
    \ State& s) const {\n        return x_.accept(s);\n    }\n\n    bool successful(const\
    \ State& s) const {\n        return x_.successful(s);\n    }\n\n    bool unsuccessful(const\
    \ State& s) const {\n        return x_.unsuccessful(s);\n    }\n\n   private:\n\
    \    X x_;\n};\n\ntemplate <typename X, typename Y>\nclass AndDfa {\n   public:\n\
    \    using Alphabet = typename X::Alphabet;\n    using State = pair<typename X::State,\
    \ typename Y::State>;\n\n    AndDfa(const X& x, const Y& y) : x_(x), y_(y) {}\n\
    \n    State init() const { return make_pair(x_.init(), y_.init()); }\n\n    State\
    \ next(const State& s, const Alphabet& a, size_t i) const {\n        return make_pair(x_.next(s.first,\
    \ a, i), y_.next(s.second, a, i));\n    }\n\n    bool accept(const State& s) const\
    \ {\n        return x_.accept(s.first) and y_.accept(s.second);\n    }\n\n   \
    \ bool successful(const State& s) const {\n        return x_.successful(s.first)\
    \ and y_.successful(s.second);\n    }\n\n    bool unsuccessful(const State& s)\
    \ const {\n        return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);\n\
    \    }\n\n   private:\n    X x_;\n    Y y_;\n};\n\ntemplate <typename X, typename\
    \ Y>\nclass OrDfa {\n   public:\n    using Alphabet = typename X::Alphabet;\n\
    \    using State = pair<typename X::State, typename Y::State>;\n\n    OrDfa(const\
    \ X& x, const Y& y) : x_(x), y_(y) {}\n\n    State init() const { return make_pair(x_.init(),\
    \ y_.init()); }\n\n    State next(const State& s, const Alphabet& a, size_t i)\
    \ const {\n        return make_pair(x_.next(s.first, a, i), y_.next(s.second,\
    \ a, i));\n    }\n\n    bool accept(const State& s) const {\n        return x_.accept(s.first)\
    \ or y_.accept(s.second);\n    }\n\n    bool successful(const State& s) const\
    \ {\n        return x_.successful(s.first) or y_.successful(s.second);\n    }\n\
    \n    bool unsuccessful(const State& s) const {\n        return x_.unsuccessful(s.first)\
    \ and y_.unsuccessful(s.second);\n    }\n\n   private:\n    X x_;\n    Y y_;\n\
    };\n\ntemplate <typename X>\nclass NotDfa {\n   public:\n    using Alphabet =\
    \ typename X::Alphabet;\n    using State = typename X::State;\n\n    NotDfa(const\
    \ X& x) : x_(x) {}\n\n    State init() const { return x_.init(); }\n\n    State\
    \ next(const State& s, const Alphabet& a, size_t i) const {\n        return x_.next(s,\
    \ a, i);\n    }\n\n    bool accept(const State& s) const {\n        return !x_.accept(s);\n\
    \    }\n\n    bool successful(const State& s) const {\n        return !x_.successful(s);\n\
    \    }\n\n    bool unsuccessful(const State& s) const {\n        return !x_.unsuccessful(s);\n\
    \    }\n\n   private:\n    X x_;\n};\n\ntemplate <typename X, typename Y>\nclass\
    \ ProdDfa {\n   public:\n    using Alphabet = pair<typename X::Alphabet, typename\
    \ Y::Alphabet>;\n    using State = pair<typename X::State, typename Y::State>;\n\
    \n    ProdDfa(const X& x, const Y& y) : x_(x), y_(y) {}\n\n    State init() const\
    \ { return make_pair(x_.init(), y_.init()); }\n\n    State next(const State& s,\
    \ const Alphabet& a, size_t i) const {\n        return make_pair(x_.next(s.first,\
    \ a.first, i), y_.next(s.second, a.second, i));\n    }\n\n    bool accept(const\
    \ State& s) const {\n        return x_.accept(s.first) and y_.accept(s.second);\n\
    \    }\n\n    bool successful(const State& s) const {\n        return x_.successful(s.first)\
    \ and y_.successful(s.second);\n    }\n\n    bool unsuccessful(const State& s)\
    \ const {\n        return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);\n\
    \    }\n\n   private:\n    X x_;\n    Y y_;\n};\n\n// 0\u4EE5\u4E0AN\u4EE5\u4E0B\
    \u306E\u6574\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass Leq {\n   public:\n\
    \    using Alphabet = char;\n    using State = Ordering;\n\n    Leq(const string&\
    \ n) : digits_(n.begin(), n.end()) {}\n\n    State init() const {\n        return\
    \ State::Equal;\n    }\n\n    State next(State s, const Alphabet& a, size_t i)\
    \ const {\n        if (s == State::Greater) {\n            return State::Greater;\n\
    \        }\n\n        if (s == State::Less) {\n            return State::Less;\n\
    \        }\n\n        if (a < digits_[i]) {\n            return State::Less;\n\
    \        }\n\n        if (a == digits_[i]) {\n            return State::Equal;\n\
    \        }\n\n        return State::Greater;\n    }\n\n    bool accept(State s)\
    \ const {\n        return s != State::Greater;\n    }\n\n    bool successful(State\
    \ s) const {\n        return s == State::Less;\n    }\n\n    bool unsuccessful(State\
    \ s) const {\n        return s == State::Greater;\n    }\n\n   private:\n    vector<char>\
    \ digits_;\n};\n\n// 0\u4EE5\u4E0AN\u672A\u6E80\u306E\u6574\u6570\u3092\u53D7\u7406\
    \u3059\u308BDFA\nclass Le {\n   public:\n    using Alphabet = char;\n    using\
    \ State = Ordering;\n\n    Le(const string& n) : digits_(n.begin(), n.end()) {}\n\
    \n    State init() const {\n        return State::Equal;\n    }\n\n    State next(State\
    \ s, const Alphabet& a, size_t i) const {\n        if (s == State::Greater) {\n\
    \            return State::Greater;\n        }\n\n        if (s == State::Less)\
    \ {\n            return State::Less;\n        }\n\n        if (a < digits_[i])\
    \ {\n            return State::Less;\n        }\n\n        if (a == digits_[i])\
    \ {\n            return State::Equal;\n        }\n\n        return State::Greater;\n\
    \    }\n\n    bool accept(State s) const {\n        return s == State::Less;\n\
    \    }\n\n    bool successful(State s) const {\n        return s == State::Less;\n\
    \    }\n\n    bool unsuccessful(State s) const {\n        return s == State::Greater;\n\
    \    }\n\n   private:\n    vector<char> digits_;\n};\n\n// M\u306E\u500D\u6570\
    \u3092\u53D7\u7406\u3059\u308BDFA\nclass MultipleOf {\n   public:\n    using Alphabet\
    \ = char;\n    using State = int;\n\n    MultipleOf(int m, int base = 10) : m_(m),\
    \ base_(base) {}\n\n    State init() const {\n        return 0;\n    }\n\n   \
    \ State next(State s, const Alphabet& a, size_t i) const {\n        return (s\
    \ * base_ + (a - '0')) % m_;\n    }\n\n    bool accept(State s) const {\n    \
    \    return s == 0;\n    }\n\n    bool successful(State s) const {\n        return\
    \ 0;\n    }\n\n    bool unsuccessful(State s) const {\n        return 0;\n   \
    \ }\n\n   private:\n    int base_;\n    int m_;\n};\n\n// popcount\u304C\u3061\
    \u3087\u3046\u3069K\u306E\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass PopcountOf\
    \ {\n   public:\n    using Alphabet = char;\n    using State = int;\n\n    PopcountOf(int\
    \ k) : k_(k) {}\n\n    State init() const {\n        return 0;\n    }\n\n    State\
    \ next(State s, const Alphabet& a, size_t i) const {\n        return s + (a -\
    \ '0');\n    }\n\n    bool accept(State s) const {\n        return s == k_;\n\
    \    }\n\n    bool successful(State s) const {\n        return 0;\n    }\n\n \
    \   bool unsuccessful(State s) const {\n        return s > k_;\n    }\n\n   private:\n\
    \    int k_;\n};\n\n// \u6841\u548C\u304CM\u306E\u500D\u6570\u3068\u306A\u308B\
    \u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass DigitSumMultipleOf {\n   public:\n\
    \    using Alphabet = char;\n    using State = int;\n\n    DigitSumMultipleOf(int\
    \ m) : m_(m) {}\n\n    State init() const {\n        return 0;\n    }\n\n    State\
    \ next(State s, const Alphabet& a, size_t i) const {\n        return (s + (a -\
    \ '0')) % m_;\n    }\n\n    bool accept(State s) const {\n        return s ==\
    \ 0;\n    }\n\n    bool successful(State s) const {\n        return 0;\n    }\n\
    \n    bool unsuccessful(State s) const {\n        return 0;\n    }\n\n   private:\n\
    \    int m_;\n};\n\n// \u6841\u540C\u58EB\u306E\u7A4D\u304CM\u306E\u500D\u6570\
    \u3068\u306A\u308B\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass DigitProdMultipleOf\
    \ {\n   public:\n    using Alphabet = char;\n    using State = int;\n\n    DigitProdMultipleOf(int\
    \ m) : m_(m) {}\n\n    State init() const {\n        return -1;\n    }\n\n   \
    \ State next(State s, const Alphabet& a, size_t i) const {\n        if (s == -1\
    \ and a == '0') {\n            return -1;\n        }\n        if (s == -1 and\
    \ a != '0') {\n            return a - '0';\n        }\n        return (s * (a\
    \ - '0')) % m_;\n    }\n\n    bool accept(State s) const {\n        return s ==\
    \ 0;\n    }\n\n    bool successful(State s) const {\n        return s == 0;\n\
    \    }\n\n    bool unsuccessful(State s) const {\n        return 0;\n    }\n\n\
    \   private:\n    int m_;\n};\n\nclass LeadingZero {\n   public:\n    using Alphabet\
    \ = char;\n    using State = bool;\n\n    LeadingZero() {}\n\n    State init()\
    \ const {\n        return true;\n    }\n\n    State next(State s, const Alphabet&\
    \ a, size_t i) const {\n        return s and a == '0';\n    }\n\n    bool accept(State\
    \ s) const {\n        return !s;\n    }\n\n    bool successful(State s) const\
    \ {\n        return !s;\n    }\n\n    bool unsuccessful(State s) const {\n   \
    \     return 0;\n    }\n};\n\ntemplate <typename DFA>\nlong long count_dfa(const\
    \ DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {\n    using\
    \ State = typename DFA::State;\n\n    unordered_map<State, modint998244353> dp;\n\
    \    unordered_map<State, modint998244353> dp_next;\n\n    dp.emplace(dfa.init(),\
    \ 1);\n\n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n    \
    \    for (const auto& [state, count] : dp) {\n            for (const auto& a :\
    \ alphabet) {\n                State s1 = dfa.next(state, a, i);\n           \
    \     if (dfa.unsuccessful(s1)) continue;\n                dp_next[s1] = dp_next[s1]\
    \ + count;\n            }\n        }\n        dp.swap(dp_next);\n    }\n\n   \
    \ modint998244353 ans = 0;\n    for (const auto& [state, count] : dp) {\n    \
    \    if (dfa.accept(state)) {\n            ans += count;\n        }\n    }\n \
    \   return ans.val();\n}\n\ntemplate <typename DFA>\nlong long count_dfa_ll(const\
    \ DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {\n    using\
    \ State = typename DFA::State;\n\n    unordered_map<State, long long> dp;\n  \
    \  unordered_map<State, long long> dp_next;\n\n    dp.emplace(dfa.init(), 1);\n\
    \n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n        for\
    \ (const auto& [state, count] : dp) {\n            for (const auto& a : alphabet)\
    \ {\n                State s1 = dfa.next(state, a, i);\n                if (dfa.unsuccessful(s1))\
    \ continue;\n                dp_next[s1] = dp_next[s1] + count;\n            }\n\
    \        }\n        dp.swap(dp_next);\n    }\n\n    long long ans = 0;\n    for\
    \ (const auto& [state, count] : dp) {\n        if (dfa.accept(state)) {\n    \
    \        ans += count;\n        }\n    }\n    return ans;\n}\n\nstruct DPRes {\n\
    \    modint998244353 num, sum;\n};\n\ntemplate <typename DFA>\npair<long long,\
    \ long long> count_sum_dfa(const DFA& dfa, size_t n, const vector<typename DFA::Alphabet>&\
    \ alphabet, int base = 10) {\n    using State = typename DFA::State;\n\n    unordered_map<State,\
    \ DPRes> dp;\n    unordered_map<State, DPRes> dp_next;\n\n    dp.emplace(dfa.init(),\
    \ 1);\n\n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n    \
    \    for (const auto& [state, res] : dp) {\n            for (const auto& a : alphabet)\
    \ {\n                State s1 = dfa.next(state, a, i);\n                if (dfa.unsuccessful(s1))\
    \ continue;\n                dp_next[s1].num = dp_next[s1].num + res.num;\n  \
    \              dp_next[s1].sum = dp_next[s1].sum + res.sum * base + (a - '0')\
    \ * res.num;\n            }\n        }\n        dp.swap(dp_next);\n    }\n   \
    \ modint998244353 cnt = 0;\n    modint998244353 sum = 0;\n    for (const auto&\
    \ [state, res] : dp) {\n        if (dfa.accept(state)) {\n            cnt += res.num;\n\
    \            sum += res.sum;\n        }\n    }\n    return {cnt.val(), sum.val()};\n\
    }\n\nstring decimalToBinary(const string& decimalStr) {\n    if (decimalStr.empty())\
    \ return \"0\";\n    string num = decimalStr;\n    string binaryStr = \"\";\n\
    \    while (num != \"0\") {\n        int remainder = 0;\n        string quotient\
    \ = \"\";\n        for (char ch : num) {\n            int current = remainder\
    \ * 10 + (ch - '0');\n            if (!quotient.empty() || current / 2 != 0) {\n\
    \                quotient += (current / 2) + '0';\n            }\n           \
    \ remainder = current % 2;\n        }\n        binaryStr += (remainder ? '1' :\
    \ '0');\n        num = quotient.empty() ? \"0\" : quotient;\n    }\n    reverse(binaryStr.begin(),\
    \ binaryStr.end());\n    return binaryStr.empty() ? \"0\" : binaryStr;\n}\n"
  code: "\nenum class Ordering { Less,\n                      Equal,\n           \
    \           Greater };\n\nnamespace std {\ntemplate <>\nstruct hash<Ordering>\
    \ {\n    std::size_t operator()(const Ordering& o) const {\n        return std::hash<int>()(static_cast<int>(o));\n\
    \    }\n};\ntemplate <typename T1, typename T2>\nstruct hash<pair<T1, T2>> {\n\
    \    std::size_t operator()(const pair<T1, T2>& p) const {\n        return std::hash<T1>()(p.first)\
    \ * 31 + std::hash<T2>()(p.second);\n    }\n};\n\n}  // namespace std\n\nstruct\
    \ TupleHash {\n    size_t operator()(const std::tuple<int, int, int>& t) const\
    \ {\n        auto [x, y, z] = t;\n        return std::hash<int>()(x) ^ (std::hash<int>()(y)\
    \ << 1) ^ (std::hash<int>()(z) << 2);\n    }\n};\n\ntemplate <typename X>\nclass\
    \ Dfa {\n   public:\n    using Alphabet = typename X::Alphabet;\n    using State\
    \ = typename X::State;\n\n    Dfa(const X& x) : x_(x) {}\n\n    State init() const\
    \ { return x_.init(); }\n\n    State next(const State& s, const Alphabet& a, size_t\
    \ i) const {\n        return x_.next(s, a, i);\n    }\n\n    bool accept(const\
    \ State& s) const {\n        return x_.accept(s);\n    }\n\n    bool successful(const\
    \ State& s) const {\n        return x_.successful(s);\n    }\n\n    bool unsuccessful(const\
    \ State& s) const {\n        return x_.unsuccessful(s);\n    }\n\n   private:\n\
    \    X x_;\n};\n\ntemplate <typename X, typename Y>\nclass AndDfa {\n   public:\n\
    \    using Alphabet = typename X::Alphabet;\n    using State = pair<typename X::State,\
    \ typename Y::State>;\n\n    AndDfa(const X& x, const Y& y) : x_(x), y_(y) {}\n\
    \n    State init() const { return make_pair(x_.init(), y_.init()); }\n\n    State\
    \ next(const State& s, const Alphabet& a, size_t i) const {\n        return make_pair(x_.next(s.first,\
    \ a, i), y_.next(s.second, a, i));\n    }\n\n    bool accept(const State& s) const\
    \ {\n        return x_.accept(s.first) and y_.accept(s.second);\n    }\n\n   \
    \ bool successful(const State& s) const {\n        return x_.successful(s.first)\
    \ and y_.successful(s.second);\n    }\n\n    bool unsuccessful(const State& s)\
    \ const {\n        return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);\n\
    \    }\n\n   private:\n    X x_;\n    Y y_;\n};\n\ntemplate <typename X, typename\
    \ Y>\nclass OrDfa {\n   public:\n    using Alphabet = typename X::Alphabet;\n\
    \    using State = pair<typename X::State, typename Y::State>;\n\n    OrDfa(const\
    \ X& x, const Y& y) : x_(x), y_(y) {}\n\n    State init() const { return make_pair(x_.init(),\
    \ y_.init()); }\n\n    State next(const State& s, const Alphabet& a, size_t i)\
    \ const {\n        return make_pair(x_.next(s.first, a, i), y_.next(s.second,\
    \ a, i));\n    }\n\n    bool accept(const State& s) const {\n        return x_.accept(s.first)\
    \ or y_.accept(s.second);\n    }\n\n    bool successful(const State& s) const\
    \ {\n        return x_.successful(s.first) or y_.successful(s.second);\n    }\n\
    \n    bool unsuccessful(const State& s) const {\n        return x_.unsuccessful(s.first)\
    \ and y_.unsuccessful(s.second);\n    }\n\n   private:\n    X x_;\n    Y y_;\n\
    };\n\ntemplate <typename X>\nclass NotDfa {\n   public:\n    using Alphabet =\
    \ typename X::Alphabet;\n    using State = typename X::State;\n\n    NotDfa(const\
    \ X& x) : x_(x) {}\n\n    State init() const { return x_.init(); }\n\n    State\
    \ next(const State& s, const Alphabet& a, size_t i) const {\n        return x_.next(s,\
    \ a, i);\n    }\n\n    bool accept(const State& s) const {\n        return !x_.accept(s);\n\
    \    }\n\n    bool successful(const State& s) const {\n        return !x_.successful(s);\n\
    \    }\n\n    bool unsuccessful(const State& s) const {\n        return !x_.unsuccessful(s);\n\
    \    }\n\n   private:\n    X x_;\n};\n\ntemplate <typename X, typename Y>\nclass\
    \ ProdDfa {\n   public:\n    using Alphabet = pair<typename X::Alphabet, typename\
    \ Y::Alphabet>;\n    using State = pair<typename X::State, typename Y::State>;\n\
    \n    ProdDfa(const X& x, const Y& y) : x_(x), y_(y) {}\n\n    State init() const\
    \ { return make_pair(x_.init(), y_.init()); }\n\n    State next(const State& s,\
    \ const Alphabet& a, size_t i) const {\n        return make_pair(x_.next(s.first,\
    \ a.first, i), y_.next(s.second, a.second, i));\n    }\n\n    bool accept(const\
    \ State& s) const {\n        return x_.accept(s.first) and y_.accept(s.second);\n\
    \    }\n\n    bool successful(const State& s) const {\n        return x_.successful(s.first)\
    \ and y_.successful(s.second);\n    }\n\n    bool unsuccessful(const State& s)\
    \ const {\n        return x_.unsuccessful(s.first) or y_.unsuccessful(s.second);\n\
    \    }\n\n   private:\n    X x_;\n    Y y_;\n};\n\n// 0\u4EE5\u4E0AN\u4EE5\u4E0B\
    \u306E\u6574\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass Leq {\n   public:\n\
    \    using Alphabet = char;\n    using State = Ordering;\n\n    Leq(const string&\
    \ n) : digits_(n.begin(), n.end()) {}\n\n    State init() const {\n        return\
    \ State::Equal;\n    }\n\n    State next(State s, const Alphabet& a, size_t i)\
    \ const {\n        if (s == State::Greater) {\n            return State::Greater;\n\
    \        }\n\n        if (s == State::Less) {\n            return State::Less;\n\
    \        }\n\n        if (a < digits_[i]) {\n            return State::Less;\n\
    \        }\n\n        if (a == digits_[i]) {\n            return State::Equal;\n\
    \        }\n\n        return State::Greater;\n    }\n\n    bool accept(State s)\
    \ const {\n        return s != State::Greater;\n    }\n\n    bool successful(State\
    \ s) const {\n        return s == State::Less;\n    }\n\n    bool unsuccessful(State\
    \ s) const {\n        return s == State::Greater;\n    }\n\n   private:\n    vector<char>\
    \ digits_;\n};\n\n// 0\u4EE5\u4E0AN\u672A\u6E80\u306E\u6574\u6570\u3092\u53D7\u7406\
    \u3059\u308BDFA\nclass Le {\n   public:\n    using Alphabet = char;\n    using\
    \ State = Ordering;\n\n    Le(const string& n) : digits_(n.begin(), n.end()) {}\n\
    \n    State init() const {\n        return State::Equal;\n    }\n\n    State next(State\
    \ s, const Alphabet& a, size_t i) const {\n        if (s == State::Greater) {\n\
    \            return State::Greater;\n        }\n\n        if (s == State::Less)\
    \ {\n            return State::Less;\n        }\n\n        if (a < digits_[i])\
    \ {\n            return State::Less;\n        }\n\n        if (a == digits_[i])\
    \ {\n            return State::Equal;\n        }\n\n        return State::Greater;\n\
    \    }\n\n    bool accept(State s) const {\n        return s == State::Less;\n\
    \    }\n\n    bool successful(State s) const {\n        return s == State::Less;\n\
    \    }\n\n    bool unsuccessful(State s) const {\n        return s == State::Greater;\n\
    \    }\n\n   private:\n    vector<char> digits_;\n};\n\n// M\u306E\u500D\u6570\
    \u3092\u53D7\u7406\u3059\u308BDFA\nclass MultipleOf {\n   public:\n    using Alphabet\
    \ = char;\n    using State = int;\n\n    MultipleOf(int m, int base = 10) : m_(m),\
    \ base_(base) {}\n\n    State init() const {\n        return 0;\n    }\n\n   \
    \ State next(State s, const Alphabet& a, size_t i) const {\n        return (s\
    \ * base_ + (a - '0')) % m_;\n    }\n\n    bool accept(State s) const {\n    \
    \    return s == 0;\n    }\n\n    bool successful(State s) const {\n        return\
    \ 0;\n    }\n\n    bool unsuccessful(State s) const {\n        return 0;\n   \
    \ }\n\n   private:\n    int base_;\n    int m_;\n};\n\n// popcount\u304C\u3061\
    \u3087\u3046\u3069K\u306E\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass PopcountOf\
    \ {\n   public:\n    using Alphabet = char;\n    using State = int;\n\n    PopcountOf(int\
    \ k) : k_(k) {}\n\n    State init() const {\n        return 0;\n    }\n\n    State\
    \ next(State s, const Alphabet& a, size_t i) const {\n        return s + (a -\
    \ '0');\n    }\n\n    bool accept(State s) const {\n        return s == k_;\n\
    \    }\n\n    bool successful(State s) const {\n        return 0;\n    }\n\n \
    \   bool unsuccessful(State s) const {\n        return s > k_;\n    }\n\n   private:\n\
    \    int k_;\n};\n\n// \u6841\u548C\u304CM\u306E\u500D\u6570\u3068\u306A\u308B\
    \u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass DigitSumMultipleOf {\n   public:\n\
    \    using Alphabet = char;\n    using State = int;\n\n    DigitSumMultipleOf(int\
    \ m) : m_(m) {}\n\n    State init() const {\n        return 0;\n    }\n\n    State\
    \ next(State s, const Alphabet& a, size_t i) const {\n        return (s + (a -\
    \ '0')) % m_;\n    }\n\n    bool accept(State s) const {\n        return s ==\
    \ 0;\n    }\n\n    bool successful(State s) const {\n        return 0;\n    }\n\
    \n    bool unsuccessful(State s) const {\n        return 0;\n    }\n\n   private:\n\
    \    int m_;\n};\n\n// \u6841\u540C\u58EB\u306E\u7A4D\u304CM\u306E\u500D\u6570\
    \u3068\u306A\u308B\u6570\u3092\u53D7\u7406\u3059\u308BDFA\nclass DigitProdMultipleOf\
    \ {\n   public:\n    using Alphabet = char;\n    using State = int;\n\n    DigitProdMultipleOf(int\
    \ m) : m_(m) {}\n\n    State init() const {\n        return -1;\n    }\n\n   \
    \ State next(State s, const Alphabet& a, size_t i) const {\n        if (s == -1\
    \ and a == '0') {\n            return -1;\n        }\n        if (s == -1 and\
    \ a != '0') {\n            return a - '0';\n        }\n        return (s * (a\
    \ - '0')) % m_;\n    }\n\n    bool accept(State s) const {\n        return s ==\
    \ 0;\n    }\n\n    bool successful(State s) const {\n        return s == 0;\n\
    \    }\n\n    bool unsuccessful(State s) const {\n        return 0;\n    }\n\n\
    \   private:\n    int m_;\n};\n\nclass LeadingZero {\n   public:\n    using Alphabet\
    \ = char;\n    using State = bool;\n\n    LeadingZero() {}\n\n    State init()\
    \ const {\n        return true;\n    }\n\n    State next(State s, const Alphabet&\
    \ a, size_t i) const {\n        return s and a == '0';\n    }\n\n    bool accept(State\
    \ s) const {\n        return !s;\n    }\n\n    bool successful(State s) const\
    \ {\n        return !s;\n    }\n\n    bool unsuccessful(State s) const {\n   \
    \     return 0;\n    }\n};\n\ntemplate <typename DFA>\nlong long count_dfa(const\
    \ DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {\n    using\
    \ State = typename DFA::State;\n\n    unordered_map<State, modint998244353> dp;\n\
    \    unordered_map<State, modint998244353> dp_next;\n\n    dp.emplace(dfa.init(),\
    \ 1);\n\n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n    \
    \    for (const auto& [state, count] : dp) {\n            for (const auto& a :\
    \ alphabet) {\n                State s1 = dfa.next(state, a, i);\n           \
    \     if (dfa.unsuccessful(s1)) continue;\n                dp_next[s1] = dp_next[s1]\
    \ + count;\n            }\n        }\n        dp.swap(dp_next);\n    }\n\n   \
    \ modint998244353 ans = 0;\n    for (const auto& [state, count] : dp) {\n    \
    \    if (dfa.accept(state)) {\n            ans += count;\n        }\n    }\n \
    \   return ans.val();\n}\n\ntemplate <typename DFA>\nlong long count_dfa_ll(const\
    \ DFA& dfa, size_t n, const vector<typename DFA::Alphabet>& alphabet) {\n    using\
    \ State = typename DFA::State;\n\n    unordered_map<State, long long> dp;\n  \
    \  unordered_map<State, long long> dp_next;\n\n    dp.emplace(dfa.init(), 1);\n\
    \n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n        for\
    \ (const auto& [state, count] : dp) {\n            for (const auto& a : alphabet)\
    \ {\n                State s1 = dfa.next(state, a, i);\n                if (dfa.unsuccessful(s1))\
    \ continue;\n                dp_next[s1] = dp_next[s1] + count;\n            }\n\
    \        }\n        dp.swap(dp_next);\n    }\n\n    long long ans = 0;\n    for\
    \ (const auto& [state, count] : dp) {\n        if (dfa.accept(state)) {\n    \
    \        ans += count;\n        }\n    }\n    return ans;\n}\n\nstruct DPRes {\n\
    \    modint998244353 num, sum;\n};\n\ntemplate <typename DFA>\npair<long long,\
    \ long long> count_sum_dfa(const DFA& dfa, size_t n, const vector<typename DFA::Alphabet>&\
    \ alphabet, int base = 10) {\n    using State = typename DFA::State;\n\n    unordered_map<State,\
    \ DPRes> dp;\n    unordered_map<State, DPRes> dp_next;\n\n    dp.emplace(dfa.init(),\
    \ 1);\n\n    for (size_t i = 0; i < n; ++i) {\n        dp_next.clear();\n    \
    \    for (const auto& [state, res] : dp) {\n            for (const auto& a : alphabet)\
    \ {\n                State s1 = dfa.next(state, a, i);\n                if (dfa.unsuccessful(s1))\
    \ continue;\n                dp_next[s1].num = dp_next[s1].num + res.num;\n  \
    \              dp_next[s1].sum = dp_next[s1].sum + res.sum * base + (a - '0')\
    \ * res.num;\n            }\n        }\n        dp.swap(dp_next);\n    }\n   \
    \ modint998244353 cnt = 0;\n    modint998244353 sum = 0;\n    for (const auto&\
    \ [state, res] : dp) {\n        if (dfa.accept(state)) {\n            cnt += res.num;\n\
    \            sum += res.sum;\n        }\n    }\n    return {cnt.val(), sum.val()};\n\
    }\n\nstring decimalToBinary(const string& decimalStr) {\n    if (decimalStr.empty())\
    \ return \"0\";\n    string num = decimalStr;\n    string binaryStr = \"\";\n\
    \    while (num != \"0\") {\n        int remainder = 0;\n        string quotient\
    \ = \"\";\n        for (char ch : num) {\n            int current = remainder\
    \ * 10 + (ch - '0');\n            if (!quotient.empty() || current / 2 != 0) {\n\
    \                quotient += (current / 2) + '0';\n            }\n           \
    \ remainder = current % 2;\n        }\n        binaryStr += (remainder ? '1' :\
    \ '0');\n        num = quotient.empty() ? \"0\" : quotient;\n    }\n    reverse(binaryStr.begin(),\
    \ binaryStr.end());\n    return binaryStr.empty() ? \"0\" : binaryStr;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/DeterministicFiniteAutomatonDP.hpp
  requiredBy: []
  timestamp: '2025-05-26 06:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AizuOnlineJudge/dp/GochiusaNumber.test.cpp
documentation_of: dp/DeterministicFiniteAutomatonDP.hpp
layout: document
title: Deterministic Finite Automaton DP
---

## 概要
todo

## 計算量
todo