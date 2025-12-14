#include "SuffixArray.hpp"
vector<int> LCPArray(const string& s, const vector<int>& sa) {
  int n = int(s.size());
  vector<int> rank(n);
  for (int i = 0; i < n; i++) rank[sa[i]] = i;
  vector<int> lcp(n - 1);
  int h = 0;
  for (int i = 0; i < n; i++) {
    if (h > 0) h--;
    if (rank[i] == 0) continue;
    int j = sa[rank[i] - 1];
    for (; j + h < n and i + h < n; h++) {
      if (s[j + h] != s[i + h]) break;
    }
    lcp[rank[i] - 1] = h;
  }
  return lcp;
}