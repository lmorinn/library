---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/Geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
  bundledCode: "#line 1 \"verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 1e-8\n#include <bits/stdc++.h>\nusing namespace std;\n#line 2\
    \ \"geometry/Geometry.hpp\"\n#define EPS (1e-10)\n#define equals(a, b) (fabsl((a)\
    \ - (b)) < EPS)\n\nstatic const int COUNTER_CLOCKWISE = 1;\nstatic const int CLOCKWISE\
    \ = -1;\nstatic const int ONLINE_BACK = 2;\nstatic const int ONLINE_FRONT = -2;\n\
    static const int ON_SEGMENT = 0;\nstatic const int CONTAIN = 2;\nstatic const\
    \ int CONTAIN_LINE = 1;\nstatic const int NOT_CONTAIN = 0;\nstatic const int CIRCUMSCRIPTION\
    \ = 3;\nstatic const int INSCRIPTION = 1;\nstatic const int INTERSECT = 2;\nstatic\
    \ const int CONNOTATION = 0;\nstatic const int NOT_CONNOTATION = 4;\n\nstruct\
    \ Point {\n public:\n  long double x, y;\n  Point(long double x = 0, long double\
    \ y = 0) : x(x), y(y) {}\n\n  Point operator+(Point p) { return Point(x + p.x,\
    \ y + p.y); }\n  Point operator-(Point p) { return Point(x - p.x, y - p.y); }\n\
    \  Point operator*(long double a) { return Point(a * x, a * y); }\n  Point operator/(long\
    \ double a) { return Point(x / a, y / a); }\n  bool operator<(const Point &p)\
    \ const { return x != p.x ? x < p.x : y < p.y; }\n  bool operator>(const Point\
    \ &p) const { return x != p.x ? x > p.x : y > p.y; }\n  bool operator==(const\
    \ Point &p) const { return fabsl(x - p.x) < EPS and fabsl(y - p.y) < EPS; }\n\n\
    \  long double abs() { return sqrtl(norm()); }\n  long double norm() { return\
    \ x * x + y * y; }\n};\n\n\nostream &operator<<(ostream &os, const Point &p) {\n\
    \  os <<  p.x << \" \" << p.y;\n  return os;\n}\n\n\n\n\n\nusing Vector = Point;\n\
    \nlong double norm(Vector a) {\n  return a.x * a.x + a.y * a.y;\n}\n\nlong double\
    \ abs(Vector a) {\n  return sqrtl(norm(a));\n}\n\nstruct Segment {\n  Point p1,\
    \ p2;\n  Segment(Point x, Point y) {\n    p1 = x;\n    p2 = y;\n  }\n};\n\nusing\
    \ Line = Segment;\n\nclass Circle {\n public:\n  Point c;\n  long double r;\n\
    \  Circle(Point c = Point(), long double r = 0.0) : c(c), r(r) {}\n};\n\nusing\
    \ Polygon = vector<Point>;\n\n// \u30D9\u30AF\u30C8\u30EB a\u3068b\u306E\u5185\
    \u7A4D\u3092\u8FD4\u3059\nlong double dot(Vector a, Vector b) {\n  return a.x\
    \ * b.x + a.y * b.y;\n}\n\n// \u30D9\u30AF\u30C8\u30EB a\u3068b\u306E\u5916\u7A4D\
    \u3092\u8FD4\u3059\nlong double cross(Vector a, Vector b) {\n  return a.x * b.y\
    \ - a.y * b.x;\n}\n\n// \u30D9\u30AF\u30C8\u30EB a\u3068b\u304C\u76F4\u4EA4\u304B\
    \u3069\u3046\u304B\u3092\u8FD4\u3059\nbool isOrthogonal(Vector a, Vector b) {\n\
    \  return equals(dot(a, b), 0.0);\n}\n\n// \u70B9\u3000a1,a2\u304B\u3089\u306A\
    \u308B\u30D9\u30AF\u30C8\u30EB\u3068 b1,b2\u304B\u3089\u306A\u308B\u30D9\u30AF\
    \u30C8\u30EB\u304C\u76F4\u4EA4\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\nbool\
    \ isOrthogonal(Point a1, Point a2, Point b1, Point b2) {\n  return isOrthogonal(a1\
    \ - a2, b1 - b2);\n}\n\n// \u7DDA\u5206 a\u3068b\u304C\u76F4\u4EA4\u304B\u3069\
    \u3046\u304B\u3092\u8FD4\u3059\nbool isOrthogonal(Segment s1, Segment s2) {\n\
    \  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);\n}\n\n// \u30D9\u30AF\
    \u30C8\u30EB a\u3068b\u304C\u5E73\u884C\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\
    \nbool isParallel(Vector a, Vector b) {\n  return equals(cross(a, b), 0.0);\n\
    }\n\n// \u70B9\u3000a1,a2\u304B\u3089\u306A\u308B\u30D9\u30AF\u30C8\u30EB\u3068\
    \ b1,b2\u304B\u3089\u306A\u308B\u30D9\u30AF\u30C8\u30EB\u304C\u5E73\u884C\u304B\
    \u3069\u3046\u304B\u3092\u8FD4\u3059\nbool isParallel(Point a1, Point a2, Point\
    \ b1, Point b2) {\n  return isParallel(a1 - a2, b1 - b2);\n}\n\n// \u7DDA\u5206\
    \ a\u3068b\u304C\u5E73\u884C\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\nbool isParallel(Segment\
    \ s1, Segment s2) {\n  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);\n\
    }\n\n// \u70B9p\u304B\u3089\u7DDA\u5206s\u306B\u5782\u7DDA\u3092\u4E0B\u308D\u3057\
    \u305F\u6642\u306E\u4EA4\u70B9\uFF08\u5C04\u5F71\uFF09\u3092\u8FD4\u3059\nPoint\
    \ project(Segment s, Point p) {\n  Vector base = s.p2 - s.p1;\n  long double r\
    \ = dot(p - s.p1, base) / norm(base);\n  return s.p1 + base * r;\n}\n\n// \u7DDA\
    \u5206s\u3092\u5BFE\u79F0\u8EF8\u3068\u3057\u3066\u3001\u70B9p\u3068\u7DDA\u5BFE\
    \u79F0\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u70B9\uFF08\u53CD\u5C04\uFF09\u3092\
    \u8FD4\u3059\nPoint reflect(Segment s, Point p) {\n  return p + (project(s, p)\
    \ - p) * 2.0;\n}\n\n// 2\u70B9\u9593\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\nlong\
    \ double Distance(Point a, Point b) {\n  return abs(a - b);\n}\n\n// \u70B9p\u3068\
    \u76F4\u7DDAl\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\nlong double DistanceLP(Line\
    \ l, Point p) {\n  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));\n\
    }\n\n// \u70B9p\u3068\u7DDA\u5206l\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\nlong double\
    \ DistanceSP(Segment s, Point p) {\n  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return\
    \ abs(p - s.p1);\n  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);\n\
    \  return DistanceLP(s, p);\n}\n\n// \u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2\u3092\
    \u8ABF\u3079\u308B\nint ccw(Point p0, Point p1, Point p2) {\n  Vector a = p1 -\
    \ p0;\n  Vector b = p2 - p0;\n  // p0->p1\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B\
    \u56DE\u8EE2\u3055\u305B\u308B\u65B9\u5411\u306Bp2\u304C\u5B58\u5728\u3059\u308B\
    \n  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;\n  // p0->p1\u3092\u6642\u8A08\
    \u56DE\u308A\u306B\u56DE\u8EE2\u3055\u305B\u308B\u65B9\u5411\u306Bp2\u304C\u5B58\
    \u5728\u3059\u308B\n  if (cross(a, b) < -EPS) return CLOCKWISE;\n  // 3\u70B9\u306F\
    \u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u5B58\u5728\u3057\u30012\u70B9\u306B\u631F\
    \u307E\u308C\u3066\u3044\u308B\u70B9\u306Fp0\n  if (dot(a, b) < -EPS) return ONLINE_BACK;\n\
    \  // 3\u70B9\u306F\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u5B58\u5728\u3057\u3001\
    2\u70B9\u306B\u631F\u307E\u308C\u3066\u3044\u308B\u70B9\u306Fp1\n  if (a.norm()\
    \ < b.norm()) return ONLINE_FRONT;\n  // 3\u70B9\u306F\u540C\u4E00\u76F4\u7DDA\
    \u4E0A\u306B\u5B58\u5728\u3057\u30012\u70B9\u306B\u631F\u307E\u308C\u3066\u3044\
    \u308B\u70B9\u306Fp2\n  return ON_SEGMENT;\n}\n\n// \u70B9p1,p2\u304B\u3089\u306A\
    \u308B\u7DDA\u5206\u3068p3,p4\u304B\u3089\u306A\u308B\u7DDA\u5206\u304C\u4EA4\u5DEE\
    \u3059\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\nbool intersect(Point p1,\
    \ Point p2, Point p3, Point p4) {\n  return (ccw(p1, p2, p3) * ccw(p1, p2, p4)\
    \ <= 0 and ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);\n}\n\n// \u7DDA\u5206 s1\u3068\
    s2\u304C\u4EA4\u5DEE\u3059\u308B\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\nbool\
    \ intersect(Segment s1, Segment s2) {\n  return intersect(s1.p1, s1.p2, s2.p1,\
    \ s2.p2);\n}\n\n// \u5186 c1\u3068c2\u306E\u4F4D\u7F6E\u95A2\u4FC2\u3092\u8ABF\
    \u3079\u308B\nint intersect(Circle c1, Circle c2) {\n  long double d = abs((c1.c\
    \ - c2.c));\n  // 2\u3064\u306E\u5186\u306F\u96E2\u308C\u3066\u3044\u308B\uFF08\
    \u5185\u5305\u3057\u3066\u3044\u306A\u3044\uFF09\n  if (d > c1.r + c2.r + EPS)\
    \ {\n    return NOT_CONNOTATION;\n  }\n  // \u5916\u63A5\u3057\u3066\u3044\u308B\
    \n  if (equals(d, c1.r + c2.r)) {\n    return CIRCUMSCRIPTION;\n  }\n  // \u5185\
    \u63A5\u3057\u3066\u3044\u308B\n  if (equals(d, abs(c1.r - c2.r))) {\n    return\
    \ INSCRIPTION;\n  }\n  // \u5185\u5305\u3057\u3066\u3044\u308B\n  if (d < abs(c1.r\
    \ - c2.r) - EPS) {\n    return CONNOTATION;\n  }\n  // 2\u70B9\u3067\u4EA4\u308F\
    \u308B\n  return INTERSECT;\n}\n\n// \u70B9 a,b,c\u304B\u3089\u306A\u308B\u4E09\
    \u89D2\u5F62\u306E\u5185\u63A5\u5186\u3092\u8FD4\u3059\nCircle inCircle(Point\
    \ a, Point b, Point c) {\n  long double A = abs(b - c);\n  long double B = abs(a\
    \ - c);\n  long double C = abs(a - b);\n  Point p((A * a.x) + (B * b.x) + (C *\
    \ c.x), (A * a.y) + (B * b.y) + (C * c.y));\n  p = p / (A + B + C);\n  long double\
    \ r = DistanceLP({a, b}, p);\n  return Circle(p, r);\n}\n\n// \u7DDA\u5206 s1\u3068\
    s2\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\nlong double Distance(Segment s1, Segment\
    \ s2) {\n  if (intersect(s1, s2)) return 0.0;\n  return min({DistanceSP(s1, s2.p1),\
    \ DistanceSP(s1, s2.p2), DistanceSP(s2, s1.p1), DistanceSP(s2, s1.p2)});\n}\n\n\
    // \u7DDA\u5206 s1\u3068s2\u306E\u4EA4\u70B9\u3092\u8FD4\u3059\nPoint CrossPoint(Segment\
    \ s1, Segment s2) {\n  Vector base = s2.p2 - s2.p1;\n  long double d1 = abs(cross(base,\
    \ s1.p1 - s2.p1));\n  long double d2 = abs(cross(base, s1.p2 - s2.p1));\n  long\
    \ double t = d1 / (d1 + d2);\n  return s1.p1 + (s1.p2 - s1.p1) * t;\n}\n\n// \u5186\
    \ c\u3068\u3001\u76F4\u7DDAl\u306E\u4EA4\u70B9\u3092\u8FD4\u3059\ntemplate<class\
    \ T>\npair<T, T> CrossPoints(Circle c, Line l) {\n  Vector pr = project(l, c.c);\n\
    \  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);\n  long double base = sqrtl(c.r\
    \ * c.r - norm(pr - c.c));\n  return {Point(pr + e * base), Point(pr - e * base)};\n\
    }\n\nlong double arg(Vector p) { return atan2l(p.y, p.x); }\nVector polar(long\
    \ double a, long double r) { return Point(cosl(r) * a, sinl(r) * a); }\n\n// \u5186\
    \ c1\u3068c2\u306E\u4EA4\u70B9\u3092\u8FD4\u3059\ntemplate<class T>\npair<T, T>\
    \ CrossPoints(Circle c1, Circle c2) {\n  long double d = abs(c1.c - c2.c);\n \
    \ long double a = acosl((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));\n\
    \  long double t = arg(c2.c - c1.c);\n  return {c1.c + polar(c1.r, t + a), c1.c\
    \ + polar(c1.r, t - a)};\n}\n\n// \u70B9 p\u3092\u901A\u308B\u3001\u5186c\u306E\
    \u63A5\u7DDA\u3092\u6C42\u3081\u3001\u305D\u306E\u63A5\u70B9\u3092\u8FD4\u3059\
    \ p\u306F\u5186\u306E\u5916\u5074\u3060\u3068\u4EEE\u5B9A\u3059\u308B\ntemplate<class\
    \ T>\npair<T, T> tangentToCircle(Circle c, Point p) {\n  return CrossPoints<Point>(c,\
    \ Circle(p, sqrtl(norm(c.c - p) - c.r * c.r)));\n}\n\n// \u70B9 p\u304C\u3001\u591A\
    \u89D2\u5F62g\u306E\u5185\u90E8\u3001\u8FBA\u4E0A\u3001\u5916\u90E8\u306E\u3046\
    \u3061\u3069\u3053\u306B\u3042\u308B\u304B\u8FD4\u3059\nint contains(Polygon g,\
    \ Point p) {\n  int n = g.size();\n  bool x = false;\n  for (int i = 0; i < n;\
    \ i++) {\n    Point a = g[i] - p, b = g[(i + 1) % n] - p;\n    if (abs(cross(a,\
    \ b)) < EPS and dot(a, b) < EPS) return CONTAIN_LINE;\n    if (a.y > b.y) swap(a,\
    \ b);\n    if (a.y < EPS and EPS < b.y and cross(a, b) > EPS) x = !x;\n  }\n \
    \ return (x ? CONTAIN : NOT_CONTAIN);\n}\n\n// \u591A\u89D2\u5F62p\u306E\u9762\
    \u7A4D\u3092\u8FD4\u3059\nlong double PolygonArea(const vector<Point> &p) {\n\
    \  long double res = 0;\n  int n = p.size();\n  for (int i = 0; i < n - 1; i++)\
    \ {\n    res += cross(p[i], p[i + 1]);\n  }\n  res += cross(p[n - 1], p[0]);\n\
    \  return res * 0.5;\n}\n\n// \u591A\u89D2\u5F62p\u304C\u51F8\u591A\u89D2\u5F62\
    \u304B\u3069\u3046\u304B\u8FD4\u3059\nbool isConvex(const vector<Point> &p) {\n\
    \  int n = p.size();\n  int now, pre, nxt;\n  for (int i = 0; i < n; i++) {\n\
    \    pre = (i - 1 + n) % n;\n    nxt = (i + 1) % n;\n    now = i;\n    if (ccw(p[pre],\
    \ p[now], p[nxt]) == CLOCKWISE) {\n      return false;\n    }\n  }\n  return true;\n\
    }\n\n// \u51F8\u5305\nPolygon andrewScan(Polygon s, bool on_line = 0) {\n  Polygon\
    \ u, l;\n  if (s.size() < 3) return s;\n  sort(s.begin(), s.end());\n\n  u.push_back(s[0]);\n\
    \  u.push_back(s[1]);\n\n  l.push_back(s[s.size() - 1]);\n  l.push_back(s[s.size()\
    \ - 2]);\n  if (on_line) {\n    for (int i = 2; i < s.size(); i++) {\n      for\
    \ (int n = u.size(); n >= 2 and ccw(u[n - 2], u[n - 1], s[i]) == COUNTER_CLOCKWISE;\
    \ n--) {\n        u.pop_back();\n      }\n      u.push_back(s[i]);\n    }\n\n\
    \    for (int i = s.size() - 3; i >= 0; i--) {\n      for (int n = l.size(); n\
    \ >= 2 and ccw(l[n - 2], l[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {\n      \
    \  l.pop_back();\n      }\n      l.push_back(s[i]);\n    }\n  } else {\n    for\
    \ (int i = 2; i < s.size(); i++) {\n      for (int n = u.size(); n >= 2 and ccw(u[n\
    \ - 2], u[n - 1], s[i]) != CLOCKWISE; n--) {\n        u.pop_back();\n      }\n\
    \      u.push_back(s[i]);\n    }\n\n    for (int i = s.size() - 3; i >= 0; i--)\
    \ {\n      for (int n = l.size(); n >= 2 and ccw(l[n - 2], l[n - 1], s[i]) !=\
    \ CLOCKWISE; n--) {\n        l.pop_back();\n      }\n      l.push_back(s[i]);\n\
    \    }\n    reverse(l.begin(), l.end());\n    for (int i = u.size() - 2; i >=\
    \ 1; i--) l.push_back(u[i]);\n  }\n  return l;\n}\n#line 6 \"verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp\"\
    \nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n  int x1, y1, x2, y2;\n  cin\
    \ >> x1 >> y1 >> x2 >> y2;\n  Line l(Point(x1, y1), Point(x2, y2));\n  int q;\n\
    \  cin >> q;\n  for (int i = 0; i < q; i++) {\n    int x, y;\n    cin >> x >>\
    \ y;\n    outf(reflect(l, Point(x, y)));\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 1e-8\n#include <bits/stdc++.h>\nusing namespace std;\n#include\
    \ \"../../../geometry/Geometry.hpp\"\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  int x1, y1, x2, y2;\n  cin >> x1 >> y1 >> x2 >> y2;\n  Line l(Point(x1, y1),\
    \ Point(x2, y2));\n  int q;\n  cin >> q;\n  for (int i = 0; i < q; i++) {\n  \
    \  int x, y;\n    cin >> x >> y;\n    outf(reflect(l, Point(x, y)));\n  }\n}\n"
  dependsOn:
  - geometry/Geometry.hpp
  isVerificationFile: true
  path: verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-06-28 14:42:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
layout: document
redirect_from:
- /verify/verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
- /verify/verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp.html
title: verify/AizuOnlineJudge/geometry/CGL_1_B.test.cpp
---
