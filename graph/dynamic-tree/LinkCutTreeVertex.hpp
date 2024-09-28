// ReverseProd: 反転の処理
// 入力時にb2の入力を忘れない
// 一次関数の合成なら,b1とb2をswap
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id, auto reverseprod>
struct LinkCutTree {
   private:
    struct Node {
        Node *l = 0;
        Node *r = 0;
        Node *p = 0;
        Node *pp = 0;
        // 値、集約値、作用値
        S val = e();
        S acc = e();
        F lazy = id();
        int idx = -1;
        int z = 0;
        int sumz = 0;
        bool rev = 0;
    };

    using pNode = shared_ptr<Node>;
    pNode pNIL;
    Node *NIL = nullptr;
    vector<pNode> A;

    void push(Node *v) {
        if (v->l != NIL) {
            v->l->val = mapping(v->lazy, v->l->val);
            v->l->acc = mapping(v->lazy, v->l->acc);
            v->l->lazy = composition(v->lazy, v->l->lazy);
        }
        if (v->r != NIL) {
            v->r->val = mapping(v->lazy, v->r->val);
            v->r->acc = mapping(v->lazy, v->r->acc);
            v->r->lazy = composition(v->lazy, v->r->lazy);
        }
        if (v->rev) {
            swap(v->l, v->r);
            if (v->l != NIL) {
                v->l->rev ^= 1;
                reverseprod(v->l->acc);
            }
            if (v->r != NIL) {
                v->r->rev ^= 1;
                reverseprod(v->r->acc);
            }
            v->rev = 0;
        }
        v->lazy = id();
    }

    void update(Node *v) {
        v->sumz = v->l->sumz + v->r->sumz + 1;
        v->acc = op(op(v->l->acc, v->val), v->r->acc);
    }

    Node *&parentchild(Node *v) {
        if (v->p == NIL) return NIL;
        if (v->p->l == v) {
            return v->p->l;
        } else {
            return v->p->r;
        }
    }

    Node *at(int idx) {
        return A[idx].get();
    }

    void rotL(Node *v) {
        Node *p = v->p;
        if (p->p == NIL) {
            swap(p->pp, v->pp);
        } else {
            parentchild(p) = v;
        }
        v->p = p->p;
        p->p = v;
        if (v->l != NIL) v->l->p = p;
        p->r = v->l;
        v->l = p;
    }

    void rotR(Node *v) {
        Node *p = v->p;
        if (p->p == NIL) {
            swap(p->pp, v->pp);
        } else {
            parentchild(p) = v;
        }
        v->p = p->p;
        p->p = v;
        if (v->r != NIL) v->r->p = p;
        p->l = v->r;
        v->r = p;
    }

    void splay(Node *v) {
        push(v);
        while (v->p != NIL) {
            Node *p = v->p;
            Node *pp = p->p;
            if (pp != NIL) push(pp);
            push(p);
            push(v);

            // zig zag
            if (p->l == v) {
                if (pp == NIL) {
                    rotR(v);
                } else if (pp->l == p) {
                    rotR(p);
                    rotR(v);
                } else if (pp->r == p) {
                    rotR(v);
                    rotL(v);
                }
            } else {
                if (pp == NIL) {
                    rotL(v);
                } else if (pp->r == p) {
                    rotL(p);
                    rotL(v);
                } else if (pp->l == p) {
                    rotL(v);
                    rotR(v);
                }
            }

            if (pp != NIL) update(pp);
            update(p);
        }
        update(v);
    }

    void expose(Node *v) {
        auto p = v;
        while (p != NIL) {
            splay(p);
            p = p->pp;
        }
        p = v;
        while (p->pp != NIL) {
            auto prev = p->pp->r;
            if (prev != NIL) swap(prev->pp, prev->p);
            swap(p->p, p->pp);
            p->p->r = p;
            p = p->p;
        }
        splay(v);
    }

    void evert(Node *v) {
        expose(v);
        if (v->r != NIL) {
            v->r->pp = v->r->p;
            v->r->p = NIL;
            v->r = NIL;
        }
        v->rev ^= 1;
        reverseprod(v->acc);
        push(v);
    }

    void link(Node *u, Node *v) {
        evert(u);
        evert(v);
        if (u->p != NIL or u->pp != NIL) return;
        u->pp = v;
    }

    void cut(Node *v) {
        expose(v);
        if (v->l == NIL) return;
        v->l->p = NIL;
        v->l = NIL;
    }

    Node *between(Node *u, Node *v) {
        evert(u);
        expose(v);
        push(v->l);
        return v->l;
    }

    S prod(Node *u, Node *v) {
        S res = between(u, v)->acc;
        res = op(res, v->val);
        return res;
    }

    S get(Node *v) {
        expose(v);
        return v->val;
    }

    void set(Node *v, S x) {
        expose(v);
        v->val = x;
        update(v);
    }

   public:
    // コンストラクタ
    LinkCutTree(vector<S> &w) {
        if (!pNIL) {
            pNIL = make_shared<Node>();
            NIL = pNIL.get();
            NIL->l = NIL->r = NIL->p = NIL->pp = NIL;
        }
        int n = w.size();
        A.resize(n);
        for (int i = 0; i < n; i++) {
            A[i] = make_shared<Node>(*NIL);
            A[i]->z = A[i]->sumz = 1;
            A[i]->idx = i;
            A[i]->val = A[i]->acc = w[i];
        }
    }

    // u,v間のパス上の頂点に書かれた総積
    S prod(int u, int v) {
        return prod(at(u), at(v));
    }

    // 頂点idxにxを代入
    void set(int idx, S x) {
        set(at(idx), x);
    }

    // 頂点idxの値を取得
    S get(int idx) {
        return get(at(idx));
    }

    // uとvを結ぶ辺を追加
    void add(int u, int v) {
        link(at(u), at(v));
    }

    void apply(int u, int v, F f) {
        evert(at(u));
        expose(at(v));
        Node *path = between(at(u), at(v));
        if (path != NIL) {
            path->val = mapping(f, path->val);
            path->acc = mapping(f, path->acc);
            path->lazy = composition(f, path->lazy);
        }
        update(path);
        Node *nd = at(v);
        nd->val = mapping(f, nd->val);
        nd->acc = mapping(f, nd->acc);
        update(nd);
    }

    // uとvを結ぶ辺を削除
    void erase(int u, int v) {
        evert(at(u));
        cut(at(v));
    }
};