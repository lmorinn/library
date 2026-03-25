struct Point {
  long long x, y;
};

__int128_t cross(const Point& a, const Point& b) {
  return (__int128_t)a.x * b.y - (__int128_t)a.y * b.x;
}

template <auto f = less()>
bool cmp(const Point& a, const Point& b) {
  int ah = (f(a.y, 0) or (a.y == 0 and a.x > 0));
  int bh = (f(b.y, 0) or (b.y == 0 and b.x > 0));
  if (ah != bh) return ah > bh;
  __int128_t c = cross(a, b);
  if (c == 0) {
    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
  } else {
    return c > 0;
  }
}
