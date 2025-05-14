__int128_t mod_pow(__int128_t a, long long n, long long m) {
    __int128_t res = 1;
    a %= m;
    while (n) {
        if (n & 1) res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}

constexpr long long MR[] = {2, 7, 61};
constexpr long long MRl[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

bool Miller_Rabin(long long n) {
    long long s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }
    for (int i = 0; i < 3; i++) {
        if (n <= MR[i]) return true;
        __int128_t x = mod_pow(MR[i], d, n);
        if (x != 1) {
            bool ok = false;
            for (int t = 0; t < s; t++) {
                if (x == n - 1) {
                    ok = true;
                    break;
                }
                x = x * x % n;
            }
            if (!ok) return false;
        }
    }
    return true;
}

bool Miller_Rabinl(long long n) {
    long long s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        s++;
        d >>= 1;
    }
    for (int i = 0; i < 7; i++) {
        if (n <= MRl[i]) return true;
        __int128_t x = mod_pow(MRl[i], d, n);
        if (x != 1) {
            bool ok = false;
            for (int t = 0; t < s; t++) {
                if (x == n - 1) {
                    ok = true;
                    break;
                }
                x = x * x % n;
            }
            if (!ok) return false;
        }
    }
    return true;
}

bool brute_force(long long n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_prime(long long n) {
    if (n == 2) return true;
    if ((n & 1) == 0 or n < 2) return false;
    if (n < 1000) return brute_force(n);
    if (n < 4759123141LL) {
        return Miller_Rabin(n);
    }
    return Miller_Rabinl(n);
}
