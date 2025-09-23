#include "../../../../template/template.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../../../data-structure/others/BinaryTrie.hpp"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;
    in(q);
    lazy_binary_trie<int> trie;
    rep(i, q) {
        int com, x;
        in(com, x);
        if (com == 0 and trie.count(x) == 0) {
            trie.insert(x);
        } else if (com == 1 and trie.count(x) > 0) {
            trie.erase(x);
        } else if (com == 2) {
            out(trie.min_element(x) ^ x);
        }
    }
}
