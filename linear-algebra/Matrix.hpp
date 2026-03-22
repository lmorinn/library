template <class S>
struct Matrix {
 private:
 public:
  vector<vector<S>> A;
  Matrix() {}
  Matrix(int n, int m) : A(n, vector<S>(m)) {}
  Matrix(int n) : A(n, vector<S>(n)) {}

  inline int size() const { return A.size(); }
  inline int height() const { return A.size(); }
  inline int width() const { return A[0].size(); }
  inline const vector<S>& operator[](int h) const { return (A[h]); }
  inline vector<S>& operator[](int h) { return (A[h]); }

  Matrix& operator+=(const Matrix& B) {
    int h = height();
    int w = width();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        (*this)[i][j] += B[i][j];
      }
    }
    return (*this);
  }
  Matrix& operator-=(const Matrix& B) {
    int h = height();
    int w = width();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return (*this);
  }

  Matrix& operator*=(const Matrix& B) {
    int h = height();
    int w = B.width();
    int c = width();
    vector<vector<S>> C(h, vector<S>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        for (int k = 0; k < c; k++) {
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        }
      }
    }
    A = move(C);
    return (*this);
  }
  Matrix operator+(const Matrix& B) const { return (Matrix(*this) += B); }
  Matrix operator-(const Matrix& B) const { return (Matrix(*this) -= B); }
  Matrix operator*(const Matrix& B) const { return (Matrix(*this) *= B); }

  int rank() {
    Matrix B(*this);
    if (B.height() == 0 or B.width() == 0) return 0;
    int res = 0;
    int h = height();
    int w = width();
    int ch = 0;
    int cw = 0;
    while (ch < h and cw < w) {
      bool ok = false;
      for (int j = cw; j < w; j++) {
        for (int i = ch; i < h; i++) {
          if (B[i][j] != 0) {
            ok = true;
            swap(B[ch], B[i]);
            S d = B[ch][j];
            for (int j2 = j; j2 < w; j2++) {
              B[ch][j2] /= d;
            }
            for (int i2 = 0; i2 < h; i2++) {
              if (B[i2][j] != 0 and i2 != ch) {
                S m = B[i2][j];
                for (int j2 = j; j2 < w; j2++) {
                  B[i2][j2] -= B[ch][j2] * m;
                }
              }
            }
            res++;
            ch++;
            cw = j + 1;
            break;
          }
        }
        if (ok) break;
      }
      if (!ok) break;
    }
    return res;
  }

  S determinant() {
    Matrix B(*this);
    if (B.height() == 0 or B.width() == 0) return 0;
    assert(B.height() == B.width());
    int h = height();
    int w = width();
    int ch = 0;
    int cw = 0;
    S div = 1;
    bool neg = false;
    while (ch < h and cw < w) {
      bool ok = false;
      for (int j = cw; j < w; j++) {
        for (int i = ch; i < h; i++) {
          if (B[i][j] != 0) {
            ok = true;
            if (ch != i) neg = !neg;
            swap(B[ch], B[i]);
            S d = B[ch][j];
            div /= d;
            for (int j2 = j; j2 < w; j2++) {
              B[ch][j2] /= d;
            }
            for (int i2 = 0; i2 < h; i2++) {
              if (B[i2][j] != 0 and i2 != ch) {
                S m = B[i2][j];
                for (int j2 = j; j2 < w; j2++) {
                  B[i2][j2] -= B[ch][j2] * m;
                }
              }
            }
            ch++;
            cw = j + 1;
            break;
          }
        }
        if (ok) {
          break;
        } else {
          return S(0);
        }
      }
      if (!ok) break;
    }
    S res = (neg ? -B[0][0] : B[0][0]) / div;
    for (int i = 1; i < h; i++) {
      res = res * B[i][i];
    }
    return res;
  }

  pair<bool, Matrix<S>> inverse() {
    int h = height();
    int w = width();
    assert(h == w);
    Matrix<S> B(h, w * 2);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        B[i][j] = (*this)[i][j];
      }
    }
    for (int i = 0; i < h; i++) {
      B[i][i + w] = 1;
    }
    w *= 2;
    int rnk = 0;

    int ch = 0;
    int cw = 0;
    while (ch < h and cw < h) {
      bool ok = false;
      for (int j = cw; j < h; j++) {
        for (int i = ch; i < h; i++) {
          if (B[i][j] != 0) {
            ok = true;
            swap(B[ch], B[i]);
            S d = B[ch][j];
            for (int j2 = j; j2 < w; j2++) {
              B[ch][j2] /= d;
            }
            for (int i2 = 0; i2 < h; i2++) {
              if (B[i2][j] != 0 and i2 != ch) {
                S m = B[i2][j];
                for (int j2 = j; j2 < w; j2++) {
                  B[i2][j2] -= B[ch][j2] * m;
                }
              }
            }
            rnk++;
            ch++;
            cw = j + 1;
            break;
          }
        }
        if (ok) break;
      }
      if (!ok) break;
    }
    Matrix<S> res(h);
    if (rnk == h) {
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
          res[i][j] = B[i][j + h];
        }
      }
      return {true, res};
    } else {
      return {false, res};
    }
  }
};