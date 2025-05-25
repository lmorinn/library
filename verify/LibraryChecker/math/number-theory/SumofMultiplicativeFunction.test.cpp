#include "../../../../atcoder/modint.hpp"
#include "../../../../template/template.hpp"
using namespace atcoder;
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_multiplicative_function"
#include "../../../../math/number-theory/SumofMultiplicativeFunction.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, a, b;
        cin >> n >> a >> b;
        cout << sum_of_multiplicative(n, a, b) << '\n';
    }
}
