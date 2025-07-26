class AVLTree {
   private:
    struct Node {
        Node *p, *left, *right;
        int key, height;
        int subtree_size;

        // Balance Factor
        int bf() {
            return left->height - right->height;
        }
    };
    int siz;
    Node *NIL;
    Node *root;

    // 左回転
    void rotate_left(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != NIL) y->left->p = x;
        y->p = x->p;
        if (x->p == NIL) {
            root = y;
        } else if (x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }
        y->left = x;
        x->p = y;
        update(x);
        update(y);
    }

    // 右回転
    void rotate_right(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        if (x->right != NIL) x->right->p = y;
        x->p = y->p;
        if (y->p == NIL) {
            root = x;
        } else if (y == y->p->left) {
            y->p->left = x;
        } else {
            y->p->right = x;
        }
        x->right = y;
        y->p = x;
        update(y);
        update(x);
    }

    // 右回転→左回転
    void rotate_RL(Node *x) {
        rotate_right(x->right);
        rotate_left(x);
    }

    // 左回転→右回転
    void rotate_LR(Node *z) {
        rotate_left(z->left);
        rotate_right(z);
    }

    // 部分木curの情報を更新する（左右の子の情報が最新でないといけない）
    void update(Node *cur) {
        cur->height = max(cur->left->height, cur->right->height) + 1;
        cur->subtree_size = cur->left->subtree_size + cur->right->subtree_size + 1;
    }

    // ノードポインタzをAVL木に挿入する。挿入できた場合true、zのkeyがすでに含まれていた場合falseを返す
    bool insert(Node *z) {
        Node *y = NIL;
        Node *x = root;
        while (x != NIL) {
            y = x;
            if (z->key == x->key) {
                delete z;
                return false;
            }
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->p = y;
        if (y == NIL) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        siz++;
        insert_fixup(z);
        return true;
    }

    // 挿入操作時のAVL木修復処理
    void insert_fixup(Node *z) {
        bool active = true;
        while (z->p != NIL) {
            Node *u = z->p;
            update(u);
            if (!active) {
                z = u;
                continue;
            }
            int bf_u = u->bf();
            if (u->left == z) {
                if (bf_u == 0) {
                    active = false;
                } else if (bf_u == 2) {
                    Node *v = u->left;
                    if (v->bf() == 1) {
                        rotate_right(u);
                        active = false;
                    } else {
                        rotate_LR(u);
                        active = false;
                    }
                }
            } else {
                if (bf_u == 0) {
                    active = false;
                } else if (bf_u == -2) {
                    Node *v = u->right;
                    if (v->bf() == -1) {
                        rotate_left(u);
                        active = false;
                    } else {
                        rotate_RL(u);
                        active = false;
                    }
                }
            }
            z = u;
        }
    }

    // curの部分木内で最小のキーを持つノードポインタを返す
    Node *min_element(Node *cur) {
        while (cur->left != NIL) {
            cur = cur->left;
        }
        return cur;
    }

    // 部分木uの場所に部分木vを植え替える(uの親の子をvにする)
    void transplant(Node *u, Node *v) {
        if (u->p == NIL) {
            root = v;
        } else if (u == u->p->left) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        v->p = u->p;
        if (u->p != NIL) update(u->p);
    }

    // ノードポインタzをAVL木から削除する。
    void erase(Node *z) {
        Node *x;
        Node *y = z;
        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = min_element(z->right);
            x = y->right;
            if (y->p == z) {
                x->p = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->p = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->p = y;
        }
        erase_fixup(x);
        siz--;
        delete z;
    }

    // 削除操作時のAVL木修復処理
    void erase_fixup(Node *z) {
        bool active = true;
        while (z->p != NIL) {
            Node *u = z->p;
            update(u);
            if (!active) {
                z = u;
                continue;
            }
            int bf_u = u->bf();
            if (u->right == z) {
                if (bf_u == 1) {
                    active = false;
                } else if (bf_u == 2) {
                    Node *v = u->left;
                    if (v->bf() == 1) {
                        rotate_right(u);
                    } else if (v->bf() == 0) {
                        rotate_right(u);
                        active = false;
                    } else if (v->bf() == -1) {
                        rotate_LR(u);
                    }
                }
            } else {
                if (bf_u == -1) {
                    active = false;
                } else if (bf_u == -2) {
                    Node *v = u->right;
                    if (v->bf() == -1) {
                        rotate_left(u);
                    } else if (v->bf() == 0) {
                        rotate_left(u);
                        active = false;
                    } else if (v->bf() == 1) {
                        rotate_RL(u);
                    }
                }
            }
            z = u;
        }
    }

    // keyのノードポインタを返す。keyが存在しなければNILを返す。
    Node *contains(Node *cur, int key) {
        while (cur != NIL and cur->key != key) {
            if (key < cur->key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return cur;
    }

    int less_count(Node *cur, int key) {
        int res = 0;
        while (cur != NIL) {
            if (cur->key < key) {
                res += cur->left->subtree_size + 1;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return res;
    }

    Node *kth_element(Node *cur, int k) {
        while (cur != NIL and k > 0) {
            if (cur->left->subtree_size < k) {
                k -= cur->left->subtree_size;
                if (k == 1) return cur;
                k--;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return cur;
    }

    Node *lower_bound(Node *cur, int key) {
        Node *res = NIL;
        while (cur != NIL) {
            if (key <= cur->key) {
                res = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }

    Node *upper_bound(Node *cur, int key) {
        Node *res = NIL;
        while (cur != NIL) {
            if (key >= cur->key) {
                res = cur;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return res;
    }

   public:
    // コンストラクタ
    AVLTree() {
        NIL = new Node();
        NIL->key = 0;
        NIL->p = NIL->left = NIL->right = NIL;
        NIL->height = 0;
        NIL->subtree_size = 0;
        root = NIL;
        siz = 0;
    }

    // AVL木にkeyを挿入する。挿入されたらtrue、keyがすでに存在したらfalseを返す(何もしない)
    bool insert(int key) {
        Node *z = new Node();
        z->key = key;
        z->left = NIL;
        z->right = NIL;
        z->height = 1;
        z->subtree_size = 1;
        return insert(z);
    }

    // AVL木からkeyを削除する。削除されたらtrue、keyが存在しなかったらfalseを返す（何もしない）
    bool erase(int key) {
        Node *z = contains(root, key);
        if (z != NIL) {
            erase(z);
            return true;
        } else {
            return false;
        }
    }

    // AVL木にkeyが含まれているならtrue、そうでなければfalseを返す
    bool contains(int key) {
        Node *z = contains(root, key);
        return z != NIL;
    }

    // 現在のAVL木の要素数を返す
    int size() {
        return siz;
    }

    // key未満の要素の個数を返す
    int less_count(int key) {
        return less_count(root, key);
    }

    // 0-indexedで昇順idx番目の要素を返す。存在しないなら-1を返す
    int kth_element(int idx) {
        Node *z = kth_element(root, idx + 1);
        if (z != NIL) {
            return z->key;
        } else {
            return -1;
        }
    }

    // key以上の要素のうち最小のものを返す。存在しないなら-1を返す
    int lower_bound(int key) {
        Node *z = lower_bound(root, key);
        if (z == NIL) return -1;
        return z->key;
    }

    // key以下の要素のうち最大のものを返す。存在しないなら-1を返す
    int upper_bound(int key) {
        Node *z = upper_bound(root, key);
        if (z == NIL) return -1;
        return z->key;
    }
};