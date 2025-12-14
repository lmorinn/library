#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "../../../string/LCPArray.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  in(s);
  vector<int> l = LCPArray(s, suffixArray(s));
  lint n = s.size();
  lint res = n * (n + 1) / 2;
  for (auto x : l) res -= x;
  out(res);
}
