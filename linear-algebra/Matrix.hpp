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
};
