#pragma once

#define tget(i) (((t)[(i) >> 3] >> (7 - ((i) & 7))) & 1)

#define tset(i, b)                                    \
    do {                                              \
        if (b)                                        \
            (t)[(i) >> 3] |= (1 << (7 - ((i) & 7)));  \
        else                                          \
            (t)[(i) >> 3] &= ~(1 << (7 - ((i) & 7))); \
    } while (0)

#define chr(i) (cs == sizeof(int) ? ((int *)s)[i] : ((unsigned char *)s)[i])
#define isLMS(i) (i > 0 and tget(i) and !tget(i - 1))

void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int sum = 0;
    for (int i = 0; i <= K; i++) {
        bkt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bkt[chr(i)]++;
    }
    for (int i = 0; i <= K; i++) {
        sum += bkt[i];
        bkt[i] = end ? sum : sum - bkt[i];
    }
}

void induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    getBuckets(s, bkt, n, K, cs, end);
    for (int i = 0; i < n; i++) {
        int j = SA[i] - 1;
        if (j >= 0 and !tget(j)) {
            SA[bkt[chr(j)]++] = j;
        }
    }
}

void induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    getBuckets(s, bkt, n, K, cs, end);
    for (int i = n - 1; i >= 0; i--) {
        int j = SA[i] - 1;
        if (j >= 0 and tget(j)) {
            SA[--bkt[chr(j)]] = j;
        }
    }
}

void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
    unsigned char *t = (unsigned char *)malloc(n / 8 + 1);
    tset(n - 2, 0);
    tset(n - 1, 1);
    for (int i = n - 3; i >= 0; i--) {
        tset(i, (chr(i) < chr(i + 1) or (chr(i) == chr(i + 1) and tget(i + 1) == 1)) ? 1 : 0);
    }

    int *bkt = (int *)malloc(sizeof(int) * (K + 1));
    getBuckets(s, bkt, n, K, cs, true);
    for (int i = 0; i < n; i++) {
        SA[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        if (isLMS(i)) {
            SA[--bkt[chr(i)]] = i;
        }
    }
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);

    int n1 = 0;
    for (int i = 0; i < n; i++) {
        if (isLMS(SA[i])) {
            SA[n1++] = SA[i];
        }
    }

    for (int i = n1; i < n; i++) {
        SA[i] = -1;
    }
    int name = 0;
    int prev = -1;
    for (int i = 0; i < n1; i++) {
        int pos = SA[i];
        bool diff = false;
        for (int d = 0; d < n; d++) {
            if (prev == -1 or chr(pos + d) != chr(prev + d) or tget(pos + d) != tget(prev + d)) {
                diff = true;
                break;
            } else if (d > 0 and (isLMS(pos + d) or isLMS(prev + d))) {
                break;
            }
        }
        if (diff) {
            name++;
            prev = pos;
        }
        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
        SA[n1 + pos] = name - 1;
    }
    for (int i = n - 1, j = n - 1; i >= n1; i--) {
        if (SA[i] >= 0) {
            SA[j--] = SA[i];
        }
    }

    int *SA1 = SA;
    int *s1 = SA + n - n1;
    if (name < n1) {
        SA_IS((unsigned char *)s1, SA1, n1, name - 1, sizeof(int));
    } else {
        for (int i = 0; i < n1; i++) {
            SA1[s1[i]] = i;
        }
    }
    bkt = (int *)malloc(sizeof(int) * (K + 1));
    getBuckets(s, bkt, n, K, cs, true);
    for (int i = 1, j = 0; i < n; i++) {
        if (isLMS(i)) {
            s1[j++] = i;
        }
    }
    for (int i = 0; i < n1; i++) {
        SA1[i] = s1[SA1[i]];
    }
    for (int i = n1; i < n; i++) {
        SA[i] = -1;
    }
    for (int i = n1 - 1; i >= 0; i--) {
        int j = SA[i];
        SA[i] = -1;
        SA[--bkt[chr(j)]] = j;
    }
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    free(t);
}

vector<int> suffixArray(string &str) {
    int n = str.size() + 1;
    int *sa = (int *)malloc(sizeof(int) * n);
    unsigned char *s = (unsigned char *)malloc(sizeof(unsigned char) * (n + 2));
    int k = 256;
    int cs = sizeof(unsigned char);
    for (int i = 0; i < str.size(); i++) {
        s[i] = str[i];
    }
    s[int(str.size())] = 0;
    SA_IS((unsigned char *)(s), sa, n, k, cs);
    vector<int> res(n - 1);
    for (int i = 0; i < n - 1; i++) {
        res[i] = sa[i + 1];
    }
    free(sa);
    free(s);
    return res;
}