class RollingHash {
   private:
    int64_t n;
    int64_t mod = (1LL << 61) - 1;
    int64_t base = 58347;
    vector<int64_t> invb;
    vector<int64_t> sum;

    __int128_t mod_pow(__int128_t a, int64_t p) {
        __int128_t res = 1;
        while (p) {
            if (p & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            p >>= 1;
        }
        return res;
    }

   public:
    RollingHash(const string &s) {
        __int128_t b_p = 1;
        n = int64_t(s.size());
        invb.resize(n + 1);
        sum.resize(n + 1);

        for (int i = 0; i < n; i++) {
            int64_t h_i = (b_p * int(s[i])) % mod;
            sum[i + 1] = (sum[i] + h_i) % mod;
            b_p = (b_p * base) % mod;
        }
        invb[n] = mod_pow(b_p, mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invb[i] = (__int128_t(invb[i + 1]) * base) % mod;
        }
    }

    int64_t range_hash(int l, int r) {
        return (__int128_t(sum[r] - sum[l] + mod) * invb[l]) % mod;
    }
};