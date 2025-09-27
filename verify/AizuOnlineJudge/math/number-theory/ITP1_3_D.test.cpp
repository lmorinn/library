#include "../../../../template/template.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"
#include "../../../../math/number-theory/EnumerateDivisors.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    in(a, b, c);
    int res = 0;
    for (int d : enumerate_divisors(c)) {
        if (a <= d and d <= b) res++;
    }

    out(res);
}