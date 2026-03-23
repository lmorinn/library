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

  Matrix<S> linear_equation(vector<S> b) {
    Matrix A(*this);

    int rnk = 0;
    assert(A.height() == b.size());
    int h = height();
    int w = width();
    int ch = 0;
    int cw = 0;
    vector<int> pivot_row(w, -1);
    while (ch < h and cw < w) {
      bool ok = false;
      for (int j = cw; j < w; j++) {
        for (int i = ch; i < h; i++) {
          if (A[i][j] != 0) {
            ok = true;
            swap(A[ch], A[i]);
            swap(b[ch], b[i]);
            S d = A[ch][j];
            for (int j2 = j; j2 < w; j2++) {
              A[ch][j2] /= d;
            }
            b[ch] /= d;
            for (int i2 = 0; i2 < h; i2++) {
              S m = A[i2][j];
              if (A[i2][j] != 0 and i2 != ch) {
                for (int j2 = j; j2 < w; j2++) {
                  A[i2][j2] -= A[ch][j2] * m;
                }
              }
              if (i2 != ch) b[i2] -= b[ch] * m;
            }
            pivot_row[j] = ch;
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

    for (int i = rnk; i < h; i++) {
      if (b[i] != 0) return Matrix<S>(0);
    }
    Matrix<S> sol(w - rnk + 1, w);
    int idx = 1;
    for (int j = 0; j < w; j++) {
      if (pivot_row[j] != -1) {
        sol[0][j] = b[pivot_row[j]];
      } else {
        sol[idx][j] = 1;
        for (int i = 0; i < w; i++) {
          if (pivot_row[i] != -1) {
            sol[idx][i] = -A[pivot_row[i]][j];
          }
        }
        idx++;
      }
    }
    return sol;
  }
};