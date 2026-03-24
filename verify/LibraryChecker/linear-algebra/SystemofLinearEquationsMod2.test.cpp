#include "../../../template/template.hpp"

#include "../../../linear-algebra/BitMatrix.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  in(n, m);
  BitMatrix a(n, m);
  rep(i, n) {
    string s;
    in(s);
    rep(j, m) {
      if (s[j] == '1') a[i][j] = 1;
    }
  }

  dynamic_bitset<> b(n);
  string s;
  in(s);
  rep(i, n) {
    if (s[i] == '1') b[i] = 1;
  }
  BitMatrix sol = a.linear_equation(b);
  if (sol.size() == 0) {
    out(-1);
  } else {
    out(sol.size() - 1);
    rep(i, sol.size()) {
      s = sol[i].to_string();
      reverse(all(s));
      out(s);
    }
  }
}
