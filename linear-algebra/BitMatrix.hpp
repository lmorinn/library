

struct BitMatrix {
 private:
 public:
  vector<dynamic_bitset<>> A;
  BitMatrix() {}
  BitMatrix(int n, int m) : A(n, dynamic_bitset<>(m)) {}
  BitMatrix(int n) : A(n, dynamic_bitset<>(n)) {}

  inline int size() const { return A.size(); }
  inline int height() const { return A.size(); }
  inline int width() const { return A[0].size(); }
  inline const dynamic_bitset<>& operator[](int h) const { return (A[h]); }
  inline dynamic_bitset<>& operator[](int h) { return (A[h]); }

  BitMatrix& operator+=(const BitMatrix& B) {
    int h = height();
    for (int i = 0; i < h; i++) (*this)[i] ^= B[i];
    return (*this);
  }
  BitMatrix& operator-=(const BitMatrix& B) {
    int h = height();
    for (int i = 0; i < h; i++) (*this)[i] ^= B[i];
    return (*this);
  }

  BitMatrix& operator*=(const BitMatrix& B) {
    int h = height();
    int w = B.width();
    int c = width();
    vector<dynamic_bitset<>> C(h, dynamic_bitset<>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < c; j++) {
        if ((*this)[i][j]) C[i] ^= B[j];
      }
    }
    A = move(C);
    return (*this);
  }

  BitMatrix operator+(const BitMatrix& B) const { return (BitMatrix(*this) += B); }
  BitMatrix operator-(const BitMatrix& B) const { return (BitMatrix(*this) -= B); }
  BitMatrix operator*(const BitMatrix& B) const { return (BitMatrix(*this) *= B); }

  int rank() {
    BitMatrix B(*this);
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
          if (B[i][j]) {
            ok = true;
            swap(B[ch], B[i]);
            for (int i2 = 0; i2 < h; i2++) {
              if (B[i2][j] != 0 and i2 != ch) B[i2] ^= B[ch];
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

  int determinant() {
    BitMatrix B(*this);
    if (B.height() == 0 or B.width() == 0) return 0;
    assert(B.height() == B.width());
    int h = height();
    int w = width();
    int ch = 0;
    int cw = 0;
    while (ch < h and cw < w) {
      bool ok = false;
      for (int j = cw; j < w; j++) {
        for (int i = ch; i < h; i++) {
          if (B[i][j]) {
            ok = true;
            swap(B[ch], B[i]);
            for (int i2 = 0; i2 < h; i2++) {
              if (B[i2][j] != 0 and i2 != ch) B[i2] ^= B[ch];
            }
            ch++;
            cw = j + 1;
            break;
          }
        }
        if (ok) {
          break;
        } else {
          return 0;
        }
      }
      if (!ok) break;
    }
    return 1;
  }

  pair<bool, BitMatrix> inverse() {
    int h = height();
    int w = width();
    assert(h == w);
    BitMatrix B(h, w * 2);
    for (int i = 0; i < h; i++) {
      dynamic_bitset<> tmp = (*this)[i];
      tmp.resize(w * 2);
      tmp[i + w] = 1;
      B[i] ^= tmp;
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
            for (int i2 = 0; i2 < h; i2++) {
              if (B[i2][j] != 0 and i2 != ch) B[i2] ^= B[ch];
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
    BitMatrix res(h);
    if (rnk == h) {
      for (int i = 0; i < h; i++) {
        B[i] >>= h;
        B[i].resize(h);
        res[i] ^= B[i];
      }
      return {true, res};
    } else {
      return {false, res};
    }
  }

  BitMatrix linear_equation(dynamic_bitset<> b) {
    BitMatrix A(*this);
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
            bool tmp = b[ch];
            b[ch] = b[i];
            b[i] = tmp;
            for (int i2 = 0; i2 < h; i2++) {
              if (A[i2][j] != 0 and i2 != ch) {
                A[i2] ^= A[ch];
                b[i2] = b[i2] ^ b[ch];
              }
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
      if (b[i] != 0) return BitMatrix(0);
    }
    BitMatrix sol(w - rnk + 1, w);
    int idx = 1;
    for (int j = 0; j < w; j++) {
      if (pivot_row[j] != -1) {
        sol[0][j] = b[pivot_row[j]];
      } else {
        sol[idx][j] = 1;
        for (int i = 0; i < w; i++) {
          if (pivot_row[i] != -1) {
            sol[idx][i] = A[pivot_row[i]][j];
          }
        }
        idx++;
      }
    }
    return sol;
  }
};