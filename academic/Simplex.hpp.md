---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"academic/Simplex.hpp\"\n#define EPS_ 1e-8\nbool equal_ld(long\
    \ double a, long double b) {\n  return abs(a - b) <= EPS_;\n}\n\n// a>b\nbool\
    \ greater_ld(long double a, long double b) {\n  return !equal_ld(a, b) and a >\
    \ b;\n}\n\nbool less_ld(long double a, long double b) {\n  return !equal_ld(a,\
    \ b) and a < b;\n}\n\n// maximize zx\n// subject to Ax<=b\npair<long double, vector<long\
    \ double>> simplex(vector<long double> z, vector<vector<long double>> A, vector<long\
    \ double> B) {\n  int n = int(A.size());\n  int m = int(A[0].size());\n  for (int\
    \ i = 0; i < n; i++) {\n    for (int j = 0; j < m; j++) {\n      A[i][j] = -A[i][j];\n\
    \    }\n  }\n\n  bool is_feasible = true;\n  long double min_b = 1.0;\n  int min_b_id\
    \ = -1;\n  for (int i = 0; i < n; i++) {\n    if (less_ld(B[i], 0.0)) {\n    \
    \  is_feasible = false;\n      if (less_ld(B[i], min_b)) {\n        min_b = B[i];\n\
    \        min_b_id = i;\n      }\n    }\n  }\n\n  vector<int> n_index(m), b_index(n);\n\
    \  iota(n_index.begin(), n_index.end(), 0);\n  iota(b_index.begin(), b_index.end(),\
    \ m);\n  long double optimal_value = 0.0;\n\n  if (!is_feasible) {\n    for (int\
    \ i = 0; i < n; i++) {\n      A[i].emplace_back(0.0);\n    }\n    n_index.emplace_back(n\
    \ + m);\n    for (int i = 0; i < n; i++) {\n      if (less_ld(B[i], 0.0)) {\n\
    \        A[i][m] = 1.0;\n        if (i == min_b_id) {\n          B[i] = -B[i];\n\
    \          for (int j = 0; j < m; j++) {\n            A[i][j] = -A[i][j];\n  \
    \        }\n          swap(b_index[i], n_index[m]);\n        }\n      }\n    }\n\
    \n    for (int i = 0; i < n; i++) {\n      if (less_ld(B[i], 0.0) and i != min_b_id)\
    \ {\n        B[i] += B[min_b_id];\n        for (int j = 0; j < m; j++) {\n   \
    \       A[i][j] += A[min_b_id][j];\n        }\n      }\n    }\n\n    long double\
    \ ap_optimal_value = min_b;\n    // maximize z_\n    vector<long double> z_(m\
    \ + 1);\n    for (int j = 0; j <= m; j++) {\n      z_[j] = -A[min_b_id][j];\n\
    \    }\n    bool stop = false;\n    while (!stop) {\n      stop = true;\n    \
    \  int min_j = 1e9;\n      int j_memo;\n\n      for (int j = 0; j <= m; j++) {\n\
    \        if (greater_ld(z_[j], 0.0) and min_j > n_index[j]) {\n          min_j\
    \ = n_index[j];\n          j_memo = j;\n          stop = false;\n        }\n \
    \     }\n\n      if (min_j != 1e9) {\n        int j = j_memo;\n        if (greater_ld(z_[j],\
    \ 0.0)) {\n          stop = false;\n          int min_i = 1e9;\n          int\
    \ i_memo;\n          long double min_ratio = 1e18;\n          for (int i = 0;\
    \ i < n; i++) {\n            if (less_ld(A[i][j], 0.0)) {\n              long\
    \ double ratio = B[i] / (-A[i][j]);\n              if (greater_ld(min_ratio, ratio)\
    \ or (equal_ld(min_ratio, ratio) and greater_ld(min_i, b_index[i]))) {\n     \
    \           min_i = b_index[i];\n                i_memo = i;\n               \
    \ min_ratio = ratio;\n              }\n            }\n          }\n\n        \
    \  if (min_i == 1e9) {\n            // \u975E\u6709\u754C\n            return\
    \ {1e35, {}};\n          } else {\n            vector<long double> tmp(m + 1);\n\
    \            long double coef = -A[i_memo][j];\n            for (int r = 0; r\
    \ < n; r++) {\n              if (r == i_memo) {\n                for (int c =\
    \ 0; c <= m; c++) {\n                  if (c != j) {\n                    tmp[c]\
    \ = A[r][c] / coef;\n                  } else {\n                    tmp[c] =\
    \ (-1.0) / coef;\n                  }\n                }\n                B[r]\
    \ /= coef;\n                continue;\n              }\n              long double\
    \ mul = A[r][j];\n              if (equal_ld(mul, 0.0)) continue;\n          \
    \    B[r] += mul * min_ratio;\n\n              for (int c = 0; c <= m; c++) {\n\
    \                if (c != j) {\n                  A[r][c] += A[i_memo][c] / coef\
    \ * mul;\n                } else {\n                  A[r][c] = (-1.0) / coef\
    \ * mul;\n                }\n              }\n            }\n            long\
    \ double mul = z_[j];\n            ap_optimal_value += mul * min_ratio;\n    \
    \        for (int c = 0; c <= m; c++) {\n              if (c != j) {\n       \
    \         z_[c] += A[i_memo][c] / coef * mul;\n              } else {\n      \
    \          z_[c] = (-1.0) / coef * mul;\n              }\n            }\n    \
    \        swap(A[i_memo], tmp);\n            swap(n_index[j], b_index[i_memo]);\n\
    \          }\n        }\n      }\n    }\n\n    if (equal_ld(ap_optimal_value,\
    \ 0.0)) {\n      for (int i = 0; i < n; i++) {\n        if (b_index[i] == n +\
    \ m) {\n          for (int j = 0; j <= m; j++) {\n            if (!equal_ld(A[i][j],\
    \ 0.0)) {\n              vector<long double> tmp(m + 1);\n              long double\
    \ coef = -A[i][j];\n              long double ratio = B[i] / coef;\n\n       \
    \       for (int r = 0; r < n; r++) {\n                if (r == i) {\n       \
    \           for (int c = 0; c <= m; c++) {\n                    if (c != j) {\n\
    \                      tmp[c] = A[r][c] / coef;\n                    } else {\n\
    \                      tmp[c] = (-1.0) / coef;\n                    }\n      \
    \            }\n                  B[r] = ratio;\n                  continue;\n\
    \                }\n                long double mul = A[r][j];\n             \
    \   if (equal_ld(mul, 0.0)) continue;\n                B[r] += mul * ratio;\n\n\
    \                for (int c = 0; c <= m; c++) {\n                  if (c != j)\
    \ {\n                    A[r][c] += A[i][c] / coef * mul;\n                  }\
    \ else {\n                    A[r][c] = (-1.0) / coef * mul;\n               \
    \   }\n                }\n              }\n              long double mul = z_[j];\n\
    \              ap_optimal_value += mul * ratio;\n              for (int c = 0;\
    \ c <= m; c++) {\n                if (c != j) {\n                  z_[c] += A[i][c]\
    \ / coef * mul;\n                } else {\n                  z_[c] = (-1.0) /\
    \ coef * mul;\n                }\n              }\n              swap(A[i], tmp);\n\
    \              swap(n_index[j], b_index[i]);\n              break;\n         \
    \   }\n          }\n        }\n      }\n      int art = n + m;\n      int pos\
    \ = -1;\n\n      for (int j = 0; j < (int)n_index.size(); j++) {\n        if (n_index[j]\
    \ == art) {\n          pos = j;\n          break;\n        }\n      }\n\n    \
    \  if (pos != -1) {\n        int last = (int)n_index.size() - 1;\n\n        for\
    \ (int i = 0; i < n; i++) {\n          swap(A[i][pos], A[i][last]);\n        \
    \  A[i].pop_back();\n        }\n\n        swap(n_index[pos], n_index[last]);\n\
    \        n_index.pop_back();\n      }\n\n      vector<int> rid(n + m, -1);\n \
    \     for (int i = 0; i < n; i++) {\n        rid[b_index[i]] = i;\n      }\n \
    \     for (int j = 0; j < m; j++) {\n        rid[n_index[j]] = n + j;\n      }\n\
    \      vector<long double> nz(m, 0.0);\n      for (int j = 0; j < m; j++) {\n\
    \        if (!equal_ld(z[j], 0.0)) {\n          if (rid[j] < n) {\n          \
    \  // basis\n            for (int c = 0; c < m; c++) {\n              nz[c] +=\
    \ A[rid[j]][c] * z[j];\n            }\n            optimal_value += B[rid[j]]\
    \ * z[j];\n          } else {\n            // non-basis\n            nz[rid[j]\
    \ - n] += z[j];\n          }\n        }\n      }\n\n      swap(z, nz);\n    }\
    \ else {\n      // \u5B9F\u884C\u4E0D\u53EF\u80FD\n      return {-1e35, {}};\n\
    \    }\n  }\n\n  bool stop = false;\n  while (!stop) {\n    stop = true;\n   \
    \ int min_j = 1e9;\n    int j_memo;\n\n    for (int j = 0; j < m; j++) {\n   \
    \   if (greater_ld(z[j], 0.0) and min_j > n_index[j]) {\n        min_j = n_index[j];\n\
    \        j_memo = j;\n        stop = false;\n      }\n    }\n\n    if (min_j !=\
    \ 1e9) {\n      int j = j_memo;\n      if (greater_ld(z[j], 0.0)) {\n        int\
    \ min_i = 1e9;\n        int i_memo;\n        long double min_ratio = 1e18;\n \
    \       for (int i = 0; i < n; i++) {\n          if (less_ld(A[i][j], 0.0)) {\n\
    \            long double ratio = B[i] / (-A[i][j]);\n            if (greater_ld(min_ratio,\
    \ ratio) or (equal_ld(min_ratio, ratio) and greater_ld(min_i, b_index[i]))) {\n\
    \              min_i = b_index[i];\n              i_memo = i;\n              min_ratio\
    \ = ratio;\n            }\n          }\n        }\n\n        if (min_i == 1e9)\
    \ {\n          // \u975E\u6709\u754C\n          return {1e35, {-1}};\n       \
    \ } else {\n          vector<long double> tmp(m);\n          long double coef\
    \ = -A[i_memo][j];\n          for (int r = 0; r < n; r++) {\n            if (r\
    \ == i_memo) {\n              for (int c = 0; c < m; c++) {\n                if\
    \ (c != j) {\n                  tmp[c] = A[r][c] / coef;\n                } else\
    \ {\n                  tmp[c] = (-1.0) / coef;\n                }\n          \
    \    }\n              B[r] /= coef;\n              continue;\n            }\n\
    \            long double mul = A[r][j];\n            if (equal_ld(mul, 0.0)) continue;\n\
    \            B[r] += mul * min_ratio;\n\n            for (int c = 0; c < m; c++)\
    \ {\n              if (c != j) {\n                A[r][c] += A[i_memo][c] / coef\
    \ * mul;\n              } else {\n                A[r][c] = (-1.0) / coef * mul;\n\
    \              }\n            }\n          }\n          long double mul = z[j];\n\
    \          optimal_value += mul * min_ratio;\n          for (int c = 0; c < m;\
    \ c++) {\n            if (c != j) {\n              z[c] += A[i_memo][c] / coef\
    \ * mul;\n            } else {\n              z[c] = (-1.0) / coef * mul;\n  \
    \          }\n          }\n          swap(A[i_memo], tmp);\n          swap(n_index[j],\
    \ b_index[i_memo]);\n        }\n      }\n    }\n  }\n  return {optimal_value,\
    \ {}};\n}\n"
  code: "#define EPS_ 1e-8\nbool equal_ld(long double a, long double b) {\n  return\
    \ abs(a - b) <= EPS_;\n}\n\n// a>b\nbool greater_ld(long double a, long double\
    \ b) {\n  return !equal_ld(a, b) and a > b;\n}\n\nbool less_ld(long double a,\
    \ long double b) {\n  return !equal_ld(a, b) and a < b;\n}\n\n// maximize zx\n\
    // subject to Ax<=b\npair<long double, vector<long double>> simplex(vector<long\
    \ double> z, vector<vector<long double>> A, vector<long double> B) {\n  int n\
    \ = int(A.size());\n  int m = int(A[0].size());\n  for (int i = 0; i < n; i++)\
    \ {\n    for (int j = 0; j < m; j++) {\n      A[i][j] = -A[i][j];\n    }\n  }\n\
    \n  bool is_feasible = true;\n  long double min_b = 1.0;\n  int min_b_id = -1;\n\
    \  for (int i = 0; i < n; i++) {\n    if (less_ld(B[i], 0.0)) {\n      is_feasible\
    \ = false;\n      if (less_ld(B[i], min_b)) {\n        min_b = B[i];\n       \
    \ min_b_id = i;\n      }\n    }\n  }\n\n  vector<int> n_index(m), b_index(n);\n\
    \  iota(n_index.begin(), n_index.end(), 0);\n  iota(b_index.begin(), b_index.end(),\
    \ m);\n  long double optimal_value = 0.0;\n\n  if (!is_feasible) {\n    for (int\
    \ i = 0; i < n; i++) {\n      A[i].emplace_back(0.0);\n    }\n    n_index.emplace_back(n\
    \ + m);\n    for (int i = 0; i < n; i++) {\n      if (less_ld(B[i], 0.0)) {\n\
    \        A[i][m] = 1.0;\n        if (i == min_b_id) {\n          B[i] = -B[i];\n\
    \          for (int j = 0; j < m; j++) {\n            A[i][j] = -A[i][j];\n  \
    \        }\n          swap(b_index[i], n_index[m]);\n        }\n      }\n    }\n\
    \n    for (int i = 0; i < n; i++) {\n      if (less_ld(B[i], 0.0) and i != min_b_id)\
    \ {\n        B[i] += B[min_b_id];\n        for (int j = 0; j < m; j++) {\n   \
    \       A[i][j] += A[min_b_id][j];\n        }\n      }\n    }\n\n    long double\
    \ ap_optimal_value = min_b;\n    // maximize z_\n    vector<long double> z_(m\
    \ + 1);\n    for (int j = 0; j <= m; j++) {\n      z_[j] = -A[min_b_id][j];\n\
    \    }\n    bool stop = false;\n    while (!stop) {\n      stop = true;\n    \
    \  int min_j = 1e9;\n      int j_memo;\n\n      for (int j = 0; j <= m; j++) {\n\
    \        if (greater_ld(z_[j], 0.0) and min_j > n_index[j]) {\n          min_j\
    \ = n_index[j];\n          j_memo = j;\n          stop = false;\n        }\n \
    \     }\n\n      if (min_j != 1e9) {\n        int j = j_memo;\n        if (greater_ld(z_[j],\
    \ 0.0)) {\n          stop = false;\n          int min_i = 1e9;\n          int\
    \ i_memo;\n          long double min_ratio = 1e18;\n          for (int i = 0;\
    \ i < n; i++) {\n            if (less_ld(A[i][j], 0.0)) {\n              long\
    \ double ratio = B[i] / (-A[i][j]);\n              if (greater_ld(min_ratio, ratio)\
    \ or (equal_ld(min_ratio, ratio) and greater_ld(min_i, b_index[i]))) {\n     \
    \           min_i = b_index[i];\n                i_memo = i;\n               \
    \ min_ratio = ratio;\n              }\n            }\n          }\n\n        \
    \  if (min_i == 1e9) {\n            // \u975E\u6709\u754C\n            return\
    \ {1e35, {}};\n          } else {\n            vector<long double> tmp(m + 1);\n\
    \            long double coef = -A[i_memo][j];\n            for (int r = 0; r\
    \ < n; r++) {\n              if (r == i_memo) {\n                for (int c =\
    \ 0; c <= m; c++) {\n                  if (c != j) {\n                    tmp[c]\
    \ = A[r][c] / coef;\n                  } else {\n                    tmp[c] =\
    \ (-1.0) / coef;\n                  }\n                }\n                B[r]\
    \ /= coef;\n                continue;\n              }\n              long double\
    \ mul = A[r][j];\n              if (equal_ld(mul, 0.0)) continue;\n          \
    \    B[r] += mul * min_ratio;\n\n              for (int c = 0; c <= m; c++) {\n\
    \                if (c != j) {\n                  A[r][c] += A[i_memo][c] / coef\
    \ * mul;\n                } else {\n                  A[r][c] = (-1.0) / coef\
    \ * mul;\n                }\n              }\n            }\n            long\
    \ double mul = z_[j];\n            ap_optimal_value += mul * min_ratio;\n    \
    \        for (int c = 0; c <= m; c++) {\n              if (c != j) {\n       \
    \         z_[c] += A[i_memo][c] / coef * mul;\n              } else {\n      \
    \          z_[c] = (-1.0) / coef * mul;\n              }\n            }\n    \
    \        swap(A[i_memo], tmp);\n            swap(n_index[j], b_index[i_memo]);\n\
    \          }\n        }\n      }\n    }\n\n    if (equal_ld(ap_optimal_value,\
    \ 0.0)) {\n      for (int i = 0; i < n; i++) {\n        if (b_index[i] == n +\
    \ m) {\n          for (int j = 0; j <= m; j++) {\n            if (!equal_ld(A[i][j],\
    \ 0.0)) {\n              vector<long double> tmp(m + 1);\n              long double\
    \ coef = -A[i][j];\n              long double ratio = B[i] / coef;\n\n       \
    \       for (int r = 0; r < n; r++) {\n                if (r == i) {\n       \
    \           for (int c = 0; c <= m; c++) {\n                    if (c != j) {\n\
    \                      tmp[c] = A[r][c] / coef;\n                    } else {\n\
    \                      tmp[c] = (-1.0) / coef;\n                    }\n      \
    \            }\n                  B[r] = ratio;\n                  continue;\n\
    \                }\n                long double mul = A[r][j];\n             \
    \   if (equal_ld(mul, 0.0)) continue;\n                B[r] += mul * ratio;\n\n\
    \                for (int c = 0; c <= m; c++) {\n                  if (c != j)\
    \ {\n                    A[r][c] += A[i][c] / coef * mul;\n                  }\
    \ else {\n                    A[r][c] = (-1.0) / coef * mul;\n               \
    \   }\n                }\n              }\n              long double mul = z_[j];\n\
    \              ap_optimal_value += mul * ratio;\n              for (int c = 0;\
    \ c <= m; c++) {\n                if (c != j) {\n                  z_[c] += A[i][c]\
    \ / coef * mul;\n                } else {\n                  z_[c] = (-1.0) /\
    \ coef * mul;\n                }\n              }\n              swap(A[i], tmp);\n\
    \              swap(n_index[j], b_index[i]);\n              break;\n         \
    \   }\n          }\n        }\n      }\n      int art = n + m;\n      int pos\
    \ = -1;\n\n      for (int j = 0; j < (int)n_index.size(); j++) {\n        if (n_index[j]\
    \ == art) {\n          pos = j;\n          break;\n        }\n      }\n\n    \
    \  if (pos != -1) {\n        int last = (int)n_index.size() - 1;\n\n        for\
    \ (int i = 0; i < n; i++) {\n          swap(A[i][pos], A[i][last]);\n        \
    \  A[i].pop_back();\n        }\n\n        swap(n_index[pos], n_index[last]);\n\
    \        n_index.pop_back();\n      }\n\n      vector<int> rid(n + m, -1);\n \
    \     for (int i = 0; i < n; i++) {\n        rid[b_index[i]] = i;\n      }\n \
    \     for (int j = 0; j < m; j++) {\n        rid[n_index[j]] = n + j;\n      }\n\
    \      vector<long double> nz(m, 0.0);\n      for (int j = 0; j < m; j++) {\n\
    \        if (!equal_ld(z[j], 0.0)) {\n          if (rid[j] < n) {\n          \
    \  // basis\n            for (int c = 0; c < m; c++) {\n              nz[c] +=\
    \ A[rid[j]][c] * z[j];\n            }\n            optimal_value += B[rid[j]]\
    \ * z[j];\n          } else {\n            // non-basis\n            nz[rid[j]\
    \ - n] += z[j];\n          }\n        }\n      }\n\n      swap(z, nz);\n    }\
    \ else {\n      // \u5B9F\u884C\u4E0D\u53EF\u80FD\n      return {-1e35, {}};\n\
    \    }\n  }\n\n  bool stop = false;\n  while (!stop) {\n    stop = true;\n   \
    \ int min_j = 1e9;\n    int j_memo;\n\n    for (int j = 0; j < m; j++) {\n   \
    \   if (greater_ld(z[j], 0.0) and min_j > n_index[j]) {\n        min_j = n_index[j];\n\
    \        j_memo = j;\n        stop = false;\n      }\n    }\n\n    if (min_j !=\
    \ 1e9) {\n      int j = j_memo;\n      if (greater_ld(z[j], 0.0)) {\n        int\
    \ min_i = 1e9;\n        int i_memo;\n        long double min_ratio = 1e18;\n \
    \       for (int i = 0; i < n; i++) {\n          if (less_ld(A[i][j], 0.0)) {\n\
    \            long double ratio = B[i] / (-A[i][j]);\n            if (greater_ld(min_ratio,\
    \ ratio) or (equal_ld(min_ratio, ratio) and greater_ld(min_i, b_index[i]))) {\n\
    \              min_i = b_index[i];\n              i_memo = i;\n              min_ratio\
    \ = ratio;\n            }\n          }\n        }\n\n        if (min_i == 1e9)\
    \ {\n          // \u975E\u6709\u754C\n          return {1e35, {-1}};\n       \
    \ } else {\n          vector<long double> tmp(m);\n          long double coef\
    \ = -A[i_memo][j];\n          for (int r = 0; r < n; r++) {\n            if (r\
    \ == i_memo) {\n              for (int c = 0; c < m; c++) {\n                if\
    \ (c != j) {\n                  tmp[c] = A[r][c] / coef;\n                } else\
    \ {\n                  tmp[c] = (-1.0) / coef;\n                }\n          \
    \    }\n              B[r] /= coef;\n              continue;\n            }\n\
    \            long double mul = A[r][j];\n            if (equal_ld(mul, 0.0)) continue;\n\
    \            B[r] += mul * min_ratio;\n\n            for (int c = 0; c < m; c++)\
    \ {\n              if (c != j) {\n                A[r][c] += A[i_memo][c] / coef\
    \ * mul;\n              } else {\n                A[r][c] = (-1.0) / coef * mul;\n\
    \              }\n            }\n          }\n          long double mul = z[j];\n\
    \          optimal_value += mul * min_ratio;\n          for (int c = 0; c < m;\
    \ c++) {\n            if (c != j) {\n              z[c] += A[i_memo][c] / coef\
    \ * mul;\n            } else {\n              z[c] = (-1.0) / coef * mul;\n  \
    \          }\n          }\n          swap(A[i_memo], tmp);\n          swap(n_index[j],\
    \ b_index[i_memo]);\n        }\n      }\n    }\n  }\n  return {optimal_value,\
    \ {}};\n}"
  dependsOn: []
  isVerificationFile: false
  path: academic/Simplex.hpp
  requiredBy: []
  timestamp: '2026-04-25 17:57:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: academic/Simplex.hpp
layout: document
title: Simplex Method
---

## 概要

単体法　(未verify)

