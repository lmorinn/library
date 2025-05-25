#include "../../../../atcoder/modint.hpp"
#include "../../../../template/template.hpp"
using namespace atcoder;
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "../../../../math/number-theory/SumofEulersPhiFunction.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n;
    cin >> n;
    cout << sum_of_totient(n) << '\n';
}
