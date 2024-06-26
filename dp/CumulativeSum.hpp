#pragma once
template <class T>
class CumulativeSum {
 private:
  int siz;
  vector<T> s;

 public:
  CumulativeSum() {}
  CumulativeSum(vector<T> &a) {
    siz = a.size();
    s.resize(siz + 1, 0);
    for (int i = 0; i < siz; i++) {
      s[i + 1] = s[i] + a[i];
    }
  }

  T sum(int r) {
    return s[r];
  }

  T sum(int l, int r) {
    return s[r] - s[l];
  }
};