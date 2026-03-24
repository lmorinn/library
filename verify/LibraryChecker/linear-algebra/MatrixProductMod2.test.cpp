#include "../../../template/template.hpp"

#include "../../../linear-algebra/BitMatrix.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"

int main() {
  cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
  in(n, m, k);
  BitMatrix a(n, m), b(m, k);
  rep(i, n) {
    string s;
    in(s);
    rep(j, m) {
      if (s[j] == '1') a[i][j] = 1;
    }
  }

  rep(i, m) {
    string s;
    in(s);
    rep(j, k) {
      if (s[j] == '1') b[i][j] = 1;
    }
  }

  a *= b;
  rep(i, n) {
    string s = a[i].to_string();
    reverse(all(s));
    out(s);
  }
}
