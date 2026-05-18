#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "../../../../atcoder/convolution.hpp"
#include "../../../../atcoder/modint.hpp"
using namespace atcoder;
using mint = modint998244353;
#include "../../../../math/fps/BostanMori.hpp"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  lint d, k;
  in(d, k);
  FPS<mint> a(d), q(d + 1);
  rep(i, d) {
    int x;
    in(x);
    a[i] = x;
  }
  q[0] = 1;
  rep(i, d) {
    int c;
    in(c);
    q[i + 1] = -c;
  }
  a *= q;
  out(bostan_mori<mint>(a, q, k).val());
}
