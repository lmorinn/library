#include "../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../../../string/SuffixArray.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    in(s);
    out(suffixArray(s));
}
