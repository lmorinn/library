#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
#include "../../../string/WildcardPatternMatching.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s, t;
  in(s, t);
  for (auto b : wildcard_matching(s, t)) cout << b;
  out();
}
