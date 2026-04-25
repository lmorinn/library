#define EPS_ 1e-8
bool equal_ld(long double a, long double b) {
  return abs(a - b) <= EPS_;
}

// a>b
bool greater_ld(long double a, long double b) {
  return !equal_ld(a, b) and a > b;
}

bool less_ld(long double a, long double b) {
  return !equal_ld(a, b) and a < b;
}

// maximize zx
// subject to Ax<=b
pair<long double, vector<long double>> simplex(vector<long double> z, vector<vector<long double>> A, vector<long double> B) {
  int n = int(A.size());
  int m = int(A[0].size());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = -A[i][j];
    }
  }

  bool is_feasible = true;
  long double min_b = 1.0;
  int min_b_id = -1;
  for (int i = 0; i < n; i++) {
    if (less_ld(B[i], 0.0)) {
      is_feasible = false;
      if (less_ld(B[i], min_b)) {
        min_b = B[i];
        min_b_id = i;
      }
    }
  }

  vector<int> n_index(m), b_index(n);
  iota(n_index.begin(), n_index.end(), 0);
  iota(b_index.begin(), b_index.end(), m);
  long double optimal_value = 0.0;

  if (!is_feasible) {
    for (int i = 0; i < n; i++) {
      A[i].emplace_back(0.0);
    }
    n_index.emplace_back(n + m);
    for (int i = 0; i < n; i++) {
      if (less_ld(B[i], 0.0)) {
        A[i][m] = 1.0;
        if (i == min_b_id) {
          B[i] = -B[i];
          for (int j = 0; j < m; j++) {
            A[i][j] = -A[i][j];
          }
          swap(b_index[i], n_index[m]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (less_ld(B[i], 0.0) and i != min_b_id) {
        B[i] += B[min_b_id];
        for (int j = 0; j < m; j++) {
          A[i][j] += A[min_b_id][j];
        }
      }
    }

    long double ap_optimal_value = min_b;
    // maximize z_
    vector<long double> z_(m + 1);
    for (int j = 0; j <= m; j++) {
      z_[j] = -A[min_b_id][j];
    }
    bool stop = false;
    while (!stop) {
      stop = true;
      int min_j = 1e9;
      int j_memo;

      for (int j = 0; j <= m; j++) {
        if (greater_ld(z_[j], 0.0) and min_j > n_index[j]) {
          min_j = n_index[j];
          j_memo = j;
          stop = false;
        }
      }

      if (min_j != 1e9) {
        int j = j_memo;
        if (greater_ld(z_[j], 0.0)) {
          stop = false;
          int min_i = 1e9;
          int i_memo;
          long double min_ratio = 1e18;
          for (int i = 0; i < n; i++) {
            if (less_ld(A[i][j], 0.0)) {
              long double ratio = B[i] / (-A[i][j]);
              if (greater_ld(min_ratio, ratio) or (equal_ld(min_ratio, ratio) and greater_ld(min_i, b_index[i]))) {
                min_i = b_index[i];
                i_memo = i;
                min_ratio = ratio;
              }
            }
          }

          if (min_i == 1e9) {
            // 非有界
            return {1e35, {}};
          } else {
            vector<long double> tmp(m + 1);
            long double coef = -A[i_memo][j];
            for (int r = 0; r < n; r++) {
              if (r == i_memo) {
                for (int c = 0; c <= m; c++) {
                  if (c != j) {
                    tmp[c] = A[r][c] / coef;
                  } else {
                    tmp[c] = (-1.0) / coef;
                  }
                }
                B[r] /= coef;
                continue;
              }
              long double mul = A[r][j];
              if (equal_ld(mul, 0.0)) continue;
              B[r] += mul * min_ratio;

              for (int c = 0; c <= m; c++) {
                if (c != j) {
                  A[r][c] += A[i_memo][c] / coef * mul;
                } else {
                  A[r][c] = (-1.0) / coef * mul;
                }
              }
            }
            long double mul = z_[j];
            ap_optimal_value += mul * min_ratio;
            for (int c = 0; c <= m; c++) {
              if (c != j) {
                z_[c] += A[i_memo][c] / coef * mul;
              } else {
                z_[c] = (-1.0) / coef * mul;
              }
            }
            swap(A[i_memo], tmp);
            swap(n_index[j], b_index[i_memo]);
          }
        }
      }
    }

    if (equal_ld(ap_optimal_value, 0.0)) {
      for (int i = 0; i < n; i++) {
        if (b_index[i] == n + m) {
          for (int j = 0; j <= m; j++) {
            if (!equal_ld(A[i][j], 0.0)) {
              vector<long double> tmp(m + 1);
              long double coef = -A[i][j];
              long double ratio = B[i] / coef;

              for (int r = 0; r < n; r++) {
                if (r == i) {
                  for (int c = 0; c <= m; c++) {
                    if (c != j) {
                      tmp[c] = A[r][c] / coef;
                    } else {
                      tmp[c] = (-1.0) / coef;
                    }
                  }
                  B[r] = ratio;
                  continue;
                }
                long double mul = A[r][j];
                if (equal_ld(mul, 0.0)) continue;
                B[r] += mul * ratio;

                for (int c = 0; c <= m; c++) {
                  if (c != j) {
                    A[r][c] += A[i][c] / coef * mul;
                  } else {
                    A[r][c] = (-1.0) / coef * mul;
                  }
                }
              }
              long double mul = z_[j];
              ap_optimal_value += mul * ratio;
              for (int c = 0; c <= m; c++) {
                if (c != j) {
                  z_[c] += A[i][c] / coef * mul;
                } else {
                  z_[c] = (-1.0) / coef * mul;
                }
              }
              swap(A[i], tmp);
              swap(n_index[j], b_index[i]);
              break;
            }
          }
        }
      }
      int art = n + m;
      int pos = -1;

      for (int j = 0; j < (int)n_index.size(); j++) {
        if (n_index[j] == art) {
          pos = j;
          break;
        }
      }

      if (pos != -1) {
        int last = (int)n_index.size() - 1;

        for (int i = 0; i < n; i++) {
          swap(A[i][pos], A[i][last]);
          A[i].pop_back();
        }

        swap(n_index[pos], n_index[last]);
        n_index.pop_back();
      }

      vector<int> rid(n + m, -1);
      for (int i = 0; i < n; i++) {
        rid[b_index[i]] = i;
      }
      for (int j = 0; j < m; j++) {
        rid[n_index[j]] = n + j;
      }
      vector<long double> nz(m, 0.0);
      for (int j = 0; j < m; j++) {
        if (!equal_ld(z[j], 0.0)) {
          if (rid[j] < n) {
            // basis
            for (int c = 0; c < m; c++) {
              nz[c] += A[rid[j]][c] * z[j];
            }
            optimal_value += B[rid[j]] * z[j];
          } else {
            // non-basis
            nz[rid[j] - n] += z[j];
          }
        }
      }

      swap(z, nz);
    } else {
      // 実行不可能
      return {-1e35, {}};
    }
  }

  bool stop = false;
  while (!stop) {
    stop = true;
    int min_j = 1e9;
    int j_memo;

    for (int j = 0; j < m; j++) {
      if (greater_ld(z[j], 0.0) and min_j > n_index[j]) {
        min_j = n_index[j];
        j_memo = j;
        stop = false;
      }
    }

    if (min_j != 1e9) {
      int j = j_memo;
      if (greater_ld(z[j], 0.0)) {
        int min_i = 1e9;
        int i_memo;
        long double min_ratio = 1e18;
        for (int i = 0; i < n; i++) {
          if (less_ld(A[i][j], 0.0)) {
            long double ratio = B[i] / (-A[i][j]);
            if (greater_ld(min_ratio, ratio) or (equal_ld(min_ratio, ratio) and greater_ld(min_i, b_index[i]))) {
              min_i = b_index[i];
              i_memo = i;
              min_ratio = ratio;
            }
          }
        }

        if (min_i == 1e9) {
          // 非有界
          return {1e35, {-1}};
        } else {
          vector<long double> tmp(m);
          long double coef = -A[i_memo][j];
          for (int r = 0; r < n; r++) {
            if (r == i_memo) {
              for (int c = 0; c < m; c++) {
                if (c != j) {
                  tmp[c] = A[r][c] / coef;
                } else {
                  tmp[c] = (-1.0) / coef;
                }
              }
              B[r] /= coef;
              continue;
            }
            long double mul = A[r][j];
            if (equal_ld(mul, 0.0)) continue;
            B[r] += mul * min_ratio;

            for (int c = 0; c < m; c++) {
              if (c != j) {
                A[r][c] += A[i_memo][c] / coef * mul;
              } else {
                A[r][c] = (-1.0) / coef * mul;
              }
            }
          }
          long double mul = z[j];
          optimal_value += mul * min_ratio;
          for (int c = 0; c < m; c++) {
            if (c != j) {
              z[c] += A[i_memo][c] / coef * mul;
            } else {
              z[c] = (-1.0) / coef * mul;
            }
          }
          swap(A[i_memo], tmp);
          swap(n_index[j], b_index[i_memo]);
        }
      }
    }
  }
  return {optimal_value, {}};
}