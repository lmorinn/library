#pragma once
template <int char_size = 26, char base = 'a'>
class Trie {
    struct Node {
        vector<int> child;
        vector<int> fin;
        int dist;
        int cnt;
        Node(int c_) : dist(c_), cnt(0) {
            child.resize(char_size, -1);
        }
    };

   private:
    vector<Node> tree;
    int root;

    void insert(const string &s, int word_id) {
        int node_id = 0;
        rep(i, s.size()) {
            int c = s[i] - base;
            int &next_id = tree[node_id].child[c];
            if (next_id == -1) {
                next_id = tree.size();
                tree.emplace_back(Node(c));
            }
            tree[node_id].cnt++;
            node_id = next_id;
        }
        tree[node_id].cnt++;
        tree[node_id].fin.push_back(word_id);
    }

   public:
    Trie() : root(0) {
        tree.push_back(Node(root));
    }

    // 文字列を挿入する
    void insert(const string &s) {
        insert(s, tree[0].cnt);
    }

    // 指定した文字列が存在するか or 指定したprefixをもつ文字列が存在するかどうかを返す
    bool search(const string &s, bool prefix = false) {
        int node_id = 0;
        rep(i, s.size()) {
            int c = s[i] - base;
            int &next_id = tree[node_id].child[c];
            if (next_id == -1) {
                return false;
            }
            node_id = next_id;
            out("cnt", tree[node_id].cnt);
        }
        return (prefix) ? true : tree[node_id].fin.size() > 0;
    }

    // 指定したprefixをもつ文字列が存在するかどうかを返す
    bool start_with(const string &s) {
        return search(s, 1);
    }

    // 挿入した文字列の総数を返す
    int count() {
        return tree[0].cnt;
    }
};