#pragma once
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
struct SplayTree {
   private:
    struct Node {
        Node *l = 0;
        Node *r = 0;
        Node *p = 0;
        // 値、集約値、作用値
        S val = e();
        S acc = e();
        F lazy = id();
        int idx = -1;
        int z = 0;
        int sumz = 0;
        bool rev = 0;
    };

    using pNode = unique_ptr<Node>;
    pNode pNIL;
    Node *NIL = nullptr;
    vector<pNode> A;
    Node *R;

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
            if (v->l != NIL) v->l->rev ^= 1;
            if (v->r != NIL) v->r->rev ^= 1;

            v->rev = 0;
        }
        v->lazy = id();
    }

    void update(Node *v) {
        v->sumz = v->l->sumz + v->r->sumz + 1;
        v->acc = op(op(v->l->acc, v->val), v->r->acc);
    }

    Node *&parentchild(Node *v) {
        if (v->p == NIL) return R;
        if (v->p->l == v) {
            return v->p->l;
        } else {
            return v->p->r;
        }
    }

    void rotL(Node *v) {
        Node *p = v->p;
        parentchild(p) = v;
        v->p = p->p;
        p->p = v;
        if (v->l != NIL) v->l->p = p;
        p->r = v->l;
        v->l = p;
    }

    void rotR(Node *v) {
        Node *p = v->p;
        parentchild(p) = v;
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
            if (p != NIL) push(p);
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
            if (p != NIL) update(p);
            update(v);
        }
        update(v);
    }

    Node *access(int k) {
        Node *c = R;
        while (true) {
            push(c);
            if (c->l->sumz == k) break;
            if (c->l->sumz > k) {
                c = c->l;
                continue;
            }
            k -= c->l->sumz + 1;
            c = c->r;
        }
        push(c);
        splay(c);
        return c;
    }

    Node *between(int l, int r) {
        if (l == 0 and r == R->sumz) return R;
        if (l == 0) return access(r)->l;
        if (r == R->sumz) return access(l - 1)->r;
        auto rp = access(r);
        auto lp = rp->l;
        R = lp;
        lp->p = NIL;
        lp = access(l - 1);
        R = rp;
        rp->l = lp;
        lp->p = rp;
        update(rp);
        return lp->r;
    }

   public:
    // コンストラクタ
    SplayTree() {
        if (!pNIL) {
            pNIL = make_unique<Node>();
            NIL = pNIL.get();
            NIL->l = NIL->r = NIL->p = NIL;
            R = NIL;
        }
    }

    // 左からk-1番目の要素のすぐ右側に要素xを挿入する（0-indexed）
    void insert_at(int k, S x) {
        pNode pnx = make_unique<Node>(*NIL);
        Node *nx = pnx.get();
        nx->z = nx->sumz = 1;
        nx->idx = A.size();
        nx->val = nx->acc = x;
        A.emplace_back(move(pnx));
        if (k == 0) {
            nx->r = R;
            if (R != NIL) R->p = nx;
            R = nx;
            update(nx);
            return;
        }
        if (k == R->sumz) {
            nx->l = R;
            if (R != NIL) R->p = nx;
            R = nx;
            update(nx);
            return;
        }
        auto p = access(k);
        nx->l = p->l;
        nx->r = p;
        R = nx;
        p->l->p = nx;
        p->p = nx;
        p->l = NIL;
        update(p);
        update(nx);
    }

    // 左からk番目の要素を削除する (0-indexed)
    void erase_at(int k) {
        auto p = access(k);
        if (k == 0) {
            R = p->r;
            if (R != NIL) R->p = NIL;
        } else if (k == R->sumz - 1) {
            R = p->l;
            if (R != NIL) R->p = NIL;
        } else {
            auto l = p->l;
            auto r = p->r;
            r->p = NIL;
            R = r;
            access(0);
            r = R;
            r->l = l;
            l->p = r;
            update(r);
        }
        swap(p->idx, A.back()->idx);
        swap(A[p->idx], A[A.back()->idx]);
        A.pop_back();
    }

    // [l,r)の区間を反転
    void reverse(int l, int r) {
        auto c = between(l, r);
        c->rev ^= 1;
        splay(c);
    }

    // [l,r)の区間にfを作用
    void apply(int l, int r, F f) {
        auto c = between(l, r);
        c->val = mapping(f, c->val);
        c->acc = mapping(f, c->acc);
        c->lazy = composition(f, c->lazy);
        splay(c);
    }

    // [l,r)の区間の総積
    S prod(int l, int r) {
        return between(l, r)->acc;
    }

    // 添字アクセス
    S operator[](int k) {
        return access(k)->val;
    }
};