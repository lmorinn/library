#include "../../../template/template.hpp"

#include "../../../linear-algebra/BitMatrix.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  in(n);
  BitMatrix a(n);
  rep(i, n) {
    string s;
    in(s);
    rep(j, n) {
      if (s[j] == '1') a[i][j] = 1;
    }
  }

  out(a.determinant());
}
