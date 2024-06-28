#pragma once
#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using ull = unsigned long long;
using ld = long double;
using int128 = __int128_t;
#define all(x) (x).begin(), (x).end()
#define uniqv(v) v.erase(unique(all(v)), v.end())
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define logfixed(x) cout << fixed << setprecision(10) << x << endl;

ostream &operator<<(ostream &dest, __int128_t value) {
  ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(ios_base::badbit);
    }
  }
  return dest;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 != (int)v.size() ? " " : "");
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &set_var) {
  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &set_var) {
  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &map_var) {
  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
    os << itr->first << " -> " << itr->second << "\n";
  }
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const unordered_map<T, U> &map_var) {
  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
    os << itr->first << " -> " << itr->second << "\n";
  }
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pair_var) {
  os << pair_var.first << " " << pair_var.second;
  return os;
}

void out() { cout << '\n'; }
template <class T, class... Ts>
void out(const T &a, const Ts &...b) {
  cout << a;
  (cout << ... << (cout << ' ', b));
  cout << '\n';
}

void outf() { cout << '\n'; }
template <class T, class... Ts>
void outf(const T &a, const Ts &...b) {
  cout << fixed << setprecision(16) << a;
  (cout << ... << (cout << ' ', b));
  cout << '\n';
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) is >> in;
  return is;
}

inline void in(void) { return; }
template <typename First, typename... Rest>
void in(First &first, Rest &...rest) {
  cin >> first;
  in(rest...);
  return;
}

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

vector<lint> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};
vector<lint> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<lint> dx4 = {1, 0, -1, 0};
vector<lint> dy4 = {0, 1, 0, -1};

#pragma endregion
