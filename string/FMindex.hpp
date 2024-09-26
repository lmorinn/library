#pragma once
#include "../data-structure/wavelet-matrix/WaveletMatrixString.hpp"
#include "../string/SuffixArray.hpp"

class FMindex {
   private:
    int n;
    WaveletMatrix w;
    vector<int> less;

   public:
    FMindex(string &s) {
        n = s.size();
        less.resize(256);
        vector<int> cnt(256);
        string bwt(n + 1, '$');
        vector<int> sa = suffixArray(s);
        reverse(sa.begin(), sa.end());
        sa.emplace_back(s.size());
        reverse(sa.begin(), sa.end());

        for (int i = 0; i < s.size() + 1; i++) {
            if (sa[i] > 0) {
                bwt[i] = s[sa[i] - 1];
            }
            cnt[s[i]]++;
        }

        for (int i = 1; i < 256; i++) {
            less[i] = less[i - 1] + cnt[i - 1];
        }
        w = WaveletMatrix(bwt);
    }

    int substrCount(string &t) {
        int m = t.size();
        int l = 0;
        int r = n + 1;
        for (int i = 0; i < m; i++) {
            unsigned char c = t[m - 1 - i];
            l = less[c] + w.rank(l, c);
            r = less[c] + w.rank(r, c);
            if (l >= r) {
                l = 0;
                r = 0;
                break;
            }
        }
        return r - l;
    }
};