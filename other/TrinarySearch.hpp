template <class S, class T, class F>
S find_min_convex_function(T l, T r, F f) {
  while (abs(l - r) > 2) {
    T m1 = (2 * l + r) / T(3);
    T m2 = (l + 2 * r) / T(3);
    S s1 = f(m1);
    S s2 = f(m2);
    if (s1 < s2) {
      r = m2;
    } else {
      l = m1;
    }
  }
  S res = f(l);
  for (T i = l + 1; i < r + 2; i++) {
    S v = f(i);
    if (res > v) res = v;
  }
  return res;
}