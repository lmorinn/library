#include "../../../template/template.hpp"

#include "../../../linear-algebra/BitMatrix.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  in(n, m);
  if (n < m) {
    BitMatrix a(n, m);
    rep(i, n) {
      string s;
      in(s);
      rep(j, m) if (s[j] == '1') a[i][j] = 1;
    }
    out(a.rank());
  } else {
    BitMatrix a(m, n);
    rep(i, n) {
      string s;
      in(s);
      rep(j, m) if (s[j] == '1') a[j][i] = 1;
    }
    out(a.rank());
  }
}
