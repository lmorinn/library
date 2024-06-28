#pragma once
#define EPS (1e-10)
#define equals(a, b) (fabsl((a) - (b)) < EPS)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
static const int CONTAIN = 2;
static const int CONTAIN_LINE = 1;
static const int NOT_CONTAIN = 0;
static const int CIRCUMSCRIPTION = 3;
static const int INSCRIPTION = 1;
static const int INTERSECT = 2;
static const int CONNOTATION = 0;
static const int NOT_CONNOTATION = 4;

struct Point {
 public:
  long double x, y;
  Point(long double x = 0, long double y = 0) : x(x), y(y) {}

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(long double a) { return Point(a * x, a * y); }
  Point operator/(long double a) { return Point(x / a, y / a); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator>(const Point &p) const { return x != p.x ? x > p.x : y > p.y; }
  bool operator==(const Point &p) const { return fabsl(x - p.x) < EPS and fabsl(y - p.y) < EPS; }

  long double abs() { return sqrtl(norm()); }
  long double norm() { return x * x + y * y; }
};


ostream &operator<<(ostream &os, const Point &p) {
  os <<  p.x << " " << p.y;
  return os;
}





using Vector = Point;

long double norm(Vector a) {
  return a.x * a.x + a.y * a.y;
}

long double abs(Vector a) {
  return sqrtl(norm(a));
}

struct Segment {
  Point p1, p2;
  Segment(Point x, Point y) {
    p1 = x;
    p2 = y;
  }
};

using Line = Segment;

class Circle {
 public:
  Point c;
  long double r;
  Circle(Point c = Point(), long double r = 0.0) : c(c), r(r) {}
};

using Polygon = vector<Point>;

// ベクトル aとbの内積を返す
long double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}

// ベクトル aとbの外積を返す
long double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

// ベクトル aとbが直交かどうかを返す
bool isOrthogonal(Vector a, Vector b) {
  return equals(dot(a, b), 0.0);
}

// 点　a1,a2からなるベクトルと b1,b2からなるベクトルが直交かどうかを返す
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}

// 線分 aとbが直交かどうかを返す
bool isOrthogonal(Segment s1, Segment s2) {
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// ベクトル aとbが平行かどうかを返す
bool isParallel(Vector a, Vector b) {
  return equals(cross(a, b), 0.0);
}

// 点　a1,a2からなるベクトルと b1,b2からなるベクトルが平行かどうかを返す
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}

// 線分 aとbが平行かどうかを返す
bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// 点pから線分sに垂線を下ろした時の交点（射影）を返す
Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  long double r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
}

// 線分sを対称軸として、点pと線対称の位置にある点（反射）を返す
Point reflect(Segment s, Point p) {
  return p + (project(s, p) - p) * 2.0;
}

// 2点間の距離を返す
long double Distance(Point a, Point b) {
  return abs(a - b);
}

// 点pと直線lの距離を返す
long double DistanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

// 点pと線分lの距離を返す
long double DistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return DistanceLP(s, p);
}

// 点の位置関係を調べる
int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  // p0->p1を反時計回りに回転させる方向にp2が存在する
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  // p0->p1を時計回りに回転させる方向にp2が存在する
  if (cross(a, b) < -EPS) return CLOCKWISE;
  // 3点は同一直線上に存在し、2点に挟まれている点はp0
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  // 3点は同一直線上に存在し、2点に挟まれている点はp1
  if (a.norm() < b.norm()) return ONLINE_FRONT;
  // 3点は同一直線上に存在し、2点に挟まれている点はp2
  return ON_SEGMENT;
}

// 点p1,p2からなる線分とp3,p4からなる線分が交差するかどうかを返す
bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

// 線分 s1とs2が交差するかどうかを返す
bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// 円 c1とc2の位置関係を調べる
int intersect(Circle c1, Circle c2) {
  long double d = abs((c1.c - c2.c));
  // 2つの円は離れている（内包していない）
  if (d > c1.r + c2.r + EPS) {
    return NOT_CONNOTATION;
  }
  // 外接している
  if (equals(d, c1.r + c2.r)) {
    return CIRCUMSCRIPTION;
  }
  // 内接している
  if (equals(d, abs(c1.r - c2.r))) {
    return INSCRIPTION;
  }
  // 内包している
  if (d < abs(c1.r - c2.r) - EPS) {
    return CONNOTATION;
  }
  // 2点で交わる
  return INTERSECT;
}

