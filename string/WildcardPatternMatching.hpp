#include "../atcoder/convolution.hpp"

vector<bool> wildcard_matching(const string& s, string t, char wildcard = '*') {
  int n = int(s.size());
  int m = int(t.size());
  reverse(t.begin(), t.end());
  vector<bool> ans;
  vector<atcoder::modint998244353> res(n - m + 1);
  vector<atcoder::modint998244353> tmp;
  vector<atcoder::modint998244353> vs(n), vt(m);

  for (int i = 0; i < n; i++) vs[i] = (s[i] != wildcard);
  for (int i = 0; i < m; i++) vt[i] = (t[i] != wildcard) * int(t[i]) * int(t[i]);
  tmp = convolution(vs, vt);
  for (int i = 0; i < n - m + 1; i++) res[i] = tmp[i + m - 1];

  for (int i = 0; i < n; i++) vs[i] = (s[i] != wildcard) * int(s[i]);
  for (int i = 0; i < m; i++) vt[i] = (t[i] != wildcard) * int(t[i]);
  tmp = convolution(vs, vt);
  for (int i = 0; i < n - m + 1; i++) res[i] -= tmp[i + m - 1] * 2;

  for (int i = 0; i < n; i++) vs[i] = (s[i] != wildcard) * int(s[i]) * int(s[i]);
  for (int i = 0; i < m; i++) vt[i] = (t[i] != wildcard);
  tmp = convolution(vs, vt);
  for (int i = 0; i < n - m + 1; i++) res[i] += tmp[i + m - 1];

  ans.resize(res.size());
  for (int i = 0; i < n - m + 1; i++) ans[i] = (res[i] == 0);
  return ans;
}