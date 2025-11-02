
struct FPS : vector<mint> {
    using vector<mint>::vector;
    using vector<mint>::operator=;

    FPS inv() {
        int n = int((*this).size());
        FPS res = {(*this)[0].inv()};
        while (int(res.size()) < n) {
            int m = int(res.size());
            FPS f((*this).begin(), (*this).begin() + min(n, m << 1));
            FPS inv_f(res);
            f.resize(m << 1);
            internal::butterfly(f);
            inv_f.resize(m << 1);
            internal::butterfly(inv_f);
            for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];
            internal::butterfly_inv(f);
            f.erase(f.begin(), f.begin() + m);
            f.resize(m << 1);
            internal::butterfly(f);
            for (int i = 0; i < m << 1; i++) f[i] *= inv_f[i];
            internal::butterfly_inv(f);
            mint m2i = mint(m << 1).inv();
            m2i *= -m2i;
            for (int i = 0; i < m << 1; i++) f[i] *= m2i;
            res.insert(res.end(), f.begin(), f.begin() + m);
        }
        return {res.begin(), res.begin() + n};
    }

    FPS log() {
        int n = int((*this).size());
        FPS res = (*this).differentiate();
        res /= (*this);
        return res.integrate();
    }

    FPS differentiate() {
        int n = int((*this).size());
        FPS res(n);
        for (int i = 0; i < n - 1; i++) res[i] = (*this)[i + 1] * mint(i + 1);
        res[n - 1] = 0;
        return res;
    }

    FPS integrate() {
        int n = int((*this).size());
        vector<mint> iv(n);
        iv[1] = 1;
        for (int i = 2; i < n; i++) iv[i] = iv[998244353 % i] * (-(998244353 / i));
        FPS res(n);
        res[0] = 0;
        for (int i = 0; i < n - 1; i++) res[i + 1] = (*this)[i] * iv[i + 1];
        return res;
    }

    FPS& operator*=(const FPS& g) {
        int n = int((*this).size());
        *this = convolution(*this, g);
        (*this).resize(n);
        return *this;
    }

    FPS& operator/=(FPS& g) {
        int n = int((*this).size());
        *this = convolution(*this, g.inv());
        (*this).resize(n);
        return *this;
    }
};