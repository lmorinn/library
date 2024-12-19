#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "../../../string/SuffixAutomaton.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  in(s);
  out(SuffixAutomaton(s).number_of_substrings());
}
