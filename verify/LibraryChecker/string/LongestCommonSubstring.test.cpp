#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"
#include "../../../string/LongestCommonSubstring.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<string> v(2);
  in(v);
  auto res = longest_common_substring(v);
  out(res[0].first, res[0].second, res[1].first, res[1].second);
}