// 点 a,b,cからなる三角形の内接円を返す
Circle inCircle(Point a, Point b, Point c) {
  long double A = abs(b - c);
  long double B = abs(a - c);
  long double C = abs(a - b);
  Point p((A * a.x) + (B * b.x) + (C * c.x), (A * a.y) + (B * b.y) + (C * c.y));
  p = p / (A + B + C);
  long double r = DistanceLP({a, b}, p);
  return Circle(p, r);
}

// 線分 s1とs2の距離を返す
long double Distance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min({DistanceSP(s1, s2.p1), DistanceSP(s1, s2.p2), DistanceSP(s2, s1.p1), DistanceSP(s2, s1.p2)});
}

// 線分 s1とs2の交点を返す
Point CrossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  long double d1 = abs(cross(base, s1.p1 - s2.p1));
  long double d2 = abs(cross(base, s1.p2 - s2.p1));
  long double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}

// 円 cと、直線lの交点を返す
template<class T>
pair<T, T> CrossPoints(Circle c, Line l) {
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  long double base = sqrtl(c.r * c.r - norm(pr - c.c));
  return {Point(pr + e * base), Point(pr - e * base)};
}

long double arg(Vector p) { return atan2l(p.y, p.x); }
Vector polar(long double a, long double r) { return Point(cosl(r) * a, sinl(r) * a); }

// 円 c1とc2の交点を返す
template<class T>
pair<T, T> CrossPoints(Circle c1, Circle c2) {
  long double d = abs(c1.c - c2.c);
  long double a = acosl((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  long double t = arg(c2.c - c1.c);
  return {c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a)};
}

// 点 pを通る、円cの接線を求め、その接点を返す pは円の外側だと仮定する
template<class T>
pair<T, T> tangentToCircle(Circle c, Point p) {
  return CrossPoints<Point>(c, Circle(p, sqrtl(norm(c.c - p) - c.r * c.r)));
}

// 点 pが、多角形gの内部、辺上、外部のうちどこにあるか返す
int contains(Polygon g, Point p) {
  int n = g.size();
  bool x = false;
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    if (abs(cross(a, b)) < EPS and dot(a, b) < EPS) return CONTAIN_LINE;
    if (a.y > b.y) swap(a, b);
    if (a.y < EPS and EPS < b.y and cross(a, b) > EPS) x = !x;
  }
  return (x ? CONTAIN : NOT_CONTAIN);
}

// 多角形pの面積を返す
long double PolygonArea(const vector<Point> &p) {
  long double res = 0;
  int n = p.size();
  for (int i = 0; i < n - 1; i++) {
    res += cross(p[i], p[i + 1]);
  }
  res += cross(p[n - 1], p[0]);
  return res * 0.5;
}

// 多角形pが凸多角形かどうか返す
bool isConvex(const vector<Point> &p) {
  int n = p.size();
  int now, pre, nxt;
  for (int i = 0; i < n; i++) {
    pre = (i - 1 + n) % n;
    nxt = (i + 1) % n;
    now = i;
    if (ccw(p[pre], p[now], p[nxt]) == CLOCKWISE) {
      return false;
    }
  }
  return true;
}

// 凸包
Polygon andrewScan(Polygon s, bool on_line = 0) {
  Polygon u, l;
  if (s.size() < 3) return s;
  sort(s.begin(), s.end());

  u.push_back(s[0]);
  u.push_back(s[1]);

  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);
  if (on_line) {
    for (int i = 2; i < s.size(); i++) {
      for (int n = u.size(); n >= 2 and ccw(u[n - 2], u[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
        u.pop_back();
      }
      u.push_back(s[i]);
    }

    for (int i = s.size() - 3; i >= 0; i--) {
      for (int n = l.size(); n >= 2 and ccw(l[n - 2], l[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
        l.pop_back();
      }
      l.push_back(s[i]);
    }
  } else {
    for (int i = 2; i < s.size(); i++) {
      for (int n = u.size(); n >= 2 and ccw(u[n - 2], u[n - 1], s[i]) != CLOCKWISE; n--) {
        u.pop_back();
      }
      u.push_back(s[i]);
    }

    for (int i = s.size() - 3; i >= 0; i--) {
      for (int n = l.size(); n >= 2 and ccw(l[n - 2], l[n - 1], s[i]) != CLOCKWISE; n--) {
        l.pop_back();
      }
      l.push_back(s[i]);
    }
    reverse(l.begin(), l.end());
    for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);
  }
  return l;
}