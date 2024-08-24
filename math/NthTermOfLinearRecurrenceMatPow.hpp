#pragma once
template <class T>
vector<vector<T>> multiply_matrix(vector<vector<T>> &a, vector<vector<T>> &b) {
    int n = a.size();
    int m = b[0].size();
    vector<vector<T>> ret(n, vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < b.size(); k++) {
                ret[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return ret;
}

template <class T>
vector<vector<T>> pow_matrix(vector<vector<T>> a, long long n) {
    vector<vector<T>> ret(a.size(), vector<T>(a[0].size()));
    for (int i = 0; i < ret.size(); i++) {
        ret[i][i] = 1;
    }

    while (n > 0) {
        if (n & 1) ret = multiply_matrix(ret, a);
        a = multiply_matrix(a, a);
        n >>= 1;
    }

    return ret;
}

template <class T>
T nth_sequence_recurrence(vector<T> coefficient, T constant, vector<T> init, long long n) {
    int m = coefficient.size();
    vector<vector<T>> mat(m + 1, vector<T>(m + 1));
    vector<vector<T>> initv(m + 1, vector<T>(1));
    reverse(init.begin(), init.end());
    for (int i = 0; i < m; i++) {
        initv[i][0] = init[i];
    }
    initv[m][0] = 1;
    for (int i = 0; i < m; i++) {
        mat[0][i] = coefficient[m - 1 - i];
    }
    for (int i = 1; i < m; i++) {
        mat[i][i - 1] = 1;
    }
    mat[0][m] = constant;
    mat[m][m] = 1;
    mat = pow_matrix(mat, n - m + 1);
    return multiply_matrix(mat, initv)[0][0];

    // nth_sequence_recurrence
    // 0-indexed
    // a_n+k = b_0*a_0 + b_1*a_1 + ... + b_m-1*a_n+m-1
    // coefficient = {b_0, b_1, ... , b_m-1}
    // init = {a_0, a_1, ... , a_m-1}

    // vector<lint> coefficient = {1, 1};
    // vector<lint> init = {1, 1};
    // lint constant = 0;
    // lint n;
    // in(n);
    // if (n < init.size()) {
    //     out(init[n]);
    //     return 0;
    // }
    // out(nth_sequence_recurrence(coefficient, constant, init, n));
}