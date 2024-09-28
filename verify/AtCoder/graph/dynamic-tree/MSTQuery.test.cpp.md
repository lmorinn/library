---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dynamic-tree/LinkCutTreeEdge.hpp
    title: Link Cut Tree (Edge)
  - icon: ':question:'
    path: template/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc355/tasks/abc355_f
    links:
    - https://atcoder.jp/contests/abc355/tasks/abc355_f
  bundledCode: "#line 2 \"template/template.hpp\"\n#pragma region Macros\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing lint = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\nusing int128 = __int128_t;\n#define\
    \ all(x) (x).begin(), (x).end()\n#define uniqv(v) v.erase(unique(all(v)), v.end())\n\
    #define OVERLOAD_REP(_1, _2, _3, name, ...) name\n#define REP1(i, n) for (auto\
    \ i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))\n#define REP2(i, l, r) for\
    \ (auto i = (l); (i) != (r); ++(i))\n#define rep(...) OVERLOAD_REP(__VA_ARGS__,\
    \ REP2, REP1)(__VA_ARGS__)\n#define logfixed(x) cout << fixed << setprecision(10)\
    \ << x << endl;\n\nostream &operator<<(ostream &dest, __int128_t value) {\n  ostream::sentry\
    \ s(dest);\n  if (s) {\n    __uint128_t tmp = value < 0 ? -value : value;\n  \
    \  char buffer[128];\n    char *d = end(buffer);\n    do {\n      --d;\n     \
    \ *d = \"0123456789\"[tmp % 10];\n      tmp /= 10;\n    } while (tmp != 0);\n\
    \    if (value < 0) {\n      --d;\n      *d = '-';\n    }\n    int len = end(buffer)\
    \ - d;\n    if (dest.rdbuf()->sputn(d, len) != len) {\n      dest.setstate(ios_base::badbit);\n\
    \    }\n  }\n  return dest;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &v) {\n  for (int i = 0; i < (int)v.size(); i++) {\n  \
    \  os << v[i] << (i + 1 != (int)v.size() ? \" \" : \"\");\n  }\n  return os;\n\
    }\n\ntemplate <typename T>\nostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\n  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\n    os\
    \ << *itr;\n    ++itr;\n    if (itr != set_var.end()) os << \" \";\n    itr--;\n\
    \  }\n  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os,\
    \ const unordered_set<T> &set_var) {\n  for (auto itr = set_var.begin(); itr !=\
    \ set_var.end(); itr++) {\n    os << *itr;\n    ++itr;\n    if (itr != set_var.end())\
    \ os << \" \";\n    itr--;\n  }\n  return os;\n}\n\ntemplate <typename T, typename\
    \ U>\nostream &operator<<(ostream &os, const map<T, U> &map_var) {\n  for (auto\
    \ itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os << itr->first\
    \ << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\ntemplate <typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const unordered_map<T, U> &map_var)\
    \ {\n  for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\n    os\
    \ << itr->first << \" -> \" << itr->second << \"\\n\";\n  }\n  return os;\n}\n\
    \ntemplate <typename T, typename U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &pair_var) {\n  os << pair_var.first << \" \" << pair_var.second;\n  return\
    \ os;\n}\n\nvoid out() { cout << '\\n'; }\ntemplate <class T, class... Ts>\nvoid\
    \ out(const T &a, const Ts &...b) {\n  cout << a;\n  (cout << ... << (cout <<\
    \ ' ', b));\n  cout << '\\n';\n}\n\nvoid outf() { cout << '\\n'; }\ntemplate <class\
    \ T, class... Ts>\nvoid outf(const T &a, const Ts &...b) {\n  cout << fixed <<\
    \ setprecision(14) << a;\n  (cout << ... << (cout << ' ', b));\n  cout << '\\\
    n';\n}\n\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v)\
    \ {\n  for (T &in : v) is >> in;\n  return is;\n}\n\ninline void in(void) { return;\
    \ }\ntemplate <typename First, typename... Rest>\nvoid in(First &first, Rest &...rest)\
    \ {\n  cin >> first;\n  in(rest...);\n  return;\n}\n\ntemplate <typename T>\n\
    bool chmax(T &a, const T &b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <typename T>\nbool chmin(T &a, const T &b)\
    \ {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\n\
    vector<lint> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};\nvector<lint> dy8 = {0, 1, 1,\
    \ 1, 0, -1, -1, -1};\nvector<lint> dx4 = {1, 0, -1, 0};\nvector<lint> dy4 = {0,\
    \ 1, 0, -1};\n\n#pragma endregion\n#line 2 \"verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc355/tasks/abc355_f\"\n#line\
    \ 2 \"graph/dynamic-tree/LinkCutTreeEdge.hpp\"\nstruct S {\n    unsigned long\
    \ long val;\n    int u, v;\n};\nusing F = unsigned long long;\nstruct LinkCutTree\
    \ {\n   private:\n    static S op(S a, S b) {\n        if (a.val > b.val) {\n\
    \            return a;\n        } else {\n            return b;\n        }\n \
    \   }\n    static S e() {\n        return {0, -1, -1};\n    }\n\n    // \u53CD\
    \u8EE2\u306E\u51E6\u7406\n    // \u5165\u529B\u6642\u306Bb2\u306E\u5165\u529B\u3092\
    \u5FD8\u308C\u306A\u3044\n    // \u4E00\u6B21\u95A2\u6570\u306E\u5408\u6210\u306A\
    \u3089,b1\u3068b2\u3092swap\n    static void reverseprod(S &x) {\n    }\n\n  \
    \  static S mapping(F f, S x) {\n        return x;\n    }\n    static F composition(F\
    \ f, F x) {\n        return x;\n    }\n    static F id() {\n        return 0;\n\
    \    }\n\n    struct Node {\n        Node *l = 0;\n        Node *r = 0;\n    \
    \    Node *p = 0;\n        Node *pp = 0;\n        // \u5024\u3001\u96C6\u7D04\u5024\
    \u3001\u4F5C\u7528\u5024\n        S val = e();\n        S acc = e();\n       \
    \ F lazy = id();\n        int idx = -1;\n        int z = 0;\n        int sumz\
    \ = 0;\n        int w = 0;\n        int sumw = 0;\n        bool rev = 0;\n   \
    \     int u = -1;\n        int v = -1;\n    };\n\n    using pNode = shared_ptr<Node>;\n\
    \    pNode pNIL;\n    Node *NIL = nullptr;\n    vector<pNode> A;\n    vector<unordered_map<int,\
    \ Node *>> ed;\n    queue<int> unused;\n\n    void push(Node *v) {\n        if\
    \ (v->l != NIL) {\n            v->l->val = mapping(v->lazy, v->l->val);\n    \
    \        v->l->acc = mapping(v->lazy, v->l->acc);\n            v->l->lazy = composition(v->lazy,\
    \ v->l->lazy);\n        }\n        if (v->r != NIL) {\n            v->r->val =\
    \ mapping(v->lazy, v->r->val);\n            v->r->acc = mapping(v->lazy, v->r->acc);\n\
    \            v->r->lazy = composition(v->lazy, v->r->lazy);\n        }\n     \
    \   if (v->rev) {\n            swap(v->l, v->r);\n            if (v->l != NIL)\
    \ {\n                v->l->rev ^= 1;\n                reverseprod(v->l->acc);\n\
    \            }\n            if (v->r != NIL) {\n                v->r->rev ^= 1;\n\
    \                reverseprod(v->r->acc);\n            }\n            v->rev =\
    \ 0;\n        }\n        v->lazy = id();\n    }\n\n    void update(Node *v) {\n\
    \        v->sumz = v->l->sumz + v->r->sumz + 1;\n        v->sumw = v->l->sumw\
    \ + v->r->sumw + 1;\n        v->acc = op(op(v->l->acc, v->val), v->r->acc);\n\
    \    }\n\n    Node *&parentchild(Node *v) {\n        if (v->p == NIL) return NIL;\n\
    \        if (v->p->l == v) {\n            return v->p->l;\n        } else {\n\
    \            return v->p->r;\n        }\n    }\n\n    Node *at(int idx) {\n  \
    \      return A[idx].get();\n    }\n\n    void rotL(Node *v) {\n        Node *p\
    \ = v->p;\n        if (p->p == NIL) {\n            swap(p->pp, v->pp);\n     \
    \   } else {\n            parentchild(p) = v;\n        }\n        v->p = p->p;\n\
    \        p->p = v;\n        if (v->l != NIL) v->l->p = p;\n        p->r = v->l;\n\
    \        v->l = p;\n    }\n\n    void rotR(Node *v) {\n        Node *p = v->p;\n\
    \        if (p->p == NIL) {\n            swap(p->pp, v->pp);\n        } else {\n\
    \            parentchild(p) = v;\n        }\n        v->p = p->p;\n        p->p\
    \ = v;\n        if (v->r != NIL) v->r->p = p;\n        p->l = v->r;\n        v->r\
    \ = p;\n    }\n\n    void splay(Node *v) {\n        push(v);\n        while (v->p\
    \ != NIL) {\n            Node *p = v->p;\n            Node *pp = p->p;\n     \
    \       if (pp != NIL) push(pp);\n            push(p);\n            push(v);\n\
    \n            // zig zag\n            if (p->l == v) {\n                if (pp\
    \ == NIL) {\n                    rotR(v);\n                } else if (pp->l ==\
    \ p) {\n                    rotR(p);\n                    rotR(v);\n         \
    \       } else if (pp->r == p) {\n                    rotR(v);\n             \
    \       rotL(v);\n                }\n            } else {\n                if\
    \ (pp == NIL) {\n                    rotL(v);\n                } else if (pp->r\
    \ == p) {\n                    rotL(p);\n                    rotL(v);\n      \
    \          } else if (pp->l == p) {\n                    rotL(v);\n          \
    \          rotR(v);\n                }\n            }\n\n            if (pp !=\
    \ NIL) update(pp);\n            update(p);\n        }\n        update(v);\n  \
    \  }\n\n    void expose(Node *v) {\n        auto p = v;\n        while (p != NIL)\
    \ {\n            splay(p);\n            p = p->pp;\n        }\n        p = v;\n\
    \        while (p->pp != NIL) {\n            auto prev = p->pp->r;\n         \
    \   if (prev != NIL) swap(prev->pp, prev->p);\n            swap(p->p, p->pp);\n\
    \            p->p->r = p;\n            p = p->p;\n        }\n        splay(v);\n\
    \    }\n\n    void evert(Node *v) {\n        expose(v);\n        if (v->r != NIL)\
    \ {\n            v->r->pp = v->r->p;\n            v->r->p = NIL;\n           \
    \ v->r = NIL;\n        }\n        v->rev ^= 1;\n        reverseprod(v->acc);\n\
    \        push(v);\n    }\n\n    void link(Node *u, Node *v) {\n        evert(u);\n\
    \        evert(v);\n        if (u->p != NIL or u->pp != NIL) return;\n       \
    \ u->pp = v;\n    }\n\n    void cut(Node *v) {\n        expose(v);\n        if\
    \ (v->l == NIL) return;\n        v->l->p = NIL;\n        v->l = NIL;\n    }\n\n\
    \    Node *between(Node *u, Node *v) {\n        evert(u);\n        expose(v);\n\
    \        push(v->l);\n        return v->l;\n    }\n\n    S prod(Node *u, Node\
    \ *v) {\n        S res = between(u, v)->acc;\n        res = op(res, v->val);\n\
    \        return res;\n    }\n\n    S get(Node *v) {\n        expose(v);\n    \
    \    return v->val;\n    }\n\n    void set(Node *v, S x) {\n        expose(v);\n\
    \        v->val = x;\n        update(v);\n    }\n\n   public:\n    // \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n    LinkCutTree(vector<S> &w) {\n        if (!pNIL)\
    \ {\n            pNIL = make_shared<Node>();\n            NIL = pNIL.get();\n\
    \            NIL->l = NIL->r = NIL->p = NIL->pp = NIL;\n        }\n        int\
    \ n = w.size();\n        A.resize(2 * n + 1);\n        ed.resize(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            A[i] = make_shared<Node>(*NIL);\n\
    \            A[i]->w = A[i]->sumw = 0;\n            A[i]->z = A[i]->sumz = 1;\n\
    \            A[i]->idx = i;\n            A[i]->val = A[i]->acc = w[i];\n     \
    \   }\n\n        for (int i = n; i < n * 2 - 1; i++) {\n            A[i] = make_shared<Node>(*NIL);\n\
    \            A[i]->w = A[i]->sumw = 1;\n            A[i]->z = A[i]->sumz = 0;\n\
    \            A[i]->idx = i;\n            A[i]->val = A[i]->acc = e();\n      \
    \      unused.push(i);\n        }\n    }\n\n    // u,v\u9593\u306E\u30D1\u30B9\
    \u4E0A\u306B\u66F8\u304B\u308C\u305F\u7DCF\u7A4D\n    S prod(int u, int v) {\n\
    \        return prod(at(u), at(v));\n    }\n\n    // \u9802\u70B9idx\u306Bx\u3092\
    \u4EE3\u5165\n    void set(int idx, S x) {\n        set(at(idx), x);\n    }\n\n\
    \    // \u9802\u70B9u\u3068v\u3092\u76F4\u63A5\u7D50\u3076\u8FBA\u306Bx\u3092\u4EE3\
    \u5165\n    void set(int u, int v, S x) {\n        if (u > v) swap(u, v);\n  \
    \      int edidx = ed[u][v]->idx;\n        set(edidx, x);\n    }\n\n    // \u9802\
    \u70B9idx\u306E\u5024\u3092\u53D6\u5F97\n    S get(int idx) {\n        return\
    \ get(at(idx));\n    }\n\n    // \u9802\u70B9u\u3068v\u3092\u76F4\u63A5\u7D50\u3076\
    \u8FBA\u306E\u5024\u3092\u53D6\u5F97\n    S get(int u, int v) {\n        if (u\
    \ > v) swap(u, v);\n        int edidx = ed[u][v]->idx;\n        return get(edidx);\n\
    \    }\n\n    // u\u3068v\u3092\u7D50\u3076\u91CD\u307Fx\u306E\u8FBA\u3092\u8FFD\
    \u52A0\n    void add(int u, int v, int x) {\n        if (u > v) swap(u, v);\n\
    \        int edidx = unused.front();\n        unused.pop();\n        S newedge;\n\
    \        newedge.u = u;\n        newedge.v = v;\n        newedge.val = x;\n  \
    \      Node *edge = A[edidx].get();\n        ed[u][v] = edge;\n        link(at(u),\
    \ at(edidx));\n        link(at(edidx), at(v));\n        set(edidx, newedge);\n\
    \        edge->u = u;\n        edge->v = v;\n    }\n\n    // u\u3068v\u3092\u7D50\
    \u3076\u8FBA\u3092\u524A\u9664\n    void erase(int u, int v) {\n        if (u\
    \ > v) swap(u, v);\n        Node *edge = ed[u][v];\n        int edidx = edge->idx;\n\
    \        unused.push(edidx);\n        set(edidx, e());\n        ed[u].erase(v);\n\
    \        evert(at(u));\n        cut(at(edidx));\n        evert(at(edidx));\n \
    \       cut(at(v));\n        edge->u = -1;\n        edge->v = -1;\n    }\n};\n\
    #line 4 \"verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n, q);\n    ull\
    \ sum = 0;\n    vector<S> nodew(n, {0, -1, -1});\n    LinkCutTree l(nodew);\n\
    \    rep(i, n - 1) {\n        ull a, b, c;\n        in(a, b, c);\n        a--;\n\
    \        b--;\n        l.add(a, b, c);\n        sum += c;\n    }\n    rep(i, q)\
    \ {\n        ull u, v, w;\n        in(u, v, w);\n        u--;\n        v--;\n\
    \        S path = l.prod(u, v);\n        if (path.val > w) {\n            l.erase(path.u,\
    \ path.v);\n            l.add(u, v, w);\n            sum -= path.val;\n      \
    \      sum += w;\n        }\n        out(sum);\n    }\n}\n"
  code: "#include \"../../../../template/template.hpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc355/tasks/abc355_f\"\
    \n#include \"../../../../graph/dynamic-tree/LinkCutTreeEdge.hpp\"\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    int n, q;\n    in(n, q);\n    ull\
    \ sum = 0;\n    vector<S> nodew(n, {0, -1, -1});\n    LinkCutTree l(nodew);\n\
    \    rep(i, n - 1) {\n        ull a, b, c;\n        in(a, b, c);\n        a--;\n\
    \        b--;\n        l.add(a, b, c);\n        sum += c;\n    }\n    rep(i, q)\
    \ {\n        ull u, v, w;\n        in(u, v, w);\n        u--;\n        v--;\n\
    \        S path = l.prod(u, v);\n        if (path.val > w) {\n            l.erase(path.u,\
    \ path.v);\n            l.add(u, v, w);\n            sum -= path.val;\n      \
    \      sum += w;\n        }\n        out(sum);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/dynamic-tree/LinkCutTreeEdge.hpp
  isVerificationFile: true
  path: verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 11:20:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp
layout: document
redirect_from:
- /verify/verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp
- /verify/verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp.html
title: verify/AtCoder/graph/dynamic-tree/MSTQuery.test.cpp
---
